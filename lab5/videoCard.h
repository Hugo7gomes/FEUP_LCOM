#ifndef _VIDEOCARD_H
#define _VIDEOCARD_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>

uint8_t get_RedFieldPosition(void);

uint8_t get_GreenFieldPosition(void);

uint8_t get_BlueFieldPosition(void);

uint16_t get_RedMaskSize(void);

uint16_t get_GreenMaskSize(void);

uint16_t get_BlueMaskSize(void);

uint16_t get_hres(void);

uint16_t get_vres(void);

unsigned get_bitsPerPixel(void);

int free_map_memory(void);

void drawPixMap(xpm_image_t image, uint8_t *pixMap, uint16_t x, uint16_t y);

void *(vg_init)(uint16_t mode);

int (vg_draw_rectangle) (uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

int (vg_draw_hline) (uint16_t x, uint16_t y, uint16_t len,uint32_t color);

int drawPixel(uint16_t x, uint16_t y, uint32_t color);

int clearScreen();

#endif /* _VIDEOCARD_H */
