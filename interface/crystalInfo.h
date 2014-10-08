#ifndef __CRYSTAL_INFO_H_
#define __CRYSTAL_INFO_H_

class CrystalInfo{
 public:
  // methods
  CrystalInfo(){};
  ~CrystalInfo(){};
  
  // variables
  int ieta;
  int iphi;
  int ix;
  int iy;
  float energy;
  float time;
  bool if_kWeird;
  bool if_kDiWeird;
  bool if_kOutOfTime;
  bool if_nearCrack;
};
#endif
