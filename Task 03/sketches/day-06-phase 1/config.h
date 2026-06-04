#ifndef CONFIG_H
#define CONFIG_H

// Pin assignments
#define BTN_MANUAL  2
#define LED_STATUS  13
#define RELAY_VALVE 7

// Serial
#define BAUD_RATE 9600

// Debounce
#define DEBOUNCE_MS 50

// Relay logic (active-low module)
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

#endif
