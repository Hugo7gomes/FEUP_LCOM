#include <lcom/lcf.h>
#include "timer.h"

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





