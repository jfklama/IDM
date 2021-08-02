#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TVector3.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

// ReadBDT class for testing BDT response

#include "chain_list.C"
#include "dataset_off_shellwithOverlay_alternativeMissingP4_noMlv/weights/my_mva_selection_test_BDT.class.C"

using namespace std ;

/*
 *
 *  Test BDT training results on previously generated test event sample
 *
 *  Compile with:
 *  g++ -o test_bdt -I  `root-config --incdir` test_bdt.cc `root-config --libs`
 *
 *  A.F.Zarnecki, 2020-08-05
 */

int main(int argc, char** argv ){

  string inputFileName  = "../root_withOverlay_cutsForFastSim/idm_hphm_slep_BP18_1500DataPreselected.root";
  string outputFileName = "BDT_AppTest/event.root";

  string sigChannel = "BP18";

  if(argc>2) {
    sigChannel = argv[2];
    inputFileName  = "../root_withOverlay_alternativeMissingP4/idm_hphm_slep_" + sigChannel + "_1500DataPreselected.root";
    outputFileName = "BDT_Classified/root_withDefaultSelectedOverlay_cutsForFastSim/off_shell/" + sigChannel + "_classified.root";
  }
/*
  // Initialize root

  TROOT simple("simple","Using ROOT in a compiled program");

  // Input event tree

  TFile *fin = new TFile(inputFileName.c_str());

  if( ! fin->IsOpen() )
    {
     cout << "Error opening input root file !?" << endl;
     exit(2);
    }
*/
  //TTree *tin = (TTree *) fin->FindObjectAny("event");

  TChain *tempChain;
  tempChain = chain_list(argv[1],"event");
  tempChain->AddFile(inputFileName.c_str());

  TTree *tin;
  tin = tempChain;



  long nentries = tin->GetEntries();


  struct event_head {
     Int_t Ievt;
     Float_t weight;
     Float_t crossSection;
     char *sampleName;
    };

  struct event_data {
     Float_t jetsM_inv;
     Float_t jetsEnergy;
     Float_t jetsTheta;
     Float_t leptonEnergy;
     Float_t leptonTheta;
     Float_t leptonPt;
     Float_t jetDeltaTheta;
     Float_t jetDeltaPhi;
     Float_t EFsum;
     Float_t MET;
     Float_t missingMass;
     Float_t jet1Theta;
     Float_t jet2Theta;
     Float_t jet1Pt;
     Float_t jet2Pt;
     Float_t jet1E;
     Float_t jet2E;
     Float_t M_inv_Wlep;
   };

  event_head myheader;
  event_data mydata;

  tin->SetBranchAddress("header",&myheader);
  tin->SetBranchAddress("data",&mydata);

  // Open output file

  TFile *fout = new TFile(outputFileName.c_str(),"RECREATE");

  if( ! fout->IsOpen() )
    {
     cout << "Error creating output root file !?" << endl;
     exit(2);
    }

  // Create output tree (same data + BDT response)

  TTree *tout   = new TTree("event","Simple TMVA test: BDT response on test event sample");

  tout->Branch( "header",&myheader, "Ievt/I:w/F:crossSection/F:sampleName/C" );
  tout->Branch( "data",&mydata, "jetsM_inv/F:jetsEnergy:jetsTheta:leptonEnergy:leptonTheta:leptonPt:jetDeltaTheta:jetDeltaPhi:EFsum:MET:missingMass:jet1Theta:jet2Theta:jet1Pt:jet2Pt:jet1E:jet2E");

  struct event_bdt {
      Int_t classID;
      Float_t BDT;
     };

  event_bdt mybdt;

  tout->Branch("bdt",&mybdt, "classID/I:BDT/F" );

  // Prepare BDT testing
/*
  const string myInputVars[] = { "jetsM_inv", "jetsEnergy", "jetsTheta", "leptonEnergy","leptonTheta", "leptonPt", "EFsum", "MET", "missingMass", "jet1Theta", "jet2Theta", "jet1Pt", "jet2Pt", "jet1E", "jet2E", "M_inv_Wlep" };
  int myNvar=9;

  vector<double> myInputVariableValues(9);

*/
  const string myInputVars[] = { "jetsM_inv", "jetsEnergy", "jetsTheta", "leptonEnergy","leptonTheta", "leptonPt", "jetDeltaTheta", "jetDeltaPhi", "EFsum", "MET", "missingMass", "jet1Theta", "jet2Theta", "jet1Pt", "jet2Pt", "jet1E", "jet2E" };
  int myNvar=17;

  vector<double> myInputVariableValues(17);

  IClassifierReader* myClassReader;   // pointer to BDT classifier

  cout << "Input variables: " << endl;

  vector<string> inputVariableNames;
  for(int ivar=0;ivar<myNvar;ivar++) {
     inputVariableNames.push_back(myInputVars[ivar]);
     cout << ivar+1 << ". " << myInputVars[ivar] << endl;
  }
  cout << endl;

  myClassReader = new ReadBDT(inputVariableNames);

 // Loop over events, calculate BDT response and fill new tree

  for(long jentry=0; jentry<nentries;jentry++)
    {
     tin->GetEntry(jentry);
/*
      myInputVariableValues[0] = mydata.jetsM_inv;
      myInputVariableValues[1] = mydata.jetsEnergy;
      myInputVariableValues[2] = mydata.jetsTheta;
      myInputVariableValues[3] = mydata.leptonEnergy;
      myInputVariableValues[4] = mydata.leptonTheta;
      myInputVariableValues[5] = mydata.leptonPt;
      myInputVariableValues[6] = mydata.EFsum;
      myInputVariableValues[7] = mydata.MET;
      myInputVariableValues[8] = mydata.missingMass;
*/
      myInputVariableValues[0] = mydata.jetsM_inv;
      myInputVariableValues[1] = mydata.jetsEnergy;
      myInputVariableValues[2] = mydata.jetsTheta;
      myInputVariableValues[3] = mydata.leptonEnergy;
      myInputVariableValues[4] = mydata.leptonTheta;
      myInputVariableValues[5] = mydata.leptonPt;
      myInputVariableValues[6] = mydata.jetDeltaTheta;
      myInputVariableValues[7] = mydata.jetDeltaPhi;
      myInputVariableValues[8] = mydata.EFsum;
      myInputVariableValues[9] = mydata.MET;
      myInputVariableValues[10] = mydata.missingMass;
      myInputVariableValues[11] = mydata.jet1Theta;
      myInputVariableValues[12] = mydata.jet2Theta;
      myInputVariableValues[13] = mydata.jet1Pt;
      myInputVariableValues[14] = mydata.jet2Pt;
      myInputVariableValues[15] = mydata.jet1E;
      myInputVariableValues[16] = mydata.jet2E;
      //myInputVariableValues[17] = mydata.M_inv_Wlep;

      mybdt.BDT = myClassReader->GetMvaValue(myInputVariableValues);

      if( myheader.crossSection > 20. )
        mybdt.classID = 0;
      else
        mybdt.classID = 1;

      tout->Fill();

     if(myheader.Ievt%1000 == 0) {
        cout << myheader.Ievt << " :  ( "
  //           << mydata.x << ", "
  //           << mydata.y << ", " << mydata.z << ", "
  //           << mydata.t << ")  =>  " << mybdt.angle
	     << " => " << mybdt.BDT << endl;
       cout << "Analysing " << jentry << " entry in chain out of " << nentries << endl;
     }


    }

  cout << "Writing output file...";

  fout->Write();

  cout << " Done!" << endl;

  cout << "Closing output file...";

  fout->Close();

  cout << " Done!" << endl;

  return 0 ;
}
