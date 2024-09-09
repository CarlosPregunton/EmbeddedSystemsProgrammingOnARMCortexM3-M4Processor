/*
 * usart.h
 *
 *  Created on: 6 dic 2022
 *      Author: CARLOS
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f3xx.h"
#include <stdio.h>
void usart_tx_init(void);
void usart_write(unsigned char);
void usart_enabled(void);
void usart_disable(void);
void usart_reset(void);

#endif /* USART_H_ */
