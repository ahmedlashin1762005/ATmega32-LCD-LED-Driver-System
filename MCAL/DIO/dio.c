/*
 * dio.c
 *
 * Created: 10/3/2026 6:13:16 PM
 *  Author: Administrator
 *  Created by: AhmedLashin (AL6)
 */ 
#include "dio.h"
#include <avr/io.h>
void DIO_SetPinDirection(uint8_t port, uint8_t pin, uint8_t direction) {
	switch(port) {
		case PORT_A:
		if(direction == OUTPUT) DDRA |= (1 << pin);
		else DDRA &= ~(1 << pin);
		break;
		case PORT_B:
		if(direction == OUTPUT) DDRB |= (1 << pin);
		else DDRB &= ~(1 << pin);
		break;
		case PORT_C:
		if(direction == OUTPUT) DDRC |= (1 << pin);
		else DDRC &= ~(1 << pin);
		break;
		case PORT_D:
		if(direction == OUTPUT) DDRD |= (1 << pin);
		else DDRD &= ~(1 << pin);
		break;
	}
}

void DIO_WritePin(uint8_t port, uint8_t pin, uint8_t value) {
	switch(port) {
		case PORT_A:
		if(value == HIGH) PORTA |= (1 << pin);
		else PORTA &= ~(1 << pin);
		break;
		case PORT_B:
		if(value == HIGH) PORTB |= (1 << pin);
		else PORTB &= ~(1 << pin);
		break;
		case PORT_C:
		if(value == HIGH) PORTC |= (1 << pin);
		else PORTC &= ~(1 << pin);
		break;
		case PORT_D:
		if(value == HIGH) PORTD |= (1 << pin);
		else PORTD &= ~(1 << pin);
		break;
	}
}

uint8_t DIO_ReadPin(uint8_t port, uint8_t pin) {
	uint8_t val = 0;
	switch(port) {
		case PORT_A: val = (PINA >> pin) & 0x01; break;
		case PORT_B: val = (PINB >> pin) & 0x01; break;
		case PORT_C: val = (PINC >> pin) & 0x01; break;
		case PORT_D: val = (PIND >> pin) & 0x01; break;
	}
	return val;
}

void DIO_TogglePin(uint8_t port, uint8_t pin) {
	switch(port) {
		case PORT_A: PORTA ^= (1 << pin); break;
		case PORT_B: PORTB ^= (1 << pin); break;
		case PORT_C: PORTC ^= (1 << pin); break;
		case PORT_D: PORTD ^= (1 << pin); break;
	}
}