#include "cruise_control.h"
#include "motor_control.h"
#include "panel_control.h"
#include <stdio.h>
#include <stdbool.h>

static int desired_speed = 0;
static bool cruise_control_active = false;

void set_cruise_control(int speed) {
    desired_speed = speed;
    cruise_control_active = true;
    printf("Cruise control set to %d km/h\n", desired_speed);
}

void resume_cruise_control() {
    if (cruise_control_active) {
        printf("Cruise control resumed at %d km/h\n", desired_speed);
    } else {
        printf("Cruise control is not active. Please set a speed first.\n");
    }
}

void cancel_cruise_control() {
    cruise_control_active = false;
    desired_speed = 0;
    printf("Cruise control canceled.\n");
}

void update_cruise_control(int current_speed) {
    if (cruise_control_active) {
        if (current_speed < desired_speed) {
            increase_motor_speed(desired_speed - current_speed);
        } else if (current_speed > desired_speed) {
            decrease_motor_speed(current_speed - desired_speed);
        }
    }
}