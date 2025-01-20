#include "pwm_control.h"
#include <wiringPi.h>

#define PWM_FREQUENCY 1000 // 1 kHz
#define PWM_RANGE 100 // 0 to 100%

void pwm_init() {
    wiringPiSetupGpio(); // Initialize wiringPi using GPIO numbering
    pinMode(Motor_POT, PWM_OUTPUT); // Set motor PWM pin as output
    pinMode(Freio_INT, PWM_OUTPUT); // Set brake PWM pin as output
    pwmSetMode(PWM_MODE_MS); // Set PWM mode to mark-space
    pwmSetRange(PWM_RANGE); // Set the range for PWM
    pwmSetClock(PWM_FREQUENCY); // Set the PWM frequency
}

void set_motor_pwm(int duty_cycle) {
    if (duty_cycle < 0) {
        duty_cycle = 0; // Ensure duty cycle is not negative
    } else if (duty_cycle > PWM_RANGE) {
        duty_cycle = PWM_RANGE; // Ensure duty cycle does not exceed range
    }
    pwmWrite(Motor_POT, duty_cycle); // Set the PWM duty cycle for the motor
}

void set_brake_pwm(int duty_cycle) {
    if (duty_cycle < 0) {
        duty_cycle = 0; // Ensure duty cycle is not negative
    } else if (duty_cycle > PWM_RANGE) {
        duty_cycle = PWM_RANGE; // Ensure duty cycle does not exceed range
    }
    pwmWrite(Freio_INT, duty_cycle); // Set the PWM duty cycle for the brake
}