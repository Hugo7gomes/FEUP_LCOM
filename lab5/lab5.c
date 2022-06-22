// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <lcom/lab5.h>

#include <stdint.h>
#include <stdio.h>
#include "videoCard.h"
#include "keyboard.h"
#include "timer.h"

// Any header files included below this line should have been created by you

extern uint8_t scanCode;
extern unsigned int count_freq;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab5/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}




int(video_test_init)(uint16_t mode, uint8_t delay) {
  
  vg_init(mode);
  tickdelay(micros_to_ticks(delay * 1000000));
  vg_exit();
  free_map_memory();


  return 0;
}




int(video_test_rectangle)(uint16_t mode, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) {
  
  vg_init(mode);

  if(vg_draw_rectangle(x, y, width, height, color)){
    return 1;
  }

  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq;

  if(kbc_subscribe_int(&keyboard_irq)==1){    //check if subscription worked
    printf("CANNOT SUBSCRIBE INT\n");
    vg_exit();
    free_map_memory();
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
          }
          break;
        default:
          break;
        }
      }
    }
    if (kbc_unsubscribe_int() != 0) {            //check if unsubscription worked
      printf("CANNOT UNSUBSCRIBE INT \n");
      vg_exit();
      free_map_memory();
      return 1;
  }


  vg_exit();
  free_map_memory();
  return 0;
}






int(video_test_pattern)(uint16_t mode, uint8_t no_rectangles, uint32_t first, uint8_t step) {
  vg_init(mode);
  uint32_t RedFirst;
  uint32_t GreenFirst;
  uint32_t BlueFirst;
  switch(mode){
    case 0x105:
      for(int row = 0; row < no_rectangles; row++){ //row
        for(int col= 0; col < no_rectangles; col++){ //col
          uint8_t color = (first + (row * no_rectangles + col) * step) % (1 << get_bitsPerPixel());
          vg_draw_rectangle(col *(get_hres()/no_rectangles), row* (get_vres()/no_rectangles), (get_hres()/no_rectangles), (get_vres()/no_rectangles), color);
        }
      }
      break;
    case 0x115:
      RedFirst = (first >> get_RedFieldPosition()) & 0x000000FF;
      GreenFirst = (first >> get_GreenFieldPosition()) & 0x000000FF;
      BlueFirst = (first >> get_BlueFieldPosition()) & 0x000000FF;

      for(int row = 0; row < no_rectangles; row++){ //row
        for(int col= 0; col < no_rectangles; col++){ //col
          uint32_t red = (RedFirst + col * step) % (1 << get_RedMaskSize());
          uint32_t green = (GreenFirst + row * step) % (1 << get_GreenMaskSize());
          uint32_t blue = (BlueFirst+ (col + row) * step) % (1 << get_BlueMaskSize());
          uint32_t color= 0;
          color = color | (red << get_RedFieldPosition()) | (green << get_GreenFieldPosition()) | (blue << get_BlueFieldPosition());
          vg_draw_rectangle(col *(get_hres()/no_rectangles), row* (get_vres()/no_rectangles), (get_hres()/no_rectangles), (get_vres()/no_rectangles), color);
      }
    }
      break;
  }

  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq;

  if(kbc_subscribe_int(&keyboard_irq)==1){    //check if subscription worked
    printf("CANNOT SUBSCRIBE INT\n");
    vg_exit();
    free_map_memory();
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
          }
          break;
        default:
          break;
        }
      }
    }
    if (kbc_unsubscribe_int() != 0) {            //check if unsubscription worked
      printf("CANNOT UNSUBSCRIBE INT \n");
      vg_exit();
      free_map_memory();
      return 1;
  }


  vg_exit();
  free_map_memory();
  return 0;
}





int(video_test_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y) {
  uint16_t mode = 0x105;  
  vg_init(mode);
  enum xpm_image_type imageType= XPM_INDEXED;
  xpm_image_t image;

  uint8_t *pixMap = xpm_load(xpm, imageType, &image);
  drawPixMap(image, pixMap, x, y);


  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq;

  if(kbc_subscribe_int(&keyboard_irq)==1){    //check if subscription worked
    printf("CANNOT SUBSCRIBE INT\n");
    vg_exit();
    free_map_memory();
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
          }
          break;
        default:
          break;
        }
      }
    }
    if (kbc_unsubscribe_int() != 0) {            //check if unsubscription worked
      printf("CANNOT UNSUBSCRIBE INT \n");
      vg_exit();
      free_map_memory();
      return 1;
  }


  vg_exit();
  free_map_memory();
  return 0;
}





int(video_test_move)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate) {
  timer_set_frequency(0, fr_rate);
  bool done;
  int r, ipc_status;
  message msg;
  uint8_t keyboard_irq, timer_irq;

  uint16_t mode = 0x105;  
  vg_init(mode);
  enum xpm_image_type imageType= XPM_INDEXED;
  xpm_image_t image;

  uint8_t *pixMap = xpm_load(xpm, imageType, &image);
  drawPixMap(image, pixMap, xi, yi);

  if(timer_subscribe_int(&timer_irq) != 0){
    printf("CANNOT SUBSCRIBE TIMER\n");
    return 1;
  }

  if(kbc_subscribe_int(&keyboard_irq) != 0){    //check if subscription worked
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
          }

          if (msg.m_notify.interrupts & timer_irq){   
            timer_int_handler();
            if(!done){
              if(speed>0){
                if(xi== xf){
                  //clearScreen();
                  vg_draw_rectangle(xi,yi,image.width, image.height, 0);
                  yi += speed;
                  if(yi>yf){
                    yi = yf;
                    done = true;
                  } 
                  drawPixMap(image, pixMap, xi, yi);
                }

                else if(yi == yf){
                  //clearScreen();
                  vg_draw_rectangle(xi,yi,image.width, image.height, 0);
                  xi+= speed;
                  if(xi>xf){
                    xi = xf;
                    done = true;
                  }
                  drawPixMap(image, pixMap, xi, yi);

                }
              }
              else if(speed < 0 && (count_freq % (speed) == 0)){
                if(xi== xf){
                  //clearScreen();
                  vg_draw_rectangle(xi,yi,image.width, image.height, 0);
                  yi += speed;
                  if(yi>yf){
                    yi = yf;
                    done = true;
                  } 
                  drawPixMap(image, pixMap, xi, yi);
                }

                else if(yi == yf){
                  //clearScreen();
                  vg_draw_rectangle(xi,yi,image.width, image.height, 0);
                  xi+= speed;
                  if(xi>xf){
                    xi = xf;
                    done = true;
                  }
                  drawPixMap(image, pixMap, xi, yi);

                }
              }
            }
          }
          break;
        default:
          break;
        }
      }
    }
  if (kbc_unsubscribe_int() != 0) {           
    printf("CANNOT UNSUBSCRIBE INT \n");
    vg_exit();
    free_map_memory();
    return 1;
  }

  if(timer_unsubscribe_int() != 0){
    vg_exit();
    free_map_memory();
    return 1;
  }


  vg_exit();
  free_map_memory();
  return 0;

}





