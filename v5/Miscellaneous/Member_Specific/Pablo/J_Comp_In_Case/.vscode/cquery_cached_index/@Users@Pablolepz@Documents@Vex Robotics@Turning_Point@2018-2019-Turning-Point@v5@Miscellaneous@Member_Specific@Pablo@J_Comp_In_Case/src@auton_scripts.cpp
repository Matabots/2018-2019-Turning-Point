#include "main.h"
#include "auton_scripts.hpp"
#include "brain_screen.hpp"

//fork at 90 degrees is -1000
//fork at bottom is


void run_auton()
{
  //auton_tester();
  //red_auton_one();
  //red_auton_two();
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

void auton_tester()
{
  shoot_ball_test();
  //draw_test_screen();

}

void red_auton_one()
{
  //By Pablo Lepe **********
  // turn_left(90);
  move_forward(30, 90);
  move_fork(-1600, 100);
  shoot_ball();
  delay(1000);
  move_forward(25, 170);
}

void red_auton_two()
{
  //by Turtle
  move_fork(-1600, 100);
  shoot_ball(195);
  delay(2000);
  shoot_ball(180);



}

void red_auton_one()
{

}

void red_auton_two()
{

}
