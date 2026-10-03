/*
 * button.c
 *
 * Created: 10/3/2026 6:14:34 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 
#include "button.h"

void Button_Init(uint8_t port, uint8_t pin) {
	DIO_SetPinDirection(port, pin, INPUT);
}

uint8_t Button_Read(uint8_t port, uint8_t pin) {
	return DIO_ReadPin(port, pin);
}