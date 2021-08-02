void plotFastFullComparison(std::string variable = "jetsMass", Double_t sigma = 1., std::string channel = "BP21") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile fileFullSim(("./histoFiles/plotsAfterPreselectionFullSim_" + channel + ".root").c_str(), "READ");

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  string category;
  if(sigma > 100)
    category = "background";
  else
    category = "signal";


  TH1F *fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R10_idm_hphm_slep_" + channel + "_1500").c_str() );
  if(sigma > 100)
    fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R10_idm_bg_" + channel + "_1500").c_str() );

  TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 2000;

  fastSimHist->SetLineColor(kBlue);
  fullSimHist->SetLineColor(kRed);

  fastSimHist->SetLineWidth(3);
  fullSimHist->SetLineWidth(3);

  fastSimHist->SetStats(kFALSE);
  fullSimHist->SetStats(kFALSE);

  TLegend *Leg = new TLegend(0.8,0.65,0.9,0.9);
  Leg->AddEntry(fastSimHist, "Fast sim.", "L");
  Leg->AddEntry(fullSimHist, "Full sim.", "L");

  if(sigma < 100)
    fastSimHist->Scale( sigma*lumi/100000 );
  else
    fastSimHist->Scale( sigma*lumi/1000000 );

  //fullSimHist->Scale( sigma*lumi/49500 );

  fullSimHist->Draw("HIST");
  fastSimHist->Draw("SAME HIST");
  Leg->Draw("SAME");
  c1.Print( ("./plots/" + channel + "_" + variable + "FastFullCompare.jpg").c_str() );

}

void drawAll( Double_t sigma = 8.093, std::string channel = "BP21" ) {

  plotFastFullComparison("jetsMass", sigma, channel);
  plotFastFullComparison("jetsEnergy", sigma, channel);
  plotFastFullComparison("jetsTheta", sigma, channel);
  plotFastFullComparison("lepPt", sigma, channel);
  plotFastFullComparison("lepEnergy", sigma, channel);
  plotFastFullComparison("lepTheta", sigma, channel);
  plotFastFullComparison("met", sigma, channel);
  plotFastFullComparison("missingMass", sigma, channel);

}

void drawAllSamples() {
  drawAll( 8.093, "BP21" );
  drawAll( 12.602, "BP23" );
  drawAll( 0.63347, "HP3" );
  drawAll( 2.44644, "HP17" );
  drawAll( 1.3261, "HP20" );
  drawAll( 7001., "qqlv" );
  drawAll( 2715., "qqll" );
}
