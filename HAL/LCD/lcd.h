/*
 * lcd.h
 *
 * Created: 10/3/2026 6:15:18 PM
 *  Author: Administrator
 * Created by: AhmedLashin (AL6)
 */ 

#ifndef LCD_H_
#define LCD_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include "../../MCAL/DIO/dio.h"

#define LCD_DATA_PORT PORT_A
#define LCD_CTRL_PORT PORT_B

#define RS_PIN PIN0
#define EN_PIN PIN1

void LCD_Init(void);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendChar(char data);
void LCD_SendString(const char *str);
void LCD_Clear(void);

#endif