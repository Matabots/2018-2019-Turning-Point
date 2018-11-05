#include "robot.h"
    //default constructor to allocate memory

    robot::robot(){
      this->drive = new chassis();
      this->analog = new analogSensors();
      this->digital = new digitalSensors();
      this->arm = new lift();
      this->ef = new roller();
      this->remote = new control();
      this->communications = new i2c();
      this->aMotor = new motor();
      this->robotState = ADJUSTHEIGHT;
      this->stackedCones = 0;
      this->targetStack = 0;
      this->uartComms = new botUart();
      this->hasMobileGoal = false;
    };
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////this function will often be changed and is at the top///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void robot::setupBot(){
      this->remote->setupcontrol();
      this->digital->set_leftLiftEncoder(digital3, digital4, false);
      this->digital->set_rightLiftEncoder(digital1, digital2, false);
      this->drive->addLeftMotor(motor1, true);
      this->drive->addLeftMotor(motor2, true);
      this->drive->addLeftMotor(motor3, false);
      this->drive->addRightMotor(motor7, false);
      this->drive->addRightMotor(motor9, true);
      this->drive->addRightMotor(motor10, true);

      imeReset(0);
      imeReset(1);
      imeReset(2);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////Setters and Getters///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    state robot::get_state(){
      return this->robotState;
    }
    void robot::set_communications(i2c communications){
      this->communications = &communications;
    };
    i2c* robot::get_communications(){
      return this->communications;
    };
    void robot::set_remote(control remote){
      this->remote = &remote;
    };
    control* robot::get_remote(){
      return this->remote;
    };
    void robot::set_drive(chassis drive){
      this->drive = &drive;
    };
    chassis* robot::get_drive(){
      return this->drive;
    };
    void robot::set_analog(analogSensors analog){
      this->analog = &analog;
    };
    analogSensors* robot::get_analog(){
      return this->analog;
    };
    void robot::set_digital(digitalSensors digital){
      this->digital = &digital;
    };
    digitalSensors* robot::get_digital(){
      return this->digital;
    };
    void robot::set_arm(lift arm){
      this->arm = &arm;
    };
    lift* robot::get_arm(){
      return this->arm;
    };
    void robot::set_ef(roller ef){
      this->ef = &ef;
    };
    roller* robot::get_ef(){
      return this->ef;
    };
    int robot::get_stackedCones(){
      return this->stackedCones;
    };
    int robot::get_targetStack(){
      return this->targetStack;
    };
    bool robot::get_mobileGoalStatus(){
      return this->hasMobileGoal;
    };
    void robot::set_mobileGoalStatus(bool mobileGoalStatus){
      this->hasMobileGoal = mobileGoalStatus;
    };

    void robot::set_targetStack(int coneHeight){
      this->targetStack = coneHeight;
    };
    long robot::get_IntakeTimer(){
        return this->intakeTimer;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////These are the operator control functions////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void robot::remoteListen(){
      autoAbort();
      printf("Remote Listening\n");
    };
    void robot::uart()
    {
      this->uartComms->runUART();
    }
    void robot::joystickInputs(){
      rightJoystick();
      leftJoystick();
    };
    void robot::leftJoystick(){
      if(this->remote->absLeftJoystickVal()>15){
  			this->drive->leftPower(this->remote->leftJoystickVal());
  		}else{
  			this->drive->haltLeft();
  		}
    };
    void robot::rightJoystick(){
      if(this->remote->absRightJoystickVal()>15){
  			this->drive->rightPower(this->remote->rightJoystickVal());
  		}else{
  			this->drive->haltRight();
  		}
    };
    void robot::rollerButtons(){
      if(this->remote->rollerOpen()){
        this->ef->set_Power(100);
        delay(50);
      }else if(this->remote->rollerClose()){
        this->ef->set_Power(-100);
        delay(50);
      }else{
        this->ef->halt();
      }
    };

    void robot::autoAbort(){
      if(this->remote->autoLiftAbort()){
        autoStacking = false;
        addReleased = false;
        addPressed = false;
        subtractPressed = false;
        subtractReleased = false;
        this->robotState = ADJUSTHEIGHT;
        this->targetStack = this->stackedCones;
        this->arm->primaryLiftPower(0);
        this->ef->set_Power(0);
        //this->arm->secondaryLiftPower(0);
      }
    };

    bool addReleased = false;
    bool addPressed = false;
    bool subtractPressed = false;
    bool subtractReleased = false;
    void robot::autonLiftProcess(){

        if(!autoStacking){
          printf("this is running");
          if(this->remote->autonLiftProcessAdd()){
            addPressed = true;
          }
          if(!this->remote->autonLiftProcessAdd()){
            addReleased = true;
          }
          if(this->remote->autonLiftProcessSubtract()){
            subtractPressed = true;
          }
          if(!this->remote->autonLiftProcessSubtract()){
            subtractReleased = true;
          }
          if(addPressed && addReleased && this->targetStack < 8){
            this->targetStack += 1;
            autoStacking = true;
          }
          if(subtractPressed && subtractReleased && this->stackedCones > 0 ){
            this->targetStack -= 1;
            this->stackedCones -=1;
            autoStacking = true;
          }
        }
        else{
          if(this->remote->get_team() == 2){
            autoLoadCSUN2();
          }
          else{
            autoLoad();
          }
          printf("lift is running");
        }

    };
    void robot::bigLift(){
      if(this->remote->get_team() == 2){
        printf("this is cusn2");
        if(this->remote->bigLift() == 1 ){
          this->arm->primaryLiftPower(100);
          printf("joy %d\n",this->remote->bigLift());
        }
        else if(this->remote->bigLift() == -1){
          this->arm->primaryLiftPower(-100);
          printf("joy %d\n",this->remote->bigLift());
        }
        else{
          this->arm->haltPrimaryLift();
        }
      }
      else{
        if(abs(this->remote->bigLift()) > 20){
          if(this->remote->bigLift() < 0 && average(this->get_digital()->leftLiftEncoderVal(),this->get_digital()->rightLiftEncoderVal()) < 25){
                this->arm->primaryLiftPower((int)(this->remote->bigLift()));//x/4
          }
          else{
            this->arm->primaryLiftPower(this->remote->bigLift());
          }
          delay(50);
        }else{
          this->arm->haltPrimaryLift();
        }
      }
    };

    bool toggleUp = true;
    void robot::smallLift(){
      // motorSet(5, speed);
      if(this->remote->smallLiftUp() ){
        this->arm->secondaryLiftPower(100);
        // if(this->analog->get_potentiometerVal() < 1800){
        //   toggleUp = false;
        // }
        delay(50);
      }
      else if(this->remote->smallLiftDown()){
        this->arm->secondaryLiftPower(-100);
        // if(this->analog->get_potentiometerVal() > 3000 ){
        //   toggleUp = true;
        // }
        delay(50);
      }
      else{
        this->arm->haltSecondaryLift();
      }
    };

    void robot::goalLift(){
      if(this->remote->goalLiftUp()){
        this->arm->goalLiftPower(100);
      }else if(this->remote->goalLiftDown()){
        this->arm->goalLiftPower(-100);
        delay(50);
      }else{
        this->arm->haltGoalLift();
      }
    };

    void robot::setLiftAboveStation(){
      if(this->remote->defaultPosition())
      {
        this->arm->primaryLiftPosition(40+CONE_HEIGHT, this->digital->leftLiftEncoderVal());
        this->arm->secondaryLiftPosition(SECONDARY_BOT, this->analog->get_potentiometerVal());
        if(this->arm->get_primaryLiftAt(0)->get_posPID()->get_error() != 0){
            //this->ef->set_Power(-100);
            this->arm->haltPrimaryLift();
            this->arm->haltSecondaryLift();
        }
      }
    };
    void robot::clearStack(){
      if(this->remote->clearConeStack()){
        this->stackedCones = 0;
      }
    }
  // void smallLift(){
  //     if(this->remote->smallLiftUp()){
  //       this->arm->groupTwoPower(100);
  //       delay(50);
  //     }else if(this->remote->smallLiftDown()){
  //       this->arm->groupTwoPower(-100);
  //       delay(50);
  //     }else{
  //       this->arm->haltGroupTwo();
  //     }
  //   };
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////Routines related to sensors will belong here////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void robot::resetGyro(){
      int previousValue = 0;
      this->analog->reset_gyro();
      this->analog->set_deltaGyro(0);
      this->drive->leftPower(0);
      this->drive->rightPower(0);
      previousValue = this->analog->gyro_val();
      delay(2000);
      this->analog->set_deltaGyro(this->analog->gyro_val() - previousValue);
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////Routines related to movement will belong here////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void robot::lowerGoalLift(){
  while(!this->arm->atBottom){
  this->arm->goalLiftDown();
  delay(50);
  }
};
void robot::timedLowerGoalLift(long timer)
{
  long startTime = millis();
  while((long)millis()-startTime <= timer)
  {
    this->arm->goalLiftPower(-127);
    delay(50);
  }
  this->arm->goalLiftPower(0);
  delay(10);
};

