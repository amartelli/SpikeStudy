#include "DPGTask/SpikeStudy/interface/eventInfo.h"

eventInfo::eventInfo(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  if(debug) std::cout<<"in eventInfo constructor"<<std::endl;
  lumiLabel_             = iConfig.getUntrackedParameter<edm::InputTag> ("lumiLabel_");
  lumiProducerLabel_     = iConfig.getUntrackedParameter<edm::InputTag> ("lumiProducerLabel_");
  Event_n                = 0;
  if(debug) std::cout<<"in photon constructor: calling SetBrances()"<<std::endl;
  SetBranches();
}

eventInfo::~eventInfo(){
  delete tree_;
}

void eventInfo::Fill(const edm::Event& iEvent){

  if(debug_)    std::cout<<"getting event info"<<std::endl;
  RunNumber   = iEvent.id().run();
  EventNumber = iEvent.id().event();
  LumiNumber  = iEvent.id().luminosityBlock();
  BXNumber = iEvent.bunchCrossing();


  const edm::LuminosityBlock& iLumi = iEvent.getLuminosityBlock();
  edm::Handle<edm::ConditionsInLumiBlock> condInLumiBlock;
  iLumi.getByLabel(lumiLabel_, condInLumiBlock);

  if(not iLumi.getByLabel(lumiLabel_, condInLumiBlock)){
    std::cout<<"FATAL EXCEPTION: "<<"Following Not Found: "<<lumiLabel_<<std::endl; 
    exit(0);
  }  

  if(condInLumiBlock.isValid()){//check pointer condInLumiBlock is not null
    totalIntensityBeam1 = condInLumiBlock->totalIntensityBeam1;
    totalIntensityBeam2 = condInLumiBlock->totalIntensityBeam2;
  }
  else{
    totalIntensityBeam1 = -1;
    totalIntensityBeam2 = -1;
  }

  // get LumiSummary
  edm::Handle<LumiSummary> lumiSummary;
  iLumi.getByLabel(lumiProducerLabel_, lumiSummary);

  if(lumiSummary.isValid()){//check pointer lumiSummary is not null
    if(lumiSummary->isValid()){//data are valid only if run exists from all sources lumi,trg ,hlt
      avgInsDelLumi    = (float)lumiSummary->avgInsDelLumi();
      avgInsDelLumiErr = (float)lumiSummary->avgInsDelLumiErr();
      avgInsRecLumi    = (float)lumiSummary->avgInsRecLumi();
      avgInsRecLumiErr = (float)lumiSummary->avgInsRecLumiErr();
    }
  }
  else
    {
      avgInsDelLumi    = -1.;
      avgInsDelLumiErr = -1.;
      avgInsRecLumi    = -1.;
      avgInsRecLumiErr = -1.;
    }

  Event_n++;
  if(debug_)    std::cout<<"got event info"<<std::endl;
}

void eventInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&RunNumber,"RunNumber");
  AddBranch(&EventNumber,"EventNumber");
  AddBranch(&LumiNumber,"LumiNumber");
  AddBranch(&BXNumber,"BXNumber");
  AddBranch(&totalIntensityBeam1,"totalIntensityBeam1");
  AddBranch(&totalIntensityBeam2,"totalIntensityBeam2");
  AddBranch(&avgInsDelLumi,"avgInsDelLumi");
  AddBranch(&avgInsDelLumiErr,"avgInsDelLumiErr");
  AddBranch(&avgInsRecLumi,"avgInsRecLumi");
  AddBranch(&avgInsRecLumiErr,"avgInsRecLumiErr");
  AddBranch(&Event_n,"Event_n");
  
  if(debug_)    std::cout<<"set branches"<<std::endl;
}


