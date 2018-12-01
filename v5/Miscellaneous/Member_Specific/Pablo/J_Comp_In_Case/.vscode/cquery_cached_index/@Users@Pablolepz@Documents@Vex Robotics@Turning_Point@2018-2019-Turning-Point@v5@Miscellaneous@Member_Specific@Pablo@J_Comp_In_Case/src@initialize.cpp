#include "main.h"
#include "drive.hpp"
#include "robot.hpp"

static bool pressed = false;

/*CSUN:From looking at the current API,
currently using the Legacy LCD is the only
way to print onto the vex v5 brain*/

void left_button() {
	pressed = true;
	if (pressed) {
		lcd::clear();
		pros::lcd::set_text(1, "Auton_1 was pressed!");
	}
}
void middle_button() {
	pressed = true;
	if (pressed) {
		lcd::clear();
		pros::lcd::set_text(2, "Auton_2 was pressed!");
	}
}
void right_button() {
	pressed = true;
	if (pressed) {
		lcd::clear();
		pros::lcd::set_text(3, "Auton_3 was pressed!");
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//pros::lcd::initialize();
	//////0o lvgl_init();
	// setup_bot();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

	// //
	// pros::lcd::set_text(1, "This code is for \"Jerry\".");
	// pros::lcd::set_text(2, "By CSUN Vex Robotics");
	// pros::lcd::set_text(3, "==========================");
	// pros::lcd::set_text(4, "Main Menu");
	// pros::lcd::set_text(5, "(Left) Auton_1 (Mid) Auton_2 (Right) Auton_3");
	// pros::lcd::set_text(6, "Please select an auton:");
	// pros::lcd::register_btn0_cb(left_button);
	// pros::lcd::register_btn1_cb(middle_button);
	// pros::lcd::register_btn2_cb(right_button);
	// //


	// if (pressed)
	// {
	// 	screen_placeholder();
	// }
}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {


}
