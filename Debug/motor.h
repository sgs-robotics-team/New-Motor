#include "serialize.h"
#include "transferclient.h"

#ifndef MOTOR_H
#define MOTOR_H

class motor{

public:
  //setTargetRPM
  motor();
  ~motor();

  void initialize();//initializes arrays targetrpms and

  void setTargetRPM(int mID,int val);//sets target RPM of motor with ID in param
  void setTargetRPM(int val);//sets target RPM of all motors

  int getCurrentRPM(int mID);//returns current RPM of motor with ID in param
  int* getCurrentRPM();//returns current RPM array of all motors

  int getTargetRPM(int mID);//returns target RPM of motor with ID in param
  int* getTargetRPM();//returns target RPM array of all motors

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
