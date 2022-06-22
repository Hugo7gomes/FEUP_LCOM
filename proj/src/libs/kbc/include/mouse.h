#ifndef _MOUSE_H
#define _MOUSE_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include "mouse_macros.h"
#include "videoCard.h"
#include "keyboard.h"

/**
 * @brief enables the data report from the mouse
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int mouse_enable_info();

/**
 * @brief handles the information contained in the 3 bytes from the mouse and puts the information inside the pp struct
 * 
 * @param pp struct that contains the information 
 */
void handle_byte(struct packet *pp);

/**
 * @brief disables the data report from the mouse
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int mouse_disable_info();

/**
 * @brief sends a command to the mouse
 * 
 * @param command command that's meant to be sent to the mouse
 * @return int returns 0 in case of success and 1 otherwise
 */
int write_to_mouse(uint8_t command);

/**
 * @brief unsubcribes mouse interrupts
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (mouse_unsubscribe_int)(void);

/**
 * @brief subcribes mouse interrupts
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int (mouse_subscribe_int)(uint8_t *bit_no);

/**
 * @brief mouse interrupt handler
 * 
 */
void (kbc_ih)(void);

/**
 * @brief handles the movement of the mouse and the buttons of the menu
 * 
 */
void interruptsMouse();

/**
 * @brief Get the Xpos of the mouse
 * 
 * @return int returns 0 in case of success and 1 otherwise 
 */
int getXpos(void);

/**
 * @brief Get the Ypos of the mouse
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int getYpos(void);

#endif
