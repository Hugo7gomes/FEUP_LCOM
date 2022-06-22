#include "keyboard.h"

uint8_t scanCode = 0;
int KBC_id = KBD_IRQ;
	
uint32_t count = 0;

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  *lsb =(uint8_t) val;
  return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  val = val >> 8;
  *msb = (uint8_t) val;
  return 0;
}

int (util_sys_inb)(int port, uint8_t *value) {
  uint32_t newVal;

  if(sys_inb(port, &newVal) != 0){
    printf("ERROR IN SYS_INB");
    return 1;
  }
  *value = newVal | 0x00 ;
  
  #ifdef LAB3
  count++;
  #endif
  return 0;
}


//interrupt handler	
void (kbc_ih)() {
	uint8_t st_reg;

	if(util_sys_inb(KBC_ST_REG ,&st_reg) != 0){
		printf("ERROR READING STATUS_REG");
		return;
	}

	if((st_reg & ST_PARITY) != 0){
		printf("PARITY ERROR\n");
		return;
	}

	if((st_reg & ST_TOUT) != 0){
		printf("TIMEOUT ERROR\n");
		return;
	}

	if((st_reg & ST_AUX) != 0){
		printf("MOUSE ERROR\n");
		return;
	}


	if((st_reg & ST_OBF) == 0){
		printf("ERROR OUTPUT BUFFER EMPTY \n");
		return;
	}


	if(util_sys_inb(KBC_OUT_BUF, &scanCode) != 0){
		printf("ERROR READING OUTPUT BUFFER\n");
		return;
	}
}

int (kbc_subscribe_int)(uint8_t *bit_no){
	*bit_no = BIT(KBC_id);
	if(sys_irqsetpolicy(KBD_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE,&KBC_id) != 0){
		printf("CANNOT SUBSCRIBE INT\n");
		return 1;
	}
	return 0;
}

int (kbc_unsubscribe_int()){
	if(sys_irqrmpolicy(&KBC_id) == 1){
		printf("CANNOT UNSUBSCRIBE INT\n");
		return 1;
	}

	return 0;
}

int (enableInterupt)(){
	uint8_t command;

	if(sys_outb(KBC_ST_REG,RCOMMAND) != 0){
		printf("CANNOT WRITE READ_COMMAND TO STATUS REGISTER\n");
		return 1;
	}

  if(util_sys_inb(KBC_OUT_BUF, &command) != 0){
    printf("CANNOT READ COMMAND BYTE\n");
    return 1;
  }

	command = command | ENABLE_INTERRUPT;

	if(sys_outb(KBC_ST_REG, KBC_OUT_BUF) != 0){
		printf("CANNOT WRITE OUTBUFFER TO STATUS REGISTER\n");
		return 1;
	}

	if(sys_outb(KBC_OUT_BUF, command) != 0){
		printf("CANNOT WRITE COMMAND BYTE\n");
		return 1;
}
  return 0;

}
