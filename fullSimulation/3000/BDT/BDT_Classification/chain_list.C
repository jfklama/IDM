#include <TROOT.h>
#include <TChain.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TChain* chain_list(const char* filelist="scan_root.list",const char* chainname="scan_chain")
{
  const std::string treename = "event"; // this is fixed

  // Try to use "old" chain

  TChain *mychain = (TChain *) gROOT->FindObject(chainname);

  if(mychain)
    {
      std::string oldlist = mychain->GetTitle();
      std::string newlist = std::string(filelist);

      if(oldlist!=newlist)
	{
	mychain->Clear();
	delete mychain;
	mychain = NULL;
	std::cout << "Deleting old chain - file list name changed " << std::endl;
	}
      else
	std::cout << "File list name unchanged - returning pointer to old chain!" << std::endl;
    }


  if(! mychain)
     {
       mychain = new TChain(treename.c_str(),filelist);

       std::ifstream inputFile;
       inputFile.open(filelist,std::ios::in);


       bool inputOK = true;

       std::cout << "[" ;

        while(inputOK)
          {
          std::string filename;

           inputFile >> filename;

           if(inputFile.good())
              {
		     cout << "Adding root file: " << filename << endl;

	      //std::cout << "+" ;

              mychain->AddFile(filename.c_str());
              }
          else
             inputOK=false;
           }

        inputFile.close();

	std::cout  << "]" << std::endl;

	mychain->SetName(chainname);
     }

  return  mychain;

}
