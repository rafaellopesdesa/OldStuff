Double_t* func(Double_t* x, Double_t* p) {

  return TMath::Exp(p[0]+p[1]*TMath::Log(x[0]));

}

void draw() {

  gStyle->SetOptStat(0000);

  TGraphErrors* gr = new TGraphErrors("papel_um.txt", "%lg %lg %lg %lg");
  gr->Draw("A");

  gr->GetXaxis()->SetTitle("Diametro (mm)");
  gr->GetYaxis()->SetTitle("Massa (u.m.)");
  gr->SetTitle("Dimensao Fractal - Papel");
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(gr->GetMarkerSize()/2.);

  TCanvas* c1 = new TCanvas();
  gr->Draw("AP");
  c1->Print("gr1.png");


  TGraphErrors* grlog = new TGraphErrors();
  for (int i=0; i<gr->GetN(); i++) {
    grlog->SetPoint(i, TMath::Log(gr->GetX()[i]), TMath::Log(gr->GetY()[i]));
    grlog->SetPointError(i, gr->GetEX()[i]/gr->GetX()[i], 0.0);
  }
  grlog->Draw("A");
  grlog->GetXaxis()->SetTitle("Logaritmo do diametro (diametro em mm)");
  grlog->GetYaxis()->SetTitle("Logaritmo da massa (massa em unidade arbitraria)");
  grlog->SetTitle("Dimensao Fractal - Papel");
  grlog->SetMarkerStyle(20);
  //  grlog->SetMarkerSize(gr->GetMarkerSize()/2.);
  grlog->Fit("pol1");
  TCanvas* c2 = new TCanvas();
  grlog->Draw("AP");
  c2->Print("gr2.png");

}
