#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>

#include "i8254.h"

unsigned int count_freq = 0;
int hook_id = 0;

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  if(timer < 0 | timer > 2){
    printf("TIMER MUST BE BETWEEN 0 AND 2\n");
    return 1;
  }
  if(freq< 19 | freq > TIMER_FREQ){
    return 1;
  }

  uint8_t statusb, msb, lsb;
  uint16_t val = TIMER_FREQ / freq;
  util_get_MSB(val, &msb);
  util_get_LSB(val, &lsb);
  if(timer_get_conf(timer, &statusb) != 0){
    return 1;
  }

  uint8_t last_bits = statusb & 0x0F;


  switch(timer){
    case 0:
      statusb = last_bits | TIMER_SEL0 | TIMER_LSB_MSB;
      sys_outb(TIMER_CTRL, statusb);
      sys_outb(TIMER_0, lsb);
      sys_outb(TIMER_0, msb);
      break;
    case 1:
      statusb = last_bits | TIMER_SEL1 | TIMER_LSB_MSB;
      sys_outb(TIMER_CTRL, statusb);
      sys_outb(TIMER_1, lsb);
      sys_outb(TIMER_1, msb);
      break;
    case 2:
      statusb = last_bits | TIMER_SEL2 | TIMER_LSB_MSB;
      sys_outb(TIMER_CTRL, statusb);
      sys_outb(TIMER_2, lsb);
      sys_outb(TIMER_2, msb);
      break;
    default:
      return 1;
      break;
  }
  return 0;
}




int (timer_subscribe_int)(uint8_t *bit_no) {
  *bit_no = BIT(hook_id);  
  if(sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id) != 0){
    return 1;
  }

  return 0;
}





int (timer_unsubscribe_int)() {

  if(sys_irqrmpolicy(&hook_id) != 0){
    return 1;
  }
  return 0;
}





void (timer_int_handler)() {
  count_freq++;
}




int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  uint8_t readback = TIMER_RB_CMD | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer);

  if(sys_outb(TIMER_CTRL, readback) != 0){
    return 1;
  }
  switch(timer){
    case 0:
      if(util_sys_inb(TIMER_0, st) != 0){
        return 1;
      }
      break;
    case 1:
      if(util_sys_inb(TIMER_1, st) != 0){
        return 1;
      }
      break;
    case 2:
      if(util_sys_inb(TIMER_2, st) != 0){
        return 1;
      }
      break;
    default:
      return 1;
      break;
  }
  return 0;
}





int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {

  union timer_status_field_val val;
  switch(field){
    case tsf_all:
      val.byte = st;
      break;

    case tsf_initial:
      if((st & 0x30) == TIMER_LSB){
        val.in_mode = LSB_only;
      }
      else if((st & 0x30) == TIMER_MSB){
        val.in_mode = MSB_only;
      }
      else if((st & 0x30) == TIMER_LSB_MSB){
        val.in_mode = MSB_after_LSB;
      }
      else{
        return 1;
      }
      break;

    case tsf_mode:
      if((st & 0x0E) == 0){
        val.count_mode = 0;
      }
      else if((st & 0x0E) == 2){
        val.count_mode = 1;
      }
      else if((st & 0x0E) == 4 | (st & 0x0E) == 12){
        val.count_mode = 2;
      }
      else if((st & 0x0E) == 6 | (st & 0x0E) == 14){
        val.count_mode = 3;
      }
      else if((st & 0x0E) == 8){
        val.count_mode = 4;
      }
      else if((st & 0x0E) == 10){
        val.count_mode = 5;
      }
      else{
        return 1;
      }
      break;
    case tsf_base:
      if((st & 0x01) == 1){
        val.bcd = true;
      }
      else if((st & 0x01) == 0){
        val.bcd = false;
      }
      else{
        return 1;
      }
      break;         
  }
  if(timer_print_config(timer,field, val) != 0){
    return 1;
  }
  return 0;
}
