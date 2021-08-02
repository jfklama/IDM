#include "CLICdpStyle.C"

void drawAfterBDT(){
    TFile *file1 = TFile::Open(
"/home/jfklama/FUW/CLIC/IDM/1500/BDT/outputRootFiles/my_mva_selection_test_HP15.root");
    TTree *TestTree = (TTree*)file1->Get("dataset/TestTree");

    gStyle->SetOptStat(0);

    TH1 *hbgtrain;
    TH1 *hbgtest;
    TH1 *hsignaltest;

    TCanvas *c = new TCanvas("c", "masa", 200, 10, 600, 400);
    TestTree->Draw("jetsEnergy>>hsignaltest", "classID==1","");
    hsignaltest = (TH1*)gPad->GetPrimitive("hsignaltest");
    Double_t bgEntries = hsignaltest->GetEntries();
    if (c) { c->Close(); gSystem->ProcessEvents(); }

    new TCanvas();
    //TestTree->Draw("jetsM_inv>>hbgtrain", "BDT>0.14 && classID==0", "hist");
    TestTree->Draw("jetsEnergy>>hbgtrain", "BDT>0.14 && classID==0", "hist");
    hbgtrain = (TH1*)gPad->GetPrimitive("hbgtrain");
    cout << "1 signal entries: " << hbgtrain->GetEntries() << std::endl;
    //hbgtrain->Scale( 2000.*12.602/100000. );
    hbgtrain->Scale( 2000.*4.7676/100000. );
    cout << "1 signal scaled: " << hbgtrain->Integral() << std::endl;

    //TestTree->Draw("jetsM_inv>>hbgtest", "BDT>0.14 && classID==1","same hist");
    TestTree->Draw("jetsEnergy>>hbgtest", "BDT>0.14 && classID==1","same hist");
    hbgtest = (TH1*)gPad->GetPrimitive("hbgtest");
    cout << "2 background entries: " << hbgtest->GetEntries() << std::endl;
    hbgtest->Scale( 1078272./bgEntries );
    cout << "2 background scaled: " << hbgtest->Integral() << std::endl;

    gPad->Modified();

    hbgtrain->SetLineColor( kRed );
    hbgtest->SetLineColor(  kBlack );
    hbgtest->SetXTitle("E_{j1}+E_{j2}");
    //hbgtest->SetXTitle("M_{jj}");

    TCanvas c1("c1", "", 200, 10, 800, 600);
    hbgtest->Draw("hist");
    hbgtrain->Draw("hist same");

    TLegend *Leg = new TLegend(0.7,0.8,0.9,0.9);
    Leg->AddEntry(hbgtest, "background", "L");
  	Leg->AddEntry(hbgtrain, "signal HP15 (W*)", "L");

    Leg->Draw("same");

    //c1.Print("jetsMassHP15_after.png");
    c1.Print("jetsEnergyHP15_after.png");
}

void drawBDTResponse(std::string channel = "HP17"){

    CLICdpStyle();

    string signalLegendStr = channel + " signal (test sample)";
    char signalLegend[signalLegendStr.size() + 1];
    strcpy( signalLegend, signalLegendStr.c_str() );
    string signalTrainLegendStr = channel + " signal (training sample)";
    char signalTrainLegend[signalTrainLegendStr.size() + 1];
    strcpy( signalTrainLegend, signalTrainLegendStr.c_str() );

    string fileDirStr = "./outputRootFiles/my_mva_selection_" + channel + ".root";
    char fileDir[fileDirStr.size() + 1];
    strcpy( fileDir, fileDirStr.c_str() );

    TFile *file1 = TFile::Open(fileDir);
    TTree *TestTree = (TTree*)file1->Get("dataset/TestTree");
    TTree *TrainTree = (TTree*)file1->Get("dataset/TrainTree");

    gStyle->SetOptStat(0);

    TH1 *hbgtrain;
    TH1 *hbgtest;
    TH1 *hsignaltrain;
    TH1 *hsignaltest;

    TCanvas *c = new TCanvas("c", "bdt", 200, 10, 600, 400);
    TrainTree->Draw("BDT>>hbgtrain", "(classID==1)*2*w","p");
    hbgtrain = (TH1*)gPad->GetPrimitive("hbgtrain");
    Double_t bgEntries = hbgtrain->GetEntries();

    TestTree->Draw("BDT>>hbgtest", "(classID==1)*2*w","hist same");
    hbgtest = (TH1*)gPad->GetPrimitive("hbgtest");
    cout << "test background entries: " << hbgtest->GetEntries() << std::endl;
    cout << "test background scaled: " << hbgtest->Integral() << std::endl;

    TrainTree->Draw("BDT>>hsignaltrain", "(classID==0)*2*w", "hist same");
    hsignaltrain = (TH1*)gPad->GetPrimitive("hsignaltrain");
    cout << "train signal entries: " << hsignaltrain->GetEntries() << std::endl;
    cout << "train signal scaled: " << hsignaltrain->Integral() << std::endl;

    TestTree->Draw("BDT>>hsignaltest", "(classID==0)*2*w", "hist same");
    hsignaltest = (TH1*)gPad->GetPrimitive("hsignaltest");
    cout << "test signal entries: " << hsignaltest->GetEntries() << std::endl;
    cout << "test signal scaled: " << hsignaltest->Integral() << std::endl;

    if (c) { c->Close(); gSystem->ProcessEvents(); }

    hbgtrain->GetYaxis()->SetRangeUser(1,hbgtrain->GetMaximum() * 50);
    hbgtrain->SetTitle( "" );
    hbgtrain->SetMarkerColor( kRed );
    hbgtrain->SetMarkerStyle( 8 );
    hbgtrain->SetMarkerSize( 0.8 );
    hbgtest->GetYaxis()->SetRangeUser(1,hbgtest->GetMaximum() * 50);
    hbgtest->SetLineColor(  kRed );
    hbgtest->SetFillStyle(  3354 );
    hbgtest->SetFillColor(  kRed );
    hsignaltrain->SetMarkerColor(  kBlue );
    hsignaltrain->SetMarkerStyle( 8 );
    hsignaltrain->SetMarkerSize( 0.8 );
    hsignaltest->SetLineColor(  kBlue );
    hsignaltest->SetFillStyle(  3345 );
    hsignaltest->SetFillColor(  kBlue );
    hbgtrain->SetXTitle("BDT response");
    hbgtrain->SetYTitle("Events");
    hbgtest->SetXTitle("BDT response");
    hbgtest->SetYTitle("Events");

    TCanvas c1("c1", "", 200, 10, 800, 600);
    //hbgtrain->Draw("hist p");
    hbgtest->Draw("hist");
    //hsignaltrain->Draw("hist p same");
    hsignaltest->Draw("hist same");


    TLegend *Leg = new TLegend(0.3,0.77,0.9,0.88);
    //Leg->AddEntry(hbgtrain, "Background (training sample)", "p");
    Leg->AddEntry(hbgtest, "Background (test sample)", "f");
    //Leg->AddEntry(hsignaltrain, signalTrainLegend, "p");
    Leg->AddEntry(hsignaltest, signalLegend, "f");
    Leg->SetFillStyle(0);

    Leg->Draw("same");

    c1.SetLogy();
    c1.SetTitle("");
    c1.Print( ("BDTResponse/BDTResponse_" + channel + ".pdf").c_str() );
}
