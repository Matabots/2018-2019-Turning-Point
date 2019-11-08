#include "main.h"
#include "calculation_methods.hpp"

int wheelRadius = 2;	// inches

// CONVERT INCHES TO DEGREES
float InchToDeg(float inches)
{
  float deg = (inches * 360) / (4 * 3.14);
  return deg;
}

// CONVERT DEGREES TO INCHES
float DegToInch(float degrees)
{
  float inch = (4 * 3.14 * degrees) / 360;
  return inch;
}

// CONVERT SQUARES TO INCHES
float SqToInch(float sq)
{
  return sq * 22.1;
}

// CALCULATE RIGHT POSITION
float Rpos(float Rf, float Rm, float Rb)
{
  float result = ((Rf + Rm + Rb) / 3);
  return result;
}

// CALCULATE LEFT POSITION
float Lpos(float Lf, float Lm, float Lb)
{
  float result = ((Lf + Lm + Lb) / 3);
  return result;
}

// RESET ENCODERS
void tare()
{
  RightFront.tare_position();
  RightMiddle.tare_position();
  RightBack.tare_position();
  LeftFront.tare_position();
  LeftMiddle.tare_position();
  LeftBack.tare_position();
  //gyro.reset();
}
