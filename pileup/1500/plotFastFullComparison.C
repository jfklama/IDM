void plotFastFullComparison(std::string variable = "jetsMass", Double_t sigma = 1., std::string channel = "BP21") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  //TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile fileFastSim0("./histoFiles/VarHistogramsBeforeCuts_HP17_noOverlay_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFastSim5("./histoFiles/VarHistogramsBeforeCuts_HP17_overlay_defaultSelected_batch20FullSelection10ns_26ev_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFastSim10("./histoFiles/VarHistogramsBeforeCuts_HP17_overlay_defaultSelected_batchFullSelection_26ev_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFullSim(("./histoFiles/plotsBeforePreselectionFullSim_" + channel + "_allEvents_R09.root").c_str(), "READ");

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  string category;
  if(sigma > 100)
    category = "background";
  else
    category = "signal";


  //TH1F *fastSimHist0 = (TH1F*)fileFastSim0.Get( (variable + "R10_idm_slep_" + channel + "_1500").c_str() );
  /*TH1F *fastSimHist5 = (TH1F*)fileFastSim5.Get( (variable + "R10_idm_slep_" + channel + "_1500").c_str() );
  TH1F *fastSimHist10 = (TH1F*)fileFastSim10.Get( (variable + "R10_idm_slep_" + channel + "_1500").c_str() );*/
  TH1F *fastSimHist0 = (TH1F*)fileFastSim0.Get( (variable + "R10_" + channel).c_str() );
  TH1F *fastSimHist5 = (TH1F*)fileFastSim5.Get( (variable + "R10_" + channel).c_str() );
  TH1F *fastSimHist10 = (TH1F*)fileFastSim10.Get( (variable + "R10_" + channel).c_str() );
  // if(sigma > 100)
  //   fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R10_idm_bg_" + channel + "_1500").c_str() );

  TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 2000;

  fastSimHist0->SetLineColor(kBlue-7);
  fastSimHist5->SetLineColor(kBlue);
  fastSimHist10->SetLineColor(kBlue+3);
  fullSimHist->SetLineColor(kRed);
/*
  fastSimHist0->SetLineColor(kBlack);
  fastSimHist5->SetLineColor(kBlue);
  fastSimHist10->SetLineColor(kRed);
*/
  fastSimHist0->SetLineWidth(2);
  fastSimHist5->SetLineWidth(2);
  fastSimHist10->SetLineWidth(2);
  fullSimHist->SetLineWidth(2);

  fastSimHist0->SetStats(kFALSE);
  fastSimHist5->SetStats(kFALSE);
  fastSimHist10->SetStats(kFALSE);
  fullSimHist->SetStats(kFALSE);

  TLegend *Leg = new TLegend(0.77,0.65,0.9,0.9);
  Leg->AddEntry(fastSimHist0, "no overlay", "L");
  Leg->AddEntry(fastSimHist5, "defaultSelectedPFOs", "L");
  Leg->AddEntry(fastSimHist10, "twice loosened cuts", "L");
  Leg->AddEntry(fullSimHist, "full sim. R=0.9", "L");
/*
  if(sigma < 100)
    fastSimHist->Scale( sigma*lumi/100000 );
  else
    fastSimHist->Scale( sigma*lumi/1000000 );
*/

  fastSimHist0->Scale( sigma*lumi/100000 );
  fastSimHist5->Scale( sigma*lumi/100000 );
  fastSimHist10->Scale( sigma*lumi/100000 );

  //fullSimHist->SetTitle("150 GeV < p_{T}^{l} < 800 GeV");

  fullSimHist->Draw(" HIST");
  fastSimHist0->Draw("SAME HIST");
  fastSimHist5->Draw("SAME HIST");
  fastSimHist10->Draw("SAME HIST");

  cout << fullSimHist->Integral() << " " << fastSimHist0->Integral() << " " << fastSimHist5->Integral() << endl;


  Leg->Draw("SAME");
  c1.Print( ("./plots/differentOverlayModes/selectedOverlay/noLeptonSelection/allEvents/" + channel + "_" + variable + "_FastFullCompare.jpg").c_str() );
  c1.Print( ("./plots/differentOverlayModes/selectedOverlay/noLeptonSelection/allEvents/" + channel + "_" + variable + "_FastFullCompare.pdf").c_str() );

}

