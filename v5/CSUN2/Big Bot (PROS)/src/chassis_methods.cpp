#include "main.h"
#include "chassis_methods.hpp"

float RCircumference= (2 * 3.14 * (14.5/2));
float MinPower = 20;
float R_kp = .5, L_kp = .5;
float tolerance = .1;
float R_error, L_error; // error in target distance and current distance

// DRIVE MEHTODS
void LMotors(float power)
{
  if(power == 0)
  {
    LeftFront.move_velocity(0);
    LeftMiddle.move_velocity(0);
    LeftBack.move_velocity(0);
  }
  else
  {
    LeftFront.move(power);
    LeftMiddle.move(power);
    LeftBack.move(power);
  }
}

void RMotors(float power)
{
  if (power == 0)
  {
    RightFront.move_velocity(0);
    RightMiddle.move_velocity(0);
    RightBack.move_velocity(0);
  } else
  {
    RightFront.move(power);
    RightMiddle.move(power);
    RightBack.move(power);
  }
}

// AUTONOMOUS METHODS

// MOVE METHODS
void MoveSq(float sq)
{
  tare();
  float target = InchToDeg(SqToInch(sq));
  RightFront.move_absolute(target, 60);
  RightMiddle.move_absolute(target, 60);
  RightBack.move_absolute(target, 60);
  LeftFront.move_absolute(target, 60);
  LeftMiddle.move_absolute(target, 60);
  LeftBack.move_absolute(target, 60);
  while(!((RightFront.get_position() < (target + 1)) && (RightFront.get_position() > (target - 1)))
          && (!((LeftFront.get_position() < (target + 1)) && (LeftFront.get_position() > (target - 1)))))
  {
    delay(2);
  }

}
void MoveTo(float distance, float velocity)
{
  tare();
  RightFront.move_absolute(InchToDeg(distance), velocity);
  RightMiddle.move_absolute(InchToDeg(distance), velocity);
  RightBack.move_absolute(InchToDeg(distance), velocity);
  LeftFront.move_absolute(InchToDeg(distance), velocity);
  LeftMiddle.move_absolute(InchToDeg(distance), velocity);
  LeftBack.move_absolute(InchToDeg(distance), velocity);
}

// TURN METHODS
void turn_right(float Rdeg)
{
  gyro.reset();
  float position = (Rdeg/360) * RCircumference;
  tare();
  float target = InchToDeg(position);
  RightFront.move_absolute(-target, -70);
  RightMiddle.move_absolute(-target, -70);
  RightBack.move_absolute(-target, -70);
  LeftFront.move_absolute(target, 70);
  LeftMiddle.move_absolute(target, 70);
  LeftBack.move_absolute(target, 70);
  while((!((RightFront.get_position() < (target + 2)) && (RightFront.get_position() > (target - 2))))
          && (!((LeftFront.get_position() < (target + 2)) && (LeftFront.get_position() > (target - 2))))
          && (gyro.get() <= (Rdeg * 10)))
  {
    delay(2);
  }
}

void turn_left(float Rdeg)
{
  gyro.reset();
  float position = (Rdeg/360) * RCircumference;
  tare();
  float target = InchToDeg(position);
  RightFront.move_absolute(target, 70);
  RightMiddle.move_absolute(target, 70);
  RightBack.move_absolute(target, 70);
  LeftFront.move_absolute(-target, -70);
  LeftMiddle.move_absolute(-target, -70);
  LeftBack.move_absolute(-target, -70);
  while((!((RightFront.get_position() < (target + 2)) && (RightFront.get_position() > (target - 2))))
          && (!((LeftFront.get_position() < (target + 2)) && (LeftFront.get_position() > (target - 2))))
          && (gyro.get() <= (Rdeg * 10)))
  {
    delay(2);
  }
}
