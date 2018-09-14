
#include "mainfile.c"



float minSpeed;
float encAvg;
float error;
float tolerance;
float kP;
float totalErrorD;
float kI;
float kD;
int gyroVal = 0;



float degToInch(float degree)
{
	float inch = ((2 * 3.14) * (degree/360));
	return inch;
}

void halt()
{
   motor[left1] = 0;
   motor[left2] = 0;
   motor[right1] = 0;
   motor[right2] = 0;

}

void rightMots(int power)
{
   motor[right1] = power;
   motor[right2] = power;
}

void leftMots(int power)
{
   motor[left1] = power;
   motor[left2] = power;
}

void forward(int power)
{
motor[left1] = power;
motor[right1] = power;
}

void resetDEnc()
{
   SensorValue[REnc] = 0;
   SensorValue[LEnc] = 0;
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

//gyro


void turn(int power, int degree)
{
	SensorValue[Gyro] = 0;
	if (degree < 0)
	{
		while(abs(SensorValue[Gyro]) < abs(degree * 10))
		{
			gyroVal = SensorValue[Gyro];
			motor[left1] = power;
			motor[right1] = -power;
		}
	}
	else
	{
		while(abs(SensorValue[Gyro]) < abs(degree * 10))
		{
			gyroVal = SensorValue[Gyro];
			motor[left1] = -power;
			motor[right1] = power;
		}
	}
}

void runAuto()
{
	SensorValue[Gyro] = 0;
	gyroVal = SensorValue[Gyro];

	forward(90);
	wait10Msec(200);
	halt();
	wait10Msec(50);
	turn(50,90);
	halt();
	wait10Msec(50);
	forward(127);
	wait10Msec(250);
	halt();
	wait10Msec(50);
	turn(50,90);
	forward(127);
	wait10Msec(463);
	halt();
}
