#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "main.h"

extern Controller master;
extern Motor RightFront;
extern Motor RightMiddle;
extern Motor RightBack;
extern Motor LeftFront;
extern Motor LeftMiddle;
extern Motor LeftBack;
//extern Motor Arm;
extern Motor rightArm;
extern Motor leftArm;
extern Motor RightPunch;
extern Motor LeftPunch;
extern Motor Intake;
extern okapi::ADIGyro gyro;

extern void setup_bot();

extern void brake_chassis();

#endif
