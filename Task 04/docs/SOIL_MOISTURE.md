# Soil Moisture Sensor Notes

## Probe Type

Resistive Soil Moisture Sensor

## Wiring

* VCC → D7
* GND → GND
* AOUT → A1

## Calibration Results

| Condition | ADC Reading |
| --------- | ----------- |
| Dry       | 820         |
| Wet       | 380         |

## Observations

* Dry soil produced ADC readings around 820.
* Wet soil produced ADC readings around 380.
* Readings were mapped to a 0–100% relative moisture index.
* Powering the probe only during sampling helps reduce probe corrosion.

## Sensor Placement

* Probe inserted approximately 5 cm into the soil.
* Probe kept away from container walls for consistent readings.

## Result

The soil moisture sensor was successfully calibrated with dry and wet reference values of 820 and 380 respectively, enabling reliable soil moisture monitoring for irrigation control.
