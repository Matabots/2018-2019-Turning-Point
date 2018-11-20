//This is the drive
#include "v2DriveControls.h"
task runControl()
{
	while (true)
	{
		runPID();
		wait1Msec(10); // avoids cpu hog
  }
}
task runLift ()
{
  while(true)
  {
    lift();
  }
}
void drive()
{
	setVariables();
	setupController();
	//resetEnc();
	SensorValue[stackEnc] = 0;
	//startTask(clawCont);
	startTask(runControl);
	startTask(runLift);
  while(true)
  {
		runController();
		//if (vexRT[controller.stack] == 1)
		//{
			//rotatate for  degrees using P control
		wait1Msec(10); // avoids cpu hog
  }
}
