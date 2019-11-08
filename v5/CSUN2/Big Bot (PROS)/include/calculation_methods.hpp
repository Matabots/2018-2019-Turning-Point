#ifndef CALCULATION_METHODS_HPP
#define CALCULATION_METHODS_HPP
#include "main.h"

// CONVERSION MEHTODS
extern float InchToDeg(float inches);
extern float DegToInch(float degrees);
extern float SqToInch(float sq);

// POSITION CALCULATION METHODS
extern float Rpos(float Rf, float Rm, float Rb);
extern float Lpos(float Lf, float Lm, float Lb);

// TARE MEHTOD
extern void tare();

#endif
