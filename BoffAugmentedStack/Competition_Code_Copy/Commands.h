/*
  Commands list
*/
#include "Variables.h"
#include "AutonCommands.h"
#include "CompetitionMain.c"


void tasksFinished()
{
	while(!atGyro)
	{
	}
}

void MoveArm()// to targetDeg
{
	minS = 20;
	target = targetDeg;
	error = target - pitch;	//error is the difference between the goal and current distance
	float prevError = 0;
	float kD = 200;

	tolerance = 3;	//how accurate do I want the robot to be was at .25
  if (cone) {
    kp = 1.7; //was 1.8
    minS = 30;
    tolerance = 10;
  } else  {
	  kp = 1.2;		//Kp is a multiplier to calibrate the power //1.3 works
  }
  if (target == 0) {
  	minS = 20;
  	tolerance = 5;
  	kp = 1.7;
  }
  if (targetDeg == firstCone) //was currentStack, but that caused issues
  {
    kp = 2.0;
    kD = 400;
    tolerance = 20; //was originally 8
  }
	totalError= 0;
	ki = 0;
	time1[T1] = 0;
  time1[T2] = 0;
	while(same )//&& time1[T1] < 5000)
		{
			enc = SensorValue[stackEnc];
			pitch = enc + offSet;
			error = target - pitch;
			float motSpeed;
			if (target == 0)
		  {
		    motSpeed = -((error * kp) + (totalError * ki) + ((error - prevError) * 0/*kD*/)) ;//constantly updates as I get closer to target
		  } else {
			  motSpeed = -((error * kp) + (totalError * ki) + ((error - prevError) * kD)) ;//constantly updates as I get closer to target
		  }
			if (abs(motSpeed) < minS)
			{
			  if (motSpeed < 0) {
			    motor[LiftMot] = -minS;
			  } else {
			    motor[LiftMot] = minS;
			  }
			}
		  else
		  {

		  		motor[LiftMot] = motSpeed;

		  }
			if(abs(error) < tolerance*50)
			{
					//kD = 20;
				//	ki = 1;
			}
			if(abs(error)>tolerance)
			{
		 		time1[T1] = 0;
			}
				//motor power limits itself to 127 if too large.
				//check to make sure the robot is not stalling before it reaches the target point
					//Note: stalling is either from Kp being too low and doesn't have enough power to push last bit of distance
					//Note: You can eliminate stalling with a minimum speed limit i.e: if(error*kp < MIN){ motor[port[1]] = MIN};

				//*****STEPS TO CALIBRATE Kp*****
				//1. keep increasing Kp until the robot starts to oscillate about the target point physically
				//2. once Kp oscillates, decrease Kp a little so it is stable
		  totalError += error;
		  prevError = error;
	    if (targetDeg != target)
	    {
	    	same = false;
	    }
		}
		lastPost = targetDeg;
		same = true;

}
void AutoClaw(int IO) //0 is open, 1 is closed
{
	//open claw
	switch(IO)
	{
  case 0:
    //time1[T1] = 0;
    //while(/*(SensorValue[Potent] > potentVal - 275) &&*/ (time1[T1] < 1500))
    //{
		  motor[CMot] = -127;
	  //}
		wait10Msec(90);
    motor[CMot] = -20;
    //wait10Msec(80);
    cone = false;
  	break;

  case 1:

    cone = true;
    motor[CMot] = 30;
  	break;
  }
}

void AutoLift()
{
	float oldDeg;
	{
	  switch ( currentStack )
	 	{
		case 0:
		  oldDeg = targetDeg;

		  AutoClaw(1);

	    targetDeg = firstCone;
			wait10Msec(165);

	    AutoClaw(0);
	    wait10Msec(20);

			targetDeg = oldDeg;
			same = false;// goes back to old position

			break;

		case 1:
		  oldDeg = targetDeg;

		  AutoClaw(1);

	    targetDeg = secondCone;
			wait10Msec(150);

	    AutoClaw(0);
	    wait10Msec(50);

			targetDeg = oldDeg;
			break;

		case 2:
		  oldDeg = targetDeg;

		  AutoClaw(1);

	    targetDeg = thirdCone;
			wait10Msec(130);

	    AutoClaw(0);
	    wait10Msec(50);

			targetDeg = oldDeg;
			break;
	  }
	  currentStack++;
  }
}
void StackGro()
{
  targetDeg = -138;
}
void StackLoad()
{
	targetDeg = -80;
}
void StackNeut()
{
	targetDeg = 0;
	currentStack = 0;
}


