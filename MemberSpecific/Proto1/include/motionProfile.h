#ifndef MOTIONPROFILE_H
#define MOTIONPROFILE_H
#include <API.h>
#include "main.h"

class motionProfile{
private:
  int targetVel;
  int tAccel; //milliseconds
  int totalTime;
public:
  motionProfile();
};
#endif
