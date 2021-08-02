#include "./CLICdpStyle.C"

void plotFastFullComparison(std::string variable = "jetsMass", Double_t sigma = 1., std::string channel = "BP21") {

  CLICdpStyle();

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();

  //TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile fileFastSim0("./histoFiles/VarHistogramsBeforeCuts_HP17_noOverlay_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFastSim5("./histoFiles/VarHistogramsBeforeCuts_HP17_overlay_tightSelected_batch20FullSelection10ns_64ev_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFastSim10("./histoFiles/VarHistogramsBeforeCuts_HP17_overlay_tightSelected_batchFullSelection_64ev_allEvents_jet20Gev_newEff.root", "READ");
  TFile fileFullSim(("./histoFiles/plotsBeforePreselectionFullSim_" + channel + "_allEvents.root").c_str(), "READ");

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  string category;
  if(sigma > 100)
    category = "background";
  else
    category = "signal";


  //TH1F *fastSimHist0 = (TH1F*)fileFastSim0.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );
  /*TH1F *fastSimHist5 = (TH1F*)fileFastSim5.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );
  TH1F *fastSimHist10 = (TH1F*)fileFastSim10.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );*/
  TH1F *fastSimHist0 = (TH1F*)fileFastSim0.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );
  TH1F *fastSimHist5 = (TH1F*)fileFastSim5.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );
  TH1F *fastSimHist10 = (TH1F*)fileFastSim10.Get( (variable + "R12_idm_slep_" + channel + "_3000").c_str() );
  // if(sigma > 100)
  //   fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R12_idm_bg_" + channel + "_3000").c_str() );

  TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 4000;

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

  TLegend *Leg = new TLegend(0.55,0.7,0.9,0.9);
  Leg->AddEntry(fastSimHist0, "Fast sim. (no overlay)", "L");
  Leg->AddEntry(fastSimHist5, "Fast sim. (overlay)", "L");
  //Leg->AddEntry(fastSimHist10, "twice loosened cuts", "L");
  Leg->AddEntry(fullSimHist, "Full sim.", "L");
  Leg->SetFillStyle(0);
/*
  if(sigma < 100)
    fastSimHist->Scale( sigma*lumi/100000 );
  else
    fastSimHist->Scale( sigma*lumi/1000000 );
*/

  fastSimHist0->Scale( sigma*lumi/100000 );
  fastSimHist5->Scale( sigma*lumi/100000 );
  fastSimHist10->Scale( sigma*lumi/100000 );

  //fullSimHist->SetTitle("no lepton selection");

  fastSimHist0->Draw("HIST");
  fastSimHist5->Draw("SAME HIST");
  //fastSimHist10->Draw("SAME HIST");
  fullSimHist->Draw("SAME HIST");

  cout << fullSimHist->Integral() << " " << fastSimHist0->Integral() << " " << fastSimHist5->Integral() << endl;


  Leg->Draw("SAME");
  CLICdpLabel(0.17,0.935,"Preliminary");

  c1.Print( ("./plots/differentOverlayModes/selectedOverlay/noLeptonSelection/allEvents_forDIS/" + channel + "_" + variable + "_FastFullCompare.jpg").c_str() );
  c1.Print( ("./plots/differentOverlayModes/selectedOverlay/noLeptonSelection/allEvents_forDIS/" + channel + "_" + variable + "_FastFullCompare.pdf").c_str() );

}

void plotPfoRatiosInTheta(const char *fileName = "histoFiles/VarHistogramsBeforeCuts_qqlv_noOverlay_corrEff2.root", std::string channel = "qqlv"){

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  TFile file(fileName, "READ");
/*
  TH1F phoPartialHist = * (TH1F*) file.Get( ("phoThetaPartialR12_idm_slep_" + channel + "_3000").c_str() );
  TH1F nhPartialHist = * (TH1F*) file.Get( ("nhThetaPartialR12_idm_slep_" + channel + "_3000").c_str() );
  TH1F chPartialHist = * (TH1F*) file.Get( ("chThetaPartialR12_idm_slep_" + channel + "_3000").c_str() );
  TH1F fullHist = * (TH1F*) file.Get( ("allThetaR12_idm_slep_" + channel + "_3000").c_str() );
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
  //plotFastFullComparison("nIsoPhotons", sigma, channel);
  //plotFastFullComparison("isoPhotonEnergy", sigma, channel);

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
  drawAll( 4.26603, "BP21" );
  drawAll( 5.67891, "BP23" );
  drawAll( 1.72873, "HP3" );
  drawAll( 1.42266, "HP17" );
  drawAll( 1.54028, "HP20" );
  drawAll( 8831.58, "qqlv" );
  drawAll( 3219.26, "qqll" );
}
