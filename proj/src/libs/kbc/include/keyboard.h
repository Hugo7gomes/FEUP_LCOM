#ifndef _KEYBOARD_H
#define _KEYBOARD_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include "i8042.h"
#include "libs/xpms/include/xpms.h"

#define LETTER_HEIGHT 15
#define LETTER_WIDTH 20


struct letter
{
	char * p;
	uint16_t x;
	uint16_t y;
};

/**
 * @brief keyboard interrupt handler
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (keyboard_ih)(void);

/**
 * @brief subscribes keyboard interrupts
 * 
 * @param bit_no address of memory to be initialized with the bit number to be set in the mask returned upon an interrupt
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int(keyboard_subscribe_int)(uint8_t *bit_no);

/**
 * @brief unsubcribes keyboard interrupts
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int(keyboard_unsubscribe_int)();

/**
 * @brief reads scancodes
 * 
 */
void interruptsKB();

/**
 * @brief inserts the character corresponding to the key pressed into an array
 * 
 * @param breakCode of the key pressed
 */
void addLetterArray(uint16_t breakCode);

#endif /*_KEYBOARD_H */
