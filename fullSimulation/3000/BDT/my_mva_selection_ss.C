/**********************************************************************************
 *                                                                                *
 * Based on TMVAClassification.C - TMVA tutororial example                        *
 * General routine for training and testing BDT method                            *
 * A.F.Zarnecki                                                                   *
 *                                                                                *
 **********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "TMVA/mvaeffs.h"
#include "TMVA/variables.h"

int ncat=4;
string innames[4];
string treetag[4] = {"sig_train_","bg_train_","sig_test_","bg_test_"};
int nentries[4];
int nfiles[4];

int nsamp;
std::vector<string> samplename;
std::vector<string> treename;
std::vector<TTree*> samptree;
std::vector<TMVA::Types::ESBType> sbtype;     // kSignal, kBackground
std::vector<TMVA::Types::ETreeType> evtype;   //  kTraining, kTesting, kMaxTreeType
std::vector<int> sampcat;
std::vector<int> nevents;

string oldtreename = "event";         // tree name (should be the same in all input files)

void my_mva_selection_ss(string // signame1 = "root_withSmear1/idm_hphm_slep_BP18_1500DataPreselected.root root_withSmear1/idm_hphm_slep_BP21_1500DataPreselected.root root_withSmear1/idm_hphm_slep_BP23_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP1_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP3_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP4_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP5_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP15_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP19_1500DataPreselected.root",   // signal tree for training //all samples
				 signame1 = "inputs/myjets/R12/HP17_DataPreselected.root inputs/myjets/R12/HP20_DataPreselected.root inputs/myjets/R12/HP3_DataPreselected.root", //real W
				 // signame1 = "root_withSmear1/idm_hphm_slep_BP18_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP2_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP3_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP5_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP6_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP12_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP13_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP14_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP15_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP16_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP17_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP18_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP19_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP20_1500DataPreselected.root", //virual W (all)
				 // signame1 = "root_withSmear1/idm_hphm_slep_BP18_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP11_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP12_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP13_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP14_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP15_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP16_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP18_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP19_1500DataPreselected.root root_withSmear1/idm_hphm_slep_HP20_1500DataPreselected.root", //virual W
			   string bgname1 = "inputs/myjets/R12/qqll_DataPreselected.root inputs/myjets/R12/qqlv_DataPreselected.root",    // background tree for training
			   string signame2 = "HP17",   // signal tree for testing
			   string bgname2 = "",    // background tree for testing
				 string variables = "jetsM_inv jetsEnergy jetsTheta jet1Theta jet2Theta leptonEnergy leptonTheta leptonPt jetDeltaTheta jetDeltaPhi EFsum MET missingMass", // input BDT variable names
			   string spectator = "w", // spectator variable names (for output tree)
			   double nsgen= 1283.0,     // expected signal events
			   double nbgen= 1303751.0,     // expected background events
			   string signal = "",      // additional signal selection cut
			   string background = "",  // additional background selection cut
			   string weight = "w",     // event weigth formula
			   string outfile = "my_mva_selection_test", // output file name root
			   string Ntrees = "1000",  // number of trees
			   string transf = "G+D",     // input variable transformation options
			   string bdtpar = "UseNvars=6:PruneMethod=CostComplexity:PruneStrength=-1") // BDT options
{
  // Clear previous results

  nsamp=0;
  samplename.clear();
  treename.clear();
  samptree.clear();
  sbtype.clear();
  evtype.clear();
  sampcat.clear();
  nevents.clear();


  // Decode input tree names

	string fullSigname2 = "";

  innames[0]=signame1;
  innames[1]=bgname1;
  innames[2]=fullSigname2;
  innames[3]=bgname2;

  cout << endl << "Input files for BDT analysis:" << endl;

  for(int icat=0;icat<ncat;icat++)
    {
    TString filelist(innames[icat]);
    TObjArray* filearray = filelist.Tokenize(" ");
    int nFile = filearray->GetEntries();

    nentries[icat]=0;
    nfiles[icat]=0;

    for(int iFile=0; iFile<nFile; iFile++)
     {
     string fileName(((TObjString *)filearray->At(iFile))->String());
     samplename.push_back(fileName);

     stringstream fileTag;
     fileTag << treetag[icat] << iFile;
     treename.push_back(fileTag.str());

     TMVA::Types::ETreeType ttype =   TMVA::Types::kMaxTreeType;
     if(icat>=2) ttype =  TMVA::Types::kTesting;
     if(icat<2 && innames[icat+2].size()>0) ttype =  TMVA::Types::kTraining;
     evtype.push_back(ttype);

     if(icat%2==0)
       sbtype.push_back(TMVA::Types::kSignal);
     else
       sbtype.push_back(TMVA::Types::kBackground);

     samptree.push_back(NULL);
     nevents.push_back(0);
     sampcat.push_back(icat);

     cout << "   " << treename[nsamp] << " : " <<  sbtype[nsamp] << " " << evtype[nsamp] << " " << samplename[nsamp] << endl;

     nfiles[icat]++;
     nsamp++;
     }

    }

  cout << nsamp << " data samples will be used in the analysis " << endl << endl;

  // Open all trees

  for(int isamp=0;isamp<nsamp;isamp++)
    {
      samptree[isamp] = (TTree *)  gDirectory->FindObject(treename[isamp].c_str());

      string oldtitle = "";

      if( samptree[isamp]) oldtitle = samptree[isamp]->GetTitle();

      if( oldtitle == samplename[isamp] )
	cout << "Old Ttree found in memory: " << treename[isamp] << "  " << oldtitle << endl;
      else
	{
	if( samptree[isamp]) gDirectory->Delete(treename[isamp].c_str());

        TFile* treefile = new TFile( samplename[isamp].c_str() );

        if (!treefile)
          {
           cout << "==> Abort, please verify filename: " <<  samplename[isamp]  << endl;
           return;
          }

        samptree[isamp] = (TTree *)(treefile->FindObjectAny(oldtreename.c_str()));

        samptree[isamp]->SetNameTitle(treename[isamp].c_str(),samplename[isamp].c_str());

	cout << "Ttree read from file: " << samplename[isamp] << endl;

	}

      nevents[isamp] = samptree[isamp]->GetEntries();
      nentries[sampcat[isamp]] += nevents[isamp];

      cout << "Total of " << nevents[isamp] << " events in " << treename[isamp] << " tree " << endl;
    }

  cout << endl << "Total number of events per category: " << endl;

  for(int icat=0;icat<ncat;icat++)
    cout << "    " << treetag[icat] << " : " << nentries[icat] << endl;


  cout << endl << endl;

   //---------------------------------------------------------------
   // This loads the library

   TMVA::Tools::Instance();

   // to get access to the GUI and all tmva macros
   //    TString tmva_dir(TString(gRootDir) + "/tmva");
   //   if(gSystem->Getenv("TMVASYS"))
   //      tmva_dir = TString(gSystem->Getenv("TMVASYS"));
   //   gROOT->SetMacroPath(tmva_dir + "/test/:" + gROOT->GetMacroPath() );
   //
   //  gROOT->SetMacroPath(TString("test/:") + gROOT->GetMacroPath() );
   //  gROOT->ProcessLine(".L TMVAGui.C");
   //  gROOT->ProcessLine(".L efficiencies.C");


   // Default MVA methods to be trained + tested

   std::map<std::string,int> Use;

 // --- Boosted Decision Trees

   Use["SVM"]             = 0; // uses Adaptive Boost
   Use["BDT"]             = 1; // uses Adaptive Boost
   Use["BDTG"]            = 0; // uses Gradient Boost

 /*
   Use["BDTB"]            = 0; // uses Bagging
   Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
   Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting
 */

 // ---------------------------------------------------------------

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;


   // --- Here the preparation phase begins

   // Create a ROOT output file where TMVA will store ntuples, histograms, etc.

   string outroot = "./outputRootFiles/" + outfile + "_" + signame2 + ".root";

   TFile* outputFile = TFile::Open( outroot.c_str(), "RECREATE" );

   // Create the factory object. Later you can choose the methods
   // whose performance you'd like to investigate. The factory is
   // the only TMVA object you have to interact with
   //
   // The first argument is the base of the name of all the
   // weightfiles in the directory weight/
   //
   // The second argument is the output file for the training results
   // All TMVA output can be suppressed by removing the "!" (not) in
   // front of the "Silent" argument in the option string


   /*  V1
   TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
                 "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification" );
   */


   string factory_opt = "!V:!Silent:Color:DrawProgressBar:Transformations=" + transf + ":AnalysisType=Classification";

   TMVA::Factory *factory = new TMVA::Factory( outfile.c_str(), outputFile, factory_opt.c_str() );

   TMVA::DataLoader *dataloader=new TMVA::DataLoader("dataset");


   // If you wish to modify default settings
   // (please check "src/Config.h" to see all available global options)
   //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
   //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]


   TString varlist(variables);
   TObjArray* vararray = varlist.Tokenize(" ");
   int nVar = vararray->GetEntries();

   for(int iVar=0; iVar<nVar; iVar++)
     {
       string varName(((TObjString *)vararray->At(iVar))->String());
       cout << "Adding variable: " << varName << endl;
       dataloader->AddVariable( varName.c_str(), "", "", 'F' );
     }

