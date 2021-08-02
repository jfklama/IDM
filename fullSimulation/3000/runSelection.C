void runSelection(double Emin = 0.) {

  if (Emin == 0) {

    gROOT->ProcessLine(".L treeAnalyser.C");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/idm_HpHm_3000_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(4.213, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/idm_HpHm_3000_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(5.767, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/idm_HpHm_3000_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(1.678, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/idm_HpHm_3000_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.506, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/idm_HpHm_3000_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(1.775, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(8672, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(3180, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1664.9796, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg4(qqqq_tree);");
    gROOT->ProcessLine("tBg4.Loop(902, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file10 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqlvlv.root\")");
    gROOT->ProcessLine("TTree *qqlvlv_tree = (TTree*)_file10->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg5(qqlvlv_tree);");
    gROOT->ProcessLine("tBg5.Loop(20.4, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file11 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqqqlv.root\")");
    gROOT->ProcessLine("TTree *qqqqlv_tree = (TTree*)_file11->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg6(qqqqlv_tree);");
    gROOT->ProcessLine("tBg6.Loop(148, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file12 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqlvvv.root\")");
    gROOT->ProcessLine("TTree *qqlvvv_tree = (TTree*)_file12->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg7(qqlvvv_tree);");
    gROOT->ProcessLine("tBg7.Loop(96.8, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file13 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qqvv.root\")");
    gROOT->ProcessLine("TTree *qqvv_tree = (TTree*)_file13->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg8(qqvv_tree);");
    gROOT->ProcessLine("tBg8.Loop(2333.5039, \"1.2\", 0);");

    gROOT->ProcessLine("TFile *_file14 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/idm_bg_3000_qq.root\")");
    gROOT->ProcessLine("TTree *qq_tree = (TTree*)_file14->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg9(qq_tree);");
    gROOT->ProcessLine("tBg9.Loop(1269, \"1.2\", 0);");

  }

  else if (Emin == 2.) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R12/Emin2/idm_HpHm_3000_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(4.213, \"1.2\", 1);");
    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R12/Emin2/idm_HpHm_3000_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(5.767, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R12/Emin2/idm_HpHm_3000_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(1.678, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R12/Emin2/idm_HpHm_3000_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.506, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R12/Emin2/idm_HpHm_3000_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(1.775, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R12/Emin2/idm_bg_3000_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(8672, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R12/Emin2/idm_bg_3000_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(3180, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R12/Emin2/idm_bg_3000_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1664.9796, \"1.2\", 1);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R12/Emin2/idm_bg_3000_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg4(qqqq_tree);");
    gROOT->ProcessLine("tBg4.Loop(902, \"1.2\", 1);");


  }

  else if (Emin == 5.) {

    gROOT->ProcessLine(".x treeAnalyser.C()");

    gROOT->ProcessLine("TFile *_file1 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R10/Emin5/idm_HpHm_3000_BP21.root\")");
    gROOT->ProcessLine("TTree *BP21_tree = (TTree*)_file1->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig1(BP21_tree);");
    gROOT->ProcessLine("tSig1.Loop(4.213, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file2 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R10/Emin5/idm_HpHm_3000_BP23.root\")");
    gROOT->ProcessLine("TTree *BP23_tree = (TTree*)_file2->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig2(BP23_tree);");
    gROOT->ProcessLine("tSig2.Loop(5.767, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file3 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R10/Emin5/idm_HpHm_3000_HP17.root\")");
    gROOT->ProcessLine("TTree *HP17_tree = (TTree*)_file3->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig3(HP17_tree);");
    gROOT->ProcessLine("tSig3.Loop(1.678, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file4 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R10/Emin5/idm_HpHm_3000_HP20.root\")");
    gROOT->ProcessLine("TTree *HP20_tree = (TTree*)_file4->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig4(HP20_tree);");
    gROOT->ProcessLine("tSig4.Loop(1.506, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file5 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000//media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/signal/myjets/R10/Emin5/idm_HpHm_3000_HP3.root\")");
    gROOT->ProcessLine("TTree *HP3_tree = (TTree*)_file5->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tSig5(HP3_tree);");
    gROOT->ProcessLine("tSig5.Loop(1.775, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file6 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R10/Emin5/idm_bg_3000_qqlv.root\")");
    gROOT->ProcessLine("TTree *qqlv_tree = (TTree*)_file6->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg1(qqlv_tree);");
    gROOT->ProcessLine("tBg1.Loop(8672, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file7 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R10/Emin5/idm_bg_3000_qqll.root\")");
    gROOT->ProcessLine("TTree *qqll_tree = (TTree*)_file7->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg2(qqll_tree);");
    gROOT->ProcessLine("tBg2.Loop(3180, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file8 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R10/Emin5/idm_bg_3000_ll.root\")");
    gROOT->ProcessLine("TTree *ll_tree = (TTree*)_file8->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg3(ll_tree);");
    gROOT->ProcessLine("tBg3.Loop(1664.9796, \"1.0\", 1);");

    gROOT->ProcessLine("TFile *_file9 = TFile::Open(\"/media/jfklama/Filip_USB3/CLIC/fullSimulation/3000/rootSamples/background/myjets/R10/Emin5/idm_bg_3000_qqqq.root\")");
    gROOT->ProcessLine("TTree *qqqq_tree = (TTree*)_file9->Get(\"rawTree\")");
    gROOT->ProcessLine("treeAnalyser tBg4(qqqq_tree);");
    gROOT->ProcessLine("tBg4.Loop(902, \"1.0\", 1);");

  }

  else
    cout << "Wrong E_min given! Provide E_min = 0, 2, 5" << endl;

}
