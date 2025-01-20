#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "gpio_control.h"
#include "motor_control.h"
#include "pwm_control.h"
#include "cruise_control.h"
#include "panel_control.h"

volatile int running = 1;

void handle_sigint(int sig) {
    running = 0;
}

int main() {
    // Set up signal handler for graceful exit
    signal(SIGINT, handle_sigint);

    // Initialize GPIO
    if (gpio_init() < 0) {
        fprintf(stderr, "Failed to initialize GPIO\n");
        return EXIT_FAILURE;
    }

    // Initialize motor control
    if (motor_init() < 0) {
        fprintf(stderr, "Failed to initialize motor control\n");
        return EXIT_FAILURE;
    }

    // Initialize PWM control
    if (pwm_init() < 0) {
        fprintf(stderr, "Failed to initialize PWM control\n");
        return EXIT_FAILURE;
    }

    // Initialize cruise control
    if (cruise_control_init() < 0) {
        fprintf(stderr, "Failed to initialize cruise control\n");
        return EXIT_FAILURE;
    }

    // Initialize panel control
    if (panel_init() < 0) {
        fprintf(stderr, "Failed to initialize panel control\n");
        return EXIT_FAILURE;
    }

    // Main control loop
    while (running) {
        // Update panel information
        panel_update();

        // Process user inputs
        panel_process_input();

        // Control motor based on inputs
        motor_control();

        // Control PWM signals
        pwm_control();

        // Handle cruise control logic
        cruise_control_update();
    }

    // Cleanup and shutdown
    pwm_cleanup();
    motor_cleanup();
    gpio_cleanup();

    return EXIT_SUCCESS;
}