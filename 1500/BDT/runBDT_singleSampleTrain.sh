#!/bin/bash


echo 'channel (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg (no smear, smeared EFlow, trained on single sample, more vars, no jet angles)' >> singleSampleTrainResults.txt

: << 'END'
#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_BP18_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "BP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   13315.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "BP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP2_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP2",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   613.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP2",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP3_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   673.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP5_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP5",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   177.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP5",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP6_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP6",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   15.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP6",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP11_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP11",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   8311.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP11",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP12_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP12",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4317.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP12",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP13_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6391.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP13",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP14_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP14",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2533.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP14",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt



#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP15_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP15",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5457.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP15",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP16_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP16",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4808.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP16",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP17_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1577.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP18_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3698.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP19_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP19",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2767.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP19",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP20_1500DataPreselected.root",
         			   "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1484.0,
         			   1074253.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_BP21_1500DataPreselected.root",
			    "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    9407.0,
			    1074253.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "noSmear_moreVars")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_BP23_1500DataPreselected.root",
			    "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    14584.0,
			    1074253.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "noSmear_moreVars")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP1_1500DataPreselected.root",
			    "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "HP1",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8869.0,
			    1074253.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP1",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_noSmear_moreVars/idm_hphm_slep_HP4_1500DataPreselected.root",
			    "root_noSmear_moreVars/idm_bg_ll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqll_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqq_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_noSmear_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "HP4",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    239.0,
			    1074253.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "noSmear_moreVars")' | awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt

END
          #### WITH SMEAR ####

echo 'channel (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg (with smear, smeared EFlow, trained on single sample, all vars, PCA, no pruning, split signal for training, no Mlv)' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP3_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   673.0,
         			   1078562.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP17_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   1577.0,
         			   1078562.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP20_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   1484.0,
         			   1078562.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP21_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
			    "w",
			    9400.0,
			    1078562.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP23_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
			    "w",
			    14579.0,
			    1078562.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

: << 'END'

#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP18_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "BP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   13315.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "BP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP2_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP2",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   613.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP2",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP3_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   673.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP5_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP5",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   177.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP5",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP6_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP6",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   15.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP6",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP11_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP11",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   8311.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP11",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP12_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP12",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4317.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP12",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP13_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6391.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP13",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP14_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP14",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2533.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP14",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP15_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP15",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5457.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP15",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP16_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP16",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4808.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP16",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP17_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1577.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP18_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3698.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP19_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP19",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2767.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP19",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP20_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1484.0,
         			   1077400.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP21_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    9400.0,
			    1077400.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP23_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    14579.0,
			    1077400.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP1_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "HP1",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8869.0,
			    1077400.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP1",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt


#for i in `seq 5`;
#do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP4_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "HP4",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    239.0,
			    1077400.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			    "UseNvars=6",
          "withSmear1_smearedEFlow_moreVars")' | awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
#done

#echo ' ' >> singleSampleTrainResults.txt

END
