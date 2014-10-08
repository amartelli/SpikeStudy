#ifndef __BASE_TREE_H__
#define __BASE_TREE_H__

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "TTree.h"
#include "TROOT.h"
#include "TString.h"
#include "TClonesArray.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EcalDetIdCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"

typedef edm::ParameterSet pset;

class baseTree{
 public:
  baseTree(std::string identifier, TTree* tree, bool debug);
 ~baseTree(){delete tree_;};

 protected:
  baseTree(){}
  TTree* tree_;
  bool debug_;
  std::string identifier_; //eg. "pat"/"reco"
  void AddBranch(double* x, std::string name);
  void AddBranch(int* x, std::string name);
  void AddBranch(unsigned int* x, std::string name);
  void AddBranch(float* x, std::string name);
  void AddBranch(bool* x, std::string name);
  void AddBranch(std::vector<bool>* vec, std::string name);
  void AddBranch(std::vector<float>* vec, std::string name);
  void AddBranch(std::vector<int>* vec, std::string name);
  void AddBranch(std::vector<std::string>* vec, std::string name);
  void AddBranch(TClonesArray** vec, std::string name);
  void AddBranch(std::vector<std::vector<int> >* vec, std::string name);
  void AddBranch(std::vector<std::vector<float> >* vec, std::string name);
  void AddBranch(std::vector<std::vector<TString> >* vec, std::string name);

  float recHitE( const DetId id, const EcalRecHitCollection &recHits );
  float recHitApproxEt( const DetId id, const EcalRecHitCollection &recHits );

  const std::vector<DetId> neighbours(const DetId& id);
  float  e4e1(const DetId& id, const EcalRecHitCollection& rhs);
  float  swissCross(const DetId& id, const EcalRecHitCollection& rhs);
  float  Gete6e2(const DetId& id, const EcalRecHitCollection& rhs);

  };

#endif
