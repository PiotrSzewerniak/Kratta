enum DrawOpt {
    edep
};

void draw(DrawOpt opt);


void hist(){
	//TFile *fin = new TFile("/home/piotrek/kratta-build/steppingAction_t0.root"); //plik wejściowy
	
	char name[200];
	char name1[200];
	char name2[200];
	for(int i=50;i<=200;i+=30)
{
	sprintf(name,"/home/piotrek/Symulacje/%d_MeV/steppingAction_t0.root/T",i);
	sprintf(name1,"pics_%d.root",i);
	TFile *fout = new TFile(name1,"recreate"); //plik wyjsciowy

	TChain *chain = new TChain("T");
	sprintf(name,"/home/piotrek/Symulacje/%d_MeV/",i);
	for(int j=0;j<=5;j++)
	{
		sprintf(name2,"%s/steppingAction_t%d.root/T",name,j);
		chain->Add(name2);
	}


	TH1F* edep = new TH1F("edep","edep", 200, 0, 3); //(nazwa,tytul)
	TH2F* phivstheta = new TH2F("phivstheta","phivstheta",100,0,50,100,-50,0);
	TH1F* p0 = new TH1F("p0","p0",100,0,5);
	TH1F* p1 = new TH1F("p1","p1",100,0,5);
	TH2F* edepvsp0 = new TH2F("edepvsp0","edepvsp0",100,0,5,100,0,5);
	TH2F* edepvsp1 = new TH2F("edepvsp1","edepvsp1",100,0,5,100,0,5);
	TH1F* kr_nb = new TH1F("kr_nb","kr_nb",200, 0, 14);
	TH2F* edepvsshort = new TH2F("edepvsshort","edepvsshort",200,0,20,200,0,5);
	TH2F* edepvslong = new TH2F("edepvslong","edepvslong",200,0,140,200,0,5);
	TH2F* shortvslong = new TH2F("shortvslong","shortvslong",200,0,140,200,0,20);
	TH1F* edep_target = new TH1F("edep_target","edep_target",200,0,35);
	TH1F* edep_krHouse = new TH1F("edep_krHouse","edep_krHouse",200,-10,10);
	TH1F* edep_CsIshortgauss = new TH1F("edep_CsIshortgauss","edep_CsIshortgauss",200,0,45);
	//TNtuple *T = (TNtuple*)fin->Get("T");
	TH1F* edep_CsIshort = new TH1F("edep_CsIshort","edep_CsIshort",200,0,50);
	TH1F* edep_CsIlong = new TH1F("edep_CsIlong","edep_CsIlong",200,0,140);

	chain->Project("edep","edep_Plastic","edep_Plastic>0");
	// chain->Project("phivstheta","phi:theta","kr_nb==14||kr_nb==12||kr_nb==10");
	chain->Project("phivstheta","phi:theta","");
	chain->Project("p0","edep_PDactive0","kr_nb==13");
	chain->Project("p1","edep_PDactive1","kr_nb==13");
	// chain->Project("edepvsp0","edep_Plastic:edep_PDdeadF0+edep_PDdeadR0+edep_PDactive0","edep_Plastic>0 && edep_PDdeadF0+edep_PDdeadR0+edep_PDactive0>0");
	// chain->Project("edepvsp1","edep_Plastic:edep_PDdeadF1+edep_PDdeadR1+edep_PDactive1","edep_Plastic>0 && edep_PDdeadF1+edep_PDdeadR1+edep_PDactive1>0");
	chain->Project("edepvsp1","edep_Plastic:edep_PDactive1","edep_Plastic>0 && edep_PDactive1>0");
	chain->Project("edepvsp0","edep_Plastic:edep_PDactive0","edep_Plastic>0 && edep_PDactive0>0");
	chain->Project("kr_nb","kr_nb","");
	chain->Project("edepvsshort","edep_Plastic:edep_CsIshort","edep_Plastic>0 && edep_CsIshort>0");
	chain->Project("edepvslong","edep_Plastic:edep_CsIlong","edep_Plastic>0 && edep_CsIlong>0");
	chain->Project("shortvslong","edep_CsIshort:edep_CsIlong","kr_nb==13");
	chain->Project("edep_target","edep_target","");
	chain->Project("edep_krHouse","edep_krHouse","");
	chain->Project("edep_CsIshortgauss","edep_CsIshort","kr_nb==13");
	chain->Project("edep_CsIshort","edep_CsIshort","kr_nb==13");
	chain->Project("edep_CsIlong","edep_CsIlong","kr_nb==13");


	edep->Write();
	phivstheta->Write();
	p0->Write();
	p1->Write();
	edepvsp0->Write();
	edepvsp1->Write();
	kr_nb->Write();
	edepvsshort->Write();
	edepvslong->Write();
	shortvslong->Write();
	edep_target->Write();
	edep_krHouse->Write();
	edep_CsIshortgauss->Write();
	edep_CsIshort->Write();
	edep_CsIlong->Write();

	fout->Close();
}
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

	// TH1F *edep = 0;
	// TH2F *phivstheta = 0;
	// TH2F *edepvsp0 = 0;
	// TH1F *kr_nb = 0;
	// TH2F *edepvsshort = 0;
	// TH2F *edepvslong = 0;
	// TH1F *edep_target = 0;
	// TH1F *edep_krHouse = 0;

	canvas->Close();
}
