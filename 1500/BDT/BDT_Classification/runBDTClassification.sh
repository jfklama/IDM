#!/bin/bash

declare -a offshell=(BP18 HP2 HP3 HP5 HP6 HP11 HP12
                HP13 HP14 HP15 HP16 HP17 HP18
                HP19 HP20
                )
declare -a onshell=(BP21 BP23 HP1 HP4)

: << 'END'

noSmearOffShell=$(g++ -o classify_bdt_noSmearOffShell -I  `root-config --incdir` classify_bdt_noSmearOffShell.cc `root-config --libs`)
echo $noSmearOffShell

for i in ${offshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_noSmearOffShell root_files_noSmear.list $i
done


noSmearOnShell=$(g++ -o classify_bdt_noSmearOnShell -I  `root-config --incdir` classify_bdt_noSmearOnShell.cc `root-config --libs`)
echo $noSmearOnShell

for i in ${onshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_noSmearOnShell root_files_noSmear.list $i
done



withSmear1OffShell=$(g++ -o classify_bdt_withSmear1OffShell -I  `root-config --incdir` classify_bdt_withSmear1OffShell.cc `root-config --libs`)
echo $withSmear1OffShell

for i in ${offshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_withSmear1OffShell root_files_withSmear1.list $i
done


withSmear1OnShell=$(g++ -o classify_bdt_withSmear1OnShell -I  `root-config --incdir` classify_bdt_withSmear1OnShell.cc `root-config --libs`)
echo $withSmear1OnShell

for i in ${onshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_withSmear1OnShell root_files_withSmear1.list $i
done

END

withOverlayOffShell=$(g++ -o classify_bdt_withOverlayOffShell -I  `root-config --incdir` classify_bdt_withOverlayOffShell.cc `root-config --libs`)
echo $withOverlayOffShell

for i in ${offshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_withOverlayOffShell root_files_withOverlay.list $i
done


withOverlayOnShell=$(g++ -o classify_bdt_withOverlayOnShell -I  `root-config --incdir` classify_bdt_withOverlayOnShell.cc `root-config --libs`)
echo $withOverlayOnShell

for i in ${onshell[@]}
do
  echo "Classifying $i..."
  ./classify_bdt_withOverlayOnShell root_files_withOverlay.list $i
done
