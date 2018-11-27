#include "autonComds.h"
#include "Competitiontemplate.c"

void autonGo()
{
	 SensorValue[Enc] = 0;
	 while(SensorValue[Enc] < 720)
	 {
 			driveGo(127);
	 }
}
