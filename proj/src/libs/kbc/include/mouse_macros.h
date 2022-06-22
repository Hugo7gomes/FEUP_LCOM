#ifndef _LCOM_MOUSE_MACROS_H_
#define _LCOM_MOUSE_MACROS_H_

#include <lcom/lcf.h>


#define MOUSE_IRQ 12

//STATUS WORD
#define STATUS_REG 0x64
#define CONTROL_REG 0x64
#define ST_PARITY BIT(7)
#define ST_TOUT BIT(6)
#define ST_AUX BIT(5)
#define ST_INH BIT(4)
#define ST_A2 BIT(3)
#define ST_SYS BIT(2)
#define ST_IBF BIT(1)
#define ST_OBF BIT(0)

#define WRITE_MOUSE 0xD4
#define IN_BUF_ARG 0x60 //write arguments to kbc
#define IN_BUF_COMMAND 0x64 
#define OUT_BUF 0x60
#define ACK 0xFA
#define NACK 0xFE
#define ERROR 0xFC
#define STREAM_MODE 0xEA
#define REMOTE_MODE 0xF0
#define ENABLE_DATA_REPORT 0xF4
#define DISABLE_DATA_REPORT 0xF5

//DATA PACKET
#define Y_OVFL BIT(7)
#define X_OVFL BIT(6)
#define Y_SIGN BIT(5)
#define X_SIGN BIT(4)
#define MID_BUTTON BIT(2)
#define RIGHT_BUTTON BIT(1)
#define LEFT_BUTTON BIT(0)
#define BYTE1_DEF 0x08
#define FAILS_MAX 2

#define WIDTH_MOUSE 16
#define HEIGHT_MOUSE 19




#endif
