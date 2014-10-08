#define tree_cxx
#include "tree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

int main(int argc, char *argv[])
{
  if(argc > 1)
    {
      tree t(argv[1], argv[2]);
      t.Loop();
    }
      return 0;
}

void tree::Loop()
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntries();
   Long64_t nbytes = 0, nb = 0;
   num =1;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     std::cout<<"Event:"<<jentry<<std::endl;
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     bool vertexdecision;
     int foundVertex = 0;
     vertexdecision  = VertexDecision(foundVertex);

     if(vertexdecision)
       {
	 for(int i = 0; i < Rechit_energy->size(); i++)
	   {
	     //////remove for 14 TeV MC //////
	     if( ((*Rechit_ieta)[i] == 11 && (*Rechit_iphi)[i]== 68)            //remove
		 || ((*Rechit_ieta)[i]  ==  68 && (*Rechit_iphi)[i]== 74 ) //remove
		 || ((*Rechit_ieta)[i]  == -83 && (*Rechit_iphi)[i]== 189) //remove
		 || ((*Rechit_ieta)[i]  == -75 && (*Rechit_iphi)[i]== 199) //remove
		 || ((*Rechit_ieta)[i]  == -81 && (*Rechit_iphi)[i]== 316) //remove
		 ) continue;//remove
	     
	     if((*Rechit_is_spike_50_counts)[i])
	       {
	 //std::cout<< "TT index:"<< (*Rechit_TT_index)[i]<< "\t sFGBV:" << (*Rechit_is_L1_spike)[i]<< "\tiEta:" 
		 //	  << (*Rechit_ieta)[i] << "\tiPhi:" << (*Rechit_iphi)[i]<< "\t TP compressedEt:" << (*Rechit_TT_Et)[i]<< std::endl;
		 //PrintRecHitsInfo((*Rechit_TT_index)[i]);
		 
		 h_rechit_spike_energy_50->Fill((*Rechit_energy)[i] );
		 h_rechit_spike_ieta_50->Fill(abs((*Rechit_ieta)[i]) );

		 for(float threshold = 0.; threshold < 1.; threshold+=0.100)  
		   {
		     CountRecHitsinE((*Rechit_TT_index)[i], threshold);
		     CountRecHitsinEt((*Rechit_TT_index)[i], threshold);
		     sFGVBinE((*Rechit_TT_index)[i], threshold, i);
		     sFGVBinEt((*Rechit_TT_index)[i], threshold,i);
		   }
		 
		 if(!sFGVB((*Rechit_TT_index)[i],0.350))
		   {
		     h_rechit_spike_energy_sFGVB->Fill((*Rechit_energy)[i]);
		     h_rechit_spike_ieta_sFGVB->Fill(abs((*Rechit_ieta)[i]));
		   }
		 
		 if(!(*Rechit_is_L1_spike)[i])
		   {
		     h_rechit_spike_energy_L1->Fill((*Rechit_energy)[i]);
		     h_rechit_spike_ieta_L1->Fill(abs((*Rechit_ieta)[i]) );
		   }

	       }
	   }
       }
   }
}

void tree::PrintRecHitsInfo(int TT_index) {
  int count = 0;
  std::cout<< "rechits in the same TT with the above rechit:" <<std::endl;
  std::cout<< setw(15) << "Energy" << setw(25) <<"Et" << setw(20) <<"iEta" << setw(20) <<"iPhi" << setw(25) << "Time" << std::endl;
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	std::cout << std::fixed;
	std::cout << setw(15) <<  std::setprecision(4) << (*Rechit_energy)[i] << setw(25) << std::setprecision(4) << (*Rechit_et)[i] 
		  << setw(20) << (*Rechit_ieta)[i]
		  << setw(20) << (*Rechit_iphi)[i] << setw(25) << std::setprecision(4) 
		  << (*Rechit_time)[i]<<std::endl;
	count++;
      }
  }
}

void tree::CountRecHitsinE(int TT_index, float threshold) {
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	if ((*Rechit_energy)[i] > threshold) 
	  {
	    bool done(false);
	    for (unsigned int k=0; k< etaIndex.size(); ++k) {
	      if ((*Rechit_ieta)[i] == etaIndex[k]) {
		kount[k]++;
		done = true;
		break;
	      }
	    }
	    if (!done) {
	      etaIndex.push_back((*Rechit_ieta)[i]);
	      kount.push_back(1);
	    }
	  }
      }
  }
  
  // std::cout <<"Thresold is : "<< std::setprecision(1) << threshold<<std::endl;
  for (unsigned int k=0; k< etaIndex.size(); ++k) {
    float prob = 0; 
    //    std::cout<<"Eta Index:" << etaIndex[k]<< "\t prob above threshold:"<< std::setprecision(1) <<kount[k]/5. <<std::endl;
    if(kount[k] >=2)
      prob =1.;
    h_prob_energy->Fill(threshold, prob);
    if(abs(etaIndex[k])<= 40)
      h_prob_energy_40->Fill(threshold, prob);
    if(abs(etaIndex[k])>40 && abs(etaIndex[k]) <= 70)
      h_prob_energy_70->Fill(threshold, prob);
    if(abs(etaIndex[k]) > 70 && abs(etaIndex[k]) <= 85)
      h_prob_energy_85->Fill(threshold, prob);
  }
}

void tree::CountRecHitsinEt(int TT_index, float threshold) {
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	if ((*Rechit_et)[i] > threshold) 
	  {
	    bool done(false);
	    for (unsigned int k=0; k< etaIndex.size(); ++k) {
	      if ((*Rechit_ieta)[i] == etaIndex[k]) {
		kount[k]++;
		done = true;
		break;
	      }
	    }
	    if (!done) {
	      etaIndex.push_back((*Rechit_ieta)[i]);
	      kount.push_back(1);
	    }
	  }
      }
  }

  //std::cout <<"Thresold is : "<< std::setprecision(1) << threshold<<std::endl;
  for (unsigned int k=0; k< etaIndex.size(); ++k) {
    float prob = 0;
    if(kount[k] >=2)
      prob =1.;
    h_prob_et->Fill(threshold, prob);
    if(abs(etaIndex[k])<= 40)
      h_prob_et_40->Fill(threshold, prob);
    if(abs(etaIndex[k])>40 && abs(etaIndex[k]) <= 70)
      h_prob_et_70->Fill(threshold, prob);
    if(abs(etaIndex[k]) > 70 && abs(etaIndex[k]) <= 85)
      h_prob_et_85->Fill(threshold, prob);
  } 
}

void tree::sFGVBinE(int TT_index, float threshold, int rechit_index) {
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	if ((*Rechit_energy)[i] > threshold) 
	  {
	    bool done(false);
	    for (unsigned int k=0; k< etaIndex.size(); ++k) {
	      if ((*Rechit_ieta)[i] == etaIndex[k]) {
		kount[k]++;
		done = true;
		break;
	      }
	    }
	    if (!done) {
	      etaIndex.push_back((*Rechit_ieta)[i]);
	      kount.push_back(1);
	    }
	  }
      }
  }
  float prob = 0;   
  for (unsigned int k=0; k< etaIndex.size(); ++k) {
    if(kount[k] >=2)
      {
	prob =1.;
	break;
      }
  }
  h_prob_energy_sFGVB->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index])<= 40)
    h_prob_energy_sFGVB_40->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index])>40 && abs((*Rechit_ieta)[rechit_index]) <= 70)
    h_prob_energy_sFGVB_70->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index]) > 70 && abs((*Rechit_ieta)[rechit_index]) <= 85)
    h_prob_energy_sFGVB_85->Fill(threshold, prob);
  
}

