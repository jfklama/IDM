void plotVarHisto(std::string variable = "WhadMass",  std::string signalChannel = "HP17") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();
  //TFile file("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsAfterCuts.root", "READ");

  string signalFile = "./histoFiles/plotsAfterPreselectionFullSim_" + signalChannel + ".root";
  char signalFileName[signalChannel.size() + 1];
  strcpy(signalFileName, (signalFile).c_str());

  TFile file_qqll("./histoFiles/plotsAfterPreselectionFullSim_qqll.root", "READ");
  TFile file_qqlv("./histoFiles/plotsAfterPreselectionFullSim_qqlv.root", "READ");
  TFile file_ll("./histoFiles/plotsAfterPreselectionFullSim_ll.root", "READ");
  TFile file_qqqq("./histoFiles/plotsAfterPreselectionFullSim_qqqq.root", "READ");
  TFile file_signal(signalFileName, "READ");

  TH1F *llHist = (TH1F*)file_ll.Get( (variable).c_str() );
  TH1F *qqllHist = (TH1F*)file_qqll.Get( (variable).c_str() );
  TH1F *qqlvHist = (TH1F*)file_qqlv.Get( (variable).c_str() );
  TH1F *qqqqHist = (TH1F*)file_qqqq.Get( (variable).c_str() );

  TH1F *signalHist = (TH1F*)file_signal.Get( (variable).c_str() );

  cout << variable << endl;

  Double_t lumi = 4000;

  llHist->SetLineColor(kBlue);
  qqllHist->SetLineColor(kRed);
  qqlvHist->SetLineColor(kPink+10);
  qqqqHist->SetLineColor(kGreen-1);
  signalHist->SetLineColor(kCyan);
  //qqqqHist = (TH1F*)file.Get( ("R10_idm_bg_qqqq_1500") );
  //qqqqlvHist = (TH1F*)file.Get( ("R10_idm_bg_qqqqlv_1500") );
  //qqvvHist = (TH1F*)file.Get( ("R10_idm_bg_qqvv_1500") );
  //qqHist = (TH1F*)file.Get( ("R10_idm_bg_qq_1500") );
  llHist->SetLineWidth(3);
  qqllHist->SetLineWidth(3);
  qqlvHist->SetLineWidth(3);
  qqqqHist->SetLineWidth(3);
  signalHist->SetLineWidth(3);
  llHist->SetStats(kFALSE);
  qqllHist->SetStats(kFALSE);
  qqlvHist->SetStats(kFALSE);
  qqqqHist->SetStats(kFALSE);
  signalHist->SetStats(kFALSE);
  TLegend *Leg = new TLegend(0.8,0.65,0.9,0.9);
  Leg->AddEntry(llHist, "ll", "L");
	Leg->AddEntry(qqllHist, "qqll", "L");
  Leg->AddEntry(qqlvHist, "qqlv", "L");
	Leg->AddEntry(qqqqHist, "qqqq", "L");
  char signalHistName[signalChannel.size() + 1];
  strcpy(signalHistName, (signalChannel).c_str());
  Leg->AddEntry(signalHist, signalHistName, "L");
/*  llHist->Scale( 1673.16*lumi/100000 );
  qqllHist->Scale( 2826.22*lumi/100000 );
  qqlvHist->Scale( 8748.91*lumi/100000 );
  qqqqHist->Scale( 79.4786*lumi/10000 );
  signalHist->Scale( sigmaSignal*lumi/10000 ); */
  qqlvHist->SetMinimum(0.0001);
  qqlvHist->Draw("HIST");
  llHist->Draw( "SAME HIST" );
  qqllHist->Draw("SAME HIST");
  qqqqHist->Draw("SAME HIST");
  signalHist->Draw("SAME HIST");

  Leg->Draw("SAME");
  c1.Print( ("./plots/varPlots/" + signalChannel + "_" + variable + "Compare.jpg").c_str() );

}

void drawHistos(  std::string signalChannel = "HP17" ) {

  plotVarHisto("WhadMass", signalChannel);
  plotVarHisto("WlepMass", signalChannel);
  plotVarHisto("jetsEnergy", signalChannel);
  plotVarHisto("jetsTheta", signalChannel);
  plotVarHisto("jetDeltaTheta", signalChannel);
  plotVarHisto("jetDeltaPhi", signalChannel);
  plotVarHisto("jetPt", signalChannel);
  plotVarHisto("lepPt", signalChannel);
  plotVarHisto("lepEnergy", signalChannel);
  plotVarHisto("lepTheta", signalChannel);
  plotVarHisto("met", signalChannel);
  plotVarHisto("missingMass", signalChannel);

}

void drawAllHistos() {

  drawHistos("BP21");
  drawHistos("BP23");
  drawHistos("HP17");
  drawHistos("HP20");
  drawHistos("HP3");

}
