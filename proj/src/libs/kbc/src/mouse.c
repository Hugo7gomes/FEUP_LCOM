#include <stdbool.h>
#include "libs/kbc/include/mouse.h"

extern uint16_t posX;
extern uint16_t posY;

int mouse_id;
uint8_t counter;

bool error_reading = false;
bool x_negative,y_negative;
int x_pos = 0, y_pos = 0;
int byte[3];

bool temp = true;
bool serialPortOn = false;

uint32_t colorBG = 0;
uint32_t colorL = 63;



void handle_byte(struct packet *pp){
	pp->bytes[0] = byte[0];
	pp->bytes[1] = byte[2];
  pp->rb = false;
  pp->mb = false;
  pp->lb = false;
  pp->x_ov = false;
  pp->y_ov = false;
  bool x_negative = false;
  bool y_negative = false;
  pp->delta_x = 0;
  pp->delta_y = 0;

  if(byte[0] & Y_OVFL){
      pp->y_ov = true;
  }
  if(byte[0] & X_OVFL){
      pp->x_ov = true;
  }
  if(byte[0] & Y_SIGN){
      y_negative = true;
  }
  if(byte[0]& X_SIGN){
      x_negative = true;
  }
  if(byte[0] & MID_BUTTON){
      pp->mb = true;
  }
  if(byte[0] & RIGHT_BUTTON){
      pp->rb = true;
  }
  if(byte[0] & LEFT_BUTTON){
      pp->lb = true;
  }
  if(x_negative){
    pp->delta_x = byte[1] -256;
	}
	else{
    pp->delta_x = byte[1]; 
	}
	if(y_negative){
    pp->delta_y = byte[2] -256;
  }
  else{
    pp->delta_y = byte[2]; 
  }
}



int write_to_mouse(uint8_t argument){
	uint8_t acknowledge;
	uint8_t st_reg;
	uint8_t fails = 0;

	while(fails < FAILS_MAX){
		if(util_sys_inb(STATUS_REG ,&st_reg) != 0){
			printf("ERROR READING STATUS_REG");
			return 1;
		}

		if((st_reg & ST_IBF) == 0){
			if(sys_outb(IN_BUF_COMMAND, WRITE_MOUSE)){
				return 1;
			}
		}
		else{continue;}

		if(util_sys_inb(STATUS_REG ,&st_reg) != 0){
			printf("ERROR READING STATUS_REG");
			return 1;
		}

		if((st_reg & ST_IBF) == 0){
			if(sys_outb(IN_BUF_ARG, argument)){
				return 1;
			}
		}
		else{continue;}

		tickdelay(micros_to_ticks(20000));

		if(util_sys_inb(OUT_BUF, &acknowledge)){
			return 1;
		}

		if(acknowledge == ACK){
			break;
		}

		fails++;
	}
	return 0;
}


int mouse_enable_info(){
	if(write_to_mouse(STREAM_MODE)){
		return 1;
	}
	if(write_to_mouse(ENABLE_DATA_REPORT)){
		return 1;
	}
	return 0;
} 


int mouse_disable_info(){
	if(write_to_mouse(DISABLE_DATA_REPORT)){
		return 1;
	}
	if(write_to_mouse(STREAM_MODE)){
		return 1;
	}


	return 0;
}


int (mouse_subscribe_int)(uint8_t *bit_no){
	*bit_no = BIT(3);
	mouse_id = 3;
	if(sys_irqsetpolicy(MOUSE_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE,&mouse_id) != 0){
		printf("CANNOT SUBSCRIBE INT\n");
		return 1;
	}
	return 0;
}

int (mouse_unsubscribe_int)(){
	if(sys_irqrmpolicy(&mouse_id) == 1){
		printf("CANNOT UNSUBSCRIBE INT\n");
		return 1;
	}

	return 0;
}


void (mouse_ih)(void){
	uint8_t st_reg;
	uint8_t mouse_byte;


	if(util_sys_inb(STATUS_REG ,&st_reg) != 0){
		printf("ERROR READING STATUS_REG");
		error_reading = true;
		counter++;
		return;
	}

	if((st_reg & ST_PARITY) != 0){
		printf("PARITY ERROR\n");
		error_reading = true;
		counter++;
		return;
	}

	if((st_reg & ST_TOUT) != 0){
		printf("TIMEOUT ERROR\n");
		error_reading = true;
		counter++;
		return;
	}
	
	if((st_reg & ST_AUX) != 0x20){
		printf("MOUSE ERROR");
		error_reading = true;
		counter++;
		return;
	}


	if((st_reg & ST_OBF) == 0){
		printf("ERROR OUTPUT BUFFER EMPTY \n");
		error_reading = true;
		counter++;
		return;
	}



	if(util_sys_inb(OUT_BUF ,&mouse_byte) != 0){
		printf("ERROR READING STATUS_REG");
		error_reading = true;
		counter++;
		return;
	}
	byte[counter] = mouse_byte;
	counter++;
}

void interruptsMouse(){
	mouse_ih();

	struct packet pp;

  if(error_reading && counter != 3){
      return;
  }
  else if(error_reading && counter == 3){
      error_reading = false;
      counter = 0;
  }
  else if((!error_reading) && counter == 3){
      handle_byte(&pp);
      counter = 0;

      x_pos += pp.delta_x;
      y_pos -= pp.delta_y;
      

      if(x_pos < 0){
          x_pos = 0;
      }

      if(x_pos + WIDTH_MOUSE > get_hres()){
          x_pos = get_hres() - WIDTH_MOUSE;
      }


      if(y_pos < 0){
          y_pos = 0;
      }

      if(y_pos + HEIGHT_MOUSE  >= get_vres()){
          y_pos = get_vres() - HEIGHT_MOUSE;
      }

      if(pp.lb && (x_pos > 80 && x_pos < 280) && (y_pos > 10 && y_pos < 70)){
          temp = false;
      }

      if(pp.lb && x_pos > 520 && x_pos <720  && y_pos > 10 && y_pos < 70){
      	colorBG++;
      	if(colorBG >= 64){
      		colorBG = 0;
      	}
      }

      if(pp.lb && x_pos > 740 && x_pos <940  && y_pos > 10 && y_pos < 70){
      	colorL++;
      	if(colorL >= 64){
      		colorL = 0;
      	}
      }

      if(pp.lb && x_pos > 300 && x_pos <500  && y_pos > 10 && y_pos < 70){
      	if(serialPortOn){
      		serialPortOn = false;
      	}else{
      		serialPortOn = true;
      	}
      }

	  if(pp.lb && x_pos > 0 && y_pos > 110){
		posX = (x_pos/LETTER_WIDTH)*LETTER_WIDTH;
		posY = (y_pos/LETTER_HEIGHT)*LETTER_HEIGHT;
	  }
  }
}

int getXpos(void){
	return x_pos;
}


int getYpos(void){
	return y_pos;
}







