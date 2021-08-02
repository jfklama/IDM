#include "./CLICdpStyle.C"

void drawSignalBackgroundComparison(std::string variable = "jetsMass", const char *letter = "(a)") {

  CLICdpStyle();

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();
  TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsBeforeCuts_withOverlay_afterPhotonsAndEFlow.root", "READ");
  //TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsFterCuts_noSmear.root", "READ");

  gStyle->SetTitleFontSize(1.5);

  Double_t lumi = 2000;

  TH1F *llHist = (TH1F*)file.Get( (variable + "R10_idm_bg_ll_1500").c_str() );
  TH1F *qqllHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqll_1500").c_str() );
  TH1F *qqlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlv_1500").c_str() );
  TH1F *qqlvlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlvlv_1500").c_str() );
  TH1F *qqlvvvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlvvv_1500").c_str() );
  TH1F *qqqqHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqqq_1500").c_str() );
  TH1F *qqqqlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqqqlv_1500").c_str() );
  TH1F *qqvvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqvv_1500").c_str() );
  TH1F *qqHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qq_1500").c_str() );
  TH1F *signalBP21 = (TH1F*)file.Get( (variable + "R10_idm_hphm_slep_BP21_1500").c_str() );
  TH1F *signalHP17 = (TH1F*)file.Get( (variable + "R10_idm_hphm_slep_HP17_1500").c_str() );

  llHist->Scale( 1396.18*lumi/1000000 );
  qqHist->Scale( 2873.4*lumi/1000000 );
  qqllHist->Scale( 2739.2*lumi/1000000 );
  qqlvHist->Scale( 7054.67*lumi/1000000 );
  qqlvlvHist->Scale( 56.912*lumi/100000 );
  qqlvvvHist->Scale( 40.1477*lumi/100000 );
  qqqqHist->Scale( 1970.68*lumi/1000000 );
  qqqqlvHist->Scale( 177.428*lumi/100000 );
  qqvvHist->Scale( 1520.1*lumi/1000000 );
  signalBP21->Scale( 8.192*lumi/100000 );
  signalHP17->Scale( 2.44644*lumi/100000 );


  char HistoName[variable.size() + 1];
  strcpy(HistoName, (variable).c_str());

  THStack *hs = new THStack("hs","");
  hs->Add(llHist);
  hs->Add(qqllHist);
  hs->Add(qqlvHist);
  hs->Add(qqlvvvHist);
  hs->Add(qqqqHist);
  hs->Add(qqqqlvHist);
  hs->Add(qqvvHist);
  hs->Add(qqHist);
  hs->Add(qqlvlvHist);

  TH1F *backgroundHist = (TH1F*)hs->GetStack()->Last();

  backgroundHist->SetLineColor(kBlack);
  signalBP21->SetLineColor(kBlue);
  signalHP17->SetLineColor(kRed);
  backgroundHist->SetStats(kFALSE);
  signalBP21->SetStats(kFALSE);
  signalHP17->SetStats(kFALSE);
  signalBP21->SetLineWidth(2);
  signalHP17->SetLineWidth(2);
  backgroundHist->SetYTitle("Events");
  signalBP21->SetYTitle("Events");
  signalHP17->SetYTitle("Events");

  TLegend *Leg = new TLegend(0.8,0.7,0.99,0.99);
  Leg->AddEntry(backgroundHist, "background", "L");
	Leg->AddEntry(signalBP21, "signal BP21 (W)", "L");
  Leg->AddEntry(signalHP17, "signal HP17 (W*)", "L");

  backgroundHist->SetMinimum(0.1);
  backgroundHist->Draw("HIST");
  signalBP21->Draw( "SAME HIST" );
  signalHP17->Draw("SAME HIST");

  TLatex t;
  t.SetTextAlign(10);
  t.SetTextSize(0.06);
  //t.DrawLatex(backgroundHist->GetXaxis()->GetXmax()*1.03, backgroundHist->GetMaximum(), letter);

  //Leg->Draw("SAME");
  //c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/SignBackgComp/" + variable + "SignBackgCompareR10.pdf").c_str() );

  // save plots to file
  TObjArray HList(0);
  HList.SetOwner(kTRUE);
  HList.Add(backgroundHist);
  HList.Add(signalBP21);
  HList.Add(signalHP17);

  TFile f("./fastsim_plots_withOverlay_afterPhotonsAndEFlow.root","update");
  HList.Write();
  f.Close();

}

