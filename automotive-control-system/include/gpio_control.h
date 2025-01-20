#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

// Function prototypes for GPIO control
void gpio_init(void);
int read_accelerator_pedal(void);
int read_brake_pedal(void);
void control_headlights(int state);
void control_turn_signal(int direction);

#endif // GPIO_CONTROL_H