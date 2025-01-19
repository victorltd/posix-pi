#include <wiringPi.h>
#include <stdio.h>
#include "gpio_setup.h"

void controle_farol() {
    if (digitalRead(COMANDO_FAROL_BAIXO) == HIGH) {
        digitalWrite(FAROL_BAIXO, !digitalRead(FAROL_BAIXO));
        printf("Farol Baixo: %s\n", digitalRead(FAROL_BAIXO) ? "Ligado" : "Desligado");
    }

    if (digitalRead(COMANDO_FAROL_ALTO) == HIGH) {
        digitalWrite(FAROL_ALTO, !digitalRead(FAROL_ALTO));
        printf("Farol Alto: %s\n", digitalRead(FAROL_ALTO) ? "Ligado" : "Desligado");
    }
}

void controle_setas() {
    if (digitalRead(COMANDO_SETA_ESQUERDA) == HIGH) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(SETA_ESQUERDA, HIGH);
            delay(500);
            digitalWrite(SETA_ESQUERDA, LOW);
            delay(500);
        }
    }

    if (digitalRead(COMANDO_SETA_DIREITA) == HIGH) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(SETA_DIREITA, HIGH);
            delay(500);
            digitalWrite(SETA_DIREITA, LOW);
            delay(500);
        }
    }
}
