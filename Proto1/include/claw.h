#ifndef CLAW_H
#define CLAW_H
#include "motor.h"
class claw{
private:
  motor* clawMotor;
  // bool reversed;

public:

  claw();

  void set_Direction(bool reverse);
  void set_Port(int port);
  void set_Power(int power);
  void halt();
  bool get_Direction();
  int get_Speed();
  void set_ClawMotor(int port);
};
#endif
