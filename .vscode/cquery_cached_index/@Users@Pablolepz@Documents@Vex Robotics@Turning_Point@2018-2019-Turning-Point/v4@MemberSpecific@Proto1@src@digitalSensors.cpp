#include "digitalSensors.h"

digitalSensors::digitalSensors(){

};
void digitalSensors::set_leftLimitSwitch(int port){
  this->leftLimitSwitchPort = (port);
};
int digitalSensors::get_leftLimitSwitch(){
  this->leftLimitSwitch = digitalRead(this->leftLimitSwitchPort);
  return this->leftLimitSwitch;
};
void digitalSensors::set_rightLimitSwitch(int port){
  this->rightLimitSwitchPort = (port);
};
int digitalSensors::get_rightLimitSwitch(){
  this->rightLimitSwitch = digitalRead(this->rightLimitSwitchPort);
  return this->rightLimitSwitch;
};


void digitalSensors::set_coneLiftEncoder(int port1, int port2, bool direction){
  this->coneLiftEncoder = encoderInit(port1, port2, direction);
};
Encoder digitalSensors::get_coneLiftEncoder(){
  return this->coneLiftEncoder;
};
int digitalSensors::coneLiftEncoderVal(){
  return encoderGet(this->coneLiftEncoder);
};

void digitalSensors::set_leftLiftEncoder(int port1, int port2, bool direction){
  this->leftLiftEncoder = encoderInit(port1, port2, direction);
};
Encoder digitalSensors::get_leftLiftEncoder(){
  return this->leftLiftEncoder;
};
int digitalSensors::leftLiftEncoderVal(){
  return encoderGet(this->leftLiftEncoder);
};

void digitalSensors::set_rightLiftEncoder(int port1, int port2, bool direction){
  this->rightLiftEncoder = encoderInit(port1, port2, direction);
};
Encoder digitalSensors::get_rightLiftEncoder(){
  return this->rightLiftEncoder;
};
int digitalSensors::rightLiftEncoderVal(){
  return encoderGet(this->rightLiftEncoder)/2; //for some reason the right side is counting 2x as much
};
int digitalSensors::rightLiftEncoderValModern(){
  return encoderGet(this->rightLiftEncoder);
};

void digitalSensors::set_LeftEncoder(int port1, int port2, bool direction){
  this->leftEncoder = encoderInit(port1, port2, direction);
};
Encoder digitalSensors::get_LeftEncoder(){
  return this->leftEncoder;
};
Encoder* digitalSensors::get_pLeftEncoder(){
  return &this->leftEncoder;
};
int digitalSensors::leftEncoderVal(){
  return encoderGet(this->leftEncoder);
};
void digitalSensors::set_RightEncoder(int port1, int port2, bool direction){
  this->rightEncoder = encoderInit(port1, port2, direction);
};
Encoder digitalSensors::get_RightEncoder(){
  return this->rightEncoder;
};
int digitalSensors::rightEncoderVal(){
  return encoderGet(this->rightEncoder);
};
void digitalSensors::resetDriveEncoders(){
  encoderReset(this->leftEncoder);
  encoderReset(this->rightEncoder);
};
void digitalSensors::resetLiftEncoders(){
  encoderReset(this->rightLiftEncoder);
  encoderReset(this->leftLiftEncoder);
};

void digitalSensors::printEncoderValues(){
  printf("%d\n", encoderGet(this->leftEncoder));
  printf("%d\n", encoderGet(this->rightEncoder));
};
