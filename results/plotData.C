#include "./CLICdpStyle.C"

void plotData()
{
  CLICdpStyle();


  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  //if(!ch1)  ch1 = new TCanvas("ch1","Inert Doublet Model",20,20,600,450);
  if(!ch1)  ch1 = new TCanvas("ch1","",20,20,600,450);
  ch1->cd();

  TTree *sigDelphes3000 = new TTree("sigDelphes3000","SignificanceDelphes3000");
  TTree *sigDelphes3000_Overlay = new TTree("sigDelphes3000_Overlay","SignificanceDelphes3000_Overlay");
  TTree *sigFullSim3000 = new TTree("sigFullSim3000","SignificanceFullSim3000");
  // sigFullSim3000->ReadFile("run_process_loop_clic_hphm_6+7.dat","set/I:ene/I:mH/F:mA:mHpm:ah:hphm:scs:sig");
  sigDelphes3000->ReadFile("signif-mass_Delphes3000_SingleSampleTrain.txt","bp/C:2mH/F:sig");
  sigDelphes3000_Overlay->ReadFile("signif-mass_3000_Overlay_SingleSampleTrain_simpleMissingP4.txt","bp/C:2mH/F:sig");
  sigFullSim3000->ReadFile("signif-mass_fullSim3000_SingleSampleTrain.txt","bp/C:2mH/F:sig");

  //sigDelphes3000->Print();
  //sigFullSim3000->Print();

  sigDelphes3000->SetMarkerStyle(20);
  sigDelphes3000->SetMarkerColor(7);
  sigDelphes3000_Overlay->SetMarkerStyle(20);
  sigDelphes3000_Overlay->SetMarkerColor(kSpring+10);
  sigFullSim3000->SetMarkerStyle(20);
  sigFullSim3000->SetMarkerColor(2);
  //  sigFullSim3000->SetMarkerSize(1.5);

  sigDelphes3000->Draw("sig:2mH");
  sigDelphes3000_Overlay->Draw("sig:2mH","","same");
  sigFullSim3000->Draw("sig:2mH","","same");
  //ch1->BuildLegend();

  TCanvas  *ch2 = (TCanvas *) gROOT->FindObject("ch2");
  //if(!ch2)  ch2 = new TCanvas("ch2","Inert Doublet Model",20,20,600,450);
  if(!ch2)  ch2 = new TCanvas("ch2","",20,20,600,450);
  ch2->cd();

  ch2->DrawFrame(0,0,2200.,65.);

  TGraph *gr2 = new TGraph(sigDelphes3000_Overlay->GetSelectedRows(), sigDelphes3000_Overlay->GetV2(), sigDelphes3000_Overlay->GetV1());
  gr2->SetTitle("Fast simulation (overlay);2m_{H^{#pm}} [GeV];S/#sqrt{S+B}");
  gr2->SetMarkerStyle(20);
  gr2->SetMarkerColor(kGreen+1);
  gr2->Draw("AP"); //draw graph in current pad
  gr2->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr2->GetYaxis()->SetRangeUser(0.0,45.0);
  ch2->Update();

  TGraph *gr3 = new TGraph(sigFullSim3000->GetSelectedRows(), sigFullSim3000->GetV2(), sigFullSim3000->GetV1());
  gr3->SetTitle("Full simulation;2m_{H^{#pm}} [GeV];S/#sqrt{S+B}");
  gr3->SetMarkerStyle(53);
  gr3->SetMarkerColor(kRed);
  gr3->GetYaxis()->SetRangeUser(0.0,37.0);

  TGraph *gr = new TGraph(sigDelphes3000->GetSelectedRows(), sigDelphes3000->GetV2(), sigDelphes3000->GetV1());
  gr->SetTitle("Fast simulation;2m_{H^{#pm}} [GeV];S/#sqrt{S+B}");
  gr->SetMarkerStyle(52);
  gr->SetMarkerColor(kAzure+1);


/*
  gr->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr->GetYaxis()->SetRangeUser(0.0,62.0);
  gr->Draw("AP");
  ch2->Update();
*/

  gr2->Draw("AP"); //draw graph in current pad
  gr->Draw("p"); //draw graph in current pad
  gr3->Draw("p");

  TLine *line = new TLine(280.0,5.0,1375.0,5.0);
  //TLine *line = new TLine(295.0,5.0,1360.0,5.0); // for full sim only
  //TLine *line = new TLine(275.0,5.0,1550.0,5.0);
  //TLine *line = new TLine(250.0,5.0,2200.0,5.0);
  line->SetLineStyle(5);
  line->SetLineColor(2);
  line->Draw("same");

  TLegend *Leg = new TLegend(0.6,0.7,0.9,0.9);
  Leg->AddEntry(gr3, "Full simulation", "p");
  Leg->AddEntry(gr2, "Fast simulation (#gamma#gamma #rightarrow had.)", "p");
  Leg->AddEntry(gr, "Fast simulation ", "p");
  Leg->SetFillStyle(0);
  Leg->Draw("same");

  //CLICdpLabel(0.17,0.935,"Preliminary");

  ch2->Modified();
  ch2->Update();

}
