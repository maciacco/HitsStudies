void stepStudy(const char* vol = "sensor"){
  Color_t col = kRed;
  string vol_str(vol);
  if (vol_str.find("sensor") < vol_str.size())
    col = kGreen + 1;
  else if (vol_str.find("chip") < vol_str.size())
    col = kGreen + 3;

  TFile *in = TFile::Open("stepOut.root");
  auto gS = (TGraph*)in->Get(Form("graph_%s", vol));

  TFile f(Form("stepOutPlot_%s.root", vol), "recreate");

  for (int iSS{0}; iSS < (gS->GetN() / 2); ++iSS) {
    // std::cout << gS->GetPointX(2 * iSS) << "\t" << gS->GetPointY(2 * iSS) << "\t" << gS->GetPointX(2 * iSS + 1) << "\t" << gS->GetPointY(2 * iSS + 1) << std::endl;
    TGraph ll;
    ll.SetName(Form("line_%d_%d", 2 * iSS, 2 * iSS + 1));
    ll.AddPoint(gS->GetPointX(2 * iSS), gS->GetPointY(2 * iSS));
    ll.AddPoint(gS->GetPointX(2 * iSS + 1), gS->GetPointY(2 * iSS + 1));
    f.ls();
    ll.SetLineWidth(2);
    ll.SetLineColor(col);
    ll.Write();
  }

  gS->SetMarkerStyle(20);
  gS->SetMarkerSize(0.5);
  gS->SetMarkerColor(col);
  gS->Write(vol);
  in->Close();
  f.Close();
}