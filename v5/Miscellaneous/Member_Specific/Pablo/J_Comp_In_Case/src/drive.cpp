
#include "main.h"
#include "drive.hpp"

int start = 0;
int max_standard_rpm = 200;
int descore_degree = 130; //120 also works

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

  int max_high_rpm = 600;
  int left = 0;
  int right = 0;
  int inTake = 0;
  int choice = 0;


  while (true) {
    // pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
    //                  (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
    //                  (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

    left = master.get_analog(ANALOG_LEFT_Y);
    right = master.get_analog(ANALOG_RIGHT_Y);

    if (master.get_digital(DIGITAL_DOWN) == 1)
    {
      inTake = max_standard_rpm;
    }
    else if (master.get_digital(DIGITAL_L2) == 1)
    {
      inTake = -max_standard_rpm;
    }
    else
    {
      inTake = 0;
    }

    if (master.get_digital(DIGITAL_L1) == 1)
    {
      catapult_motor1.move_velocity(70);
      catapult_motor2.move_velocity(70);
    }
    else if (master.get_digital(DIGITAL_UP) == 1)
    {
      catapult_motor1.move_velocity(-200);
      catapult_motor2.move_velocity(-200);
    }
    else
    {
      catapult_motor1.move_velocity(0);
      catapult_motor2.move_velocity(0);
    }

    left_motors_go(left);
    right_motors_go(right);
    intake_motor1.move_velocity(inTake);
    intake_motor2.move_velocity(inTake);

    pros::delay(20); //its there from pros
  }

}

void claw_mot(void* pntr3)
{
  //descore_degree = 40;
  while(true)
  {
    if ((master.get_digital(DIGITAL_A) == 1) || (master.get_digital(DIGITAL_X) == 1))
    {
      start = millis();
      descore_arm.set_zero_position(0);
      while((millis() - start) < 275)
      {
      // descore_arm.move_velocity(max_standard_rpm);
      // }
      // descore_arm.move_velocity(0);
        descore_arm.move_absolute(descore_degree * 3, max_standard_rpm);
      }
      delay(1000);
    }
    else
    {
      descore_arm.move_velocity(0);
    }
    if (master.get_digital(DIGITAL_R1) == 1)
    {
      descore_arm.move_velocity(200);
    }
    else if (master.get_digital(DIGITAL_R2) == 1)
    {
      descore_arm.move_velocity(-200);
    }
    else
    {
      descore_arm.move_velocity(0);
    }
    delay(20);
  }
}
