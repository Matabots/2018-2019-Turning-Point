//Driver Control
#include "protoCodeMain.c"
#include "MathFuncs.h"
bool onOff = true;

int choice = 0;

int maxRPM = 100; //arbitrary after doing a test
int rpm2 = 80;
int rpm3 = 40;
int rpm4 = 10;
int rpmTar;
int currRPM = 0;

void joyStickCheck()
{
			if(abs(vexRT[Ch2]) > 20)
      {
         motor[right1] = vexRT(Ch2);
         motor[right2] = vexRT(Ch2);
         motor[right3] = vexRT(Ch2);
      }
      else
      {
         motor[right1] = 0;
         motor[right2] = 0;
         motor[right3] = 0;
      }
      if(abs(vexRT[Ch3]) > 20)
      {
         motor[left1] = vexRT[Ch3];
         motor[left2] = vexRT[Ch3];
         motor[left3] = vexRT[Ch3];
      }
      else
      {
         motor[left1] = 0;
         motor[left2] = 0;
         motor[left3] = 0;
      }
}

void checkFly()
{
	if ((vexRT[Btn7U] == 1) && onOff)
	{
			onOff = !onOff;
			motor[flyTop] = rpmTar;
			motor[flyMiddle] = rpmTar;
			motor[flyBottom] = rpmTar;
			wait1Msec(500);
	}
	else if ((vexRT[Btn7U] == 1) && !onOff)
	{
			onOff = !onOff;
			motor[flyTop] = 0;
			motor[flyMiddle] = 0;
			motor[flyBottom] = 0;
			wait1Msec(500);
	}
}
void readFlyWheel()
{
	currRPM = rpmCalc(numRot);
}



void flyTar()
{
	if(vexRT[Btn8U] == 1)
	{
		choice++;
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
		wait1Msec(500);
	}
}

void drive()
{
	while(true)
   {
     joyStickCheck();
     checkFly();
     getRPM();
     flyTar();
   }
}
