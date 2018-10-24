/*
  AutonFunction
*/
#include "Commands.h"
bool red = true;
bool autoLoad = false;
bool preloading = true;

void testTask() //temp
{
	PIDDrive(20);
  //ToLine(100);//positive for forward, negative for backward
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void autonGo()
{
	if (red)
	{	//needs to have fresh batteries and good rubber bands. starts at 7 inches from the wall
		if (preloading)
		{
		  PreLoad();
		  wait1Msec(1000); // 1/4 of second to clear cone, not
		}
		tinyLiftDown(1.25);//was 1.75
		PIDDrive(61); //was 60, is split into two 30s
		tinyLiftUp();
    wait10Msec(50);
		if (preloading)
		{
		  AutoLift();
		  //wait1Msec(250);
		}
		if (autoLoad)
			{
		}
		else
		{
			PIDDrive(-47);

			//--good for 20 points
			TurnTo(310); //170
			wait10Msec(100); // was at 200
			PIDDrive(-30);

			//scoring ----
			TurnTo(225);
			wait10Msec(100); // was 50
			PIDDrive(6); //was 10
			score(115, 115, 1.25);

			tinyLiftDown(1.75);
			wait10Msec(55); //was 40
			tinyLiftUpTmp(0.15);
			score(80, 80, 0.75);
			driveBack(127,127, 0.85);

			TurnTo(95);
			wait10Msec(150);

			//nextGoal----
			tinyLiftUp();
			PIDDrive(35);
			TurnTo(355);
			wait10Msec(150);
			driveBack(35,35,1.4);
			wait10Msec(30); //to wait for bot to stop
			setGyroInGame();
			PIDDrive(7);
		  TurnTo(98);

			oldtinyLiftDown(1.9);

			PIDDrive(33); // was 31
			wait10Msec(100);

			tinyLiftUp();
			wait10Msec(80);
			TurnTo(100);

			wait10Msec(25);

			driveBack(127,127, 1.0);

			TurnTo(275);

			wait10Msec(50);

			score(127, 127, 0.8);
			wait10Msec(75);
			tinyLiftDown(1.75);
			wait10Msec(150);

			driveBack(127, 127, 1.5);


		}
      tasksFinished();
  }
  else
  { //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      tasksFinished();
  }
}
