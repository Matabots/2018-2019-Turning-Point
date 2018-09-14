bool onOff = false;

void runMot(int power, int degree)
{
	if (onOff == true)
	{
		if (SensorValue[enc1] > degree)
		{
			motor[LDrive] = 0;
			onOff = false;
			SensorValue[enc1] = 0;
		}
	}
	if(SensorValue[limswitch1] == 1)
	{
		if(onOff == false)
		{
			motor[LDrive] = power;
			onOff = true;
		}
		else
		{
			motor[LDrive] = 0;
			onOff = false;
		}
		wait1Msec(500);
	}
}
//void go(int power)
//{
//	motor[LDrive] = power;
//	motor[RDrive] = power;
//}

//void lTurn(int power)
//{
//	motor[RDrive] = power;
//}

//void rTurn(int power)
//{
//	motor[LDrive] = power;
//}
//void halt()
//{
//	motor[LDrive] = 0;
//	motor[RDrive] = 0;
//}



void autonGo()
{

	while(true)
	{
		runMot(20, 720);
	}
	//go(127);
	//wait1Msec(3000);
	//halt();
	//wait1Msec(400);
	//rTurn(80);
	//wait1Msec(1000);
	//halt();
	//wait1Msec(400);
	//go(100);
	//wait1Msec(3000);
	//halt();
	//wait1Msec(400);
	//motor[LDrive] = 90;
	//wait1Msec(1000);
	//go(100);
	//wait1Msec(2000);
	//motor[LDrive] = 0;
	//motor[RDrive] = 0;
	//wait1Msec(400);
	//motor[LDrive] = 80;
	//wait1Msec(1000);
	//motor[LDrive] = 0;
	//wait1Msec(400);
	//motor[LDrive] = 100;
	//motor[RDrive] = 100;
	//wait1Msec(3000);
	//motor[LDrive] = 80;
	//wait1Msec(1000);
	//motor[LDrive] = 0;
	//wait1Msec(400);
}
