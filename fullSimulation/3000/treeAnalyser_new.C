#define treeAnalyser_cxx
#include "treeAnalyser.h"

#include <cmath>

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

void treeAnalyser::Loop(double cs = 8.093, TString R = "1.2", Bool_t myjets = false)
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

   if (cs == 5.767 )
     channel = "BP23";
   if (cs == 1.678 )
     channel = "HP17";
   if (cs == 1.506  )
     channel = "HP20";
   if (cs == 1.775 )
    channel = "HP3";
   if (cs == 8672 )
    channel = "qqlv";
   if (cs == 3180 )
    channel = "qqll";
   if (cs == 1664.9796 )
    channel = "ll";
   if (cs == 902 )
    channel = "qqqq";
   if (cs == 20.4 )
    channel = "qqlvlv";
   if (cs == 148 )
    channel = "qqqqlv";
   if (cs == 96.8 )
    channel = "qqlvvv";
   if (cs == 2333.5039 )
    channel = "qqvv";

  cout << "Analysing " << channel << " sample..." << endl;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t numberOfEntries = nentries;
   if(channel == "qqlv")
    numberOfEntries -= 3;

   Double_t luminosity = 4000;

   TCanvas c1("c1", "", 200, 10, 600, 400);

   // book histograms
   TH1 *h_mqqTrue = new TH1F("mqqTrue", "", 100, 0.0, 200.0);
   TH1 *h_jetsMass = new TH1F("WhadMass", "", 50, 0.0, 200.0);
   TH1 *h_lepNuMass = new TH1F("WlepMass", "", 400, 0.0, 1600.0);
   TH1 *h_jetsEnergy = new TH1F("jetsEnergy", "", 100, 0.0, 2000.0);
   TH1 *h_jetsTheta = new TH1F("jetsTheta", "", 175, 0.0, 3.5);
   TH1 *h_jetDeltaTheta = new TH1F("jetDeltaTheta", "", 80, -3.15, 3.15);
   TH1 *h_jetDeltaPhi = new TH1F("jetDeltaPhi", "", 100, -3.15, 3.15);
   TH1 *h_jetPt = new TH1F("jetPt", "", 100, 0.0, 2000.0);
   TH1 *h_lepEnergy = new TH1F("lepEnergy", "", 100, 0.0, 2000.0);
   TH1 *h_lepTheta = new TH1F("lepTheta", "", 175, 0.0, 3.5);
   TH1 *h_lepPt = new TH1F("lepPt", "", 100, 0.0, 2000.0);
   TH1 *h_met = new TH1F("met", "", 140, 0.0, 1400.0);
   TH1 *h_missingMass = new TH1F("missingMass", "", 160, 0.0, 3100.0);
   TH1 *h_EFlow = new TH1F("EFlow", "", 100, 0.0, 200.0);
   TH1 *h_jetM = new TH1F("jetM", "", 50, 0.0, 200.0);
   TH1 *h_nPFOs = new TH1F("nPFOs", "", 50, 0.0, 200.0);
   TH1 *h_nIsoPhotons = new TH1F("nIsoPhotons", "", 50, 0.0, 50.0);
 	TH1 *h_isoPhotonEnergy = new TH1F("isoPhotonEnergy", "", 50, 0.0, 100.0);

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

   TFile *outputFile;
   if(myjets)
    outputFile = new TFile("./BDT/inputs/myjets/R" + Rname.ReplaceAll(".","") + "/" + channel + "_DataPreselected.root","RECREATE");
   else
    outputFile  = new TFile("./BDT/inputs/R" + Rname.ReplaceAll(".","") + "/" + channel + "_DataPreselected.root","RECREATE");

   if(!outputFile)
    cout << "WARNING: Output file couldn't be opened!" << endl;

   TTree *event = new TTree("event","Events after preselection");

   Int_t Ievt;
 	 Float_t weight;
 	 Float_t crossSection;
   Double_t jetR;
   Double_t Emin;
 	 char *sampleName;

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
 	 vector<float> jetM;
 	 Float_t M_inv_Wlep;
   Int_t nPFOs;

 	event->Branch("Ievt",&Ievt);
 	event->Branch("weight",&weight);
 	event->Branch("crossSection",&crossSection);
 	//event->Branch("sampleName",&sampleName);

 	event->Branch("jetsM_inv",&jetsM_inv);
 	event->Branch("jetsEnergy",&jetsEnergy);
 	event->Branch("jetsTheta",&jetsTheta);
 	event->Branch("leptonEnergy",&leptonEnergy);
 	event->Branch("leptonTheta",&leptonTheta);
 	event->Branch("leptonPt",&leptonPt);
 	event->Branch("jetDeltaTheta",&jetDeltaTheta);
 	event->Branch("jetDeltaPhi",&jetDeltaPhi);
 	event->Branch("EFsum",&EFsum);
 	event->Branch("MET",&MET);
 	event->Branch("missingMass",&missingMass);
 	event->Branch("jet1Theta",&jet1Theta);
 	event->Branch("jet2Theta",&jet2Theta);
 	event->Branch("jet1Pt",&jet1Pt);
 	event->Branch("jet2Pt",&jet2Pt);
 	event->Branch("jet1E",&jet1E);
 	event->Branch("jet2E",&jet2E);
 	event->Branch("jetM",&jetM);
 	event->Branch("M_inv_Wlep",&M_inv_Wlep);


   weight = cs*luminosity/numberOfEntries;
   crossSection = cs;
   jetR = R.Atof();
   Emin = e_min;

   int addEnergy      = 0;
   int noPhotons      = 0;
   int emptyPFOs      = 0;
   int matchedLeptons = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(PFOnoIso_n < 2)
        continue;
      if(PFOs_n==0)
        emptyPFOs++;


      // if(lep_n != 1) continue;

      TLorentzVector jet1P4, jet2P4, lepP4, missingP4, Whad, Wlep;

      if(!myjets) {

        jet1P4.SetPtEtaPhiE(jet_vlc_R10_pt->at(0), -1*log(tan(jet_vlc_R10_theta->at(0)/2)),jet_vlc_R10_phi->at(0),jet_vlc_R10_e->at(0));
        jet2P4.SetPtEtaPhiE(jet_vlc_R10_pt->at(1), -1*log(tan(jet_vlc_R10_theta->at(1)/2)),jet_vlc_R10_phi->at(1),jet_vlc_R10_e->at(1));

        if (R == "0.6") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R06_pt->at(0), -1*log(tan(jet_vlc_R06_theta->at(0)/2)),jet_vlc_R06_phi->at(0),jet_vlc_R06_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R06_pt->at(1), -1*log(tan(jet_vlc_R06_theta->at(1)/2)),jet_vlc_R06_phi->at(1),jet_vlc_R06_e->at(1));
        }
        if (R == "0.7") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R07_pt->at(0), -1*log(tan(jet_vlc_R07_theta->at(0)/2)),jet_vlc_R07_phi->at(0),jet_vlc_R07_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R07_pt->at(1), -1*log(tan(jet_vlc_R07_theta->at(1)/2)),jet_vlc_R07_phi->at(1),jet_vlc_R07_e->at(1));
        }
        if (R == "0.8") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R08_pt->at(0), -1*log(tan(jet_vlc_R08_theta->at(0)/2)),jet_vlc_R08_phi->at(0),jet_vlc_R08_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R08_pt->at(1), -1*log(tan(jet_vlc_R08_theta->at(1)/2)),jet_vlc_R08_phi->at(1),jet_vlc_R08_e->at(1));
        }
        if (R == "0.9") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R09_pt->at(0), -1*log(tan(jet_vlc_R09_theta->at(0)/2)),jet_vlc_R09_phi->at(0),jet_vlc_R09_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R09_pt->at(1), -1*log(tan(jet_vlc_R09_theta->at(1)/2)),jet_vlc_R09_phi->at(1),jet_vlc_R09_e->at(1));
        }
        if (R == "1.2") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R12_pt->at(0), -1*log(tan(jet_vlc_R12_theta->at(0)/2)),jet_vlc_R12_phi->at(0),jet_vlc_R12_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R12_pt->at(1), -1*log(tan(jet_vlc_R12_theta->at(1)/2)),jet_vlc_R12_phi->at(1),jet_vlc_R12_e->at(1));
        }
        if (R == "1.5") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R15_pt->at(0), -1*log(tan(jet_vlc_R15_theta->at(0)/2)),jet_vlc_R15_phi->at(0),jet_vlc_R15_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R15_pt->at(1), -1*log(tan(jet_vlc_R15_theta->at(1)/2)),jet_vlc_R15_phi->at(1),jet_vlc_R15_e->at(1));
        }
      }
      else {
        jet1P4.SetPxPyPzE(jet_Px[0], jet_Py[0], jet_Pz[0], jet_E[0]);
        jet2P4.SetPxPyPzE(jet_Px[1], jet_Py[1], jet_Pz[1], jet_E[1]);
      }

      if(lep_n != 0)
        lepP4.SetPtEtaPhiE(lep_pt->at(0),-1*log(tan(lep_theta->at(0)/2)),lep_phi->at(0),lep_e->at(0));

      Whad = jet1P4 + jet2P4;

      //if(jet1P4.Pt() < 20 || jet2P4.Pt() < 20)
      //  continue;

