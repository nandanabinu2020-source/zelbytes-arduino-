LDR Calibration

## Components

* Arduino Uno/Nano
* LDR
* 10 kΩ Resistor

## Calibration Results

| Condition | ADC Reading |
| --------- | ----------- |
| Dark      | 95          |
| Bright    | 910         |

## Thresholds

| Level   | Range      |
| ------- | ---------- |
| Dark    | 0 – 300    |
| Ambient | 301 – 700  |
| Bright  | 701 – 1023 |

## Notes

* 10 kΩ resistor used in the voltage divider.
* 8-sample averaging reduced reading jitter.
* LDR placed facing upward for ambient light measurement.

## Conclusion

The LDR was calibrated successfully with dark and bright reference values of 95 and 910 respectively.