void robot::raiseGoalLift(){
  while(!this->arm->atTop){
    this->arm->goalLiftUp();
    delay(50);
  }
};
void robot::timedRaiseGoalLift(long timer)
{

  long startTime = millis();
  while(((long)millis()-startTime) <= timer)
  {
    this->arm->goalLiftPower(127);
    delay(50);
  }
  this->arm->goalLiftPower(0);
  delay(10);
};

void robot::driveIn(float inch)
{
imeReset(0);
imeReset(1);
unsigned long time1 =0;
delay(100);
time1 = millis();
if(this->get_remote()->get_team() == 2){
  inch /= 3;
}
  this->drive->atPos = false;
  while (!this->drive->atPos && (millis()-time1 < 3000)) {
    // time1 = millis();
    this->drive->moveDistance(inch);
    // if(this->get_drive()->getLeftMotorAt(0)->get_Power() <= 10){
    //   this->drive->haltRight();
    // }
    //printf("Go to:%f, Now at: %d\n", this->get_drive()->getLeftMotorAt(0)->get_posPID()->get_deadband(), abs(this->get_drive()->getLeftMotorAt(0)->get_posPID()->get_error()));
    delay(50);
  }
  this->drive->haltLeft();
  this->drive->haltRight();
  delay(100);
};

