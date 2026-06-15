# Sensor Data Logger

## Objective

The objective of this project is to collect and log environmental sensor data over a 30-minute period using an Arduino Uno. The system records temperature, humidity, soil moisture, and light intensity readings and outputs them in CSV format for analysis and storage.

## Components Used

* Arduino Uno
* DHT22 Temperature and Humidity Sensor
* Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* 10 kΩ Resistor (for LDR voltage divider)
* Breadboard
* Jumper Wires
* USB Cable

## Sensor Connections

### DHT22

| DHT22 Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| DATA      | D2          |
| GND       | GND         |

### Soil Moisture Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

### LDR

| Component      | Arduino Pin |
| -------------- | ----------- |
| LDR Output     | A1          |
| Other LDR Leg  | 5V          |
| 10 kΩ Resistor | A1 to GND   |

## Data Logging Format

The sensor readings are logged in CSV format with the following columns:

timestamp,time,temp,humidity,soil,light

Where:

* timestamp = elapsed time in milliseconds
* time = elapsed time in HH:MM:SS format
* temp = temperature in °C
* humidity = relative humidity in %
* soil = soil moisture analog value (0–1023)
* light = LDR analog value (0–1023)

## Sample Data

timestamp,time,temp,humidity,soil,light

0,00:00:00,29.4,71.8,540,315

30000,00:00:30,29.5,71.7,538,318

60000,00:01:00,29.5,71.7,537,320

## Logging Configuration

* Logging Duration: 30 Minutes
* Sampling Interval: 30 Seconds
* Total Samples: 60
* Output Format: CSV

## Procedure

1. Assemble the circuit according to the connection table.
2. Install the required Arduino libraries:

   * DHT Sensor Library
3. Open the Arduino IDE.
4. Upload the sensor_logger.ino sketch to the Arduino Uno.
5. Open the Serial Monitor.
6. Set the baud rate to 9600.
7. Allow the system to run for 30 minutes.
8. Copy the generated CSV output.
9. Save the output as data/sample_log.csv.

## Repository Structure

sensor-data-logger/

├── README.md

├── src/

│   └── sensor_logger.ino

├── data/

│   └── sample_log.csv

└── docs/

## Expected Outcome

The system successfully records:

* Temperature
* Humidity
* Soil Moisture
* Light Intensity

The collected data is stored in CSV format and can be imported into spreadsheet software such as Microsoft Excel, Google Sheets, or LibreOffice Calc for further analysis.
