#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "API.h"
class potentiometer{
private:
  int value;
  int potentiometerPort;
public:
  potentiometer();
  void set_Potentiometer(int port);
  int get_Potentiometer();
  void updateValues();
  int getValue();
  void reset();
};
#endif
