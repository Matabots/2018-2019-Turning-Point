//File for math functions

float currDeg = 0;
int encAvg;
int encVal;
int numRot;

//float degToInch(float degree)
//{
//	float inch = ((2 * 3.14) * (degree/360));
//	return inch;
//}

int rpmCalc(int currRev)
{
	wait10Msec(6000);
	return currRev;

}

void getRPM()
{
	encAvg = ((SensorValue[flyEnc]) % 3600);
	if (encVal == 0)
	{
		numRot++;
	}
}
