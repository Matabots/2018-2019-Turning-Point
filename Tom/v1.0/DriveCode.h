//Drive code for tom
#include "TomMain.c"
#include "RobotModules.h"
int deadzone = 15;
bool transBool = true;
int lag = 50;

void butLag()
{
	wait10Msec(lag);
}
//void halt()
//{
//	rightMotors(0);
//	leftMotors(0);
//}
void transmission()
{
	if (vexRT[remote.transmission] == 1)
	{
		if(transBool)
		{
			transBool = false;
			SensorValue[TransPneu] = 1;
			butLag();
		}
		else
		{
			transBool = true;
			SensorValue[TransPneu] = 0;
			butLag();
		}
	}
}
//void chassisCode()
//{
//	if(abs(vexRT[remote.rightDrive]) > deadzone)
//	{
//		rightMotors(vexRT[remote.rightDrive]);
//	}
//	else
//	{
//		rightMotors(0);
//	}
//	if(abs(vexRT[remote.leftDrive]) > deadzone)
//	{
//		leftMotors(vexRT[remote.leftDrive]);
//	}
//	else
//	{
//		leftMotors(0);
//	}
//}
void buttonCode()
{
	transmission();
}
void intakeCode()
{
	if(vexRT[remote.intakeBackward] == 1)
	{
		intake(127);
	}
	else if(vexRT[remote.intakeForward] == 1)
	{
		intake(-127);
	}
	else
	{
		intake(0);
	}
}
void drive()
{
	//chassisCode();
	buttonCode();
	intakeCode();
}
