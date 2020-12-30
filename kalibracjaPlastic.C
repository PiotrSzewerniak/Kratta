void kalibracjaPlastic(){
	const Int_t n = 6;
	Double_t energy[n]  = {50,80,110,140,170,200};
	Double_t mean[n] = {3.29,1.984,1.466,1.186,0.9552,0.8337};
	Double_t sigma[n] = {0.2241,0.1533,0.1265,0.1101,0.05327,0.04093};
	auto gr = new TGraphErrors(n,energy,mean,0,sigma);
	gr->SetTitle("TGraphErrors Example");
   	gr->SetMarkerColor(4);
   	gr->SetMarkerStyle(21);
   	gr->Draw("AP");
   	//gr->Fit("expo");

}