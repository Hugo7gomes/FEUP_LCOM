#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#include <lcom/lcf.h>

#define KBD_IRQ 1


#define DELAY_US 20000

#define ST_PARITY BIT(7)
#define ST_TOUT BIT(6)
#define ST_AUX BIT(5)
#define ST_INH BIT(4)
#define ST_A2 BIT(3)
#define ST_SYS BIT(2)
#define ST_IBF BIT(1)
#define ST_OBF BIT(0)

#define RCOMMAND 0x20

#define KBC_IN_BUF 0x60
#define KBC_OUT_BUF 0x60
#define KBC_ST_REG 0x64
#define KBC_CMD_REG 0x64

#define ESC_BREAKCODE 0x81
#define TWO_BYTE_SCANCODES 0xE0
#define MAKE_CODE 0x80
#define ENABLE_INTERRUPT BIT(0) 

#endif
