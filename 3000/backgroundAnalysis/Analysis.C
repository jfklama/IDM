#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#endif

//------------------------------------------------------------------------------

TLorentzVector JetSmear(const TLorentzVector &Jet, double esmear, double msmear, double corr)
{

	TTimeStamp ttsmp;
	TRandom *jet_rn = NULL;

  if(!jet_rn) jet_rn = new TRandom(ttsmp.GetNanoSec()/1000);  // pseudo-random seed

  double r1 = jet_rn->Gaus();  // Default i.e. mean = 0, sigma = 1
  double r2 = jet_rn->Gaus();

  // Calculate generation parameters

   double phi = 0.5*asin(corr);

   double  sphi = sin(phi);
   double  cphi = cos(phi);


   double newE = (r1*cphi + r2*sphi)*esmear;
   double newM = (r1*sphi + r2*cphi)*msmear;

   // To avoid problems with negative smeared vales
   // change  (1+delta) to  exp(delta)

    newE = Jet.E() * exp(newE);   // instead of  = jetE * (1 + newE);
    newM = Jet.M() * exp(newM);

    if(newM > newE) newM=newE;

    double newP = sqrt(newE*newE-newM*newM)/Jet.P();

    TLorentzVector outJet;
    outJet.SetPxPyPzE(newP*Jet.Px(),newP*Jet.Py(),newP*Jet.Pz(),newE);

    return outJet;
}


//------------------------------------------------------------------------------

