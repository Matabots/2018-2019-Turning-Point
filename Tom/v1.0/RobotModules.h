//Robot modules4
#include "TomMain.c"
struct Remote
{
	TVexJoysticks intakeForward;
	TVexJoysticks intakeBackward;
	TVexJoysticks flywheel;
	TVexJoysticks rightDrive;
	TVexJoysticks	leftDrive;
	TVexJoysticks transmission;
};

Remote remote;

void setupRemote()
{
	remote.intakeForward = Btn5U;
	remote.intakeBackward = Btn5D;
	remote.flywheel = Btn6U;
	//remote.rightDrive = Ch2;
	//remote.leftDrive = Ch3;
	remote.transmission = Btn6D;
}
void setupSens()
{
	SensorValue[TransPneu] = 0;
}

void rightMotors(int power)
{
	motor[rightDrive1] = power;
	motor[rightDrive2] = power;
	motor[rightDrive3] = power;
}
void leftMotors(int power)
{
	motor[leftDrive1] = power;
	motor[leftDrive2] = power;
	motor[leftDrive3] = power;
}

void intake(int power)
{
	motor[intakeMot] = power;
}
