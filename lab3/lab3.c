#include <lcom/lcf.h>

#include <lcom/lab3.h>

#include <stdbool.h>
#include <stdint.h>

#include "keyboard.h"
#include "timer.h"


int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

extern uint8_t scanCode;
extern uint32_t count;
extern unsigned int count_freq;

int(kbd_test_scan)() {
  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq, size;
  uint8_t sCodeBytes[2];
  bool make;

  if(kbc_subscribe_int(&keyboard_irq)==1){    //check if subscription worked
    printf("CANNOT SUBSCRIBE INT\n");
    return 1;
  }

  while(scanCode != ESC_BREAKCODE){
    if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)){                             
      switch (_ENDPOINT_P(msg.m_source)){
        case HARDWARE:
          if (msg.m_notify.interrupts & keyboard_irq){  
            
            kbc_ih();
            
            if(scanCode == TWO_BYTE_SCANCODES){
              size = 2;
            }else{
              size = 1;
            }

            if(scanCode & MAKE_CODE){
              make = false;
            }else{
              make = true;
            }

            sCodeBytes[0] = scanCode;
            sCodeBytes[1] = scanCode;

            if(kbd_print_scancode(make, size, sCodeBytes) == 1){
              printf("CANNOT PRINT SCANCODE\n");
              return 1;
            }
          }  
          
          break;   

      default:
          break;   
      }     
    }
  }


  if (kbc_unsubscribe_int() != 0) {            //check if unsubscription worked
      printf("CANNOT UNSUBSCRIBE INT \n");
      return 1;
  }

  if(kbd_print_no_sysinb(count) != 0){
    printf("CANNOT PRINT COUNTER \n");
    return 1;
  }

  count = 0;
  scanCode = 0;

  return 0;
}

int(kbd_test_poll)() {
  uint8_t status, size;
  uint8_t sCodeBytes[2];
  bool make = false;

  while(scanCode != ESC_BREAKCODE){
    if(util_sys_inb(KBC_ST_REG, &status) != 0){
      printf("CANNOT READ STATUS REGISTER\n");
      return 1;
    }

    if(!(status & ST_PARITY) && !(status & ST_TOUT) && !(status & ST_AUX) && (status & ST_OBF)){
      if(util_sys_inb(KBC_OUT_BUF, &scanCode) != 0){
        printf("CANNOT READ OUTPUT BUFFER\n");
        return 1;
      }

      if(scanCode == TWO_BYTE_SCANCODES){
        size = 2;
      }else{
        size = 1;
      }

      if(scanCode & MAKE_CODE){
        make = false;
      }else{
        make = true;
      }
      
      sCodeBytes[0] = scanCode;
      sCodeBytes[1] = scanCode;

      if(kbd_print_scancode(make, size, sCodeBytes) != 0){
        printf("CANNOT PRINT SCANCODE");
        return 1;
      }
  }
  else{
      tickdelay(micros_to_ticks(DELAY_US));
    }
  }

  if(enableInterupt() != 0){
    printf("ERROR REENABLING THE INTERRUPTIONS\n");
    return 1;
  }

  if(kbd_print_no_sysinb(count) != 0){
    printf("CANNOT PRINT COUNTER \n");
    return 1;
  }

  count = 0;
  scanCode = 0;
  return 0;
}


int(kbd_test_timed_scan)(uint8_t n) {
  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq, size, timer_irq;
  uint8_t sCodeBytes[2];
  bool make;

  if(timer_subscribe_int(&timer_irq) != 0){
    printf("CANNOT SUBSCRIBE TIMER\n");
    return 1;
  }

  if(kbc_subscribe_int(&keyboard_irq) != 0){    //check if subscription worked
    printf("CANNOT SUBSCRIBE INT\n");
    return 1;
  }

  while((scanCode != ESC_BREAKCODE) & (count_freq/60.0 < n)){
    if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)){                             
      switch (_ENDPOINT_P(msg.m_source)){
        case HARDWARE:
          if (msg.m_notify.interrupts & keyboard_irq){  
            
            kbc_ih();
            
            if(scanCode == TWO_BYTE_SCANCODES){
              size = 2;
            }else{
              size = 1;
            }

            if(scanCode & MAKE_CODE){
              make = false;
            }else{
              make = true;
            }

            sCodeBytes[0] = scanCode;
            sCodeBytes[1] = scanCode;

            if(kbd_print_scancode(make, size, sCodeBytes) == 1){
              printf("CANNOT PRINT SCANCODE\n");
              return 1;
            }
            
            count_freq = 0;
          
          }else if(msg.m_notify.interrupts & timer_irq){
            timer_int_handler();
          }
          
          break;   

        default:
          break;   
      }     
    }else{

    }
  }  
    if(timer_unsubscribe_int() != 0){
      printf("CANNOT SUBSCRIBE TIMER\n");
      return 1;
    }

    if (kbc_unsubscribe_int() != 0) {           
      printf("CANNOT UNSUBSCRIBE INT \n");
      return 1;
    }

    if(kbd_print_no_sysinb(count) != 0){
      printf("CANNOT PRINT COUNTER \n");
      return 1;
    }

    count = 0;
    scanCode = 0;

    return 0;
}
