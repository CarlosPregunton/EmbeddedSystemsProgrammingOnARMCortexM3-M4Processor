/*
 * led.c
 *
 *  Created on: Dec 2, 2022
 *      Author: CARLOS
 */
#include "led.h"

void led_init(void){

	RCC->AHBENR |= (1 << 17);		//Enable GPIO Clock
	GPIOA->MODER |= (1 << 10);		//PA5 as an output
	GPIOA->OTYPER &= ~(1 << 5);		//PA5 on Push-Pull
	GPIOA->OSPEEDR &= ~(3 << 10);	//PA5 on low speed
	GPIOA->PUPDR &= ~(3 << 10);		//PA5 with no Pull-up Pulll-down
}

void led_on(void){
	GPIOA->ODR |= (1 << 5);			//PA5 is on
}

void led_off(void){					//PA5 is off
	GPIOA->ODR &= ~(1 << 5);
}
