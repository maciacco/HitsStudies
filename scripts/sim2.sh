#! /usr/bin/bash -xe

if [[ -z $MCSTEPLOGGER_ROOT ]] ; then
    echo "Please load the MCStepper module before running this script: alienv enter O2/latest,MCStepLogger/latest"
    exit 1
fi

MC_STEPPER_PREFIX=$MCSTEPLOGGER_ROOT/lib/libMCStepLoggerInterceptSteps.so

#BOXGEN="-g boxgen --configKeyValues=BoxGun.eta[0]=-0.1;BoxGun.eta[1]=0.1;BoxGun.phirange[0]=45.0;BoxGun.phirange[1]=45.0;BoxGun.prange[0]=20;BoxGun.prange[1]=21.0i;BoxGun.pdg=13;BoxGun.number=1;"

#BOXGEN="-g boxgen --configKeyValues=BoxGun.eta[0]=-3.;BoxGun.eta[1]=3.;BoxGun.phirange[0]=0.0;BoxGun.phirange[1]=360.0;BoxGun.prange[0]=10.0;BoxGun.prange[1]=10.;BoxGun.pdg=13;BoxGun.number=1;"
BOXGEN="-g boxgen --configKeyValues=BoxGun.eta[0]=-0.1;BoxGun.eta[1]=.0;BoxGun.phirange[0]=18.816523;BoxGun.phirange[1]=19.389481;BoxGun.prange[0]=100.0;BoxGun.prange[1]=100.1;BoxGun.pdg=13;BoxGun.number=1;"
#BOXGEN="-g pythia8hi --configKeyValues="
PARALLEL_WORLD=";GeometryManagerParam.useParallelWorld=$1;GeometryManagerParam.addSensorToPW=$2;GeometryManagerParam.addMetalToPW=$3;GeometryManagerParam.addChipToPW=$4"
NEVENTS=1

MCSTEPLOG_TTREE=1 LD_PRELOAD=${MC_STEPPER_PREFIX} o2-sim-serial --seed 42 -m PIPE ITS -n $NEVENTS ${BOXGEN}${PARALLEL_WORLD} --run 526641 > sim$1.log # 2>&1 | tee sim$1.log #-j 10 # 2>&1 | tee sim$1.log #| tee sim$1.log 2>&1 #| tee sim$1.log 2>&1 # | tee sim$1.log 2>&1 # -e TGeant4 | tee sim$1.log 2>&1 #300000 # | tee sim$1.log #-e TGeant4 2>&1
