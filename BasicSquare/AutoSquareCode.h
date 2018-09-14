?#include "Gyro.h"

void halt()
{
  motor[leftWheel] = 0;
	motor[rightWheel] = 0;
}

void forward(int power)
{
motor[rightWheel] = power;
motor[leftWheel] = power;
}

void runAuto()

{
	SensorValue[Gyro] = 0;
	gyroVal = SensorValue[Gyro];
	forward(90);
	wait10Msec(200);
	halt();
	wait10Msec(50);
	spin(100,50);
	halt();
	wait10Msec(50);
	forward(127);
	wait10Msec(250);
	halt();
	wait10Msec(50);
	spin(50,90);
	forward(127);
	wait10Msec(463);
	halt();

}
