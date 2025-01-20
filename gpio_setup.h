#ifndef GPIO_SETUP_H
#define GPIO_SETUP_H

// Definições dos pinos GPIO
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

// Declaração da função de setup
void setup_gpio();

#endif // GPIO_SETUP_H
