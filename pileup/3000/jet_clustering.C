//=================================
//
//     Jet clustering routines
//   
//=================================


// Global parameters
//-------------------

// Algorithm parameters

double Rval, Bval, Gval;

// Choice of enegy and angular variables (0/1 switches)

int Evar, Rvar;

// Output distance values

double ymin,ymax;
   
//  Jet distance definitions

double Jet2Jet_Distance(TLorentzVector &J1, TLorentzVector &J2)
{
  double DJJ;

  if(Rvar==0)
//  DJJ =    (1 - J1.Vect().Dot(J2.Vect())/J1.P()/J2.P());   // As implemented in LCFI+
    DJJ = 2.*(1 - J1.Vect().Dot(J2.Vect())/J1.P()/J2.P());   // As implemented in FastJet
  else
    {
    DJJ = J1.DeltaR(J2);
    DJJ = DJJ*DJJ;
    }
	   
  double EJ1 = (Evar==0)? J1.E() : J1.Pt() ;
  double EJ2 = (Evar==0)? J2.E() : J2.Pt() ;

  // if ( EJ1 < EJ2 )              // FastJet implementation: does not work for beta<0 => bad clustering

  if ( (EJ1 - EJ2)*Bval < 0 )      //  As properly implemented in LCFI+
      DJJ *=  pow(EJ1, 2*Bval);
  else
      DJJ *=  pow(EJ2, 2*Bval);

  DJJ/= Rval*Rval;

  return DJJ;
}

double Jet2Beam_Distance(TLorentzVector &J1)
{
   double EJ1 = (Evar==0)? J1.E() : J1.Pt() ;
   
   double DJB =  pow(EJ1,2*Bval) * pow(J1.Pt()/J1.P(),2*Gval);

   return DJB;
}

