#include "./CLICdpStyle.C"

void drawSignalBackgroundComparison(std::string variable = "jetsMass", const char *letter = "(a)") {

  CLICdpStyle();

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();
  //TFile file("~/FUW/CLIC/IDM/3000/backgroundAnalysis/VarHistogramsBeforePreselec_Smear1.root", "READ");
  TFile file("~/FUW/CLIC/IDM/3000/backgroundAnalysis/VarHistogramsBeforeCuts_withOverlay_afterPhotonsAndEFlow.root", "READ");

  gStyle->SetTitleFontSize(1.5);

  Double_t lumi = 4000;

  TH1F *llHist = (TH1F*)file.Get( (variable + "R12_idm_bg_ll_3000").c_str() );
  TH1F *qqllHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqll_3000").c_str() );
  TH1F *qqlvHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqlv_3000").c_str() );
  TH1F *qqlvlvHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqlvlv_3000").c_str() );
  TH1F *qqlvvvHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqlvvv_3000").c_str() );
  TH1F *qqqqHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqqq_3000").c_str() );
  TH1F *qqqqlvHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqqqlv_3000").c_str() );
  TH1F *qqvvHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qqvv_3000").c_str() );
  TH1F *qqHist = (TH1F*)file.Get( (variable + "R12_idm_bg_qq_3000").c_str() );
  TH1F *signalBP23 = (TH1F*)file.Get( (variable + "R12_idm_hphm_slep_BP23_3000").c_str() );
  TH1F *signalHP17 = (TH1F*)file.Get( (variable + "R12_idm_hphm_slep_HP17_3000").c_str() );

  llHist->Scale( 1671.37*lumi/1000000 );
  qqllHist->Scale( 3219.26*lumi/1000000 );
  qqlvHist->Scale( 8831.58*lumi/1000000 );
  qqlvlvHist->Scale( 63.1912*lumi/100000 );
  qqlvvvHist->Scale( 70.7564*lumi/100000 );
  qqqqHist->Scale( 916.758*lumi/1000000 );
  qqqqlvHist->Scale( 131.211*lumi/100000 );
  qqvvHist->Scale( 2512.37*lumi/1000000 );
  qqHist->Scale( 1231.27*lumi/1000000 );
  //signalBP21->Scale( 4.26603*lumi/100000 ); // BP21 XS
  signalBP23->Scale( 5.67891*lumi/100000 );
  signalHP17->Scale( 1.42266*lumi/100000 );


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
  signalBP23->SetLineColor(kBlue);
  signalHP17->SetLineColor(kRed);
  backgroundHist->SetStats(kFALSE);
  signalBP23->SetStats(kFALSE);
  signalHP17->SetStats(kFALSE);
  signalBP23->SetLineWidth(2);
  signalHP17->SetLineWidth(2);
  backgroundHist->SetYTitle("Events");
  signalBP23->SetYTitle("Events");
  signalHP17->SetYTitle("Events");

  double x1 = 0.8;
  double y1 = 0.7;
  double x2 = 0.99;
  double y2 = 0.99;

  if(variable=="jetsMass") {
    x1 = 0.7;
    y1 = 0.47;
    x2 = 0.9;
    y2 = 0.72;
  }
  if(variable=="jetsEnergy") {
    x1 = 0.7;
    y1 = 0.4;
    x2 = 0.9;
    y2 = 0.65;
  }

  TLegend *Leg = new TLegend(x1,y1,x2,y2);
  Leg->AddEntry(backgroundHist, "background", "L");
	Leg->AddEntry(signalBP23, "signal BP23 (W)", "L");
  Leg->AddEntry(signalHP17, "signal HP17 (W*)", "L");
  Leg->SetFillStyle(0);


  backgroundHist->SetMinimum(0.1);
  //backgroundHist->SetMaximum( backgroundHist->GetMaximum()*10 );
  backgroundHist->Draw("HIST");
  signalBP23->Draw( "SAME HIST" );
  signalHP17->Draw("SAME HIST");

  CLICdpLabel(0.17,0.935,"Preliminary");

  //TLatex t;
  //t.SetTextAlign(10);
  //t.SetTextSize(0.06);
  //t.DrawLatex(backgroundHist->GetXaxis()->GetXmax()*1.03, backgroundHist->GetMaximum(), letter);

  Leg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/SignBackgComp/withOverlay/" + variable + "SignBackgCompareR12.pdf").c_str() );
  //c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/SignBackgComp/" + variable + "SignBackgCompareR12.jpg").c_str() );
/*
  TObjArray HList(0);
  HList.SetOwner(kTRUE);
  HList.Add(backgroundHist);
  HList.Add(signalBP23);
  HList.Add(signalHP17);

  TFile f("./fastsim_plots_withOverlay_afterPhotonsAndEFlow.root","update");
  HList.Write();
  f.Close();
*/
}

