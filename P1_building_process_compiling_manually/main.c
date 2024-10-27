
#include "stm32f303xx.h"
#include "stm32f303xx_gpio.h"

void delay(uint32_t cnt){
	while(cnt)
		cnt--;
}

GPIO_handle_t LED;
GPIO_handle_t Button;

void GPIO_setup(void){
	LED.pGPIOx = GPIOA;
	LED.GPIO_config.GPIO_Mode = GPIO_Mode_OUT;
	LED.GPIO_config.GPIO_Otyper = GPIO_Otyper_PP;
	LED.GPIO_config.GPIO_Pin = GPIO_PIN_5;
	LED.GPIO_config.GPIO_PuPd = GPIO_PuPd_NONE;
	LED.GPIO_config.GPIO_Speed = GPIO_Speed_LOW;
	GPIO_Init(&LED);

	Button.pGPIOx = GPIOC;
	Button.GPIO_config.GPIO_Mode = GPIO_Mode_IN;
	Button.GPIO_config.GPIO_Pin = GPIO_PIN_13;
	Button.GPIO_config.GPIO_PuPd = GPIO_PuPd_NONE;
	Button.GPIO_config.GPIO_Speed = GPIO_Speed_LOW;
	GPIO_Init(&Button);
}

int main(void){

	GPIO_setup();

	while(1){
		if(!GPIO_ReadPin(Button.pGPIOx,GPIO_PIN_13)){
			GPIO_TogglePin(LED.pGPIOx, GPIO_PIN_5);
			delay(500000);
		}else{
			GPIO_WritePin(Button.pGPIOx,GPIO_PIN_13,RESET);
		}
	}
}

/* Reference file: 
   https://kleinembedded.com/stm32-without-cubeide-part-1-the-bare-necessities/
*/

