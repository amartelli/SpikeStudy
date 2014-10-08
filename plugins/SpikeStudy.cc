// system include files
#include <memory>
#include <string>

#include "DPGTask/SpikeStudy/interface/SpikeStudy.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

SpikeStudy::SpikeStudy(const edm::ParameterSet& iConfig):
  MaxN(200)
{
  debug_               = iConfig.getUntrackedParameter<bool>("debug_");
  filleventInfo_       = iConfig.getUntrackedParameter<bool>("filleventInfo_");
  fillrechitInfo_      = iConfig.getUntrackedParameter<bool>("fillrechitInfo_");
  fillsuperClusterInfo_= iConfig.getUntrackedParameter<bool>("fillsuperClusterInfo_");
  fillvertexInfo_      = iConfig.getUntrackedParameter<bool>("fillvertexInfo_");
  filltrackInfo_       = iConfig.getUntrackedParameter<bool>("filltrackInfo_");
  fillpileUpInfo_      = iConfig.getUntrackedParameter<bool>("fillpileUpInfo_");

  edm::Service<TFileService> fs;
  tree_ = fs->make<TTree>("tree","tree");

  if( filleventInfo_)         eventInfo_       = new eventInfo       ("pat", tree_, debug_, iConfig);
  if( fillrechitInfo_)        rechitInfo_      = new rechitInfo      ("pat", tree_, debug_, iConfig);
  if( fillsuperClusterInfo_)  superClusterInfo_= new superClusterInfo("pat", tree_, debug_, iConfig);
  if( fillvertexInfo_)        vertexInfo_      = new vertexInfo     ("pat", tree_, debug_, iConfig);
  if( filltrackInfo_)         trackInfo_       = new trackInfo      ("pat", tree_, debug_, iConfig);
  if( fillpileUpInfo_)        pileUpInfo_      = new pileUpInfo     ("pat", tree_, debug_, iConfig);
  if(debug_) std::cout<<"got all the objects and branches in the tree"<<std::endl;
}


SpikeStudy::~SpikeStudy()
{}

void
SpikeStudy::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){
  using namespace edm;
  if(debug_) std::cout<<"in main analyze function"<<std::endl;
  if( filleventInfo_)       eventInfo_       ->Fill(iEvent);
  if( fillrechitInfo_)      rechitInfo_      ->Fill(iEvent, iSetup);
  if( fillpileUpInfo_)      pileUpInfo_      ->Fill(iEvent);
  if( fillsuperClusterInfo_)superClusterInfo_->Fill(iEvent, iSetup);
  if( fillvertexInfo_)      vertexInfo_      ->Fill(iEvent);
  if( filltrackInfo_)       trackInfo_       ->Fill(iEvent);
  if(debug_) std::cout<<"ended main analyze function"<<std::endl;
  tree_->Fill();
}

void
SpikeStudy::beginJob(){
}

void
SpikeStudy::endJob() {
}

void SpikeStudy::beginRun(const edm::Run& iRun, const edm::EventSetup& iSetup){
}



DEFINE_FWK_MODULE(SpikeStudy);
