//Sam's attempt at flywheel code
#include "TomMain.c"
#include "RobotModules.h"

//Function to be used to directly apply motor power to the flywheel motors.
void setFlyWheelPower(int power)
{
	motor[flyWheel1] = power;
	motor[flyWheel2] = power;
}

//Used to ramp up/down the flywheel to the desired power.
void flyWheelRamp(int maxPower)
{
	int currentPower;
	if(maxPower < currentPower || maxPower == 0) //If you need to slow the flywheel down.
	{
		for(int flyWheelSpeed; flyWheelSpeed > maxPower; flyWheelSpeed = flyWheelSpeed-2)
		{
			setFlyWheelPower(flyWheelSpeed);
		}
		currentPower = maxPower;
	}
	else //If you need to ramp the flywheel up to speed.
	{
		for(int flyWheelSpeed; flyWheelSpeed < maxPower; flyWheelSpeed = flyWheelSpeed+2)
		{
			setFlyWheelPower(flyWheelSpeed);
		}
		currentPower = maxPower;
	}
}

void flyWheel()
{
	if(vexRT[remote.flywheel])
	{
		flyWheelRamp(127);
	}
	else
	{
		flyWheelRamp(0);
	}
}
