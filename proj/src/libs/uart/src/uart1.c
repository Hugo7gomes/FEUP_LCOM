#include "libs/uart/include/uart1.h"


int uart_hook_id;

int(uart_subscribe_int)(uint8_t *bit_no){
	*bit_no = BIT(COM1_IRQ);
	uart_hook_id = COM1_IRQ;
	if(sys_irqsetpolicy(COM1_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE,&uart_hook_id) != 0){
		printf("CANNOT SUBSCRIBE UART INTERRUPT\n");
		return 1;
	}

	if(sys_irqenable(&uart_hook_id)){
		printf("CANNOT ENABLE UART INTERRUPT\n");
		return 1;		
	}
	return 0;
}

int(uart_unsubscribe_int)(void){

	if(sys_irqdisable(&uart_hook_id)){
		printf("CANNOT DISABLE UART INTERRUPT\n");
		return 1;
	}

	if(sys_irqrmpolicy(&uart_hook_id)){
		printf("CANNOT UNSUBSCRIBE UART INT\n");
		return 1;
	}
	return 0;
}

int uart_read(uint32_t base, uint32_t port, uint8_t *data){
	if(util_sys_inb(base+port, data)){
		return 1;
	}
	return 0;
}

int uart_write(uint32_t base, uint32_t port, uint32_t data){
	if(sys_outb(base+port, data)){
		return 1;
	}
	return 0;
}

int uart_send(uint8_t word_send){
	uint8_t lsr_stat;
	if(uart_read(COM1_BASE, LSR, &lsr_stat)){
		return 1;
	}
	if((lsr_stat & THRE) == 0){
		return 1;
	}
	if(uart_write(COM1_BASE, THR, word_send)){
		return 1;
	}
	return 0;
}

int uart_receive(uint8_t *word_received){
	uint8_t lsr_stat, iir_stat;
	if(uart_read(COM1_BASE, IIR, &iir_stat)){
		return 1;
	}

	if(uart_read(COM1_BASE, LSR, &lsr_stat)){
		return 1;
	}

	if(lsr_stat & (FE | PE | OE)){
		return 1;
	}
	if(uart_read(COM1_BASE, RBR, word_received)){
		return 1;
	}
	return 0;
}

int (uart_set_conf)(bool receiver){
	uint32_t command_lcr = 0;
	command_lcr = CHAR_8 | STOP_1 | NO_PAR | DLAB;

	if(uart_write(COM1_BASE, LCR, command_lcr)){
		return 1;
	}
	uint8_t lsb, msb;
	lsb = (CLOCK_UART/BIT_RATE) & 0xFF;
	msb = ((CLOCK_UART/BIT_RATE)>> 8) & 0xFF;

	if(uart_write(COM1_BASE, DLL, lsb)){
		return 1;
	}
	if(uart_write(COM1_BASE, DLM, msb)){
		return 1;
	}
	command_lcr = 0;
	command_lcr = CHAR_8 | STOP_1 | NO_PAR;
	if(uart_write(COM1_BASE, LCR, command_lcr)){
		return 1;
	}
	uint32_t interrupt_conf = 0;
	if(receiver){
		interrupt_conf = ERBFI;
	}
	if(uart_write(COM1_BASE, IER, interrupt_conf)){
		return 1;
	}
	return 0;
}


