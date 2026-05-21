# wifi-button-tracker

# Buttons For Like Activity

ESP32 project that tracks button presses and sends activity data to ThingSpeak using Wi-Fi.

## Features
- Wi-Fi connection with ESP32
- Sends data to ThingSpeak API
- Tracks 3 different buttons
- Real-time cloud data updates
- Serial Monitor logging

## Components
- ESP32
- 3 Push Buttons
- Jumper Wires

## Pin Configuration
- Button 1 → GPIO 12
- Button 2 → GPIO 5
- Button 3 → GPIO 2

## How It Works
1. ESP32 connects to Wi-Fi
2. User presses a button
3. Counter increases
4. Data is sent to ThingSpeak
5. Activity can be monitored remotely

## Technologies
- ESP32
- Arduino C++
- WiFi.h
- ThingSpeak API

## Setup

1. Add your Wi-Fi credentials:

```cpp
#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASS "YOUR_PASSWORD"
```

2. Add your ThingSpeak API key:

```cpp
#define TS_API_KEY "YOUR_WRITE_KEY"
```

3. Upload code to ESP32

## Preview

![Circuit](image.png)

## Author
Vasyl
