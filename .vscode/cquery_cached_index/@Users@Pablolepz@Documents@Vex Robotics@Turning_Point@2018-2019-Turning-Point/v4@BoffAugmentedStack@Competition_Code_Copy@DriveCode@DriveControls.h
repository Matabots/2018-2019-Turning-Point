/*
Drive Functions (some code taken from Jeff (Robot 1)/Teleoperated Control.h"
*/

#define DEADZONE 15
bool turning = false;
int potentVal = 0;

struct Controller
{
	TVexJoysticks stack;
	TVexJoysticks rightMotors;
	TVexJoysticks	leftMotors;
	TVexJoysticks	clawOpen;
	TVexJoysticks clawClose;
	TVexJoysticks goalLift;
	TVexJoysticks resetStack;
};

Controller controller;

void setupController()
{
	controller.stack = Btn7U; //activate lift
	controller.rightMotors = Ch2;	//move the right side of the robot
	controller.leftMotors = Ch3;	//move the left side of the robot
	controller.clawOpen = Btn6U;	//open claw
	controller.clawClose = Btn6D;	//close claw
	controller.goalLift = Btn8R;	//lift/lower the goal
	controller.resetStack = Btn7L; //reset stack #
}
int currentStack = 0;
enum Mode
{
	 TANK = 0,
	 ARCADE =1
};

void autoClaw()
{
	/*
  while(abs(SensorValue[CMEnc]) < 90)
	{
	  motor[CMot] = 127;
  }
  motor[CMot] = 0;


	motor[CMot] = -127;
	wait10Msec(80);
	motor[CMot] = 0;*/
}

/*void autoLift(int degr)
{
	while(abs(SensorValue[stackEnc]) <= degr)
	{
  	motor[LiftMot] = -127;
  }
	motor[LiftMot] = 0;
	autoClaw();

	while(abs(SensorValue[stackEnc]) >= 0)
	{
		motor[LiftMot] = 127;
  }
  motor[LiftMot] = 0;
  currentStack = currentStack + 1;
}*/


void MoveClaw()
{
	if(vexRT[Btn7D] == 1 && (SensorValue[Potent] > potentVal - 200)) //&& abs(SensorValue[CMEnc]) < 90)
	{ //open
		motor[CMot] = 127;
  }
  else if(vexRT[Btn7R] == 1 && (SensorValue[Potent] < (potentVal + 1000))) //&& abs(SensorValue[CMEnc]) > 0)
  { //close
    motor[CMot] = -127;
  }
  else
  {
  	motor[CMot] = 0;
  }
}

/*
void MoveLift()
{
	//moves stacker up to 4 cones
	if(vexRT[controller.stack])
	{
	  switch ( currentStack )
	 	{
		case 0:
		    autoLift(180);// needs to turn 230 degrees *Not including drift*
			break;
		case 1:
				autoLift(180);
			break;
		case 2:
				autoLift(180);
			break;
		case 3:
				autoLift(180);
			break;
		case 4:
				autoLift(140);
		  break;
	  }
  }
}
*/

void MoveChassis()
{

	if (abs(vexRT[controller.rightMotors]) > DEADZONE)
	{
		motor[RMots1] = n*vexRT[controller.rightMotors];
		motor[RMots2] = n*vexRT[controller.rightMotors];
		motor[RMots3] = n*vexRT[controller.rightMotors];
	}
	else
	{
		motor[RMots1] = 0;
		motor[RMots2] = 0;
		motor[RMots3] = 0;
	}
	if (abs(vexRT[controller.leftMotors]) > DEADZONE)
	{
		motor[LMots1] = n*vexRT[controller.leftMotors];
		motor[LMots2] = n*vexRT[controller.leftMotors];
		motor[LMots3] = n*vexRT[controller.leftMotors];
	}
	else
	{
		motor[LMots1] = 0;
		motor[LMots2] = 0;
		motor[LMots3] = 0;
	}
}
void resetStackerNum()
{
	if(vexRT[controller.resetStack])
	{
		currentStack = 0;
  }
}
void liftBase()
{
		if (vexRT[Btn5U] == 1 && (SensorValue[LimL1] == 0 && SensorValue[LimR1] == 0))
		{
			motor[MobMots1] = -127;
			motor[MobMots2] = -127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[MobMots1] = 127;
			motor[MobMots2] = 127;
		}
		else
		{
			motor[MobMots1] = 0;
			motor[MobMots2] = 0;
		}
}
void SensCheck()
{
	if (turning == false)
  {
		SensorValue[Gyro] = 0;
  }
}
void SetupSens()
{
	SensorValue[LEnc] = 0;
	SensorValue[REnc] = 0;
	SensorValue[Gyro] = 0;
  SensorValue[stackEnc] = 0;
  potentVal = SensorValue[Potent];
}

void runController(const Mode mode = TANK)
{
	MoveChassis();
	SensCheck();
	//MoveLift(); //not working correctly (Adrian 11/24/2017)
	MoveClaw();
	liftBase();
	resetStackerNum();
}
