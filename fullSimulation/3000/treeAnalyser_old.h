//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Feb  1 15:31:49 2020 by ROOT version 6.15/01
// from TTree rawTree/rawTree
// found on file: rootSamples/signal/idm_HpHm_3000_BP21.root
//////////////////////////////////////////////////////////

#ifndef treeAnalyser_h
#define treeAnalyser_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class treeAnalyser {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        qq_m;
   Double_t        ln_m;
   Double_t        beam_e;
   Double_t        miss_pt;
   Double_t        miss_theta;
   Double_t        miss_phi;
   Double_t        miss_e;
   Double_t        mc_beam_e;
   Double_t        mc_qq_m;
   Double_t        mc_ln_m;
   Int_t           mc_n;
   vector<int>     *mc_gen_status;
   vector<int>     *mc_type;
   vector<double>  *mc_pt;
   vector<double>  *mc_theta;
   vector<double>  *mc_phi;
   vector<double>  *mc_e;
   vector<double>  *mc_charge;
   Int_t           lep_n;
   Double_t        lep_etot;
   vector<int>     *lep_type;
   vector<double>  *lep_pt;
   vector<double>  *lep_theta;
   vector<double>  *lep_phi;
   vector<double>  *lep_e;
   vector<double>  *lep_charge;
   Int_t           photon_n;
   Double_t        photon_etot;
   vector<int>     *photon_type;
   vector<double>  *photon_pt;
   vector<double>  *photon_theta;
   vector<double>  *photon_phi;
   vector<double>  *photon_e;
   vector<double>  *photon_charge;
   Int_t           PFOnoIso_n;
   vector<int>     *PFOnoIso_type;
   vector<double>  *PFOnoIso_pt;
   vector<double>  *PFOnoIso_theta;
   vector<double>  *PFOnoIso_phi;
   vector<double>  *PFOnoIso_e;
   vector<double>  *PFOnoIso_charge;
   Int_t           PFOs_n;
   vector<int>     *PFOs_type;
   vector<double>  *PFOs_pt;
   vector<double>  *PFOs_theta;
   vector<double>  *PFOs_phi;
   vector<double>  *PFOs_e;
   vector<double>  *PFOs_charge;
   Int_t           jet_vlc_R10_n;
   Double_t        jet_vlc_R10_etot;
   vector<double>  *jet_vlc_R10_pt;
   vector<double>  *jet_vlc_R10_theta;
   vector<double>  *jet_vlc_R10_phi;
   vector<double>  *jet_vlc_R10_e;
   vector<double>  *jet_vlc_R10_charge;
   Int_t           jet_vlc_R12_n;
   Double_t        jet_vlc_R12_etot;
   vector<double>  *jet_vlc_R12_pt;
   vector<double>  *jet_vlc_R12_theta;
   vector<double>  *jet_vlc_R12_phi;
   vector<double>  *jet_vlc_R12_e;
   vector<double>  *jet_vlc_R12_charge;
   Int_t           jet_vlc_R06_n;
   Double_t        jet_vlc_R06_etot;
   vector<double>  *jet_vlc_R06_pt;
   vector<double>  *jet_vlc_R06_theta;
   vector<double>  *jet_vlc_R06_phi;
   vector<double>  *jet_vlc_R06_e;
   vector<double>  *jet_vlc_R06_charge;
   Int_t           jet_vlc_R07_n;
   Double_t        jet_vlc_R07_etot;
   vector<double>  *jet_vlc_R07_pt;
   vector<double>  *jet_vlc_R07_theta;
   vector<double>  *jet_vlc_R07_phi;
   vector<double>  *jet_vlc_R07_e;
   vector<double>  *jet_vlc_R07_charge;
   Int_t           jet_vlc_R08_n;
   Double_t        jet_vlc_R08_etot;
   vector<double>  *jet_vlc_R08_pt;
   vector<double>  *jet_vlc_R08_theta;
   vector<double>  *jet_vlc_R08_phi;
   vector<double>  *jet_vlc_R08_e;
   vector<double>  *jet_vlc_R08_charge;
   Int_t           jet_vlc_R09_n;
   Double_t        jet_vlc_R09_etot;
   vector<double>  *jet_vlc_R09_pt;
   vector<double>  *jet_vlc_R09_theta;
   vector<double>  *jet_vlc_R09_phi;
   vector<double>  *jet_vlc_R09_e;
   vector<double>  *jet_vlc_R09_charge;
   Int_t           jet_vlc_R15_n;
   Double_t        jet_vlc_R15_etot;
   vector<double>  *jet_vlc_R15_pt;
   vector<double>  *jet_vlc_R15_theta;
   vector<double>  *jet_vlc_R15_phi;
   vector<double>  *jet_vlc_R15_e;
   vector<double>  *jet_vlc_R15_charge;

   // List of branches
   TBranch        *b_qq_m;   //!
   TBranch        *b_ln_m;   //!
   TBranch        *b_beam_e;   //!
   TBranch        *b_miss_pt;   //!
   TBranch        *b_miss_theta;   //!
   TBranch        *b_miss_phi;   //!
   TBranch        *b_miss_e;   //!
   TBranch        *b_mc_beam_e;   //!
   TBranch        *b_mc_qq_m;   //!
   TBranch        *b_mc_ln_m;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_gen_status;   //!
   TBranch        *b_mc_type;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_mc_theta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_e;   //!
   TBranch        *b_mc_charge;   //!
   TBranch        *b_lep_n;   //!
   TBranch        *b_lep_etot;   //!
   TBranch        *b_lep_type;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_theta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_e;   //!
   TBranch        *b_lep_charge;   //!
   TBranch        *b_photon_n;   //!
   TBranch        *b_photon_etot;   //!
   TBranch        *b_photon_type;   //!
   TBranch        *b_photon_pt;   //!
   TBranch        *b_photon_theta;   //!
   TBranch        *b_photon_phi;   //!
   TBranch        *b_photon_e;   //!
   TBranch        *b_photon_charge;   //!
   TBranch        *b_PFOnoIso_n;   //!
   TBranch        *b_PFOnoIso_type;   //!
   TBranch        *b_PFOnoIso_pt;   //!
   TBranch        *b_PFOnoIso_theta;   //!
   TBranch        *b_PFOnoIso_phi;   //!
   TBranch        *b_PFOnoIso_e;   //!
   TBranch        *b_PFOnoIso_charge;   //!
   TBranch        *b_PFOs_n;   //!
   TBranch        *b_PFOs_type;   //!
   TBranch        *b_PFOs_pt;   //!
   TBranch        *b_PFOs_theta;   //!
   TBranch        *b_PFOs_phi;   //!
   TBranch        *b_PFOs_e;   //!
   TBranch        *b_PFOs_charge;   //!
   TBranch        *b_jet_vlc_R10_n;   //!
   TBranch        *b_jet_vlc_R10_etot;   //!
   TBranch        *b_jet_vlc_R10_pt;   //!
   TBranch        *b_jet_vlc_R10_theta;   //!
   TBranch        *b_jet_vlc_R10_phi;   //!
   TBranch        *b_jet_vlc_R10_e;   //!
   TBranch        *b_jet_vlc_R10_charge;   //!
   TBranch        *b_jet_vlc_R12_n;   //!
   TBranch        *b_jet_vlc_R12_etot;   //!
   TBranch        *b_jet_vlc_R12_pt;   //!
   TBranch        *b_jet_vlc_R12_theta;   //!
   TBranch        *b_jet_vlc_R12_phi;   //!
   TBranch        *b_jet_vlc_R12_e;   //!
   TBranch        *b_jet_vlc_R12_charge;   //!
   TBranch        *b_jet_vlc_R06_n;   //!
   TBranch        *b_jet_vlc_R06_etot;   //!
   TBranch        *b_jet_vlc_R06_pt;   //!
   TBranch        *b_jet_vlc_R06_theta;   //!
   TBranch        *b_jet_vlc_R06_phi;   //!
   TBranch        *b_jet_vlc_R06_e;   //!
   TBranch        *b_jet_vlc_R06_charge;   //!
   TBranch        *b_jet_vlc_R07_n;   //!
   TBranch        *b_jet_vlc_R07_etot;   //!
   TBranch        *b_jet_vlc_R07_pt;   //!
   TBranch        *b_jet_vlc_R07_theta;   //!
   TBranch        *b_jet_vlc_R07_phi;   //!
   TBranch        *b_jet_vlc_R07_e;   //!
   TBranch        *b_jet_vlc_R07_charge;   //!
   TBranch        *b_jet_vlc_R08_n;   //!
   TBranch        *b_jet_vlc_R08_etot;   //!
   TBranch        *b_jet_vlc_R08_pt;   //!
   TBranch        *b_jet_vlc_R08_theta;   //!
   TBranch        *b_jet_vlc_R08_phi;   //!
   TBranch        *b_jet_vlc_R08_e;   //!
   TBranch        *b_jet_vlc_R08_charge;   //!
   TBranch        *b_jet_vlc_R09_n;   //!
   TBranch        *b_jet_vlc_R09_etot;   //!
   TBranch        *b_jet_vlc_R09_pt;   //!
   TBranch        *b_jet_vlc_R09_theta;   //!
   TBranch        *b_jet_vlc_R09_phi;   //!
   TBranch        *b_jet_vlc_R09_e;   //!
   TBranch        *b_jet_vlc_R09_charge;   //!
   TBranch        *b_jet_vlc_R15_n;   //!
   TBranch        *b_jet_vlc_R15_etot;   //!
   TBranch        *b_jet_vlc_R15_pt;   //!
   TBranch        *b_jet_vlc_R15_theta;   //!
   TBranch        *b_jet_vlc_R15_phi;   //!
   TBranch        *b_jet_vlc_R15_e;   //!
   TBranch        *b_jet_vlc_R15_charge;   //!

   treeAnalyser(TTree *tree=0);
   virtual ~treeAnalyser();
   virtual Int_t                    Cut(Long64_t entry);
   virtual Int_t                    GetEntry(Long64_t entry);
   virtual Long64_t                 LoadTree(Long64_t entry);
   virtual void                     Init(TTree *tree);
   virtual void                     Loop(double crossSection = 4.213, double R = 1.2);
   virtual Bool_t                   Notify();
   virtual void                     Show(Long64_t entry = -1);
   virtual std::vector<double> 			GetThetaInW_CMS(TLorentzVector v1, TLorentzVector v2);
   virtual std::vector<double> 			GetPhiInW_CMS(TLorentzVector v1, TLorentzVector v2);
};

