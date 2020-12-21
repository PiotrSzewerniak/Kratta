void kalibracjaShort(){
	const Int_t n = 5;
	Double_t energy[n]  = {80,110,140,170,200};
	Double_t mean[n] = {31.58,20.31,16.03,13.61,12.02};
	Double_t sigma[n] = {2.125,0.7204,0.5811,0.5444,0.5389};
	auto gr = new TGraphErrors(n,energy,mean,0,sigma);
	gr->SetTitle("TGraphErrors Example");
   	gr->SetMarkerColor(4);
   	gr->SetMarkerStyle(21);
   	gr->Draw("AP");
   	gr->Fit("pol1");

}