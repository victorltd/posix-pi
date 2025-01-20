#ifndef PWM_CONTROL_H
#define PWM_CONTROL_H

// Function prototypes for PWM control
void pwm_init(void);
void set_motor_pwm(int duty_cycle);
void set_brake_pwm(int duty_cycle);

#endif // PWM_CONTROL_H