# ATmega32 Layered Architecture: LED & LCD Control System

A modular, layered-architecture Embedded C application developed for the **ATmega32** microcontroller. The system interacts with a push button to toggle a LED state while dynamically updating and displaying the current status on a 16x2 Character LCD using custom **MCAL** and **HAL** drivers.

---

## 📸 System Overview

* **Microcontroller:** ATmega32 (16 MHz External Crystal)
* **Architecture:** Modular Layered Architecture (MCAL / HAL / Application)
* **Peripherals Used:** DIO (GPIO), Character LCD (16x2), Push Button, LED
* **Simulation Tool:** Proteus Design Suite
* **IDE / Toolchain:** Microchip Studio (GCC C Compiler)

---

## 📁 Repository Structure

```text
ATmega32-LCD-LED-Driver-System/
├── MCAL/
│   └── DIO/
│       ├── dio.h          # DIO Driver Hardware Abstraction & API Prototypes
│       └── dio.c          # DIO Register-Level Implementation
├── HAL/
│   ├── LED/
│   │   ├── led.h          # LED Abstraction Interface
│   │   └── led.c          # LED Implementation using DIO APIs
│   ├── Button/
│   │   ├── button.h       # Button Abstraction Interface
│   │   └── button.c       # Button Implementation using DIO APIs
│   └── LCD/
│       ├── lcd.h          # LCD1602 Driver Interface (4-bit Mode)
│       └── lcd.c          # LCD1602 Driver Implementation (4-bit Mode)
├── main.c                 # Main Application Logic & Anti-Debounce Algorithm
└── README.md              # Project Documentation
```
⚡ Hardware Connections & Pinout
1. Character LCD (16x2) - 4-bit Mode
RS Pin: Connected to PB0 (Pin 1)

EN Pin: Connected to PB1 (Pin 2)

RW Pin: Connected directly to GND (Write Mode)

Data Bus (D4 - D7): Connected to PA4 - PA7 (Pins 36 to 33)

2. LED Module
Anode (+): Connected to PC0 (Pin 22)

Cathode (-): Connected through a 220Ω Current Limiting Resistor to GND

3. Push Button Module
Configuration: External Pull-Down Resistor (10kΩ to GND)

Input Signal Pin: Connected to PD0 (Pin 14)

Power Pin: Connected to +5V (High Active)

🚀 Key Features & Design Architecture
Layered Software Architecture: Designed with strict separation between MCAL (Microcontroller Abstraction Layer) and HAL (Hardware Abstraction Layer) for optimal code reusability, hardware independence, and scalability.

Software Anti-Debouncing: Built-in software delay algorithm in main.c to handle mechanical push button bouncing effects seamlessly.

Efficient Pin Utilization: Driven in 4-bit LCD mode to reduce required GPIO pins from 8 to 4 on PORTA.

🛠️ How to Build and Flash
Clone this repository to your local machine:
```
git clone [https://github.com/ahmedlashin1762005/ATmega32-LCD-LED-Driver-System.git](https://github.com/ahmedlashin1762005/ATmega32-LCD-LED-Driver-System.git)
```
Open the solution in Microchip Studio.

Select target device as ATmega32.

Press F7 to Build Solution.

Find the compiled .hex file inside the Debug/ folder and load it into ATmega32 or Proteus simulator.

👤 Author
ENG:Ahmed Lashin
