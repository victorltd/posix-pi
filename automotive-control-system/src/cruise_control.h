#ifndef CRUISE_CONTROL_H
#define CRUISE_CONTROL_H

// Function to initialize the cruise control system
void cruise_control_init(void);

// Function to set the desired speed for cruise control
void cruise_control_set_speed(int speed);

// Function to resume cruise control with the current speed
void cruise_control_resume(void);

// Function to cancel the cruise control
void cruise_control_cancel(void);

// Function to update the cruise control state
void cruise_control_update(void);

// Function to get the current speed set in cruise control
int cruise_control_get_speed(void);

// Function to check if cruise control is active
int cruise_control_is_active(void);

#endif // CRUISE_CONTROL_H