#endif

#ifdef treeAnalyser_cxx
treeAnalyser::treeAnalyser(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rootSamples/signal/idm_HpHm_3000_BP21.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("rootSamples/signal/idm_HpHm_3000_BP21.root");
      }
      f->GetObject("rawTree",tree);

   }
   Init(tree);
}

treeAnalyser::~treeAnalyser()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t treeAnalyser::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t treeAnalyser::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void treeAnalyser::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_gen_status = 0;
   mc_type = 0;
   mc_pt = 0;
   mc_theta = 0;
   mc_phi = 0;
   mc_e = 0;
   mc_charge = 0;
   lep_type = 0;
   lep_pt = 0;
   lep_theta = 0;
   lep_phi = 0;
   lep_e = 0;
   lep_charge = 0;
   photon_type = 0;
   photon_pt = 0;
   photon_theta = 0;
   photon_phi = 0;
   photon_e = 0;
   photon_charge = 0;
   PFOnoIso_type = 0;
   PFOnoIso_pt = 0;
   PFOnoIso_theta = 0;
   PFOnoIso_phi = 0;
   PFOnoIso_e = 0;
   PFOnoIso_charge = 0;
   PFOs_type = 0;
   PFOs_pt = 0;
   PFOs_theta = 0;
   PFOs_phi = 0;
   PFOs_e = 0;
   PFOs_charge = 0;
   jet_vlc_R10_pt = 0;
   jet_vlc_R10_theta = 0;
   jet_vlc_R10_phi = 0;
   jet_vlc_R10_e = 0;
   jet_vlc_R10_charge = 0;
   jet_vlc_R12_pt = 0;
   jet_vlc_R12_theta = 0;
   jet_vlc_R12_phi = 0;
   jet_vlc_R12_e = 0;
   jet_vlc_R12_charge = 0;
   jet_vlc_R06_pt = 0;
   jet_vlc_R06_theta = 0;
   jet_vlc_R06_phi = 0;
   jet_vlc_R06_e = 0;
   jet_vlc_R06_charge = 0;
   jet_vlc_R07_pt = 0;
   jet_vlc_R07_theta = 0;
   jet_vlc_R07_phi = 0;
   jet_vlc_R07_e = 0;
   jet_vlc_R07_charge = 0;
   jet_vlc_R08_pt = 0;
   jet_vlc_R08_theta = 0;
   jet_vlc_R08_phi = 0;
   jet_vlc_R08_e = 0;
   jet_vlc_R08_charge = 0;
   jet_vlc_R09_pt = 0;
   jet_vlc_R09_theta = 0;
   jet_vlc_R09_phi = 0;
   jet_vlc_R09_e = 0;
   jet_vlc_R09_charge = 0;
   jet_vlc_R15_pt = 0;
   jet_vlc_R15_theta = 0;
   jet_vlc_R15_phi = 0;
   jet_vlc_R15_e = 0;
   jet_vlc_R15_charge = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("qq_m", &qq_m, &b_qq_m);
   fChain->SetBranchAddress("ln_m", &ln_m, &b_ln_m);
   fChain->SetBranchAddress("beam_e", &beam_e, &b_beam_e);
   fChain->SetBranchAddress("miss_pt", &miss_pt, &b_miss_pt);
   fChain->SetBranchAddress("miss_theta", &miss_theta, &b_miss_theta);
   fChain->SetBranchAddress("miss_phi", &miss_phi, &b_miss_phi);
   fChain->SetBranchAddress("miss_e", &miss_e, &b_miss_e);
   fChain->SetBranchAddress("mc_beam_e", &mc_beam_e, &b_mc_beam_e);
   fChain->SetBranchAddress("mc_qq_m", &mc_qq_m, &b_mc_qq_m);
   fChain->SetBranchAddress("mc_ln_m", &mc_ln_m, &b_mc_ln_m);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_gen_status", &mc_gen_status, &b_mc_gen_status);
   fChain->SetBranchAddress("mc_type", &mc_type, &b_mc_type);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_theta", &mc_theta, &b_mc_theta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_e", &mc_e, &b_mc_e);
   fChain->SetBranchAddress("mc_charge", &mc_charge, &b_mc_charge);
   fChain->SetBranchAddress("lep_n", &lep_n, &b_lep_n);
   fChain->SetBranchAddress("lep_etot", &lep_etot, &b_lep_etot);
   fChain->SetBranchAddress("lep_type", &lep_type, &b_lep_type);
   fChain->SetBranchAddress("lep_pt", &lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_theta", &lep_theta, &b_lep_theta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_e", &lep_e, &b_lep_e);
   fChain->SetBranchAddress("lep_charge", &lep_charge, &b_lep_charge);
   fChain->SetBranchAddress("photon_n", &photon_n, &b_photon_n);
   fChain->SetBranchAddress("photon_etot", &photon_etot, &b_photon_etot);
   fChain->SetBranchAddress("photon_type", &photon_type, &b_photon_type);
   fChain->SetBranchAddress("photon_pt", &photon_pt, &b_photon_pt);
   fChain->SetBranchAddress("photon_theta", &photon_theta, &b_photon_theta);
   fChain->SetBranchAddress("photon_phi", &photon_phi, &b_photon_phi);
   fChain->SetBranchAddress("photon_e", &photon_e, &b_photon_e);
   fChain->SetBranchAddress("photon_charge", &photon_charge, &b_photon_charge);
   fChain->SetBranchAddress("PFOnoIso_n", &PFOnoIso_n, &b_PFOnoIso_n);
   fChain->SetBranchAddress("PFOnoIso_type", &PFOnoIso_type, &b_PFOnoIso_type);
   fChain->SetBranchAddress("PFOnoIso_pt", &PFOnoIso_pt, &b_PFOnoIso_pt);
   fChain->SetBranchAddress("PFOnoIso_theta", &PFOnoIso_theta, &b_PFOnoIso_theta);
   fChain->SetBranchAddress("PFOnoIso_phi", &PFOnoIso_phi, &b_PFOnoIso_phi);
   fChain->SetBranchAddress("PFOnoIso_e", &PFOnoIso_e, &b_PFOnoIso_e);
   fChain->SetBranchAddress("PFOnoIso_charge", &PFOnoIso_charge, &b_PFOnoIso_charge);
   fChain->SetBranchAddress("PFOs_n", &PFOs_n, &b_PFOs_n);
   fChain->SetBranchAddress("PFOs_type", &PFOs_type, &b_PFOs_type);
   fChain->SetBranchAddress("PFOs_pt", &PFOs_pt, &b_PFOs_pt);
   fChain->SetBranchAddress("PFOs_theta", &PFOs_theta, &b_PFOs_theta);
   fChain->SetBranchAddress("PFOs_phi", &PFOs_phi, &b_PFOs_phi);
   fChain->SetBranchAddress("PFOs_e", &PFOs_e, &b_PFOs_e);
   fChain->SetBranchAddress("PFOs_charge", &PFOs_charge, &b_PFOs_charge);
   fChain->SetBranchAddress("jet_vlc_R10_n", &jet_vlc_R10_n, &b_jet_vlc_R10_n);
   fChain->SetBranchAddress("jet_vlc_R10_etot", &jet_vlc_R10_etot, &b_jet_vlc_R10_etot);
   fChain->SetBranchAddress("jet_vlc_R10_pt", &jet_vlc_R10_pt, &b_jet_vlc_R10_pt);
   fChain->SetBranchAddress("jet_vlc_R10_theta", &jet_vlc_R10_theta, &b_jet_vlc_R10_theta);
   fChain->SetBranchAddress("jet_vlc_R10_phi", &jet_vlc_R10_phi, &b_jet_vlc_R10_phi);
   fChain->SetBranchAddress("jet_vlc_R10_e", &jet_vlc_R10_e, &b_jet_vlc_R10_e);
   fChain->SetBranchAddress("jet_vlc_R10_charge", &jet_vlc_R10_charge, &b_jet_vlc_R10_charge);
   fChain->SetBranchAddress("jet_vlc_R12_n", &jet_vlc_R12_n, &b_jet_vlc_R12_n);
   fChain->SetBranchAddress("jet_vlc_R12_etot", &jet_vlc_R12_etot, &b_jet_vlc_R12_etot);
   fChain->SetBranchAddress("jet_vlc_R12_pt", &jet_vlc_R12_pt, &b_jet_vlc_R12_pt);
   fChain->SetBranchAddress("jet_vlc_R12_theta", &jet_vlc_R12_theta, &b_jet_vlc_R12_theta);
   fChain->SetBranchAddress("jet_vlc_R12_phi", &jet_vlc_R12_phi, &b_jet_vlc_R12_phi);
   fChain->SetBranchAddress("jet_vlc_R12_e", &jet_vlc_R12_e, &b_jet_vlc_R12_e);
   fChain->SetBranchAddress("jet_vlc_R12_charge", &jet_vlc_R12_charge, &b_jet_vlc_R12_charge);
   fChain->SetBranchAddress("jet_vlc_R06_n", &jet_vlc_R06_n, &b_jet_vlc_R06_n);
   fChain->SetBranchAddress("jet_vlc_R06_etot", &jet_vlc_R06_etot, &b_jet_vlc_R06_etot);
   fChain->SetBranchAddress("jet_vlc_R06_pt", &jet_vlc_R06_pt, &b_jet_vlc_R06_pt);
   fChain->SetBranchAddress("jet_vlc_R06_theta", &jet_vlc_R06_theta, &b_jet_vlc_R06_theta);
   fChain->SetBranchAddress("jet_vlc_R06_phi", &jet_vlc_R06_phi, &b_jet_vlc_R06_phi);
   fChain->SetBranchAddress("jet_vlc_R06_e", &jet_vlc_R06_e, &b_jet_vlc_R06_e);
   fChain->SetBranchAddress("jet_vlc_R06_charge", &jet_vlc_R06_charge, &b_jet_vlc_R06_charge);
   fChain->SetBranchAddress("jet_vlc_R07_n", &jet_vlc_R07_n, &b_jet_vlc_R07_n);
   fChain->SetBranchAddress("jet_vlc_R07_etot", &jet_vlc_R07_etot, &b_jet_vlc_R07_etot);
   fChain->SetBranchAddress("jet_vlc_R07_pt", &jet_vlc_R07_pt, &b_jet_vlc_R07_pt);
   fChain->SetBranchAddress("jet_vlc_R07_theta", &jet_vlc_R07_theta, &b_jet_vlc_R07_theta);
   fChain->SetBranchAddress("jet_vlc_R07_phi", &jet_vlc_R07_phi, &b_jet_vlc_R07_phi);
   fChain->SetBranchAddress("jet_vlc_R07_e", &jet_vlc_R07_e, &b_jet_vlc_R07_e);
   fChain->SetBranchAddress("jet_vlc_R07_charge", &jet_vlc_R07_charge, &b_jet_vlc_R07_charge);
   fChain->SetBranchAddress("jet_vlc_R08_n", &jet_vlc_R08_n, &b_jet_vlc_R08_n);
   fChain->SetBranchAddress("jet_vlc_R08_etot", &jet_vlc_R08_etot, &b_jet_vlc_R08_etot);
   fChain->SetBranchAddress("jet_vlc_R08_pt", &jet_vlc_R08_pt, &b_jet_vlc_R08_pt);
   fChain->SetBranchAddress("jet_vlc_R08_theta", &jet_vlc_R08_theta, &b_jet_vlc_R08_theta);
   fChain->SetBranchAddress("jet_vlc_R08_phi", &jet_vlc_R08_phi, &b_jet_vlc_R08_phi);
   fChain->SetBranchAddress("jet_vlc_R08_e", &jet_vlc_R08_e, &b_jet_vlc_R08_e);
   fChain->SetBranchAddress("jet_vlc_R08_charge", &jet_vlc_R08_charge, &b_jet_vlc_R08_charge);
   fChain->SetBranchAddress("jet_vlc_R09_n", &jet_vlc_R09_n, &b_jet_vlc_R09_n);
   fChain->SetBranchAddress("jet_vlc_R09_etot", &jet_vlc_R09_etot, &b_jet_vlc_R09_etot);
   fChain->SetBranchAddress("jet_vlc_R09_pt", &jet_vlc_R09_pt, &b_jet_vlc_R09_pt);
   fChain->SetBranchAddress("jet_vlc_R09_theta", &jet_vlc_R09_theta, &b_jet_vlc_R09_theta);
   fChain->SetBranchAddress("jet_vlc_R09_phi", &jet_vlc_R09_phi, &b_jet_vlc_R09_phi);
   fChain->SetBranchAddress("jet_vlc_R09_e", &jet_vlc_R09_e, &b_jet_vlc_R09_e);
   fChain->SetBranchAddress("jet_vlc_R09_charge", &jet_vlc_R09_charge, &b_jet_vlc_R09_charge);
   fChain->SetBranchAddress("jet_vlc_R15_n", &jet_vlc_R15_n, &b_jet_vlc_R15_n);
   fChain->SetBranchAddress("jet_vlc_R15_etot", &jet_vlc_R15_etot, &b_jet_vlc_R15_etot);
   fChain->SetBranchAddress("jet_vlc_R15_pt", &jet_vlc_R15_pt, &b_jet_vlc_R15_pt);
   fChain->SetBranchAddress("jet_vlc_R15_theta", &jet_vlc_R15_theta, &b_jet_vlc_R15_theta);
   fChain->SetBranchAddress("jet_vlc_R15_phi", &jet_vlc_R15_phi, &b_jet_vlc_R15_phi);
   fChain->SetBranchAddress("jet_vlc_R15_e", &jet_vlc_R15_e, &b_jet_vlc_R15_e);
   fChain->SetBranchAddress("jet_vlc_R15_charge", &jet_vlc_R15_charge, &b_jet_vlc_R15_charge);
   Notify();
}

