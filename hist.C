enum DrawOpt {
    edep
};

void draw(DrawOpt opt);


void hist(){
	//TFile *fin = new TFile("/home/piotrek/kratta-build/steppingAction_t0.root"); //plik wejściowy
	TFile *fout = new TFile("pics.root","recreate"); //plik wyjsciowy

	TChain *chain = new TChain("T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t0.root/T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t1.root/T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t2.root/T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t3.root/T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t4.root/T");
	chain->Add("/home/piotrek/kratta-build/steppingAction_t5.root/T");

	TH1F* edep = new TH1F("edep","edep", 200, 0, 3); //(nazwa,tytul)
	TH2F* phivstheta = new TH2F("phivstheta","phivstheta",100,0,50,100,-50,0);
	//TNtuple *T = (TNtuple*)fin->Get("T");

	chain->Project("edep","edep_Plastic","edep_Plastic>0");
	// chain->Project("phivstheta","phi:theta","kr_nb==14||kr_nb==12||kr_nb==10");
	chain->Project("phivstheta","phi:theta","kr_nb==14");
	edep->Write();
	phivstheta->Write();

	fout->Close();
	//fin->Close();  
}

void draw(DrawOpt opt)
{
	TCanvas *canvas = new TCanvas("picture", "picture",0,0,800,600);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0);
	canvas->ToggleEventStatus();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(0);canvas->SetTickx();
	canvas->SetTicky();
	canvas->SetLeftMargin(0.15);
	canvas->SetBottomMargin(0.15);
	canvas->SetFrameFillColor(10);
	canvas->SetFrameLineWidth(2);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(0);
	canvas->SetFrameFillColor(10);
	canvas->SetFrameLineWidth(2);
	canvas->SetFrameBorderMode(0);
	canvas->SetFrameBorderSize(0);

	TH1F *edep = 0;
	TH2F *phivstheta = 0;

	canvas->Close();
}