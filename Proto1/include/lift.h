#ifndef LIFT_H
#define LIFT_H
#include "ports.h"
#include "motor.h"
#include "API.h"
#include <vector>
class lift{
private:
  std::vector<motor*> primaryLift;
  pid* primaryLiftPosPID; //currently not being used. Things are being hard coded :(
  std::vector<motor*> secondaryLift;
  std::vector<motor*> goalLift;

public:

  lift();
  std::vector<motor*> get_primaryLift();
  void set_primaryLift(std::vector<motor*> motors);
  std::vector<motor*> get_secondaryLift();
  void set_secondaryLift(std::vector<motor*> motors);
  std::vector<motor*> get_goalLift();
  motor* get_goalLiftAt(int x);
  motor* get_primaryLiftAt(int pos);
  void set_goalLift(std::vector<motor*> motors);
  void addPrimaryLift(int port, bool reverse);

  void addSecondaryLift(int port, bool reverse);

  void addGoalLift(int port, bool reverse);

void set_primaryLiftPosPID(double kP, double kI, double kD, double kF=0);

  void primaryLiftPower(int power);

  void primaryLiftPosition(int deg, int encoderVal);

  void secondaryLiftPosition(int targetCount, int potentiometer);

  bool atTop = true;
  bool atBottom = false;
  void goalLiftUp();
  void goalLiftDown();

  void secondaryLiftPower(int power);

  void goalLiftPower(int power);
  void haltPrimaryLift();

  void haltSecondaryLift();

  void haltGoalLift();
};
#endif