void robot::spinToAngle(int targetAngle)
{
unsigned long time1 =0;
  time1 = millis();
  this->drive->atGyro = false;
  while(!this->drive->atGyro && millis()-time1 < 1500){
    this->drive->spinToAngle(targetAngle, this->analog);
    printf("yaw: %d\n", this->analog->gyro_val());
    delay(50);
  }
  this->drive->haltLeft();
  this->drive->haltRight();
};
void robot::turnLeftToAngle(int targetAngle){
  imeReset(0);
  imeReset(1);
  this->drive->atGyro = false;
  while(!this->drive->atGyro){
    this->drive->turnLeftToAngle(targetAngle, this->analog);
    delay(50);
  }
  this->drive->haltLeft();
  this->drive->haltRight();
};
void robot::turnRightToAngle(int targetAngle){
  this->drive->atGyro = false;
  imeReset(0);
  imeReset(1);
  while(!this->drive->atGyro){
    this->drive->turnRightToAngle(targetAngle, this->analog);
    delay(50);
  }
  this->drive->haltLeft();
  this->drive->haltRight();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// #define SECONDARY_BOT  500
// #define SECONDARY_TOP 1400
// #define CONE_HEIGHT 10
// #define MAX_HEIGHT 8
int primaryBottomHeight = 1; //change between 3 and height of loading station at 45
unsigned long intakeTimer =0;

void robot::setPreloadHeight(){
  intakeTimer = millis();
if(this->get_remote()->get_team() == 1){
  while(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) < CONE_HEIGHT && millis()-intakeTimer < 2000)
  {
    this->arm->primaryLiftPosition(CONE_HEIGHT, average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()));
  }

  this->arm->haltPrimaryLift();
}
  if(this->get_remote()->get_team() == 2){
    while(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) < CONE_HEIGHT_CSUN2  && millis()-intakeTimer < 2000)
    {
      this->arm->primaryLiftPosition(CONE_HEIGHT_CSUN2, average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()));
    }

    this->arm->haltPrimaryLift();

  }
};

