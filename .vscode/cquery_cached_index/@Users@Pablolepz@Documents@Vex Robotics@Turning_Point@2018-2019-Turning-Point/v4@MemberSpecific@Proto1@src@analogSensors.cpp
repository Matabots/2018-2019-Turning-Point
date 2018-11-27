// analogSensors.cpp
#include "analogSensors.h"

analogSensors::analogSensors()
{
  deltaGyro = 0;
  this->rollerPotentiometer = potentiometer();
  // this->gyro = gyroInit(analog1, 0);
  // this->rollerPotentiometer.set_Potentiometer(analog2);
  // this->jukeSwitch = potentiometer();
};
void analogSensors::set_deltaGyro(int num){
  this->deltaGyro = num;
};
int analogSensors::get_deltaGyro(){
  return this->deltaGyro;
};
void analogSensors::set_gyro(int port, int multiplier){
  this->gyro = gyroInit(port, multiplier);
};
Gyro analogSensors::get_gyro(){
  return this->gyro;
};
int analogSensors::gyro_val(){
  return gyroGet(this->gyro);
};
void analogSensors::reset_gyro(){
  gyroReset(this->gyro);
};
void analogSensors::set_potentiometer(int port){
  this->rollerPotentiometer.set_Potentiometer(port);
};
potentiometer analogSensors::get_potentiometer(){
  return this->rollerPotentiometer;
};
int analogSensors::get_potentiometerVal(){
  return this->rollerPotentiometer.getValue();
};
void analogSensors::set_jukeSwitch(int port){
  this->jukeSwitch.set_Potentiometer(port);
};
potentiometer analogSensors::get_jukeSwitch(){
  return this->jukeSwitch;
};
int analogSensors::get_jukeSwitchVal(){
  return this->jukeSwitch.getValue();
};
void analogSensors::set_leftLineSensor(int port){
  this->leftLineSensor.set_lineSensor(port);
};
void analogSensors::set_rightLineSensor(int port){
  this->rightLineSensor.set_lineSensor(port);
};
lineSensor analogSensors::get_leftLineSensor(){
  return this->leftLineSensor;
};
int analogSensors::get_leftLineSensorVal(){
  return this->leftLineSensor.getValue();
};
lineSensor analogSensors::get_rightLineSensor(){
  return this->rightLineSensor;
};
int analogSensors::get_rightLineSensorVal(){
  return this->rightLineSensor.getValue();
};
