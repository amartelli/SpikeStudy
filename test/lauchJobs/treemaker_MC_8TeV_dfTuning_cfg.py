import FWCore.ParameterSet.Config as cms

process = cms.Process("Spiketuple")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("RecoEgamma.EgammaPhotonProducers.photonSequence_cff")
process.load('RecoEcal.Configuration.RecoEcal_cff')
process.load("RecoEcal.EgammaClusterProducers.uncleanSCRecovery_cfi")
process.load("Configuration.StandardSequences.Reconstruction_cff")
from Configuration.StandardSequences.Reconstruction_cff import *
from RecoEcal.Configuration.RecoEcal_cff import *
from RecoEcal.EgammaClusterProducers.hybridSuperClusters_cfi import *

process.load("FWCore.MessageLogger.MessageLogger_cfi")

## global tag for data
process.GlobalTag.globaltag = cms.string('START61_V11::All')
process.uncleanSCRecovered.cleanScCollection = cms.InputTag("correctedHybridSuperClusters")
process.addUncleanInfo= cms.Sequence(process.uncleanSCRecovered)

# Add the files 
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring()
readFiles.extend( [
    #  arabella's two files thats she produced
    # 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/reDIGI/SpikeStudies/MinBias_8TeV_BS8TeV_standard_1.root'
    # 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/reDIGI/SpikeStudies/MinBias_8TeV_BS8TeV_standard_2.root'
    # for standard approach with check_effective_cfg.py
    # 'file:/afs/cern.ch/user/s/sandhya/scratch0/CMSSW_6_1_2/src/SimCalorimetry/EcalSimProducers/test/test/DYToLLM50_standard_sc1.root'
    # for effective  approach with pile up ( MinBias_8TeV_Effective_withPileUp_run2012C.py)
    # 'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C.root'
    # 'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective.root'
    # 'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Standard.root'

    ##############################################################
    ##### default tuning and default OOT pile up at 8TeV ########
    ##############################################################
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_0.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_1.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_2.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_3.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_4.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_5.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_6.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_7.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_8.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_9.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_10.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_11.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_12.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_13.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_14.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_15.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_16.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_17.root',
    #'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/MinBias_8TeV_Effective_withPileUp_run2012C_18.root'

    ###############################################################
    ##### default tuning and extended pile up 8TeV ################
    ###############################################################
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_1.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_10.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_11.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_12.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_13.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_2.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_3.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_4.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_5.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_6.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_7.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_8.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_a_9.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_1.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_10.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_11.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_12.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_13.root',
    #'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_2.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_3.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_4.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_5.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_6.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_7.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_8.root',
    'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MinBias_TuneZ2star_8TeV-pythia6_Summer12-START50_V13-v3_REDIGI/MinBias_8TeV_BS8TeV_effective_2012RunC_b_9.root',
    ] );

process.source = cms.Source("PoolSource",
                            fileNames = readFiles,
#                            skipEvents=cms.untracked.uint32(115)
)

#closes files after code is done running on that file
process.options = cms.untracked.PSet(
	fileMode = cms.untracked.string('NOMERGE')
)

##---input to analyzer
process.content = cms.EDAnalyzer("EventContentAnalyzer")
process.demo = cms.EDAnalyzer('SpikeStudy',
                              debug_               = cms.untracked.bool(False),
                              fillrechitInfo_      = cms.untracked.bool(True),
                              #rechitBLabel_        = cms.untracked.InputTag("reducedEcalRecHitsEB"),
                              rechitBLabel_        = cms.untracked.InputTag("ecalRecHit","EcalRecHitsEB"),
                              fillsuperClusterInfo_= cms.untracked.bool(True),
                              superClusterLabel_   = cms.untracked.InputTag("uncleanSCRecovered","uncleanHybridSuperClusters"),
                              filleventInfo_       = cms.untracked.bool(False),
                              lumiLabel_           = cms.untracked.InputTag("conditionsInEdm"),
                              lumiProducerLabel_   = cms.untracked.InputTag("lumiProducer"),
                              fillvertexInfo_      = cms.untracked.bool(True),
                              vertexLabel_         = cms.untracked.InputTag("offlinePrimaryVertices","",""),
                              filltrackInfo_       = cms.untracked.bool(True),
                              trackLabel_          = cms.untracked.InputTag("generalTracks"),
                              )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_PU_8TeV_defTuning.root"),
                                   #MinBias_612_8TeV_arabella_check.root"),
                                   closeFileFast = cms.untracked.bool(True)
                                   )

#All paths are here
process.p = cms.Path(
    process.addUncleanInfo*
    #process.content
    process.demo
    )

# reduce verbosity
#process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)

# process all the events
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))

process.schedule=cms.Schedule(process.p)

#print process.dumpPython()
