/*
 * timebase.c
 *
 *  Created on: 8 dic 2022
 *      Author: CARLOS
 */
#include "timebase.h"

#define ONE_SEC_LOAD	8000000
#define CTRL_ENABLE		(1 << 0)	//Enable Systick
#define CTRL_TICKINT	(1 << 1)	//Enables Interrupt
#define CTRL_CLCKSRC	(1 << 2)	//Internal CLK
#define CTRL_COUNTFLAG	(1 << 16)
#define MAX_DELAY		0xFFFFFFFF

volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;
volatile uint32_t tick_freq = 1;

void timebase_init(void){
	/*Reload the timer with the number of cycles per second*/
	SysTick->LOAD = ONE_SEC_LOAD;
	/*Clear systick current value register*/
	SysTick->VAL = 0;
	/*Select internal clock source*/
	SysTick->CTRL = CTRL_CLCKSRC;
	/*Enable interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;
	/*Enable systick*/
	SysTick->CTRL |= CTRL_ENABLE;
	/*Enable global interrupts*/
	__enable_irq();
}

void tick_increment(){
	g_curr_tick += tick_freq;
}

void SysTick_Handler(){
	tick_increment();
}

uint32_t get_tick(){
	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();

	return g_curr_tick_p;
}

void delay(uint32_t delay){

	uint32_t tickstart = get_tick();
	uint32_t wait = delay;

	if(wait < MAX_DELAY){
		wait += (uint32_t)tick_freq;
	}

	while((get_tick()-tickstart) < wait);
}
