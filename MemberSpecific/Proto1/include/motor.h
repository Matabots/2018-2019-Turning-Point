#ifndef MOTOR_H
#define MOTOR_H
#include "API.h"
#include "PID.h"
#include "units.h"
//#include "motionProfile.h"

class motor{
private:

  int port;
  int power;
  bool reversed;
  bool imeReversed;
  motorType type;
  unsigned char address;
  int count;
  int targetCount;
  int velocity;
  int targetVel;
  int freeRPM;
  int prevTime; //previous millisecond value
  int prevCount;
  int sampleTime; //time it takes between reading values in seconds
  pid* velPID;
  pid* posPID;

public:

  motor();
  motor(int motorPort, double kPInput=0, double kIInput=0, double kDInput=0, double kFInput=0);
  motor(int motorPort, unsigned char encoderAddress, double kPInput=0, double kIInput=0, double kDInput=0, double kFInput=0);
  void set_targetVelocity(int vel);
  int get_targetVelocity();
  int get_velocity();  //control the motor to spin at a certain veloctiy

  int get_targetCount();
  void set_targetCount(int tCount);

  int get_velocity(Encoder* encoderValue);
  void set_velPID(double kPInput=0, double kIInput=0, double kDInput=0, double kFInput=0);
  void set_velPID(pid* controller);
  pid* get_velPID();
  void set_posPID(pid* controller);
  pid* get_posPID();
  void set_freeRPM();
  int get_freeRPM();
  motorType get_motorType();
  void set_motorType(motorType mType);
  unsigned char get_address();
  void set_address(unsigned char add);
  bool get_imeReversed();
  void set_imeReversed(bool val);
  int get_count();

  int get_prevCount();
  int get_prevTime();
  void reset_encoder();
  void set_encoderPort(int encoderPort);
  unsigned char get_encoderPort();
  void set_Port(int motorPort);
  int get_Port();
  void set_Power(int motorPower);
  int get_Power();
  void set_Direction(bool motorReversed);
  bool get_Direction();
  int get_Speed();
  void set_type(motorType motor);
  void velocityControlIME(int setPoint);
  void velocityControl(Encoder* enc, int setPoint);
  //control the motor to spin to a target degree
  void positionControlIME(double setPointIn);
  //control the motor to spin to a target degree
  void tickControl(double setPointDeg, double currTick);
  //control the motor to spin to a target degree
  void tickControlIME(double setPointDeg);
};
#endif
