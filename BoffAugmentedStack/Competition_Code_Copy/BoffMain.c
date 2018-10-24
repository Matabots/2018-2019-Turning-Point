#include "AutonCommands.h"
#include "Commands.h"

void resetEnc()
{
	SensorValue[stackEnc] = 0;
}

task runMobile() //as a task to multitask the mobile lift
{
	while (true)
	{
		checkMobile();
		wait1Msec(10); //avoids cpu lag
	}
}
task runGyroControl()
{
	while(true)
	{
		if (gyroOn)
		{
		moveGyro();
    }
  }
}
task runLiftControl()
{
	while (true)
	{
		MoveArm();
	}
}
void auton()
{
	SetupSens();
	resetEnc();
	startTask(runGyroControl);
	startTask(runMobile);
	startTask(runLiftControl);

  //testTask();
  autonGo();
}
