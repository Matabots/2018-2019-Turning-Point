#include "autonScripts.h"

void debug(robot bot){
  bot.spinToAngle(360);

  delay(50);
};

void carbonRunRedPreload(robot bot){
  printf("this has ended\n");
  bot.setPreloadHeight();
  bot.lowerGoalLift();
  delay(250);
  bot.driveIn(47);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.raiseGoalLift();
  bot.scorePreload();
  bot.set_primaryBottomHeight(false);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  //bot.get_drive()->rightPosition(5);
  bot.driveIn(7);
  bot.set_targetStack(2);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    bot.autoLoad();
    delay(50);
  }
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.driveIn(-15);
  bot.set_primaryBottomHeight(true);
  delay(250);
  bot.spinToAngle(91);
  delay(250);
  bot.driveIn(-7.25);
  delay(250);



  bot.set_targetStack(8);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    printf("stacked cones: %d\n", bot.get_stackedCones());
    bot.autoLoad();
    delay(50);
  }
  // printf("autoload Ran");
   bot.set_primaryBottomHeight(false);
   delay(250);
   bot.spinToAngle(250);
   delay(250);
   bot.driveIn(40);
   delay(250);
  //  bot.get_drive()->haltLeft();
  //  bot.get_drive()->haltRight();
   delay(250);
   bot.spinToAngle(240);
   delay(250);
   bot.driveIn(-6);
    delay(250);
    bot.driveIn(35);
    delay(250);
    bot.lowerGoalLift();
    delay(250);
    bot.driveIn(-15);
   // bot.get_drive()->haltLeft();
   // bot.get_drive()->haltRight();
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


void carbonRunBluePreload(robot bot){
  printf("this has ended\n");
  bot.setPreloadHeight();
    bot.lowerGoalLift();
  delay(250);
  bot.driveIn(47);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.raiseGoalLift();
  bot.scorePreload();
  bot.set_primaryBottomHeight(false);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  // bot.get_drive()->rightPosition(5);
  bot.driveIn(7);
  bot.set_targetStack(2);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    bot.autoLoad();
    delay(50);
  }
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.driveIn(-15);
  bot.set_primaryBottomHeight(true);
  delay(250);
  bot.spinToAngle(-90);
  delay(250);
  bot.driveIn(-7.25);
  delay(250);
  bot.set_targetStack(8);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    printf("stacked cones: %d\n", bot.get_stackedCones());
    bot.autoLoad();
    delay(50);
  }
  // printf("autoload Ran");
   bot.set_primaryBottomHeight(false);
   delay(250);
   bot.spinToAngle(110);
   delay(250);
   bot.driveIn(40);
   delay(250);
   bot.get_drive()->haltLeft();
   bot.get_drive()->haltRight();
   delay(250);
   bot.spinToAngle(120);
   delay(250);
   bot.driveIn(-6);
   delay(250);
   bot.driveIn(35);
   delay(250);
   bot.lowerGoalLift();
   delay(250);
   bot.driveIn(-15);
}


//===================


void carbonJukeRunRedPreload(robot bot){
  bot.spinToAngle(129);
  delay(250);
  bot.driveIn(24);
  delay(250);
  bot.spinToAngle(117);
  delay(250);
//};//master test

  printf("this has ended\n");
  bot.setPreloadHeight();
  bot.lowerGoalLift();
  delay(250);
  bot.driveIn(47);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.raiseGoalLift();
  bot.scorePreload();
  bot.set_primaryBottomHeight(false);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.get_drive()->rightPosition(5);
  bot.driveIn(7);
  bot.set_targetStack(2);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    bot.autoLoad();
    delay(50);
  }
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.driveIn(-15);
  bot.set_primaryBottomHeight(true);
  delay(250);
  bot.spinToAngle(269);
  delay(250);
  bot.driveIn(-7.25);
  delay(250);
  bot.set_targetStack(8);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    printf("stacked cones: %d\n", bot.get_stackedCones());
    bot.autoLoad();
    delay(50);
  }
  // printf("autoload Ran");
   bot.set_primaryBottomHeight(false);
   delay(250);
   bot.spinToAngle(110);
   delay(250);
   bot.driveIn(40);
   delay(250);
   bot.get_drive()->haltLeft();
   bot.get_drive()->haltRight();
   bot.spinToAngle(225);
   bot.get_drive()->haltLeft();
   bot.get_drive()->haltRight();
}

