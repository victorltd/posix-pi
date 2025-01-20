#include "motor_control.h"
#include "pwm_control.h"
#include <wiringPi.h>

#define MOTOR_DIR1_PIN 17
#define MOTOR_DIR2_PIN 18
#define MOTOR_PWM_PIN 23

void motor_init() {
    pinMode(MOTOR_DIR1_PIN, OUTPUT);
    pinMode(MOTOR_DIR2_PIN, OUTPUT);
    pinMode(MOTOR_PWM_PIN, PWM_OUTPUT);
}

void set_motor_direction(int direction) {
    if (direction == 1) { // Forward
        digitalWrite(MOTOR_DIR1_PIN, HIGH);
        digitalWrite(MOTOR_DIR2_PIN, LOW);
    } else if (direction == -1) { // Reverse
        digitalWrite(MOTOR_DIR1_PIN, LOW);
        digitalWrite(MOTOR_DIR2_PIN, HIGH);
    } else { // Stop
        digitalWrite(MOTOR_DIR1_PIN, LOW);
        digitalWrite(MOTOR_DIR2_PIN, LOW);
    }
}

void set_motor_speed(int speed) {
    if (speed < 0) {
        speed = 0;
    } else if (speed > 100) {
        speed = 100;
    }
    pwmWrite(MOTOR_PWM_PIN, speed * 10); // Assuming PWM range is 0-1023
}