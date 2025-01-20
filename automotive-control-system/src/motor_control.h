#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor direction constants
#define MOTOR_FORWARD 1
#define MOTOR_REVERSE 2
#define MOTOR_STOP 0

// Function prototypes
void set_motor_direction(int direction);
void set_motor_speed(int speed); // Speed should be a value between 0 and 100

#endif // MOTOR_CONTROL_H