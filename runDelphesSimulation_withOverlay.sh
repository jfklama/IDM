#!/bin/bash

#declare -a backgrounds=(ll qqll qqlv qq qqlvlv qqlvvv qqqq qqqqlv qqvv)
declare -a backgrounds=(qq qqlvlv qqlvvv qqqq qqqqlv qqvv)

# 1.5 TeV

declare -a scenarios1500=(BP18 HP2 HP3 HP5 HP6 HP11 HP12
                HP13 HP14 HP15 HP16 HP17 HP18
                HP19 HP20 BP21 BP23 HP1 HP4
                )

#for i in ${backgrounds[@]}
#do
#  ./DelphesSTDHEP cards/delphes_card_CLICdet_Stage2_IDM_pileup_newCharged.tcl /media/jfklama/Nowy/moje/FUW/IDM/rootSamples_withOverlay/1500/idm_bg_${i}_1500_detResp.root /media/jfklama/Filip_USB3/CLIC/IDM_stdhep/1500/*_${i}_*.stdhep
#done

#for i in ${scenarios1500[@]}
#do
#  ./DelphesSTDHEP cards/delphes_card_CLICdet_Stage2_IDM_pileup_newCharged.tcl /media/jfklama/Nowy/moje/FUW/IDM/rootSamples_withOverlay/1500/idm_hphm_slep_${i}_1500_detResp.root /media/jfklama/Filip_USB3/CLIC/IDM_stdhep/1500/idm_hphm_slep_1500_${i}.0.stdhep
#done


# 3 TeV

declare -a scenarios=(BP18 HP2 HP3 HP5 HP6 HP7 HP8 HP9 HP10 HP11 HP12
                HP13 HP14 HP15 HP16 HP17 HP18
                HP19 HP20 BP21 BP23 HP1 HP4
                )

for i in ${backgrounds[@]}
do
  ./DelphesSTDHEP cards/delphes_card_CLICdet_Stage3_IDM_pileup_newCharged.tcl /media/jfklama/Filip_USB3/CLIC/3TeV/rootSamples_withOverlay/idm_bg_${i}_3000_detResp.root /media/jfklama/Filip_USB3/CLIC/IDM_stdhep/3000/*_${i}_*.stdhep
done

for i in ${scenarios[@]}
do
  ./DelphesSTDHEP cards/delphes_card_CLICdet_Stage3_IDM_pileup_newCharged.tcl /media/jfklama/Filip_USB3/CLIC/3TeV/rootSamples_withOverlay/idm_hphm_slep_${i}_3000_detResp.root /media/jfklama/Filip_USB3/CLIC/IDM_stdhep/3000/idm_hphm_slep_3000_${i}.0.stdhep
done
