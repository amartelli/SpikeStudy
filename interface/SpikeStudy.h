#ifndef  SPIKE_STUDY_H
#define  SPIKE_STUDY_H

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DPGTask/SpikeStudy/interface/eventInfo.h"
#include "DPGTask/SpikeStudy/interface/rechitInfo.h"
#include "DPGTask/SpikeStudy/interface/pileUpInfo.h"
#include "DPGTask/SpikeStudy/interface/superClusterInfo.h"
#include "DPGTask/SpikeStudy/interface/vertexInfo.h"
#include "DPGTask/SpikeStudy/interface/trackInfo.h"

#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"

#ifdef __MAKECINT__
#pragma link C++ class std::vector<std::vector<int> >+;
#pragma link C++ class std::vector<std::vector<std::string> >+;
#pragma link C++ class std::vector<std::vector<TString> >+;
#pragma link C++ class std::vector<std::vector<float> >+;
#pragma link C++ class std::vector<std::vector<bool> >+;
#pragma extra_include "std::vector";
#endif

class SpikeStudy : public edm::EDAnalyzer {
   public:
      explicit SpikeStudy(const edm::ParameterSet&);
      ~SpikeStudy();


   private:
      virtual void beginJob() ;
      virtual void beginRun(const edm::Run& , const edm::EventSetup&);
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
      TFile* file;
      TTree* tree_;
      const size_t MaxN;

      bool debug_;
      bool filleventInfo_;
      bool fillrechitInfo_;
      bool fillsuperClusterInfo_;
      bool fillpileUpInfo_;
      bool fillvertexInfo_;
      bool filltrackInfo_;
      
      rechitInfo       *rechitInfo_;
      eventInfo        *eventInfo_;
      pileUpInfo      *pileUpInfo_;
      superClusterInfo *superClusterInfo_;
      vertexInfo       *vertexInfo_;
      trackInfo        *trackInfo_;
      
};


#endif
