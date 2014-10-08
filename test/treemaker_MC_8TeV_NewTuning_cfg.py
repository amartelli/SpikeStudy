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
process.load("SimCalorimetry.EcalTrigPrimProducers.ecalTriggerPrimitiveDigis_cff")
process.load("FWCore.MessageLogger.MessageLogger_cfi")

## global tag for data
process.GlobalTag.globaltag = cms.string('START61_V11::All')
process.uncleanSCRecovered.cleanScCollection = cms.InputTag("correctedHybridSuperClusters")
process.addUncleanInfo= cms.Sequence(process.uncleanSCRecovered)

# Add the files 
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring()
readFiles.extend( [
    ###############################################################
    ##### new tuning and extended pile up at 8TeV  ################
    ###############################################################
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_0.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_1.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_10.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_11.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_12.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_13.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_15.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_16.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_17.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_18.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_19.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_2.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_20.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_21.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_22.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_23.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_24.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_25.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_26.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_27.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_28.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_29.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_3.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_30.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_31.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_32.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_33.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_34.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_35.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_36.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_37.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_38.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_4.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_40.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_41.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_42.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_43.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_44.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_45.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_46.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_47.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_48.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_49.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_5.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_50.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_51.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_52.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_53.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_54.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_55.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_56.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_57.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_58.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_6.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_7.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_8.root',
    'root://eoscms//eos/cms/store/caf/user/sandhya/Spikes/ValidateMC/NewTuning/MinBias_8TeV_Effective_withPileUp_run2012C_9.root',
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
                              fillpileUpInfo_      = cms.untracked.bool(True),
                              pileUpLabel_         = cms.untracked.InputTag("addPileupInfo")
                              )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_612_8TeV_sandhya_check.root"),
                                   closeFileFast = cms.untracked.bool(True)
                                   )

#All paths are here
process.p = cms.Path(
    process.simEcalTriggerPrimitiveDigis*
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
