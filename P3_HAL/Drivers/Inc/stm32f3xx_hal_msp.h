
#ifndef __STM32F3XX_HAL_MSP_H
#define __STM32F3XX_HAL_MSP_H

//#include "stm32f3xx_hal.h"

#ifdef __cplusplus
 extern "C" {
#endif

void HAL_MspInit(void);

void HAL_MspDeInit(void);

void HAL_PPP_MspInit(void);

void HAL_PPP_MspDeInit(void);

void SystemClock_Config(void);

void LED_Init(void);

static void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif 



