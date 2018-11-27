#include "lift.h"

  lift::lift(){

  };
  std::vector<motor*> lift::get_primaryLift(){
    return this->primaryLift;
  };
  void lift::set_primaryLift(std::vector<motor*> motors){
    this->primaryLift = motors;
  };
  motor* lift::get_primaryLiftAt(int pos){
    return this->primaryLift[pos];
  };
  std::vector<motor*> lift::get_secondaryLift(){
    return this->secondaryLift;
  };
  void lift::set_secondaryLift(std::vector<motor*> motors){
    this->secondaryLift = motors;
  };
  std::vector<motor*> lift::get_goalLift(){
    return this->goalLift;
  }
  motor* lift::get_goalLiftAt(int x){
    return this->goalLift[x];
  }
  void lift::set_goalLift(std::vector<motor*> motors){
    this->goalLift = motors;
  }
  void lift::addPrimaryLift(int port, bool reverse){
    motor* liftMotor = new motor(port,9.0,0.0,0.0,0.0);//10.5
    liftMotor->set_Direction(reverse);
    liftMotor->set_type(ENC);
    liftMotor->get_posPID()->set_deadband(1);
    //liftMotor->get_posPID()->set_deadband(3);
    this->primaryLift.push_back(liftMotor);
  };

  void lift::addSecondaryLift(int port, bool reverse){
    motor* liftMotor = new motor(port);
    liftMotor->set_Direction(reverse);
    // this->secondaryLift.resize(this->secondaryLift.size() + 1);
    this->secondaryLift.push_back(liftMotor);
  }

  void lift::addGoalLift(int port, bool reverse){
    motor* goalMotor = new motor(port);
    goalMotor->set_Direction(reverse);
    goalMotor->set_type(TORQUE);
    goalMotor->set_address(2);
    this->goalLift.push_back(goalMotor);
  }

void lift::set_primaryLiftPosPID(double kP, double kI, double kD, double kF) {
  pid* posPID = new pid(kP,kI,kD,kF);
  for(std::vector<motor*>::size_type i = 0; i != this->primaryLift.size(); i++) {
    this->primaryLift[i]->set_posPID(posPID);
  }
};

  void lift::primaryLiftPower(int power){
    for(std::vector<motor*>::size_type i = 0; i != this->primaryLift.size(); i++) {
      this->primaryLift[i]->set_Power(power);
    }
  };

  void lift::primaryLiftPosition(int deg, int encoderVal){
    printf("kP: %f\n", this->primaryLift[0]->get_posPID()->get_kP());
    for(std::vector<motor*>::size_type i = 0; i != this->primaryLift.size(); i++) {
      this->primaryLift[i]->tickControl(deg,encoderVal);
    }
  };

  void lift::secondaryLiftPosition(int targetCount, int potentiometer){
    for(std::vector<motor*>::size_type i = 0; i != this->secondaryLift.size(); i++) {
      if((potentiometer) > (targetCount)){
        // this->secondaryLift[i]->set_Power(-70);//=70
        this->secondaryLift[i]->set_Power((0.2*(targetCount-potentiometer)));
        printf("running %d\n",this->secondaryLift[i]->get_Power() );
        printf("# lift: %d\n",this->secondaryLift.size());
      }
      else if((potentiometer) < (targetCount)){
        this->secondaryLift[i]->set_Power((0.2*(targetCount-potentiometer)));
      }
      else{
        haltSecondaryLift();
      }
    }
  };

  bool atTop = true;
  bool atBottom = false;
  void lift::goalLiftUp(){
    for(std::vector<motor*>::size_type i = 0; i != this->secondaryLift.size(); i++) {
      if(get_goalLiftAt(0)->get_count() < 5){
        goalLiftPower(127);
        atTop = false;
      }
      else{
        haltGoalLift();
        atTop = true;
        atBottom = false;
      }
    }
  };
  void lift::goalLiftDown(){
    for(std::vector<motor*>::size_type i = 0; i != this->secondaryLift.size(); i++) {
      if(get_goalLiftAt(0)->get_count() > -850){
        goalLiftPower(-127);
        atBottom = false;
      }
      else{
        haltGoalLift();
        atBottom = true;
        atTop = false;
      }
    }
  };

  void lift::secondaryLiftPower(int power){
    for(std::vector<motor*>::size_type i = 0; i != this->secondaryLift.size(); i++) {
      this->secondaryLift[i]->set_Power(power);
    }
  };

  void lift::goalLiftPower(int power){
    for(std::vector<motor*>::size_type i =0; i != this->goalLift.size();i++){
      this->goalLift[i]->set_Power(power);
    }
  };
  void lift::haltPrimaryLift(){
    for(std::vector<motor*>::size_type i = 0; i != this->primaryLift.size(); i++) {
      this->primaryLift[i]->set_Power(0);
    }
  };

  void lift::haltSecondaryLift(){
    for(std::vector<motor*>::size_type i = 0; i != this->secondaryLift.size(); i++) {
      this->secondaryLift[i]->set_Power(0);
    }
  };

  void lift::haltGoalLift(){
    for(std::vector<motor*>::size_type i = 0;i != this->goalLift.size(); i++){
      this->goalLift[i]->set_Power(0);
    }
  }
