
#include "main.h"
#include "drive.hpp"

static std::string stringFlow = "Hello World, I'm Jerry!";
static int counter = stringFlow.length();
static std::string output;
static int start = 0;
static int end = stringFlow.length();

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

void screen_placeholder()
{
	while(true)
	{
		pros::lcd::clear_line(3);
    output.erase(output.begin(),output.end());
		output.append(stringFlow, start, end);
		pros::lcd::set_text(3, output);
	}
}

void left_motors_go(int rpm)
{
  left_motor1 = rpm;
  left_motor2 = rpm;
  left_motor3 = rpm;
}

void right_motors_go(int rpm)
{
  right_motor1 = rpm;
  right_motor2 = rpm;
  right_motor3 = rpm;
}

void move_Chassis()
{
  int left = 0;
  int right = 0;
  int inTake = 0;
  int choice = 0;
  int shootSpeed = 0;
  int endEffSpeed = 0;
  int liftSpeed = 0; //lift shall be coded in stages
  int max_standard_rpm = 200;
  int max_high_rpm = 600;
  int FW_Speed_Difference = 15;
  int FW_Speed_1 = max_standard_rpm;
  int FW_Speed_2 = max_standard_rpm - FW_Speed_Difference;
  int FW_Speed_3 = max_standard_rpm - (2 * FW_Speed_Difference);

  while (true) {
    pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                     (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                     (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

    left = master.get_analog(ANALOG_LEFT_Y);
    right = master.get_analog(ANALOG_RIGHT_Y);

    if (master.get_digital(DIGITAL_Y) == 1)
    {
      inTake = max_standard_rpm;
    }
    else if (master.get_digital(DIGITAL_X) == 1)
    {
      inTake = -max_standard_rpm;
    }
    else
    {
      inTake = 0;
    }
    if (master.get_digital(DIGITAL_UP) == 1)
    {
      shootSpeed = FW_Speed_1;
    }
    else if (master.get_digital(DIGITAL_RIGHT) == 1)
    {
      shootSpeed = FW_Speed_2;
    }
    else if (master.get_digital(DIGITAL_DOWN) == 1)
    {
      shootSpeed = FW_Speed_3;
    }
    else if (master.get_digital(DIGITAL_LEFT) == 1)
    {
      shootSpeed = 0;
    }

    if (master.get_digital(DIGITAL_R1) == 1) //&& degrees
    {
      liftSpeed = max_standard_rpm;
    }
    else if (master.get_digital(DIGITAL_R2) == 1)
    {
      liftSpeed = -max_standard_rpm;
    }
    else
    {
      liftSpeed = 0;
    }
    if (master.get_digital(DIGITAL_L1) == 1) //&& degrees
    {
      endEffSpeed = max_standard_rpm;
    }
    else if (master.get_digital(DIGITAL_L2) == 1)
    {
      endEffSpeed = -max_standard_rpm;
    }
    else
    {
      endEffSpeed = 0;
    }

    left_motors_go(left);
    right_motors_go(right);
    intake_motor.move_velocity(inTake);
    flywheel_motor1.move_velocity(shootSpeed);
    flywheel_motor2.move_velocity(shootSpeed);
    Lift_motor1.move_velocity(liftSpeed);
    Lift_motor2.move_velocity(liftSpeed);
    endEff_motor.move_velocity(endEffSpeed);

    pros::delay(20); //its there from pros
  }
}
