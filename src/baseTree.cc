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
  float e1 = recHitE( id, rhs);
  float maxene=0;
  DetId maxid;
  
  if ( e1 == 0 ) return 0;
  const std::vector<DetId>& neighs =  neighbours(id);
  
  for (size_t i=0; i<neighs.size(); ++i){
    float ene = recHitE(neighs[i],rhs);
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
  float e1 = recHitE( id, rhs);
  if ( e1 == 0 ) return 0;
  const std::vector<DetId>& neighs =  neighbours(id);
  for (size_t i=0; i<neighs.size(); ++i)
    {
      float ene = recHitE(neighs[i],rhs);
      if(ene < 0.080) ene = 0;
      s4+= ene;
    }
  return s4 / e1;
}


float baseTree::swissCross(const DetId& id, 
		       const EcalRecHitCollection& rhs)
{
  float s4 = 0;
  float e1 = recHitE( id, rhs);
  if ( e1 == 0 ) return 0;
  const std::vector<DetId>& neighs =  neighbours(id);
  for (size_t i=0; i<neighs.size(); ++i)
    s4+= recHitE(neighs[i],rhs);

  return 1 - s4 / e1;
}

float baseTree::recHitE( const DetId id, const EcalRecHitCollection &recHits){
  if ( id.rawId() == 0 ) return 0;
  EcalRecHitCollection::const_iterator it = recHits.find( id );
  if ( it != recHits.end() ){
    return (*it).energy();
  }
  return 0;
}

/// four neighbours in the swiss cross around id
const std::vector<DetId> baseTree::neighbours(const DetId& id){
  std::vector<DetId> ret;
  if ( id.subdetId() == EcalBarrel) {
    ret.push_back( EBDetId::offsetBy( id,  1, 0 ));
    ret.push_back( EBDetId::offsetBy( id, -1, 0 ));
    ret.push_back( EBDetId::offsetBy( id,  0, 1 ));
    ret.push_back( EBDetId::offsetBy( id,  0,-1 ));
  }
  return ret;
}
  
float baseTree::recHitApproxEt(const DetId id,  const EcalRecHitCollection &recHits )
{
  if ( id.subdetId() == EcalBarrel ) {
    return recHitE(id,recHits ) / cosh( EBDetId::approxEta( id ) );
  }
  return 0;
}

