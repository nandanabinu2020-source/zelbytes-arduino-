DHT22 Sensor Notes

## Wiring

* VCC → 5V
* DATA → D4
* GND → GND
* 10 kΩ pull-up resistor between VCC and DATA

## Sensor Placement

* Mounted away from direct solenoid mist and water spray.
* Positioned in open air for accurate temperature and humidity measurement.

## Observations

* Temperature and humidity readings were obtained successfully.
* A 2-second interval was maintained between readings.
* Invalid readings were handled using `isnan()` checks.

## Result

The DHT22 sensor was successfully interfaced with the Arduino and provided stable temperature and humidity data in Serial Monitor output.
