/*
 * led.h
 *
 * Created: 10/3/2026 6:13:42 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

void LED_Init(uint8_t port, uint8_t pin);
void LED_TurnOn(uint8_t port, uint8_t pin);
void LED_TurnOff(uint8_t port, uint8_t pin);
void LED_Toggle(uint8_t port, uint8_t pin);

#endif