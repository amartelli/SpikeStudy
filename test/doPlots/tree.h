//////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri May 31 15:28:06 2013 by ROOT version 5.34/03
// from TTree tree/tree
// found on file: MinBias_612_effective_withPileup.root//////////////////////////////////////////////////////////

#ifndef tree_h
#define tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TBranch.h>
#include "TH1.h"
#include <TH2.h>
#include <TMinuit.h>
#include <TRandom.h>
#include <string>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <stdio.h>
#include <TString.h>
#include <TH1F.h>
#include <TLorentzVector.h>
#include <TClonesArray.h>
#include <TH2F.h>
#include <TH1I.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TList.h>
#include <Riostream.h>
#include <TGraphAsymmErrors.h>
#include <TMap.h>
#include <vector>
#ifdef __MAKECINT__
#pragma link C++ class vector<std::vector<int> >+;
#pragma link C++ class vector<std::vector<std::string> >+;
#pragma link C++ class vector<std::vector<float> >+;
#pragma link C++ class vector<std::vector<bool> >+;
#pragma extra_include "vector";
#endif

// Fixed size dimensions of array or collections stored in the TTree if any.

class tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   TFile *fileName;

   TH1F *h_spikeDigis ;
   TH2F *h_1, *h_2, *h_3, *h_4, *h_5, *h_4_bis, *h_4_bis_E4, *h_4_bis_Eb5, *h_4_bis_E10, *h_4_bis_Et3, *h_4_OOTp15ns, *h_4_OOTn15ns, *h_4_pm5ns, *h_4_pm15ns;
   TH2F *h_4_vsPU, *h_4_vsPU_it, *h_4_vsPU_ms, *h_4_vsPU_ps;
   TH2F *h_1_tracks, *h_2_tracks, *h_3_tracks, *h_4_tracks, *h_5_tracks;
   
   TH2F *h_rechit_swissCross_PU;
   TH2F *h_rechit_spike_swissCross_PU;
   TH2F *h_rechit_spike_swissCross_ieta_50, *h_rechit_spike_swissCross_PU_50, *h_rechit_spike_swissCross_ieta_50_10;
   TH2F *h_rechit_spike_swissCross_PU_100;

   TH2F *h_rechit_spike_swissCross_energy;
   TH2F *h_rechit_spike_swissCross_energy_50;
   TH2F *h_rechit_spike_swissCross_energy_kWeird;
   TH2F *h_rechit_spike_swissCross_energy_kW_tag;
   TH2F *h_rechit_spike_swissCross_ieta_kWeird, *h_rechit_spike_swissCross_ieta_kWeird_10;


   TH2F *h_rechit_e4_ieta, *h_rechit_e4_PU;
   TH2F *h_rechit_spike_e4_ieta, *h_rechit_spike_e4_PU;
   TH2F *h_rechit_spike_e4_ieta_50, *h_rechit_spike_e4_PU_50;
   TH2F *h_rechit_spike_e4_ieta_100, *h_rechit_spike_e4_PU_100;

   TH2F *h_rechit_e1_ieta, *h_rechit_e1_PU;
   TH2F *h_rechit_spike_e1_ieta, *h_rechit_spike_e1_PU;
   TH2F *h_rechit_spike_e1_ieta_50, *h_rechit_spike_e1_PU_50;
   TH2F *h_rechit_spike_e1_ieta_100, *h_rechit_spike_e1_PU_100;

   TH1F *h_vertices;
   TH2F *h_tracks_vertices, *h_tracks_Goodvertices, *h_rechits_vertices, *h_rechits_Goodvertices, *h_rechits_vertices_1, *h_rechits_Goodvertices_1;

   TH1F *h_rechit_energy_all, *h_rechit_energy_kWeird, *h_rechit_energy_swissCross;
   TH1F *h_rechit_spike_energy, *h_rechit_spike_energy_50, *h_rechit_spike_energy_100, *h_rechit_spike_energy_kWeird;

   TH1F *h_rechit_time_all, *h_rechit_time_kWeird, *h_rechit_time_swissCross;
   TH1F *h_rechit_spike_time, *h_rechit_spike_time_50,   *h_rechit_spike_time_100;  

   TH2F* h_rechit_time_vs_SwissCross;
   TH2F* h_rechit_time_vs_spike_energy_50;
   //   TProfile* h_rechitSpike_energy_50_vs_recHitTime;
   
   // Declaration of leaf types
   vector<float>   *Rechit_energy;
   vector<float>   *Rechit_et;
   vector<float>   *Rechit_time;
   vector<bool>    *Rechit_ifkWeird;
   vector<bool>    *Rechit_ifkDiWeird;
   vector<bool>    *Rechit_ifkOOT;
   vector<bool>    *Rechit_ifnearCrack;
   vector<float>   *Rechit_e4e1;
   vector<float>   *Rechit_swissCross;
   vector<float>   *Rechit_e6e2;
   vector<int>     *Rechit_ieta;
   vector<int>     *Rechit_iphi;
   vector<bool>    *Rechit_is_spike;
   vector<bool>    *Rechit_is_L1_spike;
   vector<bool>    *Rechit_is_spike_50_counts;
   vector<bool>    *Rechit_is_spike_100_counts;
   vector<int>     *Rechit_TT_index;
   vector<int>     *Rechit_TT_Et;
   vector<int>     *APDhit_max_adc;
   vector<int>     *APDhit_max_sample;
   vector<bool>    *APDhit_50_counts;
   vector<bool>    *APDhit_100_counts;
   vector<float>   *SC_energy;
   vector<float>   *SC_seed_energy;
   vector<float>   *SC_seed_time;
   vector<bool>    *SC_seed_ifkWeird;
   vector<bool>    *SC_seed_ifkDiWeird;
   vector<bool>    *SC_seed_ifkOOT;
   vector<bool>    *SC_seed_ifnearCrack;
   vector<float>   *SC_seed_e4e1;
   vector<float>   *SC_seed_swissCross;
   vector<float>   *SC_seed_e6e2;
   vector<int>     *SC_seed_ieta;
   vector<int>     *SC_seed_iphi;
   Int_t           Vertex_n;
   Int_t           npuVertices;
   Int_t           npuVerticesms;
   Int_t           npuVerticesps;
   vector<float>   *Vertex_chi2;
   vector<float>   *Vertex_d0;
   vector<int>     *Vertex_tracksize;
   vector<int>     *Vertex_ndof;
   vector<bool>    *Vertex_isFake;
   TClonesArray    *Vertex_position;
   Int_t           Track_n;
   TClonesArray    *Track_3Momentum;
   TClonesArray    *Track_Vposition;
   Bool_t          Scraping_isScrapingEvent;

   // List of branches
   TBranch        *b_Rechit_energy;   //!
   TBranch        *b_Rechit_et;   //!
   TBranch        *b_Rechit_time;   //!
   TBranch        *b_Rechit_ifkWeird;   //!
   TBranch        *b_Rechit_ifkDiWeird;   //!
   TBranch        *b_Rechit_ifkOOT;   //!
   TBranch        *b_Rechit_ifnearCrack;   //!
   TBranch        *b_Rechit_e4e1;   //!
   TBranch        *b_Rechit_swissCross;   //!
   TBranch        *b_Rechit_e6e2;   //!
   TBranch        *b_Rechit_ieta;   //!
   TBranch        *b_Rechit_iphi;   //!
   TBranch        *b_Rechit_is_spike;   //!
   TBranch        *b_Rechit_is_L1_spike;   //!
   TBranch        *b_Rechit_is_spike_50_counts;   //!
   TBranch        *b_Rechit_is_spike_100_counts;   //! 
   TBranch        *b_Rechit_TT_index;   //!
   TBranch        *b_Rechit_TT_Et;   //!
   TBranch        *b_APDhit_max_adc;   //!
   TBranch        *b_APDhit_max_sample;   //!
   TBranch        *b_APDhit_50_counts;   //!
   TBranch        *b_APDhit_100_counts;   //! 
   TBranch        *b_SC_energy;   //!
   TBranch        *b_SC_seed_energy;   //!
   TBranch        *b_SC_seed_time;   //!
   TBranch        *b_SC_seed_ifkWeird;   //!
   TBranch        *b_SC_seed_ifkDiWeird;   //!
   TBranch        *b_SC_seed_ifkOOT;   //!
   TBranch        *b_SC_seed_ifnearCrack;   //!
   TBranch        *b_SC_seed_e4e1;   //!
   TBranch        *b_SC_seed_swissCross;   //!
   TBranch        *b_SC_seed_e6e2;   //!
   TBranch        *b_SC_seed_ieta;   //!
   TBranch        *b_SC_seed_iphi;   //!
   TBranch        *b_Vertex_n;   //!
   TBranch        *b_npuVertices;    //!
   TBranch        *b_npuVerticesms;   //!
   TBranch        *b_npuVerticesps;  //!
   TBranch        *b_Vertex_chi2;   //!
   TBranch        *b_Vertex_d0;   //!
   TBranch        *b_Vertex_tracksize;   //!
   TBranch        *b_Vertex_ndof;   //!
   TBranch        *b_Vertex_isFake;   //!
   TBranch        *b_Vertex_position;   //!
   TBranch        *b_Track_n;   //!
   TBranch        *b_Track_3Momentum;   //!
   TBranch        *b_Track_Vposition;   //!
   TBranch        *b_Scraping_isScrapingEvent;   //!
   tree(const char* file1, const char* file2);
   virtual ~tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool  VertexDecision(int &foundVertex);
   virtual void     BookHistos(const char* file2);
};

