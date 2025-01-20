#ifndef UTILS_H
#define UTILS_H

// Function to initialize the system
void init_system(void);

// Function to convert RPM to speed in km/h
float rpm_to_speed(int rpm);

// Function to calculate distance traveled
float calculate_distance(float speed, float time);

// Function to reset distance counter
void reset_distance(void);

// Function to get the current distance traveled
float get_distance(void);

#endif // UTILS_H