#ifndef CONFIG_H
#define CONFIG_H

// ---------------- Blynk Credentials ----------------
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "AgroSmart"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

// ---------------- WiFi Credentials ----------------
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"

// ---------------- Sensor Thresholds ----------------
#define MOISTURE_THRESHOLD 40      // % soil moisture
#define TANK_MIN_LEVEL 12          // cm
#define TDS_THRESHOLD 700          // ppm
#define TURBIDITY_THRESHOLD 65     // %

#endif
