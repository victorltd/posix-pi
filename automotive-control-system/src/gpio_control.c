#include "gpio_control.h"
#include <wiringPi.h>
#include <stdio.h>

// Function to initialize GPIO pins
void gpio_init() {
    wiringPiSetupGpio(); // Use BCM GPIO numbering

    // Set motor control pins as output
    pinMode(Motor_DIR1, OUTPUT);
    pinMode(Motor_DIR2, OUTPUT);
    pinMode(Motor_POT, PWM_OUTPUT);
    
    // Set brake control pin as output
    pinMode(Freio_INT, PWM_OUTPUT);
    
    // Set pedal inputs
    pinMode(Pedal_AC, INPUT);
    pinMode(Pedal_FR, INPUT);
    
    // Set sensor inputs
    pinMode(Sensor_hall_motor, INPUT);
    pinMode(Sensor_hall_roda_A, INPUT);
    pinMode(Sensor_hall_roda_B, INPUT);
    
    // Set output pins for lights
    pinMode(Farol_Baixo, OUTPUT);
    pinMode(Farol_Alto, OUTPUT);
    pinMode(Luz_Freio, OUTPUT);
    pinMode(Luz_Seta_Esq, OUTPUT);
    pinMode(Luz_Seta_Dir, OUTPUT);
    pinMode(Luz_Temp_Motor, OUTPUT);
    
    // Set input pins for commands
    pinMode(Comando_Farol, INPUT);
    pinMode(Comando_Farol_Alto, INPUT);
    pinMode(Comando_seta_esq, INPUT);
    pinMode(Comando_seta_dir, INPUT);
    pinMode(CC_RES, INPUT);
    pinMode(CC_CANCEL, INPUT);
}

// Function to read the state of the accelerator pedal
int read_accelerator() {
    return digitalRead(Pedal_AC);
}

// Function to read the state of the brake pedal
int read_brake() {
    return digitalRead(Pedal_FR);
}

// Function to control the motor direction
void set_motor_direction(int direction) {
    if (direction == 1) { // Forward
        digitalWrite(Motor_DIR1, HIGH);
        digitalWrite(Motor_DIR2, LOW);
    } else if (direction == -1) { // Reverse
        digitalWrite(Motor_DIR1, LOW);
        digitalWrite(Motor_DIR2, HIGH);
    } else { // Stop
        digitalWrite(Motor_DIR1, LOW);
        digitalWrite(Motor_DIR2, LOW);
    }
}

// Function to turn on/off the headlights
void control_headlights(int state) {
    digitalWrite(Farol_Baixo, state);
}

// Function to turn on/off the turn signals
void control_turn_signal(int direction, int state) {
    if (direction == 0) { // Left
        digitalWrite(Luz_Seta_Esq, state);
    } else if (direction == 1) { // Right
        digitalWrite(Luz_Seta_Dir, state);
    }
}