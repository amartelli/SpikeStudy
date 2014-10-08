#include "DPGTask/SpikeStudy/interface/baseTree.h"

baseTree::baseTree(std::string identifier, TTree* tree, bool debug){
  identifier_  = identifier; 
  tree_        = tree;
  debug_       = debug;
}

void baseTree::AddBranch(std::vector<float>* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(std::vector<bool>* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(std::vector<int>* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(std::vector<std::vector<float> >* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(std::vector<std::vector<int> >* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(std::vector<std::vector<TString> >* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}


void baseTree::AddBranch(std::vector<std::string>* vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(), vec);
}

void baseTree::AddBranch(TClonesArray** vec, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),"TClonesArray", vec,32000,0);
}
void baseTree::AddBranch(double* x, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),x,(brName+"/D").c_str());
}
void baseTree::AddBranch(float* x, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),x,(brName+"/F").c_str());
}
void baseTree::AddBranch(unsigned int* x, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),x,(brName+"/i").c_str());
}
void baseTree::AddBranch(int* x, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),x,(brName+"/I").c_str());
}
void baseTree::AddBranch(bool* x, std::string name){
  std::string brName = name;
  tree_->Branch(brName.c_str(),x,(brName+"/O").c_str());
}


float baseTree::Gete6e2(const DetId& id, 
			    const EcalRecHitCollection& rhs){
  float s4_1 = 0;
  float s4_2 = 0;
  float e1 = recHitE( id, rhs , false );
  float maxene=0;
  DetId maxid;
  
  if ( e1 == 0 ) return 0;
  
  const std::vector<DetId>& neighs =  neighbours(id);
  
  // find the most energetic neighbour ignoring time info
  for (size_t i=0; i<neighs.size(); ++i){
    float ene = recHitE(neighs[i],rhs,false);
    if (ene>maxene) {
      maxene=ene;
      maxid = neighs[i];
    }
  }
  
  float e2=maxene;

  s4_1 = e4e1(id,rhs)* e1;
  s4_2 = e4e1(maxid,rhs)* e2;
  
  return (s4_1 + s4_2) / (e1+e2) -1. ;
}


float baseTree::e4e1(const DetId& id, 
		       const EcalRecHitCollection& rhs)
{
  float s4 = 0;
  float e1 = recHitE( id, rhs, false );
  if ( e1 == 0 ) return 0;
  const std::vector<DetId>& neighs =  neighbours(id);
  for (size_t i=0; i<neighs.size(); ++i)
    s4+=recHitE(neighs[i],rhs, false);
  return s4 / e1;
}

float baseTree::recHitE( const  DetId id,  const EcalRecHitCollection &recHits )
{
  if ( id == DetId(0) ) {
    return 0;
  } else {
    EcalRecHitCollection::const_iterator it = recHits.find( id );
    if ( it != recHits.end() ) return (*it).energy();
  }
  return 0;
}


float baseTree::recHitE( const DetId id, const EcalRecHitCollection & recHits,int di, int dj )
{
  // in the barrel:   di = dEta   dj = dPhi
  // in the endcap:   di = dX     dj = dY
  DetId nid;
  if( id.subdetId() == EcalBarrel) nid = EBDetId::offsetBy( id, di, dj );
  else if( id.subdetId() == EcalEndcap) nid = EEDetId::offsetBy( id, di, dj );
  return ( nid == DetId(0) ? 0 : recHitE( nid, recHits ) );
}

float baseTree::recHitApproxEt(const DetId id,  const EcalRecHitCollection &recHits )
{
  // for the time being works only for the barrel
  if ( id.subdetId() == EcalBarrel ) {
    return recHitE(id,recHits ) / cosh( EBDetId::approxEta( id ) );
  }
  return 0;
}

float baseTree::recHitE( const DetId id, const EcalRecHitCollection &recHits, bool useTimingInfo ){
  if ( id.rawId() == 0 ) return 0;
  double e4e1Threshold_barrel_  = 0.080;
  double e4e1Threshold_endcap_  = 0.300;
  double ignoreOutOfTimeThresh_ = 1e9;
  
  float threshold = e4e1Threshold_barrel_;
  if ( id.subdetId() == EcalEndcap) threshold = e4e1Threshold_endcap_; 
 
  EcalRecHitCollection::const_iterator it = recHits.find( id );
  if ( it != recHits.end() ){
    float ene= (*it).energy();

    // ignore out of time in EB when making e4e1 if so configured
    if (useTimingInfo){
      if (id.subdetId()==EcalBarrel &&
          it->checkFlag(EcalRecHit::kOutOfTime) 
	  && ene>ignoreOutOfTimeThresh_) return 0;
    }
    
    // ignore hits below threshold
    if (ene < threshold) return 0;
    
    // else return the energy of this hit
    return ene;
  }
  return 0;
}

/// four neighbours in the swiss cross around id
const std::vector<DetId> baseTree::neighbours(const DetId& id){                                                                                                                              
  std::vector<DetId> ret;
  //std::cout<<"where does the ID belong to:" << id.subdetId()<<std::endl;
  if ( id.subdetId() == EcalBarrel) {
    ret.push_back( EBDetId::offsetBy( id,  1, 0 ));
    ret.push_back( EBDetId::offsetBy( id, -1, 0 ));
    ret.push_back( EBDetId::offsetBy( id,  0, 1 ));
    ret.push_back( EBDetId::offsetBy( id,  0,-1 ));
    //std::cout<<"got the barrel neighbour DetId's"<<std::endl;
  }
  // nobody understands what polymorphism is for, sgrunt !
  else  if (id.subdetId() == EcalEndcap) {
    ret.push_back( EEDetId::offsetBy( id,  1, 0 ));
    ret.push_back( EEDetId::offsetBy( id, -1, 0 ));
    ret.push_back( EEDetId::offsetBy( id,  0, 1 ));
    ret.push_back( EEDetId::offsetBy( id,  0,-1 ));
    // std::cout<<"got the endcap neighbour DetId's"<<std::endl;
  }
  return ret;
}
  
  
