#include <lcom/lcf.h>

#include <stdint.h>

/**
 * @brief gets the least significant byte of the parameter val
 * @param val the number to get the least signicant byte from
 * @param lsb the register where the least significant byte is stored
 * 
 */
int(util_get_LSB)(uint16_t val, uint8_t *lsb);

/**
 * @brief gets the most significant byte of the parameter val
 * @param val the number to get the most signicant byte from
 * @param lsb the register where the most significant byte is stored
 * 
 */
int(util_get_MSB)(uint16_t val, uint8_t *msb);

/**
 * @brief reads 8 bits from the port 
 * @param port port where its read the value
 * @param value register where it's stored the 8 bits read from the port
 * 
 */
int (util_sys_inb)(int port, uint8_t *value);