void robot::scorePreload(){
  this->ef->set_Power(75);
  delay(400);
  this->stackedCones++;
  this->ef->halt();
  this->ef->halt();
};
//set to true for loading in the preLoad area. false for picking up cones from the ground
void robot::set_primaryBottomHeight(bool toPreLoad){
  if(toPreLoad){
    primaryBottomHeight = 40;
  }
  else{
    primaryBottomHeight = 1;
  }
};

void robot::autoLoad(){
  if(this->stackedCones == this->targetStack){
    autoStacking = false;
    addReleased = false;
    addPressed = false;
    subtractPressed = false;
    subtractReleased = false;
  }
  if(this->stackedCones < this->targetStack && this->stackedCones < MAX_HEIGHT){
    switch(robotState){

          case ADJUSTHEIGHT:
            //Lower Secondary Lift to Lowest Position
            this->ef->halt();
            if(primaryBottomHeight == 40 && CONE_HEIGHT*(this->stackedCones) < primaryBottomHeight){
              this->arm->primaryLiftPosition(primaryBottomHeight, this->digital->leftLiftEncoderVal());
              if(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) >= primaryBottomHeight || millis()-intakeTimer > 2000){
                  robotState = BOTTOM;
                  //this->ef->set_Power(-100);
                  this->arm->haltPrimaryLift();
                  this->arm->haltSecondaryLift();
              }
            }
            else{
              this->arm->secondaryLiftPosition(SECONDARY_BOT, this->analog->get_potentiometerVal());
              if(this->analog->get_potentiometerVal() < SECONDARY_BOT){
                  intakeTimer = millis();
                  robotState = BOTTOM;
                  this->ef->set_Power(-100);
                  this->arm->haltPrimaryLift();
                  this->arm->haltSecondaryLift();
              }

            }

          break;
          case BOTTOM:
            //Move Primary lift to lowest position
            // if(this->stackedCones > 2){ //if the cone stack gets to high, lower the speed to drop a bit so it doesn't damage the bot
              this->arm->set_primaryLiftPosPID(5.0,0.0,0.0);
            // }
            this->arm->primaryLiftPosition(primaryBottomHeight,   (int)average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()));

            this->arm->secondaryLiftPosition(SECONDARY_BOT, this->analog->get_potentiometerVal());
            printf("At bottom\n");
            if((average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) <= primaryBottomHeight+2 && this->analog->get_potentiometerVal() < SECONDARY_BOT) || millis()-intakeTimer > 2000){

              intakeTimer = millis();
              robotState = INTAKE;
              this->arm->set_primaryLiftPosPID(9.0,0.0,0.0);
              this->arm->haltPrimaryLift();
              this->arm->haltSecondaryLift();
            }
          break;

          case INTAKE:
            //Intake Cone
            // if(this->analog->get_potentiometerVal() > SECONDARY_BOT || average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) > 7){
            //   robotState = BOTTOM;
            // }
            // printf("%ld\n", bot.intakeTimer);
            printf("Intaking\n");
            this->ef->set_Power(-100);
            if(this->digital->get_leftLimitSwitch() == 0 || this->digital->get_rightLimitSwitch() == 0 || millis()-intakeTimer > 2000){
              intakeTimer = millis();
              robotState = CONEHEIGHT;
              this->ef->halt();
            }
          break;
          //this is a change
          case CONEHEIGHT:
            //Raise Primary Lift to correct height (10deg/cone)

            this->arm->primaryLiftPosition(CONE_HEIGHT*(this->stackedCones+1),   (int)average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()));

            this->ef->halt();
            //Raise Secondary Lift to correct height
              if(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) >= CONE_HEIGHT*(this->stackedCones-1)|| millis()-intakeTimer > 2000){
                  this->arm->secondaryLiftPosition(SECONDARY_TOP, this->analog->get_potentiometerVal());
              }

            if((average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) >= CONE_HEIGHT*(this->stackedCones+1) && this->analog->get_potentiometerVal() > SECONDARY_TOP)|| millis()-intakeTimer > 3000){
              intakeTimer = millis();
              robotState = OUTTAKE;
              this->arm->haltSecondaryLift();
              this->arm->haltPrimaryLift();
              delay(500);
            }
          break;

          case OUTTAKE:
            //Outtake
            this->ef->set_Power(75);
            delay(400);
            this->ef->halt();
            if(isAutonomous() == false){
              robotState = RESTABOVE;
              intakeTimer = millis();
            }else{
              robotState = ADJUSTHEIGHT;
              intakeTimer = millis();
              this->stackedCones++;
              this->arm->haltPrimaryLift();
              this->arm->haltSecondaryLift();
            }
          break;
          case RESTABOVE:

            this->arm->secondaryLiftPosition(SECONDARY_BOT, this->analog->get_potentiometerVal());
            if(this->analog->get_potentiometerVal() < SECONDARY_BOT || millis()-intakeTimer > 3000)
            {
              this->arm->primaryLiftPosition(primaryBottomHeight + CONE_HEIGHT,   (int)average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()));
              if((average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderVal()) >= primaryBottomHeight+CONE_HEIGHT)|| millis()-intakeTimer > 2000)
              {intakeTimer = millis();
                  robotState = ADJUSTHEIGHT;
                  this->stackedCones++;
                  this->arm->haltPrimaryLift();
                  this->arm->haltSecondaryLift();
              }
            }
          break;
        };
      };
    };
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////CSUN 2 AUTO LOAD CODE////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #define SECONDARY_BOT_CSUN2  3300
// #define SECONDARY_TOP_CSUN2 1700
// #define CONE_HEIGHT_CSUN2 7
// #define MAX_HEIGHT 8
int primaryBottomHeightCSUN2 = 0; //change between 3 and height of loading station at 45

