{
  gStyle->SetOptStat(0);
  gStyle->SetLegendBorderSize(0); 
  
  TLegend* l1=new TLegend(0.15,0.75,0.42,0.90);
  l1->SetFillColor(0);
  //TFile *_file0 = TFile::Open("mc_14TeV_chk.root");
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_Output.root");

  TCanvas* c1 = new TCanvas();
  h_3->ProfileX();
  h_3_pfx->SetMarkerStyle(25);
  h_3_pfx->SetMarkerColor(kCyan+1);
  h_3_pfx->SetLineColor(kCyan+1);
  h_3_pfx->SetLineWidth(3);
  h_3_pfx->Rebin(2);
  //h_3_pfx->SetMaximum(14);
  h_3_pfx->GetYaxis()->SetTitle("Spikes/event");
  h_3_pfx->Draw();

  h_4->ProfileX();
  h_4_pfx->SetMarkerStyle(25);
  h_4_pfx->SetLineWidth(3);
  h_4_pfx->Rebin(2);
  h_4_pfx->SetMarkerColor(kYellow+1);
  h_4_pfx->SetLineColor(kYellow+1);
  h_4_pfx->Draw("sames");

  h_4_bis->ProfileX();
  h_4_bis_pfx->SetMarkerStyle(20);
  h_4_bis_pfx->SetLineWidth(3);
  h_4_bis_pfx->Rebin(2);
  h_4_bis_pfx->SetMarkerColor(kRed-7);
  h_4_bis_pfx->SetLineColor(kRed-7);
  h_4_bis_pfx->Draw("sames");

  h_4_bis_E4->ProfileX();
  h_4_bis_E4_pfx->SetMarkerStyle(7);
  h_4_bis_E4_pfx->SetLineWidth(3);
  h_4_bis_E4_pfx->Rebin(2);
  h_4_bis_E4_pfx->SetMarkerColor(kBlue);
  h_4_bis_E4_pfx->SetLineColor(kBlue);
  h_4_bis_E4_pfx->Draw("sames");

  h_4_bis_E10->ProfileX();
  h_4_bis_E10_pfx->SetMarkerStyle(21);
  h_4_bis_E10_pfx->SetLineWidth(3);
  h_4_bis_E10_pfx->Rebin(2);
  h_4_bis_E10_pfx->SetMarkerColor(kGreen+2);
  h_4_bis_E10_pfx->SetLineColor(kGreen+2);
  h_4_bis_E10_pfx->Draw("sames");

  h_4_bis_Et3->ProfileX();
  h_4_bis_Et3_pfx->SetMarkerStyle(23);
  h_4_bis_Et3_pfx->SetLineWidth(3);
  h_4_bis_Et3_pfx->Rebin(2);
  h_4_bis_Et3_pfx->SetMarkerColor(kPink);
  h_4_bis_Et3_pfx->SetLineColor(kPink);
  h_4_bis_Et3_pfx->Draw("sames");

  h_4_pm5ns->ProfileX();
  h_4_pm5ns_pfx->SetMarkerStyle(7);
  h_4_pm5ns_pfx->SetLineWidth(3);
  h_4_pm5ns_pfx->Rebin(2);
  h_4_pm5ns_pfx->SetMarkerColor(kRed);
  h_4_pm5ns_pfx->SetLineColor(kRed);
  h_4_pm5ns_pfx->Draw("sames");

  h_4_pm15ns->ProfileX();
  h_4_pm15ns_pfx->SetMarkerStyle(21);
  h_4_pm15ns_pfx->SetLineWidth(3);
  h_4_pm15ns_pfx->Rebin(2);
  h_4_pm15ns_pfx->SetMarkerColor(kRed+2);
  h_4_pm15ns_pfx->SetLineColor(kRed+2);
  h_4_pm15ns_pfx->Draw("sames");

  h_4_OOTp15ns->ProfileX();
  h_4_OOTp15ns_pfx->SetMarkerStyle(21);
  h_4_OOTp15ns_pfx->SetLineWidth(3);
  h_4_OOTp15ns_pfx->Rebin(2);
  h_4_OOTp15ns_pfx->SetMarkerColor(kCyan+2);
  h_4_OOTp15ns_pfx->SetLineColor(kCyan+2);
  h_4_OOTp15ns_pfx->Draw("sames");

  h_4_OOTn15ns->ProfileX();
  h_4_OOTn15ns_pfx->SetMarkerStyle(21);
  h_4_OOTn15ns_pfx->SetLineWidth(3);
  h_4_OOTn15ns_pfx->Rebin(2);
  h_4_OOTn15ns_pfx->SetMarkerColor(kCyan-3);
  h_4_OOTn15ns_pfx->SetLineColor(kCyan-3);
  h_4_OOTn15ns_pfx->Draw("sames");

  h_2->ProfileX();
  h_2_pfx->Rebin(2);
  h_2_pfx->SetMarkerStyle(20);
  h_2_pfx->SetLineWidth(3);
  h_2_pfx->Draw("sames");
  
  l1->AddEntry(h_2_pfx,"kWeird","p");
  l1->AddEntry(h_3_pfx,"APD hit > 50 ADC","p");
  l1->AddEntry(h_4_pfx,"APD hit > 100 ADC","p");
  l1->AddEntry(h_4_bis_pfx,"recHit > 50 ADC","p");
  l1->AddEntry(h_4_bis_E4_pfx,"recHit > 50 ADC (E>4)","p");
  l1->AddEntry(h_4_bis_E10_pfx,"recHit > 50 ADC (E>10)","p");
  l1->AddEntry(h_4_bis_Et3_pfx,"recHit > 50 ADC (Et>3)","p");
  l1->AddEntry(h_4_pm5ns_pfx,"recHit > 50 ADC time in 5ns","p");
  l1->AddEntry(h_4_pm15ns_pfx,"recHit > 50 ADC time in 15ns","p");
  l1->AddEntry(h_4_OOTp15ns_pfx,"recHit > 50 ADC time OOT > +15ns","p");
  l1->AddEntry(h_4_OOTn15ns_pfx,"recHit > 50 ADC time OOT < -15ns","p");
  l1->Draw("same");

  c1->SaveAs("Spikes_PU70_14TeV_dfTuning.pdf");

  TLegend* l1=new TLegend(0.15,0.75,0.42,0.90);
  l1->SetFillColor(0);
  TFile *_file0 = TFile::Open("MinBias_612_8TeV_MBonly_PU2012_BS50_Output.root");

  TCanvas* c2 = new TCanvas();
  h_3->ProfileX();
  h_3_pfx->SetMarkerStyle(25);
  h_3_pfx->SetMarkerColor(kCyan+1);
  h_3_pfx->SetLineColor(kCyan+1);
  h_3_pfx->SetLineWidth(3);
  //  h_3_pfx->GetXaxis()->SetRangeUser(0,50);
  //h_3_pfx->SetMaximum(14);
  h_3_pfx->GetYaxis()->SetTitle("Spikes/event");
  h_3_pfx->Draw();

  h_4->ProfileX();
  h_4_pfx->SetMarkerStyle(25);
  h_4_pfx->SetLineWidth(3);
  h_4_pfx->SetMarkerColor(kYellow+1);
  h_4_pfx->SetLineColor(kYellow+1);
  h_4_pfx->Draw("sames");

  h_4_bis->ProfileX();
  h_4_bis_pfx->SetMarkerStyle(20);
  h_4_bis_pfx->SetLineWidth(3);
  h_4_bis_pfx->Rebin(2);
  h_4_bis_pfx->SetMarkerColor(kRed-7);
  h_4_bis_pfx->SetLineColor(kRed-7);
  h_4_bis_pfx->Draw("sames");

  h_4_bis_E4->ProfileX();
  h_4_bis_E4_pfx->SetMarkerStyle(7);
  h_4_bis_E4_pfx->SetLineWidth(3);
  h_4_bis_E4_pfx->Rebin(2);
  h_4_bis_E4_pfx->SetMarkerColor(kBlue);
  h_4_bis_E4_pfx->SetLineColor(kBlue);
  h_4_bis_E4_pfx->Draw("sames");

  h_4_bis_E10->ProfileX();
  h_4_bis_E10_pfx->SetMarkerStyle(21);
  h_4_bis_E10_pfx->SetLineWidth(3);
  h_4_bis_E10_pfx->Rebin(2);
  h_4_bis_E10_pfx->SetMarkerColor(kGreen+2);
  h_4_bis_E10_pfx->SetLineColor(kGreen+2);
  h_4_bis_E10_pfx->Draw("sames");

  h_4_bis_Et3->ProfileX();
  h_4_bis_Et3_pfx->SetMarkerStyle(23);
  h_4_bis_Et3_pfx->SetLineWidth(3);
  h_4_bis_Et3_pfx->Rebin(2);
  h_4_bis_Et3_pfx->SetMarkerColor(kPink);
  h_4_bis_Et3_pfx->SetLineColor(kPink);
  h_4_bis_Et3_pfx->Draw("sames");

  h_4_pm5ns->ProfileX();
  h_4_pm5ns_pfx->SetMarkerStyle(7);
  h_4_pm5ns_pfx->SetLineWidth(3);
  h_4_pm5ns_pfx->Rebin(2);
  h_4_pm5ns_pfx->SetMarkerColor(kRed);
  h_4_pm5ns_pfx->SetLineColor(kRed);
  h_4_pm5ns_pfx->Draw("sames");

  h_4_pm15ns->ProfileX();
  h_4_pm15ns_pfx->SetMarkerStyle(21);
  h_4_pm15ns_pfx->SetLineWidth(3);
  h_4_pm15ns_pfx->Rebin(2);
  h_4_pm15ns_pfx->SetMarkerColor(kRed+2);
  h_4_pm15ns_pfx->SetLineColor(kRed+2);
  h_4_pm15ns_pfx->Draw("sames");

  h_4_OOTp15ns->ProfileX();
  h_4_OOTp15ns_pfx->SetMarkerStyle(21);
  h_4_OOTp15ns_pfx->SetLineWidth(3);
  h_4_OOTp15ns_pfx->Rebin(2);
  h_4_OOTp15ns_pfx->SetMarkerColor(kCyan+2);
  h_4_OOTp15ns_pfx->SetLineColor(kCyan+2);
  h_4_OOTp15ns_pfx->Draw("sames");

  h_4_OOTn15ns->ProfileX();
  h_4_OOTn15ns_pfx->SetMarkerStyle(21);
  h_4_OOTn15ns_pfx->SetLineWidth(3);
  h_4_OOTn15ns_pfx->Rebin(2);
  h_4_OOTn15ns_pfx->SetMarkerColor(kCyan-3);
  h_4_OOTn15ns_pfx->SetLineColor(kCyan-3);
  h_4_OOTn15ns_pfx->Draw("sames");

  h_2->ProfileX();
  h_2_pfx->SetMarkerStyle(20);
  h_2_pfx->SetLineWidth(3);
  h_2_pfx->Draw("sames");
  
  l1->AddEntry(h_2_pfx,"kWeird","p");
  l1->AddEntry(h_3_pfx,"APD hit > 50 ADC","p");
  l1->AddEntry(h_4_pfx,"APD hit > 100 ADC","p");
  l1->AddEntry(h_4_bis_pfx,"recHit > 50 ADC","p");
  l1->AddEntry(h_4_bis_E4_pfx,"recHit > 50 ADC (E>4)","p");
  l1->AddEntry(h_4_bis_E10_pfx,"recHit > 50 ADC (E>10)","p");
  l1->AddEntry(h_4_bis_Et3_pfx,"recHit > 50 ADC (Et>3)","p");
  l1->AddEntry(h_4_pm5ns_pfx,"recHit > 50 ADC time in 5ns","p");
  l1->AddEntry(h_4_pm15ns_pfx,"recHit > 50 ADC time in 15ns","p");
  l1->AddEntry(h_4_OOTp15ns_pfx,"recHit > 50 ADC time OOT > +15ns","p");
  l1->AddEntry(h_4_OOTn15ns_pfx,"recHit > 50 ADC time OOT < -15ns","p");
  l1->Draw("same");

  c2->SaveAs("Spikes_MB_PU2012_8TeV_dfTuning.pdf");

  TLegend* l1=new TLegend(0.15,0.75,0.42,0.90);
  l1->SetFillColor(0);
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_BS50_Output.root");

  TCanvas* c3 = new TCanvas();
  h_3->ProfileX();
  h_3_pfx->SetMarkerStyle(25);
  h_3_pfx->SetMarkerColor(kCyan+1);
  h_3_pfx->SetLineColor(kCyan+1);
  h_3_pfx->SetLineWidth(3);
  //  h_3_pfx->GetXaxis()->SetRangeUser(0,50);
  //h_3_pfx->SetMaximum(14);
  h_3_pfx->GetYaxis()->SetTitle("Spikes/event");
  h_3_pfx->Draw();

  h_4->ProfileX();
  h_4_pfx->SetMarkerStyle(25);
  h_4_pfx->SetLineWidth(3);
  h_4_pfx->SetMarkerColor(kYellow+1);
  h_4_pfx->SetLineColor(kYellow+1);
  h_4_pfx->Draw("sames");

  h_4_bis->ProfileX();
  h_4_bis_pfx->SetMarkerStyle(20);
  h_4_bis_pfx->SetLineWidth(3);
  h_4_bis_pfx->Rebin(2);
  h_4_bis_pfx->SetMarkerColor(kRed-7);
  h_4_bis_pfx->SetLineColor(kRed-7);
  h_4_bis_pfx->Draw("sames");

  h_4_bis_E4->ProfileX();
  h_4_bis_E4_pfx->SetMarkerStyle(7);
  h_4_bis_E4_pfx->SetLineWidth(3);
  h_4_bis_E4_pfx->Rebin(2);
  h_4_bis_E4_pfx->SetMarkerColor(kBlue);
  h_4_bis_E4_pfx->SetLineColor(kBlue);
  h_4_bis_E4_pfx->Draw("sames");

  h_4_bis_E10->ProfileX();
  h_4_bis_E10_pfx->SetMarkerStyle(21);
  h_4_bis_E10_pfx->SetLineWidth(3);
  h_4_bis_E10_pfx->Rebin(2);
  h_4_bis_E10_pfx->SetMarkerColor(kGreen+2);
  h_4_bis_E10_pfx->SetLineColor(kGreen+2);
  h_4_bis_E10_pfx->Draw("sames");

  h_4_bis_Et3->ProfileX();
  h_4_bis_Et3_pfx->SetMarkerStyle(23);
  h_4_bis_Et3_pfx->SetLineWidth(3);
  h_4_bis_Et3_pfx->Rebin(2);
  h_4_bis_Et3_pfx->SetMarkerColor(kPink);
  h_4_bis_Et3_pfx->SetLineColor(kPink);
  h_4_bis_Et3_pfx->Draw("sames");

  h_4_pm5ns->ProfileX();
  h_4_pm5ns_pfx->SetMarkerStyle(7);
  h_4_pm5ns_pfx->SetLineWidth(3);
  h_4_pm5ns_pfx->Rebin(2);
  h_4_pm5ns_pfx->SetMarkerColor(kRed);
  h_4_pm5ns_pfx->SetLineColor(kRed);
  h_4_pm5ns_pfx->Draw("sames");

  h_4_pm15ns->ProfileX();
  h_4_pm15ns_pfx->SetMarkerStyle(21);
  h_4_pm15ns_pfx->SetLineWidth(3);
  h_4_pm15ns_pfx->Rebin(2);
  h_4_pm15ns_pfx->SetMarkerColor(kRed+2);
  h_4_pm15ns_pfx->SetLineColor(kRed+2);
  h_4_pm15ns_pfx->Draw("sames");

  h_4_OOTp15ns->ProfileX();
  h_4_OOTp15ns_pfx->SetMarkerStyle(21);
  h_4_OOTp15ns_pfx->SetLineWidth(3);
  h_4_OOTp15ns_pfx->Rebin(2);
  h_4_OOTp15ns_pfx->SetMarkerColor(kCyan+2);
  h_4_OOTp15ns_pfx->SetLineColor(kCyan+2);
  h_4_OOTp15ns_pfx->Draw("sames");

  h_4_OOTn15ns->ProfileX();
  h_4_OOTn15ns_pfx->SetMarkerStyle(21);
  h_4_OOTn15ns_pfx->SetLineWidth(3);
  h_4_OOTn15ns_pfx->Rebin(2);
  h_4_OOTn15ns_pfx->SetMarkerColor(kCyan-3);
  h_4_OOTn15ns_pfx->SetLineColor(kCyan-3);
  h_4_OOTn15ns_pfx->Draw("sames");

  h_2->ProfileX();
  h_2_pfx->SetMarkerStyle(20);
  h_2_pfx->SetLineWidth(3);
  h_2_pfx->Draw("sames");
  
  l1->AddEntry(h_2_pfx,"kWeird","p");
  l1->AddEntry(h_3_pfx,"APD hit > 50 ADC","p");
  l1->AddEntry(h_4_pfx,"APD hit > 100 ADC","p");
  l1->AddEntry(h_4_bis_pfx,"recHit > 50 ADC","p");
  l1->AddEntry(h_4_bis_E4_pfx,"recHit > 50 ADC (E>4)","p");
  l1->AddEntry(h_4_bis_E10_pfx,"recHit > 50 ADC (E>10)","p");
  l1->AddEntry(h_4_bis_Et3_pfx,"recHit > 50 ADC (Et>3)","p");
  l1->AddEntry(h_4_pm5ns_pfx,"recHit > 50 ADC time in 5ns","p");
  l1->AddEntry(h_4_pm15ns_pfx,"recHit > 50 ADC time in 15ns","p");
  l1->AddEntry(h_4_OOTp15ns_pfx,"recHit > 50 ADC time OOT > +15ns","p");
  l1->AddEntry(h_4_OOTn15ns_pfx,"recHit > 50 ADC time OOT < -15ns","p");
  l1->Draw();

  c3->SaveAs("Spikes_MB_PU70_BS50_14TeV_dfTuning.pdf");





}
