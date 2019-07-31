#include "serialize.h"
#include "transferclient.h"

#ifndef MOTOR_H
#define MOTOR_H

class motor{

public:
  //setTargetRPM
  motor();
  ~motor();

  void initialize();

  int setTargetRPM(int mID,int val);
  int* setTargetRPM(int val);

  int getTargetRPM(int mID);
  int* getTargetRPM();

  int updateCurrentRPMs();//recv from python thread
  int updateTargetRPMs();//send to python thread

  void test();

private:

  int* targetrpms;
  int* currentrpms;

  transferclient tco;
  serialize so;
};

#endif
