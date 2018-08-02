#ifndef LINESENSOR_H
#define LINESENSOR_H

#include "API.h"
class lineSensor{
private:
  int value;
  int lineSensorPort;
public:
  lineSensor();

  void set_lineSensor(int port);
  int get_lineSensor();
  void updateValues();
  int getValue();

};
#endif