void plotPfoRatiosInTheta(const char *fileName = "histoFiles/VarHistogramsBeforeCuts_qqlv_noOverlay_corrEff2.root", std::string channel = "qqlv"){

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  TFile file(fileName, "READ");
/*
  TH1F phoPartialHist = * (TH1F*) file.Get( ("phoThetaPartialR10_idm_slep_" + channel + "_1500").c_str() );
  TH1F nhPartialHist = * (TH1F*) file.Get( ("nhThetaPartialR10_idm_slep_" + channel + "_1500").c_str() );
  TH1F chPartialHist = * (TH1F*) file.Get( ("chThetaPartialR10_idm_slep_" + channel + "_1500").c_str() );
  TH1F fullHist = * (TH1F*) file.Get( ("allThetaR10_idm_slep_" + channel + "_1500").c_str() );
*/
  TH1F phoPartialHist = * (TH1F*) file.Get( "phoThetaPartial" );
  TH1F nhPartialHist = * (TH1F*) file.Get( "nhThetaPartial" );
  TH1F chPartialHist = * (TH1F*) file.Get( "chThetaPartial" );
  TH1F fullHist = * (TH1F*) file.Get( "allThetaPartial" );


  TH1F phoRatioHist = phoPartialHist / fullHist;
  TH1F nhRatioHist = nhPartialHist / fullHist;
  TH1F chRatioHist = chPartialHist / fullHist;

  phoPartialHist.SetStats(kFALSE);
  nhPartialHist.SetStats(kFALSE);
  chPartialHist.SetStats(kFALSE);
  fullHist.SetStats(kFALSE);

  phoPartialHist.SetLineWidth(2);
  nhPartialHist.SetLineWidth(2);
  chPartialHist.SetLineWidth(2);
  fullHist.SetLineWidth(2);

  phoPartialHist.SetLineColor(kYellow);
  nhPartialHist.SetLineColor(kGray);
  chPartialHist.SetLineColor(kRed);
  fullHist.SetLineColor(kBlack);

  TLegend *Leg = new TLegend(0.77,0.65,0.9,0.9);
  Leg->AddEntry(&phoPartialHist, "photons fraction", "L");
  Leg->AddEntry(&nhPartialHist, "n.had. fraction", "L");
  Leg->AddEntry(&chPartialHist, "tracks fraction", "L");
  Leg->AddEntry(&fullHist, "all PFOs", "L");

  fullHist.SetXTitle("#theta");
  //fullHist.SetYTitle("fraction of all PFOs");
  fullHist.SetMinimum(0.0002);

  fullHist.Draw(" HIST");
  nhPartialHist.Draw("SAME HIST");
  phoPartialHist.Draw("SAME HIST");
  chPartialHist.Draw("SAME HIST");

  Leg->Draw("SAME");

  //cout << ratioHist.Integral() << " " << partialHist.Integral() << " " << fullHist.Integral() << endl;

  c1.Print(("plots/" + channel + "_PfoContentsInTheta_fullsim.pdf").c_str());

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
  plotFastFullComparison("jetM", sigma, channel);
  plotFastFullComparison("nPFOs", sigma, channel);

}

void drawPfoDistributions( std::string channel = "BP21", std::string mode = "Theta" ) {

  Double_t sigma = 8.093;

  if (mode == "Theta"){
    plotFastFullComparison("phoLowPtTheta", sigma, channel);
    plotFastFullComparison("phoMedPtTheta", sigma, channel);
    plotFastFullComparison("phoHighPtTheta", sigma, channel);
    plotFastFullComparison("nhLowPtTheta", sigma, channel);
    plotFastFullComparison("nhMedPtTheta", sigma, channel);
    plotFastFullComparison("nhHighPtTheta", sigma, channel);
    plotFastFullComparison("chLowPtTheta", sigma, channel);
    plotFastFullComparison("chMedPtTheta", sigma, channel);
    plotFastFullComparison("chHighPtTheta", sigma, channel);
  } else if (mode == "N") {
    plotFastFullComparison("phoLowPt_nPFOs", sigma, channel);
    plotFastFullComparison("phoHighPt_nPFOs", sigma, channel);
    plotFastFullComparison("nhLowPt_nPFOs", sigma, channel);
    plotFastFullComparison("nhHighPt_nPFOs", sigma, channel);
    plotFastFullComparison("chLowPt_nPFOs", sigma, channel);
    plotFastFullComparison("chHighPt_nPFOs", sigma, channel);
    plotFastFullComparison("allLowPt_nPFOs", sigma, channel);
    plotFastFullComparison("allHighPt_nPFOs", sigma, channel);
  } else if (mode == "Pt") {
    plotFastFullComparison("phoPt", sigma, channel);
    plotFastFullComparison("nhPt", sigma, channel);
    plotFastFullComparison("chPt", sigma, channel);
  } else cout << "Incorrect mode provided!" << endl;

}

void drawAllSamples() {
  drawAll( 8.093, "BP21" );
  drawAll( 12.602, "BP23" );
  drawAll( 0.63347, "HP3" );
  drawAll( 2.44644, "HP17" );
  drawAll( 1.3261, "HP20" );
  drawAll( 7054.67, "qqlv" );
  drawAll( 2715., "qqll" );
}
