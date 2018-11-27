#include "Jerryv1.0.c"
#include "MathFuncs.h"
bool onOff = true;
bool change = true;

int choice = 0;
int inCount = 0;
int inPow = 127;

int maxRPM = 127;//arbitrary after doing a test
int rpm2 = 127
int rpm3 = 127
int rpm4 = 127
int rpmTar = 0;
int currRPM = 0;

void rMots(int power)
{
	motor[LDrive] = power;
	motor[midleft] = power;
}

void lMots(int power)
{
	motor[RDrive] = power;
	motor[midRight] = power;
}
void flyMots(int power)
{
	motor[Fly1] = power;
	motor[Fly2] = power;
	motor[Fly3] = power;
	motor[Fly4] = power;
}

void inTake(int power)
{
	motor[InMot] = power;
}

void joyStickCheck()
{
			if(abs(vexRT[Ch2]) > 20)
      {
         rMots(vexRT(Ch2));
      }
      else
      {
         rMots(0);
      }
      if(abs(vexRT[Ch3]) > 20)
      {
         lMots(vexRT(Ch3));
      }
      else
      {
         lMots(0);
      }
}

void changeIn()
{

	if (vexRT[Btn5D] == 1)
	{
		inCount = inCount + 1;
		if (inCount == 3)
		{
			inCount = 0;
		}
		else
		{
			switch(inCount)
			{
				case 0: inPow = 80;
				break;

				case 1: inPow = 100;
				break;

				case 2: inPow = 127;
				break;

				default: inPow = 127;
				break;
			}
		}
		wait10Msec(50);
	}
}

void checkIn()
{
	if (vexRT[Btn6U] == 1)
	{
		inTake(inPow);
	}
	else if(vexRT[Btn6D] == 1)
	{
		inTake(-inPow);
	}
	else
	{
		inTake(0);
	}
}

void checkFly()
{
	if (vexRT[Btn7R] == 1)
	{
		if (onOff == true)
		{
				onOff = !onOff;
				flyMots(rpmTar);
		}
		else
		{
			onOff = !onOff;
			flyMots(0);
		}
		wait1Msec(500);
	}
}
void readFlyWheel()
{
	currRPM = rpmCalc(numRot);
}

void checkGear()
{
	if(vexRT[Btn8D] == 1)
	{
		if (change == true)
		{
			SensorValue[Transmit] = 0;
			change = false;
		}
		else
		{
			SensorValue[Transmit] = 1;
			change = true;
		}
		wait10Msec(50);
	}
}

void flyTar()
{
	if(vexRT[Btn8U] == 1)
	{
		choice = choice + 1;
		if (choice == 4)
		{
			choice = 0;
		}
		else
		{
			switch(choice)
			{
				case 0:
					rpmTar = maxRPM;
				break;

				case 1:
					rpmTar = rpm2;
				break;

				case 2:
					rpmTar = rpm3;
				break;

				case 3:
					rpmTar = rpm4;
				break;

			}
		}
		wait1Msec(500);
	}
}

void drive()
{
	while(true)
   {
     joyStickCheck();
     checkIn();
     changeIn();
     checkFly();
     checkGear();
     getRPM();
     flyTar();
   }
}