/*
      missingP4 = lepP4 + Whad;
      missingP4 *= -1.;
      TVector3 missP = missingP4.Vect();
      //missingP4.SetPxPyPzE(missP.Px(), missP.Py(), missP.Pz(), missP.Mag()); // set mass of missing fourvector to zero
*/
      TLorentzVector mc_q1, mc_q2, mc_lep;
      // generator-level (for qqlv ONLY for now)
      for(int i=0; i<mc_n; i++)
      {
        if(i < 15 && fabs(mc_type->at(i)) <= 7 && fabs(mc_type->at(i+1)) <= 7)
        {
          mc_q1.SetPtEtaPhiE(mc_pt->at(i), -log(tan(mc_theta->at(i) / 2.)), mc_phi->at(i), mc_e->at(i));
          mc_q2.SetPtEtaPhiE(mc_pt->at(i+1), -log(tan(mc_theta->at(i+1) / 2.)), mc_phi->at(i+1), mc_e->at(i+1));
        }
        if( i < 12 && (fabs(mc_type->at(i)) == 11 || fabs(mc_type->at(i)) == 13 || fabs(mc_type->at(i)) == 15) )
          mc_lep.SetPtEtaPhiE(mc_pt->at(i), -log(tan(mc_theta->at(i) / 2.)), mc_phi->at(i), mc_e->at(i));
        if (i==15) break;
      }

      double R = pow(sin(lepP4.Theta()-mc_lep.Theta()),2)*pow(lepP4.Theta()-mc_lep.Theta(), 2)+pow(lepP4.Phi()-mc_lep.Phi(), 2);
      if(R < 0.05) matchedLeptons++;
      // else continue;


      missingP4.SetPxPyPzE(0.,0.,0.,3000.);
      missingP4 -= Whad + lepP4;

      // calculate angles of one of the jets in the CMS system of W
      Double_t ThetaJetW_CM, PhiJetW_CM;
      ThetaJetW_CM = GetThetaInW_CMS(jet1P4, jet2P4).at(0);
      PhiJetW_CM = GetPhiInW_CMS(jet1P4, jet2P4).at(0);

