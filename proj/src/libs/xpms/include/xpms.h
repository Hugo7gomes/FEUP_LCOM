#ifndef _XPMS_H
#define _XPMS_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>
#include "videoCard.h"

/**
 * @brief loads all xpms into a memory buffer
 * 
 */
void loadXpms();

/**
 * @brief Reads a xpm 
 * 
 * @param map array containing xpm
 * @param wd variable to store width
 * @param ht variable to store height
 * @return char* pointer to xpm
 */
char *read_xpm(char *map[], int *wd, int *ht);

#endif
