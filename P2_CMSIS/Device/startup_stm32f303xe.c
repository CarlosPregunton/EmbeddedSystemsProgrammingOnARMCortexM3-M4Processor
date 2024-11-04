#include <stdint.h>

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (64U * 1024U)  //64KB
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))
#define STACK_START SRAM_END
#define ISR_VECTOR_SIZE_WORDS 110

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void TAMPER_STAMP_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI2_TS_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void ADC1_2_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void USB_LP_CAN_RX0_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void CAN_RX1_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void CAN_SCE_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void USART3_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void ADC3_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void FMC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void UART4_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void UART5_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM7_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel5_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void ADC4_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void COMP1_2_3_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void COMP4_5_6_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void COMP7_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void USB_HP_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void USB_LP_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void USB_WakeUp_RMP_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void TIM20_BRK_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM20_UP_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM20_TRG_COM_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void TIM20_CC_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void SPI4_Handler(void)             __attribute__((weak, alias("Default_Handler")));



uint32_t vectors[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
  STACK_START,
  (uint32_t)&Reset_Handler,
  (uint32_t)&NMI_Handler,              
  (uint32_t)&HardFault_Handler,        
  (uint32_t)&MemManage_Handler,
  (uint32_t)&BusFault_Handler,
  (uint32_t)&UsageFault_Handler,
  0,
  0,
  0,
  0,
  (uint32_t)&SVCall_Handler,
  (uint32_t)&PendSV_Handler,
  (uint32_t)&SysTick_Handler,
  (uint32_t)&WWDG_Handler,
  (uint32_t)&PVD_Handler,
  (uint32_t)&TAMPER_STAMP_Handler,
  (uint32_t)&RTC_WKUP_Handler,
  (uint32_t)&FLASH_Handler,
  (uint32_t)&RCC_Handler,
  (uint32_t)&EXTI0_Handler,
  (uint32_t)&EXTI1_Handler,
  (uint32_t)&EXTI2_TS_Handler,
  (uint32_t)&EXTI3_Handler,
  (uint32_t)&EXTI4_Handler,
  (uint32_t)&DMA1_Channel1_Handler,
  (uint32_t)&DMA1_Channel2_Handler,
  (uint32_t)&DMA1_Channel3_Handler,
  (uint32_t)&DMA1_Channel4_Handler,
  (uint32_t)&DMA1_Channel5_Handler,
  (uint32_t)&DMA1_Channel6_Handler,
  (uint32_t)&DMA1_Channel7_Handler,
  (uint32_t)&ADC1_2_Handler,
  (uint32_t)&USB_HP_CAN_TX_Handler,
  (uint32_t)&USB_LP_CAN_RX0_Handler,
  (uint32_t)&CAN_RX1_Handler,
  (uint32_t)&CAN_SCE_Handler,
  (uint32_t)&EXTI9_5_Handler,
  (uint32_t)&TIM1_BRK_Handler,
  (uint32_t)&TIM1_UP_Handler,
  (uint32_t)&TIM1_TRG_COM_Handler,
  (uint32_t)&TIM1_CC_Handler,
  (uint32_t)&TIM2_Handler,
  (uint32_t)&TIM3_Handler,
  (uint32_t)&TIM4_Handler,
  (uint32_t)&I2C1_EV_Handler,
  (uint32_t)&I2C1_ER_Handler,
  (uint32_t)&I2C2_EV_Handler,
  (uint32_t)&I2C2_ER_Handler,
  (uint32_t)&SPI1_Handler,
  (uint32_t)&SPI2_Handler,
  (uint32_t)&USART1_Handler,
  (uint32_t)&USART2_Handler,
  (uint32_t)&USART3_Handler,
  (uint32_t)&EXTI15_10_Handler,
  (uint32_t)&RTC_Alarm_Handler,
  (uint32_t)&USBWakeUp_Handler,
  (uint32_t)&TIM8_BRK_Handler,
  (uint32_t)&TIM8_UP_Handler,
  (uint32_t)&TIM8_TRG_COM_Handler,
  (uint32_t)&TIM8_CC_Handler,
  (uint32_t)&ADC3_Handler,
  (uint32_t)&FMC_Handler,
  0,
  0,
  (uint32_t)&SPI3_Handler,
  (uint32_t)&UART4_Handler,
  (uint32_t)&UART5_Handler,
  (uint32_t)&TIM6_DAC_Handler,
  (uint32_t)&TIM7_Handler,
  (uint32_t)&DMA2_Channel1_Handler,
  (uint32_t)&DMA2_Channel2_Handler,
  (uint32_t)&DMA2_Channel3_Handler,
  (uint32_t)&DMA2_Channel4_Handler,
  (uint32_t)&DMA2_Channel5_Handler,
  (uint32_t)&ADC4_Handler,
  0,
  0,
  (uint32_t)&COMP1_2_3_Handler,
  (uint32_t)&COMP4_5_6_Handler,
  (uint32_t)&COMP7_Handler,
  0,
  0,
  0,
  0,
  0,
  (uint32_t)&I2C3_EV_Handler,
  (uint32_t)&I2C3_ER_Handler,
  (uint32_t)&USB_HP_Handler,
  (uint32_t)&USB_LP_Handler,
  (uint32_t)&USB_WakeUp_RMP_Handler,
  (uint32_t)&TIM20_BRK_Handler,
  (uint32_t)&TIM20_UP_Handler,
  (uint32_t)&TIM20_TRG_COM_Handler,
  (uint32_t)&TIM20_CC_Handler,
  (uint32_t)&FPU_Handler,
  0,
  0,
  (uint32_t)&SPI4_Handler,
};

void Default_Handler(void){
  while(1);
}

int main(void);
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;

void Reset_Handler(void){
  /* Copy .data from FLASH to SRAM.*/
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t*)&_etext; //flash
  uint8_t *sram_data = (uint8_t*)&_sdata; //sram
  
  for(uint32_t i = 0; i < data_size; i++){
    sram_data[i] = flash_data[i];
  }
  // Init the .bss section to zero in SRAM.
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*)&_sbss; //sram
  
  for(uint32_t i = 0; i < bss_size; i++){
    bss[i] = 0;
  }
  
  main();
  // Call init function of std. library (only if it is used).
  // Call main.
}
/*In order to see system variables execute arm-none-eabi-nm final.elf on terminal.*/
