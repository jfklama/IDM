#!/bin/bash

declare -a off_shell=("BP18" "HP2" "HP3" "HP5" "HP6" "HP7" "HP8" "HP9" "HP10" "HP11" "HP12"
                        "HP13" "HP14" "HP15" "HP16" "HP17" "HP18"
                        "HP19" "HP20"
                )

declare -a on_shell=("BP21" "BP23" "HP1" "HP4")

: << 'END'
echo "            NO CMS ANGLES           " >> outSig.txt


  #### NO SMEAR ####

echo "scen. (nsig,    nbg)        BDT_cut signif. sig_eff bg_eff" >> outSig.txt

echo "(noSmear)" >> outSig.txt

for i in "${off_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/noSmear/off_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done


for i in "${on_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/noSmear/on_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done

echo " " >> outSig.txt



 #### SMEAR ####

echo "scen. (nsig,    nbg)        BDT_cut signif. sig_eff bg_eff" >> outSig.txt

echo "(withSmear1_smearedEFlow, wages trained on non-smeared sample)" >> outSig.txt

for i in "${off_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/withSmear1_smearedEFlow/off_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done


for i in "${on_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/withSmear1_smearedEFlow/on_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done

echo " " >> outSig.txt

END

#### OVERLAY ####

echo "scen. (nsig,    nbg)        BDT_cut signif. sig_eff bg_eff" >> outSig.txt

echo "(with overlay, cuts for fast sim, missing P4 like in full sim, reweighted signal events CORRECTED, no pruning, PCA, no Mlv, corrected training)" >> outSig.txt

for i in "${off_shell[@]}"
do
 echo "Processing $i..."
 root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/withOverlay_alternativeMissingP4/off_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done


for i in "${on_shell[@]}"
do
 echo "Processing $i..."
 root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/withOverlay_alternativeMissingP4/on_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done

echo " " >> outSig.txt
