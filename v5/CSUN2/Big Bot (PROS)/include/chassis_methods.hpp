#ifndef CHASSIS_METHODS_HPP
#define CHASSIS_METHODS_HPP
#include "main.h"

// MOVE METHODS (opcontrol)
extern void LMotors(float power);
extern void RMotors(float power);

// MOVE METHODS (autonomous)
extern void MoveSq(float sq);
extern void MoveTo(float distance, float velocity);
extern void MovePID(float distance, float rkp, float lkp);

// TURN METHODS
extern void RightPID(float Rdeg);
extern void LeftPID(float Rdeg);
extern void turn_right(float Rdeg);
extern void turn_left(float Rdeg);

extern void newMoveSq(float sq, float rkp, float lkp);
extern void newMoveTo(float distance, float velocity);
extern void newturn_right(float Rdeg, float rkp, float lkp);
extern void newturn_left(float Rdeg, float rkp, float lkp);

#endif
