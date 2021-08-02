#include "/home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/Analysis.C"
#include "/home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/drawHistos.C"

void runHugeSampleAnalysis1500(Bool_t withOverlay = 1) {

  //Background
  //gROOT->ProcessLine(".L /home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/Analysis.C");
  Analysis("idm_bg_ll_1500","RECREATE", 1396.18, withOverlay);
  Analysis("idm_bg_qq_1500","UPDATE", 2873.4, withOverlay);
  Analysis("idm_bg_qqll_1500","UPDATE", 2739.2, withOverlay);
  Analysis("idm_bg_qqlv_1500","UPDATE", 7054.67, withOverlay);
  Analysis("idm_bg_qqlvlv_1500","UPDATE", 56.912, withOverlay);
  Analysis("idm_bg_qqlvvv_1500","UPDATE", 40.1477, withOverlay);
  Analysis("idm_bg_qqqq_1500","UPDATE", 1970.68, withOverlay);
  Analysis("idm_bg_qqqqlv_1500","UPDATE", 177.428, withOverlay);
  Analysis("idm_bg_qqvv_1500","UPDATE", 1520.1, withOverlay);

  //Signal
  Analysis("idm_hphm_slep_BP18_1500","UPDATE", 11.903, withOverlay);
  Analysis("idm_hphm_slep_BP21_1500","UPDATE", 8.192, withOverlay);
  Analysis("idm_hphm_slep_BP23_1500","UPDATE", 12.602, withOverlay);
  Analysis("idm_hphm_slep_HP1_1500","UPDATE", 7.5919, withOverlay);
  Analysis("idm_hphm_slep_HP2_1500","UPDATE", 1.49793, withOverlay);
  Analysis("idm_hphm_slep_HP3_1500","UPDATE", 0.63347, withOverlay);
  Analysis("idm_hphm_slep_HP4_1500","UPDATE", 0.22964, withOverlay);
  Analysis("idm_hphm_slep_HP5_1500","UPDATE", 0.19814, withOverlay);
  Analysis("idm_hphm_slep_HP6_1500","UPDATE", 0.037207, withOverlay);
  Analysis("idm_hphm_slep_HP11_1500","UPDATE", 7.22539, withOverlay);
  Analysis("idm_hphm_slep_HP12_1500","UPDATE", 3.775, withOverlay);
  Analysis("idm_hphm_slep_HP13_1500","UPDATE", 5.74048, withOverlay);
  Analysis("idm_hphm_slep_HP14_1500","UPDATE", 2.236, withOverlay);
  Analysis("idm_hphm_slep_HP15_1500","UPDATE", 4.7676, withOverlay);
  Analysis("idm_hphm_slep_HP16_1500","UPDATE", 4.34368, withOverlay);
  Analysis("idm_hphm_slep_HP17_1500","UPDATE", 2.44644, withOverlay);
  Analysis("idm_hphm_slep_HP18_1500","UPDATE", 3.3074, withOverlay);
  Analysis("idm_hphm_slep_HP19_1500","UPDATE", 2.5918, withOverlay);
  Analysis("idm_hphm_slep_HP20_1500","UPDATE", 1.3261, withOverlay);

  //gROOT->ProcessLine(".L /home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/drawHistosHuge.C");
  //drawSignalVsBackground();

  //drawHistos( 4.7676, "hphm_slep_HP15" );

  //gROOT->ProcessLine(".x /home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/drawHistos.C( 11.903 )");


}
