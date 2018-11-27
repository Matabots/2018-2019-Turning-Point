#include "CompetitionMain.c"
#include "Commands.h"
#include "v2DriveControls.h"

task UARTReceive();

#define bytemax 1
#define deadzone 20
#define XC_BUFFER_SIZE 5
#define PIXY_BUFFER_SIZE 5
#define SONAR_BUFFER_SIZE 10
#define MAXPOWER 127
#define MIN_DISTANCE 100
#define TURNVALUE_HIGH 50
#define TURNVALUE_LOW 35
#define NOPOWER 0
int XC;
int XC_AVG_INDEX;
//int XC_AVG_BUFFER[XC_BUFFER_SIZE];
int XC_AVG_BUFFER[3];
int Pixy_Char;
int PIXY_AVG_INDEX;
int PIXY_AVG_BUFFER[PIXY_BUFFER_SIZE];
int SONAR_VALUE;
int SONAR_AVG_INDEX;
int SONAR_BUFFER[SONAR_BUFFER_SIZE];
int curr_pixy;
int powCount;

int c;
short data[bytemax];

int byteCheck(char c){
    if((c >= 48 && c <= 58)
    	return 1; //number or period found
    else
      return 0; //not a number
}

void moveUp(){
    clearTimer(T1);
    int stopTime = time1[T1] + 10000;

	while(XC == 2 && XC != 5 && time1[T1] <= stopTime && SONAR_VALUE < MIN_DISTANCE){
		//Set values to maxpower
	}

	halt();
}
int getAverage(int *values,int size){

	int avg = 0;
	int i = 0;

	for(i = 0; i < size; i++)
		avg += values[i];

	avg = avg/size;
	return avg;
}

task UARTReceive(){
    XC_AVG_INDEX = 0;
    //PIXY_AVG_INDEX = 0;
		while(true){

     Pixy_Char = getChar(uartOne);

    	if(byteCheck(Pixy_Char) == 1)
    	{ //found number or period
      // XC = (Pixy_Char - 48) * pow(10,powCount);
	     XC_AVG_BUFFER[XC_AVG_INDEX] = Pixy_Char - 48;
	     XC_AVG_INDEX++;
	  // if(XC_AVG_INDEX == XC_BUFFER_SIZE)
	//	   XC_AVG_INDEX = 0;

     //  XC = getAverage(XC_AVG_BUFFER,XC_BUFFER_SIZE);
	  	}
	  	else
	  	{
	  		XC = 0;
	  		for(powCount = 1; powCount >= 0 && XC_AVG_INDEX >= 0; powCount--)
	  		{
	  			XC = XC + (XC_AVG_BUFFER[c]);
	  			c--;
	  		}
	  		XC_AVG_INDEX = 0;
	  	}

	}
}


//task SensorReader(){
//	int SONAR_AVG_INDEX = 0;

//	while(true){

//		SONAR_BUFFER[SONAR_AVG_INDEX] = SensorValue[sonar];
//		SONAR_AVG_INDEX++;

//		if(SONAR_AVG_INDEX == SONAR_BUFFER_SIZE)
//			SONAR_AVG_INDEX = XC_AVG_INDXC_AVG_INDEX

//		SONAR_VALUE = getAverage(SONAR_BUFFER,SONAR_BUFFER_SIZE);
//	}
//}
task Drive()
{
	runController();
}


task FollowRoutine()
{

    while(true){

		//If Cone is not there
    if(XC == -1 || XC == 1)
    	continue;
   	else
   	{
     TurnTo(XC); //XD will be a degree
   	}
 //  //If the cone is to the left
	// else if(XC == 0){
	//		rotateRight_Adv();
	//		XC = 5;
	// }
	//  else if(XC == 1){
	//  	rotateRight_Adv();
	//    XC = 5;
	//  }
	//	//If Cone is in the front
	////	else if(XC == 2)
	//	//	moveUP();
	//	//If Cone is to the right
	//	else if(XC == 3){
	//		rotateLeft_Adv();
	//	  XC = 5;
	//	}
	//  else if(XC == 4){
	//		rotateLeft_Adv();
	//		XC = 5;
	//  }
		wait1Msec(200);
	}
}

task ToggleFollow(){
	 int t_switch = 1;
   while(true){
      if(vexRT[Btn7U] == 1 && t_switch == 1){
      	startTask(Drive);
         stopTask(FollowRoutine);
         t_switch = 0;
         wait1Msec(500);
      }
       if(vexRT[Btn7U] == 1 && t_switch == 0){
         stopTask(Drive);
         startTask(FollowRoutine);
         t_switch = 1;
         wait1Msec(500);
      }
  }

}
