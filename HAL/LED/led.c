/*
 * led.c
 *
 * Created: 10/3/2026 6:14:02 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 
#include "led.h"

void LED_Init(uint8_t port, uint8_t pin) {
	DIO_SetPinDirection(port, pin, OUTPUT);
}

void LED_TurnOn(uint8_t port, uint8_t pin) {
	DIO_WritePin(port, pin, HIGH);
}

void LED_TurnOff(uint8_t port, uint8_t pin) {
	DIO_WritePin(port, pin, LOW);
}

void LED_Toggle(uint8_t port, uint8_t pin) {
	DIO_TogglePin(port, pin);
}