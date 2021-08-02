#include "./CLICdpStyle.C"

void drawSignalBackgroundComparison(std::string variable = "jetsMass", const char *letter = "") {

  CLICdpStyle();

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();
  //TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsBeforeCuts_withSmear1.root", "READ");
  //TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistograms.root", "READ");

  TFile file_qqll("./histoFiles/plotsBeforePreselectionFullSim_qqll.root", "READ");
  TFile file_qqlv("./histoFiles/plotsBeforePreselectionFullSim_qqlv.root", "READ");
  TFile file_ll("./histoFiles/plotsBeforePreselectionFullSim_ll.root", "READ");
  TFile file_qq("./histoFiles/plotsBeforePreselectionFullSim_qq.root", "READ");
  TFile file_qqqq("./histoFiles/plotsBeforePreselectionFullSim_qqqq.root", "READ");
  TFile file_qqvv("./histoFiles/plotsBeforePreselectionFullSim_qqvv.root", "READ");
  TFile file_qqlvlv("./histoFiles/plotsBeforePreselectionFullSim_qqlvlv.root", "READ");
  TFile file_qqlvvv("./histoFiles/plotsBeforePreselectionFullSim_qqlvvv.root", "READ");
  TFile file_qqqqlv("./histoFiles/plotsBeforePreselectionFullSim_qqqqlv.root", "READ");
  TFile file_BP21("./histoFiles/plotsBeforePreselectionFullSim_BP21.root", "READ");
  TFile file_HP17("./histoFiles/plotsBeforePreselectionFullSim_HP17.root", "READ");

  if(variable == "jetsMass")
    variable = "WhadMass";

  gStyle->SetTitleFontSize(1.5);

  Double_t lumi = 2000;

  TH1F *qqllHist = (TH1F*)file_qqll.Get( (variable).c_str() );
  TH1F *qqlvHist = (TH1F*)file_qqlv.Get( (variable).c_str() );
  TH1F *llHist = (TH1F*)file_ll.Get( (variable).c_str() );
  TH1F *qqHist = (TH1F*)file_qq.Get( (variable).c_str() );
  TH1F *qqqqHist = (TH1F*)file_qqqq.Get( (variable).c_str() );
  TH1F *qqvvHist = (TH1F*)file_qqvv.Get( (variable).c_str() );
  TH1F *qqlvlvHist = (TH1F*)file_qqlvlv.Get( (variable).c_str() );
  TH1F *qqlvvvHist = (TH1F*)file_qqlvvv.Get( (variable).c_str() );
  TH1F *qqqqlvHist = (TH1F*)file_qqqqlv.Get( (variable).c_str() );
  TH1F *signalBP21 = (TH1F*)file_BP21.Get( (variable).c_str() );
  TH1F *signalHP17 = (TH1F*)file_HP17.Get( (variable).c_str() );

/*
  qqllHist->Scale( 2715*lumi/1000000 );
  qqlvHist->Scale( 7001*lumi/1000000 );

  signalBP21->Scale( 8.093*lumi/100000 );
  signalHP17->Scale( 2.430*lumi/100000 );
*/

  char HistoName[variable.size() + 1];
  strcpy(HistoName, (variable).c_str());

  THStack *hs = new THStack("hs","");
  hs->Add(qqlvHist);
  hs->Add(qqqqHist);
  hs->Add(qqHist);
  hs->Add(llHist);
  hs->Add(qqvvHist);
  hs->Add(qqlvlvHist);
  hs->Add(qqlvvvHist);
  hs->Add(qqqqlvHist);
  hs->Add(qqllHist);

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
  //backgroundHist->GetXaxis()->SetRangeUser(0., 150.);
  backgroundHist->Draw("HIST");
  signalBP21->Draw( "SAME HIST" );
  signalHP17->Draw("SAME HIST");

  TLatex t;
  t.SetTextAlign(10);
  t.SetTextSize(0.06);
  t.DrawLatex(backgroundHist->GetXaxis()->GetXmax()*1.03, backgroundHist->GetMaximum(), letter);

  //Leg->Draw("SAME");
  //c1.Print( ("./plots/SignBackgComp/" + variable + "SignBackgCompare.jpg").c_str() );
  c1.Print( ("./plots/SignBackgComp/" + variable + "SignBackgCompare.pdf").c_str() );

}

