#include "control.h"

control::control(){
  //setup all controller bindings here
  this->bigLiftVar = 0;
  this->smallLift = 0; //8R toggle
  this->clearStack = 0;//8L wipe the stack
  this->goalLifter = 0; //7U up 7d down
  this->roller = 0; //toggle buttons intake 8u 8d outtake
  this->autonLift = 0;
  this->autonAbort = 0; //7right
  this->team = 0;
};

void control::setupcontrol(){
  
  };
//return functions here
  int control::autonLiftProcessAdd(){
    if(this->team == 2){
      return joystickGetDigital(1, this->autonLift, JOY_UP);
    }else{
      return joystickGetDigital(2, this->autonLift, JOY_LEFT);
    }
  };
  int control::autonLiftProcessSubtract(){
    if(this->team == 2){
      return joystickGetDigital(1, this->autonLift, JOY_DOWN);
    }else{
      return joystickGetDigital(2, this->autonLift, JOY_DOWN);
    }
  };
  int control::autoLiftAbort(){
    if(this->team == 2){
      return joystickGetDigital(1, this->autonAbort, JOY_RIGHT);
    }else{
      return joystickGetDigital(2, this->autonAbort, JOY_RIGHT);
    }
  }
  int control::rollerOpen(){
    if(this->team == 2){
      return joystickGetDigital(1, this->roller, JOY_DOWN);
    }else{
      return joystickGetDigital(2, this->roller, JOY_DOWN);
    }
  };
  int control::rollerClose(){
    if(this->team == 2){
      return joystickGetDigital(1, this->roller, JOY_UP);
    }else{
      return joystickGetDigital(2, this->roller, JOY_UP);
    }
  };
  int control::smallLiftUp(){
    if(this->team == 2){
      return joystickGetDigital(1, this->smallLift, JOY_RIGHT);
    }else{
      return joystickGetDigital(2, this->smallLift, JOY_UP);
    }
  };
  int control::smallLiftDown(){
    if(this->team == 2){
      return joystickGetDigital(1, this->smallLift, JOY_LEFT);
    }else{
      return joystickGetDigital(2, this->smallLift, JOY_DOWN);
    }
  }
  int control::clearConeStack(){
    if(this->team == 2){
      return joystickGetDigital(1, this->clearStack, JOY_LEFT);
    }else{
      return joystickGetDigital(2, this->clearStack, JOY_LEFT);
    }
  };
  int control::bigLift(){
    if(this->team == 2){
      if( (joystickGetDigital(1, this->bigLiftVar, JOY_UP)) != 0){
       return joystickGetDigital(1, this->bigLiftVar, JOY_UP);
     }else if ( joystickGetDigital(1, this->bigLiftVar, JOY_DOWN)!= 0){
       return -1*joystickGetDigital(1, this->bigLiftVar, JOY_DOWN);
     }else{
       return 0;
     }
    }else{
      return joystickGetAnalog(2,3);
    }
  };
  // int control::bigLiftUp(){
  //   return joystickGetDigital(1, this->bigLift, JOY_UP);
  // };
  // int control::bigLiftDown(){
  //   return joystickGetDigital(1, this->bigLift, JOY_DOWN);
  // };
  int control::goalLiftUp(){
    if(this->team == 2){
      return joystickGetDigital(1,this->goalLifter, JOY_UP);
    }else{
      return joystickGetDigital(1, this->goalLifter, JOY_UP);
    }
  };
  int control::goalLiftDown(){
    if(this->team == 2){
      return joystickGetDigital(1,this->goalLifter,JOY_DOWN);
    }else{
      return joystickGetDigital(1, this->goalLifter, JOY_DOWN);
    }
  }
  int control::rightJoystickVal(){
    if(this->team == 2){
      return joystickGetAnalog(1, 2);
    }else{
      return joystickGetAnalog(1, 2);
    }
  };
  int control::leftJoystickVal(){
    if(this->team == 2){
      return joystickGetAnalog(1, 3);
    }else{
      return joystickGetAnalog(1, 3);
    }
  };
  int control::defaultPosition(){
    return joystickGetDigital(2, 8, JOY_UP);
  }
  int control::get_team(){
    return this->team;
  };
  int control::absRightJoystickVal() {
    return (joystickGetAnalog(1, 2) < 0 ? -joystickGetAnalog(1, 2) : joystickGetAnalog(1, 2));
  };
  int control::absLeftJoystickVal() {
    return (joystickGetAnalog(1, 3) < 0 ? -joystickGetAnalog(1, 3) : joystickGetAnalog(1, 3));
  };
