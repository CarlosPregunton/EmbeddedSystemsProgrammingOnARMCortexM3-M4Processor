#include "stm32f303xx_gpio.h"
#include "stm32f303xx.h"

void GPIO_ClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t status){
	if(status == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_EN_CLK();
		}else if(pGPIOx == GPIOB){
			GPIOB_EN_CLK();
		}else if(pGPIOx == GPIOC){
			GPIOC_EN_CLK();
		}else if(pGPIOx == GPIOD){
			GPIOD_EN_CLK();
		}else if(pGPIOx == GPIOE){
			GPIOE_EN_CLK();
		}else if(pGPIOx == GPIOF){
			GPIOF_EN_CLK();
		}else if(pGPIOx == GPIOG){
			GPIOG_EN_CLK();
		}else if(pGPIOx == GPIOH){
			GPIOH_EN_CLK();
		}
	}else if(status == DISABLE){
		if(pGPIOx == GPIOA){
			GPIOA_DIS_CLK();
		}else if(pGPIOx == GPIOB){
			GPIOB_DIS_CLK();
		}else if(pGPIOx == GPIOC){
			GPIOC_DIS_CLK();
		}else if(pGPIOx == GPIOD){
			GPIOD_DIS_CLK();
		}else if(pGPIOx == GPIOE){
			GPIOE_DIS_CLK();
		}else if(pGPIOx == GPIOF){
			GPIOF_DIS_CLK();
		}else if(pGPIOx == GPIOG){
			GPIOG_DIS_CLK();
		}else if(pGPIOx == GPIOH){
			GPIOH_DIS_CLK();
		}
	}
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx, uint8_t status){
	if(status == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_RESET();
		}else if(pGPIOx == GPIOB){
			GPIOB_RESET();
		}else if(pGPIOx == GPIOC){
			GPIOC_RESET();
		}else if(pGPIOx == GPIOD){
			GPIOD_RESET();
		}else if(pGPIOx == GPIOE){
			GPIOE_RESET();
		}else if(pGPIOx == GPIOF){
			GPIOF_RESET();
		}else if(pGPIOx == GPIOG){
			GPIOG_RESET();
		}else if(pGPIOx == GPIOH){
			GPIOH_RESET();
		}
	}
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin){
	return (uint8_t)((pGPIOx -> IDR >> pin) & 0x01);
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx){
	return (uint16_t)((pGPIOx -> IDR) & 0xFFFF);
}

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin, uint8_t value){
	if(value == SET){
		pGPIOx -> ODR |= (1 << pin);
	}else if(value == RESET){
		pGPIOx -> ODR &= ~(1 << pin);
	}
}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value){
	pGPIOx -> ODR = (uint32_t)value;
}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t pin){
	pGPIOx -> ODR ^= (1 << pin);
}

void GPIO_NVIC_IRQ_Enable(uint8_t IRQ){

	if((IRQ >= 0) & (IRQ < 32)){
		NVIC_ISER0 |= (1 << IRQ);
	}else if((IRQ >= 32) & (IRQ < 64)){
		NVIC_ISER1 |= (1 << (IRQ - 32));
	}else if((IRQ >= 64) & (IRQ < 96)){
		NVIC_ISER2 |= (1 << (IRQ - 64));
	}

}
void GPIO_NVIC_IRQ_Disable(uint8_t IRQ){

	if((IRQ >= 0) & (IRQ < 32)){
		NVIC_ICER0 |= (1 << IRQ);
	}else if((IRQ >= 32) & (IRQ < 64)){
		NVIC_ICER1 |= (1 << (IRQ - 32));
	}else if((IRQ >= 64) & (IRQ < 96)){
		NVIC_ICER2 |= (1 << (IRQ - 64));
	}
}
void GPIO_NVIC_Priority(uint8_t IRQ, uint32_t priority){
	uint8_t regidx;
	uint8_t blkidx;
	regidx = IRQ / 4;
	blkidx = IRQ % 4;
	uint32_t *NVIC_IPR = (uint32_t *)(NVIC_IPR_BASEADDR + regidx * 4);
	*NVIC_IPR &= (0xFF << (blkidx * 8));
	*NVIC_IPR |= (priority << (blkidx * 8 + 4));
}

