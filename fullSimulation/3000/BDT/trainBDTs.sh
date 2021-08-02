#!/bin/bash

root -l -q my_mva_selection_ss.C++'("inputs/R12_allBackgrounds_fastSimCuts/HP17_DataPreselected.root",
         			   "inputs/R12_allBackgrounds_fastSimCuts/qqll_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqlv_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/ll_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqqq_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqvv_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqlvlv_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqlvvv_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qqqqlv_DataPreselected.root inputs/R12_allBackgrounds_fastSimCuts/qq_DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "Ievt crossSection sampleName w",
         			   2015.0,
         			   1352347.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "P",
         			   "UseNvars=6")' #>> singleSampleOutput_HP17.log

: << 'END'

root -l -q my_mva_selection.C++'("inputs/R12_reweighted/HP3_DataPreselected.root inputs/R12_reweighted/HP17_DataPreselected.root inputs/R12_reweighted/HP20_DataPreselected.root ",
         			   "inputs/R12_reweighted/qqll_DataPreselected.root inputs/R12_reweighted/qqlv_DataPreselected.root inputs/R12_reweighted/ll_DataPreselected.root inputs/R12_reweighted/qqqq_DataPreselected.root inputs/R12_reweighted/qqvv_DataPreselected.root inputs/R12_reweighted/qqlvlv_DataPreselected.root inputs/R12_reweighted/qqlvvv_DataPreselected.root inputs/R12_reweighted/qqqqlv_DataPreselected.root inputs/R12_reweighted/qq_DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "Ievt crossSection sampleName w",
         			   2642.0,
         			   1352621.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "",
                 "off")'

root -l -q my_mva_selection.C++'("inputs/R12_reweighted/BP21_DataPreselected.root inputs/R12_reweighted/BP23_DataPreselected.root",
         			   "inputs/R12_reweighted/qqll_DataPreselected.root inputs/R12_reweighted/qqlv_DataPreselected.root inputs/R12_reweighted/ll_DataPreselected.root inputs/R12_reweighted/qqqq_DataPreselected.root inputs/R12_reweighted/qqvv_DataPreselected.root inputs/R12_reweighted/qqlvlv_DataPreselected.root inputs/R12_reweighted/qqlvvv_DataPreselected.root inputs/R12_reweighted/qqqqlv_DataPreselected.root inputs/R12_reweighted/qq_DataPreselected.root",
         			   "BP21",
         			   "",
         				 "jetsM_inv jetsEnergy jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E M_inv_Wlep",
         			   "Ievt crossSection sampleName w",
         			   6459.0,
         			   1352621.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "P",
         			   "UseNvars=6",
                 "",
                 "on")'



root -l -q my_mva_selection.C++'(
                 "inputs/R12/HP3_DataPreselected.root inputs/R12/HP17_DataPreselected.root inputs/R12/HP20_DataPreselected.root",
         			   "inputs/R12/qqll_DataPreselected.root inputs/R12/qqlv_DataPreselected.root inputs/R12/qqlvlv_DataPreselected.root inputs/R12/qqlvvv_DataPreselected.root inputs/R12/qqqq_DataPreselected.root inputs/R12/qqqqlv_DataPreselected.root inputs/R12/qqvv_DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv M_inv_Wlep jetsEnergy jetsTheta jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass",
         			   "Ievt crossSection sampleName w",
         			   2644.0,
         			   1232942.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "G+D",
         			   "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
                 "",
                 "off")'



#on shell
root -l -q my_mva_selection.C++'(
          "inputs/R12/BP21_DataPreselected.root inputs/R12/BP23_DataPreselected.root",
			    "inputs/R12/ll_DataPreselected.root inputs/R12/qqll_DataPreselected.root inputs/R12/qqlv_DataPreselected.root inputs/R12/qqlvlv_DataPreselected.root inputs/R12/qqlvvv_DataPreselected.root inputs/R12/qqqq_DataPreselected.root inputs/R12/qqqqlv_DataPreselected.root inputs/R12/qqvv_DataPreselected.root",
			    "BP21",
			    "",
				  "jetsM_inv M_inv_Wlep jetsEnergy jetsTheta jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass",
			    "Ievt crossSection sampleName w",
			    6461.0,
			    1352621.0,
			    "",
			    "",
			    "w",
			    "my_mva_selection",
			    "1000",
			    "G+D",
			    "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1",
          "",
          "on")'
END
