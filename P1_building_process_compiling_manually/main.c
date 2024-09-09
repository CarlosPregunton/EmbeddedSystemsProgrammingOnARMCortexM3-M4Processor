#include "led.h"
#include "usart.h"
#include "timebase.h"

void motor_run(void);
void motor_stop(void);
void valve_close(void);
void valve_open(void);
int motor_main(void);
int valve_main(void);

int main(void){

	led_init();
	timebase_init();
	usart_tx_init();
	usart_enabled();
	while(1){
		uint32_t volatile start = 0;
		if(start == 0){
			motor_main();
		}else{
			valve_main();
		}
	}
}

void motor_run(void){
	printf("Motor is running");
}
void motor_stop(void){
	printf("Motor is stop");
}
void valve_close(void){
	printf("The valve is close");
}
void valve_open(void){
	printf("The valve is open");
}

int motor_main(){
	while(1){
		motor_run();
		delay(1);
		motor_stop();
		delay(1);
	}
}

int valve_main(){
	while(1){
		valve_open();
		delay(1);
		valve_close();
		delay(1);
	}
}
//When an exception occurs by exception we mean an interrupt
//When an exception occurs, set in registers need to be preserved
//so after the exception or interruption finishes its execution, we
//can go back and take those contents and put them back in those same
//registers and those will allow the program to continue from where
//we left off before the execution occurred.

//When an exception occurs, set in registers need to be preserved.
//So that after the exception or interrupt finishes its execution
//, we can go back and take those contents and put them back in those
//same registers. This allow the program to continue from where we
//left off before the exception occurred.
