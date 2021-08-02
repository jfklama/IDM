#include "CLICdpStyle.C"

void drawAfterBDT(
                  std::string sample = "HP17",
                  std::string var = "jetsEnergy",
                  std::string dir = "withOverlay_cutsForFastSim",
                  string cut = "BDT>0.1027"
                 ) {

    double lumi = 4000.;

    std::string dataset = "dataset";
    std::string mode = "";
    std::string Wmode = "(W*)";
    if(sample == "BP21" || sample == "BP23" || sample == "HP1" || sample == "HP4"){
      //mode = "on_shell";
      mode = "off_shell";
      Wmode = "(W)";
    }

    //TFile *file1 = TFile::Open( ("/home/jfklama/FUW/CLIC/IDM/3000/BDT/outputRootFiles/" + dir + "/my_mva_selection_test_" + sample + ".root").c_str() );
    TFile *file1 = TFile::Open( ("/home/jfklama/FUW/CLIC/IDM/3000/BDT/outputRootFiles/my_mva_selection_testOnFullSim_" + sample + ".root").c_str() );
    TTree *TestTree = (TTree*)file1->Get( ("dataset_off_shell_testOnFullSim" + mode + dir + "/TestTree").c_str() );
    TTree *TrainTree = (TTree*)file1->Get( ("dataset_off_shell_testOnFullSim" + mode + dir + "/TrainTree").c_str() );

    gStyle->SetOptStat(0);

    TH1 *hbgtest_before;
    TH1 *hbgtest_after;
    TH1 *hsignaltest_before;
    TH1 *hsignaltest_after;

    TCanvas * c = new TCanvas("c", "masa", 200, 10, 600, 400);
    TestTree->Draw( (var+">>hbgtest_before").c_str(), "(classID==1)*w","" );
    hbgtest_before = (TH1*)gPad->GetPrimitive("hbgtest_before");
    Double_t bgEntries = hbgtest_before->GetEntries();
    if (c) { c->Close(); gSystem->ProcessEvents(); }

    new TCanvas();
    TestTree->Draw( (var+">>hsignaltest_before").c_str(), "(classID==0)*w", "hist" );
    hsignaltest_before = (TH1*)gPad->GetPrimitive("hsignaltest_before");
    cout << "1 signal entries (before): " << hsignaltest_before->GetEntries() << std::endl;
    cout << "1 signal scaled (before): " << hsignaltest_before->Integral() << std::endl;

    //TestTree->Draw("jetsM_inv>>hsignaltest_after", "BDT>0.14 && classID==0", "hist");
    TestTree->Draw( (var+">>hsignaltest_after").c_str(), ("("+cut+" && classID==0)*w").c_str(), "hist" );
    hsignaltest_after = (TH1*)gPad->GetPrimitive("hsignaltest_after");
    cout << "1 signal entries: " << hsignaltest_after->GetEntries() << std::endl;
    //hsignaltest_after->Scale( 2000.*12.602/100000. );
    //hsignaltest_after->Scale( lumi*cs/100000. );
    cout << "1 signal scaled: " << hsignaltest_after->Integral() << std::endl;

    //TestTree->Draw("jetsM_inv>>hbgtest_after", "BDT>0.14 && classID==1","same hist");
    TestTree->Draw( (var+">>hbgtest_after").c_str(), ("("+cut+" && classID==1)*w").c_str(),"same hist");
    hbgtest_after = (TH1*)gPad->GetPrimitive("hbgtest_after");
    cout << "2 background entries: " << hbgtest_after->GetEntries() << std::endl;
    //hbgtest_after->Scale( 1078272./bgEntries );
    cout << "2 background scaled: " << hbgtest_after->Integral() << std::endl;

    cout << endl;
    cout << "Signal significance: " << hsignaltest_after->Integral() / sqrt( hsignaltest_after->Integral() + hbgtest_after->Integral() ) << endl;

    gPad->Modified();

    hsignaltest_before->SetLineColor( kRed );
    hbgtest_before->SetLineColor(  kBlack );
    hsignaltest_before->SetLineStyle( 9 );
    hbgtest_before->SetLineStyle(  9 );
    hsignaltest_after->SetLineColor( kRed );
    hbgtest_after->SetLineColor(  kBlack );
    if(var=="jetsEnergy")
      hbgtest_before->SetXTitle("E_{j1}+E_{j2}");
    if(var=="jetsM_inv")
      hbgtest_before->SetXTitle("M_{jj}");
    if(var=="jetsTheta")
      hbgtest_before->SetXTitle("#theta_{W}");
    hbgtest_before->SetMinimum(0.01);

    TCanvas c1("c1", "", 200, 10, 800, 600);
    c1.SetLogy();
    hbgtest_before->Draw("hist");
    hsignaltest_before->Draw("hist same");
    hbgtest_after->Draw("hist same");
    hsignaltest_after->Draw("hist same");

    TLegend *Leg = new TLegend(0.7,0.8,0.9,0.9);
    Leg->AddEntry(hbgtest_after, "SM background", "L");
  	Leg->AddEntry(hsignaltest_after, ("signal " + sample + " " + Wmode).c_str(), "L");

    Leg->Draw("same");

    c1.Print( ("plotsAfterBDT/testOnFullSim/"+var+sample+"_after_testOnFullSim.jpg").c_str() );

}

