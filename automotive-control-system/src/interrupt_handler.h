#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

// Function prototypes for interrupt handling
void setup_interrupts(void);
void handle_accelerator_pedal_interrupt(void);
void handle_brake_pedal_interrupt(void);
void handle_cruise_control_interrupt(void);
void handle_light_switch_interrupt(void);
void handle_turn_signal_interrupt(void);

#endif // INTERRUPT_HANDLER_H