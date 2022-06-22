#include <lcom/lcf.h>

#include "videoCard.h"
static vbe_mode_info_t modeInfo;
static void *video_mem;
static void *video_buffer;

unsigned int vram_size;
extern char* mapXpms[63];

int (vbe_mode_info)(uint16_t mode, vbe_mode_info_t *vbeModeInfo){
    mmap_t mmap;
    if(lm_alloc(sizeof(vbe_mode_info_t), &mmap) == NULL){
        return 1;
    }
    reg86_t reg86;
    memset(&reg86, 0, sizeof(reg86));
    reg86.ax = 0x4F01;
    reg86.es = PB2BASE(mmap.phys);
    reg86.di = PB2OFF(mmap.phys);
    reg86.cx = mode;
    reg86.intno = 0x10;
    if(sys_int86(&reg86) != OK){
        return 1;
    }

    char *src = (char *)mmap.virt;
    char *dest= (char *)vbeModeInfo;

    for(int i = 0; i < (int)mmap.size;i++){
    	dest[i] = src[i];
    }
    if(!lm_free(&mmap)){
        return 1;
    }
    return 0;
}


uint16_t get_hres(void){
	return modeInfo.XResolution;
}


uint16_t get_vres(void){
	return modeInfo.YResolution;
}

unsigned get_bitsPerPixel(void){
	return modeInfo.BitsPerPixel;
}


int free_map_memory(void){
	free(video_buffer);
	return 0;
}

void drawPixMap(int height, int width, char *pixMap, uint16_t x, uint16_t y){
	for(int row = 0; row < height; row++){ //y
    	for(int col= 0; col < width; col++){
    		drawPixel(x+col, y+row, *(pixMap));
      		pixMap++;
    	}
  	}
}

void drawPixMapChangeColor(int height, int width, char *pixMap, uint16_t x, uint16_t y, uint32_t color){
	for(int row = 0; row < height; row++){ //y
    	for(int col= 0; col < width; col++){
    		if(*(pixMap) != 0){
    			drawPixel(x+col, y+row, color);
    		}
      		pixMap++;
    	}
  	}
}

void drawPixMapMouse(int height, int width, char *pixMap, uint16_t x, uint16_t y){
	for(int row = 0; row < height; row++){ //y
    	for(int col= 0; col < width; col++){
    		if(*(pixMap) != 0){
    			drawPixel(x+col, y+row, *(pixMap));
    		}
      		pixMap++;
    	}
  	}
}




void *(vg_init)(uint16_t mode){

	struct minix_mem_range mr;
	unsigned int vram_base;
	
	int r;

	if(vbe_mode_info(mode, &modeInfo) != 0){
		printf("CANNOT READ VBE MODE INFO\n");
		return NULL;
	}


	vram_base = modeInfo.PhysBasePtr;
	vram_size = modeInfo.XResolution * get_vres() * (get_bitsPerPixel()/8);

	if(get_bitsPerPixel() % 8 != 0){
		vram_size += 1;;
	}



	mr.mr_base = (phys_bytes) vram_base;	
	mr.mr_limit = mr.mr_base + vram_size;  

	if( OK != (r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mr))){
   		panic("sys_privctl (ADD_MEM) failed: %d\n", r);
	}

	video_mem = vm_map_phys(SELF, (void *)mr.mr_base, vram_size);

	if(video_mem == MAP_FAILED){
   		panic("couldn't map video memory");
	}

	video_buffer = malloc(vram_size);

	reg86_t reg86;

	memset(&reg86, 0, sizeof(reg86));

	reg86.ax = 0x4F02;
	reg86.intno = 0x10;
	reg86.bx = 1<<14| mode;
	if( sys_int86(&reg86) != OK ) {
       	printf("set_vbe_mode: sys_int86() failed \n");
		return NULL; 
	}
	return video_mem;
}




int drawPixel(uint16_t x, uint16_t y, uint32_t color){
	uint32_t pos;
	if(x > get_hres() || y > get_vres()|| x< 0 || y< 0){
		return 1;
	}

	pos = get_hres() * y + x;
	memcpy((void*)((unsigned int)video_buffer + pos), &color, 1);
	return 0;
}


int (vg_draw_hline) (uint16_t x, uint16_t y, uint16_t len, uint32_t color){
	for(int i = 0; i< len; i++){
		drawPixel(x+i, y, color);
	}
	return 0;
}


int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color){
	for(int i = 0; i < height; i++){
		vg_draw_hline(x, y+i,width, color);
	}
	return 0;
}


int clearScreen(uint32_t color){
	memset(video_buffer,color,vram_size); //paints the entire screen black
	return 0;
}

void draw(){
	memcpy(video_mem,video_buffer,vram_size);
}

int vg_drawMenu(){
	if(vg_draw_rectangle(0,0,get_hres(),MENU_HEIGHT,63)){
		return 1;
	}
	if(vg_draw_rectangle(EXIT_BUTTON_X,BUTTON_MENU_Y,BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT, 0)){
		return 1;
	}
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[4], EXIT_BUTTON_X + 55, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[23], EXIT_BUTTON_X + 80, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[8], EXIT_BUTTON_X + 105, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[19], EXIT_BUTTON_X + 130, BUTTON_MENU_Y + 25);


	if(vg_draw_rectangle(ADD_KEYBOARD_BUTTON_X,BUTTON_MENU_Y,BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT, 0)){
		return 1;
	}
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[0], ADD_KEYBOARD_BUTTON_X + 15, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[3], ADD_KEYBOARD_BUTTON_X + 40, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[3], ADD_KEYBOARD_BUTTON_X + 65, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[62], ADD_KEYBOARD_BUTTON_X + 85, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[10], ADD_KEYBOARD_BUTTON_X + 110, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[1], ADD_KEYBOARD_BUTTON_X + 135, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[3], ADD_KEYBOARD_BUTTON_X + 160, BUTTON_MENU_Y + 25);

	if(vg_draw_rectangle(CHANGE_BACK_BUTTON_X,BUTTON_MENU_Y,BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT, 0)){
		return 1;
	}
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[1], CHANGE_BACK_BUTTON_X + 7, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[6], CHANGE_BACK_BUTTON_X + 32, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[62], CHANGE_BACK_BUTTON_X + 52, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[2], CHANGE_BACK_BUTTON_X + 72, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[14], CHANGE_BACK_BUTTON_X + 97, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[11], CHANGE_BACK_BUTTON_X + 122, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[14], CHANGE_BACK_BUTTON_X + 147, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[17], CHANGE_BACK_BUTTON_X + 172, BUTTON_MENU_Y + 25);

	if(vg_draw_rectangle(CHANGE_LETTER_BUTTON_X,BUTTON_MENU_Y,BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT, 0)){
		return 1;
	}
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[2], CHANGE_LETTER_BUTTON_X + 40, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[14], CHANGE_LETTER_BUTTON_X + 65, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[11], CHANGE_LETTER_BUTTON_X + 90, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[14], CHANGE_LETTER_BUTTON_X + 115, BUTTON_MENU_Y + 25);
	drawPixMap(LETTER_HEIGHT, LETTER_WIDTH, mapXpms[17], CHANGE_LETTER_BUTTON_X + 140, BUTTON_MENU_Y + 25);
	
	return 0;
}


































