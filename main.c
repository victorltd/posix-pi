#include <stdio.h>
#include <signal.h>
#include <wiringPi.h>
#include "gpio_setup.h"
#include "motor_control.h"
#include "light_control.h"

// Variável de controle para encerrar o programa
int running = 1;

// Tratador de sinal para encerrar
void handle_sigint(int sig) {
    running = 0;
    printf("\nEncerrando o programa...\n");
}

int main() {
    signal(SIGINT, handle_sigint); // Registrar tratador de Ctrl+C
    setup_gpio();                 // Configurar GPIO
    printf("Sistema iniciado. Pressione Ctrl + C para encerrar.\n");

    while (running) {
        controle_motor();         // Gerenciar motor
        controle_farol();         // Gerenciar faróis
        controle_setas();         // Gerenciar setas
        delay(100);               // Reduzir uso da CPU
    }

    return 0;
}
