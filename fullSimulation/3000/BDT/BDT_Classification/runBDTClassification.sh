#!/bin/bash

declare -a offshell=(HP3 HP17 HP20)
declare -a onshell=(BP21 BP23)


offShell=$(g++ -o classify_bdt_offShell -I  `root-config --incdir` classify_bdt_offShell.cc `root-config --libs`)
echo $offShell

for i in ${offshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_offShell root_files.list $i
done


onShell=$(g++ -o classify_bdt_onShell -I  `root-config --incdir` classify_bdt_onShell.cc `root-config --libs`)
echo $onShell

for i in ${onshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_onShell root_files.list $i
done
