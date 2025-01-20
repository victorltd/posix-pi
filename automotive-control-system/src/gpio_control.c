#include <stdio.h>
#include <wiringPi.h>
#include "gpio_control.h"

// Function to initialize GPIO pins
void gpio_init() {
    wiringPiSetupGpio(); // Use BCM GPIO numbering

    // Set motor control pins as output
    pinMode(Motor_DIR1, OUTPUT);
    pinMode(Motor_DIR2, OUTPUT);
    pinMode(Motor_POT, OUTPUT);
    
    // Set brake control pin as output
    pinMode(Freio_INT, OUTPUT);
    
    // Set pedal pins as input
    pinMode(Pedal_AC, INPUT);
    pinMode(Pedal_FR, INPUT);
    
    // Set sensor pins as input
    pinMode(Sensor_hall_motor, INPUT);
    pinMode(Sensor_hall_roda_A, INPUT);
    pinMode(Sensor_hall_roda_B, INPUT);
    
    // Set light control pins as output
    pinMode(Farol_Baixo, OUTPUT);
    pinMode(Farol_Alto, OUTPUT);
    pinMode(Luz_Freio, OUTPUT);
    pinMode(Luz_Seta_Esq, OUTPUT);
    pinMode(Luz_Seta_Dir, OUTPUT);
    pinMode(Luz_Temp_Motor, OUTPUT);
}

// Function to read the state of the accelerator pedal
int read_accelerator() {
    return digitalRead(Pedal_AC);
}

// Function to read the state of the brake pedal
int read_brake() {
    return digitalRead(Pedal_FR);
}

// Function to control the headlights
void control_headlights(int state) {
    digitalWrite(Farol_Baixo, state);
}

// Function to control the turn signals
void control_turn_signal(int direction, int state) {
    if (direction == LEFT) {
        digitalWrite(Luz_Seta_Esq, state);
    } else if (direction == RIGHT) {
        digitalWrite(Luz_Seta_Dir, state);
    }
}