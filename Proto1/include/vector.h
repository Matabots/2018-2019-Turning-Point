/*
 * @file: vector.h
 * @created January 26, 2017
 * @author Brendan McGuire
 *
 *  This header file defines all functions which are related to the drive, like holonomic calculation code, and eventually, drive PID stuff
 */

#ifndef INCLUDE_VECTOR_H_
#define INCLUDE_VECTOR_H_

/**
 * There are two main types of vectors. Cartesian Vectors are vectors defined by an x and y value,
 */

typedef struct CartesianVector {
  double x;
  double y;
  int timeStamp;
} CartesianVector;

typedef struct PolarVector {
  double r;
  double angle;
  int timeStamp;
} PolarVector;

/**
 * Converts a polar vector to a cartesian one
 * @method PolarToCartesian
 * @param  vector           The vector to convert
 * @return                  The cartesian vector
 */
CartesianVector PolarToCartesian(PolarVector vector);

/**
 * Converts a cartesian vector to a polar one
 * @method CartesianToPolar
 * @param  vector           The vector to convert
 * @return                  The polar vector
 */
PolarVector CartesianToPolar(CartesianVector vector);

#endif /* INCLUDE_VECTOR_H_ */
