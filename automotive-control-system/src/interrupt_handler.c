#include "interrupt_handler.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void handle_signal(int signal);
void setup_interrupts();

void handle_signal(int signal) {
    if (signal == SIGINT) {
        // Handle Ctrl+C interrupt
        printf("Interrupt received! Shutting down...\n");
        // Perform cleanup actions here
        exit(0);
    }
}

void setup_interrupts() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0; // No special flags
    sigemptyset(&sa.sa_mask);

    // Set up the SIGINT handler
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }
}