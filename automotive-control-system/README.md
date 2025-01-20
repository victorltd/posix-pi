# Automotive Control System

## Overview
The Automotive Control System is designed to manage the electrical and motor control of an automotive system using a Raspberry Pi. The system interfaces with various sensors and actuators to control the vehicle's speed, direction, and electrical components such as lights and indicators.

## Project Structure
```
automotive-control-system
├── src
│   ├── main.c
│   ├── motor_control.c
│   ├── motor_control.h
│   ├── gpio_control.c
│   ├── gpio_control.h
│   ├── pwm_control.c
│   ├── pwm_control.h
│   ├── interrupt_handler.c
│   ├── interrupt_handler.h
│   └── utils.c
│       └── utils.h
├── include
│   ├── motor_control.h
│   ├── gpio_control.h
│   ├── pwm_control.h
│   ├── interrupt_handler.h
│   └── utils.h
├── Makefile
└── README.md
```

## Requirements
- The code is developed in C.
- The system must not have infinite loops that occupy 100% of the CPU.
- The system should implement PWM for motor control and braking.
- The system should handle user inputs through GPIO and respond accordingly.

## Compilation
To compile the project, navigate to the project directory and run the following command:

```
make
```

This will generate the executable for the automotive control system.

## Execution
To run the compiled program, use the following command:

```
./automotive_control_system
```

## Usage
- The system responds to user inputs from the accelerator and brake pedals, as well as buttons for controlling lights and cruise control.
- The dashboard displays the current speed, engine RPM, and other relevant information.
- Use the cruise control buttons to set, resume, or cancel the speed control.

## Notes
- Ensure that all hardware connections are properly set up as per the specifications before running the system.
- The program handles keyboard interrupts (Ctrl + C) to safely shut down and release resources.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.