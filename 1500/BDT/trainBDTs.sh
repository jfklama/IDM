#!/bin/bash

: << 'END'

    # no smear
# off shell
root -l -q my_mva_selection_test.C++'(
         "root_noSmear_moreVars/idm_hphm_slep_BP18_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP2_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP3_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP5_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP6_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP11_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP12_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP13_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP14_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP15_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP16_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP17_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP18_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP19_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP20_1500DataPreselected.root",
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
         "I",
         "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
         "noSmear_moreVars",
         "off")' #| awk '/^---        BDT:/ {print "HP13",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> HP13_results.txt

# on shell
root -l -q my_mva_selection_test.C++'(
          "root_noSmear_moreVars/idm_hphm_slep_BP21_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_BP23_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP1_1500DataPreselected.root root_noSmear_moreVars/idm_hphm_slep_HP4_1500DataPreselected.root",
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
			    "I",
			    "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
          "noSmear_moreVars",
          "on")' #| awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> outSig.txt


          # smear (1)

# off shell
root -l -q my_mva_selection_test.C++'(
                 "root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP18_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP2_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP3_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP5_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP6_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP12_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP13_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP14_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP15_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP16_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP17_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP18_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP19_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP20_1500DataPreselected.root",
         			   "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "w",
         			   6391.0,
         			   1078562.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "I",
         			   "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
                 "withSmear1_smearedEFlow_moreVars",
                 "off")'

#on shell
root -l -q my_mva_selection_test.C++'(
          "root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP21_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_BP23_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP1_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_hphm_slep_HP4_1500DataPreselected.root",
			    "root_withSmear1_smearedEFlow_moreVars/idm_bg_ll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqll_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_smearedEFlow_moreVars/idm_bg_qqvv_1500DataPreselected.root",
			    "HP4",
			    "",
				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
			    "w",
			    239.0,
			    1078562.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection_test",
			    "1000",
			    "I",
			    "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
          "withSmear1_smearedEFlow_moreVars",
          "on")' #| awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> outSig.txt



root -l -q my_mva_selection_test.C++'( "root_withSmear1_muonsOnly/idm_hphm_slep_BP18_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP2_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP3_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP5_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP6_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP12_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP13_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP14_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP15_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP16_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP17_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP18_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP19_1500DataPreselected.root root_withSmear1_muonsOnly/idm_hphm_slep_HP20_1500DataPreselected.root",
         			   "root_withSmear1_muonsOnly/idm_bg_ll_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qq_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqll_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqlv_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqlvlv_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqlvvv_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqqq_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqqqlv_1500DataPreselected.root root_withSmear1_muonsOnly/idm_bg_qqvv_1500DataPreselected.root",
         			   "HP13",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt MET missingMass",
         			   "w",
         			   3560.0,
         			   271041.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection_test",
         			   "1000",
         			   "I",
         			   "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
                 "withSmear1_muonsOnly",
                 "off")'

END

#     OVERLAY     #

                 # off shell
                 root -l -q my_mva_selection_test.C++'(
                                  "root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_BP18_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP2_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP3_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP5_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP6_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP11_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP12_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP13_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP14_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP15_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP16_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP17_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP18_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP19_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP20_1500DataPreselected.root",
                          			   "root_withOverlay_reweighted_alternativeMissingP4/idm_bg_ll_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qq_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqll_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlvlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlvvv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqqq_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqqqlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqvv_1500DataPreselected.root",
                          			   "HP17",
                          			   "",
                          				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
                          			   "Ievt crossSection sampleName w",
                          			   1992.0,
                          			   1381599.0,
                          			   "",
                          			   "",
                          			   "w",
                          			   "my_mva_selection_test",
                          			   "1000",
                          			   "P",
                          			   "UseNvars=6",
                                  "withOverlay_alternativeMissingP4",
                                  "off")'

                 #on shell
                 root -l -q my_mva_selection_test.C++'(
                           "root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_BP21_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_BP23_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP1_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_hphm_slep_HP4_1500DataPreselected.root",
                 			    "root_withOverlay_reweighted_alternativeMissingP4/idm_bg_ll_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qq_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqll_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlvlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqlvvv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqqq_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqqqlv_1500DataPreselected.root root_withOverlay_reweighted_alternativeMissingP4/idm_bg_qqvv_1500DataPreselected.root",
                 			    "BP21",
                 			    "",
                 				  "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
                 			    "Ievt crossSection sampleName w",
                 			    9639.0,
                 			    1381599.0,
                 			    "",
                 			    "",
                 			    "w",
                 			    "my_mva_selection_test",
                 			    "1000",
                 			    "P",
                 			    "UseNvars=6",
                           "withOverlay_alternativeMissingP4",
                           "on")' #| awk '/^---        BDT:/ {print "HP4",$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> outSig.txt