void GPIO_IRQHandler(uint8_t pin){
	if(EXTI->PR1 & (1 << pin)){
		EXTI->PR1 |= (1 << pin);
	}
}
void GPIO_Init(GPIO_handle_t *pGPIOHandle){
	//Enable clock
	GPIO_ClkCtrl(pGPIOHandle->pGPIOx, ENABLE);

	//Mode setup(input, output, analog function, alternative function, exit interrupt)*Interrupts 23-28 & alternate functions not programmed yet*

	if(pGPIOHandle->GPIO_config.GPIO_Mode > GPIO_Mode_AN){
		if(pGPIOHandle -> GPIO_config.GPIO_Mode == GPIO_Mode_RE){
			EXTI -> FTSR1 &= ~(1 << pGPIOHandle ->GPIO_config.GPIO_Pin);
			EXTI -> RTSR1 |= (1 << pGPIOHandle ->GPIO_config.GPIO_Pin);

		}else if(pGPIOHandle -> GPIO_config.GPIO_Mode == GPIO_Mode_FE){
			EXTI -> RTSR1 &= ~(1 << pGPIOHandle ->GPIO_config.GPIO_Pin);
			EXTI -> FTSR1 |= (1 << pGPIOHandle ->GPIO_config.GPIO_Pin);

		}else if(pGPIOHandle -> GPIO_config.GPIO_Mode == GPIO_Mode_RFE){
			EXTI -> FTSR1 |= (1 << pGPIOHandle ->GPIO_config.GPIO_Pin);
			EXTI -> RTSR1 |= (1 << pGPIOHandle ->GPIO_config.GPIO_Pin);
		}

		uint8_t regidx;
		uint8_t blkidx;
		regidx = pGPIOHandle->GPIO_config.GPIO_Pin / 4;
		blkidx = pGPIOHandle->GPIO_config.GPIO_Pin % 4;
		SYSCFG->EXTICR[regidx] &= ~(0x0F << (blkidx * 4));
		SYSCFG->EXTICR[regidx] |= (PORT_NUMER(pGPIOHandle->pGPIOx) << (blkidx * 4));

		//Enable EXTPI Mask Register
		EXTI -> IMR1 |= (1 << pGPIOHandle -> GPIO_config.GPIO_Pin);
	}

	else{
	pGPIOHandle->pGPIOx->MODER &= ~(0x03 << (pGPIOHandle->GPIO_config.GPIO_Pin*2));		//Setup pin mode
	pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_config.GPIO_Mode << (pGPIOHandle->GPIO_config.GPIO_Pin*2));
	}

	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x03 << (pGPIOHandle->GPIO_config.GPIO_Pin*2));	//Setup speed setup
	pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_config.GPIO_Speed << (pGPIOHandle->GPIO_config.GPIO_Pin*2));

	pGPIOHandle->pGPIOx->PUPDR &= ~(0x03 << (pGPIOHandle->GPIO_config.GPIO_Pin*2));		//Setup input pull-up/pull-down
	pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_config.GPIO_PuPd << (pGPIOHandle->GPIO_config.GPIO_Pin*2));

	pGPIOHandle->pGPIOx->OTYPER &= ~(0x01 << (pGPIOHandle->GPIO_config.GPIO_Pin));		//Setup open type (Push pull/Open Drain)
	pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_config.GPIO_Otyper << (pGPIOHandle->GPIO_config.GPIO_Pin));

	if(pGPIOHandle->GPIO_config.GPIO_Mode == GPIO_Mode_AF){								//Alternative function
		uint8_t regidx;
		uint8_t blkidx;
		regidx = pGPIOHandle->GPIO_config.GPIO_Pin / 8;
		blkidx = pGPIOHandle->GPIO_config.GPIO_Pin % 8;
		pGPIOHandle->pGPIOx->AFR[regidx] &= ~(0x0F << (blkidx * 4));
		pGPIOHandle->pGPIOx->AFR[regidx] |= (pGPIOHandle -> GPIO_config.GPIO_AltFun << (blkidx * 4));
	}
}