void Analysis(const char *channelFile, const char *fileCreate = "RECREATE", Double_t sigma = 1., Bool_t overlay = 1) {

  std::string channel = channelFile;
  std::string category;

  char inputFile[channel.size() + 1];
  if(overlay) {
    if( channel.find("_hphm_") != string::npos ) {
			strcpy(inputFile, ("/media/jfklama/108E10DD108E10DD/JFK/CLIC/IDM/rootFiles_withOverlay/" + channel + "_detResp.root").c_str()); // TightSelectedPFOs (CDR)
      category = "signal";
    }
    else {
			strcpy(inputFile, ("/media/jfklama/108E10DD108E10DD/JFK/CLIC/IDM/rootFiles_withOverlay/" + channel + "_detResp.root").c_str()); // TightSelectedPFOs (CDR)
      category = "background";
    }
  }
  else {
    if( channel.find("_hphm_") != string::npos ) {
			strcpy(inputFile, ("/media/jfklama/Filip_USB3/CLIC/3TeV/rootSamples_withOverlay_fromLXplus/" + channel + "_detResp.root").c_str()); // loose timing cuts
      category = "signal";
    }
    else {
			strcpy(inputFile, ("/media/jfklama/Filip_USB3/CLIC/3TeV/rootSamples_withOverlay_fromLXplus/" + channel + "_detResp.root").c_str()); // loose timing cuts
      category = "background";
    }
  }

  gSystem->Load("libDelphes");

  // Create chain of root trees
  TChain chain("Delphes");
  chain.Add(inputFile);

  //Create list of histograms
  TObjArray HList(0);
  HList.SetOwner(kTRUE);

  // Create object of class ExRootTreeReader
  ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
  Long64_t numberOfEntries = treeReader->GetEntries();

  // Define VLC param and energy correction
  Double_t BjetEcorr = 1;
  Double_t QjetEcorr = 1;
  std::string Rvalue = "12";
  //std::string Rvalue = "15";
  std::string bEcorr = std::to_string(BjetEcorr);
  std::string qEcorr = std::to_string(QjetEcorr);
  bEcorr.replace(1,1,"-");
  qEcorr.replace(1,1,"-");

  // Get pointers to branches used in this analysis
  TClonesArray *branchMuon = treeReader->UseBranch("Muon");
  TClonesArray *branchElectron = treeReader->UseBranch("Electron");
  TClonesArray *branchMET = treeReader->UseBranch("MissingET");
  //TClonesArray *branchJets = treeReader->UseBranch( ("VLCjetR" + Rvalue + "_inclusive").c_str() );
  TClonesArray *branchJets = treeReader->UseBranch( ("VLCjetR" + Rvalue + "N2").c_str() );
  TClonesArray *branchPhoton2 = treeReader->UseBranch("Photon");
  TClonesArray *branchCharged = treeReader->UseBranch("EFlowTrack");
  TClonesArray *branchNeutral = treeReader->UseBranch("EFlowNeutralHadron");
  TClonesArray *branchPhoton = treeReader->UseBranch("EFlowPhoton");
  Jet *jet;
  Electron *electron;
  Muon *muon;
  Photon *photon2;
  Track *charged;
  Tower *neutral;
  Tower *photon;

  //Create name variables for histos
  std::string jetsMassNameStr = "jetsMassR" + Rvalue + "_" + channel;
  std::string jetsEnergyNameStr = "jetsEnergyR" + Rvalue + "_" + channel;
  std::string jetsThetaNameStr = "jetsThetaR" + Rvalue + "_" + channel;
  std::string jetDeltaThetaNameStr = "jetDeltaThetaR" + Rvalue + "_" + channel;
  std::string jetDeltaPhiNameStr = "jetDeltaPhiR" + Rvalue + "_" + channel;
  std::string lepEnergyNameStr = "lepEnergyR" + Rvalue + "_" + channel;
  std::string lepThetaNameStr = "lepThetaR" + Rvalue + "_" + channel;
  std::string lepPtNameStr = "lepPtR" + Rvalue + "_" + channel;
  std::string metNameStr = "metR" + Rvalue + "_" + channel;
	std::string missingMassNameStr = "missingMassR" + Rvalue + "_" + channel;
	std::string EFlowNameStr = "EFlowR" + Rvalue + "_" + channel;
  char jetsMassName[jetsMassNameStr.size() + 1];
  char jetsEnergyName[jetsEnergyNameStr.size() + 1];
  char jetsThetaName[jetsThetaNameStr.size() + 1];
  char jetDeltaThetaName[jetDeltaThetaNameStr.size() + 1];
  char jetDeltaPhiName[jetDeltaPhiNameStr.size() + 1];
  char lepEnergyName[lepEnergyNameStr.size() + 1];
  char lepThetaName[lepThetaNameStr.size() + 1];
  char lepPtName[lepPtNameStr.size() + 1];
  char metName[metNameStr.size() + 1];
	char missingMassName[missingMassNameStr.size() + 1];
	char EFlowName[EFlowNameStr.size() + 1];
  strcpy(jetsMassName, (jetsMassNameStr).c_str());
  strcpy(jetsEnergyName, (jetsEnergyNameStr).c_str());
  strcpy(jetsThetaName, (jetsThetaNameStr).c_str());
  strcpy(jetDeltaThetaName, (jetDeltaThetaNameStr).c_str());
  strcpy(jetDeltaPhiName, (jetDeltaPhiNameStr).c_str());
  strcpy(lepEnergyName, (lepEnergyNameStr).c_str());
  strcpy(lepThetaName, (lepThetaNameStr).c_str());
  strcpy(lepPtName, (lepPtNameStr).c_str());
  strcpy(metName, (metNameStr).c_str());
	strcpy(missingMassName, (missingMassNameStr).c_str());
	strcpy(EFlowName, (EFlowNameStr).c_str());


  // Book histograms
  TCanvas c1("c1", "masa", 200, 10, 600, 400);
  TH1 *jetsMass = new TH1F(jetsMassName, "", 50, 0.0, 200.0);
  TH1 *jetsEnergy = new TH1F(jetsEnergyName, "", 100, 0.0, 2000.0);
  TH1 *jetsTheta = new TH1F(jetsThetaName, "", 175, 0.0, 3.5);
	TH1 *jetDeltaTheta = new TH1F(jetDeltaThetaName, "", 80, -3.15, 3.15);
  TH1 *jetDeltaPhi = new TH1F(jetDeltaPhiName, "", 100, -3.15, 3.15);
  TH1 *lepEnergy = new TH1F(lepEnergyName, "", 100, 0.0, 2000.0);
  TH1 *lepTheta = new TH1F(lepThetaName, "", 175, 0.0, 3.5);
  TH1 *lepPt = new TH1F(lepPtName, "", 100, 0.0, 2000.0);
  TH1 *met = new TH1F(metName, "", 140, 0.0, 1400.0);
	TH1 *missingMass = new TH1F(missingMassName, "", 160, 0.0, 3100.0);
	TH1 *EFlow = new TH1F(EFlowName, "", 160, 0.0, 3100.0);

  ///////////////////////
  //TREE
  ///////////////////////

  TFile *outputFile = new TFile(("~/FUW/CLIC/IDM/3000/backgroundAnalysis/inputsForBDT/" + channel + "DataPreselected.root").c_str(),"RECREATE");

  TTree *event = new TTree("event","Events after preselection");

  // Tree header

	 char mySampleName[channel.size() + 1];
	 strcpy(mySampleName, (channel).c_str());

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

    event->Branch( "header",&myheader, "Ievt/I:w/F:crossSection/F:sampleName/C" );
		event->Branch( "data",&mydata, "jetsM_inv/F:jetsEnergy:jetsTheta:leptonEnergy:leptonTheta:leptonPt:jetDeltaTheta:jetDeltaPhi:EFsum:MET:missingMass:jet1Theta:jet2Theta:jet1Pt:jet2Pt:jet1E:jet2E:M_inv_Wlep" );

		double meanCS = sigma;
/*
		if(category == "signal"){
			//meanCS = 2.266286913; // all signal samples
			meanCS = 1.925309947; // off-shell W mean CS
			//meanCS = 1.56389; // off-shell W mean CS for 3 full sim. scenarios
			if(channel.find("_BP21_") != string::npos || channel.find("_BP23_") != string::npos ||
				 channel.find("_HP1_") != string::npos || channel.find("_HP4_") != string::npos)
				 meanCS = 3.8859275; // on-shell W mean CS
				 //meanCS = 4.97247; // on-shell W mean CS for 2 full sim. scenarios
		}
*/
    myheader.weight = meanCS*4000/numberOfEntries;
		myheader.crossSection = sigma;

  Double_t events = sigma*4000;

	// vars to count events rejected by particular cuts
	int EFlow_cut = 0;
  int twoJets = 0;
  int oneLepton = 0;
  int isoPhotonCut = 0;
  int addEnergy = 0;
	int rejectedElectrons=0, rejectedMuons=0;

  ///////////////////////
  // Loop over all events
  ///////////////////////

  for(Int_t entry = 0; entry < numberOfEntries; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader->ReadEntry(entry);

  // Cut on no. of leptons
    if(branchMuon->GetEntries() > 0 && branchElectron->GetEntries() > 0) { //throw out events with both electrons and
      //cout << "2 leptons" << endl;                                       //muons
      continue;
		}
    if(branchMuon->GetEntries() > 1 || branchElectron->GetEntries() > 1) { //throw out events with more than 1 electron
      //cout << "2 leptons" << endl;                                       //or more than 1 muon
      continue;
		}
    if (branchElectron->GetEntries() == 0 && branchMuon->GetEntries() == 0) { //throw out events with no isolated leptons
      continue;
		}
//    if (branchPhoton2->GetEntries() != 0) //throw out events with isolated photons
//      continue;



//Cut on no. of jets
    //if(branchJets->GetEntries() != 1)
    //  continue;
    if(branchJets->GetEntries() != 2)
      continue;

    Jet *jet1 = (Jet*) branchJets->At(0);
    Jet *jet2 = (Jet*) branchJets->At(1);

		//TLorentzVector jetP4 = jet1->P4();
		TLorentzVector jet1P4 = jet1->P4();
		TLorentzVector jet2P4 = jet2->P4();
/*
    //smearing
    double mfac = 1.;
    double corr = 1.;
    double esmear = 0.02;  // For 3 TeV running (use 0.01 for 1.5 TeV)
    if(abs(jet1->P4().Eta())>0.76) esmear = 0.1;    // For 3 TeV running (use 0.05 for 1.5 TeV)
    jet1P4 = JetSmear(jet1->P4(), esmear, mfac*esmear, corr);

    esmear = 0.02;  // For 3 TeV running (use 0.01 for 1.5 TeV)
    if(abs(jet2->P4().Eta())>0.76) esmear = 0.1;    // For 3 TeV running (use 0.05 for 1.5 TeV)
    jet2P4 = JetSmear(jet2->P4(), esmear, mfac*esmear, corr);
*/
		//TLorentzVector jetP4 = jet1->P4() + jet2->P4();
		//Double_t jetTheta = 2*atan( exp(-1*jetP4.Eta()) );
		TLorentzVector jetP4 = jet1P4 + jet2P4;
		Double_t jetTheta = 2*atan( exp(-1*jetP4.Eta()) );

    TLorentzVector boostedJet1P4 = jet1P4;
    TVector3 beta = -jetP4.BoostVector();
    boostedJet1P4.Boost(beta);
    Double_t ThetaJetW_CM = 2*atan( exp(-1*boostedJet1P4.Eta()) ) - jetTheta;
    Double_t PhiJetW_CM = boostedJet1P4.Phi() - jetP4.Phi();
		if(PhiJetW_CM>TMath::Pi())
			PhiJetW_CM = 2*TMath::Pi() - PhiJetW_CM;
		if(PhiJetW_CM<-TMath::Pi())
			PhiJetW_CM = -2*TMath::Pi() - PhiJetW_CM;

    Int_t whichLepton = 2;
    Electron *elec;
    Muon *mu;

    // If event contains muon
    if(branchMuon->GetEntries() > 0) {
			//rejectedMuons++;
			//continue;

      // Take first muon
      mu = (Muon*) branchMuon->At(0);
      whichLepton = 0;
    }

    // If event contains electron
    if(branchElectron->GetEntries() > 0)
    {
			//rejectedElectrons++;
			//continue;

      // Take first electron
      elec = (Electron*) branchElectron->At(0);
      whichLepton = 1;
    }

    /////////////////////////////////////////////////////////////////////////
    //////////////////////// ENERGY MISS ////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    //MissingET MissEnergyTrans
    MissingET *MissEnergyTrans = (MissingET*) branchMET->At(0);


    int nCh = branchCharged->GetEntriesFast();
    int nNeu = branchNeutral->GetEntriesFast();
    int nPh = branchPhoton->GetEntriesFast();

   // Fill energy sum (all entries in the detector)
    TLorentzVector EFlowSum;
    EFlowSum.SetPxPyPzE(0.,0.,0.,0.);

    for(Int_t ineu=0; ineu<nNeu; ineu++) {
      neutral = (Tower*) branchNeutral->At(ineu);
      TLorentzVector v = neutral->P4() ;
      EFlowSum+=v;
      }

    for(Int_t iphot=0; iphot<nPh; iphot++) {
      photon = (Tower*) branchPhoton->At(iphot);
      TLorentzVector v = photon->P4() ;
      EFlowSum+=v;
      }

    for(Int_t ich=0; ich<nCh; ich++) {
      charged = (Track*) branchCharged->At(ich);
      TLorentzVector v = charged->P4() ;
      EFlowSum+=v;
      }


    // Subtract jets
    int nJet = branchJets->GetEntriesFast();

    for(Int_t ijet=0; ijet<nJet; ijet++) {
      jet = (Jet*) branchJets->At(ijet);
      TLorentzVector v = jet->P4() ;
      //TLorentzVector v = jet1P4 + jet2P4;
      EFlowSum-=v;
      }

    // Subtract muons
    int nMuon = branchMuon->GetEntriesFast();

    for(Int_t imuon=0; imuon<nMuon; imuon++) {
      muon = (Muon*) branchMuon->At(imuon);
      TLorentzVector v = muon->P4() ;
      EFlowSum-=v;
      }

    // Subtract electrons
    int nElectron = branchElectron->GetEntriesFast();

    for(Int_t ielectron=0; ielectron<nElectron; ielectron++) {
      electron = (Electron*) branchElectron->At(ielectron);
      TLorentzVector v = electron->P4() ;
      EFlowSum-=v;
      }

    // Subtract photons
    int nPhoton = branchPhoton2->GetEntriesFast();
    TLorentzVector photonsP4;
    photonsP4.SetPxPyPzE(0.,0.,0.,0.);
    int z = 0;
    for(Int_t iphoton=0; iphoton<nPhoton; iphoton++) {
      photon2 = (Photon*) branchPhoton2->At(iphoton);
      TLorentzVector v = photon2->P4() ;
      photonsP4 += photon2->P4();
      EFlowSum-=v;
      if( (photon2->P4()).E() > 10 )
        z++;
      }



		//mfac = 1;
		//esmear = 0.1;
		TLorentzVector EFlowSumSmeared = EFlowSum;
		//EFlowSumSmeared = JetSmear(EFlowSum, esmear, mfac*esmear, corr);


		if ( TMath::IsNaN(EFlowSumSmeared.M()) )
			EFlowSumSmeared = EFlowSum;

		Double_t EFlowForCut;
		if(overlay) EFlowForCut = EFlowSumSmeared.Pt();
		else EFlowForCut = EFlowSumSmeared.E();


		if(EFlowForCut >= 20) {
			EFlow_cut++;
      continue;
		}

    if(z!=0) {
			isoPhotonCut++;
      continue;
		}


    Int_t k = 0;

    if (whichLepton!=0 && whichLepton!=1) {
      continue;
		}

    TLorentzVector lepP4;

    if(whichLepton==0 && branchMuon->GetEntries() > 0)
      lepP4 = mu->P4();

    if(whichLepton==1 && branchElectron->GetEntries() > 0)
      lepP4 = elec->P4();


    TLorentzVector MissingP4;
    MissingP4.SetPxPyPzE(0.,0.,0.,3000.);

    // MissingP4 -= jetP4 + lepP4 + photonsP4;
    MissingP4 -= jetP4 + lepP4;



    /////////////////////////////////////////////////////////////////////////
    //////////////////////// CIĘCIA KINEMATYCZNE ////////////////////////////
    /////////////////////////////////////////////////////////////////////////

/////////Cuts on jets
   //if( jetTheta < 0.3 || jetTheta > (TMath::Pi() - 0.3) )
   if( jetTheta < 0.2 || jetTheta > (TMath::Pi() - 0.2) )
      continue;

    if( (jetP4).M() < 3 )
      continue;

//    if( (jetP4).E() > 850 )
//      continue;
    if( (jetP4).E() > 1300 )
          continue;


////////Cuts on leptons
//    if(lepP4.E() > 600)
//      continue;
    if(lepP4.E() > 1000)
      continue;

//    if(lepP4.Pt() > 400)
//      continue;
    if(lepP4.Pt() > 800)
      continue;

    //if( 2*atan(exp(-1*lepP4.Eta())) > (TMath::Pi() - 0.5) || 2*atan(exp(-1*lepP4.Eta())) < 0.5 )
      //continue;

		//if( lepP4.Theta() > (TMath::Pi() - 0.5) || lepP4.Theta() < 0.5 )
		if( lepP4.Theta() > (TMath::Pi() - 0.25) || lepP4.Theta() < 0.25 )
        continue;

/*
	/////// Full simulation cuts:
	//if( ( jet1P4.Theta() < 0.15 || jet1P4.Theta() > (TMath::Pi() - 0.15) ) || ( jet2P4.Theta() < 0.15 || jet2P4.Theta() > (TMath::Pi() - 0.15) ) )
	//  continue;

	if( jetP4.Theta() < 0.3 || jetP4.Theta() > (TMath::Pi() - 0.3) )
		continue;

	if( jetP4.M() < 2)
		continue;

	if( jetP4.E() > 1300 )
		continue;

	if(lepP4.E() > 1000)
		continue;

	if(lepP4.Pt() > 800)
		continue;

	if( lepP4.Theta() > (TMath::Pi() - 0.5) || lepP4.Theta() < 0.5 )
		continue;

*/

    /////////////////////////////////////////////////////////////////////////
    //////////////////////// KONIEC CIĘĆ /////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////


    jetsMass->Fill( (jetP4).M() );
    jetsEnergy->Fill( jetP4.E() );
    jetsTheta->Fill(jetTheta);
    jetDeltaTheta->Fill(ThetaJetW_CM);
    jetDeltaPhi->Fill(PhiJetW_CM);
    lepEnergy->Fill( lepP4.E() );
    lepTheta->Fill( 2*atan(exp(-1*lepP4.Eta())) );
    lepPt->Fill( lepP4.Pt() );
    met->Fill( MissingP4.Pt() );
		missingMass->Fill( MissingP4.M() );
		EFlow->Fill( EFlowForCut );

    mydata.jetsM_inv = (jetP4).M();
    mydata.jetsEnergy = (jetP4).E();
    mydata.jetsTheta = jetTheta;
    mydata.leptonEnergy = lepP4.E();
    mydata.leptonTheta = 2*atan(exp(-1*lepP4.Eta()));
    mydata.leptonPt = lepP4.Pt();
    mydata.jetDeltaTheta = ThetaJetW_CM;
    mydata.jetDeltaPhi = PhiJetW_CM;
    mydata.EFsum = EFlowForCut;
		//mydata.MET = MissEnergyTrans->MET;
		mydata.MET = MissingP4.Pt();
    mydata.missingMass = MissingP4.M();
		mydata.jet1Theta = jet1P4.Theta();
		mydata.jet2Theta = jet2P4.Theta();
		mydata.jet1Pt = jet1P4.Pt();
		mydata.jet2Pt = jet2P4.Pt();
		mydata.jet1E = jet1P4.E();
		mydata.jet2E = jet2P4.E();
		mydata.M_inv_Wlep = (lepP4+MissingP4).M();

    myheader.Ievt = entry;
		myheader.sampleName = mySampleName;

    event->Fill();

  }

  outputFile->Write();
  outputFile->Close();

  jetsMass->SetXTitle("M_{jj}");
  jetsEnergy->SetXTitle("E_{j1} + E_{j2}");
  jetsTheta->SetXTitle("#theta_{W(*)}");
  jetDeltaTheta->SetXTitle("#Delta#theta_{W(*)j}");
  jetDeltaPhi->SetXTitle("#Delta#phi_{W(*)j}");
  lepEnergy->SetXTitle("E_{l}");
  lepTheta->SetXTitle("#theta_{l}");
  lepPt->SetXTitle("p_{T}^{l}");
  met->SetXTitle("MET");
	missingMass->SetXTitle("M_{miss}");
	EFlow->SetXTitle("EFlow_{utg}");

  jetsMass->SetMinimum(0.001);
  jetsEnergy->SetMinimum(0.001);
  jetsTheta->SetMinimum(0.001);
  jetDeltaTheta->SetMinimum(0.001);
  jetDeltaPhi->SetMinimum(0.001);
  lepEnergy->SetMinimum(0.001);
  lepTheta->SetMinimum(0.001);
  lepPt->SetMinimum(0.001);
  met->SetMinimum(0.001);
	missingMass->SetMinimum(0.001);
	EFlow->SetMinimum(0.001);

  HList.Add(jetsMass);
  HList.Add(jetsEnergy);
  HList.Add(jetsTheta);
  HList.Add(jetDeltaTheta);
  HList.Add(jetDeltaPhi);
  HList.Add(lepEnergy);
  HList.Add(lepTheta);
  HList.Add(lepPt);
  HList.Add(met);
	HList.Add(missingMass);
	HList.Add(EFlow);

  TFile f("~/FUW/CLIC/IDM/3000/backgroundAnalysis/VarHistogramsAfterCuts_withOverlay_looseSel.root",fileCreate);
  HList.Write();
  f.Close();

  //to file
/*  fstream log;
  log.open("/home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/events.txt", fstream::out | fstream::app);
  if (log.is_open()) {
    log << Rvalue << " " << channel << " " << jetsMass->GetEntries() << " " << 1. - jetsMass->GetEntries()/numberOfEntries << endl;
    log.close();
  }
*/

  Double_t eff = jetsMass->GetEntries()/numberOfEntries;
  Int_t ev_after = eff*events;
  //table
  fstream log;
    log.open("/home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/table.txt", fstream::out | fstream::app);
    if (log.is_open()) {
      log << fixed << setprecision(7) << channel << " " << events << " "
      << ev_after << " " << eff << " " << jetsMass->GetEntries() << endl;
      log.close();
    }

	Double_t photonEff = isoPhotonCut;
	photonEff = 1. - photonEff / numberOfEntries;
/*
	fstream log2;
    log2.open("/home/jfklama/FUW/CLIC/IDM/3000/backgroundAnalysis/photonCut.txt", fstream::out | fstream::app);
    if (log2.is_open()) {
      log2 << fixed << setprecision(7) << channel << " " << events << " "
      << ev_after << " " << eff << " " << jetsMass->GetEntries() << " " << isoPhotonCut << " " << photonEff << endl;
      log2.close();
    }
*/
		cout << channel << " EFlowSum cut: " << EFlow_cut << " rejected events" << endl;
		cout << channel << " Iso. photon cut: " << isoPhotonCut << endl;
		cout << channel << " Rejected electrons: " << rejectedElectrons << endl;
    cout << channel << " analysis complete!" << endl;

  // Show resulting histograms
/*  jetsMass->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/jetsMass_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  jetsEnergy->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/jetsEnergy_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  jetsTheta->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/jetsTheta_" + channel + "_R" + Rvalue + ".jpg").c_str() );

  lepEnergy->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/lepEnergy_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  lepTheta->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/lepTheta_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  lepPt->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/3000/backgroundAnalysis/plots/lepPt_" + channel + "_R" + Rvalue + ".jpg").c_str() ); */
}
