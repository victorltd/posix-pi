#include <wiringPi.h>
#include <stdio.h>
#include "gpio_setup.h"

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
}
