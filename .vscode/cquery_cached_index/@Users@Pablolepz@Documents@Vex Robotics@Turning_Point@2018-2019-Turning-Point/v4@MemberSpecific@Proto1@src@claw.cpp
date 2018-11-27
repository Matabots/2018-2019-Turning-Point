#include "claw.h"

claw::claw(){
  this->clawMotor = new motor();
}

void claw::set_Direction(bool reverse){
  this->clawMotor->set_Direction(reverse);
};
void claw::set_Port(int port){
  this->clawMotor->set_Port(port);
};
void claw::set_Power(int power){
  this->clawMotor->set_Power(power);
};
void claw::halt(){
  this->clawMotor->set_Power(0);
};
bool claw::get_Direction(){
  return this->clawMotor->get_Direction();
};
int claw::get_Speed(){
  return this->clawMotor->get_Speed();
};
void claw::set_ClawMotor(int port){
   this->clawMotor->set_Port(port);
};
