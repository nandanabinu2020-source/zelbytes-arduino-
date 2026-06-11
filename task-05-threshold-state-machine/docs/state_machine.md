# Irrigation State Machine

## Objective

Implement an irrigation controller using a finite state machine (FSM) with explicit states instead of nested conditional logic. The system uses soil moisture thresholds, debounce logic, hysteresis, maximum irrigation duration, and cooldown periods to ensure reliable operation.

## States

### IDLE

* Initial state after startup.
* Irrigation is OFF.
* Transitions to MONITORING.

### MONITORING

* Reads soil moisture values.
* Applies debounce logic.
* Checks whether moisture remains below the minimum threshold for consecutive readings.
* Transitions to IRRIGATING when irrigation conditions are met.

### IRRIGATING

* Relay and valve are activated.
* Continues watering until:

  * Soil moisture reaches the target threshold, or
  * Maximum irrigation duration is reached.
* Transitions to COOLDOWN.

### COOLDOWN

* Irrigation remains OFF.
* Prevents immediate retriggering.
* Returns to MONITORING after the cooldown period expires.

## Thresholds

| Parameter           | Value       |
| ------------------- | ----------- |
| SOIL_MIN            | 25%         |
| SOIL_TARGET         | 40%         |
| LOW_COUNT_REQUIRED  | 4           |
| MAX_IRRIGATION_TIME | 120 seconds |
| COOLDOWN_TIME       | 60 seconds  |

## Hysteresis

To prevent relay chatter:

* Irrigation starts when soil moisture falls below 25%.
* Irrigation stops when soil moisture rises above 40%.

This creates a gap between ON and OFF thresholds, preventing rapid switching.

## Debounce Logic

The system requires multiple consecutive low-moisture readings before starting irrigation.

Example:

Reading 1: 24%
Reading 2: 23%
Reading 3: 24%
Reading 4: 22%

After four consecutive readings below SOIL_MIN, irrigation begins.

## State Diagram

stateDiagram-v2

    [*] --> IDLE

    IDLE --> MONITORING

    MONITORING --> IRRIGATING :
    Soil < SOIL_MIN
    for N consecutive readings

    IRRIGATING --> COOLDOWN :
    Soil >= SOIL_TARGET

    IRRIGATING --> COOLDOWN :
    Max Irrigation Time Reached

    COOLDOWN --> MONITORING :
    Cooldown Timer Expired
```

## Serial Debug Logging

Example output:

```text
[STATE] IDLE -> MONITORING

[STATE] MONITORING -> IRRIGATING
Soil Moisture = 22%

[STATE] IRRIGATING -> COOLDOWN
Reason: Target Moisture Reached

[STATE] COOLDOWN -> MONITORING
```

## Safety Notes

* Supervised wet testing only.
* Solenoid valve must never be connected directly to Arduino GPIO pins.
* Relay interlocks from Day 5 remain mandatory.
* Disconnect power before modifying wiring.

