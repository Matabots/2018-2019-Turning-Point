#ifndef PID_H
#define PID_H
#include "API.h"
#include "math.h"
#include <limits>
class pid{
  private:
    double kP;
    double kI;
    double kD;
    double kF;  //feed forward term
    double setPoint; //setPoint value
    double maxOutput;
    double minOutput;
    double maxInput;
    double minInput;
    double prevInput;
    double error;
    double prevError;
    double totalError;
    double output;
    double deadband;  //the time in which the PID controller maintains output. If the error is less than deadband, treat error for kP as 0
    double toleranceI;
    int sampleTime; //time it takes between reading values in seconds
    bool continuous;  //if it is absolute (wraps around). If true, the PID controller considers the max and min as the same value.

  public:
    pid();;
    pid(double kPInput, double kIInput, double kDInput, double kFInput);
    double calculateOutput(double input, double dt);
    void set_kP(double kPInput);
    double get_kP();
    void set_kI(double kIInput);
    double get_kI();
    void set_kD(double kDInput);
    double get_kD();
    double get_output();
    double get_error();
    double get_prevError();
    double get_totalError();
    void set_sampleTime(int inputSampleTime);
    int get_sampleTime();
    void set_setPoint(int target);
    int get_setPoint();
    void set_MinMaxOutput(double min, double max);
    void set_MinMaxInput(double min, double max);
    void set_deadband(int band);
    double get_deadband();
    void set_toleranceI(double tolerance);
    double get_toleranceI();
    void set_prevInput(double input);
    double get_prevInput();
    void set_maxMinInput(int max,int min);
    void set_continuous(bool val);
    bool isContinuous();
};
#endif
