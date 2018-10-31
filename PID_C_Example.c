
//Not optimized for speed or memory, designed to show the system clearly

float error = 0;
float currSens = 0;
float totalError = 0;
float prevError = 0;
float dt = 0.05; //arbitrary, but should be calculated if possible. Milliseconds

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

float PIDController(float target, float senseVal, float kp, float ki, float kd)
{
  float result;
  /*target is your target value
  sense is the value of a sensor
  kp is your weight for the proportional controller
  ki is your weight for the integral controller
  kd is your weight for the derivative controller
  */
  currSens = senseVal;
  error = input - currSens;
  result = proportional_Cont(target, kp) + integral_Cont(ki) + derivative_Cont(kd);
  return result;
}
