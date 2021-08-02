#include "./CLICdpStyle.C"

void plotDataDiff_allResults()
{
  CLICdpStyle();


  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  //if(!ch1)  ch1 = new TCanvas("ch1","Inert Doublet Model",20,20,600,450);
  if(!ch1)  ch1 = new TCanvas("ch1","",20,20,600,450);
  ch1->cd();

  TTree *sig1500 = new TTree("sig1500","Significance1500");
  TTree *sig3000 = new TTree("sig3000","Significance3000");
  TTree *sigOverlay1500 = new TTree("sigOverlay1500","Significance1500");
  TTree *sigOverlay3000 = new TTree("sigOverlay3000","Significance3000");
  // sig1500->ReadFile("signifDiffVsmassDiff_DelphesWithOverlay_1500.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  // sig3000->ReadFile("signifDiffVsmassDiff_DelphesWithOverlay_3000.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  //sigOverlay1500->ReadFile("signifDiffVsmassDiff_DelphesWithOverlay_1500.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  //sigOverlay3000->ReadFile("signifDiffVsmassDiff_DelphesWithOverlay_3000.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  sig1500->ReadFile("signifDiff-massDiff_fullsim-fastsim_singleSampleTrain_1500.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  sig3000->ReadFile("signifDiff-massDiff_fullsim-fastsim_singleSampleTrain_3000.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  sigOverlay1500->ReadFile("signifDiff-massDiff_fullsim-overlay_singleSampleTrain_simpleMissingP4_1500.txt","bp/C:deltaM/F:deltaSig:sigRatio");
  sigOverlay3000->ReadFile("signifDiff-massDiff_fullsim-overlay_singleSampleTrain_simpleMissingP4_3000.txt","bp/C:deltaM/F:deltaSig:sigRatio");

  //sig1500->Print();
  //sig3000->Print();

  sig1500->SetMarkerStyle(53);
  sig1500->SetMarkerColor(7);
  sigOverlay1500->SetMarkerStyle(20);
  sigOverlay1500->SetMarkerColor(7);
  sig3000->SetMarkerStyle(53);
  sig3000->SetMarkerColor(2);
  sigOverlay3000->SetMarkerStyle(20);
  sigOverlay3000->SetMarkerColor(2);
  //  sig3000->SetMarkerSize(1.5);

  sig1500->Draw("deltaSig:deltaM");
  sig3000->Draw("deltaSig:deltaM","","same");
  sigOverlay1500->Draw("deltaSig:deltaM","","same");
  sigOverlay3000->Draw("deltaSig:deltaM","","same");
  /* sig1500->Draw("sigRatio:deltaM");
  sig3000->Draw("sigRatio:deltaM","","same");
  sigOverlay1500->Draw("sigRatio:deltaM","","same");
  sigOverlay3000->Draw("sigRatio:deltaM","","same"); */
  //ch1->BuildLegend();

  TCanvas  *ch2 = (TCanvas *) gROOT->FindObject("ch2");
  //if(!ch2)  ch2 = new TCanvas("ch2","Inert Doublet Model",20,20,600,450);
  if(!ch2)  ch2 = new TCanvas("ch2","",20,20,600,450);
  ch2->cd();

  ch2->DrawFrame(0,0,2200.,21.);

  TGraph *gr = new TGraph(sig3000->GetSelectedRows(), sig3000->GetV2(), sig3000->GetV1());
  gr->SetTitle("3 TeV;m_{H^{#pm}}-m_{H};signif_{full}/signif_{fast}");
  //gr->SetTitle("Trained on non-smeared and smeared");
  gr->SetMarkerStyle(53);
  gr->SetMarkerColor(kBlue+4);
  gr->Draw("p"); //draw graph in current pad
  gr->GetXaxis()->SetRangeUser(0.0,250.0);
  gr->GetYaxis()->SetRangeUser(0.0,1.6);

  TGraph *gr2 = new TGraph(sig1500->GetSelectedRows(), sig1500->GetV2(), sig1500->GetV1());
  gr2->SetTitle("1.5 TeV;m_{H^{#pm}}-m_{H};signif_{full}/signif_{fast}");
  gr2->SetMarkerStyle(53);
  gr2->SetMarkerColor(kOrange+7);
  gr2->Draw("p"); //draw graph in current pad
/*
  gr2->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr2->GetYaxis()->SetRangeUser(0.0,62.0);
  gr2->Draw("AP");
  ch2->Update();
*/

  TGraph *gr3 = new TGraph(sigOverlay3000->GetSelectedRows(), sigOverlay3000->GetV2(), sigOverlay3000->GetV1());
  gr3->SetTitle("3 TeV;m_{H^{#pm}}-m_{H} [GeV];Significance diff. (fast - full)");
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerColor(kBlue);
  gr3->GetXaxis()->SetRangeUser(0.0,250.0);
  gr3->GetYaxis()->SetRangeUser(-1.0,21.0);

  TGraph *gr4 = new TGraph(sigOverlay1500->GetSelectedRows(), sigOverlay1500->GetV2(), sigOverlay1500->GetV1());
  gr4->SetTitle("1.5 TeV;m_{H^{#pm}}-m_{H};signif_{full}/signif_{fast}");
  gr4->SetMarkerStyle(20);
  gr4->SetMarkerColor(kOrange-3);

  gr3->Draw("AP"); //draw graph in current pad
  gr4->Draw("p"); //draw graph in current pad
  gr->Draw("p");
  gr2->Draw("p"); //draw graph in current pad



  TLine *line = new TLine(0.0,0.0,250.0,0.0);
  line->SetLineStyle(5);
  line->SetLineColor(2);
  line->Draw("same");

  TLegend *Leg = new TLegend(0.7,0.65,0.9,0.9);
  Leg->AddEntry(gr2, "1.5 TeV", "p");
  Leg->AddEntry(gr, "3 TeV", "p");
  Leg->AddEntry(gr4, "1.5 TeV (with overlay)", "p");
  Leg->AddEntry(gr3, "3 TeV (with overlay)", "p");
  Leg->Draw("same");

  //ch2->SetTitle("Trained on non-smeared and smeared");

  ch2->Modified();
  ch2->Update();

}
