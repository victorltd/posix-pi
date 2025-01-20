#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

// Function prototypes for interrupt handling
void setup_interrupts(void);
void handle_button_press(void);
void handle_cruise_control_commands(void);

#endif // INTERRUPT_HANDLER_H