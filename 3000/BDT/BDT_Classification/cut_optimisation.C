#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>


//#include "CLICdpStyle.C"


void cut_optimisation(string chname="BP18",
			string filedir = "",
		  string varname="bdt.BDT",
		  //string weight = "w*(Chi2sig>0.0)",
	          int iwid = 2, int icol = 2, int ipat=1,string label = "",
	          double lumi  = 2000., double effmin=0.05,
                  double addbg=0., double addeffi = 0.,                                // to add other channel
	          double xmin = -1.0, double xmax = 1.0, int nbin = 20000, int rebin=200,
	          double xfmin=0.01, double xfmax=0.199,
	          double yfmin=0.0000005, double yfmax=0.000999
	       )
{

	//int class[2] = {0, 1};

	string mvaname = filedir + "/" + chname + "_classified.root";

	Int_t nsamp = 2;
	string sampname[2] = {"background", "signal"};

	string treename = "event";
	TTree *samptree;

	TH1D *samphist[2];

	string wcuts[2] = {"(classID==0)*w", "(classID==1)*w"};

	double nsigevt, nbgevt;

	TCanvas  *ch1 = (TCanvas *) gROOT->FindObject("ch1");
  if(!ch1) {
     ch1 = new TCanvas("ch1","MVA histograms",20,20,600,450);
     //     gPad->SetGrid(1,1);
     //     gPad->SetLogx(1);
     gPad->SetLogy(1);
     //     gPad->SetLeftMargin(0.15);
     //     gPad->SetRightMargin(0.05);
     //     gPad->SetBottomMargin(0.15);
     //     gPad->SetTopMargin(0.05);
  }

  ch1->cd();


	TFile* mvafile = new TFile( mvaname.c_str() );
	if (!mvafile) {
		cout << "==> Abort, please verify filename" << endl;
		return;
	}
	else cout << "MVA file " << mvaname << ": " << mvafile << " opened!" << endl;
/*
	TTree *tree = (TTree*)mvafile->Get("event");
	int nentries = tree->GetEntries();
	cout << " MVA tree " << tree << " with " << nentries << " entries opened" << endl;
*/

	samptree = (TTree *)  gDirectory->FindObject(treename.c_str());

	string oldtitle = "";
	if( samptree ) oldtitle = samptree->GetTitle();

	if( oldtitle == mvaname )
		 cout << "Old MVA tree found in memory: " << treename << "  " << oldtitle << endl;
	else
		 {
		 if( samptree) gDirectory->Delete(treename.c_str());

		 TFile* mvafile = new TFile( mvaname.c_str() );
		 if (!mvafile)
			 {
			 cout << "==> Abort, please verify filename" << endl;
			 return;
			 }

		samptree = (TTree *)(mvafile->FindObjectAny(treename.c_str()));

		samptree->SetTitle(mvaname.c_str());

		int nentries = samptree->GetEntries();

		cout << " MVA tree " << treename << " with " << nentries << " opened" << endl;
		}


	// book signal and background histograms

	for(int isamp=0; isamp<nsamp; isamp++){

		string hname = sampname[isamp] + "_hist";
		if( gDirectory->FindObject(hname.c_str())!=NULL) gDirectory->Delete(hname.c_str());

		samphist[isamp] = new TH1D(hname.c_str(),"MVA response",nbin,xmin,xmax);

		// project variable on the histo above
		//tree->Project( hname.c_str(), varname.c_str(), wcuts[isamp].c_str() );
		samptree->Project( hname.c_str(), varname.c_str(), wcuts[isamp].c_str() );

		cout << " Histogram " << hname << " with "
				 << samphist[isamp]->GetSumOfWeights() << " weighted events" << endl;

		if (isamp == 0) nbgevt = samphist[isamp]->GetSumOfWeights();
		if (isamp == 1) nsigevt = samphist[isamp]->GetSumOfWeights();

	}

	int sig_nentries = samphist[1]->GetEntries();
	double sig_preseff = sig_nentries/100000.;

	//nbgevt = samphist[0]->GetSumOfWeights();
	//nsigevt = samphist[1]->GetSumOfWeights();

	// draw histograms

	if( gDirectory->FindObject("rsignal")!=NULL) gDirectory->Delete("rsignal");
  TH1D *rsignal = new TH1D("rsignal","MVA response",nbin,xmin,xmax);

  rsignal->Add(samphist[1]);
  if(rebin>1)rsignal->Rebin(rebin);

  rsignal->SetLineWidth(2);
  if(ipat>1)rsignal->SetLineWidth(1);
  rsignal->SetLineColor(4);
  rsignal->SetLineStyle(ipat);

  if( gDirectory->FindObject("rbg")!=NULL) gDirectory->Delete("rbg");
  TH1D *rbg = new TH1D("rbg","MVA response",nbin,xmin,xmax);

  rbg->Add(samphist[0]);
  if(rebin>1)rbg->Rebin(rebin);

  rbg->SetLineWidth(2);
  if(ipat>1)rbg->SetLineWidth(1);
  rbg->SetLineColor(2);
  rbg->SetLineStyle(ipat);

  rbg->SetMinimum(0.03);
  //rbg->SetMaximum(5000.);
  rbg->GetXaxis()->SetTitle("BDT response");
  rbg->GetYaxis()->SetTitle("Events");

	if(ipat==1)
  	rbg->Draw("hist");
  else
    rbg->Draw("hist same");

  rsignal->Draw("hist same");

  ch1->Update();

	double *sigeffi = new double[nbin];
  double *bgeffi = new double[nbin];

	int ifirst=0;

	double *signif = new double[nbin];
	double best_signif = 0.;

	double *bdtcut = new double[nbin];
	double best_bdtcut = 0;

	double fsigeff = 0;
	double fbgeff = 0;

	double fnsigevt = 0;
	double fnbgevt = 0;

	for(int ibin=0;ibin<nbin;ibin++) {

		bgeffi[ibin]    = (ibin>0) ? bgeffi[ibin-1]  : 0.;
		if(bgeffi[ibin] == 0) ifirst = ibin;

		bgeffi[ibin]  += samphist[0]->GetBinContent(nbin-ibin) / nbgevt;

		sigeffi[ibin]   = (ibin>0) ? sigeffi[ibin-1]  : 0.;
		sigeffi[ibin]  += samphist[1]->GetBinContent(nbin-ibin) / nsigevt;

		if(bgeffi[ibin] == 0) continue;

		bdtcut[ibin] = xmax - (ibin+1)*(xmax-xmin)/nbin;

		double sig_aftercut = sigeffi[ibin]*nsigevt;
		double bg_aftercut = bgeffi[ibin]*nbgevt;
		signif[ibin] = sig_aftercut / sqrt(sig_aftercut + bg_aftercut);
		if(signif[ibin] > best_signif && sig_preseff*sigeffi[ibin] >= 0.1) {
			best_signif = signif[ibin];
			best_bdtcut = bdtcut[ibin];
			fsigeff = sigeffi[ibin];
			fbgeff = bgeffi[ibin];
			fnsigevt = sig_aftercut;
			fnbgevt = bg_aftercut;
		}
/*
		if(bdtcut > 0.15) {
		  cout << "BDT > " << bdtcut << ": " << signif << " sigma" << endl;
			cout << "Signal: " << sigeffi[ibin] << " eff. and " << sig_aftercut << " events." << endl;
			cout << "Bin " << nbin-ibin << " content: " << samphist[1]->GetBinContent(nbin-ibin) << " evts." << endl;
			cout << "Backg.: " << bgeffi[ibin] << " eff. and " << bg_aftercut << " events." << endl;
			cout << "Bin " << nbin-ibin << " content: " << samphist[0]->GetBinContent(nbin-ibin) << " evts." << endl;
			cout << endl;
		}
*/
	}
/*
	cout << "For " << nsigevt << " signal events and " << nbgevt << " events, found highest significance "
	<< best_signif << " cutting on BDT = " << best_bdtcut << endl;
	cout << "Signal: " << fsigeff << " eff. and " << fnsigevt << " events." << endl;
	cout << "Backg.: " << fbgeff << " eff. and " << fnbgevt << " events." << endl;
	cout << endl;
*/

	//cout << "(nsig,    nbg)        BDT_cut signif. sig_eff bg_eff" << endl;
	cout << "BDT " << chname << "  (" << nsigevt << ", " << nbgevt << ")  " << best_bdtcut << "  " << best_signif
	<< "  " << fsigeff << "  " << fbgeff << endl;

	for(int isamp=0; isamp<nsamp; isamp++){
 		string hname = sampname[isamp] + "_hist";
 		if( gDirectory->FindObject(hname.c_str())!=NULL) gDirectory->Delete(hname.c_str());
	}

	TCanvas  *ch3 = (TCanvas *) gROOT->FindObject("ch3");

	if(!ch3  || label.length()==0)
		{
			if(!ch3)
				 ch3 = new TCanvas("ch3","Significance plot",620,20,600,450);
			else
				{
				 ch3->cd();
				 ch3->Clear();
				}

		 //gPad->SetLogx(1);
		 //gPad->SetLogy(1);

		 double xtabsig[2] = { -0.56, 0.32};
		 double ytabsig[2] = { 0., best_signif*1.2};

		 TGraph* myframesig = new TGraph(2,xtabsig,ytabsig);
		 myframesig->SetNameTitle("myframesig","");
		 myframesig->SetMarkerColor(8);

		 myframesig->GetXaxis()->SetTitle("BDT cut");
		 myframesig->GetYaxis()->SetTitle("Significance");


		 myframesig->Draw("AWP");

		}

	ch3->cd();

	TGraph *sigval = new TGraph(nbin-ifirst,bdtcut+ifirst,signif+ifirst);
	sigval->SetNameTitle("sigval","");

	sigval->SetLineWidth(iwid);
	sigval->SetLineColor(icol);
	sigval->SetLineStyle(ipat);

	sigval->Draw("L");

	ch3->Update();
	ch3->Print(("./plots/"+chname+"_SigVsCut.jpg").c_str());

}
/*
void OptimiseForAllScenarios(string shell = "off") {

	int nscen = 15;
	string scenarios[15] = {"BP18", "HP2", "HP3", "HP5", "HP6", "HP11", "HP12",
													"HP13", "HP14", "HP15", "HP16", "HP17", "HP18",
													"HP19", "HP20" };

	for(int iscen = 0; iscen<nscen; iscen++) {

		string filename = scenarios[iscen] + "_classified.root";
		cut_optimisation(filename);
		gDirectory->pwd();

	}

}
*/
