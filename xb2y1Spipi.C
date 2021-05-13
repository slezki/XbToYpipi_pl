#define xb2y1Spipi_cxx
// The class definition in xb2y1Spipi.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("xb2y1Spipi.C")
// root> T->Process("xb2y1Spipi.C","some options")
// root> T->Process("xb2y1Spipi.C+")
//


#include "xb2y1Spipi.h"
#include <TH2.h>
#include <TStyle.h>

void xb2y1Spipi::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void xb2y1Spipi::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   Pvtx = 0.05;

   TString sPvtx = to_string(Pvtx);
   sPvtx.ReplaceAll(".","p"); 
   sPvtx.ReplaceAll("00000","");
   sPvtx.ReplaceAll("0000","");
   sPvtx.ReplaceAll("000","");

   OutFile = new TProofOutputFile("histo_xb2y1Spipi_DataRunII_miniAOD_RS_P"+ sPvtx +".root");

   fOut = OutFile->OpenFile("RECREATE");
   if (!(fOut=OutFile->OpenFile("RECREATE"))){
      Warning("SlaveBegin","Problems opening file: %s%s", OutFile->GetDir(), OutFile->GetFileName() );
   }

   ////////////////////////////////////////////////////////////
   noCuts = new TTree("noCuts","noCuts");
   noCuts->Branch("y1Spipi_M",      &out_y1Spipi_M,   "y1Spipi_M/D");
   noCuts->Branch("y1Spipi_vProb",      &out_y1Spipi_vProb,   "y1Spipi_vProb/D");
   noCuts->Branch("y1Spipi_Pt",      &out_y1Spipi_Pt,   "y1Spipi_Pt/D");
   noCuts->Branch("y1Spipi_E",      &out_y1Spipi_E,   "y1Spipi_E/D");
   noCuts->Branch("y1Spipi_y",      &out_y1Spipi_y,   "y1Spipi_y/D");
   noCuts->Branch("y1Spipi_Eta",      &out_y1Spipi_Eta,   "y1Spipi_Eta/D");
   noCuts->Branch("y1Spipi_Phi",      &out_y1Spipi_Phi,   "y1Spipi_Phi/D");

   noCuts->Branch("ditrack_M",      &out_ditrack_M,   "ditrack_M/D");
   noCuts->Branch("ditrack_Pt",      &out_ditrack_Pt,   "ditrack_Pt/D");
   noCuts->Branch("ditrack_E",      &out_ditrack_E,   "ditrack_E/D");
   noCuts->Branch("ditrack_Eta",      &out_ditrack_Eta,   "ditrack_Eta/D");
   noCuts->Branch("ditrack_y",      &out_ditrack_y,   "ditrack_y/D");
   noCuts->Branch("ditrack_Phi",      &out_ditrack_Phi,   "ditrack_Phi/D");

   noCuts->Branch("numPrimaryVertices",      &out_numPrimaryVertices,   "numPrimaryVertices/I");
   noCuts->Branch("iPVwithmuons",      &out_iPVwithmuons,   "iPVwithmuons/I");

   noCuts->Branch("dimuon_M",      &out_dimuon_M,   "dimuon_M/D");
   noCuts->Branch("dimuon_Pt",      &out_dimuon_Pt,   "dimuon_Pt/D");
   noCuts->Branch("dimuon_E",      &out_dimuon_E,   "dimuon_E/D");
   noCuts->Branch("dimuon_Eta",      &out_dimuon_Eta,   "dimuon_Eta/D");
   noCuts->Branch("dimuon_y",      &out_dimuon_y,   "dimuon_y/D");
   noCuts->Branch("dimuon_Phi",      &out_dimuon_Phi,   "dimuon_Phi/D");

   noCuts->Branch("muonp_M",      &out_muonp_M,   "muonp_M/D");
   noCuts->Branch("muonp_Pt",      &out_muonp_Pt,   "muonp_Pt/D");
   noCuts->Branch("muonp_E",      &out_muonp_E,   "muonp_E/D");
   noCuts->Branch("muonp_Eta",      &out_muonp_Eta,   "muonp_Eta/D");
   noCuts->Branch("muonp_y",      &out_muonp_y,   "muonp_y/D");
   noCuts->Branch("muonp_Phi",      &out_muonp_Phi,   "muonp_Phi/D");

   noCuts->Branch("muonn_M",      &out_muonn_M,   "muonn_M/D");
   noCuts->Branch("muonn_Pt",      &out_muonn_Pt,   "muonn_Pt/D");
   noCuts->Branch("muonn_E",      &out_muonn_E,   "muonn_E/D");
   noCuts->Branch("muonn_Eta",      &out_muonn_Eta,   "muonn_Eta/D");
   noCuts->Branch("muonn_y",      &out_muonn_y,   "muonn_y/D");
   noCuts->Branch("muonn_Phi",      &out_muonn_Phi,   "muonn_Phi/D");

   noCuts->Branch("pion1_Pt",      &out_pion1_Pt,   "pion1_Pt/D");
   noCuts->Branch("pion1_E",      &out_pion1_E,   "pion1_E/D");
   noCuts->Branch("pion1_Eta",      &out_pion1_Eta,   "pion1_Eta/D");
   noCuts->Branch("pion1_y",      &out_pion1_y,   "pion1_y/D");
   noCuts->Branch("pion1_Phi",      &out_pion1_Phi,   "pion1_Phi/D");

   noCuts->Branch("pion2_Pt",      &out_pion2_Pt,   "pion2_Pt/D");
   noCuts->Branch("pion2_E",      &out_pion2_E,   "pion2_E/D");
   noCuts->Branch("pion2_Eta",      &out_pion2_Eta,   "pion2_Eta/D");
   noCuts->Branch("pion2_y",      &out_pion2_y,   "pion2_y/D");
   noCuts->Branch("pion2_Phi",      &out_pion2_Phi,   "pion2_Phi/D");

   noCuts->Branch("pion1_dz",      &out_pion1_dz,   "pion1_dz/D");
   noCuts->Branch("pion1_dzErr",      &out_pion1_dzErr,   "pion1_dzErr/D");
   noCuts->Branch("pion1_dxy",      &out_pion1_dxy,   "pion1_dxy/D");
   noCuts->Branch("pion1_dxyErr",      &out_pion1_dxyErr,   "pion1_dxyErr/D");

   noCuts->Branch("pion1_PV",      &out_pion1_PV,   "pion1_PV/I");
   noCuts->Branch("pion1_refVtx",      &out_pion1_refVtx,   "pion1_refVtx/I");
   noCuts->Branch("pion1_pvAssocQ",      &out_pion1_pvAssocQ,   "pion1_pvAssocQ/I");
   noCuts->Branch("pion1_dzAssocPV",      &out_pion1_dzAssocPV,   "pion1_dzAssocPV/D");

   noCuts->Branch("pion2_dz",      &out_pion2_dz,   "pion2_dz/D");
   noCuts->Branch("pion2_dzErr",      &out_pion2_dzErr,   "pion2_dzErr/D");
   noCuts->Branch("pion2_dxy",      &out_pion2_dxy,   "pion2_dxy/D");
   noCuts->Branch("pion2_dxyErr",      &out_pion2_dxyErr,   "pion2_dxyErr/D");

   noCuts->Branch("pion2_PV",      &out_pion2_PV,   "pion2_PV/I");
   noCuts->Branch("pion2_refVtx",      &out_pion2_refVtx,   "pion2_refVtx/I");
   noCuts->Branch("pion2_pvAssocQ",      &out_pion2_pvAssocQ,   "pion2_pvAssocQ/I");
   noCuts->Branch("pion2_dzAssocPV",      &out_pion2_dzAssocPV,   "pion2_dzAssocPV/D");

   noCuts->Branch("dR_pi1Vdimu",      &out_dR_pi1Vdimu,   "dR_pi1Vdimu/D");
   noCuts->Branch("dR_pi2Vdimu",      &out_dR_pi2Vdimu,   "dR_pi2Vdimu/D");

   ////////////////////////////////////////////////////////////
   multip = new TTree("multip","multip");
   multip->Branch("Multiplicity",       &out_Multiplicity_raw,   "Multiplicity/D");
   multip->Branch("dimuon_M",      &out_dimuon_M_raw,   "dimuon_M/D");
   multip->Branch("dimuon_Pt",      &out_dimuon_Pt_raw,   "dimuon_Pt/D");
   multip->Branch("iPVwithmuons",      &out_iPVwithmuons_raw,   "iPVwithmuons/I");
   multip->Branch("pion1_refVtx",      &out_pion1_refVtx_raw,   "pion1_refVtx/I");
   multip->Branch("pion2_refVtx",      &out_pion2_refVtx_raw,   "pion2_refVtx/I");

   ////////////////////////////////////////////////////////////
   base = new TTree("base","base");
   base->Branch("y1Spipi_M",      &out_y1Spipi_M_base,   "y1Spipi_M/D");
   base->Branch("y1Spipi_vProb",      &out_y1Spipi_vProb_base,   "y1Spipi_vProb/D");
   base->Branch("y1Spipi_Pt",      &out_y1Spipi_Pt_base,   "y1Spipi_Pt/D");
   base->Branch("y1Spipi_E",      &out_y1Spipi_E_base,   "y1Spipi_E/D");
   base->Branch("y1Spipi_y",      &out_y1Spipi_y_base,   "y1Spipi_y/D");
   base->Branch("y1Spipi_Eta",      &out_y1Spipi_Eta_base,   "y1Spipi_Eta/D");
   base->Branch("y1Spipi_Phi",      &out_y1Spipi_Phi_base,   "y1Spipi_Phi/D");
   
   base->Branch("ditrack_M",      &out_ditrack_M_base,   "ditrack_M/D");
   base->Branch("ditrack_Pt",      &out_ditrack_Pt_base,   "ditrack_Pt/D");
   base->Branch("ditrack_E",      &out_ditrack_E_base,   "ditrack_E/D");
   base->Branch("ditrack_Eta",      &out_ditrack_Eta_base,   "ditrack_Eta/D");
   base->Branch("ditrack_y",      &out_ditrack_y_base,   "ditrack_y/D");
   base->Branch("ditrack_Phi",      &out_ditrack_Phi_base,   "ditrack_Phi/D");

   base->Branch("numPrimaryVertices",      &out_numPrimaryVertices_base,   "numPrimaryVertices/I");
   base->Branch("iPVwithmuons",      &out_iPVwithmuons_base,   "iPVwithmuons/I");

   base->Branch("dimuon_M",      &out_dimuon_M_base,   "dimuon_M/D");
   base->Branch("dimuon_Pt",      &out_dimuon_Pt_base,   "dimuon_Pt/D");
   base->Branch("dimuon_E",      &out_dimuon_E_base,   "dimuon_E/D");
   base->Branch("dimuon_Eta",      &out_dimuon_Eta_base,   "dimuon_Eta/D");
   base->Branch("dimuon_y",      &out_dimuon_y_base,   "dimuon_y/D");
   base->Branch("dimuon_Phi",      &out_dimuon_Phi_base,   "dimuon_Phi/D");

   base->Branch("muonp_M",      &out_muonp_M_base,   "muonp_M/D");
   base->Branch("muonp_Pt",      &out_muonp_Pt_base,   "muonp_Pt/D");
   base->Branch("muonp_E",      &out_muonp_E_base,   "muonp_E/D");
   base->Branch("muonp_Eta",      &out_muonp_Eta_base,   "muonp_Eta/D");
   base->Branch("muonp_y",      &out_muonp_y_base,   "muonp_y/D");
   base->Branch("muonp_Phi",      &out_muonp_Phi_base,   "muonp_Phi/D");

   base->Branch("muonn_M",      &out_muonn_M_base,   "muonn_M/D");
   base->Branch("muonn_Pt",      &out_muonn_Pt_base,   "muonn_Pt/D");
   base->Branch("muonn_E",      &out_muonn_E_base,   "muonn_E/D");
   base->Branch("muonn_Eta",      &out_muonn_Eta_base,   "muonn_Eta/D");
   base->Branch("muonn_y",      &out_muonn_y_base,   "muonn_y/D");
   base->Branch("muonn_Phi",      &out_muonn_Phi_base,   "muonn_Phi/D");

   base->Branch("pion1_Pt",      &out_pion1_Pt_base,   "pion1_Pt/D");
   base->Branch("pion1_E",      &out_pion1_E_base,   "pion1_E/D");
   base->Branch("pion1_Eta",      &out_pion1_Eta_base,   "pion1_Eta/D");
   base->Branch("pion1_y",      &out_pion1_y_base,   "pion1_y/D");
   base->Branch("pion1_Phi",      &out_pion1_Phi_base,   "pion1_Phi/D");

   base->Branch("pion2_Pt",      &out_pion2_Pt_base,   "pion2_Pt/D");
   base->Branch("pion2_E",      &out_pion2_E_base,   "pion2_E/D");
   base->Branch("pion2_Eta",      &out_pion2_Eta_base,   "pion2_Eta/D");
   base->Branch("pion2_y",      &out_pion2_y_base,   "pion2_y/D");
   base->Branch("pion2_Phi",      &out_pion2_Phi_base,   "pion2_Phi/D");

   base->Branch("pion1_dz",      &out_pion1_dz_base,   "pion1_dz/D");
   base->Branch("pion1_dzErr",      &out_pion1_dzErr_base,   "pion1_dzErr/D");
   base->Branch("pion1_dxy",      &out_pion1_dxy_base,   "pion1_dxy/D");
   base->Branch("pion1_dxyErr",      &out_pion1_dxyErr_base,   "pion1_dxyErr/D");

   base->Branch("pion1_PV",      &out_pion1_PV_base,   "pion1_PV/I");
   base->Branch("pion1_refVtx",      &out_pion1_refVtx_base,   "pion1_refVtx/I");
   base->Branch("pion1_pvAssocQ",      &out_pion1_pvAssocQ_base,   "pion1_pvAssocQ/I");
   base->Branch("pion1_dzAssocPV",      &out_pion1_dzAssocPV_base,   "pion1_dzAssocPV/D");

   base->Branch("pion2_dz",      &out_pion2_dz_base,   "pion2_dz/D");
   base->Branch("pion2_dzErr",      &out_pion2_dzErr_base,   "pion2_dzErr/D");
   base->Branch("pion2_dxy",      &out_pion2_dxy_base,   "pion2_dxy/D");
   base->Branch("pion2_dxyErr",      &out_pion2_dxyErr_base,   "pion2_dxyErr/D");

   base->Branch("pion2_PV",      &out_pion2_PV_base,   "pion2_PV/I");
   base->Branch("pion2_refVtx",      &out_pion2_refVtx_base,   "pion2_refVtx/I");
   base->Branch("pion2_pvAssocQ",      &out_pion2_pvAssocQ_base,   "pion2_pvAssocQ/I");
   base->Branch("pion2_dzAssocPV",      &out_pion2_dzAssocPV_base,   "pion2_dzAssocPV/D");

   base->Branch("dR_pi1Vdimu",      &out_dR_pi1Vdimu_base,   "dR_pi1Vdimu/D");
   base->Branch("dR_pi2Vdimu",      &out_dR_pi2Vdimu_base,   "dR_pi2Vdimu/D");

   ////////////////////////////////////////////////////////////
   best = new TTree("best","best");
   best->Branch("y1Spipi_M_bPt",      &out_y1Spipi_M_bestPt,   "y1Spipi_M_bPt/D");
   best->Branch("y1Spipi_vProb_bPt",      &out_y1Spipi_vProb_bestPt,   "y1Spipi_vProb_bPt/D");
   best->Branch("y1Spipi_Pt_bPt",      &out_y1Spipi_Pt_bestPt,   "y1Spipi_Pt_bPt/D");
   best->Branch("y1Spipi_E_bPt",      &out_y1Spipi_E_bestPt,   "y1Spipi_E_bPt/D");
   best->Branch("y1Spipi_y_bPt",      &out_y1Spipi_y_bestPt,   "y1Spipi_y_bPt/D");
   best->Branch("y1Spipi_Eta_bPt",      &out_y1Spipi_Eta_bestPt,   "y1Spipi_Eta_bPt/D");
   best->Branch("y1Spipi_Phi_bPt",      &out_y1Spipi_Phi_bestPt,   "y1Spipi_Phi_bPt/D");
   
   best->Branch("ditrack_M_bPt",      &out_ditrack_M_bestPt,   "ditrack_M_bPt_bPt/D");
   best->Branch("ditrack_Pt_bPt",      &out_ditrack_Pt_bestPt,   "ditrack_Pt_bPt/D");
   best->Branch("ditrack_E_bPt",      &out_ditrack_E_bestPt,   "ditrack_E_bPt/D");
   best->Branch("ditrack_Eta_bPt",      &out_ditrack_Eta_bestPt,   "ditrack_Eta_bPt/D");
   best->Branch("ditrack_y_bPt",      &out_ditrack_y_bestPt,   "ditrack_y_bPt/D");
   best->Branch("ditrack_Phi_bPt",      &out_ditrack_Phi_bestPt,   "ditrack_Phi_bPt/D");

   best->Branch("dimuon_M_bPt",      &out_dimuon_M_bestPt,   "dimuon_M_bPt/D");
   best->Branch("dimuon_Pt_bPt",      &out_dimuon_Pt_bestPt,   "dimuon_Pt_bPt/D");
   best->Branch("dimuon_E_bPt",      &out_dimuon_E_bestPt,   "dimuon_E_bPt/D");
   best->Branch("dimuon_Eta_bPt",      &out_dimuon_Eta_bestPt,   "dimuon_Eta_bPt/D");
   best->Branch("dimuon_y_bPt",      &out_dimuon_y_bestPt,   "dimuon_y_bPt/D");
   best->Branch("dimuon_Phi_bPt",      &out_dimuon_Phi_bestPt,   "dimuon_Phi_bPt/D");

   best->Branch("muonp_M_bPt",      &out_muonp_M_bestPt,   "muonp_M_bPt/D");
   best->Branch("muonp_Pt_bPt",      &out_muonp_Pt_bestPt,   "muonp_Pt_bPt/D");
   best->Branch("muonp_E_bPt",      &out_muonp_E_bestPt,   "muonp_E_bPt/D");
   best->Branch("muonp_Eta_bPt",      &out_muonp_Eta_bestPt,   "muonp_Eta_bPt/D");
   best->Branch("muonp_y_bPt",      &out_muonp_y_bestPt,   "muonp_y_bPt/D");
   best->Branch("muonp_Phi_bPt",      &out_muonp_Phi_bestPt,   "muonp_Phi_bPt/D");

   best->Branch("muonn_M_bPt",      &out_muonn_M_bestPt,   "muonn_M_bPt/D");
   best->Branch("muonn_Pt_bPt",      &out_muonn_Pt_bestPt,   "muonn_Pt_bPt/D");
   best->Branch("muonn_E_bPt",      &out_muonn_E_bestPt,   "muonn_E_bPt/D");
   best->Branch("muonn_Eta_bPt",      &out_muonn_Eta_bestPt,   "muonn_Eta_bPt/D");
   best->Branch("muonn_y_bPt",      &out_muonn_y_bestPt,   "muonn_y_bPt/D");
   best->Branch("muonn_Phi_bPt",      &out_muonn_Phi_bestPt,   "muonn_Phi_bPt/D");

   best->Branch("pion1_Pt_bPt",      &out_pion1_Pt_bestPt,   "pion1_Pt_bPt/D");
   best->Branch("pion1_E_bPt",      &out_pion1_E_bestPt,   "pion1_E_bPt/D");
   best->Branch("pion1_Eta_bPt",      &out_pion1_Eta_bestPt,   "pion1_Eta_bPt/D");
   best->Branch("pion1_y_bPt",      &out_pion1_y_bestPt,   "pion1_y_bPt/D");
   best->Branch("pion1_Phi_bPt",      &out_pion1_Phi_bestPt,   "pion1_Phi_bPt/D");

   best->Branch("pion2_Pt_bPt",      &out_pion2_Pt_bestPt,   "pion2_Pt_bPt/D");
   best->Branch("pion2_E_bPt",      &out_pion2_E_bestPt,   "pion2_E_bPt/D");
   best->Branch("pion2_Eta_bPt",      &out_pion2_Eta_bestPt,   "pion2_Eta_bPt/D");
   best->Branch("pion2_y_bPt",      &out_pion2_y_bestPt,   "pion2_y_bPt/D");
   best->Branch("pion2_Phi_bPt",      &out_pion2_Phi_bestPt,   "pion2_Phi_bPt/D");

   best->Branch("y1Spipi_M_bVtx",      &out_y1Spipi_M_bestVtx,   "y1Spipi_M_bVtx/D");
   best->Branch("ditrack_M_bVtx",      &out_ditrack_M_bestVtx,   "ditrack_M_bVtx/D");

   //clean vectors
   candMultip_raw.clear();
   candMultip.clear();
}

