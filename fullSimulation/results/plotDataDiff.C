#include "./CLICdpStyle.C"

void plotData()
{
  CLICdpStyle();


  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  //if(!ch1)  ch1 = new TCanvas("ch1","Inert Doublet Model",20,20,600,450);
  if(!ch1)  ch1 = new TCanvas("ch1","",20,20,600,450);
  ch1->cd();

  TTree *sig1500 = new TTree("sig1500","Significance1500");
  TTree *sig3000 = new TTree("sig3000","Significance3000");
  // sig3000->ReadFile("run_process_loop_clic_hphm_6+7.dat","set/I:ene/I:mH/F:mA:mHpm:ah:hphm:scs:sig");
  sig1500->ReadFile("signif-massDiff1500.txt","bp/C:deltaM/F:sig");
  sig3000->ReadFile("signif-massDiff3000.txt","bp/C:deltaM/F:sig");

  sig1500->Print();
  sig3000->Print();

  sig1500->SetMarkerStyle(20);
  sig1500->SetMarkerColor(7);
  sig3000->SetMarkerStyle(20);
  sig3000->SetMarkerColor(2);
  //  sig3000->SetMarkerSize(1.5);

  sig1500->Draw("sig:deltaM");
  sig3000->Draw("sig:deltaM","","same");
  //ch1->BuildLegend();

  TCanvas  *ch2 = (TCanvas *) gROOT->FindObject("ch2");
  //if(!ch2)  ch2 = new TCanvas("ch2","Inert Doublet Model",20,20,600,450);
  if(!ch2)  ch2 = new TCanvas("ch2","",20,20,600,450);
  ch2->cd();

  ch2->DrawFrame(0,0,2200.,20.);

  TGraph *gr3 = new TGraph(sig3000->GetSelectedRows(), sig3000->GetV2(), sig3000->GetV1());
  gr3->SetTitle("3 TeV;m_{H^{#pm}}-m_{H};|signif_{fast}-signif_{full}|");
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerColor(kBlue);
  gr3->Draw("AP"); //draw graph in current pad
  gr3->GetXaxis()->SetRangeUser(0.0,250.0);
  gr3->GetYaxis()->SetRangeUser(0.0,20.0);
  gr3->Draw("AP");

  TGraph *gr = new TGraph(sig1500->GetSelectedRows(), sig1500->GetV2(), sig1500->GetV1());
  gr->SetTitle("1.5 TeV;m_{H^{#pm}}-m_{H};|signif_{fast}-signif_{full}|");
  gr->SetMarkerStyle(20);
  gr->SetMarkerColor(kOrange-3);
  gr->Draw("p"); //draw graph in current pad
/*
  gr->GetXaxis()->SetRangeUser(0.0,2200.0);
  gr->GetYaxis()->SetRangeUser(0.0,62.0);
  gr->Draw("AP");
  ch2->Update();
*/

  TLine *line = new TLine(200.0,5.0,2200.0,5.0);
  line->SetLineStyle(5);
  line->SetLineColor(2);
  //line->Draw("same");

  TLegend *Leg = new TLegend(0.7,0.6,0.9,0.9);
  Leg->AddEntry(gr, "1.5 TeV", "p");
  Leg->AddEntry(gr3, "3 TeV", "p");
  Leg->Draw("same");

  ch2->Modified();
  ch2->Update();

}
