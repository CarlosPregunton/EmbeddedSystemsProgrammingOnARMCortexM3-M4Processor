
#ifndef DRIVERS_INC_STM32F303XX_H_
#define DRIVERS_INC_STM32F303XX_H_

#include <stdint.h>

#define ENABLE	0x01
#define DISABLE	0x00

#define SET   0x01
#define RESET 0x00

#define AHB1PERIPH_BASEADDR 0x40020000UL		//Ver p55 del Reference manual
#define AHB2PERIPH_BASEADDR 0x48000000UL		//Ver p54 del Reference manual
#define APB2PERIPH_BASEADDR 0x40010000UL

#define GPIOA_BASEADDR	(AHB2PERIPH_BASEADDR + 0x0000)		//Ver p54 del reference manual
#define GPIOB_BASEADDR	(AHB2PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR	(AHB2PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR	(AHB2PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR	(AHB2PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR	(AHB2PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR	(AHB2PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR	(AHB2PERIPH_BASEADDR + 0x1C00)

#define SYSCFG_BASEADDR	(APB2PERIPH_BASEADDR + 0x0000)
#define EXTI_BASEADDR	(APB2PERIPH_BASEADDR + 0x0400)

#define RCC_BASEADDR	(AHB1PERIPH_BASEADDR + 0x1000)		//Ver p55 del Reference manual

typedef struct{
	volatile uint32_t MODER;		//GPIO port mode register (GPIOx_MODER) (x =A..H)
	volatile uint32_t OTYPER;		//GPIO port output type register (GPIOx_OTYPER) (x = A..H)
	volatile uint32_t OSPEEDR;		//GPIO port output speed register (GPIOx_OSPEEDR)
	volatile uint32_t PUPDR;		//GPIO port pull-up/pull-down register (GPIOx_PUPDR)(x = A..H)
	volatile uint32_t IDR;			//GPIO port input data register (GPIOx_IDR) (x = A..H)
	volatile uint32_t ODR;			//GPIO port output data register (GPIOx_ODR) (x = A..H)
	volatile uint32_t BSRR;			//GPIO port bit set/reset register (GPIOx_BSRR) (x = A..H)
	volatile uint32_t LCKR;			//GPIO port configuration lock register (GPIOx_LCKR)
	volatile uint32_t AFR[2];		//GPIO alternate function low register (GPIOx_AFRL) (x = A..H)
	volatile uint32_t BRR;			//GPIO port bit reset register (GPIOx_BRR) (x =A..H)
}GPIO_RegDef_t;

typedef struct{
	volatile uint32_t CR;			//Clock control register (RCC_CR)
	volatile uint32_t CFGR;			//Clock configuration register (RCC_CFGR)
	volatile uint32_t CIR;			//Clock interrupt register (RCC_CIR)
	volatile uint32_t APB2RSTR;		//APB2 peripheral reset register
	volatile uint32_t APB1RSTR;		//APB1 peripheral reset register
	volatile uint32_t AHBENR;		//AHB peripheral clock enable register
	volatile uint32_t APB2ENR;		//APB2 peripheral clock enable register
	volatile uint32_t APB1ENR;		//APB1 peripheral clock enable register
	volatile uint32_t BDCR;			//RTC Domain control register
	volatile uint32_t CSR;			//Control/Status Register
	volatile uint32_t AHBRSTR;		//AHB peripheral reset register
	volatile uint32_t CFGR2;		//Clock configuration register
	volatile uint32_t CFGR3;		//Clock configuration register
}RCC_RegDef_t;

typedef struct{
	volatile uint32_t IMR1;			//Interrupt Mask Register
	volatile uint32_t EMR1;			//Event Mask Register
	volatile uint32_t RTSR1;		//Rising Trigger Selection Register 1
	volatile uint32_t FTSR1;		//Falling Trigger Selection Register 2
	volatile uint32_t SWIER1;		//Software Interrupt Event Register
	volatile uint32_t PR1;			//Pending Register
			 uint32_t dummy0[2];
	volatile uint32_t IMR2;			//Interrupt Mask Register
	volatile uint32_t EMR2;			//Event Mask Register
	volatile uint32_t RTSR2;		//Rising trigger selection Register 2
	volatile uint32_t FTSR2;		//Falling Trigger Selection Register 2
	volatile uint32_t SWIER2;		//Software Interrupt Event Register 2
	volatile uint32_t PR2;			//Pending Register 2
}EXTI_RegDef_t;

typedef struct{
	volatile uint32_t CFGR1;		//SYSCFG configuration register 1 (SYSCFG_CFGR1)
	volatile uint32_t RCR;			//SYSCFG CCM SRAM protection register (SYSCFG_RCR)
	volatile uint32_t EXTICR[4];	//SYSCFG external interrupt configuration registerx (SYSCFG_EXTICRx)
	volatile uint32_t CFGR2;		//SYSCFG configuration register 2 (SYSCFG_CFGR2)
			 uint32_t dummy0[11];	//
	volatile uint32_t CFGR3;		//SYSCFG configuration register 3 (SYSCFG_CFGR3)
			 uint32_t dummy1;		//
	volatile uint32_t CFGR4;		//SYSCFG configuration register 4 (SYSCFG_CFGR4)
}SYSCFG_RegDef_t;

