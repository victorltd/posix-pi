#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "panel_control.h"
#include "gpio_control.h"
#include "motor_control.h"
#include "pwm_control.h"
#include "cruise_control.h"

static volatile int running = 1;

void handle_sigint(int sig) {
    running = 0;
}

void display_dashboard(int speed, int rpm, float distance, int cruise_enabled, int cruise_speed, int headlights, int turn_signal) {
    printf("Dashboard Information:\n");
    printf("Speed: %d km/h\n", speed);
    printf("RPM: %d\n", rpm);
    printf("Distance: %.2f km\n", distance);
    printf("Cruise Control: %s (Speed: %d km/h)\n", cruise_enabled ? "Enabled" : "Disabled", cruise_speed);
    printf("Headlights: %s\n", headlights ? "On" : "Off");
    printf("Turn Signal: %s\n", turn_signal ? "On" : "Off");
}

void process_input_commands() {
    char command;
    while (running) {
        printf("Enter command (r: resume, c: cancel, +: increase speed, -: decrease speed, q: quit): ");
        command = getchar();
        getchar(); // Consume newline character

        switch (command) {
            case 'r':
                resume_cruise_control();
                break;
            case 'c':
                cancel_cruise_control();
                break;
            case '+':
                increment_cruise_speed();
                break;
            case '-':
                decrement_cruise_speed();
                break;
            case 'q':
                running = 0;
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    initialize_gpio();
    initialize_pwm();
    initialize_motor();

    int speed = 0, rpm = 0, cruise_speed = 0;
    float distance = 0.0;
    int cruise_enabled = 0, headlights = 0, turn_signal = 0;

    while (running) {
        // Update speed, rpm, distance, and other variables here
        display_dashboard(speed, rpm, distance, cruise_enabled, cruise_speed, headlights, turn_signal);
        process_input_commands();
    }

    // Cleanup and shutdown procedures
    shutdown_motor();
    shutdown_pwm();
    shutdown_gpio();

    return 0;
}