
#include "main.h"
#include "drive.hpp"

// #include "robot.hpp"
// pros::Controller master(pros::E_CONTROLLER_MASTER);
// pros::Motor right_motor1(11, true);
// pros::Motor right_motor2(12, false);
// pros::Motor right_motor3(13, false);
// pros::Motor left_motor1(14 ,true);
// pros::Motor left_motor2(15, true);
// pros::Motor left_motor3(16, false);
// pros::Motor intake_motor(18);
// pros::Motor flywheel_motor1(19, true);
// pros::Motor flywheel_motor2(20, false);
// pros::Motor Lift_motor1(4, false);
// pros::Motor Lift_motor2(6, true);
// pros::Motor endEff_motor(2, true);


// static std::string stringFlow = "Hello World, I'm Jerry!";
// static int counter = stringFlow.length();
// static std::string output;
// static int start = 0;
// static int end = stringFlow.length();

//
// void screen_placeholder()
// {
// 	while(true)
// 	{
// 		pros::lcd::clear_line(3);
//     output.erase(output.begin(),output.end());
//     output.append(30u, '_');
//     for (int x = 1; x < )
// 		output.append(stringFlow, start, end);
// 		pros::lcd::set_text(3, output);
// 	}
// }

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
  bool twice = false;
  int max_standard_rpm = 200;
  int max_high_rpm = 600;
  int left = 0;
  int right = 0;
  int inTake = 0;
  int choice = 0;
  int shootSpeed = 0;

  int endEffRevCount1 = 2;
  int endEffSpeed = max_standard_rpm;
  int endEffTar = endEff_motor.get_position();
  int endEffAngle1 = 90;
  int endEffAngle2 = 90;

  int liftSpeed = 0; //lift shall be coded in stages
  double liftTar1 = Lift_motor1.get_position();
  double liftTar2 = Lift_motor2.get_position();
  int FW_Speed_Difference = 15;
  int FW_Speed_1 = max_standard_rpm;
  int FW_Speed_2 = max_standard_rpm - FW_Speed_Difference;
  int FW_Speed_3 = max_standard_rpm - (2 * FW_Speed_Difference);

  while (true) {
    // pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
    //                  (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
    //                  (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

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

    if (master.get_digital(DIGITAL_R2) == 1 && liftSens.get_value() == 0) //&& degrees
    {
      Lift_motor1.move_velocity(max_standard_rpm);
      Lift_motor2.move_velocity(max_standard_rpm);
      liftTar1 = Lift_motor1.get_position();
      liftTar2 = Lift_motor2.get_position();
    }
    else if (master.get_digital(DIGITAL_R1) == 1 )
    {
      Lift_motor1.move_velocity(-max_standard_rpm);
      Lift_motor2.move_velocity(-max_standard_rpm);
      liftTar1 = Lift_motor1.get_position();
      liftTar2 = Lift_motor2.get_position();
    }
    else
    {
      Lift_motor1.move_absolute(liftTar1, liftSpeed);
      Lift_motor2.move_absolute(liftTar2, liftSpeed);
    }
    if (master.get_digital(DIGITAL_L1) == 1) //&& degrees
    {
      if (twice)
      {
        twice = false;
      }
      else
      {
        endEffTar = endEffTar + (endEffAngle1 * endEffRevCount1);
        twice = true;
      }
    }
    else if (master.get_digital(DIGITAL_L2) == 1)
    {
      if (twice)
      {
        twice = false;
      }
      else
      {
        endEffTar = endEffTar - (endEffAngle1 * endEffRevCount1);
        twice = true;
      }
    }

    left_motors_go(left);
    right_motors_go(right);
    intake_motor.move_velocity(inTake);
    flywheel_motor1.move_velocity(shootSpeed);
    flywheel_motor2.move_velocity(shootSpeed);
    endEff_motor.move_absolute(endEffTar, endEffSpeed);

    pros::delay(20); //its there from pros
  }
}
