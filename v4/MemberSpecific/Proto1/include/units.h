/**
 * @file: units.h
 * @created Febuary 8, 2017
 * @author Brendan McGuire
 *
 *  Contains abstractions for units
 */

 #ifndef INCLUDE_UNITS_H_
 #define INCLUDE_UNITS_H_

 #include <API.h>

 typedef enum motorType {
   TORQUE,
   HIGHSPEED,
   TURBO,
   ENC
 } motorType;

#define PI 3.141492653

typedef enum state{
  BOTTOM,
  INTAKE,
  CONEHEIGHT,
  OUTTAKE,
  ADJUSTHEIGHT,
  RESTABOVE
}state;

void printState(state rState);

double avg(double num1, double num2);

double getTypeTicks(motorType motor);

int imeVelocity(int velocity, motorType motor);

double ticksToRotations(Encoder enc);

/**
 * Convert ticks to rotations
 * @method ticksToRotations
 * @param  ticks           Ticks
 * @param  motor           The motor type
 * @return                 Rotations
 */
 double ticksToRotations(int ticks, motorType motor);

double ticksToDegrees(int ticks, motorType motor);
/**
 * Converts rotations to ticks
 * @method rotationsToTicks
 * @param  rotations        Rotations
 * @param  motor            Motor Type
 * @return                  Ticks
 */
 int rotationsToTicks(double rotations, motorType motor);

 int rotationsToTicks(Encoder enc);

/**
 * Convert ticks to inches
 * @method ticksToInches
 * @param  ticks         Ticks
 * @param  wheelDiameter The wheel diameter
 * @param  motor         The motor type
 *
 * @return               Inches
 */
 double ticksToInches(int ticks, double wheelDiameter, motorType motor);
 double ticksToInches(Encoder enc, double wheelDiameter);

/**
 * Convert inches to ticks
 * @method inchesToTicks
 * @param  inches        Inches
 * @param  wheelDiameter The wheel diameter
 * @param  motor         The motor type
 *
 * @return               Ticks
 */

  double inchesToDeg(double inches, double wheelDiameter, motorType motor);
  double degToInches(double deg, double wheelDiameter);


#endif /* INCLUDE_XDRIVE_H_ */
