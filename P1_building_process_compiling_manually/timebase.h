/*
 * timebase.h
 *
 *  Created on: 8 dic 2022
 *      Author: CARLOS
 */

#ifndef TIMEBASE_H_
#define TIMEBASE_H_

#include <stdio.h>
#include "stm32f3xx.h"

void timebase_init(void);
void delay(uint32_t delay);
#endif /* TIMEBASE_H_ */
