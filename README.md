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
