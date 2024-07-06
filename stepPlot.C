void stepPlot(){
  TFile fM("stepOutPlot_metal.root");
  TFile fS("stepOutPlot_sensor.root");
  TFile fC("stepOutPlot_chip.root");

  TGraph *gM = (TGraph*)fM.Get("metal");
  TGraph *gS = (TGraph*)fS.Get("sensor");
  TGraph *gC = (TGraph*)fC.Get("chip");

  TCanvas cc;
  cc.cd();
  gM->Draw("pasame");
  gS->Draw("psame");
  gC->Draw("psame");

  auto lK = fM.GetListOfKeys();
  for (int iK{0}; iK < lK->GetEntries(); ++iK) {
    if (strstr(lK->At(iK)->GetName(), "line") != nullptr) {
      std::cout << lK->At(iK)->GetName() << std::endl;
      TGraph *g_l = (TGraph*)fM.Get(lK->At(iK)->GetName());
      g_l->Draw("same");
    }
  }

  lK = fS.GetListOfKeys();
  for (int iK{0}; iK < lK->GetEntries(); ++iK) {
    if (strstr(lK->At(iK)->GetName(), "line") != nullptr) {
      std::cout << lK->At(iK)->GetName() << std::endl;
      TGraph *g_l = (TGraph*)fS.Get(lK->At(iK)->GetName());
      g_l->Draw("same");
    }
  }

  lK = fC.GetListOfKeys();
  for (int iK{0}; iK < lK->GetEntries(); ++iK) {
    if (strstr(lK->At(iK)->GetName(), "line") != nullptr) {
      std::cout << lK->At(iK)->GetName() << std::endl;
      TGraph *g_l = (TGraph*)fC.Get(lK->At(iK)->GetName());
      g_l->Draw("same");
    }
  }

  TFile out("stepPlot.root", "recreate");
  cc.Write("cc");
  out.Close();
}