Bool_t treeAnalyser::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void treeAnalyser::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t treeAnalyser::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
std::vector<double> treeAnalyser::GetThetaInW_CMS(TLorentzVector v1, TLorentzVector v2) // in lepton-neutrino system give lepton's P4 as v1
{

	TLorentzVector boosted1P4 = v1;
	TVector3 beta = -(v1+v2).BoostVector();
	boosted1P4.Boost(beta);

	double Theta1W_CM = boosted1P4.Theta() - (v1+v2).Theta();
	double Theta2W_CM = (TMath::Pi()-boosted1P4.Theta()) - (v1+v2).Theta();

	std::vector<double> ThetaW_CM;
	ThetaW_CM.push_back(Theta1W_CM);
	ThetaW_CM.push_back(Theta2W_CM);

	return ThetaW_CM;

}

std::vector<double> treeAnalyser::GetPhiInW_CMS(TLorentzVector v1, TLorentzVector v2) // in lepton-neutrino system give lepton's P4 as v1
{

	TLorentzVector boosted1P4 = v1;
	TVector3 beta = -(v1+v2).BoostVector();
	boosted1P4.Boost(beta);

	double Phi1W_CM = boosted1P4.Phi() - (v1+v2).Phi();
	double Phi2W_CM;

	if(Phi1W_CM>TMath::Pi())
		Phi1W_CM = 2*TMath::Pi() - Phi1W_CM;

	if(Phi1W_CM<-TMath::Pi())
		Phi1W_CM = -2*TMath::Pi() - Phi1W_CM;

	if(boosted1P4.Phi() > 0)
		Phi2W_CM = (-TMath::Pi() + boosted1P4.Phi()) - (v1+v2).Phi();
	else
		Phi2W_CM = (TMath::Pi() + boosted1P4.Phi()) - (v1+v2).Phi();

	if(Phi2W_CM > TMath::Pi())
		Phi2W_CM = 2*TMath::Pi() - Phi2W_CM;

	if(Phi2W_CM < -TMath::Pi())
		Phi2W_CM = -2*TMath::Pi() - Phi2W_CM;

	std::vector<double> PhiW_CM;
	PhiW_CM.push_back(Phi1W_CM);
	PhiW_CM.push_back(Phi2W_CM);

	return PhiW_CM;

}
#endif // #ifdef treeAnalyser_cxx
