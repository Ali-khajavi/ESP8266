# ESP8266 IoT Data Logger with InfluxDB Integration

This project demonstrates a simple and efficient IoT data logging solution using the ESP8266 microcontroller. It connects to multiple Wi-Fi networks, collects temperature data from a DS18B20 sensor, and uploads the data to an InfluxDB database. The system is optimized for low power consumption using deep sleep mode.

## Features

- **Multi-WiFi Connectivity**: Automatically connects to the strongest available Wi-Fi network.
- **Temperature Monitoring**: Supports the DS18B20 temperature sensor via OneWire protocol.
- **InfluxDB Integration**: Uploads sensor data to an InfluxDB instance with customizable tags and fields.
- **Power Efficiency**: Includes deep sleep functionality and GPIO-based sensor power management.

## Project Structure

### Libraries Used

1. **ESP8266WiFi**: For managing Wi-Fi connections.
2. **ESP8266WiFiMulti**: Enables multi-network support.
3. **InfluxDbClient**: Communicates with the InfluxDB instance.
4. **OneWire & DallasTemperature** (optional): Interfaces with the DS18B20 temperature sensor.

### Configuration Parameters

- Wi-Fi credentials for up to two networks.
- InfluxDB connection details:
  - URL
  - Token
  - Organization name
  - Bucket name

### Functional Highlights

1. **Wi-Fi Connection**:
   - Automatically connects to the strongest configured network.
   - Reports connection status to the serial monitor.
2. **Temperature Sensor**:
   - Reads temperature data via the DS18B20 sensor.
   - Sensor power control for enhanced energy efficiency.
3. **InfluxDB Integration**:
   - Uploads temperature data to InfluxDB with pre-defined tags and fields.
4. **Power Management**:
   - Deep sleep mode to reduce power consumption when not in use.

## Requirements

### Hardware

- **ESP8266 Development Board** (e.g., NodeMCU or Wemos D1 Mini)
- **DS18B20 Temperature Sensor** (optional)
- **Pull-Up Resistor**: For DS18B20 data line
- **Wi-Fi Network**

### Software

- Arduino IDE or PlatformIO
- Required libraries (install via Arduino Library Manager):
  - `ESP8266WiFi`
  - `ESP8266WiFiMulti`
  - `InfluxDbClient`
  - `OneWire` (optional)
  - `DallasTemperature` (optional)

## Setup and Usage

1. **Hardware Setup**:
   - Connect the DS18B20 sensor to the ESP8266:
     - Data pin to `D2` (default, can be configured).
     - Ground and VCC pins to respective ESP8266 pins.
   - Add a 4.7kΩ pull-up resistor between the data pin and VCC.

2. **Software Configuration**:
   - Clone this repository.
   - Open the `.ino` file in Arduino IDE.
   - Update the following placeholders in the code:
     - Wi-Fi SSID and Password
     - InfluxDB URL, Token, Organization, and Bucket.
     - Device tag and point name.
   - Comment or uncomment temperature sensor-related code as needed.

3. **Upload Code**:
   - Connect the ESP8266 to your computer.
   - Select the correct board and port in Arduino IDE.
   - Compile and upload the code.

4. **Monitor and Test**:
   - Open the Serial Monitor to view connection status and debug messages.
   - Verify that the temperature data is successfully logged in your InfluxDB instance.

## Customization

- **Additional Sensors**:
  Extend the project by adding more sensors (e.g., humidity, pressure) and upload their data to InfluxDB.
- **Low Power Optimization**:
  Modify the deep sleep duration based on your use case.
- **Error Handling**:
  Enhance the code with retry mechanisms for failed Wi-Fi or database connections.

## Future Enhancements

- Add MQTT support for real-time data streaming.
- Implement OTA updates for easier firmware management.
- Expand compatibility with other databases and cloud platforms.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests for bug fixes or new features.
