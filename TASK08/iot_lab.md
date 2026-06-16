Here's the README content modified for **your setup (NodeMCU ESP8266 + DHT11)** and your Device ID.

# IoT Lab Integration

## Objective

Post temperature and humidity telemetry data from a DHT11 sensor connected to a NodeMCU ESP8266 to the Zelbytes IoT Learning Lab dashboard.

## Device Information

* **Device ID:** nandana_01
* **Endpoint:** [https://careers.zelbytes.com/api/iot-lab/v1/telemetry](https://careers.zelbytes.com/api/iot-lab/v1/telemetry)
* **Telemetry Topic:** zelbytes/lab/36/telemetry

## Hardware Used

* NodeMCU ESP8266 (ESP-12E)
* DHT11 Temperature & Humidity Sensor
* Jumper Wires
* USB Cable
* Laptop/PC

## Architecture

The DHT11 sensor is connected to the NodeMCU ESP8266. The ESP8266 reads temperature and humidity values and sends them through the serial port. A Python script running on the host laptop reads the serial data, converts it into JSON format, and posts it to the Zelbytes IoT Lab telemetry endpoint using the API key stored securely.

```text
DHT11 Sensor
      ↓
NodeMCU ESP8266
      ↓ (Serial Data)
Python Script
      ↓ (HTTP POST)
Zelbytes IoT Lab
      ↓
Dashboard
```

## Field Mapping (CSV → JSON)

| CSV Column | JSON Field    | Type  | Description                  |
| ---------- | ------------- | ----- | ---------------------------- |
| temp       | temperature_c | float | Temperature in Celsius       |
| humidity   | humidity_pct  | float | Relative Humidity Percentage |

## Sample JSON Payload

```json
{
  "device_id": "nandana_01",
  "temperature_c": 29.5,
  "humidity_pct": 68.0
}
```

## Security

* API key is stored securely and never hardcoded in source files.
* Sensitive credentials are excluded from version control.
* API keys are not displayed in screenshots or reports.
* Only placeholder credentials are included in example files.

## Verification

* Telemetry data was successfully transmitted to the Zelbytes IoT Learning Lab endpoint.
* HTTP responses confirmed successful data submission.
* Data was verified through the IoT Lab Dashboard and API Explorer.
* Multiple temperature and humidity readings were recorded successfully.

## Wiring Connections

| DHT11 | NodeMCU ESP8266 |
| ----- | --------------- |
| GND   | GND             |
| VCC   | 3V3             |
| DATA  | D4 (GPIO2)      |

## Sample Serial Output

```text
29.4,67.0
29.5,68.0
29.5,68.0
29.6,69.0
```

## Conclusion

The NodeMCU ESP8266 successfully acquired temperature and humidity data from the DHT11 sensor and transmitted the telemetry data to the Zelbytes IoT Learning Lab dashboard through a Python-based host uploader. The system demonstrated reliable real-time monitoring and cloud integration capabilities.