#define GPIOA	((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB	((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC	((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD	((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE	((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF	((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG	((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH	((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC 	((RCC_RegDef_t *)RCC_BASEADDR)

#define EXTI	((EXTI_RegDef_t *)EXTI_BASEADDR)
#define SYSCFG	((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)


#define GPIOA_EN_CLK()	(RCC -> AHBENR |= (1 << 17))	//Enable clock for GPIOx
#define GPIOB_EN_CLK()	(RCC -> AHBENR |= (1 << 18))
#define GPIOC_EN_CLK()	(RCC -> AHBENR |= (1 << 19))
#define GPIOD_EN_CLK()	(RCC -> AHBENR |= (1 << 20))
#define GPIOE_EN_CLK()	(RCC -> AHBENR |= (1 << 21))
#define GPIOF_EN_CLK()	(RCC -> AHBENR |= (1 << 22))
#define GPIOG_EN_CLK()	(RCC -> AHBENR |= (1 << 23))
#define GPIOH_EN_CLK()	(RCC -> AHBENR |= (1 << 16))

/*Habilitar clock perifericos SYSCFG*/
#define SYSCFG_EN_CLK()	(RCC -> APB2ENR |= (1 << 0))


#define GPIOA_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 17))	//Disable clock for GPIOx
#define GPIOB_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 18))
#define GPIOC_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 19))
#define GPIOD_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 20))
#define GPIOE_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 21))
#define GPIOF_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 22))
#define GPIOG_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 23))
#define GPIOH_DIS_CLK()	(RCC -> AHBENR &= ~(1 << 16))

/*Habilitar clock perifericos SYSCFG*/
#define SYSCFG_DIS_CLK() (RCC -> APB2ENR &= ~(1 << 0))


#define GPIOA_RESET()	do{(RCC -> AHBRSTR |= (1 <<17)); (RCC -> AHBRSTR &= ~(1 <<17));}while(0)	//Reset clock's register for GPIOx
#define GPIOB_RESET()	do{(RCC -> AHBRSTR |= (1 <<18)); (RCC -> AHBRSTR &= ~(1 <<18));}while(0)
#define GPIOC_RESET()	do{(RCC -> AHBRSTR |= (1 <<19)); (RCC -> AHBRSTR &= ~(1 <<19));}while(0)
#define GPIOD_RESET()	do{(RCC -> AHBRSTR |= (1 <<20)); (RCC -> AHBRSTR &= ~(1 <<20));}while(0)
#define GPIOE_RESET()	do{(RCC -> AHBRSTR |= (1 <<21)); (RCC -> AHBRSTR &= ~(1 <<21));}while(0)
#define GPIOF_RESET()	do{(RCC -> AHBRSTR |= (1 <<22)); (RCC -> AHBRSTR &= ~(1 <<22));}while(0)
#define GPIOG_RESET()	do{(RCC -> AHBRSTR |= (1 <<23)); (RCC -> AHBRSTR &= ~(1 <<23));}while(0)
#define GPIOH_RESET()	do{(RCC -> AHBRSTR |= (1 <<16)); (RCC -> AHBRSTR &= ~(1 <<16));}while(0)

#define SYSCFG_RESET()	do{(RCC -> APB2ENR |= (1 <<0)); (RCC -> APB2ENR &= ~(1 <<0));}while(0)	/*Reset SYSCFG Clock*/

/* This macro gets the port number. */

#define PORT_NUMER(x) ((x == GPIOA)? 0x00 :\
					(x == GPIOB)? 0x01 :\
					(x == GPIOC)? 0x02 :\
					(x == GPIOD)? 0x03 :\
					(x == GPIOE)? 0x04 :\
					(x == GPIOF)? 0x05 :\
					(x == GPIOG)? 0x06 : 0x07)

#define EXTI15_10 0x28

#define NVIC_ISER0	(*((volatile uint32_t *)0xE000E100UL))
#define NVIC_ISER1	(*((volatile uint32_t *)0xE000E104UL))
#define NVIC_ISER2	(*((volatile uint32_t *)0xE000E108UL))

#define NVIC_ICER0	(*((volatile uint32_t *)0XE000E180UL))
#define NVIC_ICER1	(*((volatile uint32_t *)0XE000E184UL))
#define NVIC_ICER2	(*((volatile uint32_t *)0XE000E188UL))

#define NVIC_IPR_BASEADDR	(*((volatile uint32_t *)0XE000E188UL))

#endif /* DRIVERS_INC_STM32F303XX_H_ */
