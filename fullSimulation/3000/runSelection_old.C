void runSelection() {

  gROOT->ProcessLine(".x treeAnalyser.C()");

  gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"rootSamples/signal/idm_HpHm_3000_BP21.root\")");
  gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
  gROOT->ProcessLine("tSig1.Loop(4.213);");

  gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"rootSamples/signal/idm_HpHm_3000_BP23.root\")");
  gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
  gROOT->ProcessLine("tSig2.Loop(5.767);");

  gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"rootSamples/signal/idm_HpHm_3000_HP17.root\")");
  gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
  gROOT->ProcessLine("tSig3.Loop(0.9218);");

  gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"rootSamples/signal/idm_HpHm_3000_HP20.root\")");
  gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
  gROOT->ProcessLine("tSig4.Loop(1.506);");

  gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"rootSamples/signal/idm_HpHm_3000_HP3.root\")");
  gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
  gROOT->ProcessLine("tSig5.Loop(1.775);");

  gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"rootSamples/background/idm_bg_3000_qqlv.root\")");
  gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
  gROOT->ProcessLine("tBg1.Loop(8672);");

  gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"rootSamples/background/idm_bg_3000_qqll.root\")");
  gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
  gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
  gROOT->ProcessLine("tBg2.Loop(3180);");

}
