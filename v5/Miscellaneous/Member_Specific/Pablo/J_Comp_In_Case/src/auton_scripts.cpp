#include "main.h"
#include "auton_scripts.hpp"

//fork at 90 degrees is -1000
//fork at bottom is


void run_auton()
{
  auton_tester();
  //blue_auton_one();
  // blue_auton_two();
  /*switch(choice)
    case 1:
      blue_auton_one();
      break;
    case 2:
      blue_auton_two();
      break;
    case 3:
      red_auton_one();
      break;
    case 4:
      red_auton_two();
      break;
      */
}

void blue_auton_one()
{
  //By Pablo Lepe **********
  // turn_left(90);
  move_forward(30, 90);
  move_fork(-1600, 100);
  shoot_ball();
  delay(1000);
  move_forward(25, 170);


}

void blue_auton_two()
{

}

void red_auton_one()
{

}

void red_auton_two()
{

}

void auton_tester()
{
  //shoot_ball_test();

}
