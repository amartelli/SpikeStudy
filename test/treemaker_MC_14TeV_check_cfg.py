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
#process.GlobalTag.globaltag = cms.string('START61_V11::All')
process.GlobalTag.globaltag = cms.string('STAR17_61_V6A::All')
process.uncleanSCRecovered.cleanScCollection = cms.InputTag("correctedHybridSuperClusters")
process.addUncleanInfo= cms.Sequence(process.uncleanSCRecovered)

# Add the files 
readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring()
readFiles.extend( [

    ###############################################################
    ##### default tuning and No pile up at 14TeV ############
    ###############################################################
    
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_100_1_jy0.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_101_1_03i.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_102_1_aFR.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_103_1_sKj.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_104_1_tCY.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_105_1_TSM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_106_1_CFL.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_107_1_ZcM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_108_1_mXh.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_109_1_bAH.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_10_1_7f5.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_110_1_09l.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_111_1_gyJ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_112_1_vSu.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_113_1_Ynx.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_114_1_px8.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_115_1_K5C.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_116_1_pNY.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_117_1_w8s.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_118_1_6vZ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_119_1_5HA.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_11_1_adb.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_120_1_qsk.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_121_1_Vvm.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_122_1_IdN.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_123_1_FCQ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_124_1_bQN.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_125_1_N4u.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_126_1_6dS.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_127_1_IRT.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_128_1_R9o.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_129_1_Ovw.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_12_1_kmD.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_130_1_9k5.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_131_1_EJw.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_132_1_vKW.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_133_1_K5t.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_134_1_Osz.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_135_1_aM1.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_136_1_6c3.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_137_1_CDn.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_138_1_jTM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_139_1_X2h.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_13_1_AJp.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_140_1_LwL.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_141_1_oRc.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_142_1_Tht.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_143_1_QMF.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_144_1_jJx.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_145_1_7OQ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_146_1_QLw.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_147_1_HSw.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_148_1_S1u.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_149_1_wvF.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_14_1_EFs.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_150_1_2bK.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_151_1_dS1.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_152_1_Uy7.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_153_1_rPB.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_154_1_yvq.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_155_1_mFx.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_156_1_scD.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_157_1_bVM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_158_1_pZ9.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_159_1_FDs.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_15_1_Elm.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_160_1_1Av.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_161_1_q26.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_162_1_3id.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_163_1_ZbV.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_164_1_B4p.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_165_1_lCN.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_166_1_H6z.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_167_1_BKl.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_168_1_Hzz.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_169_1_cTB.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_16_1_N5Q.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_170_1_mwH.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_171_1_XmI.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_172_1_SMc.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_173_1_3nT.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_174_1_OXU.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_175_1_Aox.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_176_1_QXA.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_177_1_BEX.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_178_1_KeN.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_179_1_nZf.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_17_1_3N4.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_180_1_XmA.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_181_1_ffP.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_182_1_m6k.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_183_1_9WM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_184_1_CMU.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_185_1_x5h.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_186_1_dyl.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_187_1_lQg.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_188_1_JhD.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_189_1_Ra4.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_18_1_Egu.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_190_1_ISd.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_191_1_qDd.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_192_1_lDT.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_193_1_Beu.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_194_1_Uai.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_195_1_ZR5.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_196_1_vJM.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_197_1_aoP.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_198_1_nn0.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_199_1_iP2.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_19_1_zqW.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_1_1_SvJ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_200_1_LBr.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_20_1_oha.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_21_1_cIB.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_22_1_Eec.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_23_1_iLz.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_24_1_oSy.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_25_1_emR.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_26_1_v9r.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_27_1_rZZ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_28_1_ilg.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_29_1_THO.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_2_1_lk5.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_30_1_ivh.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_31_1_B8f.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_32_1_9Ib.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_33_1_IwQ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_34_1_oA9.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_35_1_W3V.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_36_1_2bI.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_37_1_zlu.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_38_1_yg1.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_39_1_etE.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_3_1_iUN.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_40_1_fxZ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_41_1_jN8.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_42_1_P2R.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_43_1_h7M.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_44_1_9M6.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_45_1_ZNc.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_46_1_oh7.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_47_1_xwp.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_48_1_2kV.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_49_1_uCK.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_4_1_1cG.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_50_1_Art.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_51_1_PEc.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_52_1_azO.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_53_1_tAi.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_54_1_hJY.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_55_1_4VE.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_56_1_rxQ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_57_1_Ifj.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_58_1_8wU.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_59_1_8qH.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_5_1_Zqt.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_60_1_r6t.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_61_1_CuK.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_62_1_inJ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_63_1_jYO.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_64_1_o1M.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_65_1_H2F.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_66_1_Nab.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_67_1_j2X.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_68_1_148.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_69_1_IMP.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_6_1_7X5.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_70_1_DLf.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_71_1_eFA.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_72_1_hYK.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_73_1_EOa.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_74_1_BZB.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_75_1_UwK.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_76_1_P5W.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_77_1_2BH.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_78_1_Vp1.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_79_1_UfV.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_7_1_5S7.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_80_1_2zb.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_81_1_QLT.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_82_1_LMb.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_83_1_5Vy.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_84_1_vbe.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_85_1_k0z.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_86_1_PMg.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_87_1_IvS.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_88_1_Za1.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_89_1_WIg.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_8_1_eXm.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_90_1_C7m.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_91_1_H2z.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_92_1_v6G.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_93_1_K2Z.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_94_1_3Ze.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_95_1_aEt.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_96_1_qMr.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_97_1_5UZ.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_98_1_Yvz.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_99_1_o3b.root',
 'root://eoscms//eos/cms/store/caf/user/amartell/Upgrade/SpikeStudies/ZeroBias_14TeV_NOPU_TL300_IL1E34_STAR17_61_V6A//ZeroBias_NUgun_pT2-20_NOPU-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_9_1_9fW.root',


#######MinBias Mixed with MB############

#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_122_1_Wnq.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_124_1_CZP.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_12_1_ATB.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_134_1_zbt.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_138_1_44C.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_146_1_0qe.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_172_1_qkE.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_194_1_SIy.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_21_1_aNr.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_3_1_ZsQ.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_43_1_BeP.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_56_1_ICG.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_83_1_MAz.root',
#'root://eoscms//eos/cms//store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_TL300_IL1E34_STAR17_61_V6A/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_9_1_gbi.root',
    
    ] );

process.source = cms.Source("PoolSource",
                            fileNames = readFiles,
                            # skipEvents=cms.untracked.uint32(115)
                            duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
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
                              #rechitBLabel_       = cms.untracked.InputTag("reducedEcalRecHitsEB"),
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
                                   #fileName = cms.string("/afs/cern.ch/work/s/sandhya/public/Files/MinBias_612_14TeV_check.root"),
                                   fileName = cms.string("MinBias_612_14TeV_check.root"),
                                   closeFileFast = cms.untracked.bool(True)
                                   )

#All paths are here
process.p = cms.Path(
    process.simEcalTriggerPrimitiveDigis*
    process.addUncleanInfo*
    #process.content*
    process.demo
    )

# reduce verbosity
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)

# process all the events
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))

process.schedule=cms.Schedule(process.p)

#print process.dumpPython()
