#!/bin/bash

: << 'END'

root -l -q my_mva_selection_ss.C++'("inputs/R09_fastSimCuts/HP17_DataPreselected.root",
         			   "inputs/R09_fastSimCuts/qqll_DataPreselected.root inputs/R09_fastSimCuts/qqlv_DataPreselected.root inputs/R09_fastSimCuts/ll_DataPreselected.root inputs/R09_fastSimCuts/qqqq_DataPreselected.root inputs/R09_fastSimCuts/qqvv_DataPreselected.root inputs/R09_fastSimCuts/qqlvlv_DataPreselected.root inputs/R09_fastSimCuts/qqlvvv_DataPreselected.root inputs/R09_fastSimCuts/qqqqlv_DataPreselected.root inputs/R09_fastSimCuts/qq_DataPreselected.root",
         			   "HP17",
         			   "",
         				 "jetsM_inv jetsTheta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E",
         			   "w",
         			   1605.0,
         			   1663980.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "P",
         			   "UseNvars=6")' # >> singleSampleOutput_HP17.log

END

root -l -q my_mva_selection_ss.C++'("inputs/R09_fastSimCuts/HP20_DataPreselected.root",
         			   "inputs/R09_fastSimCuts/qqll_DataPreselected.root inputs/R09_fastSimCuts/qqlv_DataPreselected.root inputs/R09_fastSimCuts/ll_DataPreselected.root inputs/R09_fastSimCuts/qqqq_DataPreselected.root inputs/R09_fastSimCuts/qqvv_DataPreselected.root inputs/R09_fastSimCuts/qqlvlv_DataPreselected.root inputs/R09_fastSimCuts/qqlvvv_DataPreselected.root inputs/R09_fastSimCuts/qqqqlv_DataPreselected.root inputs/R09_fastSimCuts/qq_DataPreselected.root",
         			   "HP20",
         			   "",
         				 "jetsM_inv M_inv_Wlep jetsEnergy jetsTheta jet1Theta jet2Theta jet1Pt jet2Pt jet1E jet2E leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass",
         			   "w",
         			   1500.0,
         			   1663980.0,
         			   "",
         			   "",
         			   "w",
         			   "my_mva_selection",
         			   "1000",
         			   "P",
         			   "UseNvars=6")' >> singleSampleOutput_HP20.log