/*      TLorentzVector boosted1P4 = jet1P4;
    	TVector3 beta = -(jet1P4+jet2P4).BoostVector();
    	boosted1P4.Boost(beta);

    	double Theta1W_CM = boosted1P4.Theta() - (v1+v2).Theta();
*/
      if ( TMath::IsNaN(ThetaJetW_CM) || TMath::IsNaN(PhiJetW_CM) ) {
        //cout << jentry << ": " << jet_Px[0].Pt() << " " << jet_Px[0].Theta() << " " << jet_Px[0].Phi() << " " << jet_Px[0].E() << endl;
        cout << jentry << ": " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << endl;
        continue;
      }

      int isoPhotons = 0;
      double EtotPFOs = 0;
      TLorentzVector EFlowSum;
      EFlowSum.SetPxPyPzE(0.,0.,0.,0.);

      vector<TLorentzVector> isolatedPhotonsCollection;
/*      for(int j=0; j<photon_n; j++) {
        double Econe = 0;
        double pTcone = 0;
        TLorentzVector photon;
        photon.SetPtEtaPhiE(photon_pt->at(j),-1*log(tan(photon_theta->at(j)/2)),photon_phi->at(j),photon_e->at(j));
        TVector3 p = photon.Vect();
        for(int i=0; i<PFOs_n; i++){
          //EPFOs+=PFOs_e->at(i);
          if(PFOs_pt->at(i) == photon_pt->at(j) && PFOs_theta->at(i) == photon_theta->at(j) && PFOs_phi->at(i) == photon_phi->at(j) && PFOs_e->at(i) == photon_e->at(j)) continue;
          TLorentzVector PFO_i;
          PFO_i.SetPtEtaPhiE(PFOs_pt->at(i),-1*log(tan(PFOs_theta->at(i)/2)),PFOs_phi->at(i),PFOs_e->at(i));

          double R = pow(sin(photon_theta->at(j)-PFOs_theta->at(i)),2)*pow(photon_theta->at(j)-PFOs_theta->at(i), 2)+pow(photon_phi->at(j)-PFOs_phi->at(i), 2);
          if(R<=0.1){
            pTcone += PFO_i.Pt();
          }
        }

        //if(Econe < 20)
        //  isolatedPhotonsCollection.push_back(photon);
        if(pTcone/photon_pt->at(j) <= 0.2)
          isolatedPhotonsCollection.push_back(photon);
      }
*/
      // ISOLATED PHOTON FINDER (UP-TO-DATE)

      for(int j=0; j<PFOnoIso_n; j++) {
        double Econe = 0;
        double pTcone = 0;
        TLorentzVector photon;
        if(PFOnoIso_type->at(j) == 22)
          photon.SetPtEtaPhiE(PFOnoIso_pt->at(j),-1*log(tan(PFOnoIso_theta->at(j)/2)),PFOnoIso_phi->at(j),PFOnoIso_e->at(j));
        else
          continue;
        TVector3 p = photon.Vect();
        for(int i=0; i<PFOs_n; i++){
          //EPFOs+=PFOs_e->at(i);
          if(PFOs_pt->at(i) == PFOnoIso_pt->at(j) && PFOs_theta->at(i) == PFOnoIso_theta->at(j) && PFOs_phi->at(i) == PFOnoIso_phi->at(j) && PFOs_e->at(i) == PFOnoIso_e->at(j)) continue;
          TLorentzVector PFO_i;
          PFO_i.SetPtEtaPhiE(PFOs_pt->at(i),-1*log(tan(PFOs_theta->at(i)/2)),PFOs_phi->at(i),PFOs_e->at(i));

          double R = pow(sin(PFOnoIso_theta->at(j)-PFOs_theta->at(i)),2)*pow(PFOnoIso_theta->at(j)-PFOs_theta->at(i), 2)+pow(PFOnoIso_phi->at(j)-PFOs_phi->at(i), 2);
          if(R<=0.1){
            pTcone += PFO_i.Pt();
          }
        }

        //if(Econe < 20)
        //  isolatedPhotonsCollection.push_back(photon);
        if(pTcone/PFOnoIso_pt->at(j) <= 0.2)
          isolatedPhotonsCollection.push_back(photon);
      }

      //cout << jentry << " " << isolatedPhotonsCollection.size() << endl;

      //cout << jentry << " " << matchedPFOs << " " << photonPFOs << endl;

