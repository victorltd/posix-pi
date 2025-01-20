#include <wiringPi.h>
#include "pwm_control.h"

#define MOTOR_PWM_PIN 23
#define BRAKE_PWM_PIN 24
#define PWM_FREQUENCY 1000

void setupPWM() {
    pinMode(MOTOR_PWM_PIN, PWM_OUTPUT);
    pinMode(BRAKE_PWM_PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(1024);
    pwmSetClock(192); // Set clock for 1 kHz frequency
}

void setMotorSpeed(int speed) {
    if (speed < 0) {
        speed = 0;
    } else if (speed > 100) {
        speed = 100;
    }
    pwmWrite(MOTOR_PWM_PIN, speed * 10.24); // Scale speed to PWM range
}

void setBrakeIntensity(int intensity) {
    if (intensity < 0) {
        intensity = 0;
    } else if (intensity > 100) {
        intensity = 100;
    }
    pwmWrite(BRAKE_PWM_PIN, intensity * 10.24); // Scale intensity to PWM range
}

void stopMotor() {
    pwmWrite(MOTOR_PWM_PIN, 0);
}

void releaseBrake() {
    pwmWrite(BRAKE_PWM_PIN, 0);
}