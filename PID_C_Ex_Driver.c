#pragma config(Motor,  port2,           Mot1,        tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl7,  Enc,           sensorQuadEncoder)

#include "PID_C_Example.c"

/*

//===========================================================================

  This code is a driver example of an implementation of
  PID code inside of "PID_C_Example.c" with RobotC.
  The system is a motor connected to a quadrature encoder
  that holds a shaft connected to a small arm of metal.
  With the PID in use, pushing the arm will result in the
  system to try and get the arm to the target degree.


  A PID system is called by including the method "PID_C_Example.c",
  and calling the method "PIDController(float target, float senseVal,
  float senseTime, float kp, float ki, float kd)", where "target" is
  the target variable, "senseVal" is the sensor value detecting changes,
  "sampleTime" is the time between intervals of taking a sensor measurement,
  "kp" is the weight of the proportional factor, "ki" is the weight of
  the integral factor, and "kd" is the weight of the derivative factor.

  It returns a float value that is assigned to the motor as an amount of power
  (if over 127, the hardware automatically caps it at 127).

  //===========================================================================

  Variables that the user could change for this example:
  tarDeg //targetforPID
  proportionalWeight //the weight of the proportional factor
  integralWeight //the weight of the integral factor
  derivativeWeight //the weight of the derivative factor
  sampleTime //the time between intervals of taking a sensor measurement

  //===========================================================================

*/


float tarDeg = 60; //Arbitrary value for a degree target
float proportionalWeight = .6;
float integralWeight = 0;
float derivativeWeight = 0;
float sampleTime = 50; //arbitrary, but should be calculated if possible. Milliseconds
//sampleTime is the time between intervals of taking a measurement. Useful for integral
// and derivative
float motPow = 0; //a temporary place to store the result from PID.

task PIDControl()
{
  while(true) //in a while true loop to maintain the angle desired
  {
    motPow = PIDController(tarDeg, SensorValue[Enc], proportionalWeight, integralWeight, derivativeWeight);
    //this only changes a value, not the motor power, to avoid power assigning issues
    wait1msec(sampleTime); //waits for the amount of sampleTime
  }
}

task main()
{
  startTask(PIDControl);
  while(true)
  {
    motor[Mot1] = motPow;
  }
}
