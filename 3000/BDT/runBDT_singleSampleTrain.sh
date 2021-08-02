#!/bin/bash

: << 'END'

          echo 'channel (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg (no smear)' >> singleSampleTrainResults.txt


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_BP18_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "BP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   9514.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                                  "noSmear")' | awk '/^---        BDT:/ {print "BP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> HP13_results.txt
# done

# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP2_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP2",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1125.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP2",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP3_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3462.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP5_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP5",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2707.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP5",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP6_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP6",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1507.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP6",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP7_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP7",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1442.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP7",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP8_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP8",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   918.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP8",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP9_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP9",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1226.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP9",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP10_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP10",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   367.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP10",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP11_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP11",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6974.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP11",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP12_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP12",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4074.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP12",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP13_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6418.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP13",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP14_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP14",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2737.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP14",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP15_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP15",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6181.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP15",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP16_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP16",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5699.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP16",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP17_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2201.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP18_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5273.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP19_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP19",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4693.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP19",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP20_3000DataPreselected.root",
         			   "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3235.0,
         			   743701.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_BP21_3000DataPreselected.root",
			    "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8036.0,
			    743701.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_BP23_3000DataPreselected.root",
			    "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    10285.0,
			    743701.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP1_3000DataPreselected.root",
			    "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
			    "HP1",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8019.0,
			    743701.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP1",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_noSmear/idm_hphm_slep_HP4_3000DataPreselected.root",
			    "root_noSmear/idm_bg_ll_3000DataPreselected.root root_noSmear/idm_bg_qq_3000DataPreselected.root root_noSmear/idm_bg_qqll_3000DataPreselected.root root_noSmear/idm_bg_qqlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvlv_3000DataPreselected.root root_noSmear/idm_bg_qqlvvv_3000DataPreselected.root root_noSmear/idm_bg_qqqq_3000DataPreselected.root root_noSmear/idm_bg_qqqqlv_3000DataPreselected.root root_noSmear/idm_bg_qqvv_3000DataPreselected.root",
			    "HP4",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    3373.0,
			    743701.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
                 "noSmear")' | awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done



END

            #### WITH SMEAR ####

          echo 'channel (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg (with smear, smeared EFlow, trained on single sample, all vars, PCA, no pruning, split signal for training, no Mlv)' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP3_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   3449.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP17_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   2198.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP20_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   3235.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_BP21_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
			    "w",
			    8025.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt

  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_BP23_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
			    "w",
			    10265.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt


: << 'END'


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_BP18_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "BP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   9500.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "withSmear1_corrCS")' | awk '/^---        BDT:/ {print "BP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP2_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP2",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1125.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP2",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP3_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP3",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3449.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP3",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP5_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP5",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2707.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP5",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP6_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP6",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1507.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP6",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP7_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP7",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1443.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP7",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP8_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP8",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   918.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP8",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP9_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP9",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   1226.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP9",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP10_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP10",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   368.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP10",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP11_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP11",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6963.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP11",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP12_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP12",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4073.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP12",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP13_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6416.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP13",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP14_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP14",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2733.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP14",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP15_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP15",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6182.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP15",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP16_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP16",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5696.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP16",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP17_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   2198.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP17",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP18_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP18",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   5271.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP18",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP19_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP19",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   4690.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP19",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP20_3000DataPreselected.root",
         			   "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   3235.0,
         			   721656.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP20",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_BP21_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8025.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "BP21",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_BP23_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "BP23",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    10265.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "BP23",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP1_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "HP1",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    8008.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP1",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done


# for i in `seq 5`;
# do
  root -l -q my_mva_selection_test.C++'("root_withSmear1_corrCS/idm_hphm_slep_HP4_3000DataPreselected.root",
			    "root_withSmear1_corrCS/idm_bg_ll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqll_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqlvvv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqq_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqqqlv_3000DataPreselected.root root_withSmear1_corrCS/idm_bg_qqvv_3000DataPreselected.root",
			    "HP4",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    3371.0,
			    721656.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "P",
			     "UseNvars=6",
"withSmear1_corrCS")' | awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> singleSampleTrainResults.txt
# done

END
