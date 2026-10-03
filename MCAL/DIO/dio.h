/*
 * dio.h
 *
 * Created: 10/3/2026 6:12:54 PM
 *  Author: Administrator
 * Created by: AhmedLashin (AL6)
 */ 
#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

void DIO_SetPinDirection(uint8_t port, uint8_t pin, uint8_t direction);
void DIO_WritePin(uint8_t port, uint8_t pin, uint8_t value);
uint8_t DIO_ReadPin(uint8_t port, uint8_t pin);
void DIO_TogglePin(uint8_t port, uint8_t pin);

#endif