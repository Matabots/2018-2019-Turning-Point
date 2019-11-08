#include "main.h"
#include "robot.hpp"

Controller master (E_CONTROLLER_MASTER);
Motor LeftBack (5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor LeftMiddle (3, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor LeftFront (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor RightBack (19, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor RightMiddle (18, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor RightFront (17, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor rightArm (20, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor leftArm (6, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor RightPunch (9, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor LeftPunch (15, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor Intake (13, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
okapi::ADIGyro gyro ('B', 0);

void setup_bot()
{
  //RightPunch.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  //LeftPunch.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  gyro.reset();
  rightArm.tare_position();
  leftArm.tare_position();
  RightPunch.tare_position();
  LeftPunch.tare_position();
}

void brake_chassis()
{
  LeftBack.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  LeftMiddle.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  LeftFront.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  RightBack.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  RightMiddle.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
  RightFront.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
}
