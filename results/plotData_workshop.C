#include "./CLICdpStyle.C"

void plotData_workshop()
{
  CLICdpStyle();


  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  //if(!ch1)  ch1 = new TCanvas("ch1","Inert Doublet Model",20,20,600,450);
  if(!ch1)  ch1 = new TCanvas("ch1","",20,20,600,450);
  ch1->cd();

  TTree *sig1500 = new TTree("sig1500","Significance1500");
  TTree *sig3000 = new TTree("sig3000","Significance1500_real");
  TTree *sig1500_lep = new TTree("sig1500_lep","Significance1500_lep");
  // sig3000->ReadFile("run_process_loop_clic_hphm_6+7.dat","set/I:ene/I:mH/F:mA:mHpm:ah:hphm:scs:sig");
  sig1500->ReadFile("signif-mass_1500_reweighted_simpleMissingP4.txt","bp/C:2mH/F:sig");
  sig3000->ReadFile("signif-mass_3000_reweighted_simpleMissingP4.txt","bp/C:2mH/F:sig");
  sig1500_lep->ReadFile("clic1500_lepton.dat","bp/F:mH:sig");

  //sig1500->Print();
  //sig3000->Print();

  sig1500->SetMarkerStyle(20);
  sig1500->SetMarkerColor(kAzure+2);
  sig3000->SetMarkerStyle(20);
  sig3000->SetMarkerColor(kOrange-3);
  sig1500_lep->SetMarkerStyle(71);
  sig1500_lep->SetMarkerColor(kRed-4);
  //  sig3000->SetMarkerSize(1.5);

  sig1500->Draw("sig:2mH");
  sig3000->Draw("sig:2mH","","same");
  sig1500_lep->Draw("sig:2*mH","","same");
  //ch1->BuildLegend();

  TCanvas  *ch2 = (TCanvas *) gROOT->FindObject("ch2");
  //if(!ch2)  ch2 = new TCanvas("ch2","Inert Doublet Model",20,20,600,450);
  if(!ch2)  ch2 = new TCanvas("ch2","",20,20,600,450);
  ch2->cd();

  ch2->DrawFrame(0,0,2200.,65.);

  TGraph *gr = new TGraph(sig1500->GetSelectedRows(), sig1500->GetV2(), sig1500->GetV1());
  gr->SetTitle("3 TeV;2m_{H^{#pm}};S/#sqrt{S+B}");
  gr->SetMarkerStyle(53);
  gr->SetMarkerColor(kOrange-3);


  TGraph *gr2 = new TGraph(sig3000->GetSelectedRows(), sig3000->GetV2(), sig3000->GetV1());
  //gr2->SetTitle("3 TeV;2m_{H^{#pm}};S/#sqrt{S+B}");
  //gr2->SetTitle("3 TeV;m_{H^{#pm}}-m_{H} [GeV];S/#sqrt{S+B}"); // mass diff.
  gr2->SetTitle("3 TeV;2m_{H^{#pm}} [GeV];S/#sqrt{S+B}");
  gr2->SetMarkerStyle(20);
  gr2->SetMarkerColor(kAzure+2);
  gr2->Draw("AP"); //draw graph in current pad
  gr2->GetXaxis()->SetRangeUser(0.0,2200.0);
  //gr->GetYaxis()->SetRangeUser(0.0,65.0);
  gr2->GetYaxis()->SetRangeUser(0.0,60.);

  TGraph *gr3 = new TGraph(sig1500_lep->GetSelectedRows(), sig1500_lep->GetV2(), sig1500_lep->GetV1());
  gr3->SetTitle("3 TeV;2m_{H^{#pm}};S/#sqrt{S+B}");
  gr3->SetMarkerStyle(71);
  gr3->SetMarkerColor(kRed-4);
  //gr3->GetYaxis()->SetRangeUser(0.0,65.0);

  gr2->Draw("AP");
  //gr3->Draw("p"); //draw graph in current pad
  gr->Draw("p"); //draw graph in current pad


/*
  gr->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr->GetYaxis()->SetRangeUser(0.0,62.0);
  gr->Draw("AP");
  ch2->Update();
*/

  //TLine *line = new TLine(275.0,5.0,1570.0,5.0);
  TLine *line = new TLine(210.0,5.0,2185.0,5.0);
  //TLine *line = new TLine(0.0,5.0,270.0,5.0); // mass diff.
  line->SetLineStyle(5);
  line->SetLineColor(2);
  line->Draw("same");

  TLegend *Leg = new TLegend(0.55,0.65,0.9,0.9);
  Leg->AddEntry(gr, "1.5 TeV, semi-leptonic", "p");
  Leg->AddEntry(gr2, "3 TeV, semi-leptonic", "p");
  //Leg->AddEntry(gr3, "Leptonic final state", "p");
  Leg->SetFillStyle(0);
  Leg->Draw("same");

  CLICdpLabel(0.17,0.935,"Preliminary");

  //ch2->SetLogx();
  gr2->SetMinimum(0);
  gr2->SetMaximum(60.);

  ch2->Modified();
  ch2->Update();

}
