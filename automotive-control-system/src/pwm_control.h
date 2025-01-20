#ifndef PWM_CONTROL_H
#define PWM_CONTROL_H

// Function to initialize PWM for motor control
void pwm_init(void);

// Function to set the PWM duty cycle for the motor
void pwm_set_motor_duty_cycle(int duty_cycle);

// Function to set the PWM duty cycle for the brake
void pwm_set_brake_duty_cycle(int duty_cycle);

// Function to stop PWM for motor and brake
void pwm_stop(void);

#endif // PWM_CONTROL_H