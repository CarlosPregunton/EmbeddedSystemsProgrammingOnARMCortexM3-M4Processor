#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_msp.h"
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSI)
  *            SYSCLK(Hz)                     = 64000000
  *            HCLK(Hz)                       = 64000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSI Frequency(Hz)              = 8000000
  *            PREDIV                         = RCC_PREDIV_DIV2 (2)
  *            PLLMUL                         = RCC_PLL_MUL16 (16)
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* HSI Oscillator already ON after system reset, activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    Error_Handler();
  }
}

// Inicializa el pin A5 como salida para el LED
void LED_Init(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Habilita el reloj para el puerto A
    
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5;           // Configura el pin A5
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Modo salida push-pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;         // Sin resistencias pull-up/down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Baja velocidad (suficiente para LEDs)
    
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);     // Inicializa el pin con las configuraciones
}

// Configuración del UART
void UART_Init(UART_HandleTypeDef* huart2) {
    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configura los pines PA2 (TX) y PA3 (RX)
    GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    //UART_HandleTypeDef huart2= {0};
    
    // Configura el UART
    huart2->Instance = USART2;
    huart2->Init.BaudRate = 115200;
    huart2->Init.WordLength = UART_WORDLENGTH_8B;
    huart2->Init.StopBits = UART_STOPBITS_1;
    huart2->Init.Parity = UART_PARITY_NONE;
    huart2->Init.Mode = UART_MODE_TX_RX;
    huart2->Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2->Init.OverSampling = UART_OVERSAMPLING_16;
    // Inicializa el UART
    if (HAL_UART_Init(huart2) != HAL_OK) {
    // Maneja el error si la inicialización falla
    Error_Handler();
    }
}

void HAL_MspInit(void){
    
    /* Configure the system clock to 64 MHz */
    //SystemClock_Config();
    
    //HAL_InitTick(TICK_INT_PRIORITY);
    
    /* Setup led pin */
    // LED_Init();
    
    /* Set up uart*/
    //UART_Init();
}

void HAL_MspDeInit(void)
{
  
}

void HAL_PPP_MspInit(void)
{
   
}

void HAL_PPP_MspDeInit(void)
{
  
}
