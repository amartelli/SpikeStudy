#ifndef __RECHIT_INFO_H_
#define __RECHIT_INFO_H_

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
#include "DPGTask/SpikeStudy/interface/crystalInfo.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EcalDetIdCollections.h"
#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "CondFormats/DataRecord/interface/EcalGainRatiosRcd.h"
#include "CondFormats/DataRecord/interface/EcalPedestalsRcd.h"
#include "CondFormats/DataRecord/interface/EcalWeightXtalGroupsRcd.h"
#include "CondFormats/DataRecord/interface/EcalTBWeightsRcd.h"
#include "CondFormats/DataRecord/interface/EcalSampleMaskRcd.h"
#include "CondFormats/DataRecord/interface/EcalTimeCalibConstantsRcd.h"
#include "CondFormats/DataRecord/interface/EcalTimeOffsetConstantRcd.h"

#include "CondFormats/EcalObjects/interface/EcalTimeCalibConstants.h"
#include "CondFormats/EcalObjects/interface/EcalTimeOffsetConstant.h"
#include "CondFormats/EcalObjects/interface/EcalPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalGainRatios.h"
#include "CondFormats/EcalObjects/interface/EcalWeightXtalGroups.h"
#include "CondFormats/EcalObjects/interface/EcalTBWeights.h"
#include "CondFormats/EcalObjects/interface/EcalSampleMask.h"
#include "SimCalorimetry/EcalSimAlgos/interface/EBShape.h"
#include "SimCalorimetry/EcalSimAlgos/interface/EEShape.h"

#include "RecoLocalCalo/EcalRecProducers/interface/EcalUncalibRecHitWorkerBaseClass.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitRecWeightsAlgo.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitRecChi2Algo.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitRatioMethodAlgo.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitLeadingEdgeAlgo.h"


using namespace std;

class rechitInfo : public baseTree{

 public:
  rechitInfo(std::string name, TTree* tree, bool debug, const edm::ParameterSet& cfg);
  ~rechitInfo();
  void Fill(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  void Set(const edm::EventSetup& iSetup);
  void SetBranches();
  void Clear();


  edm::ESHandle<EcalPedestals> peds;
  edm::ESHandle<EcalGainRatios>  gains; 
  edm::ESHandle<EcalWeightXtalGroups>  grps;
  edm::ESHandle<EcalTBWeights> wgts;
  edm::ESHandle<EcalSampleMask> sampleMaskHand_;
  edm::ESHandle<EcalTimeCalibConstants> itime;
  edm::ESHandle<EcalTimeOffsetConstant> offtime;


  double pedVec[3];
  double pedRMSVec[3];
  double gainRatios[3];
  
  const EcalWeightSet::EcalWeightMatrix* weights[2];
  EcalUncalibRecHitRecWeightsAlgo<EBDataFrame> weightsMethod_barrel_;
  const EBShape testbeamEBShape; 

  EcalUncalibRecHitRatioMethodAlgo<EBDataFrame> ratioMethod_barrel_;  

 private:
  rechitInfo(){};
  edm::InputTag rechitBLabel_;
  bool fillrechitInfo_;

  //variables which would become branches
  int Rechit_n;
};

#endif

