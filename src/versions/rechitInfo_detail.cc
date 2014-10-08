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

  Set(iSetup);
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
	//if(hitItr->energy() > 3.)
	//{
	std::cout<<"energy :"<<hitItr->energy()<<" \t time : "<< (float)hitItr->time()<< std::endl;
	std::cout<<"kWeird:"<<hitItr->checkFlag(EcalRecHit::kWeird)
		     << "\t kDiWeird:"<< hitItr->checkFlag(EcalRecHit::kDiWeird)
		     <<"\t kOOT:"<<hitItr->checkFlag(EcalRecHit::kOutOfTime)<<std::endl;
	EBDetId detId  = (EBDetId)(hitItr->id());
	std::cout<<"ieta:"<<detId.ieta()<<"\t iphi: "<<detId.iphi()<<std::endl;
	   
	std::cout<<"Output from EB digi collection:"<<std::endl;
	EBDigiCollection::const_iterator thisDigi = EBdigis->find(hitItr->id());
	if ( thisDigi == EBdigis->end())
	  continue;
	EBDataFrame dataframe( *thisDigi );

	std::cout<<"Sample\tADC \tGain"<<std::endl;
	for (unsigned int i=0; i< (*thisDigi).size() ; ++i ) { 
	  EcalMGPASample samp_crystal(dataframe.sample(i));
	  std::cout<<i<<"\t"<<samp_crystal.adc()<<"\t"<<samp_crystal.gainId()<<std::endl;
	}
	std::cout<<"last Unsaturated Sample?:"<< dataframe.lastUnsaturatedSample()<<std::endl;

	int leadingSample = dataframe.lastUnsaturatedSample();
	const EcalPedestals::Item * aped = 0;
	const EcalMGPAGainRatio * aGain = 0;
	const EcalXtalGroupId * gid = 0;
	//	float offsetTime = 0;
	
	unsigned int hashedIndex = EBDetId(hitItr->id()).hashedIndex();
	aped  = &peds->barrel(hashedIndex);
	aGain = &gains->barrel(hashedIndex);
	gid   = &grps->barrel(hashedIndex);
	
	//offsetTime = offtime->getEBValue();
	pedVec[0] = aped->mean_x12;
	pedVec[1] = aped->mean_x6;
	pedVec[2] = aped->mean_x1;
	pedRMSVec[0] = aped->rms_x12;
	pedRMSVec[1] = aped->rms_x6;
	pedRMSVec[2] = aped->rms_x1;
	gainRatios[0] = 1.;
	gainRatios[1] = aGain->gain12Over6();
	gainRatios[2] = aGain->gain6Over1()*aGain->gain12Over6();
	

	std::cout<<"Pedestal Vector, 12, 6, 1 :"<<pedVec[0] <<" \t "<< pedVec[1]<<"\t "<<pedVec[2]<<std::endl;
	std::cout<<"Pedestal RMS Vector, 12, 6, 1 :"<<pedRMSVec[0] <<" \t "<< pedRMSVec[1]<<"\t "<<pedRMSVec[2]<<std::endl;
	std::cout<<"Gain Ratio Vector, 12, 6, 1 :"<<gainRatios[0] <<" \t "<< gainRatios[1]<<"\t "<<gainRatios[2]<<std::endl;
	
	if(leadingSample == -1)
	  {
	    EcalTBWeights::EcalTDCId tdcid(1);
	    EcalTBWeights::EcalTBWeightMap const & wgtsMap = wgts->getMap();
	    EcalTBWeights::EcalTBWeightMap::const_iterator wit;
	    wit = wgtsMap.find( std::make_pair(*gid,tdcid) );
	    if( wit == wgtsMap.end() ) {
	      edm::LogError("EcalUncalibRecHitError") << "No weights found for EcalGroupId: " 
						      << gid->id() << " and  EcalTDCId: " << tdcid
						      << "\n  skipping digi with id: " << hitItr->id().rawId();
	    }
	    const EcalWeightSet& wset = wit->second; // this is the EcalWeightSet
	    const EcalWeightSet::EcalWeightMatrix& mat1 = wset.getWeightsBeforeGainSwitch();
	    const EcalWeightSet::EcalWeightMatrix& mat2 = wset.getWeightsAfterGainSwitch();
	    
	    weights[0] = &mat1;
	    weights[1] = &mat2;
	    
	    EcalUncalibratedRecHit uncalibRecHit = weightsMethod_barrel_.makeRecHit(*thisDigi, pedVec, pedRMSVec, gainRatios, weights, testbeamEBShape);
	    std::cout<<"uncalibrated rechit amplitude:"<<uncalibRecHit.amplitude()<<std::endl;


	  }



	    
	/*
	    EBDigiCollection::const_iterator thisDigiInAPD = EBdigis2->find(hitItr->id());
	    if ( thisDigiInAPD == EBdigis2->end())
	      continue;
	    std::cout<<"Output from APD digi collection:"<<std::endl;
	    EBDetId detId  = (EBDetId)(hitItr->id());
	    std::cout<<"ieta:"<<detId.ieta()<<"\t iphi: "<<detId.iphi()<<std::endl;

	    EBDataFrame dataframe2( *thisDigiInAPD );
	    std::cout<<"Sample\tADC \tGain"<<std::endl;
	    for (unsigned int i=0; i< (*thisDigiInAPD).size() ; ++i ) {
	      EcalMGPASample samp_crystal2(dataframe2.sample(i));
	      std::cout<<i<<"\t"<<samp_crystal2.adc()<<"\t"<<samp_crystal2.gainId()<<std::endl;
	    }

	    std::cout<<"Output from EB digi collection:"<<std::endl;
	    EBDigiCollection::const_iterator thisDigi = EBdigis->find(hitItr->id());
	    if ( thisDigi == EBdigis->end())
	      continue;
	    EBDataFrame dataframe( *thisDigi );
	    std::cout<<"Sample\tADC \tGain"<<std::endl;
	    for (unsigned int i=0; i< (*thisDigi).size() ; ++i ) { 
	      EcalMGPASample samp_crystal(dataframe.sample(i));
	      std::cout<<i<<"\t"<<samp_crystal.adc()<<"\t"<<samp_crystal.gainId()<<std::endl;
	    }
	*/  
	    //}
      }


	for ( EBDigiCollection::const_iterator hitItr = EBdigis2->begin(); hitItr != EBdigis2->end(); ++hitItr ) {
	    EBDetId detId  = (EBDetId)(hitItr->id());
	    std::cout<<"ieta:"<<detId.ieta()<<"\t iphi: "<<detId.iphi()<<std::endl;
	    std::cout<<"Output from APD digi collection:"<<std::endl;
	    EBDataFrame dataframe2( *hitItr );
	    std::cout<<"Sample\tADC \tGain"<<std::endl;
	    for (unsigned int i=0; i< (*hitItr).size() ; ++i ) {
	      EcalMGPASample samp_crystal2(dataframe2.sample(i));
	      std::cout<<i<<"\t"<<samp_crystal2.adc()<<"\t"<<samp_crystal2.gainId()<<std::endl;
	    }
	}

    }

  if(debug_)    std::cout<<"got rechit info"<<std::endl;
}

void rechitInfo::SetBranches(){
  if(debug_)    std::cout<<"setting branches: calling AddBranch of baseTree"<<std::endl;
  if(debug_)    std::cout<<"set branches"<<std::endl;
}

void rechitInfo::Clear(){
  if(debug_)std::cout<<"clearing Rechit info"<<std::endl;
  if(debug_) std::cout<<"cleared"<<std::endl;
}


void rechitInfo::Set(const edm::EventSetup& iSetup)
{
  // common setup
  iSetup.get<EcalGainRatiosRcd>().get(gains);
  iSetup.get<EcalPedestalsRcd>().get(peds);
  
  // for the weights method
  iSetup.get<EcalWeightXtalGroupsRcd>().get(grps);
  iSetup.get<EcalTBWeightsRcd>().get(wgts);

  // which of the samples need be used
  iSetup.get<EcalSampleMaskRcd>().get(sampleMaskHand_);
  
  // for the leading edge method
  iSetup.get<EcalTimeCalibConstantsRcd>().get(itime);
  iSetup.get<EcalTimeOffsetConstantRcd>().get(offtime);

}
