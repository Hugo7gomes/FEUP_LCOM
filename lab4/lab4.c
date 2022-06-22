// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "mouse.h"
#include "mouse_macros.h"
#include "timer.h"

// Any header files included below this line should have been created by you

extern uint8_t counter;
extern bool error_reading;
extern uint8_t mouse_byte;
extern unsigned int count_freq;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}


int (mouse_test_packet)(uint32_t cnt) {
    if(mouse_enable_info() != 0){
        return 1;
    }

    int ipc_status;
    double r = 0;
    message msg;
    uint8_t mouse_irq;
    counter = -1;
    uint32_t counter_packets = 0;
    struct packet pp;
    bool x_negative = false;
    bool y_negative = false;
    if(mouse_subscribe_int(&mouse_irq)){
        return 1;
    }
    while(counter_packets < cnt){
        if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
          printf("driver_receive failed with: %d", r);
          continue;
        }
        if (is_ipc_notify(ipc_status)){                          
          switch (_ENDPOINT_P(msg.m_source)){
            case HARDWARE:
                if (msg.m_notify.interrupts & mouse_irq){ 
                    mouse_ih();

                    if(error_reading && counter != 2){
                        continue;
                    }
                    else if(error_reading && counter == 2){
                        error_reading = false;
                        counter = -1;
                        counter_packets++;
                    }
                    else if((!error_reading) && counter == 0){
                        first_byte(&pp, &x_negative, &y_negative);
                    }
                    else if((!error_reading) && counter == 1){
                        second_byte(&pp, &x_negative);
                    }
                    else if((!error_reading) && counter == 2){
                        third_byte(&pp, &y_negative);
                        counter_packets++;
                        counter = -1;
                        mouse_print_packet(&pp);
                    }
                }
                break;
            default:
              break;
            }
        }
    }


    if(mouse_unsubscribe_int()){
        return 1;
    }

    if(mouse_disable_info() != 0){
        return 1;
    }

    return 0;
}

int (mouse_test_async)(uint8_t idle_time) {
    if(mouse_enable_info() != 0){
        return 1;
    }

    int ipc_status;
    double r = 0;
    message msg;
    uint8_t mouse_irq, timer_irq;
    counter = -1;
    struct packet pp;
    bool x_negative = false;
    bool y_negative = false;
    if(mouse_subscribe_int(&mouse_irq)){
        return 1;
    }

    if(timer_subscribe_int(&timer_irq) != 0){
        printf("CANNOT SUBSCRIBE TIMER\n");
        return 1;
    }

    while((count_freq/60.0 < idle_time)){
        if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
          printf("driver_receive failed with: %d", r);
          continue;
        }
        if (is_ipc_notify(ipc_status)){                          
          switch (_ENDPOINT_P(msg.m_source)){
            case HARDWARE:
                if (msg.m_notify.interrupts & mouse_irq){ 
                    mouse_ih();

                    if(error_reading && counter != 2){
                        continue;
                    }
                    else if(error_reading && counter == 2){
                        error_reading = false;
                        counter = -1;
                    }
                    else if((!error_reading) && counter == 0){
                        first_byte(&pp, &x_negative, &y_negative);
                    }
                    else if((!error_reading) && counter == 1){
                        second_byte(&pp, &x_negative);
                    }
                    else if((!error_reading) && counter == 2){
                        third_byte(&pp, &y_negative);
                        counter = -1;
                        count_freq = 0;
                        mouse_print_packet(&pp);
                    }
                }
                else if (msg.m_notify.interrupts & timer_irq){
                    timer_int_handler();
                }
                break;
            default:
              break;
            }
        }
    }
    if(timer_unsubscribe_int() != 0){
      printf("CANNOT SUBSCRIBE TIMER\n");
      return 1;
    }

    if(mouse_unsubscribe_int()){
        return 1;
    }

    if(mouse_disable_info() != 0){
        return 1;
    }

    return 0;
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
    int ipc_status;
    double r = 0;
    message msg;
    uint8_t mouse_irq;
    counter = -1;
    struct packet pp;
    bool stop = false;
    bool x_negative = false;
    bool y_negative = false;
    event_type_t event;
    mouse_event_t mouseEvent;

    if(mouse_enable_info() != 0){
        return 1;
    }

    if(mouse_subscribe_int(&mouse_irq)){
        return 1;
    }

    while(!stop){
        if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
          printf("driver_receive failed with: %d", r);
          continue;
        }
        if (is_ipc_notify(ipc_status)){                          
          switch (_ENDPOINT_P(msg.m_source)){
            case HARDWARE:
                if (msg.m_notify.interrupts & mouse_irq){ 
                    mouse_ih();

                    if(error_reading && counter != 2){
                        continue;
                    }
                    else if(error_reading && counter == 2){
                        error_reading = false;
                        counter = -1;
                    }
                    else if((!error_reading) && counter == 0){
                        first_byte(&pp, &x_negative, &y_negative);
                    }
                    else if((!error_reading) && counter == 1){
                        second_byte(&pp, &x_negative);
                    }
                    else if((!error_reading) && counter == 2){
                        third_byte(&pp, &y_negative);
                        counter = -1;
                        mouse_print_packet(&pp);

                        mouse_check_event(&pp, &event);
                        mouseEvent.type = event;
                        mouseEvent.moveX = pp.delta_x;
                        mouseEvent.moveY = pp.delta_y;
                        mouseEvent.lbdown = pp.lb;
                        mouseEvent.rbdown = pp.rb;
                        mouseEvent.mbdown = pp.mb; 

                        stop = !mouse_check_pattern(mouseEvent,x_len, tolerance);
                    }
                }
                break;
            default:
              break;
          }
        }
    }

    if(mouse_unsubscribe_int()){
        return 1;
    }

    if(mouse_disable_info() != 0){
        return 1;
    }

    return 0;
}










int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    /* This year you need not implement this. */
    printf("%s(%u, %u): under construction\n", __func__, period, cnt);
    return 1;
}
