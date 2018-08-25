//Robot modules4
#include "TomMain.c"
struct Remote
{
	TVexJoysticks intakeForward;
	TVexJoysticks intakeBackward;
	TVexJoysticks flywheel;
	TVexJoysticks rightDrive;
	TVexJoysticks	leftDrive;
};

Remote remote;

void setupRemote()
{
	remote.intakeForward = Btn5U;
	remote.intakeBackward = Btn5D;
	remote.flywheel = Btn6U;
	remote.rightDrive = Ch2;
	remote.leftDrive = Ch3;
}

void rightMotors(float power)
{
	motor[rightDrive1] = power;
	motor[rightDrive2] = power;
	motor[rightDrive3] = power;
}
void leftMotors(float power)
{
	motor[leftDrive1] = power;
	motor[leftDrive2] = power;
	motor[leftDrive3] = power;
}
