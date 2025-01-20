#include "motor_control.h"
#include "pwm_control.h"

void motor_start() {
    // Set direction to forward
    gpio_set_direction(Motor_DIR1, 1);
    gpio_set_direction(Motor_DIR2, 0);
    // Start the motor with initial speed
    pwm_set_motor_speed(0);
}

void motor_stop() {
    // Stop the motor
    gpio_set_direction(Motor_DIR1, 0);
    gpio_set_direction(Motor_DIR2, 0);
    pwm_set_motor_speed(0);
}

void motor_set_speed(int speed) {
    // Ensure speed is within valid range
    if (speed < 0) {
        speed = 0;
    } else if (speed > 100) {
        speed = 100;
    }
    // Set the motor speed using PWM
    pwm_set_motor_speed(speed);
}