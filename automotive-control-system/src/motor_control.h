#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor control constants
#define MOTOR_MAX_SPEED 100
#define MOTOR_MIN_SPEED 0
#define MOTOR_PWM_FREQUENCY 1000 // 1 kHz

// Motor direction constants
#define MOTOR_DIR_FORWARD 1
#define MOTOR_DIR_REVERSE 0
#define MOTOR_DIR_BRAKE 2
#define MOTOR_DIR_FREE 3

// Function declarations
void motor_init(void);
void motor_start(int speed, int direction);
void motor_stop(void);
void motor_set_speed(int speed);
void motor_brake(void);

#endif // MOTOR_CONTROL_H