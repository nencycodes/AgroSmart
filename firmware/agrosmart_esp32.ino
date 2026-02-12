/*****************************************************
 * AGROSMART - IoT Smart Irrigation System
 * Developed by: Nency Chandiramani
 * Board: ESP32 Dev Module
 * Platform: Blynk IoT
 *****************************************************/

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "config.h"

// ---------------- Pin Definitions ----------------
#define SOIL_PIN 34
#define TDS_PIN 35
#define TURBIDITY_PIN 32
#define TRIG_PIN 5
#define ECHO_PIN 18
#define RELAY_PIN 23

// Timer for periodic updates
BlynkTimer timer;

// ---------------- Setup ----------------
void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(RELAY_PIN, HIGH);  // Pump OFF initially

  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);

  timer.setInterval(4000L, sendSensorData);
}

// ---------------- Main Loop ----------------
void loop() {
  Blynk.run();
  timer.run();
}

// ---------------- Sensor Reading Functions ----------------

// Soil moisture mapped to percentage
int readSoilMoisture() {
  int rawValue = analogRead(SOIL_PIN);
  int moisturePercent = map(rawValue, 0, 4095, 100, 0);
  return constrain(moisturePercent, 0, 100);
}

// Tank level using ultrasonic sensor
float readTankLevel() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

// Basic TDS calculation (raw to ppm approximation)
int readTDS() {
  int rawValue = analogRead(TDS_PIN);
  int tdsValue = map(rawValue, 0, 4095, 0, 1000);
  return tdsValue;
}

// Turbidity mapped to %
int readTurbidity() {
  int rawValue = analogRead(TURBIDITY_PIN);
  int turbidityPercent = map(rawValue, 0, 4095, 0, 100);
  return turbidityPercent;
}

// ---------------- Control Logic ----------------
void controlPump(int moisture, float tankLevel) {

  if (moisture < MOISTURE_THRESHOLD && tankLevel > TANK_MIN_LEVEL) {
    digitalWrite(RELAY_PIN, LOW);   // Pump ON
  } 
  else {
    digitalWrite(RELAY_PIN, HIGH);  // Pump OFF
  }
}

// ---------------- Data Transmission ----------------
void sendSensorData() {

  int soil = readSoilMoisture();
  float tank = readTankLevel();
  int tds = readTDS();
  int turbidity = readTurbidity();

  controlPump(soil, tank);

  // Send data to Blynk Dashboard
  Blynk.virtualWrite(V0, soil);
  Blynk.virtualWrite(V1, tank);
  Blynk.virtualWrite(V2, tds);
  Blynk.virtualWrite(V3, turbidity);

  // Alerts
  if (tank < TANK_MIN_LEVEL) {
    Blynk.logEvent("low_tank", "⚠ Tank level is critically low.");
  }

  if (tds > TDS_THRESHOLD) {
    Blynk.logEvent("high_tds", "⚠ High TDS detected.");
  }

  if (turbidity > TURBIDITY_THRESHOLD) {
    Blynk.logEvent("high_turbidity", "⚠ Water turbidity is high.");
  }

  Serial.println("Sensor data transmitted to Blynk.");
}
