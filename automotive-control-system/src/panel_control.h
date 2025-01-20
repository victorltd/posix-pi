#ifndef PANEL_CONTROL_H
#define PANEL_CONTROL_H

// Function to initialize the panel control system
void init_panel_control(void);

// Function to update the dashboard display
void update_dashboard_display(int speed, int rpm, float distance, int cruise_control_status, int headlight_status, int left_turn_signal, int right_turn_signal);

// Function to handle user input commands
void handle_user_input(int command);

// Function to toggle turn signals
void toggle_turn_signal(int direction);

// Function to set cruise control speed
void set_cruise_control_speed(int speed);

// Function to cancel cruise control
void cancel_cruise_control(void);

#endif // PANEL_CONTROL_H