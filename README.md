# ESP8266 IoT Projects Repository

This repository is a collection of projects and examples showcasing the capabilities of the ESP8266 microcontroller for IoT applications. Each project is stored in the `Examples` folder, providing practical implementations of various IoT concepts.

## Repository Structure

```
ESP8266-IoT-Projects/
├── Examples/
│   ├── WiFi-Multi-Connection/
│   │   ├── WiFiMultiConnection.ino
│   │   └── README.md
│   ├── Temperature-Logging-InfluxDB/
│   │   ├── TemperatureLogger.ino
│   │   └── README.md
│   ├── MQTT-Data-Publisher/
│   │   ├── MQTTPublisher.ino
│   │   └── README.md
│   ├── Deep-Sleep-Power-Saving/
│   │   ├── DeepSleepExample.ino
│   │   └── README.md
│   └── README.md
├── README.md
└── LICENSE
```

## Projects in `Examples`

1. **WiFi Multi-Connection**
   - Demonstrates how to connect to multiple Wi-Fi networks using the ESP8266.
   - Includes error handling and debugging for reliable connectivity.

2. **Temperature Logging to InfluxDB**
   - Reads temperature data from a DS18B20 sensor and uploads it to an InfluxDB database.
   - Features multi-network support and optimized power usage with deep sleep.

3. **MQTT Data Publisher**
   - Publishes sensor data to an MQTT broker for real-time monitoring.
   - Configurable topics and QoS settings for different use cases.

4. **Deep Sleep Power Saving**
   - Demonstrates the use of deep sleep to conserve power.
   - Suitable for battery-operated IoT devices.

## How to Use the Repository

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Ali-Khajavi/ESP8266/
   ```

2. **Navigate to the Examples Folder**:
   Each example has its own subfolder containing the `.ino` file and a dedicated `README.md` with setup instructions.

3. **Load the Example Code**:
   - Open the `.ino` file in Arduino IDE or your preferred development environment.
   - Update configurations (Wi-Fi credentials, database URLs, etc.) as specified in the example's `README.md`.

4. **Upload and Test**:
   - Compile and upload the code to your ESP8266 board.
   - Monitor the serial output for debugging and ensure the functionality works as intended.

## Requirements

### Hardware
- ESP8266 development board (e.g., NodeMCU, Wemos D1 Mini)
- Sensors and peripherals as specified in individual examples
- Wi-Fi network for internet connectivity

### Software
- Arduino IDE or PlatformIO
- Required libraries (install via Arduino Library Manager):
  - `ESP8266WiFi`
  - `ESP8266WiFiMulti`
  - `InfluxDbClient`
  - `PubSubClient`
  - `OneWire` and `DallasTemperature` (if applicable)

## Contribution Guidelines

Contributions are welcome! You can:
- Submit new example projects.
- Report issues or suggest improvements.
- Open pull requests for code fixes or documentation enhancements.

## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Future Plans

- Expand the repository with more IoT examples, including:
  - Real-time dashboards
  - Advanced MQTT use cases
  - Integration with cloud platforms like AWS and Google Cloud
  - IoT security best practices

---

Happy coding! Feel free to explore, modify, and share your ESP8266 projects.
