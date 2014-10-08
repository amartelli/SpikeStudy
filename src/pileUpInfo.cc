#include "DPGTask/SpikeStudy/interface/pileUpInfo.h"

pileUpInfo::pileUpInfo(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  if(debug) std::cout<<"in pileUpInfo constructor"<<std::endl;
  pileUpLabel_      = iConfig.getUntrackedParameter<edm::InputTag> ("pileUpLabel_");
  if(debug) std::cout<<"in pileup constructor: calling SetBrances()"<<std::endl;
  SetBranches();
}

pileUpInfo::~pileUpInfo(){
  delete tree_;
}

void pileUpInfo::Fill(const edm::Event& iEvent){

  if(debug_)    std::cout<<"getting pileup info"<<std::endl;
  Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(pileUpLabel_, PupInfo);

  std::vector<PileupSummaryInfo>::const_iterator PVI;
  npuVertices      = 0;
  npuVerticesms    = 0;
  npuVerticesps    = 0;
  trueInteractions = 0.;

  for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
    if(PVI->getBunchCrossing()==  0){ npuVertices   += PVI->getPU_NumInteractions(); }
    if(PVI->getBunchCrossing() <  0){ npuVerticesms += PVI->getPU_NumInteractions(); }
    if(PVI->getBunchCrossing() >  0){ npuVerticesps += PVI->getPU_NumInteractions(); }
    if(PVI->getBunchCrossing() == 0)trueInteractions = PVI->getTrueNumInteractions();

    if(debug_)std::cout << " Pileup Information: bunchXing, nvtx,true nvtx: " << PVI->getBunchCrossing() << " " << PVI->getPU_NumInteractions()<< " "<< PVI->getTrueNumInteractions()<< std::endl;

  }//loop over pileup info

  if(debug_)    std::cout<<"got pileup info"<<std::endl;
}

void pileUpInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&npuVertices     ,"npuVertices");
  AddBranch(&npuVerticesms   ,"npuVerticesms");
  AddBranch(&npuVerticesps   ,"npuVerticesps");
  AddBranch(&trueInteractions,"trueInteractions");
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

