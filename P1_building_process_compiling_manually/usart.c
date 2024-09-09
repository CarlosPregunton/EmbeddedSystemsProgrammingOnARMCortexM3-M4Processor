/*
 * usart.c
 *
 *  Created on: 6 dic 2022
 *      Author: CARLOS
 */
#include "usart.h"

void usart_tx_init(void){

	RCC->AHBENR |= (1 << 17);			//Enable GPIO Clock
	GPIOA->MODER &= ~(1 << 4);			//PA2 as alternate function
	GPIOA->MODER |= (1 << 5);
	GPIOA->AFR[0] |= (7 << 8);			//AFR7 in pin PA2

	RCC->APB1ENR |= (1 << 17);			//USART2 Clock Enable PA2->TX and PA3->RX
	//1 start bit 8 data length, USART module disable, Over sampling by 16
	USART2->CR1 &= ~((1 << 28)|(1 << 12)|(1 << 0)|(1 << 15));
	USART2->BRR = 0x0341;				//9600 bps OverSampling = 16
	USART2->CR2 &= ~(3 << 12);			//1 stop bit
	USART2->CR1 |= (1 << 3);			//Tx enabled

}

int __io_putchar(int ch){				//Function for using printf() function
	usart_write(ch);
	return ch;
}

void usart_write(unsigned char Data){
	while(!(USART2->ISR & 0x80));		//Waiting for TDR available (TXE = 1)
	USART2->TDR = Data;
}

void usart_enabled(void){
	USART2->CR1 |= (1 << 0);			//USART module enabled
}

void usart_disable(void){
	RCC->APB1ENR &= ~(1 << 17);			//Disable USART2
}

void usart_reset(void){
	RCC->APB1RSTR |= (1 << 17); 		//Reset USART2
}