void drawAllVars(
                  std::string sample = "HP17",
                  std::string dir = "",
                  string cut = "BDT>0.1027"
                 )  {

  drawAfterBDT( sample, "jetsM_inv", dir, cut);
  drawAfterBDT( sample, "jetsEnergy", dir, cut);
  drawAfterBDT( sample, "jetsTheta", dir, cut);
  drawAfterBDT( sample, "jet1Theta", dir, cut);
  drawAfterBDT( sample, "jet2Theta", dir, cut);
  drawAfterBDT( sample, "jet1Pt", dir, cut);
  drawAfterBDT( sample, "jet2Pt", dir, cut);
  drawAfterBDT( sample, "jet1E", dir, cut);
  drawAfterBDT( sample, "jet2E", dir, cut);
  drawAfterBDT( sample, "leptonEnergy", dir, cut);
  drawAfterBDT( sample, "leptonTheta", dir, cut);
  drawAfterBDT( sample, "leptonPt", dir, cut);
  drawAfterBDT( sample, "jetDeltaTheta", dir, cut);
  drawAfterBDT( sample, "jetDeltaPhi", dir, cut);
  drawAfterBDT( sample, "EFsum", dir, cut);
  drawAfterBDT( sample, "MET", dir, cut);
  drawAfterBDT( sample, "missingMass", dir, cut);

}

void drawOvertrain(std::string channel = "HP17"){

    CLICdpStyle();

    string signalLegendStr = channel + " signal (test sample)";
    char signalLegend[signalLegendStr.size() + 1];
    strcpy( signalLegend, signalLegendStr.c_str() );

    //string fileDirStr = "/home/jfklama/FUW/CLIC/IDM/3000/BDT/outputRootFiles/my_mva_selection_test_" + channel + ".root";
    string fileDirStr = "/home/jfklama/FUW/CLIC/IDM/3000/BDT/outputRootFiles/my_mva_selection_testOnFullSim_" + channel + ".root";
    char fileDir[fileDirStr.size() + 1];
    strcpy( fileDir, fileDirStr.c_str() );

    TFile *file1 = TFile::Open(fileDir);
    TTree *TestTree = (TTree*)file1->Get("dataset_off_shell_testOnFullSim/TestTree");
    TTree *TrainTree = (TTree*)file1->Get("dataset_off_shell_testOnFullSim/TrainTree");

    gStyle->SetOptStat(0);

    TH1 *hbgtrain;
    TH1 *hbgtest;
    TH1 *hsignaltest;

    TCanvas *c = new TCanvas("c", "bdt", 200, 10, 600, 400);
    TrainTree->Draw("BDT>>hbgtrain", "(classID==1)*w","p");
    hbgtrain = (TH1*)gPad->GetPrimitive("hbgtrain");
    Double_t bgEntries = hbgtrain->GetEntries();

    TestTree->Draw("BDT>>hbgtest", "(classID==1)*w","hist same");
    hbgtest = (TH1*)gPad->GetPrimitive("hbgtest");
    cout << "test background entries: " << hbgtest->GetEntries() << std::endl;
    cout << "test background scaled: " << hbgtest->Integral() << std::endl;

    TestTree->Draw("BDT>>hsignaltest", "(classID==0)*w", "hist same");
    hsignaltest = (TH1*)gPad->GetPrimitive("hsignaltest");
    cout << "test signal entries: " << hsignaltest->GetEntries() << std::endl;
    cout << "test signal scaled: " << hsignaltest->Integral() << std::endl;

    if (c) { c->Close(); gSystem->ProcessEvents(); }

    hbgtrain->GetYaxis()->SetRangeUser(1,hbgtrain->GetMaximum() * 50);
    hbgtrain->SetTitle( "" );
    hbgtrain->SetMarkerColor( kRed );
    hbgtrain->SetMarkerStyle( 8 );
    hbgtrain->SetMarkerSize( 0.8 );
    hbgtest->SetLineColor(  kRed );
    hbgtest->SetFillStyle(  3354 );
    hbgtest->SetFillColor(  kRed );
    hsignaltest->SetLineColor(  kBlue );
    hsignaltest->SetFillStyle(  3345 );
    hsignaltest->SetFillColor(  kBlue );
    hbgtrain->SetXTitle("BDT response");
    hbgtrain->SetYTitle("Events");

    TCanvas c1("c1", "", 200, 10, 800, 600);
    hbgtrain->Draw("hist p");
    hbgtest->Draw("hist same");
    hsignaltest->Draw("hist same");


    TLegend *Leg = new TLegend(0.3,0.73,0.9,0.88);
    Leg->AddEntry(hbgtrain, "Background (train sample)", "p");
    Leg->AddEntry(hbgtest, "Background (test sample)", "f");
  	Leg->AddEntry(hsignaltest, signalLegend, "f");

    Leg->Draw("same");

    c1.SetLogy();
    c1.SetTitle("");
    c1.Print( ("BDTResponse/BDTResponse_" + channel + "_testOnFullSim.pdf").c_str() );
}

