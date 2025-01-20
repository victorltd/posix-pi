CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -pedantic
SRC=src/main.c src/motor_control.c src/gpio_control.c src/pwm_control.c src/interrupt_handler.c src/utils.c
OBJ=$(SRC:.c=.o)
TARGET=automotive_control_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean