#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

// Function to initialize GPIO pins
void gpio_init(void);

// Function to set a GPIO pin to high
void gpio_set_pin_high(int pin);

// Function to set a GPIO pin to low
void gpio_set_pin_low(int pin);

// Function to read the state of a GPIO pin
int gpio_read_pin(int pin);

// Function to configure a GPIO pin as input
void gpio_configure_input(int pin);

// Function to configure a GPIO pin as output
void gpio_configure_output(int pin);

#endif // GPIO_CONTROL_H