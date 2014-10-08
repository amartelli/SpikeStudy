{
  TFile *_file0 = TFile::Open("../MinBias_PU_8TeV_defTuning.root");


  TTree* myTree = _file0->Get("demo/tree");


  vector<float>   *Rechit_time;
  vector<float>   *Rechit_swissCross;
  vector<bool>    *Rechit_is_spike_50_counts;
  vector<bool>    *APDhit_50_counts;
  vector<float>   *Rechit_e4e1;


  myTree->SetBranchAddress("Rechit_time", &Rechit_time, &Rechit_time);
  myTree->SetBranchAddress("Rechit_swissCross", &Rechit_swissCross, &Rechit_swissCross);
  myTree->SetBranchAddress("Rechit_is_spike_50_counts", &Rechit_is_spike_50_counts, &Rechit_is_spike_50_counts);
  myTree->SetBranchAddress("APDhit_50_counts", &APDhit_50_counts, &APDhit_50_counts);
  myTree->SetBranchAddress("Rechit_e4e1", &Rechit_e4e1, &Rechit_e4e1);

  float totEvents = myTree->GetEntries;
  std::cout << " >>>> totEvents = " << totEvents << std::endl;

  for(int iEntry=0; iEntry<myTree->GetEntries; ++iEntry){
    myTree->GetEvent(iEntry);
    if(iEntry % 1000 == 0) std::cout << " >>>> iEntry = " << iEntry << std::endl;

    for(unsigned int Nrec=0; Nrec<Rechit_time.size(); ++Nrec){
      std::cout << "Rechit_time.at() = " << Rechit_time.st(Nrec) << std::endl;
    }

  }
}
