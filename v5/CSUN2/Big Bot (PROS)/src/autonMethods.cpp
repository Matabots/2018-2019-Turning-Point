#include "main.h"
#include "autonMethods.hpp"

void AggressiveRedAuton() // 8 Points
{
  // BOT STARTS W/ INTAKE FACING UN-SCORED CAP (Scores 3 Caps and Gets 2 High Flags and 1 Low Flag)
  // (Outer Alignment (Bottom Left on Red Alliance))

  // 1. FLIP UNFLIPPED CAP (+1)
    // A. LINE UP WITH UNFLIPPED CAP
    MoveSq(-.5);
    turn_right(50);
    MoveSq(-1);
    turn_left(45);
    MoveSq(1);
    // B. MOVE ARM TO FRONT
    MoveArmFront();
    StopArm();
    delay(1000);
    // C. FLIP UNFLIPPED CAP
    MoveSq(-1);
    turn_right(10);
    MoveSq(-.1);
    MoveArmBack();
    StopArm();
    delay(1000);
    MoveSq(.1);
  // 2. SCORE UNSCORED CAP & INTAKE BALL (+1)
    // A. LINE UP WITH UNSCORED CAP
    turn_left(10);
    turn_right(45);
    MoveSq(1.3);
    turn_left(45);
    // B. INTAKE BALL UNDER UNSCORED CAP AND SCORE CAP
    IntakeOn();
    MoveSq(-1.6);
    delay(500);
    IntakeOff();
  // 3. MOVE TO STARTING SQUARE
    MoveSq(1.8);
  // 4. DELAY SMALL BOT PARKS OR IS OUT OF THE WAY
  //  delay(5000);
  // 5. MOVE FORWARD TO GET OWN-LOW FLAG (+1)
    // A. LINE UP WITH OWN-FLAGS
    turn_left(95);
    // B. MOVE FORWARD ARM & MOVE TO FRONT
    MoveArmFront();
    StopArm();
    delay(1000);
    MoveSq(-2.3);
  // 6. FLIP UNFLIPPED CAP IN FRONT (+1)
    // A. TURN TOWARD UNFLIPPED CAP
    turn_right(45);
    MoveSq(-.5);
    // B. FLIP CAP
    FlipCap();
    delay(500);
  // 7. SCORE OWN-MIDDLE FLAG (+2)
    // A. LINE UP WITH FLAGS
    MoveSq(.75);
    turn_left(45);
    // B. MOVE UP TO SHOOT MIDDLE FLAG
    MoveSq(-1);
    // C. SHOOT MIDDLE FLAG
    turn_left(10);
    Shoot();
    turn_right(10);
  // 8. SCORE OWN-HIGH FLAG (+2)
    // A. MOVE BACK TO SHOOT HIGH FLAG
    IntakeOn();
    MoveSq(1);
    turn_left(10);
    delay(5000);
    // B. SHOOT HIGH FLAG
    Shoot();
    IntakeOff();

  //*** END OF AUTON ***//
}

void AggressiveBlueAuton()  // 8 Points
{
  // BOT STARTS W/ INTAKE FACING UN-SCORED CAP (Scores 3 Caps and Gets 2 High Flags and 1 Low Flag)
  // (Outer Alignment (Bottom Right on Blue Alliance))

  // 1. FLIP UNFLIPPED CAP (+1)
    // A. LINE UP WITH UNFLIPPED CAP
    MoveSq(-.5);
    turn_left(45);
    MoveSq(-1);
    turn_right(45);
    MoveSq(1);
    // B. MOVE ARM TO FRONT
    MoveArmFront();
    StopArm();
    delay(1000);
    // C. FLIP UNFLIPPED CAP
    MoveSq(-1);
    turn_left(10);
    MoveSq(-.1);
    MoveArmBack();
    StopArm();
    delay(1000);
    MoveSq(.1);
  // 2. SCORE UNSCORED CAP & INTAKE BALL (+1)
    // A. LINE UP WITH UNSCORED CAP
    turn_right(10);
    turn_left(45);
    MoveSq(1.3);
    turn_right(40);
    // B. INTAKE BALL UNDER UNSCORED CAP AND SCORE CAP
    IntakeOn();
    MoveSq(-1.6);
    delay(500);
    IntakeOff();
  // 3. MOVE TO STARTING SQUARE
    MoveSq(1.8);
  // 4. DELAY SMALL BOT PARKS OR IS OUT OF THE WAY
  //  delay(5000);
  // 5. MOVE FORWARD TO GET OWN-LOW FLAG (+1)
    // A. LINE UP WITH OWN-FLAGS
    turn_right(95);
    // B. MOVE FORWARD ARM & MOVE TO FRONT
    MoveArmFront();
    StopArm();
    delay(1000);
    MoveSq(-2.3);
  // 6. FLIP UNFLIPPED CAP IN FRONT (+1)
    // A. TURN TOWARD UNFLIPPED CAP
    turn_left(45);
    MoveSq(-.5);
    // B. FLIP CAP
    FlipCap();
    delay(500);
  // 7. SCORE OWN-MIDDLE FLAG (+2)
    // A. LINE UP WITH FLAGS
    MoveSq(.75);
    turn_right(40);
    // B. MOVE UP TO SHOOT MIDDLE FLAG
    MoveSq(-1);
    // C. SHOOT MIDDLE FLAG
    turn_right(10);
    Shoot();
    turn_left(10);
  // 8. SCORE OWN-HIGH FLAG (+2)
    // A. MOVE BACK TO SHOOT HIGH FLAG
    IntakeOn();
    MoveSq(2);
    turn_right(5);
    delay(5000);
    // B. SHOOT HIGH FLAG
    Shoot();
    IntakeOff();

  //*** END OF AUTON ***//
}

