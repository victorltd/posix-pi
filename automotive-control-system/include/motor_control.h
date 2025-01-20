#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor direction constants
#define MOTOR_DIR_FORWARD 1
#define MOTOR_DIR_REVERSE 0
#define MOTOR_DIR_STOP 2

// Function prototypes
void set_motor_direction(int direction);
void set_motor_speed(int speed); // Speed should be a value between 0 and 100

#endif // MOTOR_CONTROL_H