#include "motor.h"

  motor::motor(){
    this->power = 0;
    this->reversed = false;
    this->imeReversed = false;
    this->type = TORQUE;
    this->targetVel = 0;
    this->prevTime = millis();
    this->prevCount = 0;
    this->velPID = new pid();
    this->posPID = new pid();
    set_freeRPM();
  };
  motor::motor(int motorPort, double kPInput, double kIInput, double kDInput, double kFInput){
    this->port = motorPort;
    this->power = 0;
    this->reversed = false;
    this->imeReversed = false;
    this->type = TORQUE;
    set_freeRPM();
    this->targetVel = 0;
    this->prevTime = millis();
    this->prevCount = 0;
    this->velPID = new pid(kPInput,kIInput,kDInput,kFInput);
    this->posPID = new pid(kPInput,kIInput,kDInput,kFInput);
  };
  motor::motor(int motorPort, unsigned char encoderAddress, double kPInput, double kIInput, double kDInput, double kFInput){
    this->address = encoderAddress;
    this->port = motorPort;
    this->power = 0;
    this->targetVel =0;
    this->reversed = false;
    this->imeReversed = false;
    this->prevCount = 0;
    this->type = TORQUE;
  //  set_freeRPM();
    this->prevTime = millis();
    this->velPID = new pid(kPInput,kIInput,kDInput,kFInput);
    this->posPID = new pid(kPInput,kIInput,kDInput,kFInput);
  };

  void motor::set_targetVelocity(int vel){
    if(vel >= this->freeRPM){
      (this->targetVel) = this->freeRPM;
    }
    else{
      (this->targetVel) = vel;
    }
  }
  int motor::get_targetVelocity(){
    return this->targetVel;
  }
  int motor::get_velocity(){
    if(imeGetVelocity(this->address,&this->velocity)){
      this->velocity = imeVelocity((this->velocity), this->type);
      return (this->velocity);
    }else{
      printf("Unable to retrive velocity of encoder");
      return -1;
    };
  };  //control the motor to spin at a certain veloctiy

  int motor::get_targetCount(){
    return targetCount;
  }
  void motor::set_targetCount(int tCount){
    this->targetCount = tCount;
  }

  int motor::get_velocity(Encoder* encoderValue){
    double delta_ms;
    double delta_enc;
    double motor_velocity;
    double ticks_per_rev; //encoder
      ticks_per_rev = 360;
      // Get current encoder value
      // how many mS since we were last here
      double mil = millis();
      delta_ms = (mil-(prevTime));
      this->prevTime = (mil);
      // Change in encoder count
      delta_enc = encoderGet(*encoderValue) - (this->prevCount);
      // save last position
      this->prevCount = encoderGet(*encoderValue);
      //lcdPrint(uart1, 1, "dX:%d DX:%d dT:%d",this->prevCount, encoderValue, this->prevTime);
      // Calculate velocity in rpm
      motor_velocity = ((1000.0*60 )/delta_ms)*(delta_enc/ticks_per_rev);
      // multiply by any gear ratio's being used
      this->velocity =  (int)(motor_velocity/2);
      return (this->velocity);
  };
  void motor::set_velPID(double kPInput, double kIInput, double kDInput, double kFInput){
    this->velPID = new pid(kPInput,kIInput,kDInput,kFInput);
  }
  void motor::set_velPID(pid* controller){
    this->velPID = controller;
  }
  pid* motor::get_velPID(){
    return this->velPID;
  }
  void motor::set_posPID(pid* controller){
    this->posPID = controller;
  }
  pid* motor::get_posPID(){
    return this->posPID;
  }
  void motor::set_freeRPM(){
    this->freeRPM = 100; //Torque: free spin [rpm]
    if(this->type == HIGHSPEED){
      this->freeRPM = 160;
    }
    if(this->type == TURBO){
      this->freeRPM = 240;
    }
  };
  int motor::get_freeRPM(){
    return this->freeRPM;
  }
  motorType motor::get_motorType(){
    return this->type;
  }
  void motor::set_motorType(motorType mType){
    this->type = mType;
  }
  unsigned char motor::get_address(){
    return this->address;
  };
  void motor::set_address(unsigned char add){
    this->address = add;
  }
  bool motor::get_imeReversed(){
    return this->imeReversed;
  };
  void motor::set_imeReversed(bool val){
    this->imeReversed = true;
  };

  int motor::get_count(){
    // imeGet(this->address, &this->count);
    // return this->count;
    if((this->imeReversed)==false){
      if(imeGet(this->address, &this->count)){
        return (this->count);
      }
    }
    else if(this->imeReversed == true){
      if(imeGet(this->address, &this->count)){
        return (-1 * this->count);
      }
    }
      printf("Unable to retrive value of encoder");
      return -1;

  };

  int motor::get_prevCount(){
      return this->prevCount;
  };

  int motor::get_prevTime(){
    return this->prevTime;
  };

  void motor::reset_encoder(){
    imeReset(this->address);
  };
  void motor::set_encoderPort(int encoderPort){
    this->address = encoderPort;
  };
  unsigned char motor::get_encoderPort(){
    return this->address;
  };

  void motor::set_Port(int motorPort){
    this->port = motorPort;
  };
  int motor::get_Port(){
    return this->port;
  }
  void motor::set_Power(int motorPower){
    this->power = motorPower;
    if(this->reversed == false){
      motorSet(this->port, this->power);
    }else{
      motorSet(this->port, (this->power * -1));
    }
  };
  int motor::get_Power(){
    return this->power;
  };
  void motor::set_Direction(bool motorReversed){
    this->reversed = motorReversed;
  };
  bool motor::get_Direction(){
    return this->reversed;
  };
  int motor::get_Speed(){
    return motorGet(this->port);
  };
  void motor::set_type(motorType motor){
    this->type = motor;
  };

  void motor::velocityControlIME(int setPoint){
    // int dt = millis()-prevTime;
    // dt = dt/1000;
    // this->prevTime = millis();
    //set_Power(50);
    double dt = 50;
    set_targetVelocity(setPoint);
    this->velPID->set_setPoint(this->targetVel);
    this->velocity = get_velocity();
    double vel_output = this->velocity+(this->velPID->calculateOutput(this->velocity,dt));
    //calculate velocity based on
    if(abs(this->velPID->get_setPoint()-(this->velocity))>(this->velPID->get_deadband())){
      set_Power(vel_output);
      printf("PID: %f \n",this->velPID->get_kP());
      printf("trg: %d \n", setPoint);
    }
  };

  void motor::velocityControl(Encoder* enc, int setPoint){
    // int mil = millis();
    // double dt = mil-this->prevTime;
    // this->prevTime = mil;
    double dt = 50;
    set_targetVelocity(setPoint);
    this->velPID->set_setPoint(this->targetVel);
    //lcdPrint(uart1, 2, "tV: %f", (double)this->velPID->get_setPoint());
    this->velocity = get_velocity(enc);
    double vel_output = this->velocity+(this->velPID->calculateOutput(this->velocity,dt));//*(this->freeRPM); //the speed of the robot
    //calculate velocity based on
    if(abs(this->velPID->get_setPoint()-(this->velocity)) > (this->velPID->get_deadband())){
      set_Power(vel_output);
    }
  };
  //control the motor to spin to a target degree
  void motor::positionControlIME(double setPointIn){
    double dt = 50;

    this->posPID->set_setPoint(setPointIn);
    this->count = get_count();
    double in = ticksToRotations(this->count,this->type)*(3.14*4);
    printf("in: %f\n",in);
    printf("trgtIn: %f\n",setPointIn);
    printf("dead: %f",this->posPID->get_deadband());
    // // printf("PID: %f \n",this->posPID->get_kP());
    // // printf("trg: %f \n", setPointDeg);
    double vel_output = this->posPID->calculateOutput(in, dt);
    vel_output = vel_output < 40 && vel_output > 0? 40 : vel_output;
    vel_output = vel_output > -40 && vel_output < 0 ? -40 : vel_output;
    if(abs(setPointIn-in) > (this->posPID->get_deadband())){
      set_Power(vel_output); //replace with velocity control when you get chance
      //printf("vel: %f",vel_output);
    //  printf("vel: %f \n",vel_output);
    }
    else{
      set_Power(0);
    }
  };

  //control the motor to spin to a target degree
  void motor::tickControl(double setPointDeg, double currTick){
    double dt = 50;
    double rotations = setPointDeg/360;
    int setPointCount = rotationsToTicks(rotations, this->type);
    set_targetCount(setPointCount);
    //printf("setPt: %d \n", this->targetCount);
    this->posPID->set_setPoint(this->targetCount);
    this->count = currTick;
    // // printf("PID: %f \n",this->posPID->get_kP());
    // // printf("trg: %f \n", setPointDeg);
    double vel_output = this->posPID->calculateOutput(this->count, dt);
    if(abs(this->posPID->get_setPoint()-(this->count)) > (this->posPID->get_deadband())){
      set_Power(vel_output); //replace with velocity control when you get chance
      //printf("vel: %f",vel_output);
    //  printf("vel: %f \n",vel_output);
    }
  };

  //control the motor to spin to a target degree
  void motor::tickControlIME(double setPointDeg){
    double dt = 50;
    double rotations = setPointDeg/360;
    int setPointCount = rotationsToTicks(rotations, this->type);

    set_targetCount(setPointCount);
    printf("setPt: %d \n", this->targetCount);
    this->posPID->set_setPoint(this->targetCount);
    this->count = get_count();
    // // printf("PID: %f \n",this->posPID->get_kP());
    // // printf("trg: %f \n", setPointDeg);
    double vel_output = this->posPID->calculateOutput(this->count, dt);
    if(abs(this->posPID->get_setPoint()-(this->count)) > (this->posPID->get_deadband())){
      set_Power(vel_output); //replace with velocity control when you get chance
      printf("vel: %f",vel_output);
    //  printf("vel: %f \n",vel_output);
    }
  };
// };
