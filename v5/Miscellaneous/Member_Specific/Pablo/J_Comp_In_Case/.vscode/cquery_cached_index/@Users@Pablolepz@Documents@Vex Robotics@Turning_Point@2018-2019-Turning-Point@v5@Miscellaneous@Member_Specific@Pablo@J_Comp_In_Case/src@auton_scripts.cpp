#include "main.h"
#include "auton_scripts.hpp"
#include "brain_screen.hpp"
//fork at 90 degrees is -1000
//fork at bottom is


void run_auton()
{

  NEW_red_auton_one();
  //auton_tester();
  //red_auton_one();
  //red_auton_two();
  //red_auton_three();
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

// void auton_tester()
// {
//   shoot_ball_test();
//   //draw_test_screen();
//
// }

// void red_auton_one()
// {
//   //By Pablo Lepe **********
//   // turn_left(90);
//   move_forward(30, 90);
//   move_fork(-1600, 100);
//   shoot_ball();
//   delay(1000);
//   move_forward(25, 170);
// }
//
// void red_auton_two()
// {
//   //by Turtle
//   move_fork(-1600, 100);
//   shoot_ball(195);
//   delay(2000);
//   shoot_ball(180);
//
//
//
// }
//
// void red_auton_three()
// {
//   //
//   shoot_ball(200);
//   delay(2000);
//   if (abs(get_flywheel_avg_rpm()) > 200)
//   {
//     intake_in();
//   }
// }


//##########################################################################################
void NEW_red_auton_one()
{
  // move_forward(10, 90);
  // delay(2000);
  // turn_left(90, 100);
  // delay(2000);
  move_forward(50,90);
  // while (get_curr_dist_trvld() < 30)
  // {
  // }
  delay(1000);
  intake_in();
  delay(2000);
  intake_stop();
  // delay(5000);
  // intake_out();
  // move_backward(6, 90);
  // delay(3000);
  // intake_stop();
  // turn_right(90, 200);
}
//##########################################################################################

// void blue_auton_one()
// {
//
// }
//
// void blue_auton_two()
// {
//
// }