void CalculateBackgroundEff(std::string shell_type = "BP21", std::string channel = "ll", Float_t cs = 1671.37, Float_t BDTCut = 0.0857) {

  double lumi = 4000.;

  string fileDirStr = "./outputRootFiles/my_mva_selection_test_" + shell_type + ".root";
  char fileDir[fileDirStr.size() + 1];
  strcpy( fileDir, fileDirStr.c_str() );

  std::string dataset;
  if(shell_type=="BP21")
    //dataset = "dataset_on_shellwithOverlay_cutsForFastSim";
    dataset = "dataset_off_shellwithOverlay_cutsForFastSim";
  else if(shell_type=="HP17")
    dataset = "dataset_off_shellwithOverlay_cutsForFastSim";
  else {cout << " * Provide correct name of directory in ROOT file ! *" << endl; return 0;}

  TFile *file1 = TFile::Open(fileDir);
  TTree *TestTree = (TTree*)file1->Get( (dataset+"/TestTree").c_str() );
  TTree *TrainTree = (TTree*)file1->Get( (dataset+"/TrainTree").c_str() );

  TString cutBeforeBDT = Form("(classID==1) && (crossSection > %f - 0.1 && crossSection < %f + 0.1)", cs, cs);
  TString cutAfterBDT = cutBeforeBDT + Form(" && BDT > %f", BDTCut);

  gStyle->SetOptStat(0);

  TH1 *hbgtrain;
  TH1 *hbgtest;

  TCanvas *c = new TCanvas("c", "bdt", 200, 10, 600, 400);

  // przed BDT

  TrainTree->Draw("BDT>>hbgtrain", cutBeforeBDT,"p");
  hbgtrain = (TH1*)gPad->GetPrimitive("hbgtrain");
  Double_t bgEntriesBeforeBDT = hbgtrain->GetEntries();
  //cout << "bg train entries before BDT: " << bgEntriesBeforeBDT << endl;

  TestTree->Draw("BDT>>hbgtest", cutBeforeBDT,"p");
  hbgtest = (TH1*)gPad->GetPrimitive("hbgtest");
  bgEntriesBeforeBDT += hbgtest->GetEntries();
  //cout << "all bg entries before BDT: " << bgEntriesBeforeBDT << std::endl;

  // po BDT

  TrainTree->Draw("BDT>>hbgtrain", cutAfterBDT,"p");
  hbgtrain = (TH1*)gPad->GetPrimitive("hbgtrain");
  Double_t bgEntriesAfterBDT = hbgtrain->GetEntries();
  //cout << "bg train entries after BDT: " << bgEntriesAfterBDT << endl;

  TestTree->Draw("BDT>>hbgtest", cutAfterBDT,"p");
  hbgtest = (TH1*)gPad->GetPrimitive("hbgtest");
  bgEntriesAfterBDT += hbgtest->GetEntries();
  //cout << "all bg entries after BDT: " << bgEntriesAfterBDT << std::endl;

  double allEntries = 1000000;
  if(channel == "qqlvlv" || channel == "qqlvvv" || channel == "qqqqlv")
    allEntries = 100000;

  double eff = bgEntriesAfterBDT/bgEntriesBeforeBDT;
  double ev_before = lumi * cs * bgEntriesBeforeBDT / allEntries;
  double ev_after = ev_before * eff;

  cout << channel << " " << ev_before << " " << ev_after << " " << eff << std::endl;

  if (c) {
    c->Close();
    gSystem->ProcessEvents();
    delete c;
    c = 0;
  }

}

