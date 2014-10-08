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
    ##### default tuning and extended pile up at 14TeV ############
    ###############################################################


'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_101_1_kZ1.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_108_1_36Z.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_113_1_stn.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_114_1_sCd.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_116_1_Kkb.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_120_1_56w.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_122_1_Bw0.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_125_1_tcW.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_126_1_H8s.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_127_1_YtO.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_129_1_Woh.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_12_1_Xe2.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_132_1_PHg.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_134_1_fq1.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_138_1_Nvv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_13_1_RiN.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_143_1_ext.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_144_1_ssk.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_145_1_6A0.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_146_1_7ta.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_147_1_QbZ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_148_1_pb4.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_14_1_MGI.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_154_1_4Jt.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_155_1_XNV.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_156_1_79V.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_158_1_hGS.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_159_1_8yq.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_23_1_Eq8.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_240_1_leH.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_241_1_Xu5.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_242_1_98R.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_244_1_34O.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_246_1_0cl.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_247_1_z9Q.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_248_1_Ull.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_249_1_U0u.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_24_1_xEA.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_250_1_j5c.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_251_1_El1.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_252_1_axD.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_254_1_BMI.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_256_1_1vP.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_258_1_cNY.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_259_1_fki.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_25_1_UAe.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_261_1_0Mo.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_265_1_7yg.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_267_1_duw.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_26_1_jZD.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_273_1_1jv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_274_1_5ML.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_276_1_lAc.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_277_1_Ke5.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_279_1_3Mk.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_27_1_p1y.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_283_1_SQp.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_286_1_l5O.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_287_1_pwl.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_288_1_x4u.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_289_1_pGm.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_28_1_jYo.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_290_1_ziX.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_291_1_GrZ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_292_1_3gT.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_293_1_Uek.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_294_1_hfv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_296_1_G7a.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_298_1_IN8.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_300_1_K3c.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_301_1_x8w.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_302_1_D0A.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_303_1_U2h.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_304_1_QTX.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_305_1_e0k.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_307_1_lFN.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_308_1_0Wi.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_309_1_6lS.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_310_1_8Xs.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_316_1_YKI.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_318_1_r6E.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_319_1_k1T.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_322_1_0pv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_323_1_UgP.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_325_1_od8.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_328_1_gqS.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_332_1_msJ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_336_1_IRm.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_338_1_SDx.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_342_1_b6g.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_343_1_WDm.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_345_1_pUt.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_347_1_PL0.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_348_1_BWZ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_349_1_ZIw.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_350_1_iIf.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_428_1_ctw.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_429_1_ksY.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_435_1_kpP.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_438_1_ahJ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_439_1_o8P.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_440_1_smc.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_441_1_fgz.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_444_1_RT7.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_44_1_kFH.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_453_1_UwE.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_455_1_b73.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_459_1_JzL.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_45_1_S93.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_467_1_Wld.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_470_1_8Sk.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_471_1_6Ml.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_473_1_Q98.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_474_1_EDV.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_478_1_Dxt.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_479_1_ALU.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_47_1_eQL.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_482_1_hGE.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_483_1_GU3.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_484_1_5m4.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_494_1_Jv1.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_495_1_xpm.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_498_1_9wN.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_499_1_7N8.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_52_1_X25.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_53_1_ZP2.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_57_1_nPV.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_58_1_rr2.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_5_1_rfK.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_61_1_Dj8.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_63_1_eGw.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_64_1_QK5.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_68_1_jJC.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_69_1_ChQ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_6_1_rgf.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_71_1_mjA.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_75_1_cIv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_76_1_3dJ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_77_1_bgv.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_79_1_hqX.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_81_1_LQB.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_83_1_YSK.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_85_1_HgP.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_87_1_Qzt.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_88_1_QOq.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_89_1_cRJ.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_90_1_nqo.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_92_1_7Qn.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_95_1_7XL.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_99_1_SNX.root',
'/store/caf/user/amartell/Upgrade/SpikeStudies/MBOnly_14TeV_PU70_BS50_TL300_IL1E34_STAR17_61_V6A_bis16Jul/MinimumBias_PU70-14TeV_effective_TL300_IL1E34_STAR17_61_V6A_9_1_Fke.root'
]);

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
fileName = cms.string(
    "file:/afs/cern.ch/work/a/amartell/Upgrade/SpikesStudies/CMSSW_6_1_2_SLHC4/src/DPGTask/SpikeStudy/test/MinBias_PU70_BS50_14TeV.root"
    ),
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