void DoJetClustering(std::vector<TLorentzVector> &ValJets, int ValReq, double Dmax=0.)
{
   // Prepare distance arrays for jet algorithm

   std::vector<double> DJBvec;

   double DJBmin = 1000000000.;
   int iBmin = -1;

   for(int iJ1=0; iJ1<ValJets.size(); iJ1++)
      {
      TLorentzVector J1 = ValJets[iJ1];
	   
      double DJB =  Jet2Beam_Distance(J1);
	 
      if(DJB < DJBmin)
	{
	DJBmin = DJB;
	iBmin = iJ1;
	}

      DJBvec.push_back(DJB);
      }


   typedef std::vector<double> DoubleVec;
   std::vector<DoubleVec>DJJvec;
   std::vector<double>DJJminvec;
   std::vector<int>iJJminvec;
   double DJJmin = 1000000000.;
   int iJJ1min = -1;
   int iJJ2min = -1;

   
   for(int iJ1=0; iJ1<ValJets.size(); iJ1++)
      {
      TLorentzVector J1 = ValJets[iJ1];
	   
      double DJ1min = 1000000000.;
      int iJ2min = -1;

      std::vector<double> DJ1vec;
      
      for(int iJ2=iJ1+1;iJ2<ValJets.size(); iJ2++)
	 {
	 TLorentzVector J2 = ValJets[iJ2];

	 double DJJ = Jet2Jet_Distance(J1,J2);

         DJ1vec.push_back(DJJ);
	 
	 if(DJJ < DJ1min)
	   {
	     DJ1min = DJJ;
	     iJ2min = iJ2;
	   }
	 }

      DJJvec.push_back(DJ1vec);

      DJJminvec.push_back(DJ1min);
      iJJminvec.push_back(iJ2min);

      if(DJ1min < DJJmin)
	 {
	  DJJmin = DJ1min;
	  iJJ1min = iJ1;
	  iJJ2min = iJ2min;
	 }
      }


   // Merge PFOs into given number of jets

	      
     int nValJets = ValJets.size();

     /*
     if(nEvent <= 10)
	   cout << endl << "Dumping jet algorithm performance, starting with N = " << nValJets << endl;
     */


     while(nValJets > ValReq )
        {

       // Interupt clustering if distance too large (!)
	  
       if(Dmax > 0. && DJBmin > Dmax && DJJmin > Dmax) break;


       // Control output
       /*
       if(iBmin < 0)
	   cerr << endl << "Something wrong: beam distance index not set for njet = " << nValJets << endl;
	  
       if((iJJ1min < 0 || iJJ2min < 0) && nValJets>1)
	   cerr << endl << "Something wrong: jet-jet distance index not set for njet = " << nValJets << endl;
	  
       if( DJBmin >= DJJmin && nValJets == 1 )
	   cerr << endl << "Something wrong: jet-jet distance set  for njet = " << nValJets << endl;
	  
       if( iBmin >= nValJets )
	   cerr << endl << "Something wrong: beam distance not set properly for njet = " << nValJets << endl;
       */
       
       if( DJBmin < DJJmin )
	 {
          ymin = DJBmin;

	  /*
	 if(nEvent <= 10)
	    cout << "Removing beam jet " << iBmin << " : " <<
	     ValJets[iBmin].E() << " GeV  at Theta = " << ValJets[iBmin].Theta() <<
	     " dist2beam = " << DJBmin << endl;
	  */
	  
	   // Remove beam jet
	   
	   ValJets.erase(ValJets.begin()+iBmin);

	   // Break if no jets left...

	   if(ValJets.size() == 0) break;
	   
	   // Remove corresponding entry in beam distance table
	   
	   DJBvec.erase(DJBvec.begin()+iBmin);

	   // Remove corresponding entries in jet-jet distance tables
	   
           for(int iJ1=0; iJ1<iBmin; iJ1++)
	     {
	     DJJvec[iJ1].erase(DJJvec[iJ1].begin()+iBmin-iJ1-1);

	     int ioldmin = iJJminvec[iJ1];
	     
	     if(ioldmin == iBmin)
	       {
                double DJ1min = 10000000.;
                int iJ2min = -1;
		 
		for(int iJ2=0;iJ2<DJJvec[iJ1].size(); iJ2++)
	           {
		     double DJJ = DJJvec[iJ1][iJ2];	 
   	             if(DJJ < DJ1min)
	                 {
	                 DJ1min = DJJ;
	                 iJ2min = iJ2+iJ1+1;
	                 }
	           }

		iJJminvec[iJ1] = iJ2min;
		DJJminvec[iJ1] = DJ1min;
	       }

	     if(ioldmin > iBmin)
	       iJJminvec[iJ1] = ioldmin - 1;

	     }
	   
	   // Correct closest jet indexes also for jets with higher ID
	   
           for(int iJ1=iBmin+1; iJ1 < iJJminvec.size(); iJ1++)
  	       iJJminvec[iJ1] = iJJminvec[iJ1] - 1;

	   
	   // Remove remaining entries now

	   DJJvec.erase(DJJvec.begin()+iBmin);
	   DJJminvec.erase(DJJminvec.begin()+iBmin);
	   iJJminvec.erase(iJJminvec.begin()+iBmin);
	     
	   // If removed jet was also corresponding to minimum jet-jet distance

	   int iJJ1old = iJJ1min;
	   int iJJ2old = iJJ2min;
	   
	   if(iJJ1min == iBmin || iJJ2min == iBmin)
	     {
	       
              DJJmin = 1000000000.;
              iJJ1min = -1;
              iJJ2min = -1;

   
	      for(int iJ1=0; iJ1<DJJminvec.size(); iJ1++)
	          {
		  double DJ1min = DJJminvec[iJ1];
		  
                  if(DJ1min < DJJmin)
	             {
	             DJJmin = DJ1min;
	             iJJ1min = iJ1;
	             iJJ2min = iJJminvec[iJ1];
	             }
                  }

 	     }

	   if(iJJ1old  > iBmin && iJJ2old != iBmin) iJJ1min--;
	   if(iJJ1old != iBmin && iJJ2old  > iBmin) iJJ2min--;

	   
	   // Find new minima in beam distance
	   
	   DJBmin = 1000000000.;
	   iBmin = -1;
	   
           for(int iJ1=0; iJ1<DJBvec.size(); iJ1++)
	     if(DJBvec[iJ1]<DJBmin)
	       {
		 DJBmin =  DJBvec[iJ1];
		 iBmin = iJ1;
	       }

 
	 }
       else
	 {

	   ymin = DJJmin;

	   /*
	   if(nEvent <= 10)
	     {
	   cout << "Merging two jets " << iJJ1min << " & " << iJJ2min << 
  	         " distance = " << DJJmin << endl;
	   cout << "   " <<  ValJets[iJJ1min].E() << " GeV  at Theta = " << ValJets[iJJ1min].Theta()
		<< " Phi = " << ValJets[iJJ1min].Phi() << endl;
	   cout << "   " <<  ValJets[iJJ2min].E() << " GeV  at Theta = " << ValJets[iJJ2min].Theta()
		<< " Phi = " << ValJets[iJJ2min].Phi() << endl;
	     }
	   */
	   
	   // Add the second jets to the first one 
	   
	   ValJets[iJJ1min]+=ValJets[iJJ2min];

	   // Remove second jet
	   
	   ValJets.erase(ValJets.begin()+iJJ2min);

	   // Remove corresponding entry in beam distance table
	   
	   DJBvec.erase(DJBvec.begin()+iJJ2min);

	   // Calculate beam distance for new jet

           TLorentzVector J1 = ValJets[iJJ1min];
	   
	   double DJB =  Jet2Beam_Distance(J1);

	   DJBvec[iJJ1min] = DJB;
  
	   // Find new minima in beam distance

	   if(DJB < DJBmin)
	     {
	       DJBmin = DJB;
	       iBmin = iJJ1min;
	     }
           else
	   if(iBmin == iJJ1min || iBmin == iJJ2min)
	     {
	     DJBmin = 1000000000.;
	     iBmin = -1;
	   
             for(int iJ1=0; iJ1<DJBvec.size(); iJ1++)
	       if(DJBvec[iJ1]<DJBmin)
	         {
		   DJBmin =  DJBvec[iJ1];
		   iBmin = iJ1;
	         }
	     }
	   else
	   if(iBmin > iJJ2min)
	     iBmin--;



	   // Remove corresponding entries in jet-jet distance tables
	   
           for(int iJ1=0; iJ1<iJJ2min; iJ1++)
	     {
	     DJJvec[iJ1].erase(DJJvec[iJ1].begin()+iJJ2min-iJ1-1);

	     int ioldmin = iJJminvec[iJ1];
	     
	     if(ioldmin == iJJ2min)
	       {
                double DJ1min = 1000000000.;
                int iJ2min = -1;
		 
		for(int iJ2=0;iJ2<DJJvec[iJ1].size(); iJ2++)
	           {
		     double DJJ = DJJvec[iJ1][iJ2];	 
   	             if(DJJ < DJ1min)
	                 {
	                 DJ1min = DJJ;
	                 iJ2min = iJ2+iJ1+1;
	                 }
	           }

		iJJminvec[iJ1] = iJ2min;
		DJJminvec[iJ1] = DJ1min;
	       }

	     if(ioldmin > iJJ2min)
	       iJJminvec[iJ1] = ioldmin - 1;

	     }

	   
	   // Correct closest jet indexes also for jets with higher ID
	   
           for(int iJ1=iJJ2min+1; iJ1 < iJJminvec.size(); iJ1++)
  	       iJJminvec[iJ1] = iJJminvec[iJ1] - 1;


	   // Remove remaining table entries
	   
	   DJJvec.erase(DJJvec.begin()+iJJ2min);
	   DJJminvec.erase(DJJminvec.begin()+iJJ2min);
	   iJJminvec.erase(iJJminvec.begin()+iJJ2min);


	   // Recalculate distances to the new jet

	   // For jets with smaller ID
	   
	   for(int iJ1=0;iJ1<iJJ1min; iJ1++)
 	     {
	      TLorentzVector J2 = ValJets[iJ1];

	      double DJJ = Jet2Jet_Distance(J1,J2);

	      DJJvec[iJ1][iJJ1min-iJ1-1] = DJJ;

	      if(DJJ < DJJminvec[iJ1])
		 {
		  DJJminvec[iJ1]=DJJ;
		  iJJminvec[iJ1]=iJJ1min;
		 }
	      else
	      if(iJJminvec[iJ1]==iJJ1min || iJJminvec[iJ1]==iJJ2min)
		{
                double DJ1min = 1000000000.;
                int iJ2min = -1;
		 
		for(int iJ2=0;iJ2<DJJvec[iJ1].size(); iJ2++)
	           {
		     double DJJ = DJJvec[iJ1][iJ2];	 
   	             if(DJJ < DJ1min)
	                 {
	                 DJ1min = DJJ;
	                 iJ2min = iJ2+iJ1+1;
	                 }
	           }

		iJJminvec[iJ1] = iJ2min;
		DJJminvec[iJ1] = DJ1min;
		}
	      
	     }

	   // For jets with higher ID
	   
           double DJ1min = 1000000000.;
           int iJ2min = -1;
		 
	   for(int iJ2=iJJ1min+1;iJ2<ValJets.size(); iJ2++)
 	     {
	      TLorentzVector J2 = ValJets[iJ2];

	      double DJJ =  Jet2Jet_Distance(J1,J2);
	   
	      DJJvec[iJJ1min][iJ2-iJJ1min-1] = DJJ;
	      
	      if(DJJ < DJ1min)
	        {
	        DJ1min = DJJ;
	        iJ2min = iJ2;
		}
	     }

	   DJJminvec[iJJ1min] = DJ1min;
	   iJJminvec[iJJ1min] = iJ2min;


	   // Find new global minima in jet-jet distance

          DJJmin = 1000000000.;
          iJJ1min = -1;
          iJJ2min = -1;
   
	  for(int iJ1=0; iJ1<ValJets.size(); iJ1++)
             {
             if(DJJminvec[iJ1] < DJJmin)
	        {
	        DJJmin = DJJminvec[iJ1];
	        iJJ1min = iJ1;
	        iJJ2min = iJJminvec[iJ1];
	        }
	     }
	   
	 }

       
       nValJets = ValJets.size();

       if( DJBmin < DJJmin )
         ymax = DJBmin;
       else
	 ymax = DJJmin;
       
     }

   // End of Valencia jet clustering

     /*
     if(nEvent<=10)
       {
	 cout << "Final jet configuration: " << endl;

	 for(int ijet=0; ijet<nValJets;ijet++)
	   cout << ijet+1 << " : " <<  ValJets[ijet].E() << " GeV  at Theta = " << ValJets[ijet].Theta()
		<< " Phi = " << ValJets[ijet].Phi() << endl;
	     
	       
	 cout << endl;
       }
     */
}

