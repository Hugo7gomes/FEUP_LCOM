#ifndef _UART_H
#define _UART_H

#include <lcom/lcf.h>
#include "libs/libs.h"
#include "interrupts.h" 
#include "libs/xpms/include/xpms.h"
/**
 * @brief the loop function of tha main machine
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int mainLoop();
/**
 * @brief the loop function of the second machine (sender)
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int senderLoop();

#endif
