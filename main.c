/*
 * TOGGLE-LED.c
 *
 * Created: 10/3/2026 6:08:52 PM
 * Author : Administrator
 * Created by: AhmedLashin (AL6)
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include "HAL/LED/led.h"
#include "HAL/Button/button.h"
#include "HAL/LCD/lcd.h"

#define BTN_PORT PORT_D
#define BTN_PIN  PIN0

#define LED_PORT PORT_C
#define LED_PIN  PIN0

int main(void) {
	LED_Init(LED_PORT, LED_PIN);
	Button_Init(BTN_PORT, BTN_PIN);
	LCD_Init();

	uint8_t led_state = 0;
	uint8_t btn_prev_state = LOW;

	LCD_Clear();
	LCD_SendString("LED Status:");
	LCD_SendCommand(0xC0);
	LCD_SendString("OFF");

	while (1) {
		uint8_t btn_current_state = Button_Read(BTN_PORT, BTN_PIN);

		if (btn_current_state == HIGH && btn_prev_state == LOW) {
			_delay_ms(30);
			if (Button_Read(BTN_PORT, BTN_PIN) == HIGH) {
				led_state ^= 1;
				if (led_state) {
					LED_TurnOn(LED_PORT, LED_PIN);
					LCD_SendCommand(0xC0);
					LCD_SendString("ON ");
					} else {
					LED_TurnOff(LED_PORT, LED_PIN);
					LCD_SendCommand(0xC0);
					LCD_SendString("OFF");
				}
			}
		}
		btn_prev_state = btn_current_state;
	}
}