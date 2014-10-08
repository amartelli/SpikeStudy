#include "DPGTask/SpikeStudy/interface/superClusterInfo.h"

superClusterInfo::superClusterInfo(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  if(debug) std::cout<<"in superCluster constructor"<<std::endl;
  superClusterLabel_         = iConfig.getUntrackedParameter<edm::InputTag> ("superClusterLabel_");
  fillsuperClusterInfo_      = iConfig.getUntrackedParameter<bool> ("fillsuperClusterInfo_");
  rechitBLabel_              = iConfig.getUntrackedParameter<edm::InputTag> ("rechitBLabel_");
  if(debug) std::cout<<"in superCluster constructor: calling SetBrances()"<<std::endl;
  SetBranches();
}

superClusterInfo::~superClusterInfo(){
  delete tree_;
}

void superClusterInfo::Fill(const edm::Event& iEvent, const edm::EventSetup& iSetup){
  Clear();
  if(debug_)  std::cout<<"getting superCluster info"<<std::endl;

  edm::Handle<reco::SuperClusterCollection> scs;//barrel
  iEvent.getByLabel(superClusterLabel_,scs);
  if(not iEvent.getByLabel(superClusterLabel_,scs)){
    std::cout<<"FATAL EXCEPTION: "<<"Following Not Found: "<< superClusterLabel_<<std::endl; 
    exit(0);
  }

  edm::Handle<EcalRecHitCollection> Brechit;//barrel
  iEvent.getByLabel(rechitBLabel_,Brechit);
  if(not iEvent.getByLabel(rechitBLabel_,Brechit)){
    std::cout<<"FATAL EXCEPTION: "<<"Following Not Found: "<<rechitBLabel_<<std::endl; 
    exit(0);
  }    
  const EcalRecHitCollection & rechits = *Brechit;
    
  if(fillsuperClusterInfo_)
    {
      for(reco::SuperClusterCollection::const_iterator aClus = scs->begin(); aClus != scs->end(); aClus++) {
	SC_energy.push_back((float) aClus->energy());
	//get the seed basic cluster
	const reco::CaloClusterPtr  seed = aClus->seed();
	//get the seed of seed basic cluster
	EBDetId id =(EBDetId)seed->seed();
	
	EcalRecHitCollection::const_iterator it = rechits.find( id );

	SC_seed_time.push_back((float)       it->time());
	SC_seed_energy.push_back((float)     it->energy());
	SC_seed_ifkWeird.push_back((bool)    it->checkFlag(EcalRecHit::kWeird));
	SC_seed_ifkDiWeird.push_back((bool)  it->checkFlag(EcalRecHit::kDiWeird));
	SC_seed_ifkOOT.push_back((bool)      it->checkFlag(EcalRecHit::kOutOfTime));
	SC_seed_ifnearCrack.push_back((bool) EBDetId::isNextToBoundary(id));
	SC_seed_e4e1.push_back((float)       e4e1   (id, rechits));
	SC_seed_swissCross.push_back((float) swissCross(id, rechits));
	SC_seed_e6e2.push_back((float)       Gete6e2(id, rechits));
	SC_seed_ieta.push_back((int) id.ieta());
	SC_seed_iphi.push_back((int) id.iphi());

      }
    }
  
  if(debug_)    std::cout<<"got rechit info"<<std::endl;
}

void superClusterInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&SC_energy               ,"SC_energy");
  AddBranch(&SC_seed_energy          ,"SC_seed_energy");
  AddBranch(&SC_seed_time            ,"SC_seed_time");
  AddBranch(&SC_seed_ifkWeird        ,"SC_seed_ifkWeird");
  AddBranch(&SC_seed_ifkDiWeird      ,"SC_seed_ifkDiWeird");
  AddBranch(&SC_seed_ifkOOT          ,"SC_seed_ifkOOT");
  AddBranch(&SC_seed_ifnearCrack     ,"SC_seed_ifnearCrack");
  AddBranch(&SC_seed_e4e1            ,"SC_seed_e4e1");
  AddBranch(&SC_seed_swissCross      ,"SC_seed_swissCross");
  AddBranch(&SC_seed_e6e2            ,"SC_seed_e6e2");
  AddBranch(&SC_seed_ieta            ,"SC_seed_ieta");
  AddBranch(&SC_seed_iphi            ,"SC_seed_iphi");
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void superClusterInfo::Clear(){
  if(debug_)std::cout<<"clearing SuperCluster info"<<std::endl;
  SC_energy.clear();
  SC_seed_energy.clear();
  SC_seed_time.clear();
  SC_seed_ifkWeird.clear();
  SC_seed_ifkDiWeird.clear();
  SC_seed_ifkOOT.clear();
  SC_seed_ifnearCrack.clear();
  SC_seed_e4e1.clear();
  SC_seed_swissCross.clear();
  SC_seed_e6e2.clear();
  SC_seed_ieta.clear();
  SC_seed_iphi.clear();
  if(debug_) std::cout<<"cleared"<<std::endl;
}
