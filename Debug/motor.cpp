#include <cstdlib>
#include <cstdio>

#include "motor.h"
#include "serialize.h"
#include "transferclient.h"

#define NUMMOTORS 8

motor::motor(): tco(),so((int)NUMMOTORS){//(transferclient a,serialize b){
  this->targetrpms = (int*) malloc(NUMMOTORS*sizeof(int));
  this->currentrpms = (int*) malloc(NUMMOTORS*sizeof(int));
  initialize();
  printf("Motor: RPM Arrays Initialized\n");
  test();
}

void motor::initialize(){
  for(int i = 0;i < NUMMOTORS;i++){
    targetrpms[i]=0;
    currentrpms[i]=0;
  }
}

void motor::setTargetRPM(int mID,int val){
  targetrpms[mID]=val;
}

int motor::getTargetRPM(int mID){
  //updatecurrentrpms;
  return currentrpms[mID];
}

void motor::test(){
  printf("\nMotor class functional\n");
  tco.test();
  so.test();
}

motor::~motor(){
  printf("Motor: Shutting Down...\n");
  free(targetrpms);
  free(currentrpms);
  printf("Motor: Integer Arrays freed.");
}
