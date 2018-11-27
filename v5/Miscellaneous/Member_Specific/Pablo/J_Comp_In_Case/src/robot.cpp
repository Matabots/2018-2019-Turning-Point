#include "main.h"
#include "robot.hpp"

#define KF 0
#define KP 1.0f
#define KI 0.0f
#define KD 0.0f

Controller master(pros::E_CONTROLLER_MASTER);
Motor right_motor1(11, true);
Motor right_motor2(12, false);
Motor right_motor3(13, false);
Motor left_motor1(14 ,true);
Motor left_motor2(15, true);
Motor left_motor3(16, false);
Motor intake_motor(18);
Motor flywheel_motor1(19, true);
Motor flywheel_motor2(20, false);
Motor Lift_motor1(4, false);
Motor Lift_motor2(6, true);
Motor endEff_motor(2, true);
motor_pid_s_t pid1 = Motor::convert_pid(KF, KP, KI, KD);

void setup_bot()
{
  right_motor1.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  right_motor2.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  right_motor3.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  left_motor1.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  left_motor2.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  left_motor3.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  endEff_motor.set_encoder_units(E_MOTOR_ENCODER_ROTATIONS);
  Lift_motor1.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  Lift_motor2.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  // right_motor1.set_pos_pid(pid1);
  // right_motor2.set_pos_pid(pid1);
  // right_motor3.set_pos_pid(pid1);
  // left_motor1.set_pos_pid(pid1);
  // left_motor2.set_pos_pid(pid1);
  // left_motor3.set_pos_pid(pid1);
  flywheel_motor1.set_vel_pid(pid1);
  flywheel_motor2.set_vel_pid(pid1);


}
