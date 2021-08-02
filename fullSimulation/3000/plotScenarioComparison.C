void plotScenarioComparison(std::string variable = "jetsMass",
                            Double_t sigma1 = 1., std::string channel1 = "HP3",
                            Double_t sigma2 = 1., std::string channel2 = "HP17",
                            Double_t sigma3 = 1., std::string channel3 = "HP20"
                          ) {

  TCanvas c1("c1", "", 200, 10, 1200, 600);
  c1.SetLogy();

  //TFile filefullSim("./histoFiles/VarHistogramsAfterCuts.root", "READ");
  TFile file0( ("./histoFiles/plotsBeforePreselectionFullSim_" + channel1 + ".root").c_str(), "READ" );
  TFile file1( ("./histoFiles/plotsBeforePreselectionFullSim_" + channel2 + ".root").c_str(), "READ" );
  TFile file2( ("./histoFiles/plotsBeforePreselectionFullSim_" + channel3 + ".root").c_str(), "READ" );

  std::string fullSimVar = variable;
  if(variable == "jetsMass")
    fullSimVar = "WhadMass";

  TH1F *fullSimHist0 = (TH1F*)file0.Get( (fullSimVar).c_str() );
  TH1F *fullSimHist1 = (TH1F*)file1.Get( (fullSimVar).c_str() );
  TH1F *fullSimHist2 = (TH1F*)file2.Get( (fullSimVar).c_str() );
  // if(sigma > 100)
  //   fullSimHist = (TH1F*)filefullSim.Get( (fullSimVar + "R12_idm_bg_" + channel + "_3000").c_str() );

  //TH1F *fullSimHist = (TH1F*)fileFullSim.Get( (fullSimVar).c_str() );

  Double_t lumi = 4000;

  fullSimHist0->SetLineColor(kRed);
  fullSimHist1->SetLineColor(kBlue);
  fullSimHist2->SetLineColor(kGreen);
  // fullSimHist->SetLineColor(kRed);

  fullSimHist0->SetLineWidth(2);
  fullSimHist1->SetLineWidth(2);
  fullSimHist2->SetLineWidth(2);
  // fullSimHist->SetLineWidth(2);

  fullSimHist0->SetStats(kFALSE);
  fullSimHist1->SetStats(kFALSE);
  fullSimHist2->SetStats(kFALSE);
  // fullSimHist->SetStats(kFALSE);

  double x1, y1, x2, y2;
  if(fullSimVar=="missingMass") { x1 = 0.1; y1 = 0.65; x2 = 0.23, y2 = 0.9; }
  else { x1 = 0.77; y1 = 0.65; x2 = 0.9, y2 = 0.9; }

  TLegend *Leg = new TLegend(x1,y1,x2,y2);
  Leg->AddEntry(fullSimHist0, (channel1).c_str(), "L");
  Leg->AddEntry(fullSimHist1, (channel2).c_str(), "L");
  Leg->AddEntry(fullSimHist2, (channel3).c_str(), "L");
  // Leg->AddEntry(fullSimHist, "full sim.", "L");
/*
  if(sigma < 100)
    fullSimHist->Scale( sigma*lumi/100000 );
  else
    fullSimHist->Scale( sigma*lumi/1000000 );
*/

  fullSimHist0->Scale( sigma1*lumi/100000 );
  fullSimHist1->Scale( sigma2*lumi/100000 );
  fullSimHist2->Scale( sigma3*lumi/100000 );

  //fullSimHist->SetTitle("no lepton selection");

  // fullSimHist->Draw(" HIST");
  fullSimHist0->Draw("SAME HIST");
  fullSimHist1->Draw("SAME HIST");
  fullSimHist2->Draw("SAME HIST");

  // cout << fullSimHist->Integral() << " " << fullSimHist0->Integral() << " " << fullSimHist1->Integral() << endl;


  Leg->Draw("SAME");
  c1.Print( ("./plots/scenarioComparison/" + channel1 + "_" + channel2 + "_" + channel3 + "_" + fullSimVar + "_ScenarioComparison.jpg").c_str() );
  c1.Print( ("./plots/scenarioComparison/" + channel1 + "_" + channel2 + "_" + channel3 + "_" + fullSimVar + "_ScenarioComparison.pdf").c_str() );

}

void drawAll( Double_t sigma1 = 1.775, Double_t sigma2 = 1.678, Double_t sigma3 = 1.506,
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
