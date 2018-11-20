
#include "main.h"
#include "drive.hpp"

void move_Chassis()
{
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  pros::Motor right_motor1(5, false);
  pros::Motor right_motor2(10, true);
  pros::Motor right_motor3(1, true);
  pros::Motor left_motor1(11 ,true);
  pros::Motor left_motor2(12, false);
  pros::Motor left_motor3(4, false);
  pros::Motor intake_motor(6);
  pros::Motor flywheel_motor1(2, false);
  pros::Motor flywheel_motor2(3, true);
  int left = 0;
  int right = 0;
  int inTake = 0;
  int choice = 0;
  int shootSpeed = 0;
  while (true) {
    pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                     (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                     (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
    left = master.get_analog(ANALOG_LEFT_Y);
    right = master.get_analog(ANALOG_RIGHT_Y);

    if (master.get_digital(DIGITAL_L1) == 1)
    {
      inTake = 200;
    }
    else if (master.get_digital(DIGITAL_L2) == 1)
    {
      inTake = -200;
    }
    else
    {
      inTake = 0;
    }
    if (master.get_digital(DIGITAL_UP) == 1)
    {
      shootSpeed = 200;
    }
    else if (master.get_digital(DIGITAL_RIGHT) == 1)
    {
      shootSpeed = 150;
    }
    else if (master.get_digital(DIGITAL_DOWN) == 1)
    {
      shootSpeed = 100;
    }
    else if (master.get_digital(DIGITAL_LEFT) == 1)
    {
      shootSpeed = 0;
    }

    left_motor1 = left;
    left_motor2 = left;
    left_motor3 = left;
    right_motor1 = right;
    right_motor2 = right;
    right_motor3 = right;
    intake_motor.move_velocity(inTake);
    flywheel_motor1.move_velocity(shootSpeed);
    flywheel_motor2.move_velocity(shootSpeed);
    pros::delay(20);
  }
}
