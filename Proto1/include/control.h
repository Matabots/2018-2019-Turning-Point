#ifndef CONTROL_H
#define CONTROL_H
#include "API.h"
class control{
private:
    int autonLift;
    int autonAbort;
    int bigLiftVar;
    int smallLift;
    int goalLifter;
    int roller;
    int clearStack;
    int team;
public:
    control();
    void setupcontrol();
    int autonLiftProcessAdd();
    int autonLiftProcessSubtract();
    int autoLiftAbort();
    int rollerOpen();
    int rollerClose();
    int clearConeStack();
    int bigLift();
    int goalLiftUp();
    int goalLiftDown();
    int rightJoystickVal();
    int leftJoystickVal();
    int smallLiftUp();
    int smallLiftDown();
    int defaultPosition();
    int absRightJoystickVal();
    int absLeftJoystickVal();
    int get_team();

    // int autonLiftProcessAdd();
    // int autonLiftProcessSubtract();
    // int autoLiftAbort();
    // int rollerOpen();
    // int rollerClose();
    // int smallLiftToggle();
    // int clearConeStack();
    // int bigLiftUp();
    // int bigLiftDown();
    // int goalLiftUp();
    // int goalLiftDown();
    // int rightJoystickVal();
    // int leftJoystickVal();
    // int smallLiftToggleUp();
    // int absRightJoystickVal();
    // int absLeftJoystickVal();

};
#endif
