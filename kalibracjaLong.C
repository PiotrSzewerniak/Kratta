void kalibracjaLong(){
	const Int_t n = 5;
	Double_t energy[n]  = {80,110,140,170,200};
	Double_t mean[n] = {35.33,79.77,115.7,92.66,71.48};
	Double_t sigma[n] = {5.299,2.758,2.187,3.006,1.799};
	auto gr = new TGraphErrors(n,energy,mean,0,sigma);
	gr->SetTitle("TGraphErrors Example");
   	gr->SetMarkerColor(4);
   	gr->SetMarkerStyle(21);
   	gr->Draw("AP");
   	gr->Fit("pol1");

}