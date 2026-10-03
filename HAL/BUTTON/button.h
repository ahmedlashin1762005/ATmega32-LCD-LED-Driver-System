/*
 * button.h
 *
 * Created: 10/3/2026 6:14:55 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"

void Button_Init(uint8_t port, uint8_t pin);
uint8_t Button_Read(uint8_t port, uint8_t pin);

#endif