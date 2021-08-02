#define treeAnalyser_cxx
#include "treeAnalyser.h"

#include <cmath>

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

void treeAnalyser::Loop(double cs = 8.093, TString R = "1.0", Bool_t myjets = false)
{
//   In a ROOT session, you can do:
//      root> .L treeAnalyser.C
//      root> treeAnalyser t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TString channel = "BP21";

   if (cs == 12.497 )
     channel = "BP23";
   if (cs == 2.430 )
     channel = "HP17";
   if (cs == 1.323  )
     channel = "HP20";
   if (cs == 0.6294 )
    channel = "HP3";
   if (cs == 7001 )
    channel = "qqlv";
   if (cs == 2715 )
    channel = "qqll";
   if (cs == 1406 )
    channel = "ll";
   if (cs == 1943.2 )
    channel = "qqqq";

  cout << "Analysing " << channel << " sample..." << endl;

   Long64_t nentries = fChain->GetEntriesFast();

   Double_t luminosity = 2000;

   TCanvas c1("c1", "", 200, 10, 600, 400);

   // book histograms
   TH1 *h_nPFOs = new TH1F("nPFOs", "", 50, 0.0, 200.0);

   // PFO theta histograms
   TH1 *h_phoLowPtTheta = new TH1F("phoLowPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_phoMedPtTheta = new TH1F("phoMedPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_phoHighPtTheta = new TH1F("phoHighPtTheta", "", 175, 0.0, 3.5);

	 TH1 *h_nhLowPtTheta = new TH1F("nhLowPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_nhMedPtTheta = new TH1F("nhMedPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_nhHighPtTheta = new TH1F("nhHighPtTheta", "", 175, 0.0, 3.5);

	 TH1 *h_chLowPtTheta = new TH1F("chLowPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_chMedPtTheta = new TH1F("chMedPtTheta", "", 175, 0.0, 3.5);
	 TH1 *h_chHighPtTheta = new TH1F("chHighPtTheta", "", 175, 0.0, 3.5);

   // PFO number histograms
   TH1 *h_phoLowPt_nPFOs = new TH1F("phoLowPt_nPFOs", "", 120, 0.0, 120.);
	 TH1 *h_phoHighPt_nPFOs = new TH1F("phoHighPt_nPFOs", "", 120, 0.0, 120.);

	 TH1 *h_nhLowPt_nPFOs = new TH1F("nhLowPt_nPFOs", "", 120, 0.0, 120.);
	 TH1 *h_nhHighPt_nPFOs = new TH1F("nhHighPt_nPFOs", "", 120, 0.0, 120.);

	 TH1 *h_chLowPt_nPFOs = new TH1F("chLowPt_nPFOs", "", 120, 0.0, 120.);
	 TH1 *h_chHighPt_nPFOs = new TH1F("chHighPt_nPFOs", "", 120, 0.0, 120.);

   TH1 *h_allLowPt_nPFOs = new TH1F("allLowPt_nPFOs", "", 200, 0.0, 200.);
	 TH1 *h_allHighPt_nPFOs = new TH1F("allHighPt_nPFOs", "", 200, 0.0, 200.);

   TH1 *h_phoPt = new TH1F("phoPt", "", 30, 0.0, 30.);
 	 TH1 *h_nhPt = new TH1F("nhPt", "", 30, 0.0, 30.);
 	 TH1 *h_chPt = new TH1F("chPt", "", 30, 0.0, 30.);

   TH1 *h_phoThetaPartial = new TH1F("phoThetaPartial", "", 175, 0.0, 3.5);
 	 TH1 *h_nhThetaPartial = new TH1F("nhThetaPartial", "", 175, 0.0, 3.5);
 	 TH1 *h_chThetaPartial = new TH1F("chThetaPartial", "", 175, 0.0, 3.5);
 	 TH1 *h_allThetaPartial = new TH1F("allThetaPartial", "", 175, 0.0, 3.5);

   TObjArray hList(0);
   hList.SetOwner(kTRUE);

   // loop over created histos and add them to list
   TIter next(gDirectory->GetList());
   TObject *obj;
   while ((obj = next())) {
     if (obj->InheritsFrom("TH1")) {
       TH1 *h = (TH1 *) obj;
       hList.Add(h);
     }
   }

   TString Rname = R;

   int addEnergy = 0;
   int noPhotons = 0;

   double crossSection = cs;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


      int nChLowPt = 0;
  		int nChHighPt = 0;
  		int nNeuLowPt = 0;
  		int nNeuHighPt = 0;
  		int nPhLowPt = 0;
  		int nPhHighPt = 0;

      for(int i=0; i<PFOs_n; i++) {

        //cout << PFOs_charge->at(i) << " " << fabs(PFOs_charge->at(i)) << endl;

        if( PFOs_type->at(i)==22 ) {
          if( PFOs_pt->at(i)<0.75 ) {h_phoLowPtTheta->Fill(PFOs_theta->at(i), 1. / nentries); }
          else if( PFOs_pt->at(i)<4 ) h_phoMedPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);
          else {h_phoHighPtTheta->Fill(PFOs_theta->at(i), 1. / nentries); }
          if(PFOs_pt->at(i) > 1 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nPhLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nPhHighPt++;
          h_phoPt->Fill(PFOs_pt->at(i), 1. / nentries);
          if(PFOs_pt->at(i)>2) {h_phoThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries);}
        }

        if( fabs(PFOs_type->at(i))>=111 && fabs(PFOs_charge->at(i)) < 1. ) {
          if( PFOs_pt->at(i)<0.75 ){ h_nhLowPtTheta->Fill(PFOs_theta->at(i), 1. / nentries); }
          else if( PFOs_pt->at(i)<8 ) h_nhMedPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);
          else {h_nhHighPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);}
          if(PFOs_pt->at(i) > 1.5 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nNeuLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nNeuHighPt++;
          h_nhPt->Fill(PFOs_pt->at(i), 1. / nentries);
          if(PFOs_pt->at(i)>2) {h_nhThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries);}
        }

        if( fabs(PFOs_charge->at(i)) > 0. ) {
          if( PFOs_pt->at(i)<0.75 ) {h_chLowPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);}
          else if( PFOs_pt->at(i)<4 ) h_chMedPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);
          else {h_chHighPtTheta->Fill(PFOs_theta->at(i), 1. / nentries);}
          if(PFOs_pt->at(i) > 1 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nChLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nChHighPt++;
          h_chPt->Fill(PFOs_pt->at(i), 1. / nentries);
          if(PFOs_pt->at(i)>2) {h_chThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / nentries);}
        }

      }
      h_phoLowPt_nPFOs->Fill(nPhLowPt, 1. / nentries);
      h_phoHighPt_nPFOs->Fill(nPhHighPt, 1. / nentries);
      h_nhLowPt_nPFOs->Fill(nNeuLowPt, 1. / nentries);
      h_nhHighPt_nPFOs->Fill(nNeuHighPt, 1. / nentries);
      h_chLowPt_nPFOs->Fill(nChLowPt, 1. / nentries);
      h_chHighPt_nPFOs->Fill(nChHighPt, 1. / nentries);

      int nAllLowPt = nNeuLowPt + nPhLowPt + nChLowPt;
  		int nAllHighPt = nNeuHighPt + nPhHighPt + nChHighPt;

  		h_allLowPt_nPFOs->Fill(nAllLowPt, 1. / nentries);
  		h_allHighPt_nPFOs->Fill(nAllHighPt, 1. / nentries);



   } // end of loop over events

   h_nPFOs->Scale( crossSection*luminosity/nentries );

   h_nPFOs->SetXTitle("N_{PFO}");

   // PFO theta and PFO number histograms

   h_phoLowPtTheta->SetXTitle("#theta_{#gamma}");
	 h_phoMedPtTheta->SetXTitle("#theta_{#gamma}");
	 h_phoHighPtTheta->SetXTitle("#theta_{#gamma}");
	 h_nhLowPtTheta->SetXTitle("#theta_{n.had.}");
	 h_nhMedPtTheta->SetXTitle("#theta_{n.had.}");
	 h_nhHighPtTheta->SetXTitle("#theta_{n.had.}");
	 h_chLowPtTheta->SetXTitle("#theta_{track}");
	 h_chMedPtTheta->SetXTitle("#theta_{track}");
	 h_chHighPtTheta->SetXTitle("#theta_{track}");

   h_phoLowPt_nPFOs->SetXTitle("N_{PFO}^{#gamma}");
 	 h_phoHighPt_nPFOs->SetXTitle("N_{PFO}^{#gamma}");
 	 h_nhLowPt_nPFOs->SetXTitle("N_{PFO}^{n.had.}");
 	 h_nhHighPt_nPFOs->SetXTitle("N_{PFO}^{n.had.}");
 	 h_chLowPt_nPFOs->SetXTitle("N_{PFO}^{track}");
 	 h_chHighPt_nPFOs->SetXTitle("N_{PFO}^{track}");
   h_allLowPt_nPFOs->SetXTitle("N_{PFO}^{all}");
 	 h_allHighPt_nPFOs->SetXTitle("N_{PFO}^{all}");

 	 h_phoPt->SetXTitle("p_{T}^{#gamma}");
 	 h_nhPt->SetXTitle("p_{T}^{n.had.}");
 	 h_chPt->SetXTitle("p_{T}^{track}");

   h_phoThetaPartial->SetXTitle("#theta_{#gamma}");
 	 h_nhThetaPartial->SetXTitle("#theta_{n.had.}");
 	 h_chThetaPartial->SetXTitle("#theta_{track}");
 	 h_allThetaPartial->SetXTitle("#theta_{PFO}");


	 h_phoLowPtTheta->SetYTitle("entries / event");
	 h_phoMedPtTheta->SetYTitle("entries / event");
	 h_phoHighPtTheta->SetYTitle("entries / event");
	 h_nhLowPtTheta->SetYTitle("entries / event");
	 h_nhMedPtTheta->SetYTitle("entries / event");
	 h_nhHighPtTheta->SetYTitle("entries / event");
	 h_chLowPtTheta->SetYTitle("entries / event");
	 h_chMedPtTheta->SetYTitle("entries / event");
	 h_chHighPtTheta->SetYTitle("entries / event");

   h_phoLowPt_nPFOs->SetYTitle("entries / event");
 	 h_phoHighPt_nPFOs->SetYTitle("entries / event");
 	 h_nhLowPt_nPFOs->SetYTitle("entries / event");
 	 h_nhHighPt_nPFOs->SetYTitle("entries / event");
 	 h_chLowPt_nPFOs->SetYTitle("entries / event");
 	 h_chHighPt_nPFOs->SetYTitle("entries / event");
   h_allLowPt_nPFOs->SetYTitle("entries / event");
 	 h_allHighPt_nPFOs->SetYTitle("entries / event");

 	 h_phoPt->SetYTitle("entries / event");
 	 h_nhPt->SetYTitle("entries / event");
 	 h_chPt->SetYTitle("entries / event");

   h_phoThetaPartial->SetYTitle("entries / event");
 	 h_nhThetaPartial->SetYTitle("entries / event");
 	 h_chThetaPartial->SetYTitle("entries / event");
 	 h_allThetaPartial->SetYTitle("entries / event");


   h_phoLowPtTheta->SetTitle("p_{T} < 0.75 GeV");
 	 h_phoMedPtTheta->SetTitle("0.75 GeV < p_{T} < 4 GeV");
 	 h_phoHighPtTheta->SetTitle("p_{T} > 4 GeV");
 	 h_nhLowPtTheta->SetTitle("p_{T} < 0.75 GeV");
 	 h_nhMedPtTheta->SetTitle("0.75 GeV < p_{T} < 8 GeV");
 	 h_nhHighPtTheta->SetTitle("p_{T} > 8 GeV");
 	 h_chLowPtTheta->SetTitle("p_{T} < 0.75 GeV");
 	 h_chMedPtTheta->SetTitle("0.75 GeV < p_{T} < 4 GeV");
 	 h_chHighPtTheta->SetTitle("p_{T} > 4 GeV");

   h_phoLowPt_nPFOs->SetTitle("p_{T} > 1 GeV, |#eta| < 2.4");
 	 h_phoHighPt_nPFOs->SetTitle("p_{T} > 2 GeV, |#eta| < 2.4");
 	 h_nhLowPt_nPFOs->SetTitle("p_{T} > 1.5 GeV, |#eta| < 2.4");
 	 h_nhHighPt_nPFOs->SetTitle("p_{T} > 2 GeV, |#eta| < 2.4");
 	 h_chLowPt_nPFOs->SetTitle("p_{T} > 1 GeV, |#eta| < 2.4");
 	 h_chHighPt_nPFOs->SetTitle("p_{T} > 2 GeV, |#eta| < 2.4");
 	 h_allLowPt_nPFOs->SetTitle("p_{T} > 1 (1.5) GeV, |#eta| < 2.4");
 	 h_allHighPt_nPFOs->SetTitle("p_{T} > 2 GeV, |#eta| < 2.4");


   h_phoThetaPartial->SetTitle("p_{T} > 2 GeV");
 	 h_nhThetaPartial->SetTitle("p_{T} > 2 GeV");
 	 h_chThetaPartial->SetTitle("p_{T} > 2 GeV");
 	 h_allThetaPartial->SetTitle("p_{T} > 2 GeV");

   c1.SetLogy(0);

   // save list to a file
   TFile f("./histoFiles/plotsBeforePreselectionFullSim_" + channel + "_PFOs.root", "recreate");
   hList.Write();
   f.Close();

}