Bool_t xb2y1Spipi::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   Bool_t HLTDimuonUps = false;
   Bool_t HLTDimuon12Upsilon_y1p4 = false;
   Bool_t HLTDimuon12Upsilon_eta1p5 = false;
   Bool_t HLTDimuon8Upsilon_Barrel = false;

   if ( ( (*trigger&128)==128 ) 
      || ( (*trigger&32)==32 ) 
      || ( (*trigger&256)==256 ) 
      ) HLTDimuonUps = true;

   if ( (*trigger&128)==128 ) HLTDimuon12Upsilon_y1p4 = true;
   if ( (*trigger&32)==32 ) HLTDimuon12Upsilon_eta1p5 = true;
   if ( (*trigger&256)==256 ) HLTDimuon8Upsilon_Barrel = true;

   if (//(HLTDimuon12Upsilon_y1p4 == true || HLTDimuon12Upsilon_eta1p5 == true)
      //HLTDimuon8Upsilon_Barrel == true
      HLTDimuonUps == true
      && 0 == *track1_refVtx && 0 == *track2_refVtx
      && *iPVwithmuons == 0
      && *candidate_vProb > 0.01 && *candidate_charge == 0 
      && ( (*track1_charge) * (*track2_charge) ) < 0
      && *track1_dRdimuon < 0.7 && *track2_dRdimuon <0.7
      ) {

      if (track1_p4->Pt()>track2_p4->Pt()) {
         pionL_Pt = track1_p4->Pt();
         pionS_Pt = track2_p4->Pt();
      } else {
         pionL_Pt = track2_p4->Pt();
         pionS_Pt = track1_p4->Pt();
      }

      if (*track1_charge>0 && *track2_charge<0) {
         pion1_charge = *track1_charge; pion2_charge = *track2_charge;
         pion1_Pt = track1_p4->Pt(); pion2_Pt = track2_p4->Pt();
         pion1_E = track1_p4->Energy(); pion1_Eta = track1_p4->Eta(); pion1_y = track1_p4->Rapidity(); pion1_Phi = track1_p4->Phi();
         pion2_E = track2_p4->Energy(); pion2_Eta = track2_p4->Eta(); pion2_y = track2_p4->Rapidity(); pion2_Phi = track2_p4->Phi();
         pion1_dz = *track1_dz; pion1_dxy = *track1_dxy; pion1_dzErr = *track1_dzErr; pion1_dxyErr = *track1_dxyErr;
         pion1_PV = *track1_PV; pion1_refVtx = *track1_refVtx; pion1_pvAssocQ = *track1_pvAssocQ; pion1_dzAssocPV = *track1_dzAssocPV;
         pion2_dz = *track2_dz; pion2_dxy = *track2_dxy; pion2_dzErr = *track2_dzErr; pion2_dxyErr = *track2_dxyErr;
         pion2_PV = *track2_PV; pion2_refVtx = *track2_refVtx; pion2_pvAssocQ = *track2_pvAssocQ; pion2_dzAssocPV = *track2_dzAssocPV;
         dR_pi1Vdimu = *track1_dRdimuon; dR_pi2Vdimu = *track2_dRdimuon;
      } else if (*track1_charge<0 && *track2_charge>0){
         pion1_charge = *track2_charge; pion2_charge = *track1_charge;
         pion1_Pt = track2_p4->Pt(); pion2_Pt = track1_p4->Pt();
         pion1_E = track2_p4->Energy(); pion2_Eta = track2_p4->Eta(); pion2_y = track2_p4->Rapidity(); pion2_Phi = track2_p4->Phi();
         pion2_E = track1_p4->Energy(); pion1_Eta = track1_p4->Eta(); pion1_y = track1_p4->Rapidity(); pion1_Phi = track1_p4->Phi();
         pion1_dz = *track2_dz; pion1_dxy = *track2_dxy; pion1_dzErr = *track2_dzErr; pion1_dxyErr = *track2_dxyErr;
         pion1_PV = *track2_PV; pion1_refVtx = *track2_refVtx; pion1_pvAssocQ = *track2_pvAssocQ; pion1_dzAssocPV = *track2_dzAssocPV;
         pion2_dz = *track1_dz; pion2_dxy = *track1_dxy; pion2_dzErr = *track1_dzErr; pion2_dxyErr = *track1_dxyErr;
         pion2_PV = *track1_PV; pion2_refVtx = *track1_refVtx; pion2_pvAssocQ = *track1_pvAssocQ; pion2_dzAssocPV = *track1_dzAssocPV;
         dR_pi1Vdimu = *track2_dRdimuon; dR_pi2Vdimu = *track1_dRdimuon;
      }

      y1spipi_M = *candidate_vMass;

      out_y1Spipi_M = y1spipi_M;
      out_y1Spipi_vProb = *candidate_vProb;
      out_y1Spipi_Pt = candidate_p4->Pt();
      out_y1Spipi_E = candidate_p4->Energy();
      out_y1Spipi_y = candidate_p4->Rapidity();
      out_y1Spipi_Eta = candidate_p4->Eta();
      out_y1Spipi_Phi = candidate_p4->Phi();

      out_ditrack_M = ditrack_p4->M();
      out_ditrack_Pt = ditrack_p4->Pt();
      out_ditrack_E = ditrack_p4->Energy();
      out_ditrack_Eta = ditrack_p4->Eta();
      out_ditrack_y = ditrack_p4->Rapidity();
      out_ditrack_Phi = ditrack_p4->Phi();

      out_dimuon_M = dimuon_p4->M();
      out_dimuon_Pt = dimuon_p4->Pt();
      out_dimuon_E = dimuon_p4->Energy();
      out_dimuon_Eta = dimuon_p4->Eta();
      out_dimuon_y = dimuon_p4->Rapidity();
      out_dimuon_Phi = dimuon_p4->Phi();

      out_muonp_M = muonp_p4->M();
      out_muonp_Pt = muonp_p4->Pt();
      out_muonp_Eta = muonp_p4->Eta();
      out_muonp_y = muonp_p4->Rapidity();
      out_muonp_Phi = muonp_p4->Phi();

      out_muonn_M = muonn_p4->M();
      out_muonn_Pt = muonn_p4->Pt();
      out_muonn_Eta = muonn_p4->Eta();
      out_muonn_y = muonn_p4->Rapidity();
      out_muonn_Phi = muonn_p4->Phi();

      out_numPrimaryVertices = *numPrimaryVertices;
      out_iPVwithmuons = *iPVwithmuons;

      out_pion1_Pt = pion1_Pt;
      out_pion1_E = pion1_E;
      out_pion1_Eta = pion1_Eta;
      out_pion1_y = pion1_y;
      out_pion1_Phi = pion1_Phi;

      out_pion2_Pt = pion2_Pt;
      out_pion2_E = pion2_E;
      out_pion2_Eta = pion2_Eta;
      out_pion2_y = pion2_y;
      out_pion2_Phi = pion2_Phi;

      out_pion1_dz = pion1_dz;
      out_pion1_dzErr = pion1_dzErr;
      out_pion1_dxy = pion1_dxy;
      out_pion1_dxyErr = pion1_dxyErr;
      out_pion1_PV = pion1_PV;
      out_pion1_refVtx = pion1_refVtx;
      out_pion1_pvAssocQ = pion1_pvAssocQ;
      out_pion1_dzAssocPV = pion1_dzAssocPV;

      out_pion2_dz = pion2_dz;
      out_pion2_dzErr = pion2_dzErr;
      out_pion2_dxy = pion2_dxy;
      out_pion2_dxyErr = pion2_dxyErr;
      out_pion2_PV = pion2_PV;
      out_pion2_refVtx = pion2_refVtx;
      out_pion2_pvAssocQ = pion2_pvAssocQ;
      out_pion2_dzAssocPV = pion2_dzAssocPV;

      out_dR_pi1Vdimu = dR_pi1Vdimu;
      out_dR_pi2Vdimu = dR_pi2Vdimu;
      noCuts->Fill();

      evntT0 = *event;
      if (evntT0_ == evntT0) {        
         candMultip_raw.push_back(std::make_tuple(*event, candidate_p4->Pt(), y1spipi_M, *candidate_vProb, dimuon_p4->M(), dimuon_p4->Pt(), *iPVwithmuons, pion1_refVtx, pion2_refVtx, ditrack_p4->M()));
      } else if (evntT0_ != evntT0) {
         evntT0_ = evntT0;
         Int_t sizeCandMultip_raw = candMultip_raw.size();

         if (sizeCandMultip_raw > 0){

            if ( sizeCandMultip_raw < 6 ) {
               out_Multiplicity_raw = sizeCandMultip_raw;
            } else {
               out_Multiplicity_raw = 6;
            }
            
            sort(candMultip_raw.begin(), candMultip_raw.end(), sortPtForMultip);
            out_dimuon_M_raw = get<4>(candMultip_raw[0]);
            out_dimuon_Pt_raw = get<5>(candMultip_raw[0]);
            out_iPVwithmuons_raw = get<6>(candMultip_raw[0]);
            out_pion1_refVtx_raw = get<7>(candMultip_raw[0]);
            out_pion2_refVtx_raw = get<8>(candMultip_raw[0]);
            multip->Fill();

         }
         candMultip_raw.clear();
         candMultip_raw.shrink_to_fit();
         candMultip_raw.push_back(std::make_tuple(*event, candidate_p4->Pt(), y1spipi_M, *candidate_vProb, dimuon_p4->M(), dimuon_p4->Pt(), *iPVwithmuons, pion1_refVtx, pion2_refVtx, ditrack_p4->M())); 
      }

      if (HLTDimuonUps == true
         && dimuon_p4->Pt() > 12 && dimuon_p4->Rapidity() < 1.4
         && dimuon_p4->M() > 9.3 && dimuon_p4->M() < 9.6
         && fabs(muonp_p4->Eta()) < 1.5 && fabs(muonn_p4->Eta()) < 1.5
         && pionL_Pt > 0.7 && pionS_Pt > 0.5
         && *candidate_vProb > Pvtx
         ) {
         out_y1Spipi_M_base = y1spipi_M;
         out_y1Spipi_Pt_base = candidate_p4->Pt();
         out_y1Spipi_vProb_base = *candidate_vProb;
         out_y1Spipi_E_base = candidate_p4->Energy();
         out_y1Spipi_y_base = candidate_p4->Rapidity();
         out_y1Spipi_Eta_base = candidate_p4->Eta();
         out_y1Spipi_Phi_base = candidate_p4->Phi();

         out_ditrack_M_base = ditrack_p4->M();
         out_ditrack_Pt_base = ditrack_p4->Pt();
         out_ditrack_E_base = ditrack_p4->Energy();
         out_ditrack_Eta_base = ditrack_p4->Eta();
         out_ditrack_y_base = ditrack_p4->Rapidity();
         out_ditrack_Phi_base = ditrack_p4->Phi();

         out_numPrimaryVertices_base = *numPrimaryVertices;
         out_iPVwithmuons_base = *iPVwithmuons;

         out_dimuon_M_base = dimuon_p4->M();
         out_dimuon_Pt_base = dimuon_p4->Pt();
         out_dimuon_E_base = dimuon_p4->Energy();
         out_dimuon_Eta_base = dimuon_p4->Eta();
         out_dimuon_y_base = dimuon_p4->Rapidity();
         out_dimuon_Phi_base = dimuon_p4->Phi();

         out_muonp_M_base = muonp_p4->M();
         out_muonp_Pt_base = muonp_p4->Pt();
         out_muonp_Eta_base = muonp_p4->Eta();
         out_muonp_y_base = muonp_p4->Rapidity();
         out_muonp_Phi_base = muonp_p4->Phi();

         out_muonn_M_base = muonn_p4->M();
         out_muonn_Pt_base = muonn_p4->Pt();
         out_muonn_Eta_base = muonn_p4->Eta();
         out_muonn_y_base = muonn_p4->Rapidity();
         out_muonn_Phi_base = muonn_p4->Phi();

         out_pion1_Pt_base = pion1_Pt;
         out_pion1_E_base = pion1_E;
         out_pion1_Eta_base = pion1_Eta;
         out_pion1_y_base = pion1_y;
         out_pion1_Phi_base = pion1_Phi;

         out_pion2_Pt_base = pion2_Pt;
         out_pion2_E_base = pion2_E;
         out_pion2_Eta_base = pion2_Eta;
         out_pion2_y_base = pion2_y;
         out_pion2_Phi_base = pion2_Phi;

         out_pion1_dz_base = pion1_dz;
         out_pion1_dzErr_base = pion1_dzErr;
         out_pion1_dxy_base = pion1_dxy;
         out_pion1_dxyErr_base = pion1_dxyErr;
         out_pion1_PV_base = pion1_PV;
         out_pion1_refVtx_base = pion1_refVtx;
         out_pion1_pvAssocQ_base = pion1_pvAssocQ;
         out_pion1_dzAssocPV_base = pion1_dzAssocPV;
         out_pion2_dz_base = pion2_dz;
         out_pion2_dzErr_base = pion2_dzErr;
         out_pion2_dxy_base = pion2_dxy;
         out_pion2_dxyErr_base = pion2_dxyErr;
         out_pion2_PV_base = pion2_PV;
         out_pion2_refVtx_base = pion2_refVtx;
         out_pion2_pvAssocQ_base = pion2_pvAssocQ;
         out_pion2_dzAssocPV_base = pion2_dzAssocPV;
         out_dR_pi1Vdimu_base = dR_pi1Vdimu;
         out_dR_pi2Vdimu_base = dR_pi2Vdimu;
         base->Fill();

         evntT1 = *event;
         if (evntT2 == evntT1) {
            candMultip.push_back(std::make_tuple(*event, candidate_p4->Pt(), y1spipi_M, *candidate_vProb, candidate_p4->Energy(), candidate_p4->Rapidity(), candidate_p4->Eta(), candidate_p4->Phi(), /*8*/
                                                ditrack_p4->M(), ditrack_p4->Pt(), ditrack_p4->Energy(), ditrack_p4->Eta(), ditrack_p4->Rapidity(), ditrack_p4->Phi(), /*6*/
                                                dimuon_p4->M(), dimuon_p4->Pt(), dimuon_p4->Energy(), dimuon_p4->Eta(), dimuon_p4->Rapidity(), dimuon_p4->Phi(), /*6*/
                                                muonp_p4->M(), muonp_p4->Pt(), muonp_p4->Eta(), muonp_p4->Rapidity(), muonp_p4->Phi(), /*5*/
                                                muonn_p4->M(), muonn_p4->Pt(), muonn_p4->Eta(), muonn_p4->Rapidity(), muonn_p4->Phi(), /*5*/
                                                pion1_Pt, pion1_E, pion1_Eta, pion1_y, pion1_Phi, /*5*/
                                                pion2_Pt, pion2_E, pion2_Eta, pion2_y, pion2_Phi /*5*/));
         } else if (evntT2 != evntT1) {
            evntT2 = evntT1;
            Int_t sizeCandMultip = candMultip.size();

            if (sizeCandMultip > 0){

               sort(candMultip.begin(), candMultip.end(), sortPt); 

               out_y1Spipi_Pt_bestPt = get<1>(candMultip[0]);
               out_y1Spipi_M_bestPt = get<2>(candMultip[0]);
               out_y1Spipi_vProb_bestPt = get<3>(candMultip[0]);
               out_y1Spipi_E_bestPt = get<4>(candMultip[0]);
               out_y1Spipi_y_bestPt = get<5>(candMultip[0]);
               out_y1Spipi_Eta_bestPt = get<6>(candMultip[0]);
               out_y1Spipi_Phi_bestPt = get<7>(candMultip[0]);

               out_ditrack_M_bestPt = get<8>(candMultip[0]);
               out_ditrack_Pt_bestPt = get<9>(candMultip[0]);
               out_ditrack_E_bestPt = get<10>(candMultip[0]);
               out_ditrack_Eta_bestPt = get<11>(candMultip[0]);
               out_ditrack_y_bestPt = get<12>(candMultip[0]);
               out_ditrack_Phi_bestPt = get<13>(candMultip[0]);

               out_dimuon_M_bestPt = get<14>(candMultip[0]);
               out_dimuon_Pt_bestPt = get<15>(candMultip[0]);
               out_dimuon_E_bestPt = get<16>(candMultip[0]);
               out_dimuon_Eta_bestPt = get<17>(candMultip[0]);
               out_dimuon_y_bestPt = get<18>(candMultip[0]);
               out_dimuon_Phi_bestPt = get<19>(candMultip[0]);

               out_muonp_M_bestPt = get<20>(candMultip[0]);
               out_muonp_Pt_bestPt = get<21>(candMultip[0]);
               out_muonp_Eta_bestPt = get<22>(candMultip[0]);
               out_muonp_y_bestPt = get<23>(candMultip[0]);
               out_muonp_Phi_bestPt = get<24>(candMultip[0]);

               out_muonn_M_bestPt = get<25>(candMultip[0]);
               out_muonn_Pt_bestPt = get<26>(candMultip[0]);
               out_muonn_Eta_bestPt = get<27>(candMultip[0]);
               out_muonn_y_bestPt = get<28>(candMultip[0]);
               out_muonn_Phi_bestPt = get<29>(candMultip[0]);

               out_pion1_Pt_bestPt = get<30>(candMultip[0]);
               out_pion1_E_bestPt = get<31>(candMultip[0]);
               out_pion1_Eta_bestPt = get<32>(candMultip[0]);
               out_pion1_y_bestPt = get<33>(candMultip[0]);
               out_pion1_Phi_bestPt = get<34>(candMultip[0]);

               out_pion2_Pt_bestPt = get<35>(candMultip[0]);
               out_pion2_E_bestPt = get<36>(candMultip[0]);
               out_pion2_Eta_bestPt = get<37>(candMultip[0]);
               out_pion2_y_bestPt = get<38>(candMultip[0]);
               out_pion2_Phi_bestPt = get<39>(candMultip[0]);

               sort(candMultip.begin(), candMultip.end(), sortVtx); 
               
               out_y1Spipi_M_bestVtx = get<2>(candMultip[0]);
               out_ditrack_M_bestVtx = get<8>(candMultip[0]);

               best->Fill();

            }
            candMultip.clear();
            candMultip.shrink_to_fit();
            candMultip.push_back(std::make_tuple(*event, candidate_p4->Pt(), y1spipi_M, *candidate_vProb, candidate_p4->Energy(), candidate_p4->Rapidity(), candidate_p4->Eta(), candidate_p4->Phi(), /*8*/
                                                ditrack_p4->M(), ditrack_p4->Pt(), ditrack_p4->Energy(), ditrack_p4->Eta(), ditrack_p4->Rapidity(), ditrack_p4->Phi(), /*6*/
                                                dimuon_p4->M(), dimuon_p4->Pt(), dimuon_p4->Energy(), dimuon_p4->Eta(), dimuon_p4->Rapidity(), dimuon_p4->Phi(), /*6*/
                                                muonp_p4->M(), muonp_p4->Pt(), muonp_p4->Eta(), muonp_p4->Rapidity(), muonp_p4->Phi(), /*5*/
                                                muonn_p4->M(), muonn_p4->Pt(), muonn_p4->Eta(), muonn_p4->Rapidity(), muonn_p4->Phi(), /*5*/
                                                pion1_Pt, pion1_E, pion1_Eta, pion1_y, pion1_Phi, /*5*/
                                                pion2_Pt, pion2_E, pion2_Eta, pion2_y, pion2_Phi /*5*/));
         }

      } //Baseline selection
   } //Analyzer selection
   return kTRUE;
}

void xb2y1Spipi::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   TDirectory *savedir = gDirectory;
   if (fOut)
   {
      fOut->cd();
      gStyle->SetOptStat(111111);

      noCuts->Write();
      multip->Write();
      base->Write();
      best->Write();

      OutFile->Print();
      fOutput->Add(OutFile);
      gDirectory = savedir;
      fOut->Close();
    }
}

void xb2y1Spipi::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}