void kalibracja(){
	const Int_t n = 3;
	Double_t energy[n]  = {110,140,200};
	Double_t mean[n] = {20.31,16.03,12.};
	Double_t sigma[n] = {0.7204,0.5658,0.528};
	auto gr = new TGraphErrors(n,energy,mean,0,sigma);
	gr->SetTitle("TGraphErrors Example");
   	gr->SetMarkerColor(4);
   	gr->SetMarkerStyle(21);
   	gr->Draw("AP");
   	gr->Fit("pol1");

}