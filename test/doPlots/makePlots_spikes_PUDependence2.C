{
  gStyle->SetOptStat(0);
  gStyle->SetLegendBorderSize(0); 
  
  TLegend* l1=new TLegend(0.15,0.75,0.42,0.90);
  l1->SetFillColor(0);
  //TFile *_file0 = TFile::Open("mc_14TeV_chk.root");
  //  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_Output.root");
  TFile *_file1 = TFile::Open("MinBias_612_8TeV_MBonly_PU2012_BS50_Output.root");
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_BS50_Output.root");


  TProfile*   h_2_f0 = ((TProfile*)((TH2F*)_file0->Get("h_2"))->ProfileX())->Clone("h_2_f0");
  TProfile*   h_2_f1 = ((TProfile*)((TH2F*)_file1->Get("h_2"))->ProfileX())->Clone("h_2_f1");
  TProfile*   h_3_f0 = ((TProfile*)((TH2F*)_file0->Get("h_3"))->ProfileX())->Clone("h_3_f0");
  TProfile*   h_3_f1 = ((TProfile*)((TH2F*)_file1->Get("h_3"))->ProfileX())->Clone("h_3_f1");
  TProfile*   h_4_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4"))->ProfileX())->Clone("h_4_f0");
  TProfile*   h_4_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4"))->ProfileX())->Clone("h_4_f1");
//   TProfile*   h_4_bis_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_bis"))->ProfileX())->Clone("h_4_bis_f0");
//   TProfile*   h_4_bis_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_bis"))->ProfileX())->Clone("h_4_bis_f1");
//   TProfile*   h_4_bis_E4_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_bis_E4"))->ProfileX())->Clone("h_4_bis_E4_f0");
//   TProfile*   h_4_bis_E4_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_bis_E4"))->ProfileX())->Clone("h_4_bis_E4_f1");
//   TProfile*   h_4_bis_E10_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_bis_E10"))->ProfileX())->Clone("h_4_bis_E10_f0");
//   TProfile*   h_4_bis_E10_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_bis_E10"))->ProfileX())->Clone("h_4_bis_E10_f1");
//   TProfile*   h_4_bis_Eb5_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_bis_Eb5"))->ProfileX())->Clone("h_4_bis_Eb5_f0");
//   TProfile*   h_4_bis_Eb5_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_bis_Eb5"))->ProfileX())->Clone("h_4_bis_Eb5_f1");
//   TProfile*   h_4_bis_Et3_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_bis_Et3"))->ProfileX())->Clone("h_4_bis_Et3_f0");
//   TProfile*   h_4_bis_Et3_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_bis_Et3"))->ProfileX())->Clone("h_4_bis_Et3_f1");
//   TProfile*   h_4_pm5ns_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_pm5ns"))->ProfileX())->Clone("h_4_pm5ns_f0");
//   TProfile*   h_4_pm5ns_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_pm5ns"))->ProfileX())->Clone("h_4_pm5ns_f1");
//   TProfile*   h_4_pm15ns_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_pm15ns"))->ProfileX())->Clone("h_4_pm15ns_f0");
//   TProfile*   h_4_pm15ns_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_pm15ns"))->ProfileX())->Clone("h_4_pm15ns_f1");
//   TProfile*   h_4_OOTp15ns_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_OOTp15ns"))->ProfileX())->Clone("h_4_OOTp15ns_f0");
//   TProfile*   h_4_OOTp15ns_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_OOTp15ns"))->ProfileX())->Clone("h_4_OOTp15ns_f1");
//   TProfile*   h_4_OOTn15ns_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_OOTn15ns"))->ProfileX())->Clone("h_4_OOTn15ns_f0");
//   TProfile*   h_4_OOTn15ns_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_OOTn15ns"))->ProfileX())->Clone("h_4_OOTn15ns_f1");

  TProfile*   h_4_PU_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_vsPU"))->ProfileX())->Clone("h_4_PU_f0"); 
  TProfile*   h_4_PU_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_vsPU"))->ProfileX())->Clone("h_4_PU_f1"); 
  TProfile*   h_4_PU_it_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_vsPU_it"))->ProfileX())->Clone("h_4_PU_it_f0"); 
  TProfile*   h_4_PU_it_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_vsPU_it"))->ProfileX())->Clone("h_4_PU_it_f1"); 
  TProfile*   h_4_PU_ms_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_vsPU_ms"))->ProfileX())->Clone("h_4_PU_ms_f0"); 
  TProfile*   h_4_PU_ms_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_vsPU_ms"))->ProfileX())->Clone("h_4_PU_ms_f1"); 
  TProfile*   h_4_PU_ps_f0 = ((TProfile*)((TH2F*)_file0->Get("h_4_vsPU_ps"))->ProfileX())->Clone("h_4_PU_ps_f0"); 
  TProfile*   h_4_PU_ps_f1 = ((TProfile*)((TH2F*)_file1->Get("h_4_vsPU_ps"))->ProfileX())->Clone("h_4_PU_ps_f1"); 

  if(1 == 1){
  TCanvas* c1 = new TCanvas();
  gPad->SetGrid();
  //  gPad->SetTick();
  h_3_f0->SetMarkerStyle(7);
  h_3_f0->SetMarkerColor(kCyan+1);
  h_3_f0->SetLineColor(kCyan+1);
  h_3_f0->SetLineWidth(3);
  h_3_f0->Rebin(2);
  //h_3_pfx->SetMaximum(14);
  h_3_f0->GetYaxis()->SetTitle("Spikes/event");
  h_3_f0->GetXaxis()->SetTitle("nVtx or nPU");
  h_3_f0->GetXaxis()->SetRangeUser(0., 700.);
  h_3_f0->Draw();

  h_4_f0->SetMarkerStyle(7);
  h_4_f0->SetLineWidth(3);
  h_4_f0->Rebin(2);
  h_4_f0->SetMarkerColor(kYellow+1);
  h_4_f0->SetLineColor(kYellow+1);
  h_4_f0->Draw("sames");

  h_4_PU_f0->SetMarkerStyle(7);        
  h_4_PU_f0->SetLineWidth(3);           
  h_4_PU_f0->Rebin(2);                  
  h_4_PU_f0->SetMarkerColor(kMagenta);  
  h_4_PU_f0->SetLineColor(kMagenta);    
  h_4_PU_f0->Draw("sames");             

  h_4_PU_it_f0->SetMarkerStyle(7);       
  h_4_PU_it_f0->SetLineWidth(3);          
  h_4_PU_it_f0->Rebin(2);                 
  h_4_PU_it_f0->SetMarkerColor(kViolet);  
  h_4_PU_it_f0->SetLineColor(kViolet);    
  h_4_PU_it_f0->Draw("sames");            

  h_4_PU_ms_f0->SetMarkerStyle(7);        
  h_4_PU_ms_f0->SetLineWidth(3);           
  h_4_PU_ms_f0->Rebin(2);                  
  h_4_PU_ms_f0->SetMarkerColor(kBlue);     
  h_4_PU_ms_f0->SetLineColor(kBlue);       
  h_4_PU_ms_f0->Draw("sames");             

  h_4_PU_ps_f0->SetMarkerStyle(7);       
  h_4_PU_ps_f0->SetLineWidth(3);          
  h_4_PU_ps_f0->Rebin(2);                 
  h_4_PU_ps_f0->SetMarkerColor(kGreen+2); 
  h_4_PU_ps_f0->SetLineColor(kGreen+2);   
  h_4_PU_ps_f0->Draw("sames");            


//   h_4_bis_f0->SetMarkerStyle(20);
//   h_4_bis_f0->SetLineWidth(3);
//   h_4_bis_f0->Rebin(2);
//   h_4_bis_f0->SetMarkerColor(kMagenta);
//   h_4_bis_f0->SetLineColor(kMagenta);
//   h_4_bis_f0->Draw("sames");

//   h_4_bis_Eb5_f0->SetMarkerStyle(21);
//   h_4_bis_Eb5_f0->SetLineWidth(3);
//   h_4_bis_Eb5_f0->Rebin(2);
//   h_4_bis_Eb5_f0->SetMarkerColor(kViolet);
//   h_4_bis_Eb5_f0->SetLineColor(kViolet);
//   h_4_bis_Eb5_f0->Draw("sames");

//   h_4_bis_E4_f0->SetMarkerStyle(21);
//   h_4_bis_E4_f0->SetLineWidth(3);
//   h_4_bis_E4_f0->Rebin(2);
//   h_4_bis_E4_f0->SetMarkerColor(kBlue);
//   h_4_bis_E4_f0->SetLineColor(kBlue);
//   h_4_bis_E4_f0->Draw("sames");

//   h_4_bis_E10_f0->SetMarkerStyle(21);
//   h_4_bis_E10_f0->SetLineWidth(3);
//   h_4_bis_E10_f0->Rebin(2);
//   h_4_bis_E10_f0->SetMarkerColor(kGreen+2);
//   h_4_bis_E10_f0->SetLineColor(kGreen+2);
//   h_4_bis_E10_f0->Draw("sames");

//   h_4_bis_Et3_f0->SetMarkerStyle(23);
//   h_4_bis_Et3_f0->SetLineWidth(3);
//   h_4_bis_Et3_f0->Rebin(2);
//   h_4_bis_Et3_f0->SetMarkerColor(kGreen);
//   h_4_bis_Et3_f0->SetLineColor(kGreen);
//   h_4_bis_Et3_f0->Draw("sames");

//   h_4_pm5ns_f0->SetMarkerStyle(4);
//   h_4_pm5ns_f0->SetLineWidth(3);
//   h_4_pm5ns_f0->Rebin(2);
//   h_4_pm5ns_f0->SetMarkerColor(kRed);
//   h_4_pm5ns_f0->SetLineColor(kRed);
//   h_4_pm5ns_f0->Draw("sames");

//   h_4_pm15ns_f0->SetMarkerStyle(21);
//   h_4_pm15ns_f0->SetLineWidth(3);
//   h_4_pm15ns_f0->Rebin(2);
//   h_4_pm15ns_f0->SetMarkerColor(kRed+2);
//   h_4_pm15ns_f0->SetLineColor(kRed+2);
//   h_4_pm15ns_f0->Draw("sames");

//   h_4_OOTp15ns_f0->SetMarkerStyle(21);
//   h_4_OOTp15ns_f0->SetLineWidth(3);
//   h_4_OOTp15ns_f0->Rebin(2);
//   h_4_OOTp15ns_f0->SetMarkerColor(kCyan+2);
//   h_4_OOTp15ns_f0->SetLineColor(kCyan+2);
//   h_4_OOTp15ns_f0->Draw("sames");

//   h_4_OOTn15ns_f0->SetMarkerStyle(20);
//   h_4_OOTn15ns_f0->SetLineWidth(3);
//   h_4_OOTn15ns_f0->Rebin(2);
//   h_4_OOTn15ns_f0->SetMarkerColor(kCyan-3);
//   h_4_OOTn15ns_f0->SetLineColor(kCyan-3);
//   h_4_OOTn15ns_f0->Draw("sames");


  h_2_f0->SetMarkerStyle(7);
  h_2_f0->SetLineColor(kBlack);
  h_2_f0->SetLineWidth(3);
  h_2_f0->Draw("sames");
  
  l1->AddEntry(h_2_f0,"kWeird (vs nVtx)","pl");
  l1->AddEntry(h_3_f0,"APD hit > 50 ADC (vs nVtx)","pl");
  l1->AddEntry(h_4_f0,"APD hit > 100 ADC (vs nVtx)","pl");
  l1->AddEntry(h_4_PU_f0,"APD hit > 100 ADC (vs nPU inTime+OOT)","pl");
  l1->AddEntry(h_4_PU_it_f0,"APD hit > 100 ADC (vs PU inTime)","pl");
  l1->AddEntry(h_4_PU_ms_f0,"APD hit > 100 ADC (vs PU OOT early)","pl");
  l1->AddEntry(h_4_PU_ps_f0,"APD hit > 100 ADC (vs PU OOT late)","pl");


//   l1->AddEntry(h_4_bis_f0,"recHit > 50 ADC","p");
//   l1->AddEntry(h_4_bis_Eb5_f0,"recHit > 50 ADC (E<5)","p");
//   l1->AddEntry(h_4_bis_E4_f0,"recHit > 50 ADC (E>4)","p");
//   l1->AddEntry(h_4_bis_E10_f0,"recHit > 50 ADC (E>10)","p");
//   l1->AddEntry(h_4_bis_Et3_f0,"recHit > 50 ADC (Et>3)","p");
//   l1->AddEntry(h_4_pm5ns_f0,"recHit > 50 ADC time in 5ns","p");
//   l1->AddEntry(h_4_pm15ns_f0,"recHit > 50 ADC time in 15ns","p");
//   l1->AddEntry(h_4_OOTp15ns_f0,"recHit > 50 ADC time OOT > +15ns","p");
//   l1->AddEntry(h_4_OOTn15ns_f0,"recHit > 50 ADC time OOT < -15ns","p");
  l1->Draw("same");
  }

  /// f1
  h_3_f1->SetMarkerStyle(25);
  h_3_f1->SetMarkerColor(kCyan+1);
  h_3_f1->SetLineColor(kCyan+1);
  h_3_f1->SetLineWidth(3);
  h_3_f1->Rebin(2);
  //h_3_pfx->SetMaximum(14);
  h_3_f1->GetYaxis()->SetTitle("Spikes/event");
  h_3_f1->Draw("sames");
  //  h_3_f1->Draw();

  h_4_f1->SetMarkerStyle(25);
  h_4_f1->SetLineWidth(3);
  h_4_f1->Rebin(2);
  h_4_f1->SetMarkerColor(kYellow+1);
  h_4_f1->SetLineColor(kYellow+1);
  h_4_f1->Draw("sames");

  h_4_PU_f1->SetMarkerStyle(25);        
  h_4_PU_f1->SetLineWidth(3);           
  h_4_PU_f1->Rebin(2);                  
  h_4_PU_f1->SetMarkerColor(kMagenta);  
  h_4_PU_f1->SetLineColor(kMagenta);    
  h_4_PU_f1->Draw("sames");             

  h_4_PU_it_f1->SetMarkerStyle(25);       
  h_4_PU_it_f1->SetLineWidth(3);          
  h_4_PU_it_f1->Rebin(2);                 
  h_4_PU_it_f1->SetMarkerColor(kViolet);  
  h_4_PU_it_f1->SetLineColor(kViolet);    
  h_4_PU_it_f1->Draw("sames");            

  h_4_PU_ms_f1->SetMarkerStyle(25);        
  h_4_PU_ms_f1->SetLineWidth(3);           
  h_4_PU_ms_f1->Rebin(2);                  
  h_4_PU_ms_f1->SetMarkerColor(kBlue);     
  h_4_PU_ms_f1->SetLineColor(kBlue);       
  h_4_PU_ms_f1->Draw("sames");             

  h_4_PU_ps_f1->SetMarkerStyle(25);       
  h_4_PU_ps_f1->SetLineWidth(3);          
  h_4_PU_ps_f1->Rebin(2);                 
  h_4_PU_ps_f1->SetMarkerColor(kGreen+2); 
  h_4_PU_ps_f1->SetLineColor(kGreen+2);   
  h_4_PU_ps_f1->Draw("sames");            

//   h_4_bis_f1->SetMarkerStyle(20);
//   h_4_bis_f1->SetLineWidth(3);
//   h_4_bis_f1->Rebin(2);
//   h_4_bis_f1->SetMarkerColor(kMagenta);
//   h_4_bis_f1->SetLineColor(kMagenta);
//   h_4_bis_f1->Draw("sames");

//   h_4_bis_Eb5_f1->SetMarkerStyle(21);
//   h_4_bis_Eb5_f1->SetLineWidth(3);
//   h_4_bis_Eb5_f1->Rebin(2);
//   h_4_bis_Eb5_f1->SetMarkerColor(kViolet);
//   h_4_bis_Eb5_f1->SetLineColor(kViolet);
//   h_4_bis_Eb5_f1->Draw("sames");

//   h_4_bis_E4_f1->SetMarkerStyle(21);
//   h_4_bis_E4_f1->SetLineWidth(3);
//   h_4_bis_E4_f1->Rebin(2);
//   h_4_bis_E4_f1->SetMarkerColor(kBlue);
//   h_4_bis_E4_f1->SetLineColor(kBlue);
//   h_4_bis_E4_f1->Draw("sames");

//   h_4_bis_E10_f1->SetMarkerStyle(21);
//   h_4_bis_E10_f1->SetLineWidth(3);
//   h_4_bis_E10_f1->Rebin(2);
//   h_4_bis_E10_f1->SetMarkerColor(kGreen+2);
//   h_4_bis_E10_f1->SetLineColor(kGreen+2);
//   h_4_bis_E10_f1->Draw("sames");

//   h_4_bis_Et3_f1->SetMarkerStyle(23);
//   h_4_bis_Et3_f1->SetLineWidth(3);
//   h_4_bis_Et3_f1->Rebin(2);
//   h_4_bis_Et3_f1->SetMarkerColor(kGreen);
//   h_4_bis_Et3_f1->SetLineColor(kGreen);
//   h_4_bis_Et3_f1->Draw("sames");

//   h_4_pm5ns_f1->SetMarkerStyle(4);
//   h_4_pm5ns_f1->SetLineWidth(3);
//   h_4_pm5ns_f1->Rebin(2);
//   h_4_pm5ns_f1->SetMarkerColor(kRed);
//   h_4_pm5ns_f1->SetLineColor(kRed);
//   h_4_pm5ns_f1->Draw("sames");

//   h_4_pm15ns_f1->SetMarkerStyle(21);
//   h_4_pm15ns_f1->SetLineWidth(3);
//   h_4_pm15ns_f1->Rebin(2);
//   h_4_pm15ns_f1->SetMarkerColor(kRed+2);
//   h_4_pm15ns_f1->SetLineColor(kRed+2);
//   h_4_pm15ns_f1->Draw("sames");

//   h_4_OOTp15ns_f1->SetMarkerStyle(21);
//   h_4_OOTp15ns_f1->SetLineWidth(3);
//   h_4_OOTp15ns_f1->Rebin(2);
//   h_4_OOTp15ns_f1->SetMarkerColor(kCyan+2);
//   h_4_OOTp15ns_f1->SetLineColor(kCyan+2);
//   h_4_OOTp15ns_f1->Draw("sames");

//   h_4_OOTn15ns_f1->SetMarkerStyle(20);
//   h_4_OOTn15ns_f1->SetLineWidth(3);
//   h_4_OOTn15ns_f1->Rebin(2);
//   h_4_OOTn15ns_f1->SetMarkerColor(kCyan-3);
//   h_4_OOTn15ns_f1->SetLineColor(kCyan-3);
//   h_4_OOTn15ns_f1->Draw("sames");

  h_2_f1->Rebin(2);
  h_2_f1->SetLineColor(kBlack);
  h_2_f1->SetMarkerStyle(25);
  h_2_f1->SetLineWidth(3);
  h_2_f1->Draw("sames");

  c1->SaveAs("Spikes_dfTuning.pdf");
}
