void runSelection(double Emin = 0.) {

  if (Emin == 0) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/signal/idm_HpHm_1500_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(8.093, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/signal/idm_HpHm_1500_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(12.497, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/signal/idm_HpHm_1500_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(2.430, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/signal/idm_HpHm_1500_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.323, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/signal/idm_HpHm_1500_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(0.6294, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(7001, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(2715, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1406, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg4(qqqq_tree);");
    gROOT->ProcessLine("tBg4.Loop(1943.2, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file10 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqlvlv.root\")");
    gROOT->ProcessLine("TTree *qqlvlv_tree = (TTree*)_file10->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg5(qqlvlv_tree);");
    gROOT->ProcessLine("tBg5.Loop(14.9, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file11 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqqqlv.root\")");
    gROOT->ProcessLine("TTree *qqqqlv_tree = (TTree*)_file11->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg6(qqqqlv_tree);");
    gROOT->ProcessLine("tBg6.Loop(169, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file12 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqlvvv.root\")");
    gROOT->ProcessLine("TTree *qqlvvv_tree = (TTree*)_file12->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg7(qqlvvv_tree);");
    gROOT->ProcessLine("tBg7.Loop(66.8, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file13 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qqvv.root\")");
    gROOT->ProcessLine("TTree *qqvv_tree = (TTree*)_file13->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg8(qqvv_tree);");
    gROOT->ProcessLine("tBg8.Loop(1460, \"0.9\", 0);");

    gROOT->ProcessLine("TFile *_file14 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/1500/rootSamples/background/idm_bg_1500_qq.root\")");
    gROOT->ProcessLine("TTree *qq_tree = (TTree*)_file14->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg9(qq_tree);");
    gROOT->ProcessLine("tBg9.Loop(2863, \"0.9\", 0);");

  }

  else if (Emin == 0.5) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R10/Emin05/idm_HpHm_1500_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(8.093, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R10/Emin05/idm_HpHm_1500_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(12.497, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R10/Emin05/idm_HpHm_1500_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(2.430, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R10/Emin05/idm_HpHm_1500_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.323, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R10/Emin05/idm_HpHm_1500_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(0.6294, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R10/Emin05/idm_bg_1500_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(7001, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R10/Emin05/idm_bg_1500_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(2715, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R10/Emin05/idm_bg_1500_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1406, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R10/Emin05/idm_bg_1500_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(qqqq_tree);");
    gROOT->ProcessLine("tBg3.Loop(1943.2, \"1.0\", 1);");

  }

  else if (Emin == 1.5) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R06/Emin1.5/idm_HpHm_1500_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(8.093, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R06/Emin1.5/idm_HpHm_1500_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(12.497, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R06/Emin1.5/idm_HpHm_1500_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(2.430, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R06/Emin1.5/idm_HpHm_1500_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.323, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R06/Emin1.5/idm_HpHm_1500_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(0.6294, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R06/Emin1.5/idm_bg_1500_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(7001, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R06/Emin1.5/idm_bg_1500_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(2715, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R06/Emin1.5/idm_bg_1500_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1406, \"0.6\", 1);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R06/Emin1.5/idm_bg_1500_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(qqqq_tree);");
    gROOT->ProcessLine("tBg3.Loop(1943.2, \"0.6\", 1);");

  }

  else if (Emin == 2.) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R07/Emin2/idm_HpHm_1500_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(8.093, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R07/Emin2/idm_HpHm_1500_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(12.497, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R07/Emin2/idm_HpHm_1500_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(2.430, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R07/Emin2/idm_HpHm_1500_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.323, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/R07/Emin2/idm_HpHm_1500_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(0.6294, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R07/Emin2/idm_bg_1500_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(7001, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R07/Emin2/idm_bg_1500_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(2715, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R07/Emin2/idm_bg_1500_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1406, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/R07/Emin2/idm_bg_1500_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(qqqq_tree);");
    gROOT->ProcessLine("tBg3.Loop(1943.2, \"0.7\", 1);");

  }

  else if (Emin == 5.) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/Emin5/idm_HpHm_1500_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(8.093, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/Emin5/idm_HpHm_1500_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(12.497, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/Emin5/idm_HpHm_1500_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(2.430, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/Emin5/idm_HpHm_1500_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.323, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/signal/myjets/Emin5/idm_HpHm_1500_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(0.6294, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/Emin5/idm_bg_1500_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(7001, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/Emin5/idm_bg_1500_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(2715, \"0.7\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Nowy/moje/CLIC/fullSimulation/1500/rootSamples/background/myjets/Emin5/idm_bg_1500_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1406, \"0.7\", 1);");

  }

  else
    cout << "Wrong E_min given! Provide E_min = 0, 2, 5" << endl;

}