//
// Calculates the angular distance between two jet sets
// idtab[] stores relation from the Jet1 index to Jet2 index
//         i.e. the value of Jet2 index for given Jet1 index

double JetJetDist(TLorentzVector** Jet1, TLorentzVector** Jet2, int Njet, int *idtab = NULL, double *EneDist = NULL )
{
  
 // Number of combinations
   
  int Nall = 1;
  
  for(int ijet=Njet; ijet>1;ijet--)Nall*=ijet;
  
  double d2min = 1e+100;
  double e2min = 1e+100;

   for(int iperm = 0; iperm < Nall ; iperm++)
     {

       double dist2 = 0.;
       double edist2 = 0.;

       double shift[6];
       int ijfer[6];
       
       for(int i=0;i<Njet;i++)shift[i]=i;

       int tmp=iperm;

       //      cout << "Decoding permutation " << tmp << " : ";
       
       for(int iJet1=0; iJet1<Njet;iJet1++)
	 {
	   int j=tmp%(Njet-iJet1);

	   int iJet2=shift[j];

	   ijfer[iJet1]=iJet2;
	   
	   tmp/=(Njet-iJet1);
	   for(int i=j; i < Njet-iJet1-1; i++)shift[i]=shift[i+1];

	   double dist = Jet2[iJet2]->Angle(Jet1[iJet1]->Vect());
	   dist2+=dist*dist;

	   if(dist2 > d2min) break;

	   double edist = Jet2[iJet2]->E() - Jet1[iJet1]->E();
	   edist2+=edist*edist;
	 }
       
       if(dist2 < d2min)
	 {
	   d2min = dist2;
	   e2min = edist2;
           if(idtab)for(int i=0;i<Njet;i++)idtab[i]=ijfer[i];
	 }
     }

   if(EneDist) *EneDist = e2min;
   
   return d2min;
}

