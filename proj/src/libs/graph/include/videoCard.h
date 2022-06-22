#ifndef _VIDEOCARD_H
#define _VIDEOCARD_H
#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>
#include <minix/syslib.h>
#include <minix/sysutil.h>

#include "videoCard_macros.h"
#include "libs/xpms/include/xpms.h"
#include "libs/kbc/include/keyboard.h"

/**
 * @brief returns horizontal resolution
 * 
 * @return uint16_t horizontal resolution
 */
uint16_t get_hres(void);

/**
 * @brief returns vertical resolution
 * 
 * @return uint16_t vertical resolution
 */
uint16_t get_vres(void);

/**
 * @brief returns bits per pixel
 * 
 * @return unsigned bits per pixel
 */
unsigned get_bitsPerPixel(void);

/**
 * @brief releases video_buffer memory
 * 
 * @return int return 0 on success, 1 on failure
 */
int free_map_memory(void);

/**
 * @brief draws the pixMap in the screen
 * 
 * @param height 
 * @param width 
 * @param pixMap 
 * @param x 
 * @param y 
 */
void drawPixMap(int height, int width, char *pixMap, uint16_t x, uint16_t y);

/**
 * @brief draws the pixMap in the screen with selected color
 * 
 * @param height 
 * @param width 
 * @param pixMap 
 * @param x 
 * @param y 
 * @param color 
 */
void drawPixMapChangeColor(int height, int width, char *pixMap, uint16_t x, uint16_t y, uint32_t color);

/**
 * @brief  draws mouse pixMap ignoring background pixels
 * 
 * @param height 
 * @param width 
 * @param pixMap 
 * @param x 
 * @param y 
 */
void drawPixMapMouse(int height, int width, char *pixMap, uint16_t x, uint16_t y);

/**
 * @brief Initializes the video module in graphics mode.
 * 
 *  @param mode VBE mode to set
 */
void *(vg_init)(uint16_t mode);

/**
 * @brief Draws a filled rectangle whith selected color by changing the video RAM.
 * 
 * @param height 
 * @param width 
 * @param x 
 * @param y 
 * @param color 
 * 
 * @return int return 0 on success, 1 on failure
 */
int (vg_draw_rectangle) (uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

/**
 * @brief Draws a horizontal line with selected color by changing the video RAM.
 * 
 * @param len 
 * @param x 
 * @param y 
 * @param color
 *
 * @return int return 0 on success, 1 on failure
 */
int (vg_draw_hline) (uint16_t x, uint16_t y, uint16_t len,uint32_t color);

/**
 * @brief Draws a pixel with selected color by changing the video RAM. 
 * 
 * @param x 
 * @param y 
 * @param color 
 * @return int return 0 on success, 1 on failure
 */
int drawPixel(uint16_t x, uint16_t y, uint32_t color);

/**
 * @brief Sets all video_buffer pixels to zero (black).
 * 
 * @return int return 0 on success, 1 on failure
 */
int clearScreen(uint32_t color);

/**
 * @brief Draws menu rectangle, buttons and text.
 * 
 * @return int return 0 on success, 1 on failure
 */
int vg_drawMenu();

/**
 * @brief copies video_buffer(auxiliar buffer) to video RAM buffer. 
 * 
 */
void draw();

/**
 * @brief Returns information on the input VBE mode, including screen dimensions, color depth and VRAM physical address.
 * 
 * @param mode mode whose information should be returned
 * @param vbeModeInfo address of vbe_mode_info_t structure to be initialized
*/
int (vbe_mode_info)(uint16_t mode, vbe_mode_info_t *vbeModeInfo);

#endif /* _VIDEOCARD_H */
