/*
 * @file utility.h
 * @created January 26, 2017
 * @author Brendan McGuire
 * @brief This header file defines utility functions
 */

#ifndef UTILITY_H_
#define UTILITY_H_

/**
 * Clamps a int to a value
 * @method clamp
 * @param  d           The value to clamp
 * @param  min         The min value
 * @param  max         The max value
 * @param  overrideMin The value to set if d < min
 * @param  overrideMax The value to set if d > max
 * @return
 */

int clamp(int d, int min, int max, int overrideMin, int overrideMax);

/**
 * Find the absolute value of an int
 * @method abs
 * @param  value The value to find the absolute value of
 * @return       int
 */
int abs(int value);

double average(double num1, double num2);

#endif /* INCLUDE_UTILITY_H_ */
