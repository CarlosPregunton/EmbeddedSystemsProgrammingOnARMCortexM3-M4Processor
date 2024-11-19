#include "main.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_msp.h"
#include <stdio.h>

UART_HandleTypeDef huart2;
int main(void) {

  HAL_Init();
  /* Configure the system clock to 64 MHz */
  SystemClock_Config();
  /*Setting up tick variable*/
  HAL_InitTick(TICK_INT_PRIORITY);
  
  UART_Init(&huart2);
  
  char loop_message[] = "This is a test message.\n";
  while (1) {
      HAL_Delay(1000);
      HAL_UART_Transmit(&huart2, (uint8_t *)loop_message, sizeof(loop_message) - 1, HAL_MAX_DELAY);
  }
}






#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

