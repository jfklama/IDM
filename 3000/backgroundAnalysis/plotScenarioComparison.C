void plotScenarioComparison(std::string variable = "jetsMass",
                            Double_t sigma1 = 1., std::string channel1 = "HP3",
                            Double_t sigma2 = 1., std::string channel2 = "HP17",
                            Double_t sigma3 = 1., std::string channel3 = "HP20"
                          ) {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  //TFile fileFastSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile file0("./VarHistogramsBeforeCuts_withOverlay.root", "READ");

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  TH1F *fastSimHist0 = (TH1F*)file0.Get( (variable + "R12_idm_hphm_slep_" + channel1 + "_3000").c_str() );
  TH1F *fastSimHist1 = (TH1F*)file0.Get( (variable + "R12_idm_hphm_slep_" + channel2 + "_3000").c_str() );
  TH1F *fastSimHist2 = (TH1F*)file0.Get( (variable + "R12_idm_hphm_slep_" + channel3 + "_3000").c_str() );
  // if(sigma > 100)
  //   fastSimHist = (TH1F*)fileFastSim.Get( (variable + "R12_idm_bg_" + channel + "_3000").c_str() );

  //TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 4000;

  fastSimHist0->SetLineColor(kRed);
  fastSimHist1->SetLineColor(kBlue);
  fastSimHist2->SetLineColor(kGreen);
  // fullSimHist->SetLineColor(kRed);

  fastSimHist0->SetLineWidth(2);
  fastSimHist1->SetLineWidth(2);
  fastSimHist2->SetLineWidth(2);
  // fullSimHist->SetLineWidth(2);

  fastSimHist0->SetStats(kFALSE);
  fastSimHist1->SetStats(kFALSE);
  fastSimHist2->SetStats(kFALSE);
  // fullSimHist->SetStats(kFALSE);

  double x1, y1, x2, y2;
  if(variable=="missingMass") { x1 = 0.1; y1 = 0.65; x2 = 0.23, y2 = 0.9; }
  else { x1 = 0.77; y1 = 0.65; x2 = 0.9, y2 = 0.9; }

  TLegend *Leg = new TLegend(x1,y1,x2,y2);
  Leg->AddEntry(fastSimHist0, (channel1).c_str(), "L");
  Leg->AddEntry(fastSimHist1, (channel2).c_str(), "L");
  Leg->AddEntry(fastSimHist2, (channel3).c_str(), "L");
  // Leg->AddEntry(fullSimHist, "full sim.", "L");
/*
  if(sigma < 100)
    fastSimHist->Scale( sigma*lumi/100000 );
  else
    fastSimHist->Scale( sigma*lumi/1000000 );
*/

  fastSimHist0->Scale( sigma1*lumi/100000 );
  fastSimHist1->Scale( sigma2*lumi/100000 );
  fastSimHist2->Scale( sigma3*lumi/100000 );

  //fullSimHist->SetTitle("no lepton selection");

  // fullSimHist->Draw(" HIST");
  fastSimHist0->Draw("SAME HIST");
  fastSimHist1->Draw("SAME HIST");
  fastSimHist2->Draw("SAME HIST");

  // cout << fullSimHist->Integral() << " " << fastSimHist0->Integral() << " " << fastSimHist1->Integral() << endl;


  Leg->Draw("SAME");
  c1.Print( ("./plots/scenarioComparison/" + channel1 + "_" + channel2 + "_" + channel3 + "_" + variable + "_ScenarioComparison.jpg").c_str() );
  c1.Print( ("./plots/scenarioComparison/" + channel1 + "_" + channel2 + "_" + channel3 + "_" + variable + "_ScenarioComparison.pdf").c_str() );

}

void drawAll( Double_t sigma1 = 1.72873, Double_t sigma2 = 1.42266, Double_t sigma3 = 1.54028,
              std::string channel1 = "HP3", std::string channel2 = "HP17", std::string channel3 = "HP20"
            ) {

  plotScenarioComparison("jetsMass", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("jetsEnergy", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("jetsTheta", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("lepPt", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("lepEnergy", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("lepTheta", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("met", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("missingMass", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("jetDeltaTheta", sigma1, channel1, sigma2, channel2, sigma3, channel3);
  plotScenarioComparison("jetDeltaPhi", sigma1, channel1, sigma2, channel2, sigma3, channel3);

}
