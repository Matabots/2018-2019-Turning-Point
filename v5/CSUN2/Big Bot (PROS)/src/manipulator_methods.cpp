#include "main.h"
#include "manipulator_methods.hpp"

// INTAKE METHODS
void IntakeOn()
{
  Intake.move_velocity(200);
}

void IntakeOff()
{
  Intake.move_velocity(0);
}

void IntakeRev()
{
  Intake.move(-127);
}

// CAP FLIP METHODS

// FLIP CAP
void FlipCap()
{
  rightArm.move_velocity(-200);
  leftArm.move_velocity(-200);
  delay(250);
  rightArm.move_velocity(0);
  leftArm.move_velocity(0);
}
// MOVE ARM TO FRONT OF BOT
void MoveArmFront()
{
  rightArm.move_velocity(200);
  leftArm.move_velocity(200);
  delay(1000);
}
// MOVE ARM TO BACK OF BOT
void MoveArmBack()
{
  //rightArm.move_relative(-1250, -200);
  //leftArm.move_relative(-1250, -200);
  rightArm.move_velocity(-200);
  leftArm.move_velocity(-200);
  delay(1000);
}

void StopArm()
{
  rightArm.move_velocity(0);
  leftArm.move_velocity(0);
}

// MOVE ARM HORIZONTAL
void StraightenArm()
{
  rightArm.move_absolute(1100, -200);
  leftArm.move_absolute(1100, -200);
}
void AddBrake()
{
  rightArm.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  leftArm.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}
void AddHold()
{
  rightArm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  leftArm.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}
void RemoveBrake()
{
  rightArm.set_brake_mode(E_MOTOR_BRAKE_COAST);
  leftArm.set_brake_mode(E_MOTOR_BRAKE_COAST);
}

// SHOOT PUNCHER
void Shoot()
{
  RightPunch.move(110);
  LeftPunch.move(110);
  delay(600);
  RightPunch.move_velocity(0);
  LeftPunch.move_velocity(0);
}
