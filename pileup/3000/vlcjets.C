/*

Check VLC jets on particle level

root -l 'vlcjets.C("root/root/qqqq_old_gen.root")

*/

#include "TSystem.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TClonesArray.h"

#include <iostream>
using namespace std;


//#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
//#else
//class ExRootTreeReader;
//class ExRootResult;
//#endif


// =================================================================
//
// Jet algorithm
// -------------
//
// Defines following global variables:
//
//    double Rval, Bval, Gval;
//    int Evar, Rvar;
//    double ymin,ymax;
//
//  Defines following routines:
//
//    double Jet2Jet_Distance(TLorentzVector &J1, TLorentzVector &J2)
//    double Jet2Beam_Distance(TLorentzVector &J1)
//    void DoJetClustering(std::vector<TLorentzVector> &ValJets, int ValReq, double Dmax=0.)
//    double JetJetDist(TLorentzVector** Jet1, TLorentzVector** Jet2, int Njet, int *idtab = NULL )
//
#include "jet_clustering.C"
//
// =================================================================

void vlcjets(const char *genFile="/home/jfklama/FUW/CLIC/IDM/pileup/qqlv_overlay_defaultSelected_batch20FullSelection10ns_19ev_Poisson_2_corrEff2.root", int nbin=100, double mmin=0., double mmax=500.)
{
  Rval=1.;
  Bval=1.;
  Gval=1.;
  Evar=0;
  Rvar=0;

  gSystem->Load("libDelphes");
  gStyle->SetOptStat(0);
  gStyle->SetOptLogy(1);

  // Create chain of input root trees

  TChain chain("Delphes");
  chain.Add(genFile);

  // Create object of class ExRootTreeReader

  ExRootTreeReader *genReader = new ExRootTreeReader(&chain);
  Long64_t genEntries = genReader->GetEntries();

  cout << "Input chain contains " << genEntries << " events" << endl;

  // Open canvas

  TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  if(!ch1)  ch1 = new TCanvas("ch1","Delphes histograms",20,20,600,450);
  ch1->cd();

  // (re)book histogram

  if( gDirectory->FindObject("hminv")!=NULL) gDirectory->Delete("hminv");
  TH1F *hminv = new TH1F("hminv","Jet invariant mass for signal",nbin, mmin, mmax);

  // Get pointers to branches used in this analysis

  TClonesArray *branchParticle = genReader->UseBranch("Particle");
  GenParticle *par;

  // Loop over tree events

  for(Int_t entry = 0; entry < genEntries; ++entry)
  {
    // Load selected branches with data from specified event

    genReader->ReadEntry(entry);

    int nPar = branchParticle->GetEntriesFast();

    //if(entry<10 || entry%100==0)
    //cout << entry << " " << nPar << " -> ";


    vector<TLorentzVector> ValJets;

    for(Int_t ipar=0; ipar<nPar; ipar++)
      {
      par = (GenParticle*) branchParticle->At(ipar);

      if(par->Status!=1)continue;

      ValJets.push_back(par->P4());
      }


    //if(entry<10 || entry%100==0)
    //cout << ValJets.size() << " -> " ;

    double Dcut=0.;
    int ValReq=2;

    DoJetClustering(ValJets,ValReq,Dcut);

    //if(entry<10 || entry%100==0)
    //cout << ValJets[0].M() << " + " << ValJets[1].M() << endl;

    hminv->Fill(ValJets[0].M());
    hminv->Fill(ValJets[1].M());

  }


 ch1->Clear();

 hminv->SetLineColor(2);
 hminv->GetXaxis()->SetTitle("M_{jj} [GeV]");
 hminv->GetYaxis()->SetTitle("Entries");
 hminv->SetMinimum(0.7);

 hminv->Draw();
}
