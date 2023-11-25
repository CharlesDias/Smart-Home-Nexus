# Climate Sense Node for ESP32

## Overview

`Climate-Sense-Node` is a dedicated subproject within the `SmartHomeNexus` ecosystem, aimed at environmental monitoring. It utilizes the ESP32 microcontroller in conjunction with the BMP280 sensor to gather real-time data on temperature, humidity, and atmospheric pressure. This data is then transmitted to an MQTT broker over a WiFi connection for integration into the broader `SmartHomeNexus` system.

## Key Features
- **Environmental Monitoring**: Accurate readings of temperature, humidity, and atmospheric pressure using the BMP280 sensor.
- **WiFi Connectivity**: Employs the ESP32's WiFi capabilities for network communication.
- **MQTT Integration**: Seamlessly transmits sensor data to a specified MQTT broker, enabling integration with smart home applications.

## Configuration

Before deploying `Climate-Sense-Node`, you need to configure the MQTT Broker URL and WiFi settings:

* Open the project configuration menu (`idf.py menuconfig or via ESP-IDF VSCode Plugin.`).
* Configure the MQTT Broker URL under "Example Configuration" menu.
* Configure Wi-Fi or Ethernet under "Example Connection Configuration" menu.

These settings enable the ESP32 to connect to your WiFi network and communicate with the MQTT broker.

## Getting Started

1. Navigate to the Project Directory:
   ```bash
   cd Smart-Home-Nexus/climate-sense-node-esp32/
   ```

2. Configure the MQTT Broker URL and WiFi settings::
   - Open the project configuration menu (`idf.py menuconfig`).
   - Configure the MQTT Broker URL under "Example Configuration" menu.
   - Configure Wi-Fi or Ethernet under "Example Connection Configuration" menu.

3. Build and Flash the Firmware:
   ```bash
   idf.py build
   idf.py -p (YOUR_ESP32_PORT) flash
   ```

4. Monitor Output:
   ```bash
   idf.py -p (YOUR_ESP32_PORT) monitor
   ```
   This command allows you to view the ESP32's real-time logs. You should see the sensor data (temperature, humidity, and pressure) being sent to your MQTT broker.

## Contributing

We welcome contributions to `Climate-Sense-Node`. Please consult our contributing guidelines for details on how to submit pull requests, report issues, and suggest improvements.

## License

`Climate-Sense-Node` is part of SmartHomeNexus and is released under the [Apache License 2.0](LICENSE).
