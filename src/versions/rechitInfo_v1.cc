#include "DPGTask/SpikeStudy/interface/rechitInfo.h"

rechitInfo::rechitInfo(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  if(debug) std::cout<<"in rechit constructor"<<std::endl;
  rechitBLabel_              = iConfig.getUntrackedParameter<edm::InputTag> ("rechitBLabel_");
  fillrechitInfo_            = iConfig.getUntrackedParameter<bool> ("fillrechitInfo_");
  if(debug) std::cout<<"in rechit constructor: calling SetBrances()"<<std::endl;
  SetBranches();
}

rechitInfo::~rechitInfo(){
  //delete tree_;
}

void rechitInfo::Fill(const edm::Event& iEvent, const edm::EventSetup& iSetup){
  Clear();
  if(debug_)  std::cout<<"getting rechit info"<<std::endl;

  edm::Handle<EcalRecHitCollection> Brechit;//barrel
  iEvent.getByLabel(rechitBLabel_,Brechit);
  if(not iEvent.getByLabel(rechitBLabel_,Brechit)){
    std::cout<<"FATAL EXCEPTION: "<<"Following Not Found: "<<rechitBLabel_<<std::endl; 
    exit(0);
  }    

  edm::Handle<EBDigiCollection>  EBdigis;
  iEvent.getByLabel("ecalDigis","ebDigis",EBdigis);
  edm::Handle<EBDigiCollection>  EBdigis2;
  iEvent.getByLabel("simEcalUnsuppressedDigis","APD",EBdigis2);
  
  
  if(fillrechitInfo_)
    {
      for ( EcalRecHitCollection::const_iterator hitItr = Brechit->begin(); hitItr != Brechit->end(); ++hitItr ) {
	
	Rechit_energy.push_back((float) hitItr->energy());

	//if(hitItr->energy() > 3.)
	//{
	//std::cout<<"energy :"<<hitItr->energy()<<" \t time : "<< (float)hitItr->time()<< std::endl;
	//EBDetId detId  = (EBDetId)(hitItr->id());
	//std::cout<<"ieta:"<<detId.ieta()<<"\t iphi: "<<detId.iphi()<<std::endl;
	//std::cout<<"kWeird:"<<hitItr->checkFlag(EcalRecHit::kWeird)
	//   << "\t kDiWeird:"<< hitItr->checkFlag(EcalRecHit::kDiWeird)
	//   <<"\t kOOT:"<<hitItr->checkFlag(EcalRecHit::kOutOfTime)<<std::endl;
	
	
	EBDigiCollection::const_iterator thisDigiInAPD = EBdigis2->find(hitItr->id());
	if ( thisDigiInAPD == EBdigis2->end())
	  continue;
	//std::cout<<"Output from APD digi collection:"<<std::endl;
	
	
	EBDataFrame dataframe2( *thisDigiInAPD );
	///std::cout<<"Sample\tADC \tGain"<<std::endl;
	for (unsigned int i=0; i< (*thisDigiInAPD).size() ; ++i ) {
	  EcalMGPASample samp_crystal2(dataframe2.sample(i));
	  //std::cout<<i<<"\t"<<samp_crystal2.adc()<<"\t"<<samp_crystal2.gainId()<<std::endl;
	}
	  
	//std::cout<<"Output from EB digi collection:"<<std::endl;
	EBDigiCollection::const_iterator thisDigi = EBdigis->find(hitItr->id());
	if ( thisDigi == EBdigis->end())
	  continue;
	
	EBDataFrame dataframe( *thisDigi );
	//std::cout<<"Sample\tADC \tGain"<<std::endl;
	for (unsigned int i=0; i< (*thisDigi).size() ; ++i ) { 
	  EcalMGPASample samp_crystal(dataframe.sample(i));
	  //std::cout<<i<<"\t"<<samp_crystal.adc()<<"\t"<<samp_crystal.gainId()<<std::endl;
	}
	
	//}
      }
    }
  
  if(debug_)    std::cout<<"got rechit info"<<std::endl;
}

void rechitInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&Rechit_energy          ,"Rechit_energy");

  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void rechitInfo::Clear(){
  if(debug_)std::cout<<"clearing Rechit info"<<std::endl;
  Rechit_energy.clear();
  if(debug_) std::cout<<"cleared"<<std::endl;
}