//-----------------------------------GyroScope
float degToInt(float deg)
{
	return ((deg * (3.14 * 4))/107);
}
void reSetDEnc()
{
	SensorValue[REnc] = 0;
	SensorValue[LEnc] = 0;
}
void reSetGyro() // probably not needed
{
  SensorValue[Gyro] = 0;
}
void Right(int speed)
{
	motor[RMots1] = speed;
  motor[RMots2] = speed;
	motor[RMots3] = speed;
}
void Left(int speed)
{
	motor[LMots1] = speed;
	motor[LMots2] = speed;
	motor[LMots3] = speed;
}
void Halt()
{
	Right(0);
	Left(0);
}

void GyroCalibrate()
{
 //calibrate
 /*SensorType[Gyro] = sensorNone;
 wait1Msec(100);
 //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
 SensorType[Gyro] = sensorGyro;
 wait1Msec(2000);

//Adjust SensorScale to correct the scaling for your gyro
 SensorScale[in1] = 260;
 //Adjust SensorFullCount to set the "rollover" point. 3600 sets the rollover point to +/-3600
 SensorFullCount[in1] = 3600;*/
 SensorValue[Gyro]=0;
	float prevGyro;
	time1[T1] = 0;
  while(time1[T1] < 2000)
  {
	  Halt();
		prevGyro = gyroVal;
		wait1Msec(10);
		gyroVal = SensorValue[Gyro];
		deltaGyro = (gyroVal - prevGyro);
	}
}

void SetupSens()
{
	GyroCalibrate();
	targetDeg = 0; //PID arm setup to neutral
	SensorValue[LEnc] = 0; //may affect lift , unsure
	SensorValue[REnc] = 0;
	reSetGyro();
	targetGyro = 0;
  SensorValue[stackEnc] = 0; //may affect lift enc, unsure
  potentVal = SensorValue[Potent];
  Halt();
}
void setGyroInGame()
{
	gyroOn = false;
	GyroCalibrate();
	reSetGyro();
	targetGyro = 0;
	Halt();
	gyroOn = true;
}

void GyroUpdate()
{
	gyroVal = ((SensorValue[Gyro]) - deltaGyro)/10;
}

void moveGyro()
{
	atGyro = false;
  int tolerance = 8;//7
	float KpT = 0.85;// was 0.8
	GyroUpdate();
	float difference = (targetGyro - gyroVal);

		time1[T1] =0;
		while(abs(difference) > tolerance)// || time1[T1] > 500)
		{
				GyroUpdate();
			  difference = (targetGyro - gyroVal);
        //calculate to see if it is faster to turn left or right
        if(difference > 180)
        {
                difference -= 360;
        }
        if(difference < -180)
        {
                difference += 360;
        }
        if(abs(difference)>tolerance)
        {
        	time1[T1] =0;
        }
        int power = difference * KpT;

        power = power < -100 ? -100 : power;
        power = power > 100 ? 100 : power;
        if(power < 0 && power > -25)
        {
        	power = -25*KpT;
        }
        if(power > 0 && power<25)
        {
        	power = 25*KpT;
      	}

        motor[LMots1] = -power;
        motor[LMots2] = -power;
        motor[LMots3] = -power;

        motor[RMots1] = power;
        motor[RMots2] = power;
        motor[RMots3] = power;
        delay(10);
		}
		atGyro = true;
}
void TurnTo(float input)
{
	targetGyro = input;
}

void PIDDrive(float targetIn) //using drive to? not continuous
{
	reSetDEnc();
	minGo = 9;
	encAvg = 0;
	errorD = targetIn - encAvg;	//error is the difference between the goal and current distance

	toleranceD =3.7; //3.7;	//how accurate do I want the robot to be was at .25
  kp2 = 4.1;
	totalErrorD = 0;
	ki2 = 0;
	kd2 = 0;
	time1[T3] = 0;
	float dSpeed =0;
	SensorValue[REnc]=0;
	float gyroOrig = gyroVal;
	float gyroCorr = 3;//3.5
	while(abs(errorD) > toleranceD || (time1[T3] < 1000))
		{
			//SensorValue[(tSensors) 10 ] = 1;
			//encAvg = (((SensorValue[REnc]) + (SensorValue[LEnc]))/2);
			errorD = targetIn - degToInt(SensorValue[LEnc]);
		  dSpeed = errorD * kp2;// + (totalErrorD * ki2) + ((errorD - prevErrorD) * kd2)) ;//constantly updates as I get closer to target

		  if (abs(dSpeed) < minGo)
			{
				 dSpeed = dSpeed/abs(dSpeed);
			   Right((minGo*dSpeed)+(gyroOrig-gyroVal)*gyroCorr);
			   Left((minGo*dSpeed)-(gyroOrig-gyroVal)*gyroCorr);
			}
		  else
		  {
		  		Right(dSpeed+(gyroOrig-gyroVal)*gyroCorr);
			    Left(dSpeed-(gyroOrig-gyroVal)*gyroCorr);
		  }
			//if(abs(errorD) < toleranceD*50)
			//{
			//		//kD = 20;
			//	//	ki = 1;
			//}
			if(abs(errorD) > toleranceD)
			{
		 		time1[T3] = 0;
			}
		}
	Halt();
	  //}

		//Things to know about P Controllers
		//
}

