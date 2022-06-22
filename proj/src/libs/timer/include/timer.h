#ifndef _TIMER_H
#define _TIMER_H
#include "i8254.h"
#include "libs/utils/include/utils.h"

/**
 * @brief changes the operating frequency of a timer
 *
 * @param timer	timer to configure
 * @param freq	timer operating frequency
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (timer_set_frequency)(uint8_t timer, uint32_t freq);

/**
 * @brief subscribes timer interrupts
 * 
 * @param bit_no address of memory to be initialized with the bit number to be set in the mask returned upon an interrupt
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int (timer_subscribe_int)(uint8_t *bit_no);

/**
 * @brief unsubscribes timer interrupts
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (timer_unsubscribe_int)();

/**
 * @brief reads the input timer configuration via read-back command
 *
 * @param timer	timer whose configuration to read (Ranges from 0 to 2)
 * @param st address of memory position to be filled with the timer config

 * @return int returns 0 in case of success and 1 otherwise
 */
int (timer_get_conf)(uint8_t timer, uint8_t *st);


#endif