void drawSmearVsNoSmear( std::string variable = "jetsMass" ) {

  TCanvas c1("c1", "", 200, 10, 800, 600);
  //c1.SetLogy();

  TFile noSmear_file("./fastsim_plots_noSmear.root", "READ");
  TFile smear_file("./fastsim_plots_withSmear4.root", "READ");

  TH1F *noSmear_bckg = (TH1F*)noSmear_file.Get( (variable + "R10_idm_bg_qqlvlv_1500").c_str() );
  TH1F *noSmear_signalBP18 = (TH1F*)noSmear_file.Get( (variable + "R10_idm_hphm_slep_BP18_1500").c_str() );
  TH1F *noSmear_signalHP13 = (TH1F*)noSmear_file.Get( (variable + "R10_idm_hphm_slep_HP13_1500").c_str() );

  TH1F *smear_bckg = (TH1F*)smear_file.Get( (variable + "R10_idm_bg_qqlvlv_1500").c_str() );
  TH1F *smear_signalBP18 = (TH1F*)smear_file.Get( (variable + "R10_idm_hphm_slep_BP18_1500").c_str() );
  TH1F *smear_signalHP13 = (TH1F*)smear_file.Get( (variable + "R10_idm_hphm_slep_HP13_1500").c_str() );

  smear_bckg->SetLineColor(kGray);
  smear_signalBP18->SetLineColor(kCyan);
  smear_signalHP13->SetLineColor(kOrange);
  smear_bckg->SetLineStyle(7);
  smear_signalBP18->SetLineStyle(7);
  smear_signalHP13->SetLineStyle(7);
  smear_bckg->SetStats(kFALSE);
  smear_signalBP18->SetStats(kFALSE);
  smear_signalHP13->SetStats(kFALSE);
  smear_signalBP18->SetLineWidth(2);
  smear_signalHP13->SetLineWidth(2);
  smear_bckg->SetYTitle("Events");
  smear_signalBP18->SetYTitle("Events");
  smear_signalHP13->SetYTitle("Events");

  noSmear_bckg->SetLineColor(kBlack);
  noSmear_signalBP18->SetLineColor(kBlue);
  noSmear_signalHP13->SetLineColor(kRed);
  noSmear_bckg->SetStats(kFALSE);
  noSmear_signalBP18->SetStats(kFALSE);
  noSmear_signalHP13->SetStats(kFALSE);
  noSmear_signalBP18->SetLineWidth(2);
  noSmear_signalHP13->SetLineWidth(2);
  noSmear_bckg->SetYTitle("Events");
  noSmear_signalBP18->SetYTitle("Events");
  noSmear_signalHP13->SetYTitle("Events");

  TLegend *Leg = new TLegend(0.8,0.7,0.99,0.99);
  Leg->AddEntry(noSmear_bckg, "background", "L");
	Leg->AddEntry(noSmear_signalBP18, "signal BP18", "L");
  Leg->AddEntry(noSmear_signalHP13, "signal HP13", "L");

  noSmear_bckg->SetMinimum(0.1);

  noSmear_bckg->Draw(" HIST");
  //noSmear_signalHP13->Draw(" HIST");
  //noSmear_signalBP18->Draw( "SAME HIST" );

  smear_bckg->Draw("SAME HIST");
  //smear_signalHP13->Draw("SAME HIST");
  //smear_signalBP18->Draw( "SAME HIST" );


  Leg->Draw("SAME");

  c1.Print( ("./plots/SmearVsNoSmear/" + variable + "SmearVsNoSmear_background.pdf").c_str() );


}

void drawSignalVsBackground() {

  drawSignalBackgroundComparison("jetsMass", "(a)");
  drawSignalBackgroundComparison("jetsEnergy", "(b)");
  drawSignalBackgroundComparison("jetsTheta", "(c)");
  drawSignalBackgroundComparison("jetDeltaTheta");
  drawSignalBackgroundComparison("jetDeltaPhi");
  drawSignalBackgroundComparison("lepPt");
  drawSignalBackgroundComparison("lepEnergy", "(e)");
  drawSignalBackgroundComparison("lepTheta", "(d)");
  drawSignalBackgroundComparison("met");
  drawSignalBackgroundComparison("missingMass", "(f)");

}

void drawAllSmearVsNoSmear() {

  drawSmearVsNoSmear("jetsMass");
  drawSmearVsNoSmear("jetsEnergy");
  drawSmearVsNoSmear("jetsTheta");
  drawSmearVsNoSmear("jetDeltaTheta");
  drawSmearVsNoSmear("jetDeltaPhi");
  drawSmearVsNoSmear("lepPt");
  drawSmearVsNoSmear("lepEnergy");
  drawSmearVsNoSmear("lepTheta");
  drawSmearVsNoSmear("met");
  drawSmearVsNoSmear("missingMass");

}
