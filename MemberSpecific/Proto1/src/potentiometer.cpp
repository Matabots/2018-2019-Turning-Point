#include "potentiometer.h"
  potentiometer::potentiometer(){

  };

  void potentiometer::set_Potentiometer(int port){
    this->potentiometerPort = port;
  };
  int potentiometer::get_Potentiometer(){
    return this->potentiometerPort;
  };
  void potentiometer::updateValues(){
    this->value = analogReadCalibrated(this->potentiometerPort);
  };
  int potentiometer::getValue(){
    return analogReadCalibrated(this->potentiometerPort);
  };
  void potentiometer::reset()
  {
    this->value = 0;
  };
