void plotFastFullComparison(std::string variable = "jetsMass", Double_t sigma = 4.26603, std::string channel = "BP21") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  //TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts_withOverlay.root", "READ");
  TFile fileFullSim(("./histoFiles/plotsAfterPreselectionFullSim_FullSimCuts_" + channel + ".root").c_str(), "READ");

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  TH1F *fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R12_idm_hphm_slep_" + channel + "_3000").c_str() );
  if(sigma > 10)
    fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R12_idm_bg_" + channel + "_3000").c_str() );

  TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 4000;

  fastSimHist->SetLineColor(kBlue);
  fullSimHist->SetLineColor(kRed);

  fastSimHist->SetLineWidth(3);
  fullSimHist->SetLineWidth(3);

  fastSimHist->SetStats(kFALSE);
  fullSimHist->SetStats(kFALSE);

  TLegend *Leg = new TLegend(0.8,0.65,0.9,0.9);
  Leg->AddEntry(fastSimHist, "Fast sim.", "L");
  Leg->AddEntry(fullSimHist, "Full sim.", "L");

  if(sigma < 10)
    fastSimHist->Scale( sigma*lumi/100000 );
  else if(sigma > 200)
    fastSimHist->Scale( sigma*lumi/1000000 );
  else
    fastSimHist->Scale( sigma*lumi/100000 );

  //fullSimHist->Scale( sigma*lumi/49500 );

  fullSimHist->Draw("HIST");
  fastSimHist->Draw("SAME HIST");
  //Leg->Draw("SAME");
  c1.Print( ("./plots/Overlay_FullSim/" + channel + "_" + variable + "FastFullCompare.jpg").c_str() );

}

void drawAll( Double_t sigma = 4.26603, std::string channel = "BP21" ) {

  plotFastFullComparison("jetsMass", sigma, channel);
  plotFastFullComparison("jetsEnergy", sigma, channel);
  plotFastFullComparison("jetsTheta", sigma, channel);
  plotFastFullComparison("lepPt", sigma, channel);
  //plotFastFullComparison("jetPt", sigma, channel);
  plotFastFullComparison("lepEnergy", sigma, channel);
  plotFastFullComparison("lepTheta", sigma, channel);
  plotFastFullComparison("met", sigma, channel);
  plotFastFullComparison("missingMass", sigma, channel);

}

void drawAllSamples() {
  drawAll( 4.26603, "BP21" );
  drawAll( 5.67891, "BP23" );
  drawAll( 1.72873, "HP3" );
  drawAll( 1.42266, "HP17" );
  drawAll( 1.54028, "HP20" );
  drawAll(1671.37, "ll");
  drawAll( 8831.58, "qqlv" );
  drawAll( 3219.26, "qqll" );
  drawAll(20.4, "qqlvlv");
  drawAll(96.8, "qqlvvv");
  drawAll(902, "qqqq");
  drawAll(148, "qqqqlv");
  drawAll(2333.5039, "qqvv");
}
