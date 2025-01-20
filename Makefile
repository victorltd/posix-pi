CC = gcc
CFLAGS = -lwiringPi
OBJ = main.o gpio_setup.o motor_control.o light_control.o

all: sistema

sistema: $(OBJ)
	$(CC) -o sistema $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o sistema
