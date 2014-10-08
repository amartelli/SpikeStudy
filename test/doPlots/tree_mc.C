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
     int n_spikes = 0;     
     int n_spikes_sw = 0;     
     int n_spikes_50APD = 0;

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   std::cout << "fChain->GetEntries = " << fChain->GetEntries() << std::endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     std::cout<<"Event:"<<jentry<<std::endl;
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     bool vertexdecision;
     int foundVertex = 0;
     vertexdecision  = VertexDecision(foundVertex);
     

     int n_kWeird     = 0;
     int n_swissCross = 0;
     int n_truth_50   = 0;
     int n_rec_50        = 0;
     int n_rec_50_E4        = 0;
     int n_rec_50_Eb5        = 0;
     int n_rec_50_E10        = 0;
     int n_rec_50_Et3        = 0;
     int n_rec_50_pm5ns  = 0;
     int n_rec_50_pm15ns = 0;
     int n_rec_50_OOTp15ns = 0;
     int n_rec_50_OOTn15ns = 0;
     int n_truth      = 0;
     int n_truth_100  = 0;
     int n_rechits    = 0;
     int n_rechits_1 = 0;

     if(vertexdecision)
       {
	 for(int i = 0; i < APDhit_50_counts->size(); i++)
	   {
	     n_truth++;

	     if((*APDhit_50_counts)[i])
	       n_truth_50++;
	     
	     if((*APDhit_100_counts)[i])
	       n_truth_100++;
	   }
	 
	 for(int i = 0; i < Rechit_energy->size(); i++)
	   {
	     //////remove here//////
	     if( ((*Rechit_ieta)[i] == 11 && (*Rechit_iphi)[i]== 68)            //remove
		 || ((*Rechit_ieta)[i]  ==  68 && (*Rechit_iphi)[i]== 74 ) //remove
		 || ((*Rechit_ieta)[i]  == -83 && (*Rechit_iphi)[i]== 189) //remove
		 || ((*Rechit_ieta)[i]  == -75 && (*Rechit_iphi)[i]== 199) //remove
		 || ((*Rechit_ieta)[i]  == -81 && (*Rechit_iphi)[i]== 316) //remove
		 ) continue;//remove

	     n_rechits++;
	     if((*Rechit_energy)[i] > 1.)
	       n_rechits_1++;

	     //	     if((*Rechit_energy)[i] > 3.)
	     if((*Rechit_et)[i] > 3.)
               {
                 if((*Rechit_is_spike)[i])
		   n_spikes++;
                 if((*Rechit_swissCross)[i] > 0.95)
                   n_spikes_sw++;
               }
	   

	     bool kW_tag = false; 
	     float threshold = 0.04*log10((*Rechit_energy)[i]) - 0.024; 
	     if((*Rechit_ifnearCrack)[i] )
	       threshold = threshold/3.;
	     
	     if ( (*Rechit_energy)[i] >= 4. && !((*Rechit_ifnearCrack)[i]))
	       if( 1-(*Rechit_swissCross)[i] < threshold ) 
		 kW_tag = true;
	     
	     if ( (*Rechit_energy)[i] >= 8. && ((*Rechit_ifnearCrack)[i]))
	       if( 1-(*Rechit_swissCross)[i] < threshold ) 
		 kW_tag = true;

	     h_rechit_energy_all->Fill((*Rechit_energy)[i]);
	     h_rechit_swissCross_PU->Fill(foundVertex, (*Rechit_swissCross)[i]); 
	     h_rechit_e4_PU->Fill(foundVertex, (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
	     h_rechit_e4_ieta->Fill((*Rechit_ieta)[i], (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
	     h_rechit_e1_PU->Fill(foundVertex, (*Rechit_energy)[i]); 
	     h_rechit_e1_ieta->Fill((*Rechit_ieta)[i], (*Rechit_energy)[i]); 

	     if((*Rechit_is_spike)[i])
	       {
		 h_rechit_spike_energy->Fill((*Rechit_energy)[i] );
		 h_rechit_spike_swissCross_PU->Fill(foundVertex, (*Rechit_swissCross)[i]); 
		 h_rechit_spike_e4_PU->Fill(foundVertex, (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e4_ieta->Fill((*Rechit_ieta)[i], (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e1_PU->Fill(foundVertex, (*Rechit_energy)[i]); 
		 h_rechit_spike_e1_ieta->Fill((*Rechit_ieta)[i], (*Rechit_energy)[i]); 
	       }

	     if((*Rechit_is_spike_50_counts)[i])
	       {
		 h_rechit_spike_energy_50->Fill((*Rechit_energy)[i] );
		 if((*Rechit_energy)[i] > 4 )
		   h_rechit_spike_swissCross_ieta_50->Fill((*Rechit_swissCross)[i], abs((*Rechit_ieta)[i]) );

		 if((*Rechit_energy)[i] > 10 )
		   h_rechit_spike_swissCross_ieta_50_10->Fill((*Rechit_swissCross)[i], abs((*Rechit_ieta)[i]) );

		 h_rechit_spike_swissCross_PU_50->Fill(foundVertex, (*Rechit_swissCross)[i]); 
		 h_rechit_spike_e4_PU_50->Fill(foundVertex, (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e4_ieta_50->Fill((*Rechit_ieta)[i], (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e1_PU_50->Fill(foundVertex, (*Rechit_energy)[i]); 
		 h_rechit_spike_e1_ieta_50->Fill((*Rechit_ieta)[i], (*Rechit_energy)[i]); 
		 h_rechit_spike_swissCross_energy_50->Fill((*Rechit_swissCross)[i], (*Rechit_energy)[i] );
		
		 if((*Rechit_ifkWeird)[i])
		   {
		     h_rechit_spike_energy_kWeird->Fill((*Rechit_energy)[i] );
		     h_rechit_spike_swissCross_energy_kWeird->Fill((*Rechit_swissCross)[i], (*Rechit_energy)[i] );
		     h_rechit_spike_swissCross_ieta_kWeird->Fill((*Rechit_swissCross)[i], abs((*Rechit_ieta)[i]) );
		     if((*Rechit_energy)[i] > 10 )
		       h_rechit_spike_swissCross_ieta_kWeird_10->Fill((*Rechit_swissCross)[i], abs((*Rechit_ieta)[i]) );
		   }

		 if(kW_tag) 
		   h_rechit_spike_swissCross_energy_kW_tag->Fill((*Rechit_swissCross)[i], (*Rechit_energy)[i] );
	       }

	     if((*Rechit_is_spike_100_counts)[i])
	       {
		 h_rechit_spike_energy_100->Fill((*Rechit_energy)[i] );
		 h_rechit_spike_swissCross_PU_100->Fill(foundVertex, (*Rechit_swissCross)[i]); 
		 h_rechit_spike_e4_PU_100->Fill(foundVertex, (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e4_ieta_100->Fill((*Rechit_ieta)[i], (1 - (*Rechit_swissCross)[i])*(*Rechit_energy)[i]); 
		 h_rechit_spike_e1_PU_100->Fill(foundVertex, (*Rechit_energy)[i]); 
		 h_rechit_spike_e1_ieta_100->Fill((*Rechit_ieta)[i], (*Rechit_energy)[i]); 
	       }

	     if((*Rechit_energy)[i] > 4.)
	       {
		 h_rechit_time_all->Fill((*Rechit_time)[i]);
		 
		 if((*Rechit_is_spike)[i])
		   h_rechit_spike_time->Fill((*Rechit_time)[i] );

		 if((*Rechit_is_spike_50_counts)[i])
		   h_rechit_spike_time_50->Fill((*Rechit_time)[i] );
		 
		 if((*Rechit_is_spike_100_counts)[i])
		   h_rechit_spike_time_100->Fill((*Rechit_time)[i] );

	       }
	     
	     if((*Rechit_energy)[i] < 5. && (*Rechit_swissCross)[i] > 0.95) ++n_rec_50_Eb5;
	     if((*Rechit_energy)[i] > 4. && (*Rechit_swissCross)[i] > 0.95) ++n_rec_50_E4;
	     if((*Rechit_energy)[i] > 10.&& (*Rechit_swissCross)[i] > 0.95) ++n_rec_50_E10;
	     if((*Rechit_et)[i] > 3. && (*Rechit_swissCross)[i] > 0.95) ++n_rec_50_Et3;

	     if((*Rechit_et)[i] > 3.){
	     h_rechit_time_vs_SwissCross->Fill((*Rechit_swissCross)[i], (*Rechit_time)[i]);
	     if((*Rechit_swissCross)[i] > 0.95){
	       //if(Rechit_is_spike_50_counts){
	       //h_rechit_time_vs_spike_energy_50->Fill((*Rechit_swissCross)[i], (*Rechit_time)[i]);
	       ++n_rec_50;
	       if((*Rechit_time)[i] > -5. && (*Rechit_time)[i]<5.) ++n_rec_50_pm5ns;
	       if((*Rechit_time)[i] > -15. && (*Rechit_time)[i]<15.) ++n_rec_50_pm15ns;
	       if((*Rechit_time)[i] > 15.) ++n_rec_50_OOTp15ns;
	       if((*Rechit_time)[i] < -15.) ++n_rec_50_OOTn15ns;
	     }
	     }

	     if((*Rechit_ifkWeird)[i])
	       {
		 n_kWeird++;
		 h_rechit_energy_kWeird->Fill((*Rechit_energy)[i]);
		 h_rechit_time_kWeird->Fill((*Rechit_time)[i]);
	       }
	    	     	     
	     if((*Rechit_swissCross)[i] > 0.95 && (*Rechit_energy)[i] > 4. )
	       {
		 n_swissCross++;
		 h_rechit_energy_swissCross->Fill((*Rechit_energy)[i]);
		 h_rechit_time_swissCross->Fill((*Rechit_time)[i]);
	       }
	   }


	 int PU = npuVertices + npuVerticesms + npuVerticesps;

	 h_1->Fill(foundVertex, n_truth);
	 h_2->Fill(foundVertex, n_kWeird);
	 h_3->Fill(foundVertex, n_truth_50);
	 h_4->Fill(foundVertex, n_truth_100);
	 h_4_vsPU->Fill(PU, n_truth_100);
	 h_4_vsPU_it->Fill(npuVertices, n_truth_100);
	 h_4_vsPU_ms->Fill(npuVerticesms, n_truth_100);
	 h_4_vsPU_ps->Fill(npuVerticesps, n_truth_100);
	 h_5->Fill(foundVertex, n_swissCross);
	 h_4_bis->Fill(foundVertex, n_rec_50);
	 h_4_bis_E4->Fill(foundVertex, n_rec_50_E4);
	 h_4_bis_Eb5->Fill(foundVertex, n_rec_50_Eb5);
	 h_4_bis_E10->Fill(foundVertex, n_rec_50_E10);
	 h_4_bis_Et3->Fill(foundVertex, n_rec_50_Et3);
 	 h_4_pm5ns->Fill(foundVertex, n_rec_50_pm5ns);
 	 h_4_pm15ns->Fill(foundVertex, n_rec_50_pm15ns);
 	 h_4_OOTp15ns->Fill(foundVertex, n_rec_50_OOTp15ns);
 	 h_4_OOTn15ns->Fill(foundVertex, n_rec_50_OOTn15ns);

	 h_1_tracks->Fill(Track_n, n_truth);
	 h_2_tracks->Fill(Track_n, n_kWeird);
	 h_3_tracks->Fill(Track_n, n_truth_50);
	 h_4_tracks->Fill(Track_n, n_truth_100);
	 h_5_tracks->Fill(Track_n, n_swissCross);

	 h_spikeDigis->Fill(n_truth);
	 h_vertices->Fill(Vertex_n);
	 h_tracks_vertices->Fill(Vertex_n, Track_n);
	 h_tracks_Goodvertices->Fill(foundVertex, Track_n);
	 h_rechits_vertices->Fill(Vertex_n, n_rechits);
	 h_rechits_Goodvertices->Fill(foundVertex, n_rechits);
	 h_rechits_vertices_1->Fill(Vertex_n, n_rechits_1);
	 h_rechits_Goodvertices_1->Fill(foundVertex, n_rechits_1);

       }
   }
     std::cout << " >> n_spikes = " << n_spikes << std::endl;
     std::cout << " >> n_spikes_sw = " << n_spikes_sw << std::endl;

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


void tree::BookHistos(const char* file2){
  fileName = new TFile(file2, "RECREATE");
  fileName->cd();
  char name[100];
  std::cout<<"I am in here :"<<std::endl;

  sprintf(name, "h_1");
  h_1 = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_1->GetYaxis()->SetTitle("Spikes/event");
  h_1->GetXaxis()->SetTitle("Number of Vertices");
  h_1->Sumw2(); 

  sprintf(name, "h_2");
  h_2 = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_2->GetYaxis()->SetTitle("Spikes/event");
  h_2->GetXaxis()->SetTitle("Number of Vertices");
  h_2->Sumw2(); 

  sprintf(name, "h_3");
  h_3 = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_3->GetYaxis()->SetTitle("Spikes/event");
  h_3->GetXaxis()->SetTitle("Number of Vertices");
  h_3->Sumw2(); 

  sprintf(name, "h_4");
  h_4 = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_4->GetYaxis()->SetTitle("Spikes/event");
  h_4->GetXaxis()->SetTitle("Number of Vertices");
  h_4->Sumw2(); 

  sprintf(name, "h_4_vsPU");
  h_4_vsPU = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_4_vsPU->GetYaxis()->SetTitle("Spikes/event");
  h_4_vsPU->GetXaxis()->SetTitle("Number of Vertices");
  h_4_vsPU->Sumw2(); 

  sprintf(name, "h_4_vsPU_ms");
  h_4_vsPU_ms = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_4_vsPU_ms->GetYaxis()->SetTitle("Spikes/event");
  h_4_vsPU_ms->GetXaxis()->SetTitle("Number of PUms");
  h_4_vsPU_ms->Sumw2(); 

  sprintf(name, "h_4_vsPU_it");
  h_4_vsPU_it = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_4_vsPU_it->GetYaxis()->SetTitle("Spikes/event");
  h_4_vsPU_it->GetXaxis()->SetTitle("Number of PUit");
  h_4_vsPU_it->Sumw2(); 

  sprintf(name, "h_4_vsPU_ps");
  h_4_vsPU_ps = new TH2F(name,"", 2000, -0.5, 1999.5, 500, -0.5, 499.5);
  h_4_vsPU_ps->GetYaxis()->SetTitle("Spikes/event");
  h_4_vsPU_ps->GetXaxis()->SetTitle("Number of PUps");
  h_4_vsPU_ps->Sumw2(); 

  sprintf(name, "h_4_bis");
  h_4_bis = new TH2F(name,"", 80, -0.5, 79.5, 2000, -0.5, 999.5);
  h_4_bis->GetYaxis()->SetTitle("Spikes/event (events from recHit)");
  h_4_bis->GetXaxis()->SetTitle("Number of Vertices");
  h_4_bis->Sumw2(); 

  sprintf(name, "h_4_bis_E4");
  h_4_bis_E4 = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_bis_E4->GetYaxis()->SetTitle("Spikes/event (events from recHit SW + E>4)");
  h_4_bis_E4->GetXaxis()->SetTitle("Number of Vertices");
  h_4_bis_E4->Sumw2(); 

  sprintf(name, "h_4_bis_Eb5");
  h_4_bis_Eb5 = new TH2F(name,"", 80, -0.5, 79.5, 2000, -0.5, 999.5);
  h_4_bis_Eb5->GetYaxis()->SetTitle("Spikes/event (events from recHit SW + E<5)");
  h_4_bis_Eb5->GetXaxis()->SetTitle("Number of Vertices");
  h_4_bis_Eb5->Sumw2(); 

  sprintf(name, "h_4_bis_E10");
  h_4_bis_E10 = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_bis_E10->GetYaxis()->SetTitle("Spikes/event (events from recHit SW + E>10)");
  h_4_bis_E10->GetXaxis()->SetTitle("Number of Vertices");
  h_4_bis_E10->Sumw2(); 

  sprintf(name, "h_4_bis_Et3");
  h_4_bis_Et3 = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_bis_Et3->GetYaxis()->SetTitle("Spikes/event (events from recHit SW + Et>3)");
  h_4_bis_Et3->GetXaxis()->SetTitle("Number of Vertices");
  h_4_bis_Et3->Sumw2(); 

  sprintf(name, "h_4_pm5ns");
  h_4_pm5ns = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_pm5ns->GetYaxis()->SetTitle("Spikes/event (events in #pm 5ns)");
  h_4_pm5ns->GetXaxis()->SetTitle("Number of Vertices");
  h_4_pm5ns->Sumw2(); 

  sprintf(name, "h_4_pm15ns");
  h_4_pm15ns = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_pm15ns->GetYaxis()->SetTitle("Spikes/event (events in #pm 15ns)");
  h_4_pm15ns->GetXaxis()->SetTitle("Number of Vertices");
  h_4_pm15ns->Sumw2(); 

  sprintf(name, "h_4_OOTp15ns");
  h_4_OOTp15ns = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_OOTp15ns->GetYaxis()->SetTitle("Spikes/event (events in OOT > +15ns)");
  h_4_OOTp15ns->GetXaxis()->SetTitle("Number of Vertices");
  h_4_OOTp15ns->Sumw2(); 

  sprintf(name, "h_4_OOTn15ns");
  h_4_OOTn15ns = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_4_OOTn15ns->GetYaxis()->SetTitle("Spikes/event (events in OOT < -15ns)");
  h_4_OOTn15ns->GetXaxis()->SetTitle("Number of Vertices");
  h_4_OOTn15ns->Sumw2(); 

  sprintf(name, "h_5");
  h_5 = new TH2F(name,"", 80, -0.5, 79.5, 500, -0.5, 499.5);
  h_5->GetYaxis()->SetTitle("Spikes/event");
  h_5->GetXaxis()->SetTitle("Number of Vertices");
  h_5->Sumw2(); 

  sprintf(name, "h_1_tracks");
  h_1_tracks = new TH2F(name,"", 1200, -0.5, 1199.5, 500, -0.5 , 499.5);
  h_1_tracks->GetYaxis()->SetTitle("Spikes/event");
  h_1_tracks->GetXaxis()->SetTitle("Number of Tracks");
  h_1_tracks->Sumw2(); 

  sprintf(name, "h_2_tracks");
  h_2_tracks = new TH2F(name,"", 1200, -0.5, 1199.5, 100, -0.5, 99.5);
  h_2_tracks->GetYaxis()->SetTitle("Spikes/event");
  h_2_tracks->GetXaxis()->SetTitle("Number of Tracks");
  h_2_tracks->Sumw2(); 

  sprintf(name, "h_3_tracks");
  h_3_tracks = new TH2F(name,"", 1200, -0.5, 1199.5, 100, -0.5, 99.5);
  h_3_tracks->GetYaxis()->SetTitle("Spikes/event");
  h_3_tracks->GetXaxis()->SetTitle("Number of Tracks");
  h_3_tracks->Sumw2(); 

  sprintf(name, "h_4_tracks");
  h_4_tracks = new TH2F(name,"", 1200, -0.5, 1199.5, 100, -0.5, 99.5);
  h_4_tracks->GetYaxis()->SetTitle("Spikes/event");
  h_4_tracks->GetXaxis()->SetTitle("Number of Tracks");
  h_4_tracks->Sumw2(); 

  sprintf(name, "h_5_tracks");
  h_5_tracks = new TH2F(name,"", 1200, -0.5, 1199.5, 100, -0.5, 99.5);
  h_5_tracks->GetYaxis()->SetTitle("Spikes/event");
  h_5_tracks->GetXaxis()->SetTitle("Number of Tracks");
  h_5_tracks->Sumw2(); 

  sprintf(name, "h_rechit_energy_kWeird");
  h_rechit_energy_kWeird = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_energy_kWeird->Sumw2(); 
  h_rechit_energy_kWeird->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_energy_swissCross");
  h_rechit_energy_swissCross = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_energy_swissCross->Sumw2(); 
  h_rechit_energy_swissCross->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_energy_all");
  h_rechit_energy_all = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_energy_all->Sumw2(); 
  h_rechit_energy_all->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_energy");
  h_rechit_spike_energy = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy->Sumw2(); 
  h_rechit_spike_energy->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_energy_50");
  h_rechit_spike_energy_50 = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_50->Sumw2(); 
  h_rechit_spike_energy_50->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_energy_kWeird");
  h_rechit_spike_energy_kWeird = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_kWeird->Sumw2(); 
  h_rechit_spike_energy_kWeird->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_spike_energy_100");
  h_rechit_spike_energy_100 = new TH1F (name,"" , 210 ,-10, 200);
  h_rechit_spike_energy_100->Sumw2(); 
  h_rechit_spike_energy_100->GetXaxis()->SetTitle("Rechit energy [GeV]");

  sprintf(name, "h_rechit_time_all");
  h_rechit_time_all = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_time_all->Sumw2();
  h_rechit_time_all->GetXaxis()->SetTitle("time[ns]");

  /// ara
  sprintf(name, "h_rechit_time_vs_SwissCross");
  h_rechit_time_vs_SwissCross = new TH2F(name, "", 1000, 0.2, 1.2, 1000, -100., 100.);
  h_rechit_time_vs_SwissCross->Sumw2();
  h_rechit_time_vs_SwissCross->GetYaxis()->SetTitle("swiss cross");
  h_rechit_time_vs_SwissCross->GetXaxis()->SetTitle("time[ns]");

  sprintf(name, "h_rechit_time_vs_spike_energy_50");
  h_rechit_time_vs_spike_energy_50 = new TH2F(name, "", 1000, 0.2, 1.2, 1000, -100., 100.);
  h_rechit_time_vs_spike_energy_50->Sumw2();
  h_rechit_time_vs_spike_energy_50->GetXaxis()->SetTitle("spike_energy_50");
  h_rechit_time_vs_spike_energy_50->GetYaxis()->SetTitle("time[ns]");

//   sprintf(name, "h_rechitSpike_energy_50_vs_recHitTime");
//   h_rechitSpike_energy_50_vs_recHitTime = new TProfile(name, "", 1000, -100., 100.);
//   h_rechitSpike_energy_50_vs_recHitTime->Sumw2();
//   h_rechitSpike_energy_50_vs_recHitTime->GetYaxis()->SetTitle("APD>50/rate");
//   h_rechitSpike_energy_50_vs_recHitTime->GetXaxis()->SetTitle("recHit time[ns]");

  /// ara 

  sprintf(name, "h_rechit_time_kWeird");
  h_rechit_time_kWeird = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_time_kWeird->GetXaxis()->SetTitle("time[ns]");
  h_rechit_time_kWeird->Sumw2();

  sprintf(name, "h_rechit_time_swissCross");
  h_rechit_time_swissCross = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_time_swissCross->Sumw2();
  h_rechit_time_swissCross->GetXaxis()->SetTitle("time[ns]");

  sprintf(name, "h_rechit_spike_time");
  h_rechit_spike_time = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_spike_time->GetXaxis()->SetTitle("time[ns]");  
  h_rechit_spike_time->Sumw2();

  sprintf(name, "h_rechit_spike_time_50");
  h_rechit_spike_time_50 = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_spike_time_50->GetXaxis()->SetTitle("time[ns]");  
  h_rechit_spike_time_50->Sumw2();

  sprintf(name, "h_rechit_spike_time_100");
  h_rechit_spike_time_100 = new TH1F (name,"" , 800 ,-200, 200);
  h_rechit_spike_time_100->GetXaxis()->SetTitle("time[ns]");  
  h_rechit_spike_time_100->Sumw2();

  sprintf(name, "h_vertices");
  h_vertices = new TH1F (name,"" , 200, -0.5, 199.5);
  h_vertices->GetXaxis()->SetTitle("Number of vertices");  
  h_vertices->Sumw2();

  sprintf(name, "h_tracks_vertices");
  h_tracks_vertices = new TH2F (name,"" , 200, -0.5, 199.5, 1200, -0.5, 1199.5);
  h_tracks_vertices->GetXaxis()->SetTitle("Number of vertices");  
  h_tracks_vertices->GetYaxis()->SetTitle("Number of tracks");  
  h_tracks_vertices->Sumw2();
  
  sprintf(name, "h_tracks_Goodvertices");
  h_tracks_Goodvertices = new TH2F (name,"" , 200, -0.5, 199.5, 1200, -0.5, 1199.5);
  h_tracks_Goodvertices->GetXaxis()->SetTitle("Number of vertices");  
  h_tracks_Goodvertices->GetYaxis()->SetTitle("Number of tracks");  
  h_tracks_Goodvertices->Sumw2();

  sprintf(name, "h_rechits_vertices");
  h_rechits_vertices = new TH2F (name,"" , 200, -0.5, 199.5, 10000, -0.5, 9999.5);
  h_rechits_vertices->GetXaxis()->SetTitle("Number of vertices");  
  h_rechits_vertices->GetYaxis()->SetTitle("Number of rechits");  
  h_rechits_vertices->Sumw2();
  
  sprintf(name, "h_rechits_Goodvertices");
  h_rechits_Goodvertices = new TH2F (name,"" , 200, -0.5, 199.5, 10000, -0.5, 9999.5);
  h_rechits_Goodvertices->GetXaxis()->SetTitle("Number of vertices");  
  h_rechits_Goodvertices->GetYaxis()->SetTitle("Number of rechits");  
  h_rechits_Goodvertices->Sumw2();

  sprintf(name, "h_rechits_vertices_1");
  h_rechits_vertices_1 = new TH2F (name,"" , 200, -0.5, 199.5, 1000, -0.5, 999.5);
  h_rechits_vertices_1->GetXaxis()->SetTitle("Number of vertices");  
  h_rechits_vertices_1->GetYaxis()->SetTitle("Number of rechits");  
  h_rechits_vertices_1->Sumw2();
  
  sprintf(name, "h_rechits_Goodvertices_1");
  h_rechits_Goodvertices_1 = new TH2F (name,"" , 200, -0.5, 199.5, 1000, -0.5, 999.5);
  h_rechits_Goodvertices_1->GetXaxis()->SetTitle("Number of vertices");  
  h_rechits_Goodvertices_1->GetYaxis()->SetTitle("Number of rechits");  
  h_rechits_Goodvertices_1->Sumw2();

  sprintf(name, "h_spikeDigis");
  h_spikeDigis = new TH1F (name,"" , 500 ,-0.5, 499.5);
  h_spikeDigis->GetXaxis()->SetTitle("Number of spikes");  
  h_spikeDigis->Sumw2();

  sprintf(name, "h_rechit_swissCross_PU");
  h_rechit_swissCross_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_swissCross_PU->GetYaxis()->SetTitle("swissCross");  
  h_rechit_swissCross_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_swissCross_PU->Sumw2();

  sprintf(name, "h_rechit_e4_ieta");
  h_rechit_e4_ieta = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_e4_ieta->GetYaxis()->SetTitle("e4");  
  h_rechit_e4_ieta->GetXaxis()->SetTitle("i#eta");  
  h_rechit_e4_ieta->Sumw2();

  sprintf(name, "h_rechit_e4_PU");
  h_rechit_e4_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_e4_PU->GetYaxis()->SetTitle("e4");  
  h_rechit_e4_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_e4_PU->Sumw2();

  sprintf(name, "h_rechit_e1_ieta");
  h_rechit_e1_ieta = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_e1_ieta->GetYaxis()->SetTitle("e4");  
  h_rechit_e1_ieta->GetXaxis()->SetTitle("i#eta");  
  h_rechit_e1_ieta->Sumw2();

  sprintf(name, "h_rechit_e1_PU");
  h_rechit_e1_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_e1_PU->GetYaxis()->SetTitle("e4");  
  h_rechit_e1_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_e1_PU->Sumw2();

  sprintf(name, "h_rechit_spike_swissCross_PU");
  h_rechit_spike_swissCross_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_swissCross_PU->GetYaxis()->SetTitle("swissCross");  
  h_rechit_spike_swissCross_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_swissCross_PU->Sumw2();

  sprintf(name, "h_rechit_spike_e4_ieta");
  h_rechit_spike_e4_ieta = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e4_ieta->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_ieta->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e4_ieta->Sumw2();

  sprintf(name, "h_rechit_spike_e4_PU");
  h_rechit_spike_e4_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e4_PU->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e4_PU->Sumw2();

  sprintf(name, "h_rechit_spike_e1_ieta");
  h_rechit_spike_e1_ieta = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e1_ieta->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_ieta->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e1_ieta->Sumw2();

  sprintf(name, "h_rechit_spike_e1_PU");
  h_rechit_spike_e1_PU = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e1_PU->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_PU->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e1_PU->Sumw2();

  sprintf(name, "h_rechit_spike_swissCross_PU_50");
  h_rechit_spike_swissCross_PU_50 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_swissCross_PU_50->GetYaxis()->SetTitle("swissCross");  
  h_rechit_spike_swissCross_PU_50->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_swissCross_PU_50->Sumw2();

  sprintf(name, "h_rechit_spike_e4_ieta_50");
  h_rechit_spike_e4_ieta_50 = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e4_ieta_50->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_ieta_50->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e4_ieta_50->Sumw2();

  sprintf(name, "h_rechit_spike_e4_PU_50");
  h_rechit_spike_e4_PU_50 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e4_PU_50->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_PU_50->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e4_PU_50->Sumw2();

  sprintf(name, "h_rechit_spike_e1_ieta_50");
  h_rechit_spike_e1_ieta_50 = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e1_ieta_50->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_ieta_50->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e1_ieta_50->Sumw2();

  sprintf(name, "h_rechit_spike_e1_PU_50");
  h_rechit_spike_e1_PU_50 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e1_PU_50->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_PU_50->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e1_PU_50->Sumw2();

  sprintf(name, "h_rechit_spike_swissCross_PU_100");
  h_rechit_spike_swissCross_PU_100 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_swissCross_PU_100->GetYaxis()->SetTitle("swissCross");  
  h_rechit_spike_swissCross_PU_100->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_swissCross_PU_100->Sumw2();

  sprintf(name, "h_rechit_spike_e4_ieta_100");
  h_rechit_spike_e4_ieta_100 = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e4_ieta_100->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_ieta_100->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e4_ieta_100->Sumw2();

  sprintf(name, "h_rechit_spike_e4_PU_100");
  h_rechit_spike_e4_PU_100 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e4_PU_100->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e4_PU_100->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e4_PU_100->Sumw2();

  sprintf(name, "h_rechit_spike_e1_ieta_100");
  h_rechit_spike_e1_ieta_100 = new TH2F(name,"" , 170 ,-85, 85,  300, 0, 1.2);
  h_rechit_spike_e1_ieta_100->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_ieta_100->GetXaxis()->SetTitle("i#eta");  
  h_rechit_spike_e1_ieta_100->Sumw2();

  sprintf(name, "h_rechit_spike_e1_PU_100");
  h_rechit_spike_e1_PU_100 = new TH2F(name,"" , 200 , -0.5, 199.5, 300, 0, 1.2);
  h_rechit_spike_e1_PU_100->GetYaxis()->SetTitle("e4");  
  h_rechit_spike_e1_PU_100->GetXaxis()->SetTitle("Number of vertices");  
  h_rechit_spike_e1_PU_100->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_energy_50");
  h_rechit_spike_swissCross_energy_50 = new TH2F(name,"" , 48, 0, 1.2, 100, 0, 200. );
  h_rechit_spike_swissCross_energy_50->GetYaxis()->SetTitle("energy");  
  h_rechit_spike_swissCross_energy_50->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_energy_50->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_energy_kWeird");
  h_rechit_spike_swissCross_energy_kWeird = new TH2F(name,"" , 48, 0, 1.2, 100, 0, 200. );
  h_rechit_spike_swissCross_energy_kWeird->GetYaxis()->SetTitle("energy");  
  h_rechit_spike_swissCross_energy_kWeird->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_energy_kWeird->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_energy_kW_tag");
  h_rechit_spike_swissCross_energy_kW_tag = new TH2F(name,"" , 48, 0, 1.2, 100, 0, 200. );
  h_rechit_spike_swissCross_energy_kW_tag->GetYaxis()->SetTitle("energy");  
  h_rechit_spike_swissCross_energy_kW_tag->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_energy_kW_tag->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_ieta_kWeird");
  h_rechit_spike_swissCross_ieta_kWeird = new TH2F(name,"" , 48, 0, 1.2, 17, 0, 85.);
  h_rechit_spike_swissCross_ieta_kWeird->GetYaxis()->SetTitle("|i#eta|");  
  h_rechit_spike_swissCross_ieta_kWeird->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_ieta_kWeird->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_ieta_kWeird_10");
  h_rechit_spike_swissCross_ieta_kWeird_10 = new TH2F(name,"" , 48, 0, 1.2, 17, 0, 85.);
  h_rechit_spike_swissCross_ieta_kWeird_10->GetYaxis()->SetTitle("|i#eta|");  
  h_rechit_spike_swissCross_ieta_kWeird_10->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_ieta_kWeird_10->Sumw2();  

  sprintf(name, "h_rechit_spike_swissCross_ieta_50");
  h_rechit_spike_swissCross_ieta_50 = new TH2F(name,"" , 48, 0, 1.2, 17, 0, 85.);
  h_rechit_spike_swissCross_ieta_50->GetYaxis()->SetTitle("|i#eta|");  
  h_rechit_spike_swissCross_ieta_50->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_ieta_50->Sumw2();

  sprintf(name, "h_rechit_spike_swissCross_ieta_50_10");
  h_rechit_spike_swissCross_ieta_50_10 = new TH2F(name,"" , 48, 0, 1.2, 17, 0, 85.);
  h_rechit_spike_swissCross_ieta_50_10->GetYaxis()->SetTitle("|i#eta|");  
  h_rechit_spike_swissCross_ieta_50_10->GetXaxis()->SetTitle("1-E4/E1");  
  h_rechit_spike_swissCross_ieta_50_10->Sumw2();


}