void drawSignalBackground_FastFullSim(std::string variable = "jetsMass", const char *xtitle = "M_{jj} [GeV]", const char *letter = "") {

  CLICdpStyle();

  TCanvas c1("c1", "", 200, 10, 800, 600);
  c1.SetLogy();

  TFile file_qqll("./histoFiles/plotsBeforePreselectionFullSim_qqll.root", "READ");
  TFile file_qqlv("./histoFiles/plotsBeforePreselectionFullSim_qqlv.root", "READ");
  TFile file_ll("./histoFiles/plotsBeforePreselectionFullSim_ll.root", "READ");
  TFile file_qq("./histoFiles/plotsBeforePreselectionFullSim_qq.root", "READ");
  TFile file_qqqq("./histoFiles/plotsBeforePreselectionFullSim_qqqq.root", "READ");
  TFile file_qqvv("./histoFiles/plotsBeforePreselectionFullSim_qqvv.root", "READ");
  TFile file_qqlvlv("./histoFiles/plotsBeforePreselectionFullSim_qqlvlv.root", "READ");
  TFile file_qqlvvv("./histoFiles/plotsBeforePreselectionFullSim_qqlvvv.root", "READ");
  TFile file_qqqqlv("./histoFiles/plotsBeforePreselectionFullSim_qqqqlv.root", "READ");
  TFile file_BP21("./histoFiles/plotsBeforePreselectionFullSim_BP21.root", "READ");
  TFile file_HP17("./histoFiles/plotsBeforePreselectionFullSim_HP17.root", "READ");

  TFile fastsim_file("./histoFiles/fastsim_plots_withOverlay_afterPhotonsAndEFlow.root", "READ");

  std::string fastsim_var = variable;

  if(variable == "jetsMass")
    variable = "WhadMass";

  gStyle->SetTitleFontSize(1.5);

  Double_t lumi = 2000;

  TH1F *qqllHist = (TH1F*)file_qqll.Get( (variable).c_str() );
  TH1F *qqlvHist = (TH1F*)file_qqlv.Get( (variable).c_str() );
  TH1F *llHist = (TH1F*)file_ll.Get( (variable).c_str() );
  TH1F *qqHist = (TH1F*)file_qq.Get( (variable).c_str() );
  TH1F *qqqqHist = (TH1F*)file_qqqq.Get( (variable).c_str() );
  TH1F *qqvvHist = (TH1F*)file_qqvv.Get( (variable).c_str() );
  TH1F *qqlvlvHist = (TH1F*)file_qqlvlv.Get( (variable).c_str() );
  TH1F *qqlvvvHist = (TH1F*)file_qqlvvv.Get( (variable).c_str() );
  TH1F *qqqqlvHist = (TH1F*)file_qqqqlv.Get( (variable).c_str() );
  TH1F *signalBP21 = (TH1F*)file_BP21.Get( (variable).c_str() );
  TH1F *signalHP17 = (TH1F*)file_HP17.Get( (variable).c_str() );

  TH1F *fastsim_bckg = (TH1F*)fastsim_file.Get( (fastsim_var + "R10_idm_bg_qqlvlv_1500").c_str() );
  TH1F *fastsim_signalBP21 = (TH1F*)fastsim_file.Get( (fastsim_var + "R10_idm_hphm_slep_BP21_1500").c_str() );
  TH1F *fastsim_signalHP17 = (TH1F*)fastsim_file.Get( (fastsim_var + "R10_idm_hphm_slep_HP17_1500").c_str() );

/*
  qqllHist->Scale( 2715*lumi/1000000 );
  qqlvHist->Scale( 7001*lumi/1000000 );

  signalBP21->Scale( 8.093*lumi/100000 );
  signalHP17->Scale( 2.430*lumi/100000 );
*/

  char HistoName[variable.size() + 1];
  strcpy(HistoName, (variable).c_str());

  qqllHist->SetXTitle(xtitle);

  THStack *hs = new THStack("hs","");
  hs->Add(qqlvHist);
  hs->Add(qqqqHist);
  hs->Add(qqHist);
  hs->Add(llHist);
  hs->Add(qqvvHist);
  hs->Add(qqlvlvHist);
  hs->Add(qqlvvvHist);
  hs->Add(qqqqlvHist);
  hs->Add(qqllHist);

  TH1F *backgroundHist = (TH1F*)hs->GetStack()->Last();

  //cout << backgroundHist->GetEntries() << endl;

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

  fastsim_bckg->SetLineColor(kBlack);
  fastsim_signalBP21->SetLineColor(kBlue);
  fastsim_signalHP17->SetLineColor(kRed);
  fastsim_bckg->SetLineStyle(7);
  fastsim_signalBP21->SetLineStyle(7);
  fastsim_signalHP17->SetLineStyle(7);
  fastsim_bckg->SetStats(kFALSE);
  fastsim_signalBP21->SetStats(kFALSE);
  fastsim_signalHP17->SetStats(kFALSE);
  fastsim_signalBP21->SetLineWidth(2);
  fastsim_signalHP17->SetLineWidth(2);
  fastsim_bckg->SetYTitle("Events");
  fastsim_signalBP21->SetYTitle("Events");
  fastsim_signalHP17->SetYTitle("Events");
/*
  hs->SetTitle(";X axis;");
  gPad->Modified();
  gPad->Update();
*/
  cout << xtitle << endl;

  if(fastsim_var=="jetsMass")
    backgroundHist->GetXaxis()->SetRangeUser(0.0, 148.0);

  TLegend *Leg = new TLegend(0.8,0.7,0.99,0.99);
  Leg->AddEntry(backgroundHist, "background", "L");
	Leg->AddEntry(signalBP21, "signal BP21 (W)", "L");
  Leg->AddEntry(signalHP17, "signal HP17 (W*)", "L");

  backgroundHist->SetMinimum(0.1);
  //backgroundHist->GetXaxis()->SetRangeUser(0., 150.);
  backgroundHist->Draw("HIST");
  signalBP21->Draw( "SAME HIST" );
  signalHP17->Draw("SAME HIST");

  fastsim_bckg->Draw("SAME HIST");
  fastsim_signalBP21->Draw( "SAME HIST" );
  fastsim_signalHP17->Draw("SAME HIST");

  TLatex t;
  t.SetTextAlign(10);
  t.SetTextSize(0.06);
  if(variable=="WhadMass")
    t.DrawLatex(backgroundHist->GetXaxis()->GetXmax()*0.76, backgroundHist->GetMaximum(), letter);
  else
    t.DrawLatex(backgroundHist->GetXaxis()->GetXmax()*1.03, backgroundHist->GetMaximum(), letter);

  //Leg->Draw("SAME");
  //c1.Print( ("./plots/SignBackgComp/" + variable + "SignBackgCompare.jpg").c_str() );
  c1.Print( ("./plots/FastFull_allBackgrounds_beforeCuts/" + variable + "FastFull_SignBackg.pdf").c_str() );

}

void drawSignalVsBackground(Bool_t fastsim = 0) {

  if(fastsim) {
    drawSignalBackground_FastFullSim("jetsMass", "M_{jj} [GeV]", "(a)");
    drawSignalBackground_FastFullSim("jetsEnergy", "E_{j1} + E_{j2} [GeV]", "(b)");
    drawSignalBackground_FastFullSim("jetsTheta", "#theta_{W^{#pm}}", "(c)");
    drawSignalBackground_FastFullSim("jetDeltaTheta");
    drawSignalBackground_FastFullSim("jetDeltaPhi");
    drawSignalBackground_FastFullSim("lepPt");
    drawSignalBackground_FastFullSim("lepEnergy", "E_{l} [GeV]", "(e)");
    drawSignalBackground_FastFullSim("lepTheta", "#theta_{l}", "(d)");
    drawSignalBackground_FastFullSim("met");
    drawSignalBackground_FastFullSim("missingMass", "M_{miss} [GeV]", "(f)");
    //drawSignalBackground_FastFullSim("WlepMass");
  }
  else {
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
    drawSignalBackgroundComparison("WlepMass");
  }

}
