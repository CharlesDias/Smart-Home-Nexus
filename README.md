# SmartHomeNexus

Welcome to **SmartHomeNexus**, an open-source smart home system designed to create a seamless and efficient network of various embedded devices. Our goal is to design a system that is both flexible and scalable, leveraging the strengths of popular open-source tools and platforms.

At the heart of **SmartHomeNexus** is the IoT Gateway or Central Hub, which serves as the central communication and control point of the system. For this, we employ Python and Node-Red, known for their versatility and ease of use. These high-level programming tools enable efficient development of backend logic, including the integration and management of various communication protocols such as MQTT for messaging and BLE for device connectivity.

For the node devices, we utilize Real-Time Operating Systems (RTOS) like FreeRTOS and Zephyr. These RTOS choices provide robust performance and reliability, ideal for real-time data collection and processing in the embedded devices that constitute our network's backbone.

By integrating these technologies, **SmartHomeNexus** emerges as a comprehensive home automation solution. This fusion of technologies and frameworks exemplifies the effective application of open-source resources to build an advanced yet affordable home automation system.


## System Components

- **Central Hub**: [Raspberry Pi 4](https://www.raspberrypi.org/products/raspberry-pi-4-model-b/), leveraging its powerful processing capabilities to serve as the BLE gateway and MQTT broker within the smart home network.

- **Control Panel Hub**: [STM32H7B3I-DK Discovery kit](https://www.st.com/en/evaluation-tools/stm32h7b3i-dk.html), equipped with Zephyr RTOS and LVGL, functions as an interactive user interface for the smart home system.

- **Sensor Node**: Built with both [ESP32](https://www.espressif.com/en/products/socs/esp32) boards and [XIAO Sensor nRF52840](https://www.seeedstudio.com/XIAO-nRF52840-Sense-p-5026.html), these nodes are capable of collecting a variety of environmental data, such as temperature, humidity, and atmospheric pressure.

## Subprojects: Nodes

### Climate-Sense-Node-ESP32

- **Overview**: The `Climate-Sense-Node` is a dedicated subproject focused on environmental monitoring. It features the ESP32 microcontroller and BMP280 sensor to measure temperature, humidity, and atmospheric pressure. Data collected is sent to the MQTT broker for integration and analysis.

- **Technology**: Utilizes ESP32 for WiFi connectivity and the BMP280 sensor for accurate environmental readings. Data is transmitted via MQTT to the central SmartHomeNexus system.

[Project folder.](climate-sense-node-esp32/)

### Climate-Sense-Node-nRF52

Under development!

## Communication Architecture

- **BLE (Bluetooth Low Energy)**: The Raspberry Pi 4 operates as a BLE gateway, facilitating the connection between BLE-enabled devices, such as our XIAO Sensor nodes, and the central network.

- **MQTT**: As an MQTT broker, the Raspberry Pi 4 manages messaging between the networked devices and the control panel. MQTT protocol is utilized for its simplicity and efficiency in IoT device communication.

## Software Stack

- **Zephyr RTOS**: A secure, scalable real-time operating system for connected, resource-constrained devices that prioritizes security and modularity.

- **LVGL**: A powerful yet lightweight graphics library designed to create embedded GUIs with easy-to-use graphical elements, beautiful visual effects, and a low memory footprint.

- **BlueZ**: The official Linux Bluetooth stack, used here for managing Bluetooth Low Energy communications with the Raspberry Pi 4 acting as the BLE gateway.

- **Python**: A high-level programming language used for developing the backend logic on the Raspberry Pi 4, including scripting for the MQTT broker and interfacing with BlueZ.

## Getting Started

Under development!

## Contributing

We welcome contributions to the **SmartHomeNexus** project. Please review our contribution guidelines for details on how to submit pull requests, report issues, or suggest enhancements.

## License

SmartHomeNexus is released under the [Apache License 2.0](LICENSE). The Apache License is a permissive open-source software license that allows users to freely use, modify, distribute, and sell the software with less restrictive conditions compared to copyleft licenses like GPL. This license still maintains copyright and provides an express grant of patent rights from contributors to users.