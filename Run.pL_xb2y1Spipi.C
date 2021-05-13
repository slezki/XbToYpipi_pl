{
	TDSet* dataset = new TDSet("TTree", "CandidateTree", "rootuple");

	dataset->Add("/lustre/cms/store/user/slezki/XbDecays_DataRunII_miniAOD_v4/rootuple_y1Spipi_MuOnia_2016Data_miniAOD_v4.root");
	dataset->Add("/lustre/cms/store/user/slezki/XbDecays_DataRunII_miniAOD_v4/rootuple_y1Spipi_MuOnia_2017Data_miniAOD_v4.root");
	dataset->Add("/lustre/cms/store/user/slezki/XbDecays_DataRunII_miniAOD_v4/rootuple_y1Spipi_MuOnia_2018Data_miniAOD_v4.root");

	TString selector = "xb2y1Spipi";

	TProof *p = TProof::Open("workers=37");

	cout << ">> Processing " <<selector<<" ... "<<endl;

	TString selectorcplus =selector;
	selectorcplus += ".C+";

	p->Process(dataset, selectorcplus);
}
