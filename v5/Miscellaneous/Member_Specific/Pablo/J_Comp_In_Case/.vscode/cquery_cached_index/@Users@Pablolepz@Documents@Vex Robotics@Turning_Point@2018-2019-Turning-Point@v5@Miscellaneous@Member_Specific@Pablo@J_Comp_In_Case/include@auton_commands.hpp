#ifndef AUTON_COMMANDS_CPP
#define AUTON_COMMANDS_CPP

#include "main.h"

//################Manipulators#########
extern void move_lift_to(int deg);
//################End Effectors#########
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
