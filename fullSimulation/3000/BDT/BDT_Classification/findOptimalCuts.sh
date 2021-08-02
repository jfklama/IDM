#!/bin/bash

declare -a off_shell=("HP3" "HP17" "HP20")
declare -a on_shell=("BP21" "BP23")


echo "scen. (nsig,    nbg)        BDT_cut signif. sig_eff bg_eff" >> outSig.txt

echo "(PCA, no pruning, cuts for full sim, reweighted sig samples, signal weights = meanCS*lumi/nentries, all backgrounds)" >> outSig.txt

for i in "${off_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/_allBackrounds_withCuts/off_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done


for i in "${on_shell[@]}"
do
  echo "Processing $i..."
  root -l -q 'cut_optimisation.C("'${i}'", "./BDT_Classified/_allBackrounds_withCuts/on_shell")' | awk '/^BDT/ {print $2, $3, $4, $5, $6, $7, $8}' >> outSig.txt
done

echo " " >> outSig.txt
