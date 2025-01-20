#include <wiringPi.h>
#include <stdio.h>
#include "gpio_setup.h"

int velocidade_desejada = 0;
int cruise_control_ativo = 0;

void controle_motor() {
    if (digitalRead(PEDAL_ACELERADOR) == HIGH) {
        pwmWrite(MOTOR_POT, 512); // 50% de potência
        digitalWrite(MOTOR_DIR1, HIGH);
        digitalWrite(MOTOR_DIR2, LOW);
        printf("Acelerando...\n");
    }

    if (digitalRead(PEDAL_FREIO) == HIGH) {
        pwmWrite(MOTOR_POT, 0); // Potência zero
        digitalWrite(LUZ_FREIO, HIGH);
        printf("Freando...\n");
    } else {
        digitalWrite(LUZ_FREIO, LOW);
    }

    if (cruise_control_ativo) {
        // Implementar lógica de controle de velocidade
    }
}

void controle_cruise_control() {
    if (digitalRead(CC_RES) == HIGH) {
        cruise_control_ativo = 1;
        printf("Cruise Control Ativado\n");
    }

    if (digitalRead(CC_CANCEL) == HIGH) {
        cruise_control_ativo = 0;
        printf("Cruise Control Desativado\n");
    }
}