#endif

#ifdef tree_cxx
tree::tree(const char* file1, const char* file2) : fChain(0)                      
{          

  TChain *chain = new TChain("demo/tree");
  //chain->Add("/afs/cern.ch/work/s/sandhya/public/Files/Data_Run2012C_MinimumBias_1.root");
  //chain->Add("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_612_effective_withPileup_14TeV_check1.root");
  //chain->Add("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_612_14TeV_check.root");
  //chain->Add("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_612_8TeV_arabella_check.root");
  
  chain->Add(file1);
  
  Init(chain);
  BookHistos(file2);
}

tree::~tree()
{
  if (!fChain) return;     
    delete fChain->GetCurrentFile();
    fileName->cd();      
    fileName->Write();                
    fileName->Close(); 
}

Int_t tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree::LoadTree(Long64_t entry)
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

void tree::Init(TChain *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Rechit_energy = 0;
   Rechit_et = 0;
   Rechit_time = 0;
   Rechit_ifkWeird = 0;
   Rechit_ifkDiWeird = 0;
   Rechit_ifkOOT = 0;
   Rechit_ifnearCrack = 0;
   Rechit_e4e1 = 0;
   Rechit_swissCross = 0;
   Rechit_e6e2 = 0;
   Rechit_ieta = 0;
   Rechit_iphi = 0;
   Rechit_is_spike = 0;
   Rechit_is_L1_spike = 0;
   Rechit_is_spike_50_counts = 0;
   Rechit_is_spike_100_counts = 0;
   Rechit_TT_index = 0;
   Rechit_TT_Et = 0;
   APDhit_max_adc = 0;
   APDhit_max_sample = 0;
   APDhit_50_counts = 0;
   APDhit_100_counts = 0;
   SC_energy = 0;
   SC_seed_energy = 0;
   SC_seed_time = 0;
   SC_seed_ifkWeird = 0;
   SC_seed_ifkDiWeird = 0;
   SC_seed_ifkOOT = 0;
   SC_seed_ifnearCrack = 0;
   SC_seed_e4e1 = 0;
   SC_seed_swissCross = 0;
   SC_seed_e6e2 = 0;
   SC_seed_ieta = 0;
   SC_seed_iphi = 0;
   Vertex_chi2 = 0;
   Vertex_d0 = 0;
   Vertex_tracksize = 0;
   Vertex_ndof = 0;
   Vertex_isFake = 0;
   Vertex_position = 0;
   Track_3Momentum = 0;
   Track_Vposition = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Rechit_energy", &Rechit_energy, &b_Rechit_energy);
   fChain->SetBranchAddress("Rechit_et", &Rechit_et, &b_Rechit_et);
   fChain->SetBranchAddress("Rechit_time", &Rechit_time, &b_Rechit_time);
   fChain->SetBranchAddress("Rechit_ifkWeird", &Rechit_ifkWeird, &b_Rechit_ifkWeird);
   fChain->SetBranchAddress("Rechit_ifkDiWeird", &Rechit_ifkDiWeird, &b_Rechit_ifkDiWeird);
   fChain->SetBranchAddress("Rechit_ifkOOT", &Rechit_ifkOOT, &b_Rechit_ifkOOT);
   fChain->SetBranchAddress("Rechit_ifnearCrack", &Rechit_ifnearCrack, &b_Rechit_ifnearCrack);
   fChain->SetBranchAddress("Rechit_e4e1", &Rechit_e4e1, &b_Rechit_e4e1);
   fChain->SetBranchAddress("Rechit_swissCross", &Rechit_swissCross, &b_Rechit_swissCross);
   fChain->SetBranchAddress("Rechit_e6e2", &Rechit_e6e2, &b_Rechit_e6e2);
   fChain->SetBranchAddress("Rechit_ieta", &Rechit_ieta, &b_Rechit_ieta);
   fChain->SetBranchAddress("Rechit_iphi", &Rechit_iphi, &b_Rechit_iphi);
   fChain->SetBranchAddress("Rechit_is_spike", &Rechit_is_spike, &b_Rechit_is_spike);
   fChain->SetBranchAddress("Rechit_is_L1_spike", &Rechit_is_L1_spike, &b_Rechit_is_L1_spike);
   fChain->SetBranchAddress("Rechit_is_spike_50_counts", &Rechit_is_spike_50_counts, &b_Rechit_is_spike_50_counts);
   fChain->SetBranchAddress("Rechit_is_spike_100_counts", &Rechit_is_spike_100_counts, &b_Rechit_is_spike_100_counts);
   fChain->SetBranchAddress("Rechit_TT_index", &Rechit_TT_index, &b_Rechit_TT_index);
   fChain->SetBranchAddress("Rechit_TT_Et", &Rechit_TT_Et, &b_Rechit_TT_Et);
   fChain->SetBranchAddress("APDhit_max_adc", &APDhit_max_adc, &b_APDhit_max_adc);
   fChain->SetBranchAddress("APDhit_max_sample", &APDhit_max_sample, &b_APDhit_max_sample);
   fChain->SetBranchAddress("APDhit_50_counts", &APDhit_50_counts, &b_APDhit_50_counts);
   fChain->SetBranchAddress("APDhit_100_counts", &APDhit_100_counts, &b_APDhit_100_counts);
   fChain->SetBranchAddress("SC_energy", &SC_energy, &b_SC_energy);
   fChain->SetBranchAddress("SC_seed_energy", &SC_seed_energy, &b_SC_seed_energy);
   fChain->SetBranchAddress("SC_seed_time", &SC_seed_time, &b_SC_seed_time);
   fChain->SetBranchAddress("SC_seed_ifkWeird", &SC_seed_ifkWeird, &b_SC_seed_ifkWeird);
   fChain->SetBranchAddress("SC_seed_ifkDiWeird", &SC_seed_ifkDiWeird, &b_SC_seed_ifkDiWeird);
   fChain->SetBranchAddress("SC_seed_ifkOOT", &SC_seed_ifkOOT, &b_SC_seed_ifkOOT);
   fChain->SetBranchAddress("SC_seed_ifnearCrack", &SC_seed_ifnearCrack, &b_SC_seed_ifnearCrack);
   fChain->SetBranchAddress("SC_seed_e4e1", &SC_seed_e4e1, &b_SC_seed_e4e1);
   fChain->SetBranchAddress("SC_seed_swissCross", &SC_seed_swissCross, &b_SC_seed_swissCross);
   fChain->SetBranchAddress("SC_seed_e6e2", &SC_seed_e6e2, &b_SC_seed_e6e2);
   fChain->SetBranchAddress("SC_seed_ieta", &SC_seed_ieta, &b_SC_seed_ieta);
   fChain->SetBranchAddress("SC_seed_iphi", &SC_seed_iphi, &b_SC_seed_iphi);
   fChain->SetBranchAddress("Vertex_n", &Vertex_n, &b_Vertex_n);
   fChain->SetBranchAddress("npuVertices", &npuVertices, &b_npuVertices);
   fChain->SetBranchAddress("npuVerticesms", &npuVerticesms, &b_npuVerticesms);
   fChain->SetBranchAddress("npuVerticesps", &npuVerticesps, &b_npuVerticesps);
   fChain->SetBranchAddress("Vertex_chi2", &Vertex_chi2, &b_Vertex_chi2);
   fChain->SetBranchAddress("Vertex_d0", &Vertex_d0, &b_Vertex_d0);
   fChain->SetBranchAddress("Vertex_tracksize", &Vertex_tracksize, &b_Vertex_tracksize);
   fChain->SetBranchAddress("Vertex_ndof", &Vertex_ndof, &b_Vertex_ndof);
   fChain->SetBranchAddress("Vertex_isFake", &Vertex_isFake, &b_Vertex_isFake);
   fChain->SetBranchAddress("Vertex_position", &Vertex_position, &b_Vertex_position);
   fChain->SetBranchAddress("Track_n", &Track_n, &b_Track_n);
   fChain->SetBranchAddress("Track_3Momentum", &Track_3Momentum, &b_Track_3Momentum);
   fChain->SetBranchAddress("Track_Vposition", &Track_Vposition, &b_Track_Vposition);
   fChain->SetBranchAddress("Scraping_isScrapingEvent", &Scraping_isScrapingEvent, &b_Scraping_isScrapingEvent);
   Notify();
}

Bool_t tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_cxx
