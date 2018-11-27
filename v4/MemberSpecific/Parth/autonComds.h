#include "Competitiontemplate.c"

void driveGo(int pwr)
{
	 motor[rightWheel] = pwr;
 	 motor[leftWheel] = pwr;
}