void tree::sFGVBinEt(int TT_index, float threshold, int rechit_index) {
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	if ((*Rechit_et)[i] > threshold) 
	  {
	    bool done(false);
	    for (unsigned int k=0; k< etaIndex.size(); ++k) {
	      if ((*Rechit_ieta)[i] == etaIndex[k]) {
		kount[k]++;
		done = true;
		break;
	      }
	    }
	    if (!done) {
	      etaIndex.push_back((*Rechit_ieta)[i]);
	      kount.push_back(1);
	    }
	  }
      }
  }

  float prob = 0;
  for (unsigned int k=0; k< etaIndex.size(); ++k) {
    if(kount[k] >=2)
      {
	prob =1.;
	break;
      }
  }

  h_prob_et_sFGVB->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index])<= 40)
    h_prob_et_sFGVB_40->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index])>40 && abs((*Rechit_ieta)[rechit_index]) <= 70)
    h_prob_et_sFGVB_70->Fill(threshold, prob);
  if(abs((*Rechit_ieta)[rechit_index]) > 70 && abs((*Rechit_ieta)[rechit_index]) <= 85)
    h_prob_et_sFGVB_85->Fill(threshold, prob);
}


bool tree::sFGVB(int TT_index, float threshold) {
  
  std::vector<int> etaIndex, kount;
  for(int i = 0; i < Rechit_energy->size(); i++){
    if((*Rechit_TT_index)[i]== TT_index)
      {
	if ((*Rechit_et)[i] > threshold) 
	  {
	    bool done(false);
	    for (unsigned int k=0; k< etaIndex.size(); ++k) {
	      if ((*Rechit_ieta)[i] == etaIndex[k]) {
		kount[k]++;
		done = true;
		break;
	      }
	    }
	    if (!done) {
	      etaIndex.push_back((*Rechit_ieta)[i]);
	      kount.push_back(1);
	    }
	  }
      }
  }

  bool sFGVB(false);
  for (unsigned int k=0; k< etaIndex.size(); ++k) {
    if(kount[k] >=2)
      {
	sFGVB = true;
	break;
      }
  }
  return sFGVB;
}

bool tree::VertexDecision(int &foundVertex){
  bool vtxAccepted=false;
  for(int i=0;i<Vertex_n;i++){
    TVector3* vertex_position = (TVector3*) Vertex_position->At(i);
    if((fabs(vertex_position->z()) <= 24.0) && ((*Vertex_ndof)[i] >= 4)  && (!(*Vertex_isFake)[i]) && (fabs((*Vertex_d0)[i])<= 2.0))
      foundVertex++;
  }

  if(foundVertex>0)vtxAccepted=true;
  return vtxAccepted;
}


