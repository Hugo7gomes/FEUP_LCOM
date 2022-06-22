#include <lcom/lcf.h>

#include "interrupts.h"

uint8_t mouseIRQ, timerIRQ, keyboardIRQ, uartIRQ;


int (unsubscribeAll)(void){
	if(mouse_unsubscribe_int() != 0) {
		return 1;
	}
	

	if(timer_unsubscribe_int() != 0) {
		return 1;
	}

	if(keyboard_unsubscribe_int() != 0) {
		return 1;
	}

	if(uart_unsubscribe_int() != 0){
		return 1;
	}
	return 0;
}

int (subscribeAll) (void){
	if(mouse_subscribe_int(&mouseIRQ) != 0){
		return 1;
	}

	if(timer_subscribe_int(&timerIRQ) != 0){
		return 1;
	} 

	if(keyboard_subscribe_int(&keyboardIRQ) != 0) {
		return 1;
	}
	if(uart_subscribe_int(&uartIRQ) != 0){
		return 1;
	}
	return 0;
}
