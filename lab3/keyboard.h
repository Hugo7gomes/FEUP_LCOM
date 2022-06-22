#ifndef _KEYBOARD_H
#define _KEYBOARD_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include "i8042.h"

void (kbc_ih)(void);

int (util_sys_inb)(int port, uint8_t *value);

int(kbc_subscribe_int)(uint8_t *bit_no);

int(kbc_unsubscribe_int)();

int(enableInterupt)();
#endif /*_KEYBOARD_H */
