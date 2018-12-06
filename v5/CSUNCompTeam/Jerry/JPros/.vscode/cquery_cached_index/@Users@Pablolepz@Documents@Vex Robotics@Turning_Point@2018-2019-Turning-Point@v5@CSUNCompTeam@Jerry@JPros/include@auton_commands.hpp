#ifndef AUTON_COMMANDS_CPP
#define AUTON_COMMANDS_CPP

#include "main.h"

extern void InchtoDeg(int inch);

//################Manipulators#########
extern void move_lift_to(int deg);
//################End Effectors#########
extern void intake_in();
extern void intake_out();
extern void find_flag();
extern void shoot_ball();
//################Movement#########
extern void move_forward(int inch);
extern void move_backward(int inch);
extern void move_forward(int inch, int rpm);
extern void move_backward(int inch, int rpm);
extern void turn_left(int deg);
extern void turn_right(int deg);


#endif
