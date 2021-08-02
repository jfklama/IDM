#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "/home/jfklama/FUW/CLIC/IDM/pileup/1500/jet_clustering.C"
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

void Analysis(const char *channelFile, const char *fileCreate = "RECREATE", Double_t sigma = 1., Bool_t bigStatistics = 0) {

	gROOT->ProcessLine("#include <vector>");

  std::string channel = channelFile;
  std::string category;

  char inputFile[channel.size() + 1];
	//strcpy(inputFile, "/home/jfklama/FUW/CLIC/IDM/pileup/1500/HP17_noOverlay_newChargedEff.root");
	strcpy(inputFile, "/home/jfklama/FUW/CLIC/IDM/pileup/1500/qqlv_overlay_defaultSelected_batch20FullSelection10ns_26ev_Poisson_2_newChargedEff.root");
  category = "signal";


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
  std::string Rvalue = "09";
  //std::string Rvalue = "15";
  std::string bEcorr = std::to_string(BjetEcorr);
  std::string qEcorr = std::to_string(QjetEcorr);
  bEcorr.replace(1,1,"-");
  qEcorr.replace(1,1,"-");
	// for custom jets:
	Rval=1.;
  Bval=1.;
  Gval=1.;
  Evar=0;
  Rvar=0;

  // Get pointers to branches used in this analysis
	TClonesArray *branchMCParticle = treeReader->UseBranch("Particle");
	TClonesArray *branchGenJet = treeReader->UseBranch("GenJet");
	TClonesArray *branchMuon = treeReader->UseBranch("Muon");
  TClonesArray *branchElectron = treeReader->UseBranch("Electron");
  TClonesArray *branchMET = treeReader->UseBranch("MissingET");
  //TClonesArray *branchJets = treeReader->UseBranch( ("VLCjetR" + Rvalue + "_inclusive").c_str() );
  TClonesArray *branchJets = treeReader->UseBranch( ("VLCjetR" + Rvalue + "N2").c_str() );
  TClonesArray *branchPhoton2 = treeReader->UseBranch("Photon");
  TClonesArray *branchCharged = treeReader->UseBranch("EFlowTrack");
  TClonesArray *branchNeutral = treeReader->UseBranch("EFlowNeutralHadron");
  TClonesArray *branchPhoton = treeReader->UseBranch("EFlowPhoton");
	//Particle *mcParticle;
  Jet *jet;
  Electron *electron;
  Muon *muon;
  Photon *photon2;
  Track *charged;
  Tower *neutral;
  Tower *photon;

  //Create name variables for histos
	std::string mqqTrueNameStr = "mqqTrueR" + Rvalue + "_" + channel;
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
	std::string jetMNameStr = "jetMR" + Rvalue + "_" + channel;
	std::string genJetENameStr = "genJetER" + Rvalue + "_" + channel;
	std::string jetENameStr = "jetER" + Rvalue + "_" + channel;
	std::string nPFOsNameStr = "nPFOsR" + Rvalue + "_" + channel;
	std::string hadPIDsNameStr = "hadPIDsR" + Rvalue + "_" + channel;
	char mqqTrueName[mqqTrueNameStr.size() + 1];
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
	char jetMName[jetMNameStr.size() + 1];
	char genJetEName[genJetENameStr.size() + 1];
	char jetEName[jetENameStr.size() + 1];
	char nPFOsName[nPFOsNameStr.size() + 1];
	char hadPIDsName[hadPIDsNameStr.size() + 1];
	strcpy(mqqTrueName, (mqqTrueNameStr).c_str());
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
	strcpy(jetMName, (jetMNameStr).c_str());
	strcpy(genJetEName, (genJetENameStr).c_str());
	strcpy(jetEName, (jetENameStr).c_str());
	strcpy(nPFOsName, (nPFOsNameStr).c_str());
	strcpy(hadPIDsName, (hadPIDsNameStr).c_str());


  // Book histograms
  TCanvas c1("c1", "masa", 200, 10, 600, 400);
	TH1 *h_mqqTrue = new TH1F(mqqTrueName, "", 100, 0.0, 200.0);
  TH1 *h_jetsMass = new TH1F(jetsMassName, "", 50, 0.0, 200.0);
  TH1 *h_jetsEnergy = new TH1F(jetsEnergyName, "", 100, 0.0, 2000.0);
  TH1 *h_jetsTheta = new TH1F(jetsThetaName, "", 175, 0.0, 3.5);
  TH1 *h_jetDeltaTheta = new TH1F(jetDeltaThetaName, "", 80, -3.15, 3.15);
  TH1 *h_jetDeltaPhi = new TH1F(jetDeltaPhiName, "", 100, -3.15, 3.15);
  TH1 *h_lepEnergy = new TH1F(lepEnergyName, "", 100, 0.0, 2000.0);
  TH1 *h_lepTheta = new TH1F(lepThetaName, "", 175, 0.0, 3.5);
  TH1 *h_lepPt = new TH1F(lepPtName, "", 100, 0.0, 2000.0);
  TH1 *h_met = new TH1F(metName, "", 140, 0.0, 1400.0);
	TH1 *h_missingMass = new TH1F(missingMassName, "", 160, 0.0, 3100.0);
	TH1 *h_jetM = new TH1F(jetMName, "", 50, 0.0, 200.0);
	TH1 *h_genJetE = new TH1F(genJetEName, "", 90, 0.0, 1800.0);
	TH1 *h_jetE = new TH1F(jetEName, "", 90, 0.0, 1800.0);
	TH1 *h_nPFOs = new TH1F(nPFOsName, "", 50, 0.0, 200.0);
	TH1 *h_hadPIDs = new TH1F(hadPIDsName, "", 22000, 0.0, 22000.0);

	// PFO angular, number and pT distributions

	std::string phoLowPtThetaNameStr = "phoLowPtThetaR" + Rvalue + "_" + channel;
	std::string phoMedPtThetaNameStr = "phoMedPtThetaR" + Rvalue + "_" + channel;
	std::string phoHighPtThetaNameStr = "phoHighPtThetaR" + Rvalue + "_" + channel;
	std::string nhLowPtThetaNameStr = "nhLowPtThetaR" + Rvalue + "_" + channel;
	std::string nhMedPtThetaNameStr = "nhMedPtThetaR" + Rvalue + "_" + channel;
	std::string nhHighPtThetaNameStr = "nhHighPtThetaR" + Rvalue + "_" + channel;
	std::string chLowPtThetaNameStr = "chLowPtThetaR" + Rvalue + "_" + channel;
	std::string chMedPtThetaNameStr = "chMedPtThetaR" + Rvalue + "_" + channel;
	std::string chHighPtThetaNameStr = "chHighPtThetaR" + Rvalue + "_" + channel;
	std::string phoLowPt_nPFOsNameStr = "phoLowPt_nPFOsR" + Rvalue + "_" + channel;
	std::string phoHighPt_nPFOsNameStr = "phoHighPt_nPFOsR" + Rvalue + "_" + channel;
	std::string nhLowPt_nPFOsNameStr = "nhLowPt_nPFOsR" + Rvalue + "_" + channel;
	std::string nhHighPt_nPFOsNameStr = "nhHighPt_nPFOsR" + Rvalue + "_" + channel;
	std::string chLowPt_nPFOsNameStr = "chLowPt_nPFOsR" + Rvalue + "_" + channel;
	std::string chHighPt_nPFOsNameStr = "chHighPt_nPFOsR" + Rvalue + "_" + channel;
	std::string allLowPt_nPFOsNameStr = "allLowPt_nPFOsR" + Rvalue + "_" + channel;
	std::string allHighPt_nPFOsNameStr = "allHighPt_nPFOsR" + Rvalue + "_" + channel;

	std::string phoPtNameStr = "phoPtR" + Rvalue + "_" + channel;
	std::string nhPtNameStr = "nhPtR" + Rvalue + "_" + channel;
	std::string chPtNameStr = "chPtR" + Rvalue + "_" + channel;

	std::string phoThetaPartialNameStr = "phoThetaPartialR" + Rvalue + "_" + channel;
	std::string nhThetaPartialNameStr = "nhThetaPartialR" + Rvalue + "_" + channel;
	std::string chThetaPartialNameStr = "chThetaPartialR" + Rvalue + "_" + channel;
	std::string allThetaPartialNameStr = "allThetaR" + Rvalue + "_" + channel;

	char phoLowPtThetaName[phoLowPtThetaNameStr.size() + 1];
	char phoMedPtThetaName[phoMedPtThetaNameStr.size() + 1];
	char phoHighPtThetaName[phoHighPtThetaNameStr.size() + 1];
	char nhLowPtThetaName[nhLowPtThetaNameStr.size() + 1];
	char nhMedPtThetaName[nhMedPtThetaNameStr.size() + 1];
	char nhHighPtThetaName[nhHighPtThetaNameStr.size() + 1];
	char chLowPtThetaName[chLowPtThetaNameStr.size() + 1];
	char chMedPtThetaName[chMedPtThetaNameStr.size() + 1];
	char chHighPtThetaName[chHighPtThetaNameStr.size() + 1];
	char phoLowPt_nPFOsName[phoLowPt_nPFOsNameStr.size() + 1];
	char phoHighPt_nPFOsName[phoHighPt_nPFOsNameStr.size() + 1];
	char nhLowPt_nPFOsName[nhLowPt_nPFOsNameStr.size() + 1];
	char nhHighPt_nPFOsName[nhHighPt_nPFOsNameStr.size() + 1];
	char chLowPt_nPFOsName[chLowPt_nPFOsNameStr.size() + 1];
	char chHighPt_nPFOsName[chHighPt_nPFOsNameStr.size() + 1];
	char allLowPt_nPFOsName[allLowPt_nPFOsNameStr.size() + 1];
	char allHighPt_nPFOsName[allHighPt_nPFOsNameStr.size() + 1];

	char phoPtName[phoPtNameStr.size() + 1];
	char nhPtName[nhPtNameStr.size() + 1];
	char chPtName[chPtNameStr.size() + 1];

	char phoThetaPartialName[phoThetaPartialNameStr.size() + 1];
	char nhThetaPartialName[nhThetaPartialNameStr.size() + 1];
	char chThetaPartialName[chThetaPartialNameStr.size() + 1];
	char allThetaPartialName[allThetaPartialNameStr.size() + 1];

	strcpy(phoLowPtThetaName, (phoLowPtThetaNameStr).c_str());
	strcpy(phoMedPtThetaName, (phoMedPtThetaNameStr).c_str());
	strcpy(phoHighPtThetaName, (phoHighPtThetaNameStr).c_str());
	strcpy(nhLowPtThetaName, (nhLowPtThetaNameStr).c_str());
	strcpy(nhMedPtThetaName, (nhMedPtThetaNameStr).c_str());
	strcpy(nhHighPtThetaName, (nhHighPtThetaNameStr).c_str());
	strcpy(chLowPtThetaName, (chLowPtThetaNameStr).c_str());
	strcpy(chMedPtThetaName, (chMedPtThetaNameStr).c_str());
	strcpy(chHighPtThetaName, (chHighPtThetaNameStr).c_str());
	strcpy(phoLowPt_nPFOsName, (phoLowPt_nPFOsNameStr).c_str());
	strcpy(phoHighPt_nPFOsName, (phoHighPt_nPFOsNameStr).c_str());
	strcpy(nhLowPt_nPFOsName, (nhLowPt_nPFOsNameStr).c_str());
	strcpy(nhHighPt_nPFOsName, (nhHighPt_nPFOsNameStr).c_str());
	strcpy(chLowPt_nPFOsName, (chLowPt_nPFOsNameStr).c_str());
	strcpy(chHighPt_nPFOsName, (chHighPt_nPFOsNameStr).c_str());
	strcpy(allLowPt_nPFOsName, (allLowPt_nPFOsNameStr).c_str());
	strcpy(allHighPt_nPFOsName, (allHighPt_nPFOsNameStr).c_str());

	strcpy(phoPtName, (phoPtNameStr).c_str());
	strcpy(nhPtName, (nhPtNameStr).c_str());
	strcpy(chPtName, (chPtNameStr).c_str());

	strcpy(phoThetaPartialName, (phoThetaPartialNameStr).c_str());
	strcpy(nhThetaPartialName, (nhThetaPartialNameStr).c_str());
	strcpy(chThetaPartialName, (chThetaPartialNameStr).c_str());
	strcpy(allThetaPartialName, (allThetaPartialNameStr).c_str());


	TH1 *h_phoLowPtTheta = new TH1F(phoLowPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_phoMedPtTheta = new TH1F(phoMedPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_phoHighPtTheta = new TH1F(phoHighPtThetaName, "", 175, 0.0, 3.5);

	TH1 *h_nhLowPtTheta = new TH1F(nhLowPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_nhMedPtTheta = new TH1F(nhMedPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_nhHighPtTheta = new TH1F(nhHighPtThetaName, "", 175, 0.0, 3.5);

	TH1 *h_chLowPtTheta = new TH1F(chLowPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_chMedPtTheta = new TH1F(chMedPtThetaName, "", 175, 0.0, 3.5);
	TH1 *h_chHighPtTheta = new TH1F(chHighPtThetaName, "", 175, 0.0, 3.5);

	TH1 *h_phoLowPt_nPFOs = new TH1F(phoLowPt_nPFOsName, "", 200, 0.0, 200.);
	TH1 *h_phoHighPt_nPFOs = new TH1F(phoHighPt_nPFOsName, "", 200, 0.0, 200.);

	TH1 *h_nhLowPt_nPFOs = new TH1F(nhLowPt_nPFOsName, "", 200, 0.0, 200.);
	TH1 *h_nhHighPt_nPFOs = new TH1F(nhHighPt_nPFOsName, "", 200, 0.0, 200.);

	TH1 *h_chLowPt_nPFOs = new TH1F(chLowPt_nPFOsName, "", 200, 0.0, 200.);
	TH1 *h_chHighPt_nPFOs = new TH1F(chHighPt_nPFOsName, "", 200, 0.0, 200.);

	TH1 *h_allLowPt_nPFOs = new TH1F(allLowPt_nPFOsName, "", 200, 0.0, 200.);
	TH1 *h_allHighPt_nPFOs = new TH1F(allHighPt_nPFOsName, "", 200, 0.0, 200.);

	TH1 *h_phoPt = new TH1F(phoPtName, "", 30, 0.0, 30.);
	TH1 *h_nhPt = new TH1F(nhPtName, "", 30, 0.0, 30.);
	TH1 *h_chPt = new TH1F(chPtName, "", 30, 0.0, 30.);

	TH1 *h_phoThetaPartial = new TH1F(phoThetaPartialName, "", 175, 0.0, 3.5);
	TH1 *h_nhThetaPartial = new TH1F(nhThetaPartialName, "", 175, 0.0, 3.5);
	TH1 *h_chThetaPartial = new TH1F(chThetaPartialName, "", 175, 0.0, 3.5);
	TH1 *h_allThetaPartial = new TH1F(allThetaPartialName, "", 175, 0.0, 3.5);


  Double_t luminosity = 2000;

  ///////////////////////
  //TREE
  ///////////////////////

	//TFile *outputFile = new TFile(("~/FUW/CLIC/IDM/1500/backgroundAnalysis/inputsForBDT/" + channel + "DataPreselected.root").c_str(),"RECREATE");
	TFile *outputFile = new TFile(("/home/jfklama/FUW/CLIC/IDM/pileup/1500/" + channel + "DataPreselected.root").c_str(),"RECREATE");

  TTree *event = new TTree("event","Events after preselection");

	Int_t Ievt;
	Float_t weight;
	Float_t crossSection;
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

  // Tree header

	 char mySampleName[channel.size() + 1];
	 strcpy(mySampleName, (channel).c_str());
/*
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
			vector<float> jetM;
			Float_t M_inv_Wlep;
    };

    event_head myheader;
    event_data mydata;

    event->Branch( "header",&myheader, "Ievt/I:w/F:crossSection/F:sampleName/C" );
    event->Branch( "data",&mydata, "jetsM_inv/F:jetsEnergy:jetsTheta:leptonEnergy:leptonTheta:leptonPt:jetDeltaTheta:jetDeltaPhi:EFsum:MET:missingMass:jet1Theta:jet2Theta:jet1Pt:jet2Pt:jet1E:jet2E:jetM:M_inv_Wlep" );
*/
    weight = sigma*luminosity/numberOfEntries;
    crossSection = sigma;


  Double_t events = sigma*luminosity;

	// vars to count events rejected by particular cuts
  int twoJets = 0;
  int oneLepton = 0;
  int noPhotons = 0;
  int addEnergy = 0;
	int rejectedElectrons=0, rejectedMuons=0;
	int genNeutralHad = 0;
	int recoNeutralHad = 0;


  ///////////////////////
  // Loop over all events
  ///////////////////////

  for(Int_t entry = 0; entry < numberOfEntries; ++entry)
  {
    // Load selected branches with data from specified event
    treeReader->ReadEntry(entry);

  // Cut on no. of leptons
    if(branchMuon->GetEntries() > 0 && branchElectron->GetEntries() > 0) { //throw out events with both electrons and
      //cout << "2 leptons" << endl;
      oneLepton++;                                       //muons
      // continue;
		}
    if(branchMuon->GetEntries() > 1 || branchElectron->GetEntries() > 1) { //throw out events with more than 1 electron
      //cout << "2 leptons" << endl;
      oneLepton++;                                     //or more than 1 muon
      // continue;
		}
    if (branchElectron->GetEntries() == 0 && branchMuon->GetEntries() == 0) { //throw out events with no isolated leptons
      oneLepton++;
      // continue;
		}
		if (branchElectron->GetEntries() != 0 || branchMuon->GetEntries() != 0) { //throw out events with isolated leptons
      oneLepton++;
       // continue;
		}



//Cut on no. of jets
    //if(branchJets->GetEntries() != 1)
    //continue;
    if(branchJets->GetEntries() != 2) {
      twoJets++;
       continue;
		}

// Jets
    Jet *jet1 = (Jet*) branchJets->At(0);
    Jet *jet2 = (Jet*) branchJets->At(1);

    //TLorentzVector jetP4 = jet1->P4();
		TLorentzVector jet1P4 = jet1->P4();
		TLorentzVector jet2P4 = jet2->P4();
/*
		// CUSTOM JETS
		int nPar = branchMCParticle->GetEntriesFast();
		GenParticle *par;
		vector<TLorentzVector> ValJets;
		for(int iPar=0; iPar<nPar; iPar++)
		{
			par = (GenParticle*) branchMCParticle->At(iPar);
			if(par->Status!=2) continue;
      ValJets.push_back(par->P4());
		}
		if(ValJets.size()<2) {cout << " *WARNING*: less than 2 PFOs in event!" << endl; continue;}
		//cout << "Before clustering: " << ValJets.size() << endl;
		double Dcut=0.;
    int ValReq=2;
		DoJetClustering(ValJets,ValReq,Dcut);
		//cout << "After clustering: " << ValJets.size() << endl;

		//cout << (ValJets[0] + ValJets[1]).M() << " " << ValJets.size() << endl;
		jet1P4 = ValJets[0];
		jet2P4 = ValJets[1];
*/
/*
    //smearing
    double mfac = 1.;
    double corr = 1.; // 1st scenario
    //double mfac = 1.5;
    //double corr = 0.5; // 2nd scenario
    //double mfac = 2.;
    //double corr = 0.5; // 3rd scenario
    double esmear = 0.01;  // For 3 TeV running (use 0.01 for 1.5 TeV)
    if(abs(jet1->P4().Eta())>0.76) esmear = 0.05;    // For 3 TeV running (use 0.05 for 1.5 TeV)
    jet1P4 = JetSmear(jet1->P4(), esmear, mfac*esmear, corr);

    esmear = 0.01;  // For 3 TeV running (use 0.01 for 1.5 TeV)
    if(abs(jet2->P4().Eta())>0.76) esmear = 0.05;    // For 3 TeV running (use 0.05 for 1.5 TeV)
    jet2P4 = JetSmear(jet2->P4(), esmear, mfac*esmear, corr);
*/
    TLorentzVector jetP4 = jet1P4 + jet2P4;
    Double_t jetTheta = 2*atan( exp(-1*jetP4.Eta()) );

    TLorentzVector boostedJet1P4 = jet1P4;
    TVector3 beta = -jetP4.BoostVector();
    boostedJet1P4.Boost(beta);
		//Double_t ThetaJetW_CM = fabs( 2*atan( exp(-1*boostedJet1P4.Eta()) ) - jetTheta );
		Double_t ThetaJetW_CM = boostedJet1P4.Theta()  - jetTheta ;
    Double_t PhiJetW_CM =  boostedJet1P4.Phi() - jetP4.Phi() ;
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

		if (whichLepton!=0 && whichLepton!=1) {
      oneLepton++;
      // continue;
		}

    /////////////////////////////////////////////////////////////////////////
    //////////////////////// ENERGY MISS ////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    //MissingET MissEnergyTrans
    MissingET *MissEnergyTrans = (MissingET*) branchMET->At(0);


    int nCh = branchCharged->GetEntriesFast();
    int nNeu = branchNeutral->GetEntriesFast();
    int nPh = branchPhoton->GetEntries();
		nPFOs = nCh + nNeu + nPh;

		int nChLowPt = 0;
		int nChHighPt = 0;
		int nNeuLowPt = 0;
		int nNeuHighPt = 0;
		int nPhLowPt = 0;
		int nPhHighPt = 0;

   // Fill energy sum (all entries in the detector) and PFO theta histograms
    TLorentzVector EFlowSum;
    EFlowSum.SetPxPyPzE(0.,0.,0.,0.);

    for(Int_t ineu=0; ineu<nNeu; ineu++) {
      neutral = (Tower*) branchNeutral->At(ineu);
      TLorentzVector v = neutral->P4() ;
      EFlowSum+=v;

			if(v.Pt() < 0.75) {
				h_nhLowPtTheta->Fill(v.Theta(), 1. / numberOfEntries);
			} else if(v.Pt() < 8) {
				h_nhMedPtTheta->Fill(v.Theta(), 1. / numberOfEntries);
			} else {
				h_nhHighPtTheta->Fill(v.Theta(), 1. / numberOfEntries);
			}
			if(v.Pt() > 1.5 && fabs(v.Eta()) < 2.4) nNeuLowPt++;
			if(v.Pt() > 2 && fabs(v.Eta()) < 2.4) nNeuHighPt++;
			h_nhPt->Fill(v.Pt(), 1. / numberOfEntries);
			if(v.Pt()>2) {h_nhThetaPartial->Fill(v.Theta(), 1. / numberOfEntries); h_allThetaPartial->Fill(v.Theta(), 1. / numberOfEntries);}
    }
		h_nhLowPt_nPFOs->Fill(nNeuLowPt, 1. / numberOfEntries);
		h_nhHighPt_nPFOs->Fill(nNeuHighPt, 1. / numberOfEntries);

    for(Int_t iphot=0; iphot<nPh; iphot++) {
      photon = (Tower*) branchPhoton->At(iphot);
      TLorentzVector v = photon->P4() ;
      EFlowSum+=v;

			if(v.Pt() < 0.75) {
				h_phoLowPtTheta->Fill(v.Theta(), 1. / numberOfEntries);

			} else if(v.Pt() < 4) {
				h_phoMedPtTheta->Fill(v.Theta(), 1. / numberOfEntries);
			} else {
				h_phoHighPtTheta->Fill(v.Theta(), 1. / numberOfEntries);

			}
			if(v.Pt() > 1 && fabs(v.Eta()) < 2.4) nPhLowPt++;
			if(v.Pt() > 2 && fabs(v.Eta()) < 2.4) nPhHighPt++;
			h_phoPt->Fill(v.Pt(), 1. / numberOfEntries);
			if(v.Pt()>2) {h_phoThetaPartial->Fill(v.Theta(), 1. / numberOfEntries); h_allThetaPartial->Fill(v.Theta(), 1. / numberOfEntries);}
    }
		h_phoLowPt_nPFOs->Fill(nPhLowPt, 1. / numberOfEntries);
		h_phoHighPt_nPFOs->Fill(nPhHighPt, 1. / numberOfEntries);

    for(Int_t ich=0; ich<nCh; ich++) {
      charged = (Track*) branchCharged->At(ich);
      TLorentzVector v = charged->P4() ;
      EFlowSum+=v;

			if(v.Pt() < 0.75) {
				h_chLowPtTheta->Fill(v.Theta(), 1. / numberOfEntries);

			} else if(v.Pt() < 4) {
				h_chMedPtTheta->Fill(v.Theta(), 1. / numberOfEntries);
			} else {
				h_chHighPtTheta->Fill(v.Theta(), 1. / numberOfEntries);

			}
			if(v.Pt() > 1 && fabs(v.Eta()) < 2.4) nChLowPt++;
			if(v.Pt() > 2 && fabs(v.Eta()) < 2.4) nChHighPt++;
			h_chPt->Fill(v.Pt(), 1. / numberOfEntries);
			if(v.Pt()>2) {h_chThetaPartial->Fill(v.Theta(), 1. / numberOfEntries); h_allThetaPartial->Fill(v.Theta(), 1. / numberOfEntries);}
		}
		h_chLowPt_nPFOs->Fill(nChLowPt, 1. / numberOfEntries);
		h_chHighPt_nPFOs->Fill(nChHighPt, 1. / numberOfEntries);

		int nAllLowPt = nNeuLowPt + nPhLowPt + nChLowPt;
		int nAllHighPt = nNeuHighPt + nPhHighPt + nChHighPt;

		h_allLowPt_nPFOs->Fill(nAllLowPt, 1. / numberOfEntries);
		h_allHighPt_nPFOs->Fill(nAllHighPt, 1. / numberOfEntries);

    // Subtract jets
    int nJet = branchJets->GetEntriesFast();

    for(Int_t ijet=0; ijet<nJet; ijet++) {
      jet = (Jet*) branchJets->At(ijet);
      TLorentzVector v = jet->P4() ;
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

		//mfac = 0;
		//esmear = 0.05;
		TLorentzVector EFlowSumSmeared = EFlowSum;
		//EFlowSumSmeared = JetSmear(EFlowSum, esmear, mfac*esmear, corr);

		if ( TMath::IsNaN(EFlowSumSmeared.M()) ) {
			//cout << entry << ": " << EFlowSum.Px() << " " << EFlowSum.Py() << " "
			//<< EFlowSum.Pz() << " " << EFlowSum.E() << " " << EFlowSum.M() << endl;
			//cout << entry << ": " << EFlowSumSmeared.Px() << " " << EFlowSumSmeared.Py() << " "
			//<< EFlowSumSmeared.Pz() << " " << EFlowSumSmeared.E() << " " << EFlowSumSmeared.M() << endl;
			EFlowSumSmeared = EFlowSum;
		}

    if(EFlowSumSmeared.Pt() >= 20) {
      addEnergy++;
      //continue;
		}

    if(z!=0) {
      noPhotons++;
      //continue;
		}


    TLorentzVector lepP4;

    if(whichLepton==1 && branchElectron->GetEntries() > 0)
      lepP4 = elec->P4();

		if(whichLepton==0 && branchMuon->GetEntries() > 0)
      lepP4 = mu->P4();


    TLorentzVector MissingP4;
    MissingP4.SetPxPyPzE(0.,0.,0.,1500.);

    MissingP4 -= jetP4 + lepP4 + photonsP4;
    // MissingP4 -= jetP4 + lepP4;


		// Generator level particles
		TLorentzVector mcQ1P4, mcQ2P4;
		for(int i=0; i<branchMCParticle->GetEntries(); i++)
		{
			GenParticle *q1 = (GenParticle*) branchMCParticle->At(i);
	    GenParticle *q2 = (GenParticle*) branchMCParticle->At(i+1);
			if(i < 15 && fabs(q1->PID) <= 7 && fabs(q2->PID) <= 7)
			{
				mcQ1P4 = q1->P4();
				mcQ2P4 = q2->P4();
			}

			GenParticle *particle = (GenParticle*) branchMCParticle->At(i);
			//if( abs(particle->PID)>=111 && particle->Charge == 0 && (particle->P4().Theta() <= 0.15 || particle->P4().Theta() >= TMath::Pi()-0.15) )
			if( abs(particle->PID)>=111 && particle->Charge == 0 )
			{
				genNeutralHad++;
				Double_t Rmin = 10000;
				for(Int_t ineu=0; ineu<nNeu; ineu++)
				{
		      neutral = (Tower*) branchNeutral->At(ineu);
		      TLorentzVector neutralP4 = neutral->P4() ;
					if(neutralP4.Theta() <= 0.15 || neutralP4.Theta() >= TMath::Pi()-0.15) {
						Double_t R = pow(sin(neutralP4.Theta()-particle->P4().Theta()),2)*pow(neutralP4.Theta()-particle->P4().Theta(), 2)+pow(neutralP4.Phi()-particle->P4().Phi(), 2);
						if(R<Rmin) Rmin = R;
						/*
						cout << "R: " << R << endl;
						cout << particle->P4().Pt() << " " << particle->P4().Theta() << " " << particle->P4().Phi() << " " << particle->P4().E() << endl;
						cout << neutralP4.Pt() << " " << neutralP4.Theta() << " " << neutralP4.Phi() << " " << neutralP4.E() << endl;
						cout << endl;
						*/
					}

				}
				if(Rmin<=0.5)
				{
					recoNeutralHad++;
					h_hadPIDs->Fill(abs(particle->PID));
				}
			}

		}

		TLorentzVector genJet1P4, genJet2P4;
		Int_t nGenJets = branchGenJet->GetEntries();
		if(nGenJets == 2)
		{
			Jet *genJet = (Jet*) branchGenJet->At(0);
			genJet1P4 = genJet->P4();
			Jet *genJet2 = (Jet*) branchGenJet->At(1);
			genJet2P4 = genJet2->P4();
		}
		//else continue;


    /////////////////////////////////////////////////////////////////////////
    //////////////////////// CIĘCIA KINEMATYCZNE ////////////////////////////
    /////////////////////////////////////////////////////////////////////////
/*
/////////Cuts on jets
   if( jetTheta < 0.2 || jetTheta > (TMath::Pi() - 0.2) )
      continue;
// if( jetTheta < 0.15 || jetTheta > 2.9 )
//   continue;

    if( (jetP4).M() < 3 )
      continue;

//    if( (jetP4).E() > 650 )
//      continue;
    if( (jetP4).E() > 750 )
          continue;


////////Cuts on leptons
//    if(lepP4.E() > 500)
//      continue;
    if(lepP4.E() > 600)
      continue;

//    if(lepP4.Pt() > 500)
//      continue;
    if(lepP4.Pt() > 550 || lepP4.Pt() < 2)
      continue;

		if( lepP4.Theta() > (TMath::Pi() - 0.25) || lepP4.Theta() < 0.25 )
			continue;

////////Cuts on Missing Energy
//    if (MissingP4.M() < 300)
//      continue;
    if (MissingP4.M() < 400)
      continue;
*/

		if(lepP4.Pt() > 800 || lepP4.Pt() < 150)
        // continue;

    /////////////////////////////////////////////////////////////////////////
    //////////////////////// KONIEC CIĘĆ /////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////


    h_mqqTrue->Fill( (mcQ1P4+mcQ2P4).M() );
    h_jetsMass->Fill( (jetP4).M() );
    h_jetsEnergy->Fill( jetP4.E() );
    h_jetsTheta->Fill(jetTheta);
    h_jetDeltaTheta->Fill(ThetaJetW_CM);
    h_jetDeltaPhi->Fill(PhiJetW_CM);
		if(branchElectron->GetEntries() > 0 || branchMuon->GetEntries() > 0) {
	    h_lepEnergy->Fill( lepP4.E() );
	    h_lepTheta->Fill( 2*atan(exp(-1*lepP4.Eta())) );
	    h_lepPt->Fill( lepP4.Pt() );
		}
		//met->Fill( MissEnergyTrans->MET );
		h_met->Fill( MissingP4.Pt() );
		h_missingMass->Fill( MissingP4.M() );
		h_jetM->Fill( jet1->Mass );
		h_jetM->Fill( jet2->Mass );
		//if(nGenJets==2)
		//{
			// cout << nGenJets << endl;
			//h_genJetE->Fill( genJet1P4.E() );
			//h_genJetE->Fill( genJet2P4.E() );
		//}
		for(int i=0; i<nGenJets; i++)
		{
			Jet *genJet = (Jet*) branchGenJet->At(i);
			h_genJetE->Fill( genJet->P4().E() );
		}
		//h_jetE->Fill( jet1P4.E() );
		//h_jetE->Fill( jet2P4.E() );
		for(int i=0; i<branchJets->GetEntries(); i++)
		{
			Jet *jet = (Jet*) branchJets->At(i);
			h_jetE->Fill( jet->P4().E() );
		}
		h_nPFOs->Fill( nPFOs );

		jetM.clear();

    jetsM_inv = (jetP4).M();
    jetsEnergy = (jetP4).E();
    jetsTheta = jetTheta;
    leptonEnergy = lepP4.E();
    leptonTheta = 2*atan(exp(-1*lepP4.Eta()));
    leptonPt = lepP4.Pt();
    jetDeltaTheta = ThetaJetW_CM;
    jetDeltaPhi = PhiJetW_CM;
    EFsum = EFlowSumSmeared.Pt();
		//MET = MissEnergyTrans->MET;
		MET = MissingP4.Pt();
    missingMass = MissingP4.M();
		jet1Theta = jet1P4.Theta();
		jet2Theta = jet2P4.Theta();
		jet1Pt = jet1P4.Pt();
		jet2Pt = jet2P4.Pt();
		jet1E = jet1P4.E();
		jet2E = jet2P4.E();
		//jetM[0] = jet1P4.M();
		//jetM[1] = jet2P4.M();
		jetM.push_back(jet1P4.M());
		jetM.push_back(jet2P4.M());
		M_inv_Wlep = (lepP4+MissingP4).M();

    Ievt = entry;
		sampleName = mySampleName;

    event->Fill();

  }

  outputFile->Write();
  outputFile->Close();

	h_mqqTrue->SetXTitle("M_{qq}");
	h_jetsMass->SetXTitle("M_{jj}");
  h_jetsEnergy->SetXTitle("E_{j1} + E_{j2}");
  h_jetsTheta->SetXTitle("#theta_{W(*)}");
  h_jetDeltaTheta->SetXTitle("#Delta#theta_{W(*)j}");
  h_jetDeltaPhi->SetXTitle("#Delta#phi_{W(*)j}");
  h_lepEnergy->SetXTitle("E_{l}");
  h_lepTheta->SetXTitle("#theta_{l}");
  h_lepPt->SetXTitle("p_{T}^{l}");
  h_met->SetXTitle("MET");
	h_missingMass->SetXTitle("M_{miss}");
	h_jetM->SetXTitle("M_{jet}");
	h_genJetE->SetXTitle("E^{true}_{jet}");
	h_jetE->SetXTitle("E_{jet}");
	h_nPFOs->SetXTitle("N_{PFO}");
	h_hadPIDs->SetXTitle("PID_{had}");

	h_mqqTrue->SetMinimum(0.001);
	h_jetsMass->SetMinimum(0.001);
  h_jetsEnergy->SetMinimum(0.001);
  h_jetsTheta->SetMinimum(0.001);
  h_jetDeltaTheta->SetMinimum(0.001);
  h_jetDeltaPhi->SetMinimum(0.001);
  h_lepEnergy->SetMinimum(0.001);
  h_lepTheta->SetMinimum(0.001);
  h_lepPt->SetMinimum(0.001);
  h_met->SetMinimum(0.001);
	h_missingMass->SetMinimum(0.001);
	h_jetM->SetMinimum(0.001);
	h_genJetE->SetMinimum(0.001);
	h_jetE->SetMinimum(0.001);
	h_nPFOs->SetMinimum(0.001);
	h_hadPIDs->SetMinimum(0.001);

	HList.Add(h_mqqTrue);
	HList.Add(h_jetsMass);
  HList.Add(h_jetsEnergy);
  HList.Add(h_jetsTheta);
  HList.Add(h_jetDeltaTheta);
  HList.Add(h_jetDeltaPhi);
  HList.Add(h_lepEnergy);
  HList.Add(h_lepTheta);
  HList.Add(h_lepPt);
  HList.Add(h_met);
	HList.Add(h_missingMass);
	HList.Add(h_jetM);
	HList.Add(h_genJetE);
	HList.Add(h_jetE);
	HList.Add(h_nPFOs);
	HList.Add(h_hadPIDs);

	// PFO theta histograms

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

/*
	h_phoLowPtTheta->SetMinimum(0.001);
	h_phoMedPtTheta->SetMinimum(0.001);
	h_phoHighPtTheta->SetMinimum(0.001);
	h_nhLowPtTheta->SetMinimum(0.001);
	h_nhMedPtTheta->SetMinimum(0.001);
	h_nhHighPtTheta->SetMinimum(0.001);
	h_chLowPtTheta->SetMinimum(0.001);
	h_chMedPtTheta->SetMinimum(0.001);
	h_chHighPtTheta->SetMinimum(0.001);
*/
	HList.Add(h_phoLowPtTheta);
	HList.Add(h_phoMedPtTheta);
	HList.Add(h_phoHighPtTheta);
	HList.Add(h_nhLowPtTheta);
	HList.Add(h_nhMedPtTheta);
	HList.Add(h_nhHighPtTheta);
	HList.Add(h_chLowPtTheta);
	HList.Add(h_chMedPtTheta);
	HList.Add(h_chHighPtTheta);
	HList.Add(h_phoLowPt_nPFOs);
	HList.Add(h_phoHighPt_nPFOs);
	HList.Add(h_nhLowPt_nPFOs);
	HList.Add(h_nhHighPt_nPFOs);
	HList.Add(h_chLowPt_nPFOs);
	HList.Add(h_chHighPt_nPFOs);
	HList.Add(h_allLowPt_nPFOs);
	HList.Add(h_allHighPt_nPFOs);
	HList.Add(h_phoPt);
	HList.Add(h_nhPt);
	HList.Add(h_chPt);
	HList.Add(h_phoThetaPartial);
	HList.Add(h_nhThetaPartial);
	HList.Add(h_chThetaPartial);
	HList.Add(h_allThetaPartial);

	//TFile f("~/FUW/CLIC/IDM/1500/backgroundAnalysis/VarHistogramsBeforeCuts_withSmear1.root",fileCreate);
	TFile f("/home/jfklama/FUW/CLIC/IDM/pileup/1500/VarHistogramsBeforeCuts_overlay.root",fileCreate);
  HList.Write();
  f.Close();

  //to file
/*  fstream log;
  log.open("/home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/events.txt", fstream::out | fstream::app);
  if (log.is_open()) {
    log << Rvalue << " " << channel << " " << jetsMass->GetEntries() << " " << 1. - jetsMass->GetEntries()/numberOfEntries << endl;
    log.close();
  }
*/

  Double_t eff = h_jetsMass->GetEntries()/numberOfEntries;
  Int_t ev_after = eff*events;
  //table
  fstream log;
    //log.open("/home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/table.txt", fstream::out | fstream::app);
    log.open("/home/jfklama/FUW/CLIC/IDM/pileup/1500/table.txt", fstream::out | fstream::app);
    if (log.is_open()) {
      log << fixed << setprecision(7) << channel << " " << events << " "
      << ev_after << " " << eff << " " << h_jetsMass->GetEntries() << endl;
      log.close();
    }

/*  if(category=="signal")
    {//signature
    fstream log2;
      log2.open("/home/jfklama/FUW/CLIC/IDM/1500/backgroundAnalysis/signature_eff.txt", fstream::out | fstream::app);
      if (log2.is_open()) {
        log2 << channel << ":" << endl;
        log2 << "One lepton requirement: " << oneLepton << endl;
        log2 << "Two jets requirement: " << twoJets << endl;
        log2 << "No photons requirement: " << noPhotons << endl;
        log2 << "No additional energy requirement: " << addEnergy << endl;
        log2 << endl;
        log2.close();
      }
  } */

	Double_t neutralHadEff = recoNeutralHad;
	neutralHadEff /= genNeutralHad;

	//cout << "Rejected events with too high EFlow En.: " << addEnergy << endl;
	//cout << "Rejected events with too many high-energetic photons: " << noPhotons << endl;
	//cout << channel << " Rejected muons: " << rejectedMuons << endl;
	//cout << channel << " Rejected electrons: " << rejectedElectrons << endl;
	cout << channel << " Matching % of neutral hadrons at 0.15 > Theta > 2.99: " << neutralHadEff << endl;
	cout << " Number of matching hadrons: " << recoNeutralHad << endl;
	cout << "Number of all EFLow Neutral Hadrons: " << branchNeutral->GetEntries() << endl;
	cout << "Number of gen-level neutral particles in range: " << genNeutralHad << endl;
	cout << "Total efficiency: " << eff << endl;

  cout << channel << " analysis complete!" << endl;

  // Show resulting histograms
/*  jetsMass->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/jetsMass_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  jetsEnergy->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/jetsEnergy_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  jetsTheta->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/jetsTheta_" + channel + "_R" + Rvalue + ".jpg").c_str() );

  lepEnergy->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/lepEnergy_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  lepTheta->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/lepTheta_" + channel + "_R" + Rvalue + ".jpg").c_str() );
  lepPt->Draw();
  c1.Print( ("~/FUW/CLIC/IDM/1500/backgroundAnalysis/plots/lepPt_" + channel + "_R" + Rvalue + ".jpg").c_str() ); */
}
