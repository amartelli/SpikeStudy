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

  edm::Handle<EcalTrigPrimDigiCollection>  Orig_TPs;
  iEvent.getByLabel("simEcalTriggerPrimitiveDigis",Orig_TPs);

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


 // for ( EcalTrigPrimDigiCollection::const_iterator TP = Orig_TPs->begin(); TP != Orig_TPs->end(); ++TP ) {
 //   if( TP->id().subDet() == EcalBarrel) 
 //   std::cout<< TP->id().ieta() << "\t" << TP->id().iphi() << "\t"<<TP->sFGVB() << "\t"<< TP->compressedEt()<< "\t"<< TP->id().iTT() << std::endl;
 // }
      
  if(fillrechitInfo_)
    {
      for ( EBDigiCollection::const_iterator hitItr = EBdigis2->begin(); hitItr != EBdigis2->end(); ++hitItr ) {
	EBDataFrame df(*hitItr);
	int spike_max_adc    = -1;
	int spike_max_sample = -1;
	bool is_spike_50_counts = false;
	bool is_spike_100_counts = false;
	for(int i=0; i<10;++i)
	  {
	    if(df.sample(i).adc() > spike_max_adc)
	      {
		spike_max_adc = df.sample(i).adc();
		spike_max_sample = i+1;
	      }
	    if (df.sample(i).adc()>250 ) 
	      is_spike_50_counts=true;
	    if (df.sample(i).adc()>300 )
	      is_spike_100_counts=true;
	  }

	APDhit_max_adc.push_back((int)spike_max_adc); 
	APDhit_max_sample.push_back((int)spike_max_sample); 	
  	APDhit_50_counts.push_back(is_spike_50_counts);
	APDhit_100_counts.push_back(is_spike_100_counts);
      }

      for ( EcalRecHitCollection::const_iterator hitItr = Brechit->begin(); hitItr != Brechit->end(); ++hitItr ) {
	bool is_spike = false;
	bool is_spike_3GeV = false;
	bool is_L1_spike = false;
	bool is_spike_50_counts = false;
	bool is_spike_100_counts = false;
	float TT_Et = -1.; 
 
	EBDetId detId  = (EBDetId)(hitItr->id());
	Rechit_energy.push_back((float) hitItr->energy());
	Rechit_et.push_back(recHitApproxEt(hitItr->id(), rechits));
	Rechit_time.push_back((float)   hitItr->time());
	
	Rechit_ifkWeird.push_back((bool)    hitItr->checkFlag(EcalRecHit::kWeird));
	Rechit_ifkDiWeird.push_back((bool)  hitItr->checkFlag(EcalRecHit::kDiWeird));
	Rechit_ifkOOT.push_back((bool)      hitItr->checkFlag(EcalRecHit::kOutOfTime));
	Rechit_ifkGood.push_back((bool)      hitItr->checkFlag(EcalRecHit::kGood));
	Rechit_ifnearCrack.push_back((bool) EBDetId::isNextToBoundary(detId));
	Rechit_e4e1.push_back((float)       e4e1   (detId, rechits));
	Rechit_swissCross.push_back((float) swissCross(detId, rechits));
	Rechit_e6e2.push_back((float)       Gete6e2(detId, rechits));
	Rechit_ieta.push_back((int) detId.ieta());
	Rechit_iphi.push_back((int) detId.iphi());

	const EcalTrigTowerDetId towid= detId.tower();
	
	//std::cout<<"Rechit Info:"<< detId.ieta()<<"\t"<<detId.iphi()<<std::endl;
	//std::cout<<"TT info:"<< towid.ieta()<<"\t"<<towid.iphi()<<std::endl;
	int TT_index = -1;

	EcalTrigPrimDigiCollection::const_iterator TP = Orig_TPs->begin();
	while(TP != Orig_TPs->end() && TP->id() != towid)
	  { TP++; 
	    TT_index++; 
	  }
	
	if(TP!=Orig_TPs->end()){
	  //std::cout<<"sfgv:"<< TP->sFGVB()<< std::endl;
	  is_L1_spike = (bool) TP->sFGVB();
	  TT_Et = TP->compressedEt();
	  TT_index++;
	}
            
	EBDigiCollection::const_iterator digiItrEB= EBdigis2->begin();
	while(digiItrEB != EBdigis2->end() && digiItrEB->id() != hitItr->id())
	  {
	    digiItrEB++;
	  }
	
	if (digiItrEB != EBdigis2->end()) {
	  is_spike = true; 

	  if(hitItr->energy() > 3. ) 
	    is_spike_3GeV = true; 
	  EBDataFrame df(*digiItrEB);
	  for(int i=0; i<10;++i)
	    {
	      if (df.sample(i).adc()>250 || df.sample(i).gainId()!=1) {
		is_spike_50_counts=true;
	      }
	      if (df.sample(i).adc()>300 || df.sample(i).gainId()!=1) {
		is_spike_100_counts=true;
	      }
	    }
	}

	Rechit_is_spike.push_back(is_spike);
	Rechit_is_spike_3GeV.push_back(is_spike_3GeV);
	Rechit_is_L1_spike.push_back(is_L1_spike);
	Rechit_is_spike_50_counts.push_back(is_spike_50_counts);
	Rechit_is_spike_100_counts.push_back(is_spike_100_counts);
	Rechit_TT_index.push_back(TT_index);
	Rechit_TT_Et.push_back(TT_Et);
      }
    }
  
  if(debug_)    std::cout<<"got rechit info"<<std::endl;
}

void rechitInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  AddBranch(&Rechit_energy          ,"Rechit_energy");
  AddBranch(&Rechit_et              ,"Rechit_et");
  AddBranch(&Rechit_time            ,"Rechit_time");
  AddBranch(&Rechit_ifkWeird        ,"Rechit_ifkWeird");
  AddBranch(&Rechit_ifkGood        ,"Rechit_ifkGood");
  AddBranch(&Rechit_ifkDiWeird      ,"Rechit_ifkDiWeird");
  AddBranch(&Rechit_ifkOOT          ,"Rechit_ifkOOT");
  AddBranch(&Rechit_ifnearCrack     ,"Rechit_ifnearCrack");
  AddBranch(&Rechit_e4e1            ,"Rechit_e4e1");
  AddBranch(&Rechit_swissCross      ,"Rechit_swissCross");
  AddBranch(&Rechit_e6e2            ,"Rechit_e6e2");
  AddBranch(&Rechit_ieta            ,"Rechit_ieta");
  AddBranch(&Rechit_iphi            ,"Rechit_iphi");
  AddBranch(&Rechit_is_spike        ,"Rechit_is_spike");
  AddBranch(&Rechit_is_spike_3GeV   ,"Rechit_is_spike_3GeV");
  AddBranch(&Rechit_is_L1_spike         ,"Rechit_is_L1_spike");
  AddBranch(&Rechit_is_spike_50_counts  ,"Rechit_is_spike_50_counts");
  AddBranch(&Rechit_is_spike_100_counts ,"Rechit_is_spike_100_counts");
  AddBranch(&Rechit_TT_index        ,"Rechit_TT_index");
  AddBranch(&Rechit_TT_Et           ,"Rechit_TT_Et");
  AddBranch(&APDhit_max_adc         ,"APDhit_max_adc");
  AddBranch(&APDhit_max_sample      ,"APDhit_max_sample");
  AddBranch(&APDhit_50_counts  ,"APDhit_50_counts");
  AddBranch(&APDhit_100_counts ,"APDhit_100_counts");
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void rechitInfo::Clear(){
  if(debug_)std::cout<<"clearing Rechit info"<<std::endl;
  Rechit_energy.clear();
  Rechit_et.clear();
  Rechit_time.clear();
  Rechit_ifkWeird.clear();
  Rechit_ifkDiWeird.clear();
  Rechit_ifkOOT.clear();
  Rechit_ifkGood.clear();
  Rechit_ifnearCrack.clear();
  Rechit_e4e1.clear();
  Rechit_swissCross.clear();
  Rechit_e6e2.clear();
  Rechit_ieta.clear();
  Rechit_iphi.clear();
  Rechit_is_spike.clear();
  Rechit_is_spike_3GeV.clear();
  Rechit_is_L1_spike.clear();
  Rechit_is_spike_50_counts.clear();
  Rechit_is_spike_100_counts.clear();
  Rechit_TT_index.clear();
  Rechit_TT_Et.clear();
  APDhit_max_adc.clear();
  APDhit_max_sample.clear();
  APDhit_50_counts.clear();
  APDhit_100_counts.clear();
 if(debug_) std::cout<<"cleared"<<std::endl;
}

