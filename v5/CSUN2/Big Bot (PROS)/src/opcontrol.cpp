#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	int DEADZONE = 20;
	//brake_chassis();
	tare();
	Task TimeChecker (CheckTime, (void*) "CSUN2", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Time Checker");
	gyro.reset();
	int i = 0;
	int j = 0;
	bool brakeOn = false;
	while(true)
	{

		i = rightArm.get_temperature();
		j = leftArm.get_temperature();

		master.print(0,0, "%i %i", i, j);	// Prints temperature on controller


		// MOVE CONTROL

    // LEFT DRIVE
	  if (abs(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)) >= DEADZONE)
	  {
	    LMotors(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
	  }
		else
		{
	    LMotors(0);
	  }

	  // RIGHT DRIVE
	  if (abs(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)) >= DEADZONE)
	  {
	    RMotors(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
	  }
		else
		{
	    RMotors(0);
		}

		// INTAKE CONTROL
    if (master.get_digital(E_CONTROLLER_DIGITAL_R2))
    {
      Intake.move_velocity(200);
    }
    else if (master.get_digital(E_CONTROLLER_DIGITAL_L2))
    {
      Intake.move_velocity(-200);
    }
    else
    {
      Intake.move_velocity(0);
    }

		// PUNCHER CONTROL
		if(master.get_digital(E_CONTROLLER_DIGITAL_LEFT))
		{
			Shoot();
			/*
			RightPunch.move(127);
			LeftPunch.move(127);
			RightPunch.tare_position();
		  LeftPunch.tare_position();*/
		}
		else if(master.get_digital(E_CONTROLLER_DIGITAL_RIGHT))
		{
			RightPunch.move(-40);
			LeftPunch.move(-40);
		}
		else
		{
			RightPunch.move_velocity(0);
			LeftPunch.move_velocity(0);
		}

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

		pros::delay(20);
	}
	TimeChecker.remove();
	//ControlArm.remove();

}
