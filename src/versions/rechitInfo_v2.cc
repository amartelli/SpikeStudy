#include "DPGTask/SpikeStudy/interface/rechitInfo.h"

rechitInfo::rechitInfo(std::string name, TTree* tree, bool debug, const pset& iConfig):baseTree(name,tree,debug){
  if(debug) std::cout<<"in rechit constructor"<<std::endl;
  rechitBLabel_              = iConfig.getUntrackedParameter<edm::InputTag> ("rechitBLabel_");
  fillrechitInfo_            = iConfig.getUntrackedParameter<bool> ("fillrechitInfo_");
  if(debug) std::cout<<"in rechit constructor: calling SetBrances()"<<std::endl;
  SetBranches();
}

rechitInfo::~rechitInfo(){
  delete tree_;
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
  const EcalRecHitCollection & rechits = *Brechit;

  edm::Handle<EBDigiCollection>  EBdigis;
  iEvent.getByLabel("ecalDigis","ebDigis",EBdigis);
  edm::Handle<EBDigiCollection>  EBdigis2;
  iEvent.getByLabel("simEcalUnsuppressedDigis","APD",EBdigis2);
    
  if(fillrechitInfo_)
    {
      for ( EcalRecHitCollection::const_iterator hitItr = Brechit->begin(); hitItr != Brechit->end(); ++hitItr ) {
	bool is_spike = false;
	bool is_spike_EBDigis = false;
	bool is_spike_50_counts = false;
	bool is_spike_100_counts = false;
	int spike_max_adc    = -1;
	int spike_max_sample = -1;

	EBDetId detId  = (EBDetId)(hitItr->id());
	Rechit_energy.push_back((float) hitItr->energy());
	Rechit_time.push_back((float)   hitItr->time());
	
	Rechit_ifkWeird.push_back((bool)    hitItr->checkFlag(EcalRecHit::kWeird));
	Rechit_ifkDiWeird.push_back((bool)  hitItr->checkFlag(EcalRecHit::kDiWeird));
	Rechit_ifkOOT.push_back((bool)      hitItr->checkFlag(EcalRecHit::kOutOfTime));
	Rechit_ifnearCrack.push_back((bool) EBDetId::isNextToBoundary(detId));
	Rechit_e4e1.push_back((float)       e4e1   (detId, rechits));
	Rechit_swissCross.push_back((float) swissCross(detId, rechits));
	Rechit_e6e2.push_back((float)       Gete6e2(detId, rechits));
	Rechit_ieta.push_back((int) detId.ieta());
	Rechit_iphi.push_back((int) detId.iphi());
	
	//EBDigiCollection::const_iterator thisDigiInAPD = EBdigis2->find(hitItr->id());
	//if ( thisDigiInAPD != EBdigis2->end() && thisDigiInAPD->id() == hitItr->id())
	//  {
	//    n_trueSpikeDigis++;
	//    is_spike = true;
	//    
	//    EBDataFrame dataframe(*thisDigiInAPD );
	//    for (unsigned int i=0; i< (*thisDigiInAPD).size() ; ++i ) { 
	//      if(dataframe.sample(i).adc() > spike_max_adc)
	//	{
	//	  spike_max_adc = dataframe.sample(i).adc();
	//	  spike_max_sample = i+1;
	//	}
	//      
	//      if(dataframe.sample(i).adc() > 250 || dataframe.sample(i).gainId()!=1 )
	//	is_spike_50_counts = true;
	//      
	//      if(dataframe.sample(i).adc() > 300 || dataframe.sample(i).gainId()!=1 )
	//	is_spike_100_counts = true;
	//    }
	//    EBDigiCollection::const_iterator thisDigi = EBdigis->find(hitItr->id()); 
	//      if ( thisDigi != EBdigis->end())
	//        {
	//	  is_spike_EBDigis = true;
	//	}
	//
	//  }
	
	EBDigiCollection::const_iterator digiItrEB= EBdigis2->begin();
	// look for APD digi with same detId as the rechit being analysed
	while(digiItrEB != EBdigis2->end() && digiItrEB->id() != hitItr->id())
	  {
	    digiItrEB++;
	  }
	
	if (digiItrEB != EBdigis2->end()) {
	  is_spike = true; 
	  EBDataFrame df(*digiItrEB);
	  for(int i=0; i<10;++i)
	    {
	      // spike is either > 50 ADC counts or in gain 6/1
	      if (df.sample(i).adc()>250 || df.sample(i).gainId()!=1) {
		is_spike_50_counts=true;
	      }
	      if (df.sample(i).adc()>300 || df.sample(i).gainId()!=1) {
		is_spike_100_counts=true;
	      }
	    }
	}
	
	Rechit_spike_max_adc.push_back((int)spike_max_adc); 
	Rechit_spike_max_sample.push_back((int)spike_max_sample); 	
	Rechit_is_spike.push_back(is_spike);
	Rechit_is_spike_EBDigis.push_back(is_spike_EBDigis);
	Rechit_is_spike_50_counts.push_back(is_spike_50_counts);
	Rechit_is_spike_100_counts.push_back(is_spike_100_counts);
      }
    }
  
  if(debug_)    std::cout<<"got rechit info"<<std::endl;
}

void rechitInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&Rechit_energy          ,"Rechit_energy");
  AddBranch(&Rechit_time            ,"Rechit_time");
  AddBranch(&Rechit_ifkWeird        ,"Rechit_ifkWeird");
  AddBranch(&Rechit_ifkDiWeird      ,"Rechit_ifkDiWeird");
  AddBranch(&Rechit_ifkOOT          ,"Rechit_ifkOOT");
  AddBranch(&Rechit_ifnearCrack     ,"Rechit_ifnearCrack");
  AddBranch(&Rechit_e4e1            ,"Rechit_e4e1");
  AddBranch(&Rechit_swissCross      ,"Rechit_swissCross");
  AddBranch(&Rechit_e6e2            ,"Rechit_e6e2");
  AddBranch(&Rechit_ieta            ,"Rechit_ieta");
  AddBranch(&Rechit_iphi            ,"Rechit_iphi");
  AddBranch(&Rechit_spike_max_adc   ,"Rechit_spike_max_adc");
  AddBranch(&Rechit_spike_max_sample,"Rechit_spike_max_sample");
  AddBranch(&Rechit_is_spike        ,"Rechit_is_spike");
  AddBranch(&Rechit_is_spike_EBDigis,"Rechit_is_spike_EBDigis");
  AddBranch(&Rechit_is_spike_50_counts  ,"Rechit_is_spike_50_counts");
  AddBranch(&Rechit_is_spike_100_counts ,"Rechit_is_spike_100_counts");
  AddBranch(&n_trueSpikeDigis       ,"n_trueSpikeDigis");
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void rechitInfo::Clear(){
  if(debug_)std::cout<<"clearing Rechit info"<<std::endl;
  Rechit_energy.clear();
  Rechit_time.clear();
  Rechit_ifkWeird.clear();
  Rechit_ifkDiWeird.clear();
  Rechit_ifkOOT.clear();
  Rechit_ifnearCrack.clear();
  Rechit_e4e1.clear();
  Rechit_swissCross.clear();
  Rechit_e6e2.clear();
  Rechit_ieta.clear();
  Rechit_iphi.clear();
  Rechit_spike_max_adc.clear();
  Rechit_spike_max_sample.clear();
  Rechit_is_spike.clear();
  Rechit_is_spike_EBDigis.clear();
  Rechit_is_spike_50_counts.clear();
  Rechit_is_spike_100_counts.clear();
  n_trueSpikeDigis       = 0;
 if(debug_) std::cout<<"cleared"<<std::endl;
}

