
#include "main.h"
#include "drive.hpp"

void move_Chassis()
{
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  pros::Motor right_motor1(11, false);
  pros::Motor right_motor2(12, true);
  pros::Motor right_motor3(13, false);
  pros::Motor left_motor1(14 ,true);
  pros::Motor left_motor2(15, false);
  pros::Motor left_motor3(16, true);
  pros::Motor intake_motor(20);
  pros::Motor flywheel_motor1(18, true);
  pros::Motor flywheel_motor2(19, false);
  pros::Motor Lift_motor1(4, false);
  pros::Motor Lift_motor2(5, true);
  pros::Motor endEff_motor(1, true);
  int left = 0;
  int right = 0;
  int inTake = 0;
  int choice = 0;
  int shootSpeed = 0;
  int endEffSpeed = 0;
  int liftSpeed = 0; //lift shall be coded in stages
  while (true) {
    pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                     (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                     (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
    left = master.get_analog(ANALOG_LEFT_Y);
    right = master.get_analog(ANALOG_RIGHT_Y);

    if (master.get_digital(DIGITAL_Y) == 1)
    {
      inTake = 200;
    }
    else if (master.get_digital(DIGITAL_X) == 1)
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
      shootSpeed = 185;
    }
    else if (master.get_digital(DIGITAL_DOWN) == 1)
    {
      shootSpeed = 170;
    }
    else if (master.get_digital(DIGITAL_LEFT) == 1)
    {
      shootSpeed = 0;
    }

    if (master.get_digital(DIGITAL_R1) == 1) //&& degrees
    {
      liftSpeed = 200;
    }
    else if (master.get_digital(DIGITAL_R2) == 1)
    {
      liftSpeed = -200;
    }
    else
    {
      liftSpeed = 0;
    }
    if (master.get_digital(DIGITAL_L1) == 1) //&& degrees
    {
      endEffSpeed = 200;
    }
    else if (master.get_digital(DIGITAL_L2) == 1)
    {
      endEffSpeed = -200;
    }
    else
    {
      endEffSpeed = 0;
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
    Lift_motor1.move_velocity(liftSpeed);
    Lift_motor2.move_velocity(liftSpeed);
    endEff_motor.move_velocity(endEffSpeed);

    pros::delay(20);
  }
}
