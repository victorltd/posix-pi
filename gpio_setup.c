#include <wiringPi.h>
#include "gpio_setup.h"

// Definir pinos GPIO
#define PEDAL_ACELERADOR 27
#define PEDAL_FREIO 22
#define LUZ_FREIO 25
#define FAROL_BAIXO 19
#define FAROL_ALTO 26
#define COMANDO_FAROL_BAIXO 16
#define COMANDO_FAROL_ALTO 1
#define SETA_ESQUERDA 8
#define SETA_DIREITA 7
#define COMANDO_SETA_ESQUERDA 20
#define COMANDO_SETA_DIREITA 21
#define MOTOR_DIR1 17
#define MOTOR_DIR2 18
#define MOTOR_POT 23

void setup_gpio() {
    wiringPiSetupGpio();
    pinMode(PEDAL_ACELERADOR, INPUT);
    pinMode(PEDAL_FREIO, INPUT);
    pinMode(LUZ_FREIO, OUTPUT);
    pinMode(FAROL_BAIXO, OUTPUT);
    pinMode(FAROL_ALTO, OUTPUT);
    pinMode(COMANDO_FAROL_BAIXO, INPUT);
    pinMode(COMANDO_FAROL_ALTO, INPUT);
    pinMode(SETA_ESQUERDA, OUTPUT);
    pinMode(SETA_DIREITA, OUTPUT);
    pinMode(COMANDO_SETA_ESQUERDA, INPUT);
    pinMode(COMANDO_SETA_DIREITA, INPUT);
    pinMode(MOTOR_DIR1, OUTPUT);
    pinMode(MOTOR_DIR2, OUTPUT);
    pinMode(MOTOR_POT, PWM_OUTPUT);
}
