# PWM Motor Control with Emergency Stop and Valve Control

## Objective

The objective of this project is to control the speed of a DC motor using Pulse Width Modulation (PWM) and implement an interrupt-based Emergency Stop (E-Stop) mechanism. The system also controls a solenoid valve through a relay module, ensuring safe shutdown during emergency conditions.

## Components Used

* Arduino Uno
* DC Motor
* Motor Driver Module
* Relay Module (Active LOW)
* Solenoid Valve
* Push Button (Emergency Stop)
* LED
* 220Ω Resistor
* 10kΩ Resistor
* Breadboard
* Jumper Wires
* 12V Power Supply

## System Description

The Arduino Uno generates PWM signals to control the speed of the DC motor through a motor driver module. The motor speed can be adjusted by sending values from 0 to 255 through the Serial Monitor.

A relay module is used to control a solenoid valve. When the motor is running, the valve opens. When the motor stops or an emergency condition occurs, the valve closes automatically.

An Emergency Stop push button is connected to an interrupt pin (D2). When pressed, the interrupt service routine immediately stops the motor, closes the valve, and disables the system until a reset is performed.

An LED acts as a system status indicator.

## Hardware Connections

### Motor Driver

* D9 → ENA (PWM)
* D6 → IN1
* D7 → IN2
* GND → Driver GND

### Relay Module

* D8 → IN
* 5V → VCC
* GND → GND

### Emergency Stop Button

* One side → 5V
* Other side → D2
* 10kΩ resistor between D2 and GND

### Status LED

* D13 → 220Ω resistor → LED Anode
* LED Cathode → GND

### Solenoid Valve

* Relay COM → +12V
* Relay NO → Solenoid Positive
* Solenoid Negative → 12V GND

### Power Supply

* 12V Supply powers Motor Driver and Solenoid Valve
* Arduino powered through USB

## Working Principle

1. The Arduino receives motor speed values through the Serial Monitor.
2. PWM signals are generated on pin D9.
3. The motor driver adjusts the motor speed according to the PWM duty cycle.
4. When the motor starts, the relay activates and opens the solenoid valve.
5. The status LED remains ON during normal operation.
6. Pressing the Emergency Stop button triggers an interrupt.
7. The interrupt immediately:

   * Stops the motor
   * Closes the valve
   * Turns OFF the status LED
   * Halts system operation
8. The system remains stopped until manually reset.

## Expected Output

* Motor speed varies according to PWM value.
* Solenoid valve opens when the motor runs.
* Solenoid valve closes when the motor stops.
* Emergency Stop instantly halts the entire system.
* LED indicates system status.

## Applications

* Automated irrigation systems
* Water pumping systems
* Industrial motor control
* Safety-critical automation systems
* Smart agriculture projects

## Result

The DC motor was successfully controlled using PWM signals. The emergency stop mechanism responded immediately through hardware interrupts, ensuring safe motor shutdown and automatic valve closure.
ed and verified for proper operation.
