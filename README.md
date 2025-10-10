# 🌾 **AGROSMART — IoT-Based Smart Irrigation System**

### 🚀 **Project for DEVIATHON 2025**  
**Theme:** Internet of Things (IoT)  
**Category:** Hardware–Software Integrated Solution  
**Team Name:** AlphaStack  

---

## 🟩 **1. Overview**
**AgroSmart** is an IoT-enabled smart irrigation and monitoring system designed to help farmers optimize water usage and improve crop yield.  
The system automates irrigation based on real-time data from soil moisture, water level, and water quality sensors, controlled through an **ESP32 microcontroller** and the **Blynk IoT platform**.

---

## 🟩 **2. Problem Statement**
In regions like **Jorethang, South Sikkim**, farmers face:

- Unpredictable rainfall and water scarcity  
- Excessive manual effort in irrigation  
- Lack of affordable automation tools  

These challenges lead to water wastage and decreased agricultural productivity.

---

## 🟩 **3. Proposed Solution**
AgroSmart integrates multiple sensors with IoT technology to automate and monitor irrigation intelligently.

- Measures soil moisture, water level, and water quality  
- Controls the water pump automatically through relay switching  
- Provides remote monitoring and control via the **Blynk IoT app**  
- Sends real-time alerts for low tank levels or poor water quality  

---

## 🟩 **4. System Architecture**
+---------------------------------------------------+
|             SENSOR LAYER (Inputs)                 |
| Soil Moisture | TDS | Turbidity | Ultrasonic      |
+--------------------------+------------------------+
                           |
                           v
                  +-------------------+
                  |    ESP32 Board    |
                  +-----+--------+----+
                        |        |
            Controls Pump       Sends Data
                        |        |
               +--------v--------v--------+
               |       Blynk Cloud        |
               +-----------+--------------+
                           |
                           v
                  [ Mobile Dashboard ]


---

## 🟩 **5. Hardware Components**

| **Component** | **Function** |
|----------------|--------------|
| ESP32 | Central control and Wi-Fi communication |
| Soil Moisture Sensor | Detects soil water content |
| TDS Sensor | Measures water purity (ppm) |
| Turbidity Sensor | Detects clarity of water |
| Ultrasonic Sensor | Measures tank water level |
| Relay Module | Controls pump operation |
| Submersible Pump | Waters the field automatically |

---

## 🟩 **6. Working Principle**
1. The soil moisture sensor monitors soil wetness continuously.  
2. When the soil becomes dry and the tank has sufficient water, the **relay activates the pump** automatically.  
3. The pump stops once the soil reaches the required moisture or the tank is low.  
4. Data from all sensors is sent to the **Blynk IoT dashboard**.  
5. Farmers can also manually control the pump through the mobile app.

---

## 🟩 **7. Blynk Dashboard Configuration**

| **Widget** | **Function** |
|-------------|--------------|
| Gauge 1 | Displays soil moisture percentage |
| Gauge 2 | Displays tank water level |
| Gauge 3 | Displays TDS value |
| Gauge 4 | Displays turbidity percentage |
| Button | Manual pump control |
| Notification | Alerts for low tank or poor water quality |

---

## 🟩 **8. Technologies Used**

| **Category** | **Tools / Platforms** |
|----------------|------------------------|
| Microcontroller | ESP32 |
| Programming | Arduino IDE |
| IoT Platform | Blynk |
| Connectivity | Wi-Fi |
| Power Source | USB / 5V DC |

---

## 🟩 **9. Key Features**
- Automatic irrigation based on soil moisture readings  
- Real-time monitoring via Blynk IoT app  
- Water quality and tank level analysis  
- Instant notifications and alerts  
- Manual pump control through the app  
- Low-cost, modular, and scalable design  

---

## 🟩 **10. Impact**

| **Area** | **Outcome** |
|-----------|-------------|
| Water Conservation | Reduces wastage through data-driven control |
| Productivity | Ensures consistent crop growth |
| Labor Efficiency | Minimizes manual supervision |
| Cost-effectiveness | Uses affordable and open-source components |
| Sustainability | Promotes smart and eco-friendly agriculture |

---

## 🟩 **11. Future Enhancements**
- Integration of weather APIs to avoid unnecessary irrigation  
- Solar-powered operation for energy efficiency  
- AI-driven irrigation prediction models  
- Crop-based threshold calibration  
- Dedicated Android app for regional language farmers  

---

## 🟩 **12. Team AlphaStack**

| **Member** | **Role** | **Responsibilities** |
|-------------|----------|----------------------|
| **Nency Chandiramani** | Team Leader, IoT Developer | System design, ESP32 programming, and Blynk integration |
| **Team Members** | Hardware, Testing, Presentation | Circuit assembly, testing, and documentation |

---

## 🟩 **13. Conclusion**
**AgroSmart** presents a sustainable, scalable, and affordable solution for smart agriculture.  
It automates irrigation, ensures water quality, and empowers farmers through data-driven decision-making.

**Tagline:**  
**“Every Drop Counts, Every Crop Matters — AgroSmart: Smarter Water, Better Harvest.”**

┌─────────────────────────────────────────────┐