/*
      for(int i=0; i<PFOs_n; i++){
        TLorentzVector PFO_i;
        PFO_i.SetPtEtaPhiE(PFOs_pt->at(i),-1*log(tan(PFOs_theta->at(i)/2)),PFOs_phi->at(i),PFOs_e->at(i));
        EtotPFOs += PFO_i.E();
        //EtotPFOs += PFOs_e->at(i);
        EFlowSum += PFO_i;

        if (PFOs_type->at(i) == 22) {
          if(PFOs_e->at(i) > 5)
            EFlowSum -= PFO_i;
          if(PFOs_e->at(i) > 10){
            isoPhotons++;
            //cout << jentry << " " << PFOs_type->at(i) << " " << PFO_i.E() << endl;
          }
        }
      }
*/

      //cout << EFlowSum.E() << endl;

      for (int i=0; i<isolatedPhotonsCollection.size(); i++) {
        //EFlowSum -= isolatedPhotonsCollection.at(i);
        if(isolatedPhotonsCollection.at(i).E() > 10)
          isoPhotons++;
        //if(EFlowSum.E() < 0 && isolatedPhotonsCollection.at(i).E() > 10)
          //cout << jentry << " " << isolatedPhotonsCollection.at(i).E() << endl;
        h_isoPhotonEnergy->Fill( isolatedPhotonsCollection.at(i).E() );
      }

      h_nIsoPhotons->Fill( isolatedPhotonsCollection.size() );

      //cout << EFlowSum.E() << endl;


      if(isoPhotons != 0) {
        noPhotons++;
        //continue;
  		}

      for(int i=0; i<PFOnoIso_n; i++){
        //EPFOs+=PFOnoIso_e->at(i);
        TLorentzVector PFO_i;
        PFO_i.SetPtEtaPhiE(PFOnoIso_pt->at(i),-1*log(tan(PFOnoIso_theta->at(i)/2)),PFOnoIso_phi->at(i),PFOnoIso_e->at(i));
        EFlowSum += PFO_i;
      }

      EtotPFOs -= Whad.E() + lepP4.E();
      EFlowSum -= Whad;

      h_EFlow->Fill(EFlowSum.Pt());

      int nChLowPt = 0;
  		int nChHighPt = 0;
  		int nNeuLowPt = 0;
  		int nNeuHighPt = 0;
  		int nPhLowPt = 0;
  		int nPhHighPt = 0;

      for(int i=0; i<PFOs_n; i++) {

        //cout << PFOs_charge->at(i) << " " << fabs(PFOs_charge->at(i)) << endl;

        if( PFOs_type->at(i)==22 ) {
          if( PFOs_pt->at(i)<0.75 ) {h_phoLowPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries); }
          else if( PFOs_pt->at(i)<4 ) h_phoMedPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);
          else {h_phoHighPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries); }
          if(PFOs_pt->at(i) > 1 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nPhLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nPhHighPt++;
          h_phoPt->Fill(PFOs_pt->at(i), 1. / numberOfEntries);
          if(PFOs_pt->at(i)>2) {h_phoThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
        }

        if( fabs(PFOs_type->at(i))>=111 && fabs(PFOs_charge->at(i)) < 1. ) {
          if( PFOs_pt->at(i)<0.75 ){ h_nhLowPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries); }
          else if( PFOs_pt->at(i)<8 ) h_nhMedPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);
          else {h_nhHighPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
          if(PFOs_pt->at(i) > 1.5 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nNeuLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nNeuHighPt++;
          h_nhPt->Fill(PFOs_pt->at(i), 1. / numberOfEntries);
          if(PFOs_pt->at(i)>2) {h_nhThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
        }

        if( fabs(PFOs_charge->at(i)) > 0. ) {
          if( PFOs_pt->at(i)<0.75 ) {h_chLowPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
          else if( PFOs_pt->at(i)<4 ) h_chMedPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);
          else {h_chHighPtTheta->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
          if(PFOs_pt->at(i) > 1 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nChLowPt++;
          if(PFOs_pt->at(i) > 2 && fabs(-1*log(tan(PFOs_theta->at(i)/2.))) < 2.4 ) nChHighPt++;
          h_chPt->Fill(PFOs_pt->at(i), 1. / numberOfEntries);
          if(PFOs_pt->at(i)>2) {h_chThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries); h_allThetaPartial->Fill(PFOs_theta->at(i), 1. / numberOfEntries);}
        }

      }
      h_phoLowPt_nPFOs->Fill(nPhLowPt, 1. / numberOfEntries);
      h_phoHighPt_nPFOs->Fill(nPhHighPt, 1. / numberOfEntries);
      h_nhLowPt_nPFOs->Fill(nNeuLowPt, 1. / numberOfEntries);
      h_nhHighPt_nPFOs->Fill(nNeuHighPt, 1. / numberOfEntries);
      h_chLowPt_nPFOs->Fill(nChLowPt, 1. / numberOfEntries);
      h_chHighPt_nPFOs->Fill(nChHighPt, 1. / numberOfEntries);

      int nAllLowPt = nNeuLowPt + nPhLowPt + nChLowPt;
  		int nAllHighPt = nNeuHighPt + nPhHighPt + nChHighPt;

  		h_allLowPt_nPFOs->Fill(nAllLowPt, 1. / numberOfEntries);
  		h_allHighPt_nPFOs->Fill(nAllHighPt, 1. / numberOfEntries);


      if(EFlowSum.Pt() >= 20) {
        addEnergy++;
        //continue;
  		}

      ///////////////// CUTS ///////////////////////////
/*
      if( Whad.Theta() < 0.2 || Whad.Theta() > (TMath::Pi() - 0.2) )
        continue;
      //if( Whad.Theta() < 0.25 || Whad.Theta() > (TMath::Pi() - 0.25) )
        //continue;

      //if( ( jet1P4.Theta() < 0.25 || jet1P4.Theta() > (TMath::Pi() - 0.25) ) || ( jet2P4.Theta() < 0.25 || jet2P4.Theta() > (TMath::Pi() - 0.25) ) )
      //  continue;

      if( Whad.M() < 3 )
        continue;

      //if( ThetaJetW_CM < -2. || ThetaJetW_CM > 2. )
      //  continue;

      if( Whad.E() > 750 )
        continue;
      //if( Whad.E() > 700 )
        //continue;

      if(lepP4.E() > 600)
        continue;

      if(lepP4.Pt() > 550 || lepP4.Pt() < 2)
        continue;

      if( lepP4.Theta() > (TMath::Pi() - 0.25) || lepP4.Theta() < 0.25 )
        continue;

      //if (missingP4.M() < 350)
      //  continue;
      if (missingP4.M() < 400)
        continue;
*/
      // if(lepP4.Pt() > 800 || lepP4.Pt() < 150)
        // continue;

      //////////////// END OF CUTS /////////////////////

      jetM.clear();

      h_mqqTrue->Fill( (mc_q1+mc_q2).M() );
      h_jetsMass->Fill( Whad.M() );
      h_lepNuMass->Fill( (lepP4+missingP4).M() );
      h_jetsEnergy->Fill( Whad.E() );
      h_jetsTheta->Fill(Whad.Theta());
      h_jetDeltaTheta->Fill(ThetaJetW_CM);
      h_jetDeltaPhi->Fill(PhiJetW_CM);
      h_jetPt->Fill(jet1P4.Pt());
      h_jetPt->Fill(jet2P4.Pt());
      if(lep_n == 1) {
        h_lepEnergy->Fill( lepP4.E() );
        h_lepTheta->Fill( lepP4.Theta() );
        h_lepPt->Fill( lepP4.Pt() );
      }
      h_met->Fill( missingP4.Pt() );
      h_missingMass->Fill( missingP4.M() );
      h_jetM->Fill( jet1P4.M() );
      h_jetM->Fill( jet2P4.M() );
      h_nPFOs->Fill( PFOs_n );

      jetsM_inv = (Whad).M();
      M_inv_Wlep = (lepP4+missingP4).M();
      jetsEnergy = (Whad).E();
      jetsTheta = Whad.Theta();
      jet1Theta = jet1P4.Theta();
      jet2Theta = jet2P4.Theta();
      jet1Pt = jet1P4.Pt();
      jet2Pt = jet2P4.Pt();
      jet1E = jet1P4.E();
      jet2E = jet2P4.E();
      leptonEnergy = lepP4.E();
      leptonTheta = lepP4.Theta();
      leptonPt = lepP4.Pt();
      jetDeltaTheta = ThetaJetW_CM;
      jetDeltaPhi = PhiJetW_CM;
      EFsum = EFlowSum.Pt();
      MET = missingP4.Pt();
      missingMass = missingP4.M();
      jetM.push_back(jet1P4.M());
      jetM.push_back(jet2P4.M());

      Ievt = jentry;
  		//sampleName = channel;

      //if ( TMath::IsNaN(jetDeltaTheta) || TMath::IsNaN(jetDeltaPhi) )
        //cout << jentry << ": " << jet_Px[0].Pt() << " " << jet_Px[0].Theta() << " " << jet_Px[0].Phi() << " " << jet_Px[0].E() << endl;
        //cout << jentry << ": " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << endl;

      event->Fill();

   } // end of loop over events

   outputFile->Write();
   outputFile->Close();

   h_mqqTrue->Scale( crossSection*luminosity/numberOfEntries );
   h_jetsMass->Scale( crossSection*luminosity/numberOfEntries );
   h_lepNuMass->Scale( crossSection*luminosity/numberOfEntries );
   h_jetsEnergy->Scale( crossSection*luminosity/numberOfEntries );
   h_jetsTheta->Scale(crossSection*luminosity/numberOfEntries);
   h_jetDeltaTheta->Scale(crossSection*luminosity/numberOfEntries);
   h_jetDeltaPhi->Scale(crossSection*luminosity/numberOfEntries);
   h_jetPt->Scale( crossSection*luminosity/numberOfEntries );
   h_lepEnergy->Scale( crossSection*luminosity/numberOfEntries );
   h_lepTheta->Scale( crossSection*luminosity/numberOfEntries );
   h_lepPt->Scale( crossSection*luminosity/numberOfEntries );
   h_met->Scale( crossSection*luminosity/numberOfEntries );
   h_missingMass->Scale( crossSection*luminosity/numberOfEntries );
   h_jetM->Scale( crossSection*luminosity/numberOfEntries );
   h_nPFOs->Scale( crossSection*luminosity/numberOfEntries );
   h_nIsoPhotons->Scale( crossSection*luminosity/numberOfEntries );
   h_isoPhotonEnergy->Scale( crossSection*luminosity/numberOfEntries );

   h_mqqTrue->SetXTitle("M_{qq}");
   h_jetsMass->SetXTitle("M_{jj}");
   h_lepNuMass->SetXTitle("M_{#ell - miss}");
   h_jetsEnergy->SetXTitle("E_{j1} + E_{j2}");
   h_jetsTheta->SetXTitle("#theta_{W(*)}");
   h_jetDeltaTheta->SetXTitle("#Delta#theta_{W(*)j}");
   h_jetDeltaPhi->SetXTitle("#Delta#phi_{W(*)j}");
   h_jetPt->SetXTitle("p_{T}^{j}");
   h_lepEnergy->SetXTitle("E_{l}");
   h_lepTheta->SetXTitle("#theta_{l}");
   h_lepPt->SetXTitle("p_{T}^{l}");
   h_met->SetXTitle("MET");
   h_missingMass->SetXTitle("M_{miss}");
   h_jetM->SetXTitle("M_{jet}");
   h_nPFOs->SetXTitle("N_{PFO}");
   h_nIsoPhotons->SetXTitle("N_{#gamma}^{iso}");
 	 h_isoPhotonEnergy->SetXTitle("E_{#gamma}^{iso}");

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
/*
   jetsMass->Draw("hist");
   c1.Print("./plots/WhadMass.png");
   lepNuMass->Draw("hist");
   c1.Print("./plots/WlepMass.png");
   jetsEnergy->Draw("hist");
   c1.Print("./plots/WhadEnergy.png");
   jetsTheta->Draw("hist");
   c1.Print("./plots/WlepTheta.png");
   //jetDeltaTheta->Draw("hist");
   //c1.Print("./plots/WhadJetTheta.png");
   //jetDeltaPhi->Draw("hist");
   //c1.Print("./plots/WhadJetPhi.png");
   lepEnergy->Draw("hist");
   c1.Print("./plots/lepEnergy.png");
   lepTheta->Draw("hist");
   c1.Print("./plots/lepTheta.png");
   lepPt->Draw("hist");
   c1.Print("./plots/lepPt.png");
   met->Draw("hist");
   c1.Print("./plots/met.png");
   missingMass->Draw("hist");
   c1.Print("./plots/missingMass.png");
*/

   //EFlow->Draw();
   //c1.Print("./plots/EFlow.png");

   // save list to a file
   TFile f("./histoFiles/plotsBeforePreselectionFullSim_" + channel + ".root", "recreate");
   hList.Write();
   f.Close();

   Double_t efficiency = h_jetsMass->GetEntries()/numberOfEntries;
   Double_t events = luminosity*crossSection;
   Int_t ev_after = efficiency*events;
   //table
   /*
   fstream log;
   log.open("./table.txt", fstream::out | fstream::app);
   if (log.is_open()) {
     log << fixed << setprecision(7) << channel << " " << events << " "
     << ev_after << " " << efficiency << " " << h_jetsMass->GetEntries() << endl;
     log << endl;
     log.close();
   }
   */

   double matchedLeptonsDoub = matchedLeptons;

   cout << "Tot. presel. eff. for " << channel << " sample: " << h_jetsMass->GetEntries()/numberOfEntries << endl;
   cout << "Lepton matching eff. " << matchedLeptonsDoub/numberOfEntries << endl;
   cout << "Rejected events with too high EFlow En.: " << addEnergy << endl;
 	 cout << "Rejected events with too many high-energetic photons: " << noPhotons << endl;
   cout << endl;

}
