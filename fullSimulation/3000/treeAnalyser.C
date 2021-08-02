#define treeAnalyser_cxx
#include "treeAnalyser.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void treeAnalyser::Loop(double crossSection = 4.213, TString R = "1.2", Bool_t myjets = false)
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

   if (crossSection == 5.767 )
     channel = "BP23";
   if (crossSection == 1.678 )
     channel = "HP17";
   if (crossSection == 1.506  )
     channel = "HP20";
   if (crossSection == 1.775 )
    channel = "HP3";
   if (crossSection == 8672 )
    channel = "qqlv";
   if (crossSection == 3180 )
    channel = "qqll";
   if (crossSection == 1664.9796 )
    channel = "ll";
   if (crossSection == 902 )
    channel = "qqqq";
   if (crossSection == 20.4 )
    channel = "qqlvlv";
   if (crossSection == 148 )
    channel = "qqqqlv";
   if (crossSection == 96.8 )
    channel = "qqlvvv";
   if (crossSection == 2333.5039 )
    channel = "qqvv";
   if (crossSection == 1269 )
    channel = "qq";

  cout << "Analysing " << channel << " sample..." << endl;

   Long64_t nentries = fChain->GetEntriesFast();

   Double_t luminosity = 4000;

   TCanvas c1("c1", "", 200, 10, 600, 400);

   // book histograms
   TH1 *jetsMass = new TH1F("WhadMass", "", 50, 0.0, 200.0);
   TH1 *lepNuMass = new TH1F("WlepMass", "", 400, 0.0, 3100.0);
   TH1 *jetsEnergy = new TH1F("jetsEnergy", "", 100, 0.0, 2000.0);
   TH1 *jetsTheta = new TH1F("jetsTheta", "", 175, 0.0, 3.5);
   TH1 *jetDeltaTheta = new TH1F("jetDeltaTheta", "", 80, -3.15, 3.15);
   TH1 *jetDeltaPhi = new TH1F("jetDeltaPhi", "", 100, -3.15, 3.15);
   TH1 *jetPt = new TH1F("jetPt", "", 100, 0.0, 2000.0);
   TH1 *lepEnergy = new TH1F("lepEnergy", "", 100, 0.0, 2000.0);
   TH1 *lepTheta = new TH1F("lepTheta", "", 175, 0.0, 3.5);
   TH1 *lepPt = new TH1F("lepPt", "", 100, 0.0, 2000.0);
   TH1 *met = new TH1F("met", "", 140, 0.0, 1400.0);
   TH1 *missingMass = new TH1F("missingMass", "", 160, 0.0, 3100.0);
   TH1 *EFlow = new TH1F("EFlow", "", 100, 0.0, 200.0);

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

   if(!outputFile){
    cout << endl;
    cout << "WARNING: Output file couldn't be opened!" << endl;
    cout << endl;
   }

   TTree *event = new TTree("event","Events after preselection");

   // Tree header

 	 //char mySampleName[channel.size() + 1];
 	 //strcpy(mySampleName, (channel).c_str());

   struct event_head {
     Int_t Ievt;
     Float_t weight;
 	   Float_t crossSection;
     Double_t jetR;
     Double_t Emin;
     //char *sampleName;
     TString sampleName;
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

   event->Branch( "header",&myheader, "Ievt/I:w/F:crossSection/F:jetR/F:Emin/F:sampleName/C" );
   event->Branch( "data",&mydata, "jetsM_inv/F:jetsEnergy:jetsTheta:leptonEnergy:leptonTheta:leptonPt:jetDeltaTheta:jetDeltaPhi:EFsum:MET:missingMass:jet1Theta:jet2Theta:jet1Pt:jet2Pt:jet1E:jet2E:M_inv_Wlep" );

   double meanCS = crossSection;
/*
   if(crossSection < 10.){
     //meanCS = 2.9878; // all signal samples
     meanCS = 1.653; // off-shell W mean CS
     if(channel == "BP21" || channel == "BP23")
        meanCS = 4.99; // on-shell W mean CS
   }
*/
   myheader.weight = meanCS*luminosity/nentries;
   //if(crossSection < 10.) myheader.weight = meanCS*luminosity/50000;
   //else myheader.weight = meanCS*luminosity/nentries;
   myheader.crossSection = crossSection;
   myheader.jetR = R.Atof();
   myheader.Emin = e_min;

   int addEnergy      = 0;
   int noPhotons      = 0;
   int noJets         = 0;
   int emptyPFOs      = 0;
   int matchedLeptons = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(lep_n != 1) continue;

      if(PFOs_n==0) {
        emptyPFOs++;
        continue;
      }

      if(jet_vlc_R12_n==0){
        noJets++;
        continue;
      }


      TLorentzVector jet1P4, jet2P4, lepP4, missingP4, Whad, Wlep;

      if(!myjets) {

        jet1P4.SetPtEtaPhiE(jet_vlc_R12_pt->at(0), -1*log(tan(jet_vlc_R12_theta->at(0)/2)),jet_vlc_R12_phi->at(0),jet_vlc_R12_e->at(0));
        jet2P4.SetPtEtaPhiE(jet_vlc_R12_pt->at(1), -1*log(tan(jet_vlc_R12_theta->at(1)/2)),jet_vlc_R12_phi->at(1),jet_vlc_R12_e->at(1));

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
        if (R == "1.0") {
            jet1P4.SetPtEtaPhiE(jet_vlc_R10_pt->at(0), -1*log(tan(jet_vlc_R10_theta->at(0)/2)),jet_vlc_R10_phi->at(0),jet_vlc_R10_e->at(0));
            jet2P4.SetPtEtaPhiE(jet_vlc_R10_pt->at(1), -1*log(tan(jet_vlc_R10_theta->at(1)/2)),jet_vlc_R10_phi->at(1),jet_vlc_R10_e->at(1));
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

/*
      missingP4 = lepP4 + Whad;
      missingP4 *= -1.;
      TVector3 missP = missingP4.Vect();
      //missingP4.SetPxPyPzE(missP.Px(), missP.Py(), missP.Pz(), missP.Mag()); // set mass of missing fourvector to zero
*/

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
        cout << "WARNING! NaN in " << jentry << " entry: " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << endl;
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
      }

      //cout << EFlowSum.E() << endl;


      if(isoPhotons != 0) {
        noPhotons++;
        continue;
  		}

      for(int i=0; i<PFOnoIso_n; i++){
        //EPFOs+=PFOnoIso_e->at(i);
        TLorentzVector PFO_i;
        PFO_i.SetPtEtaPhiE(PFOnoIso_pt->at(i),-1*log(tan(PFOnoIso_theta->at(i)/2)),PFOnoIso_phi->at(i),PFOnoIso_e->at(i));
        EFlowSum += PFO_i;
      }

      EtotPFOs -= Whad.E() + lepP4.E();
      EFlowSum -= Whad;

      EFlow->Fill(EFlowSum.Pt());


      if(EFlowSum.Pt() >= 20) {
        addEnergy++;
        continue;;
  		}

      ///////////////// CUTS ///////////////////////////
/*
      //if( ( jet1P4.Theta() < 0.15 || jet1P4.Theta() > (TMath::Pi() - 0.15) ) || ( jet2P4.Theta() < 0.15 || jet2P4.Theta() > (TMath::Pi() - 0.15) ) )
      //  continue;

      if( Whad.Theta() < 0.3 || Whad.Theta() > (TMath::Pi() - 0.3) )
        continue;

      //if ( fabs(ThetaJetW_CM) > (TMath::Pi() - 0.5) )
      //  continue;

      //if( Whad.Theta() < 0.15 || Whad.Theta() > (TMath::Pi() - 0.15) )
      //  continue;

      if( Whad.M() < 2)
        continue;
      //if( Whad.M() < 3 || Whad.M() > 150)
      //  continue;

      if( Whad.E() > 1300 )
        continue;

      if(lepP4.E() > 1000)
        continue;
      //if(lepP4.E() > 800)
      //  continue;

      if(lepP4.Pt() > 800)
        continue;

      if( lepP4.Theta() > (TMath::Pi() - 0.5) || lepP4.Theta() < 0.5 )
        continue;

      //if (missingP4.M() < 700)
      //  continue;

      //if ((lepP4+missingP4).M() < 1700)
      //  continue;
*/

  //////// fast simulation cuts

      if( Whad.Theta() < 0.3 || Whad.Theta() > (TMath::Pi() - 0.3) )
         continue;

       if( (Whad).M() < 3 )
         continue;

       if( (Whad).E() > 1300 )
         continue;

   ////////Cuts on leptons
       if(lepP4.E() > 1000)
         continue;

       if(lepP4.Pt() > 800)
         continue;

       if( 2*atan(exp(-1*lepP4.Eta())) > (TMath::Pi() - 0.5) || 2*atan(exp(-1*lepP4.Eta())) < 0.5 )
         continue;


      //////////////// END OF CUTS /////////////////////

      jetsMass->Fill( Whad.M() );
      lepNuMass->Fill( (lepP4+missingP4).M() );
      jetsEnergy->Fill( Whad.E() );
      jetsTheta->Fill(Whad.Theta());
      jetDeltaTheta->Fill(ThetaJetW_CM);
      jetDeltaPhi->Fill(PhiJetW_CM);
      jetPt->Fill(jet1P4.Pt());
      jetPt->Fill(jet2P4.Pt());
      lepEnergy->Fill( lepP4.E() );
      lepTheta->Fill( lepP4.Theta() );
      lepPt->Fill( lepP4.Pt() );
      met->Fill( missingP4.Pt() );
      missingMass->Fill( missingP4.M() );

      mydata.jetsM_inv = (Whad).M();
      mydata.M_inv_Wlep = (lepP4+missingP4).M();
      mydata.jetsEnergy = (Whad).E();
      mydata.jetsTheta = Whad.Theta();
      mydata.jet1Theta = jet1P4.Theta();
      mydata.jet2Theta = jet2P4.Theta();
      mydata.jet1Pt = jet1P4.Pt();
      mydata.jet2Pt = jet2P4.Pt();
      mydata.jet1E = jet1P4.E();
      mydata.jet2E = jet2P4.E();
      mydata.leptonEnergy = lepP4.E();
      mydata.leptonTheta = lepP4.Theta();
      mydata.leptonPt = lepP4.Pt();
      mydata.jetDeltaTheta = ThetaJetW_CM;
      mydata.jetDeltaPhi = PhiJetW_CM;
      mydata.EFsum = EFlowSum.Pt();
      mydata.MET = missingP4.Pt();
      mydata.missingMass = missingP4.M();

      myheader.Ievt = jentry;
  		myheader.sampleName = channel;

      //if ( TMath::IsNaN(mydata.jetDeltaTheta) || TMath::IsNaN(mydata.jetDeltaPhi) )
        //cout << jentry << ": " << jet_Px[0].Pt() << " " << jet_Px[0].Theta() << " " << jet_Px[0].Phi() << " " << jet_Px[0].E() << endl;
        //cout << jentry << ": " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << " " << jet_Px[1] << endl;

      event->Fill();

   } // end of loop over events

   outputFile->Write();
   outputFile->Close();

   //float numberOfEntries = jetsMass->GetEntries();

   jetsMass->Scale( crossSection*luminosity/nentries );
   lepNuMass->Scale( crossSection*luminosity/nentries );
   jetsEnergy->Scale( crossSection*luminosity/nentries );
   jetsTheta->Scale(crossSection*luminosity/nentries);
   jetDeltaTheta->Scale(crossSection*luminosity/nentries);
   jetDeltaPhi->Scale(crossSection*luminosity/nentries);
   jetPt->Scale( crossSection*luminosity/nentries );
   lepEnergy->Scale( crossSection*luminosity/nentries );
   lepTheta->Scale( crossSection*luminosity/nentries );
   lepPt->Scale( crossSection*luminosity/nentries );
   met->Scale( crossSection*luminosity/nentries );
   missingMass->Scale( crossSection*luminosity/nentries );

   jetsMass->SetXTitle("M_{jj}");
   lepNuMass->SetXTitle("M_{#ell - miss}");
   jetsEnergy->SetXTitle("E_{j1} + E_{j2}");
   jetsTheta->SetXTitle("#theta_{W(*)}");
   jetDeltaTheta->SetXTitle("#Delta#theta_{W(*)j}");
   jetDeltaPhi->SetXTitle("#Delta#phi_{W(*)j}");
   jetPt->SetXTitle("p_{T}^{j}");
   lepEnergy->SetXTitle("E_{l}");
   lepTheta->SetXTitle("#theta_{l}");
   lepPt->SetXTitle("p_{T}^{l}");
   met->SetXTitle("MET");
   missingMass->SetXTitle("M_{miss}");

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
   TFile f("./histoFiles/plotsAfterPreselectionFullSim_FastSimCuts_" + channel + ".root", "recreate");
   hList.Write();
   f.Close();

   Double_t efficiency = jetsMass->GetEntries()/nentries;
   Double_t events = luminosity*crossSection;
   Int_t ev_after = efficiency*events;
   //table
   fstream log;
   log.open("./table.txt", fstream::out | fstream::app);
   if (log.is_open()) {
     log << fixed << setprecision(7) << channel << " " << events << " "
     << ev_after << " " << efficiency << " " << jetsMass->GetEntries() << endl;
     log << endl;
     log.close();
   }

   Double_t photonEff = noPhotons;
   photonEff = 1. - photonEff / nentries;

/*
   fstream log2;
   log2.open("./photonCut.txt", fstream::out | fstream::app);
   if (log2.is_open()) {
     log2 << fixed << setprecision(7) << channel << " " << events << " "
     << ev_after << " " << efficiency << " " << jetsMass->GetEntries() << " " << noPhotons << " " << photonEff << endl;
     log2 << endl;
     log2.close();
   }
*/

   cout << "Tot. presel. eff. for " << channel << " sample: " << jetsMass->GetEntries()/nentries << endl;
   cout << "Rejected events with too high EFlow En.: " << addEnergy << endl;
   cout << "Rejected events with too many high-energetic photons: " << noPhotons << endl;
   cout << "Rejected events with 0 PFOs in event: " << emptyPFOs << endl;
   cout << "Rejected events with 0 jets in event: " << noJets << endl;
   cout << endl;

}
