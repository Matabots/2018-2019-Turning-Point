#ifndef ANALOGSENSORS_H
#define ANALOGSENSORS_H

#include "potentiometer.h"
#include "lineSensor.h"
#include "ports.h"
class analogSensors{
  private:
  //potentiometers defined first
  potentiometer rollerPotentiometer;
  potentiometer jukeSwitch;
  //all other analog sensors here
  lineSensor leftLineSensor;
  lineSensor rightLineSensor;
  Gyro gyro;
  int deltaGyro;
  public:

      analogSensors();

      void set_deltaGyro(int num);
      int get_deltaGyro();
      void set_gyro(int port, int multiplier);
      Gyro get_gyro();
      int gyro_val();
      void reset_gyro();

      void set_potentiometer(int port);
      potentiometer get_potentiometer();
      int get_potentiometerVal();

      void set_jukeSwitch(int port);
      potentiometer get_jukeSwitch();
      int get_jukeSwitchVal();

      void set_leftLineSensor(int port);
      void set_rightLineSensor(int port);
      lineSensor get_leftLineSensor();
      int get_leftLineSensorVal();
      lineSensor get_rightLineSensor();
      int get_rightLineSensorVal();


};
#endif
