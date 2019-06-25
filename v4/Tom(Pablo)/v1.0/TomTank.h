#include "TomMain.c"
#include "RobotModules.h"

void halt()
{
	leftMotors(0);
	rightMotors(0);
}

//Make tom move foward and backwards by using tank controls, in channel 2 and 3
void driveT()
{
	//right motor
	if(abs(vexRT[Ch2]) > 5)
	{
		rightMotors(vexRT[Ch2]);
	}
	else
	{
		halt();
	}
	//left motor
	if(abs(vexRT[Ch3]) > 5)
	{
	leftMotors(vexRT[Ch3]);
	}
	else
	{
		halt();
	}

}
