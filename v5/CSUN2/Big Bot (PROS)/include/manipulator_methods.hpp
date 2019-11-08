#ifndef MANIPULATOR_METHODS_HPP
#define MANIPULATOR_METHODS_HPP
#include "main.h"

// INTAKE METHODS
extern void IntakeOn();
extern void IntakeOff();
extern void IntakeRev();

// ARM METHODS
extern void FlipCap();
extern void MoveArmFront();
extern void MoveArmBack();
extern void StopArm();
extern void StraightenArm();
extern void AddBrake();
extern void AddHold();
extern void RemoveBrake();

// SHOOT PUNCHER METHOD
extern void Shoot();

#endif
