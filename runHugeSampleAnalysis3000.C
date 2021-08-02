#include "/home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/Analysis.C"
#include "/home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/drawHistos.C"

void runHugeSampleAnalysis(Bool_t withOverlay = 1) {

  //Background
  //gROOT->ProcessLine(".L /home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/Analysis.C");
  Analysis("idm_bg_ll_3000","RECREATE", 1671.37, withOverlay);
  Analysis("idm_bg_qq_3000","UPDATE", 1231.27, withOverlay);
  Analysis("idm_bg_qqll_3000","UPDATE", 3219.26, withOverlay);
  Analysis("idm_bg_qqlv_3000","UPDATE", 8831.58, withOverlay);
  Analysis("idm_bg_qqlvlv_3000","UPDATE", 63.1912, withOverlay);
  Analysis("idm_bg_qqlvvv_3000","UPDATE", 70.7564, withOverlay);
  Analysis("idm_bg_qqqq_3000","UPDATE", 916.758, withOverlay);
  Analysis("idm_bg_qqqqlv_3000","UPDATE", 131.211, withOverlay);
  Analysis("idm_bg_qqvv_3000","UPDATE", 2512.37, withOverlay);

  //Signal
  Analysis("idm_hphm_slep_BP18_3000","UPDATE", 5.19980, withOverlay);
  Analysis("idm_hphm_slep_BP21_3000","UPDATE", 4.26603, withOverlay);
  Analysis("idm_hphm_slep_BP23_3000","UPDATE", 5.67891, withOverlay);
  Analysis("idm_hphm_slep_HP1_3000","UPDATE", 4.00834, withOverlay);
  Analysis("idm_hphm_slep_HP2_3000","UPDATE", 0.79231, withOverlay);
  Analysis("idm_hphm_slep_HP3_3000","UPDATE", 1.72873, withOverlay);
  Analysis("idm_hphm_slep_HP4_3000","UPDATE", 1.59043, withOverlay);
  Analysis("idm_hphm_slep_HP5_3000","UPDATE", 1.43190, withOverlay);
  Analysis("idm_hphm_slep_HP6_3000","UPDATE", 1.07247, withOverlay);
  Analysis("idm_hphm_slep_HP7_3000","UPDATE", 1.00985, withOverlay);
  Analysis("idm_hphm_slep_HP8_3000","UPDATE", 0.69329, withOverlay);
  Analysis("idm_hphm_slep_HP9_3000","UPDATE", 0.607349, withOverlay);
  Analysis("idm_hphm_slep_HP10_3000","UPDATE", 0.43212, withOverlay);
  Analysis("idm_hphm_slep_HP11_3000","UPDATE", 3.51379, withOverlay);
  Analysis("idm_hphm_slep_HP12_3000","UPDATE", 2.09034, withOverlay);
  Analysis("idm_hphm_slep_HP13_3000","UPDATE", 3.15121, withOverlay);
  Analysis("idm_hphm_slep_HP14_3000","UPDATE", 1.40070, withOverlay);
  Analysis("idm_hphm_slep_HP15_3000","UPDATE", 2.99062, withOverlay);
  Analysis("idm_hphm_slep_HP16_3000","UPDATE", 2.74101, withOverlay);
  Analysis("idm_hphm_slep_HP17_3000","UPDATE", 1.42266, withOverlay);
  Analysis("idm_hphm_slep_HP18_3000","UPDATE", 2.48253, withOverlay);
  Analysis("idm_hphm_slep_HP19_3000","UPDATE", 2.27993, withOverlay);
  Analysis("idm_hphm_slep_HP20_3000","UPDATE", 1.54028, withOverlay);

  //gROOT->ProcessLine(".L /home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/drawHistosHuge.C");
  //drawSignalVsBackground();

  //gROOT->ProcessLine(".x /home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/drawHistos.C( 4.88591 )");

  //drawHistos( 2.99062, "hphm_slep_HP15" );

}
