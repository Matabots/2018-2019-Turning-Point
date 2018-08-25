//Drive code for tom
#include "TomMain.c"
#include "RobotModules.h"
int deadzone = 15;
void halt()
{
	rightMotors(0);
	leftMotors(0);
}

void chassisCode()
{
	if(abs(vexRT[remote.rightDrive]) > deadzone || abs(vexRT[remote.leftDrive]) > deadzone)
	{
			rightMotors(remote.rightDrive);
			leftMotors(remote.leftDrive);
	}
	else
	{
		halt();
	}
}
void buttonCode()
{
}
void drive()
{
	chassisCode();
	buttonCode();
}
