# Automotive Control System

## Overview
The Automotive Control System is designed to manage the electrical and motor control of an automobile. It utilizes a Raspberry Pi 4 to interface with various sensors and actuators, allowing for functionalities such as motor control, cruise control, and user interface management.

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
│   ├── cruise_control.c
│   ├── cruise_control.h
│   ├── panel_control.c
│   ├── panel_control.h
│   └── utils.c
│       └── utils.h
├── Makefile
└── README.md
```

## Compilation Instructions
To compile the project, navigate to the project directory and run the following command:

```
make
```

This will compile all source files and generate the executable.

## Execution Instructions
After compilation, run the executable with the following command:

```
./automotive_control_system
```

Ensure that you have the necessary permissions to access GPIO pins on the Raspberry Pi.

## Usage
- **Pedal Control**: The system responds to the accelerator and brake pedals for manual speed control.
- **Cruise Control**: Use the following commands:
  - `RES`: Resume cruise control at the current speed.
  - `CANCEL`: Cancel cruise control.
  - `Set +`: Increase the desired speed by 1 km/h.
  - `Set -`: Decrease the desired speed by 1 km/h.
- **Indicators**: Activate left or right turn signals, which will blink at a rate of once per second.

## Dependencies
- WiringPi or SoftPWM for PWM control.
- POSIX threads for handling concurrent operations.

## Notes
- Ensure that all connections are properly made according to the schematic before running the system.
- The program handles keyboard interrupts (Ctrl + C) to safely shut down and release GPIO resources.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.