void WorstRedAuton() // 6 Points
{
  // BOT STARTS W/ INTAKE FACING UNSCORED CAP, (Scores 2 Caps and Gets 2 High Flags)
  //(Inner Alignment (Bottom Right On Red Alliance))

  // 1. FLIP UNFLIPPED CAP (+1)
    // A. LINE UP WITH UNFLIPPED CAP
    MoveSq(-.5);
    turn_right(50);
    MoveSq(-1);
    turn_left(45);
    MoveSq(.5);
    // B. MOVE ARM TO FRONT
    MoveArmFront();
    delay(1000);
    StopArm();

    // C. FLIP UNFLIPPED CAP
    MoveSq(-.5);
    turn_right(10);
    MoveArmBack();
    delay(1000);
    StopArm();
  // 2. SCORE UNSCORED CAP & INTAKE BALL (+1)
    // A. LINE UP WITH UNSCORED CAP
    turn_left(10);
    turn_right(45);
    MoveSq(1.3);
    turn_left(45);
    // B. INTAKE BALL UNDER UNSCORED CAP AND SCORE CAP
    IntakeOn();
    MoveSq(-1.25);
    delay(2000);
    IntakeOff();
  // 3. MOVE TO STARTING SQUARE
    MoveSq(.85);
  // 4. DELAY UNTIL END SECONDS OF AUTONOMOUS
  //  delay(15000);
  // 5. SCORE MIDDLE-HIGH FLAG (+2)
    // A. TURN TOWARD MIDDLE FLAGS
    turn_left(75);
    IntakeRev();
    delay(200);
    IntakeOff();
    delay(10000);
    // B. SHOOT
    Shoot();
  // 6. SCORE OPPOSITE-MIDDLE FLAG (+2)
    // A. TURN TOWARD OPPOSITE FLAGS
    turn_right(20);
    IntakeOn();
    delay(5000);
    // B. SHOOT
    Shoot();
    IntakeOff();

  //*** END AUTON ***//
}

void WorstBlueAuton() // 6 Points
{
  // BOT STARTS W/ INTAKE FACING UNSCORED CAP, (Scores 2 Caps and Gets 2 High Flags)
  //(Inner Alignment (Bottom Left On Blue Alliance))

  // 1. FLIP UNFLIPPED CAP (+1) // 12 Seconds
    // A. LINE UP WITH UNFLIPPED CAP
    MoveSq(-.5);
    turn_left(50);
    MoveSq(-1);
    turn_right(45);
    MoveSq(.5);
    // B. MOVE ARM TO FRONT
    MoveArmFront();
    delay(1000);
    StopArm();
    // C. FLIP UNFLIPPED CAP
    MoveSq(-.5);
    turn_left(10);
    MoveArmBack();
    delay(1000);
    StopArm();
  // 2. SCORE UNSCORED CAP & INTAKE BALL (+1) //
    // A. LINE UP WITH UNSCORED CAP
    turn_right(10);
    turn_left(40);
    MoveSq(1.3);
    turn_right(45);
    // B. INTAKE BALL UNDER UNSCORED CAP AND SCORE CAP
    IntakeOn();
    MoveSq(-1.25);
    delay(2000);
    IntakeOff();
  // 3. MOVE TO STARTING SQUARE
    MoveSq(.85);
    IntakeRev();
    delay(500);
    IntakeOff();
  // 4. DELAY UNTIL END SECONDS OF AUTONOMOUS
    delay(10000);
  // 5. SCORE MIDDLE-HIGH FLAG (+2)
    // A. TURN TOWARD MIDDLE FLAGS
    turn_right(75);
    // B. SHOOT
    Shoot();
  // 6. SCORE OPPOSITE-MIDDLE FLAG (+2)
    // A. TURN TOWARD OPPOSITE FLAGS
    turn_left(20);
    IntakeOn();
    delay(5000);
    // B. SHOOT
    Shoot();
    IntakeOff();

  //*** END AUTON ***//
}
