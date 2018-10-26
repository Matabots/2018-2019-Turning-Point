#include "roller.h"

  roller::roller(){
    this->rollerMotor = new motor();
  }

  void roller::addRoller(int port, bool reverse){
    set_Port(port);
    set_Direction(reverse);
  };
  void roller::set_Direction(bool reverse){
    this->rollerMotor->set_Direction(reverse);
  };
  void roller::set_Port(int port){
    this->rollerMotor->set_Port(port);
  };
  void roller::set_Power(int power){
    this->rollerMotor->set_Power(power);
  };
  void roller::halt(){
    this->rollerMotor->set_Power(0);
  };
  bool roller::get_Direction(){
    return this->rollerMotor->get_Direction();
  };
  int roller::get_Speed(){
    return this->rollerMotor->get_Speed();
  };
  void roller::set_ClawMotor(int port){
     this->rollerMotor->set_Port(port);
  };
