#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "main.h"

extern Controller master;
extern Motor right_motor1;
extern Motor right_motor2;
extern Motor right_motor3;
extern Motor left_motor1;
extern Motor left_motor2;
extern Motor left_motor3;
extern Motor intake_motor;
extern Motor flywheel_motor1;
extern Motor flywheel_motor2;
extern Motor Lift_motor1;
extern Motor Lift_motor2;
extern Motor endEff_motor;
extern ADIDigitalIn liftSens;
extern ADIGyro gyroSens;

extern void setup_bot();
extern int get_flywheel_avg_rpm();
extern int get_flywheel_target_rpm();
extern int get_FW_KF();
extern int get_FW_KP();
extern int get_FW_KI();
extern int get_FW_KD();
extern int get_gyro_val();

#endif
