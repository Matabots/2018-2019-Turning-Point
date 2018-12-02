#include "main.h"
#include "auton_commands.hpp"

//#################Variables###########################
//Please add variables in your spaces for easy identification.

//==========Pablo==========
int x = 9001; //this is an example


//==========Gisela==========


//==========Omar==========


//==========Daniel==========
double degree;
double InchtoDeg(double inch)
{
  degree= ((360*inch)/(2*3.14));
  return degree;
}

//################Manipulators##########################

void move_lift_to(int deg)
{
  /*This method moves the manipulator (or in this scenerio, lift), to a certain degree.
  Make sure it stops when it runs out of space for the gears or it will start to fight
  and the gears will get damaged. */

}

//################End Effectors##########################

void move_fork()
{
  /*Move fork to a certain degree. Make sure it stops when it runs out of
  space for the gears or it will start to fight and the gears will get damaged.
  */

}

void intake_in()
{
  /*Turn the intake on to take in balls.
  */
}

void intake_out()
{
  /*Turn the intake on to take out balls.
  */
}

void find_flag()
{
  /* This code will have the robot look for a flag using the pixy camera.
  */
}

void shoot_ball()
{
  /*When using this method, the flywheel starts, waits for max rpm, and shoots.
  optimum flywheel control might be found by changing the pid values
  however, it doesnt have to be changed for it to be used. Driver control's
  way of starting the flywheel is a good way of showing how the flywheel works
  in a basic way.
  Once its done shooting, the flywheel should be reduced to 0 rpm or to some minimum speed
  such as 100 as an idle mode. Low rpm = low motor usage = more battery life.
  */

}

//################Movement##########################


void move_forward(int inch)
{
  //moves at a default rpm, Id suggest 200 (or max of gearset).

}

void move_backward(int inch)
{
  //moves at a default rpm, Id suggest -200 (or max of gearset).

}

void move_forward(int inch, int rpm)
{
  //same as move_forward but user can include the rpm

}

void move_backward(int inch, int rpm)
{
  //same as move_forward but user can include the rpm

}

void turn_left(int deg)
{
  //turns the bot left

}

void turn_right(int deg)
{
  //turns the bot right

}
