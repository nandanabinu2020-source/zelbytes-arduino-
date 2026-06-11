# Irrigation State Machine Controller

## Objective

Develop an automated irrigation controller using a finite state machine (FSM). The system monitors soil moisture and activates irrigation only when required. Debounce logic, hysteresis, maximum runtime limits, and cooldown periods are implemented to improve reliability and prevent unnecessary switching.

---

## Features

* Finite State Machine (FSM) implementation
* States: IDLE, MONITORING, IRRIGATING, COOLDOWN
* Soil moisture threshold monitoring
* Hysteresis to prevent relay chatter
* Debounced low-moisture detection
* Maximum irrigation runtime protection
* Cooldown period after irrigation
* Serial logging for debugging
* Relay-based valve control

---

## Hardware Used

* Arduino Uno
* Soil Moisture Sensor
* Relay Module
* Solenoid Valve
* Jumper Wires
* USB Cable

---

## State Machine Overview

The irrigation controller operates using the following states:

1. IDLE

   * System startup state.

2. MONITORING

   * Reads soil moisture.
   * Applies debounce logic.

3. IRRIGATING

   * Activates relay and valve.
   * Continues until target moisture is reached or maximum runtime expires.

4. COOLDOWN

   * Prevents immediate retriggering after irrigation.

---

## Threshold Configuration

```cpp
#define SOIL_MIN 25
#define SOIL_TARGET 40
#define LOW_COUNT_REQUIRED 4
#define MAX_IRRIGATION_TIME 120000UL
#define COOLDOWN_TIME 60000UL
```

---

## Hysteresis Logic

* Irrigation starts below 25% soil moisture.
* Irrigation stops above 40% soil moisture.

This prevents rapid ON/OFF switching near a single threshold.

---

## Safety

* Perform wet testing only under supervision.
* Never drive a solenoid valve directly from an Arduino pin.
* Always use a relay module for valve control.
* Verify wiring before powering the system.




