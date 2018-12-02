#include "main.h"
#include "robot.hpp"

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

void setup_bot()
{
  
}
