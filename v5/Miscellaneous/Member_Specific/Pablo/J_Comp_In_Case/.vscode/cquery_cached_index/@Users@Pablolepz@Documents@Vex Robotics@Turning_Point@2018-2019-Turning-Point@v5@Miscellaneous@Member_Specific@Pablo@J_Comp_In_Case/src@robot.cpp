#include "main.h"
#include "robot.hpp"

#define FW_KF 0
#define FW_KP 1.0f
#define FW_KI 0.0f
#define FW_KD 0.0f

Controller master(pros::E_CONTROLLER_MASTER);
Motor right_motor1(11, true);
Motor right_motor2(12, false);
Motor right_motor3(13, false);
Motor left_motor1(14 ,true);
Motor left_motor2(15, true);
Motor left_motor3(16, false);
Motor intake_motor(18, true);
Motor flywheel_motor1(19, true);
Motor flywheel_motor2(20, false);
Motor Lift_motor1(4, false);
Motor Lift_motor2(6, true);
Motor endEff_motor(3, true);
ADIDigitalIn liftSens('H');
ADIGyro gyroSens('C');
motor_pid_s_t pid1 = Motor::convert_pid(FW_KF, FW_KP, FW_KI, FW_KD);

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

int get_flywheel_avg_rpm()
{
  return ((flywheel_motor1.get_actual_velocity() + flywheel_motor2.get_actual_velocity())/2);
}

int get_flywheel_target_rpm()
{
  return flywheel_motor1.get_target_velocity();
}
int get_FW_KF()
{
  return FW_KF;
}
int get_FW_KP()
{
  return FW_KP;
}
int get_FW_KI()
{
  return FW_KI;
}
int get_FW_KD()
{
  return FW_KD;
}

extern int get_gyro_val()
{
  return gyroSens.get_value();
}
