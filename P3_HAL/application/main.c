// #include <stdint.h>
// #include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

void SystemClock_Config(void);
void GPIO_Init(void);

int main(void) {
    // Inicializar la HAL Library
    HAL_Init();
    
    // Configurar el sistema de reloj
    SystemClock_Config();
    
    // Inicializar el GPIO para el LED
    GPIO_Init();
    
    // Bucle infinito para parpadear el LED
    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Cambia el estado del LED
        HAL_Delay(1000);                       // Espera 1000 ms (1 segundo)
    }
}

void SystemClock_Config(void) {
    // Configuración del reloj del sistema si se requiere
    // Por simplicidad, se puede dejar vacío si el reloj está preconfigurado
}

void GPIO_Init(void) {
    // Habilitar el reloj para el puerto GPIOA
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    // Configuración del pin PA5
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5;               // Pin A5
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;     // Salida push-pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;             // Sin resistencia de pull-up o pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    // Velocidad baja

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

