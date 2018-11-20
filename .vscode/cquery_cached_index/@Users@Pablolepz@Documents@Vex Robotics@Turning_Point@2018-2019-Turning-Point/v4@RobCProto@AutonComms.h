/*
	Autonomous Commands
*/
#include "protoCodeMain.c"
#include "MathFuncs.h"
float minSpeed;
float error;
float totalErrorD;
float tolerance;
float kP;
float kI;
float kD;



void resetDEnc()
{
   SensorValue[REnc] = 0;
   SensorValue[LEnc] = 0;
}

void rightMots(int power)
{
   motor[right1] = power;
   motor[right2] = power;
   motor[right3] = power;
}

void leftMots(int power)
{
   motor[left1] = power;
   motor[left2] = power;
   motor[left3] = power;
}
void halt()
{
   motor[left1] = 0;
   motor[left2] = 0;
   motor[left3] = 0;
   motor[right1] = 0;
   motor[right2] = 0;
   motor[right3] = 0;
}
void goStraightPID(float inchTarget) //using drive to? not continuous
{
   inchTarget = inchTarget/2;
   resetDEnc();
   minSpeed = 30;//minimum motor power
   encAvg = 0; //average of two encoders
   error = inchTarget - encAvg;	//distance between target and current location
   tolerance = .5;//accuracy was at .5   // stops at tolerance  how far aff the inch target we want to be aka the error of the inch target
   kP = 70; //
   totalErrorD = 0;
   kI = 0;
   kD = 0;
   time1[T3] = 0; // kill switch for the current pid method???
   float motSpeed = 0;
   resetDEnc();
   while(abs(error) > tolerance && (time1[T3] < 1000))
   {

   		//encAvg = (((SensorValue[REnc]) + (SensorValue[LEnc]))/2);
      encAvg = SensorValue[REnc];

      error = (inchTarget - (degToInch(encAvg)));
      motSpeed = error * kP;

      if (abs(motSpeed) < minSpeed)
      {
         motSpeed = motSpeed/abs(motSpeed);
         rightMots((minSpeed*motSpeed));
         leftMots((minSpeed*motSpeed));
      }
      else
      {
         rightMots(motSpeed);
         leftMots(motSpeed);
      }
      if(abs(error) > tolerance)
      {
         time1[T3] = 0;
      }
   }
   halt();
	  //}

		//Things to know about P Controllers
		//
}

void turnLeft(int power)
{
   motor[left1] = -power;
   motor[left2] = -power;
   motor[left3] = -power;
   motor[right1] = power;
   motor[right2] = power;
   motor[right3] = power;
}

void goForward(int power)
{
   rightMots(power);
   leftMots(power);
}

void maxFlyPow()
{
	motor[flyTop] = 127;
	motor[flyMiddle] = 127;
	motor[flyBottom] = 127;
}

void setupSens()
{
   resetDEnc();
   halt();
}

void calcRPM()
{
	maxFlyPow();
	getRPM();
}
void runAuton()
{
   setupSens();
	//Drive Forward
	//goForward(127);
	//wait1Msec(4000);
	//halt();

	////Turing 90deg left
	//turnLeft(127);
	//wait1Msec(1000);
	//halt();

	//goForward(127);
	//wait1Msec(4000);
	//halt();

	////Turing 90deg left
	//turnLeft(127);
	//wait1Msec(1000);
	//halt();
   //goStraightPID(45);
   calcRPM();
   halt();
}