void tree::BookHistos(){
  fileName->cd();
  char name[100];
  std::cout<<"I am in here :"<<std::endl;

  sprintf(name, "h_prob_energy_sFGVB");
  h_prob_energy_sFGVB = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_sFGVB->GetYaxis()->SetTitle("prob");  
  h_prob_energy_sFGVB->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_sFGVB->Sumw2(); 

  sprintf(name, "h_prob_energy_sFGVB_40");
  h_prob_energy_sFGVB_40 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_sFGVB_40->GetYaxis()->SetTitle("prob");  
  h_prob_energy_sFGVB_40->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_sFGVB_40->Sumw2(); 

  sprintf(name, "h_prob_energy_sFGVB_70");
  h_prob_energy_sFGVB_70 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_sFGVB_70->GetYaxis()->SetTitle("prob");  
  h_prob_energy_sFGVB_70->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_sFGVB_70->Sumw2(); 

  sprintf(name, "h_prob_energy_sFGVB_85");
  h_prob_energy_sFGVB_85 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_sFGVB_85->GetYaxis()->SetTitle("prob");  
  h_prob_energy_sFGVB_85->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_sFGVB_85->Sumw2(); 

  sprintf(name, "h_prob_energy");
  h_prob_energy = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy->GetYaxis()->SetTitle("prob");  
  h_prob_energy->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy->Sumw2(); 

  sprintf(name, "h_prob_energy_40");
  h_prob_energy_40 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_40->GetYaxis()->SetTitle("prob");  
  h_prob_energy_40->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_40->Sumw2();  

  sprintf(name, "h_prob_energy_70");
  h_prob_energy_70 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_70->GetYaxis()->SetTitle("prob");  
  h_prob_energy_70->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_70->Sumw2();  

  sprintf(name, "h_prob_energy_85");
  h_prob_energy_85 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_energy_85->GetYaxis()->SetTitle("prob");  
  h_prob_energy_85->GetXaxis()->SetTitle("Energy[GeV]");  
  h_prob_energy_85->Sumw2();   

  sprintf(name, "h_prob_et_sFGVB");
  h_prob_et_sFGVB = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_sFGVB->GetYaxis()->SetTitle("prob");  
  h_prob_et_sFGVB->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_sFGVB->Sumw2();  

  sprintf(name, "h_prob_et_sFGVB_40");
  h_prob_et_sFGVB_40 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_sFGVB_40->GetYaxis()->SetTitle("prob");  
  h_prob_et_sFGVB_40->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_sFGVB_40->Sumw2(); 

  sprintf(name, "h_prob_et_sFGVB_70");
  h_prob_et_sFGVB_70 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_sFGVB_70->GetYaxis()->SetTitle("prob");  
  h_prob_et_sFGVB_70->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_sFGVB_70->Sumw2(); 

  sprintf(name, "h_prob_et_sFGVB_85");
  h_prob_et_sFGVB_85 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_sFGVB_85->GetYaxis()->SetTitle("prob");  
  h_prob_et_sFGVB_85->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_sFGVB_85->Sumw2(); 

  sprintf(name, "h_prob_et");
  h_prob_et = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et->GetYaxis()->SetTitle("prob");  
  h_prob_et->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et->Sumw2();  

  sprintf(name, "h_prob_et_40");
  h_prob_et_40 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_40->GetYaxis()->SetTitle("prob");  
  h_prob_et_40->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_40->Sumw2();  

  sprintf(name, "h_prob_et_70");
  h_prob_et_70 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_70->GetYaxis()->SetTitle("prob");  
  h_prob_et_70->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_70->Sumw2();  

  sprintf(name, "h_prob_et_85");
  h_prob_et_85 = new TH2F(name,"", 10,0,1,2,-0.5, 1.5 );
  h_prob_et_85->GetYaxis()->SetTitle("prob");  
  h_prob_et_85->GetXaxis()->SetTitle("Et[GeV]");  
  h_prob_et_85->Sumw2();  

  sprintf(name, "h_rechit_spike_energy_50");
  h_rechit_spike_energy_50 = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_50->Sumw2(); 
  h_rechit_spike_energy_50->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_ieta_50");
  h_rechit_spike_ieta_50 = new TH1F (name,"" , 18 , 0 , 90);
  h_rechit_spike_ieta_50->Sumw2(); 
  h_rechit_spike_ieta_50->GetXaxis()->SetTitle("|i#eta|");

  sprintf(name, "h_rechit_spike_energy_L1");
  h_rechit_spike_energy_L1 = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_L1->Sumw2(); 
  h_rechit_spike_energy_L1->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_ieta_L1");
  h_rechit_spike_ieta_L1 = new TH1F (name,"" , 18 ,0 , 90);
  h_rechit_spike_ieta_L1->Sumw2(); 
  h_rechit_spike_ieta_L1->GetXaxis()->SetTitle("|i#eta|");

  sprintf(name, "h_rechit_spike_energy_sFGVB");
  h_rechit_spike_energy_sFGVB = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_sFGVB->Sumw2(); 
  h_rechit_spike_energy_sFGVB->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_ieta_sFGVB");
  h_rechit_spike_ieta_sFGVB = new TH1F (name,"" , 18 ,0 , 90);
  h_rechit_spike_ieta_sFGVB->Sumw2(); 
  h_rechit_spike_ieta_sFGVB->GetXaxis()->SetTitle("|i#eta|");

}