//=============================================================================
//===============================Carbon (csun1)^^==========================================
//=============================================================================
//===============================Wu (csun2)\/======================================
//=============================================================================

void wuRunRedPreload(robot bot){
  printf("this has ended\n");
  bot.setPreloadHeight();
  delay(100);
  bot.timedLowerGoalLift(900);
  delay(250);
  bot.driveIn(150);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.timedRaiseGoalLift(900);
  bot.scorePreload();
  bot.set_primaryBottomHeight(false);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.get_drive()->rightPosition(25);
  bot.driveIn(21);
  bot.set_targetStack(2);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    bot.autoLoad();
    delay(50);
  }
  // printf("%ld\n", bot.intakeTimer);
  // delay(250);
  // bot.driveIn(-19);
  // bot.set_primaryBottomHeight(true);
  // delay(250);
  // bot.spinToAngle(269);
  // delay(250);
  // bot.driveIn(-7.75);
  // delay(250);
  // bot.set_targetStack(8);
  // while(bot.get_stackedCones() < bot.get_targetStack()){
  //   printf("stacked cones: %d\n", bot.get_stackedCones());
  //   bot.autoLoad();
  //   delay(50);
  // }
  // // printf("autoload Ran");
  //  bot.set_primaryBottomHeight(false);
  //  delay(250);
  //  bot.spinToAngle(110);
  //  delay(250);
  //  bot.driveIn(40);
  //  delay(250);
  //  bot.get_drive()->haltLeft();
  //  bot.get_drive()->haltRight();
  //  bot.spinToAngle(225);
  //  bot.get_drive()->haltLeft();
  //  bot.get_drive()->haltRight();
//  bot.get_drive()->haltRight();
};

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


void wuRunBluePreload(robot bot){
  printf("this has ended\n");
  bot.setPreloadHeight();
  delay(100);
  bot.timedLowerGoalLift(900);
  delay(250);
  bot.driveIn(120);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.timedRaiseGoalLift(900);
  bot.scorePreload();
  bot.set_primaryBottomHeight(false);
  // printf("%ld\n", bot.intakeTimer);
  delay(250);
  bot.get_drive()->rightPosition(25);
  bot.driveIn(21);
  bot.set_targetStack(2);
  while(bot.get_stackedCones() < bot.get_targetStack()){
    bot.autoLoad();
    delay(50);
  }
  // printf("%ld\n", bot.intakeTimer);
  // delay(250);
  // bot.driveIn(-19);
  // bot.set_primaryBottomHeight(true);
  // delay(250);
  // bot.spinToAngle(269);
  // delay(250);
  // bot.driveIn(-7.75);
  // delay(250);
  // bot.set_targetStack(8);
  // while(bot.get_stackedCones() < bot.get_targetStack()){
  //   printf("stacked cones: %d\n", bot.get_stackedCones());
  //   bot.autoLoad();
  //   delay(50);
  // }
  // // printf("autoload Ran");
  //  bot.set_primaryBottomHeight(false);
  //  delay(250);
  //  bot.spinToAngle(110);
  //  delay(250);
  //  bot.driveIn(40);
  //  delay(250);
  //  bot.get_drive()->haltLeft();
  //  bot.get_drive()->haltRight();
  //  bot.spinToAngle(225);
   bot.get_drive()->haltLeft();
   bot.get_drive()->haltRight();
}


//=====================================
//=====================================
//=====================================
//=====================================
//=====================================
void runUart(void * parameter)
{
  extern robot bot;
  while(true)
  {
    bot.uart();
    delay(50);
  }
}
