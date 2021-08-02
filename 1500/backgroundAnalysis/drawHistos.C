void plotVarHisto(std::string variable = "jetsMass", Double_t sigmaSignal = 1., std::string signalChannel = "hphm_slep_BP18") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();
  TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsAfterCuts.root", "READ");

  TH1F *llHist = (TH1F*)file.Get( (variable + "R10_idm_bg_ll_1500").c_str() );
  TH1F *qqllHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqll_1500").c_str() );
  TH1F *qqlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlv_1500").c_str() );
  TH1F *qqlvlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlvlv_1500").c_str() );
  TH1F *qqlvvvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqlvvv_1500").c_str() );
  TH1F *qqqqHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqqq_1500").c_str() );
  TH1F *qqqqlvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqqqlv_1500").c_str() );
  TH1F *qqvvHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qqvv_1500").c_str() );
  TH1F *qqHist = (TH1F*)file.Get( (variable + "R10_idm_bg_qq_1500").c_str() );
  TH1F *signalHist = (TH1F*)file.Get( (variable + "R10_idm_" + signalChannel + "_1500").c_str() );

  cout << variable << endl;

  Double_t lumi = 2000;

  llHist->SetLineColor(kBlue);
  qqllHist->SetLineColor(kRed);
  qqlvHist->SetLineColor(kPink+10);
  qqlvlvHist->SetLineColor(kGreen-1);
  qqlvvvHist->SetLineColor(kOrange-3);
  signalHist->SetLineColor(kCyan);
  //qqqqHist = (TH1F*)file.Get( ("R10_idm_bg_qqqq_1500") );
  //qqqqlvHist = (TH1F*)file.Get( ("R10_idm_bg_qqqqlv_1500") );
  //qqvvHist = (TH1F*)file.Get( ("R10_idm_bg_qqvv_1500") );
  //qqHist = (TH1F*)file.Get( ("R10_idm_bg_qq_1500") );
  llHist->SetLineWidth(3);
  qqllHist->SetLineWidth(3);
  qqlvHist->SetLineWidth(3);
  qqlvlvHist->SetLineWidth(3);
  qqlvvvHist->SetLineWidth(3);
  signalHist->SetLineWidth(3);
  llHist->SetStats(kFALSE);
  qqllHist->SetStats(kFALSE);
  qqlvHist->SetStats(kFALSE);
  qqlvlvHist->SetStats(kFALSE);
  qqlvvvHist->SetStats(kFALSE);
  signalHist->SetStats(kFALSE);
  TLegend *Leg = new TLegend(0.8,0.65,0.9,0.9);
  Leg->AddEntry(llHist, "ll", "L");
	Leg->AddEntry(qqllHist, "qqll", "L");
  Leg->AddEntry(qqlvHist, "qqlv", "L");
	Leg->AddEntry(qqlvlvHist, "qqlvlv", "L");
  Leg->AddEntry(qqlvvvHist, "qqlvvv", "L");
  char signalHistName[signalChannel.size() + 1];
  strcpy(signalHistName, (signalChannel).c_str());
  Leg->AddEntry(signalHist, signalHistName, "L");
  llHist->Scale( 1673.16*lumi/100000 );
  qqllHist->Scale( 2826.22*lumi/100000 );
  qqlvHist->Scale( 8748.91*lumi/100000 );
  qqlvlvHist->Scale( 79.4786*lumi/10000 );
  qqlvvvHist->Scale( 90.212*lumi/10000 );
  signalHist->Scale( sigmaSignal*lumi/10000 );
  qqlvHist->SetMinimum(0.0001);
  qqlvHist->Draw("HIST");
  llHist->Draw( "SAME HIST" );
  qqllHist->Draw("SAME HIST");
  qqlvlvHist->Draw("SAME HIST");
  qqlvvvHist->Draw("SAME HIST");
  signalHist->Draw("SAME HIST");

  Leg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/variablePlots/" + signalChannel + "_" + variable + "CompareR10.jpg").c_str() );

}

void drawHistos( Double_t sigmaSignal = 1., std::string signalChannel = "hphm_slep_BP18" ) {

  plotVarHisto("jetsMass", sigmaSignal, signalChannel);
  plotVarHisto("jetsEnergy", sigmaSignal, signalChannel);
  plotVarHisto("jetsTheta", sigmaSignal, signalChannel);
  plotVarHisto("jetDeltaTheta", sigmaSignal, signalChannel);
  plotVarHisto("jetDeltaPhi", sigmaSignal, signalChannel);
  plotVarHisto("lepPt", sigmaSignal, signalChannel);
  plotVarHisto("lepEnergy", sigmaSignal, signalChannel);
  plotVarHisto("lepTheta", sigmaSignal, signalChannel);
  plotVarHisto("met", sigmaSignal, signalChannel);
  plotVarHisto("missingMass", sigmaSignal, signalChannel);

}