//set to true for loading in the preLoad area. false for picking up cones from the ground
void robot::set_primaryBottomHeightCSUN2(bool toPreLoad){
  if(toPreLoad){
    primaryBottomHeightCSUN2 = 20;
  }
  else{
    primaryBottomHeightCSUN2 = 0;
  }
};

  void robot::autoLoadCSUN2(){
    printState(robotState);

    if(this->stackedCones == this->targetStack){
      autoStacking = false;
      addReleased = false;
      addPressed = false;
      subtractPressed = false;
      subtractReleased = false;
    }
    if(this->stackedCones < this->targetStack && this->stackedCones < MAX_HEIGHT){
      switch(robotState){

            case ADJUSTHEIGHT:
              //Lower Secondary Lift to Lowest Position
              this->ef->halt();
              if(primaryBottomHeightCSUN2 == 20 && CONE_HEIGHT_CSUN2*(this->stackedCones) < primaryBottomHeightCSUN2){
                this->arm->primaryLiftPosition(primaryBottomHeightCSUN2, average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));
                printf("should not be running\n");
                if(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) >= primaryBottomHeightCSUN2){
                    intakeTimer = millis();
                    robotState = BOTTOM;
                    this->ef->set_Power(-100);
                    this->arm->haltPrimaryLift();
                    this->arm->haltSecondaryLift();
                }
              }
              else{
                this->arm->primaryLiftPosition(CONE_HEIGHT_CSUN2*(this->stackedCones), average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));
                this->arm->secondaryLiftPosition(SECONDARY_BOT_CSUN2, this->analog->get_potentiometerVal());
                printf("lift should be running\n");
                if(this->analog->get_potentiometerVal() < SECONDARY_BOT_CSUN2){
                    intakeTimer = millis();
                    robotState = BOTTOM;
                    this->ef->set_Power(-100);
                    printf("reached goal");
                    this->arm->haltPrimaryLift();
                    this->arm->haltSecondaryLift();
                }

              }

            break;
            case BOTTOM:
              //Move Primary lift to lowest position
              if(this->stackedCones > 2){ //if the cone stack gets to high, lower the speed to drop a bit so it doesn't damage the bot
                this->arm->set_primaryLiftPosPID(5.0,0.0,0.0);
              }

              this->arm->primaryLiftPosition(primaryBottomHeightCSUN2, average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));

              this->arm->secondaryLiftPosition(SECONDARY_BOT_CSUN2, this->analog->get_potentiometerVal());
              if((average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) <= primaryBottomHeightCSUN2 && this->analog->get_potentiometerVal() < SECONDARY_BOT_CSUN2) || millis()-intakeTimer > 1500){
                intakeTimer = millis();
                robotState = INTAKE;
                this->arm->set_primaryLiftPosPID(9.6,0.0,0.002);//.0025
                this->arm->haltPrimaryLift();
                this->arm->haltSecondaryLift();
              }
            break;

            case INTAKE:
              //Intake Cone
              // if(this->analog->get_potentiometerVal() > SECONDARY_BOT_CSUN2 || average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) > 7){
              //   robotState = BOTTOM;
              // }
              this->ef->set_Power(-100);
              if(this->digital->get_leftLimitSwitch() == 0 || millis()-intakeTimer > 1000){
                intakeTimer = millis();
                 robotState = CONEHEIGHT;
                this->ef->halt();
              }
            break;
            //this is a change
            case CONEHEIGHT:
              //Raise Primary Lift to correct height (10deg/cone)

              this->arm->primaryLiftPosition(CONE_HEIGHT_CSUN2*(this->stackedCones+1), average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));

              this->ef->halt();
              //Raise Secondary Lift to correct height
                if(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) >= CONE_HEIGHT_CSUN2*(this->stackedCones-1)){
                    this->arm->secondaryLiftPosition(SECONDARY_TOP_CSUN2, this->analog->get_potentiometerVal());
                }

              if((average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) > CONE_HEIGHT_CSUN2*(this->stackedCones+1) && this->analog->get_potentiometerVal() > SECONDARY_TOP_CSUN2)|| millis()-intakeTimer > 2000){
                intakeTimer = millis();
                robotState = OUTTAKE;
                this->arm->haltSecondaryLift();
                this->arm->haltPrimaryLift();
                delay(250);
              }
            break;

            case OUTTAKE:
              //Outtake
              this->ef->set_Power(75);
              delay(400);
              this->ef->halt();
              if(isAutonomous() == true){
                robotState = RESTABOVE;
              }else{
                robotState = ADJUSTHEIGHT;
                this->stackedCones++;
              }
            break;

            case RESTABOVE:

              this->arm->secondaryLiftPosition(SECONDARY_BOT_CSUN2, this->analog->get_potentiometerVal());
              this->arm->primaryLiftPosition(CONE_HEIGHT_CSUN2*(this->stackedCones+1), average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));
              if(this->analog->get_potentiometerVal() < SECONDARY_BOT)
              {
                this->arm->haltSecondaryLift();
                this->arm->primaryLiftPosition(primaryBottomHeight + CONE_HEIGHT_CSUN2, average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()));
                if(average((double)this->digital->leftLiftEncoderVal(),(double)this->digital->rightLiftEncoderValModern()) >= primaryBottomHeight+CONE_HEIGHT_CSUN2)
                {
                    robotState = ADJUSTHEIGHT;
                    this->stackedCones++;
                    this->arm->haltPrimaryLift();
                    this->arm->haltSecondaryLift();
                }
              }
            break;
          };
        };
      };
