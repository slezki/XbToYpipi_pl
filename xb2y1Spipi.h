//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct  8 11:25:37 2020 by ROOT version 6.16/00
// from TTree CandidateTree/Tree of Onia and Track
// found on file: /lustre/cms/store/user/slezki/XbDecays_DataRunII_miniAOD_v1/rootuple_y1Spipi_MuOnia_2018Data_miniAOD.root
//////////////////////////////////////////////////////////

#ifndef xb2y1Spipi_h
#define xb2y1Spipi_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TLorentzVector.h"

//User defined
#include <TProof.h>
#include <TProofOutputFile.h>

class xb2y1Spipi : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run = {fReader, "run"};
   TTreeReaderValue<Int_t> event = {fReader, "event"};
   TTreeReaderValue<Int_t> nCandPerEvent = {fReader, "nCandPerEvent"};
   TTreeReaderValue<Int_t> numPrimaryVertices = {fReader, "numPrimaryVertices"};
   TTreeReaderValue<Int_t> trigger = {fReader, "trigger"};
   TTreeReaderValue<TLorentzVector> candidate_p4 = {fReader, "candidate_p4"};
   TTreeReaderValue<TLorentzVector> track1_p4 = {fReader, "track1_p4"};
   TTreeReaderValue<TLorentzVector> track2_p4 = {fReader, "track2_p4"};
   TTreeReaderValue<TLorentzVector> ditrack_p4 = {fReader, "ditrack_p4"};
   TTreeReaderValue<TLorentzVector> dimuon_p4 = {fReader, "dimuon_p4"};
   TTreeReaderValue<TLorentzVector> muonp_p4 = {fReader, "muonp_p4"};
   TTreeReaderValue<TLorentzVector> muonn_p4 = {fReader, "muonn_p4"};
   TTreeReaderValue<Double_t> invm1Spipi = {fReader, "invm1Spipi"};
   TTreeReaderValue<Double_t> invm2Spipi = {fReader, "invm2Spipi"};
   TTreeReaderValue<Int_t> iPVwithmuons = {fReader, "iPVwithmuons"};
   TTreeReaderValue<Int_t> dimuon_vertexWeight = {fReader, "dimuon_vertexWeight"};
   TTreeReaderValue<Double_t> dimuon_vProb = {fReader, "dimuon_vProb"};
   TTreeReaderValue<Double_t> dimuon_vNChi2 = {fReader, "dimuon_vNChi2"};
   TTreeReaderValue<Double_t> dimuon_DCA = {fReader, "dimuon_DCA"};
   TTreeReaderValue<Double_t> dimuon_ctauPV = {fReader, "dimuon_ctauPV"};
   TTreeReaderValue<Double_t> dimuon_ctauErrPV = {fReader, "dimuon_ctauErrPV"};
   TTreeReaderValue<Double_t> dimuon_cosAlpha = {fReader, "dimuon_cosAlpha"};
   TTreeReaderValue<Double_t> dimuon_nSigma = {fReader, "dimuon_nSigma"};
   TTreeReaderValue<Double_t> candidate_vMass = {fReader, "candidate_vMass"};
   TTreeReaderValue<Double_t> candidate_vProb = {fReader, "candidate_vProb"};
   TTreeReaderValue<Double_t> candidate_vChi2 = {fReader, "candidate_vChi2"};
   TTreeReaderValue<Double_t> candidate_cosAlpha = {fReader, "candidate_cosAlpha"};
   TTreeReaderValue<Double_t> candidate_ctauPV = {fReader, "candidate_ctauPV"};
   TTreeReaderValue<Double_t> candidate_ctauErrPV = {fReader, "candidate_ctauErrPV"};
   TTreeReaderValue<Int_t> candidate_charge = {fReader, "candidate_charge"};
   TTreeReaderValue<Double_t> candidate_lxy = {fReader, "candidate_lxy"};
   TTreeReaderValue<Double_t> candidate_lxyErr = {fReader, "candidate_lxyErr"};
   TTreeReaderValue<Double_t> candidate_lxyz = {fReader, "candidate_lxyz"};
   TTreeReaderValue<Double_t> candidate_lxyzErr = {fReader, "candidate_lxyzErr"};
   TTreeReaderValue<Double_t> track1_d0 = {fReader, "track1_d0"};
   TTreeReaderValue<Double_t> track1_d0Err = {fReader, "track1_d0Err"};
   TTreeReaderValue<Double_t> track1_dz = {fReader, "track1_dz"};
   TTreeReaderValue<Double_t> track1_dzErr = {fReader, "track1_dzErr"};
   TTreeReaderValue<Double_t> track1_dxy = {fReader, "track1_dxy"};
   TTreeReaderValue<Double_t> track1_dxyErr = {fReader, "track1_dxyErr"};
   TTreeReaderValue<Int_t> track1_nvsh = {fReader, "track1_nvsh"};
   TTreeReaderValue<Int_t> track1_nvph = {fReader, "track1_nvph"};
   TTreeReaderValue<Double_t> track1_dRdimuon = {fReader, "track1_dRdimuon"};
   TTreeReaderValue<Double_t> track1_charge = {fReader, "track1_charge"};
   TTreeReaderValue<Int_t> track1_PV = {fReader, "track1_PV"};
   TTreeReaderValue<Int_t> track1_refVtx = {fReader, "track1_refVtx"};
   TTreeReaderValue<Int_t> track1_pvAssocQ = {fReader, "track1_pvAssocQ"};
   TTreeReaderValue<Double_t> track1_dzAssocPV = {fReader, "track1_dzAssocPV"};
   TTreeReaderValue<Double_t> track2_d0 = {fReader, "track2_d0"};
   TTreeReaderValue<Double_t> track2_d0Err = {fReader, "track2_d0Err"};
   TTreeReaderValue<Double_t> track2_dz = {fReader, "track2_dz"};
   TTreeReaderValue<Double_t> track2_dzErr = {fReader, "track2_dzErr"};
   TTreeReaderValue<Double_t> track2_dxy = {fReader, "track2_dxy"};
   TTreeReaderValue<Double_t> track2_dxyErr = {fReader, "track2_dxyErr"};
   TTreeReaderValue<Int_t> track2_nvsh = {fReader, "track2_nvsh"};
   TTreeReaderValue<Int_t> track2_nvph = {fReader, "track2_nvph"};
   TTreeReaderValue<Double_t> track2_dRdimuon = {fReader, "track2_dRdimuon"};
   TTreeReaderValue<Double_t> track2_charge = {fReader, "track2_charge"};
   TTreeReaderValue<Int_t> track2_PV = {fReader, "track2_PV"};
   TTreeReaderValue<Int_t> track2_refVtx = {fReader, "track2_refVtx"};
   TTreeReaderValue<Int_t> track2_pvAssocQ = {fReader, "track2_pvAssocQ"};
   TTreeReaderValue<Double_t> track2_dzAssocPV = {fReader, "track2_dzAssocPV"};
   TTreeReaderValue<Double_t> ditrack_dRdimuon = {fReader, "ditrack_dRdimuon"};


   xb2y1Spipi(TTree * /*tree*/ =0) { }
   virtual ~xb2y1Spipi() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   TProofOutputFile *OutFile;
   TFile            *fOut;

   Double_t mPi = 0.13957061;
   Double_t y1SMass = 9.46030;

   TTree *noCuts, *noCutsPV0, *noCutsPV010, *base, *multip, *best, *baseRefPV, *baseChkDzPV, *baseChkDzPVIfNot, *baseChkDzPVIfNotOr, *basePVAQ77, *basePVAQ76, *basePVAQ66, *basePV0, *basePV010, *basePV0RfPV0;

   Double_t Pvtx = 0.;
   Double_t pion1_charge = 0., pion1_dzAssocPV = 0., pion1_Pt = 0., pion1_dz = 0., pion1_dxy = 0., pion1_dzErr = 0., pion1_dxyErr = 0.;
   Int_t pion1_PV = 0, pion1_refVtx = 0, pion1_pvAssocQ = 0;
   Double_t pion2_charge = 0., pion2_dzAssocPV = 0., pion2_Pt = 0., pion2_dz = 0., pion2_dxy = 0., pion2_dzErr = 0., pion2_dxyErr = 0.;
   Int_t pion2_PV = 0, pion2_refVtx = 0, pion2_pvAssocQ = 0;
   Double_t dR_pi1Vdimu = 0., dR_pi2Vdimu = 0.;
   Double_t pionL_Pt = 0., pionS_Pt = 0.;
   Double_t y1spipi_M = 0.;
   Double_t pion1_E = 0., pion1_Eta = 0., pion1_y = 0., pion1_Phi = 0.; 
   Double_t pion2_E = 0., pion2_Eta = 0., pion2_y = 0., pion2_Phi = 0.; 

   //*noCuts
   Double_t out_y1Spipi_M, out_y1Spipi_vProb, out_y1Spipi_Pt, out_ditrack_M, out_dimuon_M, out_dimuon_Pt, out_dimuon_Eta, out_dimuon_y, out_dimuon_Phi, out_pion1_Pt, out_pion2_Pt, out_dR_pi1Vdimu, out_dR_pi2Vdimu;
   Double_t out_pion1_d0, out_pion1_d0Err, out_pion1_dz, out_pion1_dzErr, out_pion1_dxy, out_pion1_dxyErr, out_pion1_dzAssocPV;
   Double_t out_pion2_d0, out_pion2_d0Err, out_pion2_dz, out_pion2_dzErr, out_pion2_dxy, out_pion2_dxyErr, out_pion2_dzAssocPV;
   Int_t out_pion1_nvsh, out_pion1_nvph, out_pion1_charge, out_pion1_PV, out_pion1_refVtx, out_pion1_pvAssocQ;
   Int_t out_pion2_nvsh, out_pion2_nvph, out_pion2_charge, out_pion2_PV, out_pion2_refVtx, out_pion2_pvAssocQ;  
   Int_t out_iPVwithmuons, out_numPrimaryVertices;
   Double_t out_y1Spipi_y, out_y1Spipi_Eta, out_y1Spipi_Phi;
   Double_t out_y1Spipi_E, out_dimuon_E, out_pion1_M, out_pion1_E, out_pion1_Eta, out_pion1_y, out_pion1_Phi, out_pion2_M, out_pion2_E, out_pion2_Eta, out_pion2_y, out_pion2_Phi;
   Double_t out_ditrack_Pt, out_ditrack_E, out_ditrack_Eta, out_ditrack_y, out_ditrack_Phi, out_muonp_M, out_muonp_Pt, out_muonp_E, out_muonp_Eta, out_muonp_y, out_muonp_Phi, out_muonn_M, out_muonn_Pt, out_muonn_E, out_muonn_Eta, out_muonn_y, out_muonn_Phi;

   //*multip
   Double_t out_Multiplicity_raw, out_dimuon_M_raw, out_dimuon_Pt_raw, out_iPVwithmuons_raw, out_pion1_refVtx_raw, out_pion2_refVtx_raw;

   //*base
   Double_t out_y1Spipi_M_base, out_y1Spipi_vProb_base, out_y1Spipi_Pt_base, out_ditrack_M_base, out_pion1_Pt_base, out_pion2_Pt_base, out_dR_pi1Vdimu_base, out_dR_pi2Vdimu_base;
   Double_t out_pion1_d0_base, out_pion1_d0Err_base, out_pion1_dz_base, out_pion1_dzErr_base, out_pion1_dxy_base, out_pion1_dxyErr_base, out_pion1_dzAssocPV_base;
   Double_t out_pion2_d0_base, out_pion2_d0Err_base, out_pion2_dz_base, out_pion2_dzErr_base, out_pion2_dxy_base, out_pion2_dxyErr_base, out_pion2_dzAssocPV_base;
   Int_t out_pion1_nvsh_base, out_pion1_nvph_base, out_pion1_charge_base, out_pion1_PV_base, out_pion1_refVtx_base, out_pion1_pvAssocQ_base;
   Int_t out_pion2_nvsh_base, out_pion2_nvph_base, out_pion2_charge_base, out_pion2_PV_base, out_pion2_refVtx_base, out_pion2_pvAssocQ_base;
   Int_t out_iPVwithmuons_base, out_numPrimaryVertices_base;   
   Double_t out_y1Spipi_y_base, out_y1Spipi_Eta_base, out_y1Spipi_Phi_base;
   Double_t out_y1Spipi_E_base, out_dimuon_E_base, out_pion1_M_base, out_pion1_E_base, out_pion1_Eta_base, out_pion1_y_base, out_pion1_Phi_base, out_pion2_M_base, out_pion2_E_base, out_pion2_Eta_base, out_pion2_y_base, out_pion2_Phi_base;
   Double_t out_ditrack_Pt_base, out_ditrack_E_base, out_ditrack_Eta_base, out_ditrack_y_base, out_ditrack_Phi_base, out_muonp_M_base, out_muonp_Pt_base, out_muonp_E_base, out_muonp_Eta_base, out_muonp_y_base, out_muonp_Phi_base, out_muonn_M_base, out_muonn_Pt_base, out_muonn_E_base, out_muonn_Eta_base, out_muonn_y_base, out_muonn_Phi_base;
   Double_t out_dimuon_M_base, out_dimuon_Pt_base, out_dimuon_Eta_base, out_dimuon_y_base, out_dimuon_Phi_base;

   //*best
   Double_t out_y1Spipi_M_bestPt, out_y1Spipi_Pt_bestPt, out_y1Spipi_vProb_bestPt, out_y1Spipi_M_bestVtx, out_ditrack_M_bestPt, out_ditrack_M_bestVtx;
   Double_t out_y1Spipi_y_bestPt, out_y1Spipi_Eta_bestPt, out_y1Spipi_Phi_bestPt;
   Double_t out_y1Spipi_E_bestPt, out_dimuon_E_bestPt, out_pion1_M_bestPt, out_pion1_E_bestPt, out_pion1_Eta_bestPt, out_pion1_y_bestPt, out_pion1_Phi_bestPt, out_pion2_M_bestPt, out_pion2_E_bestPt, out_pion2_Eta_bestPt, out_pion2_y_bestPt, out_pion2_Phi_bestPt;
   Double_t out_ditrack_Pt_bestPt, out_ditrack_E_bestPt, out_ditrack_Eta_bestPt, out_ditrack_y_bestPt, out_ditrack_Phi_bestPt, out_muonp_M_bestPt, out_muonp_Pt_bestPt, out_muonp_E_bestPt, out_muonp_Eta_bestPt, out_muonp_y_bestPt, out_muonp_Phi_bestPt, out_muonn_M_bestPt, out_muonn_Pt_bestPt, out_muonn_E_bestPt, out_muonn_Eta_bestPt, out_muonn_y_bestPt, out_muonn_Phi_bestPt;
   Double_t out_dimuon_M_bestPt, out_dimuon_Pt_bestPt, out_dimuon_Eta_bestPt, out_dimuon_y_bestPt, out_dimuon_Phi_bestPt, out_pion1_Pt_bestPt, out_pion2_Pt_bestPt;

   //vectors for best selection criteria
   std::vector<std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t> > candMultip_raw;

   std::vector<std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, 
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t
                           > > candMultip;

   //variables to scan event by event
   Int_t evntT0 = 0, evntT0_ = 0, evntT1 = 0, evntT2 = 0, evntT3 = 0, evntT4 = 0, evntT5 = 0, evntT6 = 0, evntT7 = 0, evntT8 = 0, evntT9 = 0, evntT10 = 0;


   ClassDef(xb2y1Spipi,0);

};

#endif

Bool_t sortPtForMultip(const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t> &a,
               const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t> &b
               ){ return (get<1>(a) > get<1>(b)); }

Bool_t sortPt(const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, 
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t
                           > &a,
               const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, 
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t
                           > &b
               ){ return (get<1>(a) > get<1>(b)); }

Bool_t sortVtx(const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, 
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t
                           > &a,
               const std::tuple<Int_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, 
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t,
                           Double_t, Double_t, Double_t, Double_t, Double_t
                           > &b
               ){ return (get<3>(a) > get<3>(b)); }

#ifdef xb2y1Spipi_cxx
void xb2y1Spipi::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t xb2y1Spipi::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef xb2y1Spipi_cxx
