#include "./CLICdpStyle.C"

void plotData()
{
  CLICdpStyle();


  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  //if(!ch1)  ch1 = new TCanvas("ch1","Inert Doublet Model",20,20,600,450);
  if(!ch1)  ch1 = new TCanvas("ch1","",20,20,600,450);
  ch1->cd();

  TTree *sigDelphes1500 = new TTree("sigDelphes1500","SignificanceDelphes1500");
  TTree *sigFullSim1500_allBg = new TTree("sigFullSim1500_allBg","SignificanceFullSim1500_allBg");
  TTree *sigFullSim1500 = new TTree("sigFullSim1500","SignificanceFullSim1500");
  // sigFullSim1500->ReadFile("run_process_loop_clic_hphm_6+7.dat","set/I:ene/I:mH/F:mA:mHpm:ah:hphm:scs:sig");
  sigDelphes1500->ReadFile("signif-mass_Delphes1500.txt","bp/C:2mH/F:sig");
  sigFullSim1500_allBg->ReadFile("signif-mass_fullSim1500_allBg.txt","bp/C:2mH/F:sig");
  sigFullSim1500->ReadFile("signif-mass_fullSim1500.txt","bp/C:2mH/F:sig");

  //sigDelphes1500->Print();
  //sigFullSim1500->Print();

  sigDelphes1500->SetMarkerStyle(20);
  sigDelphes1500->SetMarkerColor(7);
  sigFullSim1500_allBg->SetMarkerStyle(20);
  sigFullSim1500_allBg->SetMarkerColor(kSpring+10);
  sigFullSim1500->SetMarkerStyle(20);
  sigFullSim1500->SetMarkerColor(2);
  //  sigFullSim1500->SetMarkerSize(1.5);

  sigDelphes1500->Draw("sig:2mH");
  sigFullSim1500_allBg->Draw("sig:2mH","","same");
  // sigFullSim1500->Draw("sig:2mH","","same");
  //ch1->BuildLegend();

  TCanvas  *ch2 = (TCanvas *) gROOT->FindObject("ch2");
  //if(!ch2)  ch2 = new TCanvas("ch2","Inert Doublet Model",20,20,600,450);
  if(!ch2)  ch2 = new TCanvas("ch2","",20,20,600,450);
  ch2->cd();

  ch2->DrawFrame(0,0,2200.,65.);

  TGraph *gr3 = new TGraph(sigFullSim1500->GetSelectedRows(), sigFullSim1500->GetV2(), sigFullSim1500->GetV1());
  gr3->SetTitle("Full simulation;2m_{H^{#pm}};S/#sqrt{S+B}");
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerColor(2);
  // gr3->Draw("AP"); //draw graph in current pad
  gr3->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr3->GetYaxis()->SetRangeUser(0.0,65.0);
  // gr3->Draw("AP");

  TGraph *gr = new TGraph(sigDelphes1500->GetSelectedRows(), sigDelphes1500->GetV2(), sigDelphes1500->GetV1());
  gr->SetTitle("Fast simulation;2m_{H^{#pm}};S/#sqrt{S+B}");
  gr->SetMarkerStyle(20);
  gr->SetMarkerColor(7);
  gr->Draw("AP"); //draw graph in current pad
  gr->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr->GetYaxis()->SetRangeUser(0.0,65.0);
  gr->Draw("AP");

  TGraph *gr2 = new TGraph(sigFullSim1500_allBg->GetSelectedRows(), sigFullSim1500_allBg->GetV2(), sigFullSim1500_allBg->GetV1());
  gr2->SetTitle("Full simulation (full background);2m_{H^{#pm}};S/#sqrt{S+B}");
  gr2->SetMarkerStyle(20);
  // gr2->SetMarkerColor(kSpring+10);
  gr2->SetMarkerColor(2);
  gr2->Draw("p"); //draw graph in current pad
/*
  gr->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr->GetYaxis()->SetRangeUser(0.0,62.0);
  gr->Draw("AP");
  ch2->Update();
*/

  TLine *line = new TLine(275.0,5.0,1375.0,5.0);
  line->SetLineStyle(5);
  line->SetLineColor(2);
  line->Draw("same");

  TLegend *Leg = new TLegend(0.6,0.7,0.9,0.9);
  Leg->AddEntry(gr, "Fast simulation", "p");
  Leg->AddEntry(gr2, "Full simulation", "p");
  // Leg->AddEntry(gr3, "Full simulation", "p");
  Leg->Draw("same");

  ch2->Modified();
  ch2->Update();

}
