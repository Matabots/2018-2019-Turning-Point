// GLOBAL VARIABLES
float error = 0;
float currSens = 0;
float totalError = 0;
float prevError = 0;
float tarDeg = 60; //Arbitrary value for a degree target
float proportionalWeight = .6;
float integralWeight = .5;
float derivativeWeight = .5;
float sampleTime = 500; //arbitrary, but should be calculated if possible. Milliseconds
//sampleTime is the time between intervals of taking a measurement. Useful for integral
// and derivative
float motPow = 0; //a temporary place to store the result from PID.


float proportional_Cont(float input, float kp)
{
  return (error * kp);
}
float integral_Cont(float ki)
{
  if(abs(error) < abs(tolerance))
  {
    totalError = totalError + (error * dt);
  }
  else
  {
    totalError = 0;
  }
  return (totalError * ki);
}
float derivative_Cont(float kd)
{
  return (((error - prevError)/(dt)) * kd);
}

float PIDController(float target, float senseVal, float senseTime, float kp, float ki, float kd)
{
  float result;
  /*target is your target value
  sense is the value of a sensor
  kp is your weight for the proportional controller
  ki is your weight for the integral controller
  kd is your weight for the derivative controller
  */
  dt = senseTime/1000; //since time is defined in miliseconds
  currSens = senseVal;
  error = input - currSens;
  result = proportional_Cont(target, kp) + integral_Cont(ki) + derivative_Cont(kd);
  return result;
}


task PIDControl()
{
  while(true) //in a while true loop to maintain the angle desired
  {
    motPow = PIDController(tarDeg, SensorValue[Enc], proportionalWeight, integralWeight, derivativeWeight);
    //this only changes a value, not the motor power, to avoid power assigning issues
    wait1msec(sampleTime); //waits for the amount of sampleTime
  }
}