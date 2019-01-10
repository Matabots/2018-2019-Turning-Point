#ifndef AUTON_COMMANDS_CPP
#define AUTON_COMMANDS_CPP

#include "main.h"
extern int inches_to_degrees(int inches);
extern int degrees_to_inches(double degrees);
extern int get_curr_dist_trvld();
//################Manipulators#########
extern void move_lift_to(int deg);
//################End Effectors#########
extern void intake_stop();
extern void intake_in();
extern void intake_out();
extern void find_flag();
extern void shoot_ball();
extern void shoot_ball(int speed);
extern void move_fork(int rot, int rpm);
extern void shoot_ball_test();
extern void flywheel_set(int rpm);
//################Movement#########
extern void move_forward(int inch);
extern void move_backward(int inch);
extern void move_forward(int inch, int rpm);
extern void move_backward(int inch, int rpm);
extern void turn_left(int deg);
extern void turn_right(int deg);


#endif
