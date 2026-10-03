/*
 * lcd.c
 *
 * Created: 10/3/2026 6:15:37 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 
#include "lcd.h"

static void LCD_PulseEnable(void) {
	DIO_WritePin(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_us(1);
	DIO_WritePin(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_us(100);
}

void LCD_SendCommand(uint8_t cmd) {
	DIO_WritePin(LCD_CTRL_PORT, RS_PIN, LOW);

	DIO_WritePin(LCD_DATA_PORT, PIN4, (cmd >> 4) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN5, (cmd >> 5) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN6, (cmd >> 6) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN7, (cmd >> 7) & 1);
	LCD_PulseEnable();

	DIO_WritePin(LCD_DATA_PORT, PIN4, (cmd >> 0) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN5, (cmd >> 1) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN6, (cmd >> 2) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN7, (cmd >> 3) & 1);
	LCD_PulseEnable();

	_delay_ms(2);
}

void LCD_SendChar(char data) {
	DIO_WritePin(LCD_CTRL_PORT, RS_PIN, HIGH);

	DIO_WritePin(LCD_DATA_PORT, PIN4, (data >> 4) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN5, (data >> 5) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN6, (data >> 6) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN7, (data >> 7) & 1);
	LCD_PulseEnable();

	DIO_WritePin(LCD_DATA_PORT, PIN4, (data >> 0) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN5, (data >> 1) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN6, (data >> 2) & 1);
	DIO_WritePin(LCD_DATA_PORT, PIN7, (data >> 3) & 1);
	LCD_PulseEnable();

	_delay_ms(2);
}

void LCD_Init(void) {
	DIO_SetPinDirection(LCD_DATA_PORT, PIN4, OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, PIN5, OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, PIN6, OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT, PIN7, OUTPUT);

	DIO_SetPinDirection(LCD_CTRL_PORT, RS_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, EN_PIN, OUTPUT);

	_delay_ms(20);
	LCD_SendCommand(0x02);
	LCD_SendCommand(0x28);
	LCD_SendCommand(0x0C);
	LCD_SendCommand(0x01);
}

void LCD_SendString(const char *str) {
	while(*str) {
		LCD_SendChar(*str++);
	}
}

void LCD_Clear(void) {
	LCD_SendCommand(0x01);
}