/* // You can add so-called "Spectator variables", which are not used in the MVA training,
   // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
   // input variables, the response values of all trained MVAs, and the spectator variables
   //dataloader->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
   //dataloader->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );
*/

   TString speclist(spectator);
   TObjArray* specarray = speclist.Tokenize(" ");
   int nSpec = specarray->GetEntries();

   for(int iSpec=0; iSpec<nSpec; iSpec++)
     {
       string specName(((TObjString *)specarray->At(iSpec))->String());
       cout << "Adding spectator variable: " << specName << endl;
       dataloader->AddSpectator( specName.c_str(), "", "", 'F' );
     }


   // --- Register the training and test trees

   // global event weights per tree (see below for setting event-wise weights)

   Double_t signalWeight     = 1.0;
   Double_t backgroundWeight = 1.0;

   // Define signal and background trees

   for(int isamp = 0; isamp<nsamp;isamp++)
     {
       if(sbtype[isamp] == TMVA::Types::kSignal)
	 dataloader->AddSignalTree( samptree[isamp],  signalWeight, evtype[isamp] );
       else
         dataloader->AddBackgroundTree( samptree[isamp], backgroundWeight, evtype[isamp]  );
     }

   // From User Guide

   dataloader->SetWeightExpression( weight.c_str() );

   // Apply additional cuts on the signal and background samples (can be different)

   TCut mycuts = signal.c_str();

   TCut mycutb = background.c_str();  // Should in principle be empty - all events contribute

   // Tell the factory how to use the training and testing events
   //
   // If no numbers of events are given, half of the events in the tree are used
   // for training, and the other half for testing:
   //    dataloader->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
   // To also specify the number of testing events, use:
   //    dataloader->PrepareTrainingAndTestTree( mycut,
   //                                         "NSigTrain=1500:NBkgTrain=1500:NSigTest=1500:NBkgTest=1500:SplitMode=Random:!V" );

	 //TMVA::DataLoader* transformed_loader = dataloader->VarTransform("VT(2.95)");

   dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,"nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

   // ---- Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

	 if (Use["SVM"])  // Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kSVM, "SVM",
                 "Gamma=1:C=1:Tol=0.01:MaxIter=1" );

   if (Use["BDT"])  // Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT",
                 "!H:!V:NTrees=" + Ntrees + ":MinNodeSize=3%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseRandomisedTrees=True:SeparationType=GiniIndex:nCuts=100" + bdtpar );
			//factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT",
      //           "!H:!V:NTrees=" + Ntrees + ":MinNodeSize=3%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseRandomisedTrees=False:SeparationType=GiniIndex:nCuts=100" + bdtpar );
	 if (Use["BDTG"])  // Gradient Boost
			factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                 "!H:!V:NTrees=" + Ntrees + ":MinNodeSize=5%:MaxDepth=3:BoostType=Grad:Shrinkage=0.1:UseBaggedGrad:BaggedSampleFraction=0.6:UseRandomisedTrees=False:SeparationType=GiniIndex:nCuts=100" + bdtpar );

   // For an example of the category classifier usage, see: TMVAClassificationCategory

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can optimize the setting (configuration) of the MVAs using the set of training events

   // factory->OptimizeAllMethods("SigEffAt001","Scan");
   // factory->OptimizeAllMethods("ROCIntegral","GA");

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can tell the factory to train, test, and evaluate the MVAs

   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;
   delete dataloader;

   // Launch variable distributions and significance estimate

   TCanvas  *canvas1 = (TCanvas *) gROOT->FindObject("canvas1");
   if(canvas1)  gROOT->Delete("canvas1");

   TCanvas  *canvas2 = (TCanvas *) gROOT->FindObject("canvas2");
   if(canvas2)  gROOT->Delete("canvas2");


   TString fin=outroot.c_str();
   TString dataset="dataset";
   Bool_t useTMVAStyle = kFALSE;

   gStyle->SetOptLogy(0);

	 TString InputVarDir = "InputVariables_" + transf;
	 if(transf == "I")
	 	InputVarDir += "d";
	 else if(transf == "G")
	 	InputVarDir += "auss";
	 else if(transf == "P")
	 	InputVarDir += "CA";
	 else if(transf == "G+D")
 	 	InputVarDir = "InputVariables_Gauss_Deco";

	 //TMVA::variables(dataset,fin,"InputVariables_Id","TMVA Input Variables", kFALSE, useTMVAStyle);
	 TMVA::variables(dataset,fin,InputVarDir,"TMVA Input Variables", kFALSE, useTMVAStyle);

   canvas1 = (TCanvas *) gROOT->FindObject("canvas1");

   string outpdf = outfile + "_var.pdf";
   string outpng = outfile + "_var.png";
   string outc   = outfile + "_var.C";

   canvas1->Print(outpdf.c_str());
   canvas1->Print(outpng.c_str());
   canvas1->Print(outc.c_str());

   canvas2 = (TCanvas *) gROOT->FindObject("canvas2");

   if(canvas2)
     {
      outpdf = outfile + "_var2.pdf";
      outpng = outfile + "_var2.png";
      outc   = outfile + "_var2.C";

      canvas2->Print(outpdf.c_str());
      canvas2->Print(outpng.c_str());
      canvas2->Print(outc.c_str());

      gROOT->Delete("canvas2");
     }

   gROOT->Delete("canvas1");


   gStyle->SetOptLogy(1);

	 //TMVA::variables(dataset,fin,"InputVariables_Id","TMVA Input Variables", kFALSE, useTMVAStyle);
	 TMVA::variables(dataset,fin,InputVarDir,"TMVA Input Variables", kFALSE, useTMVAStyle);

   canvas1 = (TCanvas *) gROOT->FindObject("canvas1");

   outpdf = outfile + "_log.pdf";
   outpng = outfile + "_log.png";
   outc   = outfile + "_log.C";

   canvas1->Print(outpdf.c_str());
   canvas1->Print(outpng.c_str());
   canvas1->Print(outc.c_str());

   canvas2 = (TCanvas *) gROOT->FindObject("canvas2");

   if(canvas2)
     {
      outpdf = outfile + "_log2.pdf";
      outpng = outfile + "_log2.png";
      outc   = outfile + "_log2.C";

      canvas2->Print(outpdf.c_str());
      canvas2->Print(outpng.c_str());
      canvas2->Print(outc.c_str());

      gROOT->Delete("canvas2");
     }

   gROOT->Delete("canvas1");


   gStyle->SetOptLogy(0);

   TMVA::TMVAGlob::Initialize( useTMVAStyle );

   TString formula="S/sqrt(S+B)";


 // Number of events expected in each tree

   std::cout << "Number of expected signal events for significance calculation: " << nsgen << std::endl;

   std::cout << "Number of expected background events for significance calculation: " << nbgen << std::endl;

   TMVA::StatDialogMVAEffs* gGui = new TMVA::StatDialogMVAEffs(dataset,gClient->GetRoot(), nsgen, nbgen);

   TFile* file = TMVA::TMVAGlob::OpenFile( fin );

   gGui->ReadHistograms(file);
   gGui->SetFormula(formula);
   gGui->UpdateSignificanceHists();
   gGui->DrawHistograms();

   //   gGui->RaiseDialog();

   canvas1 = (TCanvas *) gROOT->FindObject("canvas1");

   outpdf = "./outputResults/" + outfile + "_sig_" + signame2 + ".pdf";
   outpng = outfile + "_sig.png";
   outc   = outfile + "_sig.C";

   canvas1->Print(outpdf.c_str());
   canvas1->Print(outpng.c_str());
   canvas1->Print(outc.c_str());


   // Launch the GUI for the root macros

   // if (!gROOT->IsBatch()) TMVA::TMVAGui( outroot.c_str() );

}
