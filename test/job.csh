#!/bin/tcsh
cd /afs/cern.ch/user/s/sandhya/scratch0/CMSSW_6_1_2/src/DPGTask/SpikeStudy/test
setenv SCRAM_ARCH slc5_amd64_gcc462
cmsenv
cd -
cmsRun /afs/cern.ch/user/s/sandhya/scratch0/CMSSW_6_1_2/src/DPGTask/SpikeStudy/test/treemaker_MC_8TeV_dfTuning_cfg.py
