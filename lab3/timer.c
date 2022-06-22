#include <lcom/lcf.h>
#include <lcom/timer.h>
#include <stdint.h>

#include "i8254.h"

unsigned int count_freq=0;
int hook_id = TIMER0_IRQ; 

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  if(timer < 0 | timer > 2){
    printf("ERROR TIMER MUST BE BETWEEN 0 AND 2\n");
    return 1;
  }

  uint8_t msb,lsb;
  uint16_t aux = TIMER_FREQ / freq;                       
  util_get_LSB(aux,&lsb);
  util_get_MSB(aux,&msb);

  uint8_t st;
  
  if(timer_get_conf(timer,&st) == 1){
    printf("CANNOT GET CONFIG\n");
    return 1;
  }

  switch(timer){
  case 0:
    st = ((st & 0x0F) | TIMER_LSB_MSB | TIMER_SEL0);
    sys_outb(TIMER_CTRL, st);
    sys_outb(TIMER_0, lsb);
    sys_outb(TIMER_0, msb);
    break;
  
  case 1:
    st = ((0x0F & st) | TIMER_LSB_MSB | TIMER_SEL1);
    sys_outb(TIMER_CTRL, st);
    sys_outb(TIMER_1, lsb);
    sys_outb(TIMER_1, msb);
    break;

  case 2:
    st = ((0x0F & st) | TIMER_LSB_MSB | TIMER_SEL2);
    sys_outb(TIMER_CTRL, st);
    sys_outb(TIMER_2, lsb);
    sys_outb(TIMER_2, msb);
    break;
  }

  return 0;
}



int (timer_subscribe_int)(uint8_t *bit_no) { 
  *bit_no = BIT(hook_id); 
  if(sys_irqsetpolicy(TIMER0_IRQ,IRQ_REENABLE, &hook_id) == 1){
    printf("CANNOT SUBSCRIBE INT\n");
    return 1;
  }

  return 0;
}

int (timer_unsubscribe_int)() {
  if(sys_irqrmpolicy(&hook_id) == 1){
    printf("CANNOT UNSUBSCRIBE INT\n");
    return 1;
  }
  return 0;
}

void (timer_int_handler)() {
  count_freq++;
}



int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  uint8_t rbCMD = TIMER_RB_CMD | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer);

  if(sys_outb(TIMER_CTRL, rbCMD) != 0){
    printf("CANNOT WRITE CONTROL WORD\n");
    return 1;
  }

  
  switch(timer){
  case 0:
    if(util_sys_inb(TIMER_0, st) != 0){
      printf("CANNOT READ FROM TIMER 0\n");
      return 1;
    }
    break;
    
  case 1:
    if(util_sys_inb(TIMER_1, st) != 0){
      printf("CANNOT READ FROM TIMER 1\n");
      return 1;
    }
    break;
    
  case 2:
    if(util_sys_inb(TIMER_2, st) != 0){
      printf("CANNOT READ FROM TIMER 2\n");
      return 1;
    }
    break;
    
  default:
    printf("NO TIMER SELECTED\n");
    return 1;
    break;
  }
  
  return 0;
}

int (timer_display_conf)(uint8_t timer, uint8_t st,
                        enum timer_status_field field) {
  
  if(timer < 0 | timer > 2){
     printf("ERROR TIMER MUST BE BETWEEN 0 AND 2\n");
    return 1;
  }

  union timer_status_field_val uniVal;

  switch(field){
  case tsf_all:
    uniVal.byte = st;
    break;

  case tsf_initial:
    if((st & 0x30) == TIMER_LSB){
      uniVal.in_mode =LSB_only;
    }
    else if((st & 0x30) == TIMER_MSB){
      uniVal.in_mode = MSB_only;
    }
    else if((st & 0x30) == TIMER_LSB_MSB){
      uniVal.in_mode = MSB_after_LSB;
    }
    else{
      printf("CANNOT INITIALISE THE TIMER\n");
      return 1;
    }
    break;
  case tsf_mode:
    if((st & 0x0E) == 0){
      uniVal.count_mode = 0;
    }
    else if((st & 0x0E) == 2){
      uniVal.count_mode = 1;
    }
    else if((st & 0x0E) == 4 | (st & 0x0E) == 12){
      uniVal.count_mode = 2;
    }
    else if((st & 0x0E) == 6 | (st & 0x0E) == 14){
      uniVal.count_mode = 3;
    }
    else if((st & 0x0E) == 8){
      uniVal.count_mode = 4;
    }
    else if((st & 0x0E) == 10){
      uniVal.count_mode = 5;
    }
    else{
      printf("CANNOT INITIALISE COUNTING MODE\n");
      return 1;
    }
    break;
  case tsf_base:
    if((st & 0x01) == TIMER_BCD){
      uniVal.bcd = true;
    }
    else if((st & 0x01) == TIMER_BIN){
      uniVal.bcd = false;
    }
    else{
      printf("CANNOT INITIALISE BCD\n");
      return 1;
    }
    break;
  default:
    return 1;
 }
  
  
  if(timer_print_config(timer, field, uniVal) != 0){
    printf("ERROR PRINT CONF\n");
    return 1;
  }
  return 0;
}

