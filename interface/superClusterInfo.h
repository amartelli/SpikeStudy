#ifndef __SUPERCLUSTER_INFO_H_
#define __SUPERCLUSTER_INFO_H_

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "TTree.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"


#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DPGTask/SpikeStudy/interface/utils.h"
#include "DPGTask/SpikeStudy/interface/baseTree.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"

using namespace std;

class superClusterInfo : public baseTree{

 public:
  superClusterInfo(std::string name, TTree* tree, bool debug, const edm::ParameterSet& cfg);
  ~superClusterInfo();
  void Fill(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  void Set(const edm::EventSetup& iSetup);
  void SetBranches();
  void Clear();


 private:
  superClusterInfo(){};
  edm::InputTag superClusterLabel_;
  edm::InputTag rechitBLabel_;
  bool fillsuperClusterInfo_;

  //variables which would become branches

  std::vector<float> SC_energy          ;
  std::vector<float> SC_seed_energy     ;
  std::vector<float> SC_seed_time       ;
  std::vector<bool>  SC_seed_ifkWeird   ;
  std::vector<bool>  SC_seed_ifkDiWeird ;
  std::vector<bool>  SC_seed_ifkOOT     ;
  std::vector<bool>  SC_seed_ifnearCrack;
  std::vector<float> SC_seed_e4e1       ;
  std::vector<float> SC_seed_swissCross ;
  std::vector<float> SC_seed_e6e2       ;
  std::vector<int>   SC_seed_ieta       ;
  std::vector<int>   SC_seed_iphi       ;

  };
#endif
