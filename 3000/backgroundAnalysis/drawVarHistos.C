void drawVarHistos(const char *variable = "") {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();
  TFile file("~/FUW/CLIC/IDM/backgroundAnalysis/VarHistograms.root", "READ");

  //JETS
  TH1F *llJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_ll_3000") );
  TH1F *qqllJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqll_3000") );
  TH1F *qqlvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  TH1F *qqJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18JetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_hphm_slep_BP18_3000") );

  TH1F *llJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_ll_3000") );
  TH1F *qqllJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqll_3000") );
  TH1F *qqlvJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qqvv_3000") );
  TH1F *qqJetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18JetsEnergyHist = (TH1F*)file.Get( ("jetsEnergyR12_idm_hphm_slep_BP18_3000") );

  TH1F *llJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_ll_3000") );
  TH1F *qqllJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqll_3000") );
  TH1F *qqlvJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qqvv_3000") );
  TH1F *qqJetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18JetsThetaHist = (TH1F*)file.Get( ("jetsThetaR12_idm_hphm_slep_BP18_3000") );

  TH1F *llJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_ll_3000") );
  TH1F *qqllJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqll_3000") );
  TH1F *qqlvJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qqvv_3000") );
  TH1F *qqJetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18JetDeltaThetaHist = (TH1F*)file.Get( ("jetDeltaThetaR12_idm_hphm_slep_BP18_3000") );

  TH1F *llJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_ll_3000") );
  TH1F *qqllJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqll_3000") );
  TH1F *qqlvJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qqvv_3000") );
  TH1F *qqJetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18JetDeltaPhiHist = (TH1F*)file.Get( ("jetDeltaPhiR12_idm_hphm_slep_BP18_3000") );



  //LEPTON
  TH1F *llLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_ll_3000") );
  TH1F *qqllLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqll_3000") );
  TH1F *qqlvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqvv_3000") );
  TH1F *qqLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18LepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_hphm_slep_BP18_3000") );

  TH1F *llLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_ll_3000") );
  TH1F *qqllLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqll_3000") );
  TH1F *qqlvLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qqvv_3000") );
  TH1F *qqLepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18LepEnergyHist = (TH1F*)file.Get( ("lepEnergyR12_idm_hphm_slep_BP18_3000") );

  TH1F *llLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_ll_3000") );
  TH1F *qqllLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqll_3000") );
  TH1F *qqlvLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqlv_3000") );
  TH1F *qqlvlvLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqlvlv_3000") );
  TH1F *qqlvvvLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqlvvv_3000") );
  TH1F *qqqqLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqqq_3000") );
  TH1F *qqqqlvLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqqqlv_3000") );
  TH1F *qqvvLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qqvv_3000") );
  TH1F *qqLepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_bg_qq_3000") );
  TH1F *hphpm_BP18LepThetaHist = (TH1F*)file.Get( ("lepThetaR12_idm_hphm_slep_BP18_3000") );

  ////////////////////////////////////
  ////// DRAWING ////////////////////
  //////////////////////////////////

  //JETS MASS

  Double_t norm = 4000;

  llJetsMassHist->SetLineColor(kBlue);
  qqllJetsMassHist->SetLineColor(kRed);
  qqlvJetsMassHist->SetLineColor(kPink+10);
  qqlvlvJetsMassHist->SetLineColor(kGreen-1);
  qqlvvvJetsMassHist->SetLineColor(kOrange-3);
  hphpm_BP18JetsMassHist->SetLineColor(kCyan);
  //qqqqJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  //qqqqlvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  //qqvvJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  //qqJetsMassHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  llJetsMassHist->SetLineWidth(3);
  qqllJetsMassHist->SetLineWidth(3);
  qqlvJetsMassHist->SetLineWidth(3);
  qqlvlvJetsMassHist->SetLineWidth(3);
  qqlvvvJetsMassHist->SetLineWidth(3);
  hphpm_BP18JetsMassHist->SetLineWidth(3);
  llJetsMassHist->SetStats(kFALSE);
  qqllJetsMassHist->SetStats(kFALSE);
  qqlvJetsMassHist->SetStats(kFALSE);
  qqlvlvJetsMassHist->SetStats(kFALSE);
  qqlvvvJetsMassHist->SetStats(kFALSE);
  hphpm_BP18JetsMassHist->SetStats(kFALSE);
  TLegend *JetsMassLeg = new TLegend(0.8,0.65,0.9,0.9);
  JetsMassLeg->AddEntry(llJetsMassHist, "ll", "L");
	JetsMassLeg->AddEntry(qqllJetsMassHist, "qqll", "L");
  JetsMassLeg->AddEntry(qqlvJetsMassHist, "qqlv", "L");
	JetsMassLeg->AddEntry(qqlvlvJetsMassHist, "qqlvlv", "L");
  JetsMassLeg->AddEntry(qqlvvvJetsMassHist, "qqlvvv", "L");
  JetsMassLeg->AddEntry(hphpm_BP18JetsMassHist, "hphpm_BP18", "L");
  /* llJetsMassHist->Scale( norm/(llJetsMassHist->Integral()) );
  qqllJetsMassHist->Scale( norm/(qqllJetsMassHist->Integral()) );
  qqlvJetsMassHist->Scale( norm/(qqlvJetsMassHist->Integral()) );
  qqlvlvJetsMassHist->Scale( norm/(qqlvlvJetsMassHist->Integral()) );
  qqlvvvJetsMassHist->Scale( norm/(qqlvvvJetsMassHist->Integral()) );
  llJetsMassHist->Scale( 1673.16/(llJetsMassHist->Integral()) );
  qqllJetsMassHist->Scale( 2826.22/(qqllJetsMassHist->Integral()) );
  qqlvJetsMassHist->Scale( 8748.91/(qqlvJetsMassHist->Integral()) );
  qqlvlvJetsMassHist->Scale( 79.4786/(qqlvlvJetsMassHist->Integral()) );
  qqlvvvJetsMassHist->Scale( 90.212/(qqlvvvJetsMassHist->Integral()) );*/
  llJetsMassHist->Scale( 1673.16/100000 );
  qqllJetsMassHist->Scale( 2826.22/100000 );
  qqlvJetsMassHist->Scale( 8748.91/100000 );
  qqlvlvJetsMassHist->Scale( 79.4786/10000 );
  qqlvvvJetsMassHist->Scale( 90.212/10000 );
  hphpm_BP18JetsMassHist->Scale( 4.88591/10000 );
  qqlvJetsMassHist->SetMinimum(0.0001);
  qqlvJetsMassHist->Draw("HIST");
  llJetsMassHist->Draw( "SAME HIST" );
  qqllJetsMassHist->Draw("SAME HIST");
  qqlvlvJetsMassHist->Draw("SAME HIST");
  qqlvvvJetsMassHist->Draw("SAME HIST");
  hphpm_BP18JetsMassHist->Draw("SAME HIST");
  /* THStack *hsJetsMass = new THStack("hsJetsMass","");
  hsJetsMass->Add(llJetsMassHist);
  hsJetsMass->Add(qqllJetsMassHist);
  hsJetsMass->Add(qqlvJetsMassHist);
  hsJetsMass->Add(qqlvlvJetsMassHist);
  hsJetsMass->Add(qqlvvvJetsMassHist);
  hsJetsMass->Draw("HIST");*/
  JetsMassLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/jetMassCompareR12.jpg") );


  //JETS ENERGY

  llJetsEnergyHist->SetLineColor(kBlue);
  qqllJetsEnergyHist->SetLineColor(kRed);
  qqlvJetsEnergyHist->SetLineColor(kPink+10);
  qqlvlvJetsEnergyHist->SetLineColor(kGreen-1);
  qqlvvvJetsEnergyHist->SetLineColor(kOrange-3);
  hphpm_BP18JetsEnergyHist->SetLineColor(kCyan);
  //qqqqJetsEnergyHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  //qqqqlvJetsEnergyHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  //qqvvJetsEnergyHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  //qqJetsEnergyHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  llJetsEnergyHist->SetLineWidth(3);
  qqllJetsEnergyHist->SetLineWidth(3);
  qqlvJetsEnergyHist->SetLineWidth(3);
  qqlvlvJetsEnergyHist->SetLineWidth(3);
  qqlvvvJetsEnergyHist->SetLineWidth(3);
  hphpm_BP18JetsEnergyHist->SetLineWidth(3);
  llJetsEnergyHist->SetStats(kFALSE);
  qqllJetsEnergyHist->SetStats(kFALSE);
  qqlvJetsEnergyHist->SetStats(kFALSE);
  qqlvlvJetsEnergyHist->SetStats(kFALSE);
  qqlvvvJetsEnergyHist->SetStats(kFALSE);
  hphpm_BP18JetsEnergyHist->SetStats(kFALSE);
  TLegend *JetsEnergyLeg = new TLegend(0.8,0.65,0.9,0.9);
  JetsEnergyLeg->AddEntry(llJetsEnergyHist, "ll", "L");
  JetsEnergyLeg->AddEntry(qqllJetsEnergyHist, "qqll", "L");
  JetsEnergyLeg->AddEntry(qqlvJetsEnergyHist, "qqlv", "L");
  JetsEnergyLeg->AddEntry(qqlvlvJetsEnergyHist, "qqlvlv", "L");
  JetsEnergyLeg->AddEntry(qqlvvvJetsEnergyHist, "qqlvvv", "L");
  JetsEnergyLeg->AddEntry(hphpm_BP18JetsEnergyHist, "hphpm_BP18", "L");
  /* llJetsEnergyHist->Scale( norm/(llJetsEnergyHist->Integral()) );
  qqllJetsEnergyHist->Scale( norm/(qqllJetsEnergyHist->Integral()) );
  qqlvJetsEnergyHist->Scale( norm/(qqlvJetsEnergyHist->Integral()) );
  qqlvlvJetsEnergyHist->Scale( norm/(qqlvlvJetsEnergyHist->Integral()) );
  qqlvvvJetsEnergyHist->Scale( norm/(qqlvvvJetsEnergyHist->Integral()) );
  llJetsEnergyHist->Scale( 1673.16/(llJetsEnergyHist->Integral()) );
  qqllJetsEnergyHist->Scale( 2826.22/(qqllJetsEnergyHist->Integral()) );
  qqlvJetsEnergyHist->Scale( 8748.91/(qqlvJetsEnergyHist->Integral()) );
  qqlvlvJetsEnergyHist->Scale( 79.4786/(qqlvlvJetsEnergyHist->Integral()) );
  qqlvvvJetsEnergyHist->Scale( 90.212/(qqlvvvJetsEnergyHist->Integral()) );*/
  llJetsEnergyHist->Scale( 1673.16/100000 );
  qqllJetsEnergyHist->Scale( 2826.22/100000 );
  qqlvJetsEnergyHist->Scale( 8748.91/100000 );
  qqlvlvJetsEnergyHist->Scale( 79.4786/10000 );
  qqlvvvJetsEnergyHist->Scale( 90.212/10000 );
  hphpm_BP18JetsEnergyHist->Scale( 4.88591/10000 );
  qqlvJetsEnergyHist->SetMinimum(0.0001);
  qqlvJetsEnergyHist->Draw("HIST");
  llJetsEnergyHist->Draw( "SAME HIST" );
  qqllJetsEnergyHist->Draw("SAME HIST");
  qqlvlvJetsEnergyHist->Draw("SAME HIST");
  qqlvvvJetsEnergyHist->Draw("SAME HIST");
  hphpm_BP18JetsEnergyHist->Draw("SAME HIST");
  /* THStack *hsJetsEnergy = new THStack("hsJetsMass","");
  hsJetsEnergy->Add(llJetsEnergyHist);
  hsJetsEnergy->Add(qqllJetsEnergyHist);
  hsJetsEnergy->Add(qqlvJetsEnergyHist);
  hsJetsEnergy->Add(qqlvlvJetsEnergyHist);
  hsJetsEnergy->Add(qqlvvvJetsEnergyHist);
  hsJetsEnergy->Draw("HIST"); */
  JetsEnergyLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/jetsEnergyCompareR12.jpg") );

  //JETS THETA

  llJetsThetaHist->SetLineColor(kBlue);
  qqllJetsThetaHist->SetLineColor(kRed);
  qqlvJetsThetaHist->SetLineColor(kPink+10);
  qqlvlvJetsThetaHist->SetLineColor(kGreen-1);
  qqlvvvJetsThetaHist->SetLineColor(kOrange-3);
  hphpm_BP18JetsThetaHist->SetLineColor(kCyan);
  //qqqqJetsThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  //qqqqlvJetsThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  //qqvvJetsThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  //qqJetsThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  llJetsThetaHist->SetLineWidth(3);
  qqllJetsThetaHist->SetLineWidth(3);
  qqlvJetsThetaHist->SetLineWidth(3);
  qqlvlvJetsThetaHist->SetLineWidth(3);
  qqlvvvJetsThetaHist->SetLineWidth(3);
  hphpm_BP18JetsThetaHist->SetLineWidth(3);
  llJetsThetaHist->SetStats(kFALSE);
  qqllJetsThetaHist->SetStats(kFALSE);
  qqlvJetsThetaHist->SetStats(kFALSE);
  qqlvlvJetsThetaHist->SetStats(kFALSE);
  qqlvvvJetsThetaHist->SetStats(kFALSE);
  hphpm_BP18JetsThetaHist->SetStats(kFALSE);
  TLegend *JetsThetaLeg = new TLegend(0.8,0.65,0.9,0.9);
  JetsThetaLeg->AddEntry(llJetsThetaHist, "ll", "L");
  JetsThetaLeg->AddEntry(qqllJetsThetaHist, "qqll", "L");
  JetsThetaLeg->AddEntry(qqlvJetsThetaHist, "qqlv", "L");
  JetsThetaLeg->AddEntry(qqlvlvJetsThetaHist, "qqlvlv", "L");
  JetsThetaLeg->AddEntry(qqlvvvJetsThetaHist, "qqlvvv", "L");
  JetsThetaLeg->AddEntry(hphpm_BP18JetsThetaHist, "hphpm_BP18", "L");
  /* llJetsThetaHist->Scale( norm/(llJetsThetaHist->Integral()) );
  qqllJetsThetaHist->Scale( norm/(qqllJetsThetaHist->Integral()) );
  qqlvJetsThetaHist->Scale( norm/(qqlvJetsThetaHist->Integral()) );
  qqlvlvJetsThetaHist->Scale( norm/(qqlvlvJetsThetaHist->Integral()) );
  qqlvvvJetsThetaHist->Scale( norm/(qqlvvvJetsThetaHist->Integral()) );
  llJetsThetaHist->Scale( 1673.16/(llJetsThetaHist->Integral()) );
  qqllJetsThetaHist->Scale( 2826.22/(qqllJetsThetaHist->Integral()) );
  qqlvJetsThetaHist->Scale( 8748.91/(qqlvJetsThetaHist->Integral()) );
  qqlvlvJetsThetaHist->Scale( 79.4786/(qqlvlvJetsThetaHist->Integral()) );
  qqlvvvJetsThetaHist->Scale( 90.212/(qqlvvvJetsThetaHist->Integral()) ); */
  llJetsThetaHist->Scale( 1673.16/100000 );
  qqllJetsThetaHist->Scale( 2826.22/100000 );
  qqlvJetsThetaHist->Scale( 8748.91/100000 );
  qqlvlvJetsThetaHist->Scale( 79.4786/10000 );
  qqlvvvJetsThetaHist->Scale( 90.212/10000 );
  hphpm_BP18JetsThetaHist->Scale( 4.88591/10000 );
  qqlvJetsThetaHist->SetMinimum(0.0001);
  qqlvJetsThetaHist->Draw("HIST");
  llJetsThetaHist->Draw( "SAME HIST" );
  qqllJetsThetaHist->Draw("SAME HIST");
  qqlvlvJetsThetaHist->Draw("SAME HIST");
  qqlvvvJetsThetaHist->Draw("SAME HIST");
  hphpm_BP18JetsThetaHist->Draw("SAME HIST");
  /* THStack *hsJetsTheta = new THStack("hsJetsMass","");
  hsJetsTheta->Add(llJetsThetaHist);
  hsJetsTheta->Add(qqllJetsThetaHist);
  hsJetsTheta->Add(qqlvJetsThetaHist);
  hsJetsTheta->Add(qqlvlvJetsThetaHist);
  hsJetsTheta->Add(qqlvvvJetsThetaHist);
  hsJetsTheta->Draw("HIST"); */
  JetsThetaLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/jetsThetaCompareR12.jpg") );

  //JET-W DELTA THETA

  llJetDeltaThetaHist->SetLineColor(kBlue);
  qqllJetDeltaThetaHist->SetLineColor(kRed);
  qqlvJetDeltaThetaHist->SetLineColor(kPink+10);
  qqlvlvJetDeltaThetaHist->SetLineColor(kGreen-1);
  qqlvvvJetDeltaThetaHist->SetLineColor(kOrange-3);
  hphpm_BP18JetDeltaThetaHist->SetLineColor(kCyan);
  //qqqqJetDeltaThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  //qqqqlvJetDeltaThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  //qqvvJetDeltaThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  //qqJetDeltaThetaHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  llJetDeltaThetaHist->SetLineWidth(3);
  qqllJetDeltaThetaHist->SetLineWidth(3);
  qqlvJetDeltaThetaHist->SetLineWidth(3);
  qqlvlvJetDeltaThetaHist->SetLineWidth(3);
  qqlvvvJetDeltaThetaHist->SetLineWidth(3);
  hphpm_BP18JetDeltaThetaHist->SetLineWidth(3);
  llJetDeltaThetaHist->SetStats(kFALSE);
  qqllJetDeltaThetaHist->SetStats(kFALSE);
  qqlvJetDeltaThetaHist->SetStats(kFALSE);
  qqlvlvJetDeltaThetaHist->SetStats(kFALSE);
  qqlvvvJetDeltaThetaHist->SetStats(kFALSE);
  hphpm_BP18JetDeltaThetaHist->SetStats(kFALSE);
  TLegend *JetDeltaThetaLeg = new TLegend(0.8,0.65,0.9,0.9);
  JetDeltaThetaLeg->AddEntry(llJetDeltaThetaHist, "ll", "L");
  JetDeltaThetaLeg->AddEntry(qqllJetDeltaThetaHist, "qqll", "L");
  JetDeltaThetaLeg->AddEntry(qqlvJetDeltaThetaHist, "qqlv", "L");
  JetDeltaThetaLeg->AddEntry(qqlvlvJetDeltaThetaHist, "qqlvlv", "L");
  JetDeltaThetaLeg->AddEntry(qqlvvvJetDeltaThetaHist, "qqlvvv", "L");
  JetDeltaThetaLeg->AddEntry(hphpm_BP18JetDeltaThetaHist, "hphpm_BP18", "L");
  /* llJetDeltaThetaHist->Scale( norm/(llJetDeltaThetaHist->Integral()) );
  qqllJetDeltaThetaHist->Scale( norm/(qqllJetDeltaThetaHist->Integral()) );
  qqlvJetDeltaThetaHist->Scale( norm/(qqlvJetDeltaThetaHist->Integral()) );
  qqlvlvJetDeltaThetaHist->Scale( norm/(qqlvlvJetDeltaThetaHist->Integral()) );
  qqlvvvJetDeltaThetaHist->Scale( norm/(qqlvvvJetDeltaThetaHist->Integral()) );
  llJetDeltaThetaHist->Scale( 1673.16/(llJetDeltaThetaHist->Integral()) );
  qqllJetDeltaThetaHist->Scale( 2826.22/(qqllJetDeltaThetaHist->Integral()) );
  qqlvJetDeltaThetaHist->Scale( 8748.91/(qqlvJetDeltaThetaHist->Integral()) );
  qqlvlvJetDeltaThetaHist->Scale( 79.4786/(qqlvlvJetDeltaThetaHist->Integral()) );
  qqlvvvJetDeltaThetaHist->Scale( 90.212/(qqlvvvJetDeltaThetaHist->Integral()) ); */
  llJetDeltaThetaHist->Scale( 1673.16/100000 );
  qqllJetDeltaThetaHist->Scale( 2826.22/100000 );
  qqlvJetDeltaThetaHist->Scale( 8748.91/100000 );
  qqlvlvJetDeltaThetaHist->Scale( 79.4786/10000 );
  qqlvvvJetDeltaThetaHist->Scale( 90.212/10000 );
  hphpm_BP18JetDeltaThetaHist->Scale( 4.88591/10000 );
  qqlvJetDeltaThetaHist->SetMinimum(0.0001);
  qqlvJetDeltaThetaHist->Draw("HIST");
  llJetDeltaThetaHist->Draw( "SAME HIST" );
  qqllJetDeltaThetaHist->Draw("SAME HIST");
  qqlvlvJetDeltaThetaHist->Draw("SAME HIST");
  qqlvvvJetDeltaThetaHist->Draw("SAME HIST");
  hphpm_BP18JetDeltaThetaHist->Draw("SAME HIST");
  /* THStack *hsJetDeltaTheta = new THStack("hsJetsMass","");
  hsJetDeltaTheta->Add(llJetDeltaThetaHist);
  hsJetDeltaTheta->Add(qqllJetDeltaThetaHist);
  hsJetDeltaTheta->Add(qqlvJetDeltaThetaHist);
  hsJetDeltaTheta->Add(qqlvlvJetDeltaThetaHist);
  hsJetDeltaTheta->Add(qqlvvvJetDeltaThetaHist);
  hsJetDeltaTheta->Draw("HIST"); */
  JetDeltaThetaLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/jetDeltaThetaCompareR12.jpg") );

  //JET-W DELTA PHI

  llJetDeltaPhiHist->SetLineColor(kBlue);
  qqllJetDeltaPhiHist->SetLineColor(kRed);
  qqlvJetDeltaPhiHist->SetLineColor(kPink+10);
  qqlvlvJetDeltaPhiHist->SetLineColor(kGreen-1);
  qqlvvvJetDeltaPhiHist->SetLineColor(kOrange-3);
  hphpm_BP18JetDeltaPhiHist->SetLineColor(kCyan);
  //qqqqJetDeltaPhiHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqq_3000") );
  //qqqqlvJetDeltaPhiHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqqqlv_3000") );
  //qqvvJetDeltaPhiHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qqvv_3000") );
  //qqJetDeltaPhiHist = (TH1F*)file.Get( ("jetsMassR12_idm_bg_qq_3000") );
  llJetDeltaPhiHist->SetLineWidth(3);
  qqllJetDeltaPhiHist->SetLineWidth(3);
  qqlvJetDeltaPhiHist->SetLineWidth(3);
  qqlvlvJetDeltaPhiHist->SetLineWidth(3);
  qqlvvvJetDeltaPhiHist->SetLineWidth(3);
  hphpm_BP18JetDeltaPhiHist->SetLineWidth(3);
  llJetDeltaPhiHist->SetStats(kFALSE);
  qqllJetDeltaPhiHist->SetStats(kFALSE);
  qqlvJetDeltaPhiHist->SetStats(kFALSE);
  qqlvlvJetDeltaPhiHist->SetStats(kFALSE);
  qqlvvvJetDeltaPhiHist->SetStats(kFALSE);
  hphpm_BP18JetDeltaPhiHist->SetStats(kFALSE);
  TLegend *JetDeltaPhiLeg = new TLegend(0.8,0.65,0.9,0.9);
  JetDeltaPhiLeg->AddEntry(llJetDeltaPhiHist, "ll", "L");
  JetDeltaPhiLeg->AddEntry(qqllJetDeltaPhiHist, "qqll", "L");
  JetDeltaPhiLeg->AddEntry(qqlvJetDeltaPhiHist, "qqlv", "L");
  JetDeltaPhiLeg->AddEntry(qqlvlvJetDeltaPhiHist, "qqlvlv", "L");
  JetDeltaPhiLeg->AddEntry(qqlvvvJetDeltaPhiHist, "qqlvvv", "L");
  JetDeltaPhiLeg->AddEntry(hphpm_BP18JetDeltaPhiHist, "hphpm_BP18", "L");
  /* llJetDeltaPhiHist->Scale( norm/(llJetDeltaPhiHist->Integral()) );
  qqllJetDeltaPhiHist->Scale( norm/(qqllJetDeltaPhiHist->Integral()) );
  qqlvJetDeltaPhiHist->Scale( norm/(qqlvJetDeltaPhiHist->Integral()) );
  qqlvlvJetDeltaPhiHist->Scale( norm/(qqlvlvJetDeltaPhiHist->Integral()) );
  qqlvvvJetDeltaPhiHist->Scale( norm/(qqlvvvJetDeltaPhiHist->Integral()) );
  llJetDeltaPhiHist->Scale( 1673.16/(llJetDeltaPhiHist->Integral()) );
  qqllJetDeltaPhiHist->Scale( 2826.22/(qqllJetDeltaPhiHist->Integral()) );
  qqlvJetDeltaPhiHist->Scale( 8748.91/(qqlvJetDeltaPhiHist->Integral()) );
  qqlvlvJetDeltaPhiHist->Scale( 79.4786/(qqlvlvJetDeltaPhiHist->Integral()) );
  qqlvvvJetDeltaPhiHist->Scale( 90.212/(qqlvvvJetDeltaPhiHist->Integral()) ); */
  llJetDeltaPhiHist->Scale( 1673.16/100000 );
  qqllJetDeltaPhiHist->Scale( 2826.22/100000 );
  qqlvJetDeltaPhiHist->Scale( 8748.91/100000 );
  qqlvlvJetDeltaPhiHist->Scale( 79.4786/10000 );
  qqlvvvJetDeltaPhiHist->Scale( 90.212/10000 );
  hphpm_BP18JetDeltaPhiHist->Scale( 4.88591/10000 );
  qqlvJetDeltaPhiHist->SetMinimum(0.0001);
  qqlvJetDeltaPhiHist->Draw("HIST");
  llJetDeltaPhiHist->Draw( "SAME HIST" );
  qqllJetDeltaPhiHist->Draw("SAME HIST");
  qqlvlvJetDeltaPhiHist->Draw("SAME HIST");
  qqlvvvJetDeltaPhiHist->Draw("SAME HIST");
  hphpm_BP18JetDeltaPhiHist->Draw("SAME HIST");
  /* THStack *hsJetDeltaPhi = new THStack("hsJetsMass","");
  hsJetDeltaPhi->Add(llJetDeltaPhiHist);
  hsJetDeltaPhi->Add(qqllJetDeltaPhiHist);
  hsJetDeltaPhi->Add(qqlvJetDeltaPhiHist);
  hsJetDeltaPhi->Add(qqlvlvJetDeltaPhiHist);
  hsJetDeltaPhi->Add(qqlvvvJetDeltaPhiHist);
  hsJetDeltaPhi->Draw("HIST"); */
  JetDeltaPhiLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/jetDeltaPhiCompareR12.jpg") );

  ////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////// LEPTONS ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////

  //LEPTON PT

  llLepPtHist->SetLineColor(kBlue);
  qqllLepPtHist->SetLineColor(kRed);
  qqlvLepPtHist->SetLineColor(kPink+10);
  qqlvlvLepPtHist->SetLineColor(kGreen-1);
  qqlvvvLepPtHist->SetLineColor(kOrange-3);
  hphpm_BP18LepPtHist->SetLineColor(kCyan);
  //qqqqLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqq_3000") );
  //qqqqlvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqqlv_3000") );
  //qqvvLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqvv_3000") );
  //qqLepPtHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qq_3000") );
  llLepPtHist->SetLineWidth(3);
  qqllLepPtHist->SetLineWidth(3);
  qqlvLepPtHist->SetLineWidth(3);
  qqlvlvLepPtHist->SetLineWidth(3);
  qqlvvvLepPtHist->SetLineWidth(3);
  hphpm_BP18LepPtHist->SetLineWidth(3);
  llLepPtHist->SetStats(kFALSE);
  qqllLepPtHist->SetStats(kFALSE);
  qqlvLepPtHist->SetStats(kFALSE);
  qqlvlvLepPtHist->SetStats(kFALSE);
  qqlvvvLepPtHist->SetStats(kFALSE);
  hphpm_BP18LepPtHist->SetStats(kFALSE);
  TLegend *LepPtLeg = new TLegend(0.8,0.65,0.9,0.9);
  LepPtLeg->AddEntry(llLepPtHist, "ll", "L");
	LepPtLeg->AddEntry(qqllLepPtHist, "qqll", "L");
  LepPtLeg->AddEntry(qqlvLepPtHist, "qqlv", "L");
	LepPtLeg->AddEntry(qqlvlvLepPtHist, "qqlvlv", "L");
  LepPtLeg->AddEntry(qqlvvvLepPtHist, "qqlvvv", "L");
  LepPtLeg->AddEntry(hphpm_BP18LepPtHist, "hphpm_BP18", "L");
  /* llLepPtHist->Scale( norm/(llLepPtHist->Integral()) );
  qqllLepPtHist->Scale( norm/(qqllLepPtHist->Integral()) );
  qqlvLepPtHist->Scale( norm/(qqlvLepPtHist->Integral()) );
  qqlvlvLepPtHist->Scale( norm/(qqlvlvLepPtHist->Integral()) );
  qqlvvvLepPtHist->Scale( norm/(qqlvvvLepPtHist->Integral()) );
  llLepPtHist->Scale( 1673.16/(llLepPtHist->Integral()) );
  qqllLepPtHist->Scale( 2826.22/(qqllLepPtHist->Integral()) );
  qqlvLepPtHist->Scale( 8748.91/(qqlvLepPtHist->Integral()) );
  qqlvlvLepPtHist->Scale( 79.4786/(qqlvlvLepPtHist->Integral()) );
  qqlvvvLepPtHist->Scale( 90.212/(qqlvvvLepPtHist->Integral()) ); */
  llLepPtHist->Scale( 1673.16/100000 );
  qqllLepPtHist->Scale( 2826.22/100000 );
  qqlvLepPtHist->Scale( 8748.91/100000 );
  qqlvlvLepPtHist->Scale( 79.4786/10000 );
  qqlvvvLepPtHist->Scale( 90.212/10000 );
  hphpm_BP18LepPtHist->Scale( 4.88591/10000 );
  qqlvLepPtHist->SetMinimum(0.0001);
  qqlvLepPtHist->Draw("HIST");
  llLepPtHist->Draw( "SAME HIST" );
  qqllLepPtHist->Draw("SAME HIST");
  qqlvlvLepPtHist->Draw("SAME HIST");
  qqlvvvLepPtHist->Draw("SAME HIST");
  hphpm_BP18LepPtHist->Draw("SAME HIST");
  /* THStack *hsLepPt = new THStack("hsLepPt","");
  hsLepPt->Add(llLepPtHist);
  hsLepPt->Add(qqllLepPtHist);
  hsLepPt->Add(qqlvLepPtHist);
  hsLepPt->Add(qqlvlvLepPtHist);
  hsLepPt->Add(qqlvvvLepPtHist);
  hsLepPt->Draw("HIST");*/
  LepPtLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/lepPtCompareR12.jpg") );


  //LEPTON ENERGY

  llLepEnergyHist->SetLineColor(kBlue);
  qqllLepEnergyHist->SetLineColor(kRed);
  qqlvLepEnergyHist->SetLineColor(kPink+10);
  qqlvlvLepEnergyHist->SetLineColor(kGreen-1);
  qqlvvvLepEnergyHist->SetLineColor(kOrange-3);
  hphpm_BP18LepEnergyHist->SetLineColor(kCyan);
  //qqqqLepEnergyHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqq_3000") );
  //qqqqlvLepEnergyHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqqlv_3000") );
  //qqvvLepEnergyHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqvv_3000") );
  //qqLepEnergyHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qq_3000") );
  llLepEnergyHist->SetLineWidth(3);
  qqllLepEnergyHist->SetLineWidth(3);
  qqlvLepEnergyHist->SetLineWidth(3);
  qqlvlvLepEnergyHist->SetLineWidth(3);
  qqlvvvLepEnergyHist->SetLineWidth(3);
  hphpm_BP18LepEnergyHist->SetLineWidth(3);
  llLepEnergyHist->SetStats(kFALSE);
  qqllLepEnergyHist->SetStats(kFALSE);
  qqlvLepEnergyHist->SetStats(kFALSE);
  qqlvlvLepEnergyHist->SetStats(kFALSE);
  qqlvvvLepEnergyHist->SetStats(kFALSE);
  hphpm_BP18LepEnergyHist->SetStats(kFALSE);
  TLegend *LepEnergyLeg = new TLegend(0.8,0.65,0.9,0.9);
  LepEnergyLeg->AddEntry(llLepEnergyHist, "ll", "L");
  LepEnergyLeg->AddEntry(qqllLepEnergyHist, "qqll", "L");
  LepEnergyLeg->AddEntry(qqlvLepEnergyHist, "qqlv", "L");
  LepEnergyLeg->AddEntry(qqlvlvLepEnergyHist, "qqlvlv", "L");
  LepEnergyLeg->AddEntry(qqlvvvLepEnergyHist, "qqlvvv", "L");
  LepEnergyLeg->AddEntry(hphpm_BP18LepEnergyHist, "hphpm_BP18", "L");
  /* llLepEnergyHist->Scale( norm/(llLepEnergyHist->Integral()) );
  qqllLepEnergyHist->Scale( norm/(qqllLepEnergyHist->Integral()) );
  qqlvLepEnergyHist->Scale( norm/(qqlvLepEnergyHist->Integral()) );
  qqlvlvLepEnergyHist->Scale( norm/(qqlvlvLepEnergyHist->Integral()) );
  qqlvvvLepEnergyHist->Scale( norm/(qqlvvvLepEnergyHist->Integral()) );
  llLepEnergyHist->Scale( 1673.16/(llLepEnergyHist->Integral()) );
  qqllLepEnergyHist->Scale( 2826.22/(qqllLepEnergyHist->Integral()) );
  qqlvLepEnergyHist->Scale( 8748.91/(qqlvLepEnergyHist->Integral()) );
  qqlvlvLepEnergyHist->Scale( 79.4786/(qqlvlvLepEnergyHist->Integral()) );
  qqlvvvLepEnergyHist->Scale( 90.212/(qqlvvvLepEnergyHist->Integral()) ); */
  llLepEnergyHist->Scale( 1673.16/100000 );
  qqllLepEnergyHist->Scale( 2826.22/100000 );
  qqlvLepEnergyHist->Scale( 8748.91/100000 );
  qqlvlvLepEnergyHist->Scale( 79.4786/10000 );
  qqlvvvLepEnergyHist->Scale( 90.212/10000 );
  hphpm_BP18LepEnergyHist->Scale( 4.88591/10000 );
  qqlvLepEnergyHist->SetMinimum(0.0001);
  qqlvLepEnergyHist->Draw("HIST");
  llLepEnergyHist->Draw( "SAME HIST" );
  qqllLepEnergyHist->Draw("SAME HIST");
  qqlvlvLepEnergyHist->Draw("SAME HIST");
  qqlvvvLepEnergyHist->Draw("SAME HIST");
  hphpm_BP18LepEnergyHist->Draw("SAME HIST");
  /* THStack *hsLepEnergy = new THStack("hsLepPt","");
  hsLepEnergy->Add(llLepEnergyHist);
  hsLepEnergy->Add(qqllLepEnergyHist);
  hsLepEnergy->Add(qqlvLepEnergyHist);
  hsLepEnergy->Add(qqlvlvLepEnergyHist);
  hsLepEnergy->Add(qqlvvvLepEnergyHist);
  hsLepEnergy->Draw("HIST");*/
  LepEnergyLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/lepEnergyCompareR12.jpg") );

  //LEPTON THETA

  llLepThetaHist->SetLineColor(kBlue);
  qqllLepThetaHist->SetLineColor(kRed);
  qqlvLepThetaHist->SetLineColor(kPink+10);
  qqlvlvLepThetaHist->SetLineColor(kGreen-1);
  qqlvvvLepThetaHist->SetLineColor(kOrange-3);
  hphpm_BP18LepThetaHist->SetLineColor(kCyan);
  //qqqqLepThetaHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqq_3000") );
  //qqqqlvLepThetaHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqqqlv_3000") );
  //qqvvLepThetaHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qqvv_3000") );
  //qqLepThetaHist = (TH1F*)file.Get( ("lepPtR12_idm_bg_qq_3000") );
  llLepThetaHist->SetLineWidth(3);
  qqllLepThetaHist->SetLineWidth(3);
  qqlvLepThetaHist->SetLineWidth(3);
  qqlvlvLepThetaHist->SetLineWidth(3);
  qqlvvvLepThetaHist->SetLineWidth(3);
  hphpm_BP18LepThetaHist->SetLineWidth(3);
  llLepThetaHist->SetStats(kFALSE);
  qqllLepThetaHist->SetStats(kFALSE);
  qqlvLepThetaHist->SetStats(kFALSE);
  qqlvlvLepThetaHist->SetStats(kFALSE);
  qqlvvvLepThetaHist->SetStats(kFALSE);
  hphpm_BP18LepThetaHist->SetStats(kFALSE);
  TLegend *LepThetaLeg = new TLegend(0.8,0.65,0.9,0.9);
  LepThetaLeg->AddEntry(llLepThetaHist, "ll", "L");
  LepThetaLeg->AddEntry(qqllLepThetaHist, "qqll", "L");
  LepThetaLeg->AddEntry(qqlvLepThetaHist, "qqlv", "L");
  LepThetaLeg->AddEntry(qqlvlvLepThetaHist, "qqlvlv", "L");
  LepThetaLeg->AddEntry(qqlvvvLepThetaHist, "qqlvvv", "L");
  LepThetaLeg->AddEntry(hphpm_BP18LepThetaHist, "hphpm_BP18", "L");
  /* llLepThetaHist->Scale( norm/(llLepThetaHist->Integral()) );
  qqllLepThetaHist->Scale( norm/(qqllLepThetaHist->Integral()) );
  qqlvLepThetaHist->Scale( norm/(qqlvLepThetaHist->Integral()) );
  qqlvlvLepThetaHist->Scale( norm/(qqlvlvLepThetaHist->Integral()) );
  qqlvvvLepThetaHist->Scale( norm/(qqlvvvLepThetaHist->Integral()) );
  llLepThetaHist->Scale( 1673.16/(llLepThetaHist->Integral()) );
  qqllLepThetaHist->Scale( 2826.22/(qqllLepThetaHist->Integral()) );
  qqlvLepThetaHist->Scale( 8748.91/(qqlvLepThetaHist->Integral()) );
  qqlvlvLepThetaHist->Scale( 79.4786/(qqlvlvLepThetaHist->Integral()) );
  qqlvvvLepThetaHist->Scale( 90.212/(qqlvvvLepThetaHist->Integral()) ); */
  llLepThetaHist->Scale( 1673.16/100000 );
  qqllLepThetaHist->Scale( 2826.22/100000 );
  qqlvLepThetaHist->Scale( 8748.91/100000 );
  qqlvlvLepThetaHist->Scale( 79.4786/10000 );
  qqlvvvLepThetaHist->Scale( 90.212/10000 );
  hphpm_BP18LepThetaHist->Scale( 4.88591/10000 );
  qqlvLepThetaHist->SetMinimum(0.0001);
  qqlvLepThetaHist->Draw("HIST");
  llLepThetaHist->Draw( "SAME HIST" );
  qqllLepThetaHist->Draw("SAME HIST");
  qqlvlvLepThetaHist->Draw("SAME HIST");
  qqlvvvLepThetaHist->Draw("SAME HIST");
  hphpm_BP18LepThetaHist->Draw("SAME HIST");
  /* THStack *hsLepTheta = new THStack("hsLepPt","");
  hsLepTheta->Add(llLepThetaHist);
  hsLepTheta->Add(qqllLepThetaHist);
  hsLepTheta->Add(qqlvLepThetaHist);
  hsLepTheta->Add(qqlvlvLepThetaHist);
  hsLepTheta->Add(qqlvvvLepThetaHist);
  hsLepTheta->Draw("HIST"); */
  LepThetaLeg->Draw("SAME");
  c1.Print( ("~/FUW/CLIC/IDM/backgroundAnalysis/plots/variablePlots/lepThetaCompareR12.jpg") );

}
