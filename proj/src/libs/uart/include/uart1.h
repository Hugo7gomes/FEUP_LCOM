#ifndef _UART1_H
#define _UART1_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>

#include "libs/utils/include/utils.h"


#define COM1_IRQ 4

#define COM1_BASE 0x3F8
#define CLOCK_UART 115200

#define RBR 0x00 //receiver buffer register (read)
#define THR 0x00 //transmitter holding register (write)
#define DLL 0x00 //divisor latch (LS)
#define DLM 0x01 //divisor latch (MS)
#define IER 0x01 //interrupt enable register 
#define IIR 0x02 //interrupt identification register (read)
#define FCR 0x02 //FIFO control register (write)
#define LCR 0x03 //line control register 
#define MCR 0x04 //MODEM control register
#define LSR 0x05 //line status register
#define MSR 0x06 //MODEM status register
#define SCR 0x07 //scratch register

//interrupt enable register (IER)
#define EDSSI BIT(3) //Enable MODEM status interrupt
#define ELSI BIT(2) //Enable receiver line status interrupt
#define ETBEI BIT(1) //Enable Transmitter holding register empty interrupt
#define ERBFI BIT(0) //Enable received data available interrupt

//interrupt identification register (read) (IIR)
#define EN_FIFO (BIT(7) | BIT(6)) //FIFOs enabled
#define INT_BIT (BIT(3) | BIT(2) | BIT(1)) //interrupt ID bit
#define INT_PEND BIT(0) //"0" if interrupt pending

//FIFO control register (write) (FCR)
#define FIFO_TRIGGER (BIT(7) | BIT(6)) //FIFO TRIGGER RCVR
#define DMA_MODE BIT(3) //DMA select mode
#define XMIT_RESET BIT(2)//XMIT FIFO reset
#define RCVR_RESET BIT(1) //RCVR FIFO reset
#define ENBL_FIFO BIT(0) //FIFO ENABLE

//line control register (LCR) 
#define CHAR_8 (BIT(1) | BIT(0)) //8 bit chars
#define STOP_1 0x00 //1 stop per char
#define STOP_2 BIT(2) // 2 stops per char
#define NO_PAR 0x00 //no parity
#define BIT_RATE 9600
#define DLAB BIT(7) //divisor latch access bit


//line status register (LSR)
#define RCVR_ERR BIT(7) //error in RCVR FIFO
#define TEMT BIT(6) //transmitter empty
#define THRE BIT(5) //transmitter holding register
#define BI BIT(4) //Break interrupt
#define FE BIT(3) //framing error
#define PE BIT(2) //parity error
#define OE BIT(1) //overrun error
#define DR BIT(0) //data ready


/**
 * @brief subscribes uart interrupts
 * 
 * @param bit_no address of memory to be initialized with the bit number to be set in the mask returned upon an interrupt
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int (uart_subscribe_int)(uint8_t *bit_no);

/**
 * @brief unsubcribes uart interrupts
 *
 * @return int returns 0 in case of success and 1 otherwise
 */
int (uart_unsubscribe_int)(void);

/**
 * @brief Reads from uart port and saves it in data variable
 * 
 * @param base base address of COM
 * @param port offset of COM port
 * @param data data variable
 * @return int returns 0 in case of success and 1 otherwise
 */
int uart_read(uint32_t base, uint32_t port, uint8_t *data);

/**
 * @brief Writes data variable to uart port 
 * 
 * @param base base address of COM
 * @param port offset of COM port
 * @param data data to send
 * @return int returns 0 in case of success and 1 otherwise
 */
int uart_write(uint32_t base, uint32_t port, uint32_t data);

/**
 * @brief Sends a byte through COM1
 * 
 * @param word_send word to send
 * @return int returns 0 in case of success and 1 otherwise
 */
int uart_send(uint8_t word_send);

/**
 * @brief Receives a byte through COM1
 * 
 * @param word_received variable to store incoming data
 * @return int returns 0 in case of success and 1 otherwise
 */
int uart_receive(uint8_t *word_received);

/**
 * @brief Set uart configuration whether is a sender or a receiver
 * 
 * @param receiver 
 */
int (uart_set_conf)(bool receiver);

#endif
