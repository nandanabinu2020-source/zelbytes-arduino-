# Relay Module Testing

## Objective
The objective of this task is to test the operation of a relay module using an Arduino Uno. The relay acts as an electrically controlled switch that allows low-power control signals from the Arduino to control higher-power loads safely.

## Components Used
- Arduino Uno
- Relay Module (Active LOW)
- Jumper Wires
- USB Cable
- Breadboard (optional)

## Circuit Connections

| Relay Module | Arduino Uno |
|-------------|-------------|
| VCC | 5V |
| GND | GND |
| IN | D8 |

## Working Principle
The Arduino sends a digital signal to the relay module through pin D8.

- When D8 is LOW, the relay is activated.
- When D8 is HIGH, the relay is deactivated.

The relay repeatedly switches between ON and OFF states, allowing verification of its operation through an audible clicking sound and status LED indication on the relay module.

## Testing Procedure
1. Connect the relay module to the Arduino according to the wiring diagram.
2. Upload the relay testing code.
3. Open the Serial Monitor at 9600 baud rate.
4. Observe the relay switching ON and OFF every two seconds.
5. Listen for the clicking sound and check the relay indicator LED.

## Expected Output
- Relay clicks every two seconds.
- Relay indicator LED turns ON and OFF.
- Serial Monitor displays relay status messages.

## Applications
- Home automation systems
- Irrigation systems
- Industrial control systems
- Smart energy management
- Motor and solenoid valve control

## Result
The relay module was successfully tested and verified for proper operation.
