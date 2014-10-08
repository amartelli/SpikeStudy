TH1F* myRebin(TH1F* in, TString name) {
  // input is 1 GeV per bin from -10 to 100
  // output is variable binning

  double xbins[14] = {4, 5, 6, 7, 8, 9, 10, 12, 15, 20, 30, 50, 100, 150};

  TH1F* output = new TH1F(name, "", 13, xbins);
  output->Sumw2();

  for(int iBin = 0; iBin != 14; ++iBin) {
    int lowEdge = in->FindBin(-10 - 1);
    int highEdge = in->FindBin(xbins[0]);
    if ( iBin != 0 ) {
      lowEdge = in->FindBin(xbins[iBin-1]);
      highEdge = in->FindBin(xbins[iBin]);
    }
    float sum = 0;
    float err2 = 0;
    
    cout << iBin << '\t' << lowEdge << '\t' << highEdge << endl;

    for(int i = lowEdge; i <= highEdge; i++) {
      sum += in->GetBinContent(i);
      err2 += in->GetBinError(i)*in->GetBinError(i);
      cout<<sum<<endl;
    }
    cout << iBin << '\t' << lowEdge << '\t' << highEdge << "\t sum:"<< sum << endl;
    output->SetBinContent(iBin, sum);
    output->SetBinError(iBin, TMath::Sqrt(sum));
    //output->SetBinError(iBin, TMath::Sqrt(err2));
  }
  //cout << "After rebinning: " << in->Integral() << endl;
  return output;
}

void makePlots_energy(){

  gStyle->SetOptStat(0);
  gStyle->SetLegendBorderSize(0); 
  TLegend* l1=new TLegend(0.6,0.7,0.85,0.85);
  l1->SetFillColor(0);
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_Output.root");

  TCanvas* c1 = new TCanvas();
  h_rechit_energy_all->SetLineColor(1);
  h_rechit_energy_all->SetLineWidth(2);
  h_rechit_energy_all->GetXaxis()->SetRangeUser(0, 50.);
  h_rechit_energy_all->Draw("HIST");
  h_rechit_energy_kWeird->SetLineColor(2);
  h_rechit_energy_kWeird->SetLineWidth(2);
  h_rechit_energy_kWeird->Draw("HISTsames");
  h_rechit_energy_swissCross->SetLineColor(3);
  h_rechit_energy_swissCross->SetLineWidth(2);
  h_rechit_energy_swissCross->Draw("HISTsames");
  h_rechit_spike_energy_50->SetLineColor(4);
  h_rechit_spike_energy_50->SetLineWidth(2);
  h_rechit_spike_energy_50->Draw("HISTsames");
  
  l1->AddEntry(h_rechit_energy_all,"All","l");
  l1->AddEntry(h_rechit_energy_kWeird,"Spikes - kW","l");
  l1->AddEntry(h_rechit_energy_swissCross,"Spikes - swissCross","l");
  l1->AddEntry(h_rechit_spike_energy_50,"Spikes - truth ","l");
  c1->SetLogy();
  l1->Draw();
  c1->SaveAs("Rechit_energy_MB_PU70_14TeV_dfTuning.pdf");
 
  
  TLegend* l1=new TLegend(0.6,0.7,0.85,0.85);
  l1->SetFillColor(0);
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_PU70_Output.root");
  TCanvas* c2 = new TCanvas();
  h_rechit_energy_all->SetLineColor(1);
  h_rechit_energy_all->SetLineWidth(2);
  h_rechit_energy_all->GetXaxis()->SetRangeUser(0, 50.);
  h_rechit_energy_all->Draw("HIST");
  h_rechit_energy_kWeird->SetLineColor(2);
  h_rechit_energy_kWeird->SetLineWidth(2);
  h_rechit_energy_kWeird->Draw("HISTsames");
  h_rechit_energy_swissCross->SetLineColor(3);
  h_rechit_energy_swissCross->SetLineWidth(2);
  h_rechit_energy_swissCross->Draw("HISTsames");
  h_rechit_spike_energy_50->SetLineColor(4);
  h_rechit_spike_energy_50->SetLineWidth(2);
  h_rechit_spike_energy_50->Draw("HISTsames");
  
  l1->AddEntry(h_rechit_energy_all,"All","l");
  l1->AddEntry(h_rechit_energy_kWeird,"Spikes - kW","l");
  l1->AddEntry(h_rechit_energy_swissCross,"Spikes - swissCross","l");
  l1->AddEntry(h_rechit_spike_energy_50,"Spikes - truth ","l");
  c2->SetLogy();
  l1->Draw();
  
  c2->SaveAs("Rechit_energy_MB_PU70_14TeV_dfTuning.pdf");

  
  TLegend* l1=new TLegend(0.6,0.7,0.85,0.85);
  l1->SetFillColor(0);
  TFile *_file0 = TFile::Open("MinBias_612_14TeV_MBonly_noPU_Output.root");
  TCanvas* c3 = new TCanvas();
  h_rechit_energy_all->SetLineColor(1);
  h_rechit_energy_all->SetLineWidth(2);
  h_rechit_energy_all->GetXaxis()->SetRangeUser(0, 50.);
  h_rechit_energy_all->Draw("HIST");
  h_rechit_energy_kWeird->SetLineColor(2);
  h_rechit_energy_kWeird->SetLineWidth(2);
  h_rechit_energy_kWeird->Draw("HISTsames");
  h_rechit_energy_swissCross->SetLineColor(3);
  h_rechit_energy_swissCross->SetLineWidth(2);
  h_rechit_energy_swissCross->Draw("HISTsames");
  h_rechit_spike_energy_50->SetLineColor(4);
  h_rechit_spike_energy_50->SetLineWidth(2);
  h_rechit_spike_energy_50->Draw("HISTsames");
  
  l1->AddEntry(h_rechit_energy_all,"All","l");
  l1->AddEntry(h_rechit_energy_kWeird,"Spikes - kW","l");
  l1->AddEntry(h_rechit_energy_swissCross,"Spikes - swissCross","l");
  l1->AddEntry(h_rechit_spike_energy_50,"Spikes - truth ","l");
  c3->SetLogy();
  l1->Draw();
  
  c3->SaveAs("Rechit_energy_MB_noPU_14TeV_dfTuning.pdf");

}
