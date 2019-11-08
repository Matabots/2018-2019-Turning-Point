#include "main.h"
#include "tasks.hpp"

// CONTAINS ALL TASK METHODS

// TIME TRACKER (This task will constantly check for elasped time)
// If only 10 seconds are left during opcontrol, Controller will vibrate(rumble)
void CheckTime(void* param)
{
  float startTime = pros::millis();
  float now = pros::millis();
  while(true)
  {
    // Update now
    now = pros::millis();

    // CHECK FOR TIME
    if((now - startTime) > 65000) // Only 10 seconds left
    {
      master.rumble("-.-.-");
      break;
    }
  }
}
/*
// ARM CONTROL (This task will control the arm for Ash during opcontrol)
void ArmControl(void* param)
{
    bool brakeOn = false;

  while(true)
  {
    //rightArm.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    //leftArm.set_brake_mode(E_MOTOR_BRAKE_BRAKE);

    // ARM CONTROL
    if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
    {
      rightArm.move(127);
      leftArm.move(127);
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_L1))
    {
      rightArm.move(-127);
      leftArm.move(-127);
    }
    else
    {
      rightArm.move_velocity(0);
      leftArm.move_velocity(0);
    }

    // MOVE ARM TO HORIZONTAL POSITION
    if (master.get_digital(E_CONTROLLER_DIGITAL_UP))
    {
      MoveArmFront();
    }

    // MOVE ARM BACK
    if (master.get_digital(E_CONTROLLER_DIGITAL_DOWN))
    {
      MoveArmBack();
    }

    // FLIP CAP WITH ARM
    if (master.get_digital(E_CONTROLLER_DIGITAL_A))
    {
      FlipCap();
    }

    // BRAKE ARM
    if (master.get_digital(E_CONTROLLER_DIGITAL_B) && (!brakeOn))
    {
      AddBrake();
      delay(500);
      brakeOn = true;
    }

    // UNBRAKE ARM
    if (master.get_digital(E_CONTROLLER_DIGITAL_B) && (brakeOn))
    {
      RemoveBrake();
      delay(500);
      brakeOn = false;
    }
  }
}*/
