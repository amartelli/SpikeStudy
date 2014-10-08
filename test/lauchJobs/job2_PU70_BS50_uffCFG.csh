#!/bin/tcsh
cd /afs/cern.ch/work/a/amartell/Upgrade/SpikesStudies/CMSSW_6_1_2_SLHC4/src/DPGTask/SpikeStudy/test/
setenv SCRAM_ARCH slc5_amd64_gcc462
cmsenv
cd -
cmsRun /afs/cern.ch/work/a/amartell/Upgrade/SpikesStudies/CMSSW_6_1_2_SLHC4/src/DPGTask/SpikeStudy/test/treemaker_MC_14TeV_dfTuning_cfg.py