void drawSmearVsNoSmear( std::string variable = "jetsMass" ) {

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();

  TFile noSmear_file("./fastsim_plots_beforeCuts_withSmear1.root", "READ");
  TFile smear_file("./fastsim_plots_beforeCuts_withSmear1_newCard.root", "READ");

  TH1F *noSmear_bckg = (TH1F*)noSmear_file.Get( (variable + "R12_idm_bg_qqlvlv_3000").c_str() );
  TH1F *noSmear_signalBP18 = (TH1F*)noSmear_file.Get( (variable + "R12_idm_hphm_slep_BP18_3000").c_str() );
  TH1F *noSmear_signalHP17 = (TH1F*)noSmear_file.Get( (variable + "R12_idm_hphm_slep_HP17_3000").c_str() );

  TH1F *smear_bckg = (TH1F*)smear_file.Get( (variable + "R12_idm_bg_qqlvlv_3000").c_str() );
  TH1F *smear_signalBP18 = (TH1F*)smear_file.Get( (variable + "R12_idm_hphm_slep_BP18_3000").c_str() );
  TH1F *smear_signalHP17 = (TH1F*)smear_file.Get( (variable + "R12_idm_hphm_slep_HP17_3000").c_str() );

  smear_bckg->SetLineColor(kGray);
  smear_signalBP18->SetLineColor(kCyan);
  smear_signalHP17->SetLineColor(kOrange);
  smear_bckg->SetLineStyle(7);
  smear_signalBP18->SetLineStyle(7);
  smear_signalHP17->SetLineStyle(7);
  smear_bckg->SetStats(kFALSE);
  smear_signalBP18->SetStats(kFALSE);
  smear_signalHP17->SetStats(kFALSE);
  smear_signalBP18->SetLineWidth(2);
  smear_signalHP17->SetLineWidth(2);
  smear_bckg->SetYTitle("Events");
  smear_signalBP18->SetYTitle("Events");
  smear_signalHP17->SetYTitle("Events");

  noSmear_bckg->SetLineColor(kBlack);
  noSmear_signalBP18->SetLineColor(kBlue);
  noSmear_signalHP17->SetLineColor(kRed);
  noSmear_bckg->SetStats(kFALSE);
  noSmear_signalBP18->SetStats(kFALSE);
  noSmear_signalHP17->SetStats(kFALSE);
  noSmear_signalBP18->SetLineWidth(2);
  noSmear_signalHP17->SetLineWidth(2);
  noSmear_bckg->SetYTitle("Events");
  noSmear_signalBP18->SetYTitle("Events");
  noSmear_signalHP17->SetYTitle("Events");

  TLegend *Leg = new TLegend(0.8,0.7,0.99,0.99);
  Leg->AddEntry(noSmear_bckg, "background", "L");
	Leg->AddEntry(noSmear_signalBP18, "signal BP18", "L");
  Leg->AddEntry(noSmear_signalHP17, "signal HP17", "L");

  noSmear_bckg->SetMinimum(0.1);

  noSmear_bckg->Draw(" HIST");
  noSmear_signalBP18->Draw( "SAME HIST" );
  noSmear_signalHP17->Draw("SAME HIST");

  smear_bckg->Draw("SAME HIST");
  smear_signalBP18->Draw( "SAME HIST" );
  smear_signalHP17->Draw("SAME HIST");

  Leg->Draw("SAME");

  c1.Print( ("./plots/SmearVsNoSmear/" + variable + "SmearVsNoSmear.pdf").c_str() );


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