//------------------Mobile Goal Lift --------------
void oldtinyLiftDown(float time)
{
	  motor[MobMots1] = 127;
    motor[MobMots2] = 127;

	  wait10Msec(time * 100);

	  motor[MobMots1] = 0;
	  motor[MobMots2] = 0;
}

void tinyLiftDown(float time)
{
	timeVal = time;
  mobDown = true;
  wait10Msec(40);
}
void tinyLiftUp()
{
  mobUp = true;
  wait10Msec(40);
}
void tinyLiftUpTmp(float time)
{
	motor[MobMots1] = -127;
  motor[MobMots2] = -127;

  wait10Msec(time * 100);

  motor[MobMots1] = 0;
	motor[MobMots2] = 0;

}

void checkMobile()
{
  if (mobUp)
  {
  	while(SensorValue[LimL1] == 0 && SensorValue[LimR1] == 0)
	  {
      motor[MobMots1] = -127;
      motor[MobMots2] = -127;
    }
    motor[MobMots1] = 0;
	  motor[MobMots2] = 0;
  }
  else if (mobDown)
  {
    motor[MobMots1] = 127;
    motor[MobMots2] = 127;

	  wait10Msec(timeVal * 100);

	  motor[MobMots1] = 0;
	  motor[MobMots2] = 0;
  }
  mobUp = false;
  mobDown = false;
}

void score(float leftP, float rightP, float sec)
{
	time1[T2] = 0;
	while (time1[T2] < (sec * 1000))
	{
  	Right(rightP);
	  Left(leftP);
	}
	Halt();
}
void driveBack(float leftP, float rightP, float sec)
{
	time1[T2] = 0;
	while (time1[T2] < (sec * 1000))
	{
  	Right(-leftP);
	  Left(-rightP);
	}
	Halt();
}
void PreLoad()
{
  motor[CMot] = 30;
  //delay lift
  targetDeg = pitch;
  wait10Msec(50);
  targetDeg = 0;
}
//-----------------Temporary, for Line Sensors
void ToLine(float targetIn) //using drive to? not continuous
{
	reSetDEnc();
	minGo = 9;
	encAvg = 0;
	errorD = targetIn - encAvg;	//error is the difference between the goal and current distance

	toleranceD =3.7; //3.7;	//how accurate do I want the robot to be was at .25
  kp2 = 4.1;
	totalErrorD = 0;
	ki2 = 0;
	kd2 = 0;
	time1[T3] = 0;
	float dSpeed =0;
	SensorValue[REnc]=0;
	float gyroOrig = gyroVal;
	float gyroCorr = 3;//3.5
	while(abs(errorD) > toleranceD || (time1[T3] < 1000))
		{
			//SensorValue[(tSensors) 10 ] = 1;
			//encAvg = (((SensorValue[REnc]) + (SensorValue[LEnc]))/2);
			errorD = targetIn - degToInt(SensorValue[LEnc]);
		  dSpeed = errorD * kp2;// + (totalErrorD * ki2) + ((errorD - prevErrorD) * kd2)) ;//constantly updates as I get closer to target

		  if (abs(dSpeed) < minGo)
			{
				 dSpeed = dSpeed/abs(dSpeed);
			   Right((minGo*dSpeed)+(gyroOrig-gyroVal)*gyroCorr);
			   Left((minGo*dSpeed)-(gyroOrig-gyroVal)*gyroCorr);
			}
		  else
		  {
		  		Right(dSpeed+(gyroOrig-gyroVal)*gyroCorr);
			    Left(dSpeed-(gyroOrig-gyroVal)*gyroCorr);
		  }
			//if(abs(errorD) < toleranceD*50)
			//{
			//		//kD = 20;
			//	//	ki = 1;
			//}
			if(abs(errorD) > toleranceD)
			{
		 		time1[T3] = 0;
			}
			if(!lineFound && ((SensorValue[lineSens1] < 1500 )||(SensorValue[lineSens2] < 1500 )||(SensorValue[lineSens3] < 1500 )))
			{
				targetIn = encAvg;
				lineFound = true;
			}
		}
	Halt();
}
