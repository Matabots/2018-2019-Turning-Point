#include "PID.h"

    pid::pid(){
      this->kP = 0;
      this->kI = 0;
      this->kD = 0;
      this->kF = 0;
      this->setPoint = 0.0;

      this->maxInput = std::numeric_limits<int>::max();//120.0;
      this->minInput = std::numeric_limits<int>::min();//-100.0;

      this->maxOutput = 100.0;
      this->minOutput = -120.0;
      this->error = 0.0;
      this->prevError = 0.0;
      this->totalError = 0.0;
      this->output = 0.0;
      this->deadband = 3;
      this->toleranceI = 15;
      this->sampleTime = pow(10,-2); //seconds
      this->continuous = false;
    };
    pid::pid(double kPInput, double kIInput, double kDInput, double kFInput){
      this->kP = kPInput;
      this->kI = kIInput;
      this->kD = kDInput;
      this->kF = kFInput;
      this->sampleTime = 10;
      this->setPoint = 0;

      this->maxInput = std::numeric_limits<int>::max();// 100.0;
      this->minInput = std::numeric_limits<int>::min();// -100.0;

      this->maxOutput = 120.0;
      this->minOutput = -120.0;
      this->error = 0.0;
      this->prevError = 0.0;
      this->totalError = 0.0;
      this->output = 0.0;
      this->deadband = 3;
      this->toleranceI = 15;
      this->continuous = false;
    };

    double pid::calculateOutput(double input, double dt){ //dt is in milliseconds
      dt = dt/1000;
      if(dt < (pow(10,-6))){
        dt = pow(10,-6);
      }

      this->error = (this->setPoint) - input;

      if(continuous == true){
        if(abs(this->error) > ((this->maxInput)-(this->minInput))/2){
          if(this->error > 0){
            this->error = (this->error)-(this->maxInput)+(this->minInput);
          }
          else{
            this->error = (this->error)+(this->maxInput)-(this->minInput);
          }
        }
      }

      //if((this->error)*(this->kP) < this->maxOutput && (this->error)*(this->kP) > this->minOutput){
      if(abs((this->error)) < abs(this->toleranceI)){
        this->totalError += (this->error)*dt;
      } else{
        this->totalError = 0;
      }

      double pError = abs(this->error)<abs(this->deadband) ? 0 : (this->error);
      double dError = ((this->error)-((this->prevError))/(dt));
      this->output = ((this->kP)*pError) + ((this->kI)*(this->totalError)) + ((this->kD)*(dError) + (this->kF)*(this->setPoint));


      this->prevError = this->error;
      this->prevInput = input;

      if((this->output)>(this->maxOutput)){
        this->output = this->maxOutput;
      }
      if((this->output)<(this->minOutput)){
        this->output = this->minOutput;
      }
      //lcdPrint(uart1, 2, "out: %f", this->output);
      lcdPrint(uart1,2,"kP: %f",this->kP);
      return this->output;
    };
    void pid::set_kP(double kPInput){
      this->kP = kPInput;
    };
    double pid::get_kP(){
      return this->kP;
    };
    void pid::set_kI(double kIInput){
      this->kI = kIInput;
    };
    double pid::get_kI(){
      return this->kI;
    };
    void pid::set_kD(double kDInput){
      this->kD = kDInput;
    };
    double pid::get_kD(){
      return this->kD;
    };
    double pid::get_output(){
      return this->output;
    };
    double pid::get_error(){
      return this->error;
    };
    double pid::get_prevError(){
      return this->prevError;
    };
    double pid::get_totalError(){
      return this->totalError;
    };
    void pid::set_sampleTime(int inputSampleTime){
      this->sampleTime = inputSampleTime;
    };
    int pid::get_sampleTime(){
      return this->sampleTime;
    };
    void pid::set_setPoint(int target){
      if((this->maxInput)>(this->minInput)){
        if(target > this->maxInput){
          this->setPoint = this->maxInput;
        }
        else if(target < this->minInput){
          this->setPoint = this->minInput;
        }
        else{
          this->setPoint = target;
        }
      }
    };
    int pid::get_setPoint(){
      return this->setPoint;
    };
    void pid::set_MinMaxOutput(double min, double max){
      if(min > max){
        printf("LOWER BOUNDARY IS GREATER THAN UPPER BOUND\n");
      }
      this->maxOutput = max;
      this->minOutput = min;
    };
    void pid::set_MinMaxInput(double min, double max){
      if(min > max){
        printf("LOWER BOUNDARY IS GREATER THAN UPPER BOUND\n");
      }
      this->maxInput = max;
      this->minInput = min;
      set_setPoint(this->setPoint);
    };
    void pid::set_deadband(int band){
      this->deadband = band;
    };
    double pid::get_deadband(){
      return this->deadband;
    };
    void pid::set_toleranceI(double tolerance){
      this->toleranceI = tolerance;
    };
    double pid::get_toleranceI(){
      return this->toleranceI;
    }
    void pid::set_prevInput(double input){
      this->prevInput = input;
    };
    double pid::get_prevInput(){
      return this->prevInput;
    };
    void pid::set_maxMinInput(int max,int min){
      this->maxInput = max;
      this->minInput = min;
    }
    void pid::set_continuous(bool val){
      this->continuous = val;
    };
    bool pid::isContinuous(){
      return this->continuous;
    };
