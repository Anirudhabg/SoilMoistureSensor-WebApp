# ESP8266 Soil Moisture Monitor

This project uses a NodeMCU ESP8266 and a soil moisture sensor to monitor soil moisture levels and display the readings on a web page.

## Components

- NodeMCU ESP8266
- Soil moisture sensor
- WiFi network

## Project Structure

```
ESP8266-Soil-Moisture-Monitor/
├── soil.ino
└── template/
    └── index.html
```

## Setup

### Hardware Connections

1. **Connect the Soil Moisture Sensor to NodeMCU ESP8266**:
    - **VCC** to **3.3V** on the ESP8266
    - **GND** to **GND** on the ESP8266
    - **Analog Output (AO)** to **A0** on the ESP8266

### Software Configuration

1. **Arduino IDE**:
    - Ensure you have the [Arduino IDE](https://www.arduino.cc/en/software) installed.
    - Install the ESP8266 board package. In the Arduino IDE, go to `File` > `Preferences`, and add `http://arduino.esp8266.com/stable/package_esp8266com_index.json` to the Additional Board Manager URLs. Then go to `Tools` > `Board` > `Boards Manager`, search for `esp8266` and install it.
    - Open the `soil.ino` file in the Arduino IDE.

2. **Update WiFi Credentials**:
    - In `soil.ino`, update the `ssid` and `password` variables with your WiFi network credentials.

```cpp
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
```

3. **Upload the Sketch**:
    - Connect your NodeMCU ESP8266 to your computer via USB.
    - Select the correct board and port in the Arduino IDE (`Tools` > `Board` > `NodeMCU 1.0 (ESP-12E Module)` and `Tools` > `Port` > select the appropriate port).
    - Click on the Upload button to upload the sketch to the ESP8266.

4. **Place `index.html` in the `template` Folder**:
    - Ensure that the `index.html` file is placed inside a folder named `template` in the same directory as `soil.ino`.

## Usage

1. **Power the NodeMCU ESP8266**:
    - After uploading the sketch, keep the NodeMCU ESP8266 powered via USB or an external power source.

2. **Connect to the WiFi Network**:
    - The NodeMCU ESP8266 will connect to the specified WiFi network. Open the Serial Monitor in the Arduino IDE to see the IP address assigned to the ESP8266.

3. **Open Web Browser**:
    - Open a web browser and navigate to `http://<ESP8266-IP-ADDRESS>/`, replacing `<ESP8266-IP-ADDRESS>` with the IP address shown in the Serial Monitor.

4. **View Soil Moisture Levels**:
    - The web page will display the current soil moisture level and automatically update it every 5 seconds.

## Example Output

Upon navigating to the ESP8266's IP address, you should see a web page displaying the soil moisture level:

```
Soil Moisture: 304
```

The value will update every 5 seconds to reflect the current soil moisture reading.



Happy Coding :)
