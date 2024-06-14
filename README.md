markdown
Copy code
# ESP8266 Weather Monitoring Dashboard

## Overview

This project uses an ESP8266 microcontroller with BMP085 and DHT11 sensors to monitor temperature, humidity, pressure, and altitude. The sensor readings are displayed in real-time on a web dashboard accessible from a browser.

## Components Used

- ESP8266 NodeMCU
- BMP085 Pressure Sensor
- DHT11 Temperature and Humidity Sensor
- LEDs and resistors (for indication)
- WiFi Router

## Libraries Required

- ESP8266WiFi
- WiFiClient
- ESP8266WebServer
- Wire (for I2C communication)
- Adafruit_BMP085 (for BMP085 sensor)
- DHT (for DHT11 sensor)

## Installation and Setup

1. **Hardware Setup**:
   - Connect the BMP085 sensor and DHT11 sensor to the ESP8266 according to the wiring specified in your code (`DHTpin`, `A0`, I2C pins for BMP085).

2. **Software Setup**:
   - Install the Arduino IDE and necessary libraries (`ESP8266WiFi`, `Adafruit_BMP085`, `DHT`).
   - Copy the provided code into the Arduino IDE.
   - Modify the code to include your WiFi SSID and password (`ssid` and `password` variables).

3. **Upload the Code**:
   - Select the appropriate board and COM port in the Arduino IDE.
   - Click on **Upload** to upload the code to your ESP8266.

4. **Accessing the Dashboard**:
   - Once uploaded, open the Serial Monitor to view the ESP8266's IP address.
   - Enter this IP address in a web browser on your local network to access the real-time weather dashboard.

## Usage

1. **Web Dashboard**:
   - The dashboard displays charts (using Chart.js) for altitude, temperature, and humidity.
   - Data is updated dynamically using AJAX requests to the ESP8266 server (`readADC` endpoint).

2. **LED Indication**:
   - The onboard LED (`LED` pin) toggles with each data update, indicating server activity.

## Notes

- Ensure stable WiFi connectivity for reliable data updates.
- Customize the HTML (`index.h`) and JavaScript (`<script>` section in `index.h`) for additional features or visual enhancements.


## Authors

- **Antarikchya Pratisthan Nepal** [https://antarikchya.org.np/]
