/*
 * stm32f303xx_gpio.h
 *
 *  Created on: 24 ago 2022
 *      Author: CARLOS
 */
#ifndef DRIVERS_INC_STM32F303XX_GPIO_H_
#define DRIVERS_INC_STM32F303XX_GPIO_H_

#include "stm32f303xx.h"
typedef enum{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_Pin_t;

typedef enum{
	GPIO_Mode_IN,
	GPIO_Mode_OUT,
	GPIO_Mode_AF,
	GPIO_Mode_AN,
	GPIO_Mode_RE,
	GPIO_Mode_FE,
	GPIO_Mode_RFE
}GPIO_Mode_t;

typedef enum{
	GPIO_Speed_LOW,
	GPIO_Speed_MED,
	GPIO_Speed_DUM,
	GPIO_Speed_HIGH
}GPIO_Speed_t;

typedef enum{
	GPIO_PuPd_NONE,
	GPIO_PuPd_UP,
	GPIO_PuPd_DOWN
}GPIO_PuPd_t;

typedef enum{			//See pinout of the device's data sheet
	GPIO_ALTFUN_0,
	GPIO_ALTFUN_1,
	GPIO_ALTFUN_2,
	GPIO_ALTFUN_3,
	GPIO_ALTFUN_4,
	GPIO_ALTFUN_5,
	GPIO_ALTFUN_6,
	GPIO_ALTFUN_7,
	GPIO_ALTFUN_8,
	GPIO_ALTFUN_9,
	GPIO_ALTFUN_10,
	GPIO_ALTFUN_11,
	GPIO_ALTFUN_12,
	GPIO_ALTFUN_13,
	GPIO_ALTFUN_14,
	GPIO_ALTFUN_15
}GPIO_AltFun_t;

typedef enum{
	GPIO_Otyper_PP,
	GPIO_Otyper_OD
}GPIO_Otyper_t;

typedef struct{
	GPIO_Pin_t GPIO_Pin;		//Numero de pin
	GPIO_Mode_t GPIO_Mode;		//Modo de funcionamiento del pin
	GPIO_Speed_t GPIO_Speed;	//Velocidad de funcionamiento del pin
	GPIO_PuPd_t	GPIO_PuPd;		//Configura cada pin en modo pull-up o pull-down
	GPIO_AltFun_t GPIO_AltFun;	//Configuración de funciones alternativas de cada pin
	GPIO_Otyper_t GPIO_Otyper;
}GPIO_Config_t;

typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_Config_t GPIO_config;
}GPIO_handle_t;

/*prototypes of functions*/

void GPIO_ClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status);
void GPIO_Init(GPIO_handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx, uint8_t status);

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin,uint8_t value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin);

void GPIO_NVIC_IRQ_Enable(uint8_t IRQ);
void GPIO_NVIC_IRQ_Disable(uint8_t IRQ);
void GPIO_NVIC_Priority(uint8_t IRQ, uint32_t priority);
void GPIO_IRQHandler(uint8_t pin);

#endif /* DRIVERS_INC_STM32F303XX_GPIO_H_ */
