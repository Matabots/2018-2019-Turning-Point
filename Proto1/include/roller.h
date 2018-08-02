#ifndef ROLLER_H
#define ROLLER

#include"motor.h"

class roller{
private:
  motor* rollerMotor;

public:
  roller();

  void addRoller(int port, bool reverse);
  void set_Direction(bool reverse);
  void set_Port(int port);
  void set_Power(int power);
  void halt();
  bool get_Direction();
  int get_Speed();
  void set_ClawMotor(int port);
};

#endif
