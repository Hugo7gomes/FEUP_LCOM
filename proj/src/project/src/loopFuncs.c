#include "loopFuncs.h"


extern char *mouse[];

extern struct letter lettersArray[1360];
extern char* mapXpms[63];

extern uint8_t scanCode;

extern uint8_t mouseIRQ;
extern uint8_t timerIRQ;
extern uint8_t keyboardIRQ;
extern uint8_t uartIRQ;

extern bool temp;
extern bool serialPortOn;

extern uint32_t colorBG;
extern uint32_t colorL;


int mainLoop(){

    loadXpms();
    if(write_to_mouse(STREAM_MODE)){
        return 1;
    }

    if(subscribeAll() != 0) {
        return 1;
    }

    if(uart_set_conf(true)){
        return 1;
    }


    vg_init(INDEXED_MODE);

    uint8_t scanCodeUart;
    
    int w_mouse, h_mouse;   
    char *mouse_xpm = read_xpm(mouse,&w_mouse,&h_mouse);
    
    int ipc_status;
    double r = 0;
    message msg;

    while(temp) {
        if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
          printf("driver_receive failed with: %f", r);
          continue;
        }
        if (is_ipc_notify(ipc_status)){                          
          switch (_ENDPOINT_P(msg.m_source)){
            case HARDWARE:
                if (msg.m_notify.interrupts & mouseIRQ){ 
                    interruptsMouse();
                }
                else if(msg.m_notify.interrupts & timerIRQ){
                    timer_int_handler();

                    if(clearScreen(colorBG) != 0) {
                        unsubscribeAll();
                        vg_exit();
                        free_map_memory();
                        return 1;
                    }

                    if(vg_drawMenu() != 0) {
                        unsubscribeAll();
                        vg_exit();
                        free_map_memory();
                        return 1;
                    }


                    for(int i = 0; i < ((HRES/LETTER_WIDTH)*(VRES/LETTER_HEIGHT)); i++){
                        if(lettersArray[i].p != NULL){
                            drawPixMapChangeColor(LETTER_HEIGHT,LETTER_WIDTH,lettersArray[i].p,lettersArray[i].x,lettersArray[i].y,colorL);    
                        } 
                    }

                    drawPixMapMouse(h_mouse, w_mouse, mouse_xpm, getXpos(), getYpos());

                    draw();
                }
                else if(msg.m_notify.interrupts & keyboardIRQ){
                    interruptsKB();
                }
                else if(msg.m_notify.interrupts & uartIRQ){
                    if(uart_receive(&scanCodeUart)){ 
                        unsubscribeAll();
                        vg_exit();
                        free_map_memory();
                        return 1;
                    }

                    if(serialPortOn){
                        addLetterArray(scanCodeUart);
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    if(unsubscribeAll()){
        return 1;
    }
    vg_exit();
    free_map_memory();
    return 0;
}

int senderLoop(){
    if(keyboard_subscribe_int(&keyboardIRQ) != 0) {
        return 1;
    }
    
    if(uart_subscribe_int(&uartIRQ) != 0){
        return 1;
    }

    int ipc_status;
    double r = 0;
    message msg;
    
    bool loopStop = false;
    if(uart_set_conf(false)){
        return 1;
    }
    while(!loopStop) {
        if((r = driver_receive(ANY, &msg, &ipc_status))!= 0){
          printf("driver_receive failed with: %f", r);
          continue;
        }
        if (is_ipc_notify(ipc_status)){                          
          switch (_ENDPOINT_P(msg.m_source)){
            case HARDWARE:
                if(msg.m_notify.interrupts & keyboardIRQ){
                    if(keyboard_ih()){
                        return 1;
                    }
                    if(scanCode & MAKE_CODE){
                       printf("%u\n",scanCode); 
                       if(scanCode == ESC_BREAKCODE){
                        loopStop = true;
                        printf("Connection closed\n");
                        break;
                       } 
                       if(uart_send(scanCode)){
                        return 1;
                       }
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    if(keyboard_unsubscribe_int() != 0) {
        return 1;
    }

    if(uart_unsubscribe_int() != 0){
        return 1;
    }
    return 0;
}