void PrintAllBgEff() {

  cout << "ch.  ev. bef.  ev. aft.  eff." << endl;

  cout << "on-shell W:" << endl;

  CalculateBackgroundEff("BP21", "ll", 1671.37, 0.0857);
  CalculateBackgroundEff("BP21", "qq", 1231.27, 0.0857);
  CalculateBackgroundEff("BP21", "qqll", 3219.26, 0.0857);
  CalculateBackgroundEff("BP21", "qqlv", 8831.58, 0.0857);
  CalculateBackgroundEff("BP21", "qqlvlv", 63.1912, 0.0857);
  CalculateBackgroundEff("BP21", "qqlvvv", 70.7564, 0.0857);
  CalculateBackgroundEff("BP21", "qqqq", 916.758, 0.0857);
  CalculateBackgroundEff("BP21", "qqqqlv", 131.211, 0.0857);
  CalculateBackgroundEff("BP21", "qqvv", 2512.37, 0.0857);

  cout << endl;
  cout << "off-shell W:" << endl;

  CalculateBackgroundEff("HP17", "ll", 1671.37, 0.0908);
  CalculateBackgroundEff("HP17", "qq", 1231.27, 0.0908);
  CalculateBackgroundEff("HP17", "qqll", 3219.26, 0.0908);
  CalculateBackgroundEff("HP17", "qqlv", 8831.58, 0.0908);
  CalculateBackgroundEff("HP17", "qqlvlv", 63.1912, 0.0908);
  CalculateBackgroundEff("HP17", "qqlvvv", 70.7564, 0.0908);
  CalculateBackgroundEff("HP17", "qqqq", 916.758, 0.0908);
  CalculateBackgroundEff("HP17", "qqqqlv", 131.211, 0.0908);
  CalculateBackgroundEff("HP17", "qqvv", 2512.37, 0.0908);

}

void CalculateSignificance(std::string channel="BP21", Double_t signalEv = 9398., Double_t BDTCut = 0.12) {

  string fileDirStr = "./outputRootFiles/my_mva_selection_test_" + channel + ".root";
  char fileDir[fileDirStr.size() + 1];
  strcpy( fileDir, fileDirStr.c_str() );

  TFile *file1 = TFile::Open(fileDir);
  //TTree *TestTree = (TTree*)file1->Get("dataset/Method");
  //TTree *TrainTree = (TTree*)file1->Get("dataset/TrainTree");

  //gSystem->cd("dataset/Method_BDT/BDT");

  TH1F *effB = (TH1F*)file1->Get("dataset/Method_BDT/BDT/MVA_BDT_effB");
  double backgroundEff = effB->GetBinContent( effB->GetXaxis()->FindBin(BDTCut) );
  TH1F *effS = (TH1F*)file1->Get("dataset/Method_BDT/BDT/MVA_BDT_effS");
  double signalEff = effS->GetBinContent( effS->GetXaxis()->FindBin(BDTCut) );

  double expSignalEvAfter = signalEff*signalEv;
  double expBackgEvAfter = backgroundEff*622275;
  double significance = expSignalEvAfter / sqrt( expSignalEvAfter + expBackgEvAfter );

  cout << channel << " " << significance << " " << signalEff << endl;

}

void PrintAllSignificances() {

  cout << "BP.  sig.  eff." << endl;

  CalculateSignificance("BP18", 8961, 0.12);
  CalculateSignificance("HP2", 1118, 0.12);
  CalculateSignificance("HP3", 3395, 0.12);
  CalculateSignificance("HP5", 2705, 0.12);
  CalculateSignificance("HP6", 1505, 0.12);
  CalculateSignificance("HP7", 1438, 0.12);
  CalculateSignificance("HP8", 917, 0.12);
  CalculateSignificance("HP9", 1223, 0.12);
  CalculateSignificance("HP10", 366, 0.12);
  CalculateSignificance("HP11", 6811, 0.12);
  CalculateSignificance("HP12", 3956, 0.12);
  CalculateSignificance("HP13", 6374, 0.12);
  CalculateSignificance("HP14", 2650, 0.12);
  CalculateSignificance("HP15", 6071, 0.12);
  CalculateSignificance("HP16", 5672, 0.12);
  CalculateSignificance("HP17", 2196, 0.12);
  CalculateSignificance("HP18", 5236, 0.12);
  CalculateSignificance("HP19", 4681, 0.12);
  CalculateSignificance("HP20", 3210, 0.12);

  CalculateSignificance("BP21", 7037, 0.01);
  CalculateSignificance("BP23", 8952, 0.01);
  CalculateSignificance("HP1", 7283, 0.01);
  CalculateSignificance("HP4", 3264, 0.01);

}
