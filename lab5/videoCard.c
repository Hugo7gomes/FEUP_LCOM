#include "videoCard.h"
static vbe_mode_info_t modeInfo;
static void *video_mem;
static mmap_t mem_map;



uint8_t get_RedFieldPosition(void){
	return modeInfo.RedFieldPosition;
}


uint8_t get_GreenFieldPosition(void){
	return modeInfo.GreenFieldPosition;
}


uint8_t get_BlueFieldPosition(void){
	return modeInfo.BlueFieldPosition;
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

uint16_t get_RedMaskSize(void){
	return modeInfo.RedMaskSize;
}

uint16_t get_GreenMaskSize(void){
	return modeInfo.GreenMaskSize;
}

uint16_t get_BlueMaskSize(void){
	return modeInfo.BlueMaskSize;
}

int free_map_memory(void){
	lm_free(&mem_map);
	return 0;
}

void drawPixMap(xpm_image_t image, uint8_t *pixMap, uint16_t x, uint16_t y){
	for(int row = 0; row < image.height; row++){ //y
    	for(int col= 0; col < image.width; col++){ //x
      		drawPixel(x+col, y+row, *(pixMap));
      		pixMap++;
    	}
  	}
}



void *(vg_init)(uint16_t mode){

	struct minix_mem_range mr;
	unsigned int vram_base;
	unsigned int vram_size;
	int r;

	if(vbe_get_mode_info(mode, &modeInfo) != 0){
		printf("CANNOT READ VBE MODE INFO\n");
		return NULL;
	}


	vram_base = modeInfo.PhysBasePtr;
	vram_size = modeInfo.XResolution * get_vres() * (get_bitsPerPixel()/8);

	if(get_bitsPerPixel() % 8 != 0){
		vram_size += 1;;
	}

	lm_alloc(vram_size, &mem_map);


	mr.mr_base = (phys_bytes) vram_base;	
	mr.mr_limit = mr.mr_base + vram_size;  

	if( OK != (r = sys_privctl(SELF, SYS_PRIV_ADD_MEM, &mr))){
   		panic("sys_privctl (ADD_MEM) failed: %d\n", r);
	}

	video_mem = vm_map_phys(SELF, (void *)mr.mr_base, vram_size);

	if(video_mem == MAP_FAILED){
   		panic("couldn't map video memory");
	}

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
	uint8_t number_bytes;
	if(x > get_hres() || y > get_vres()|| x< 0 || y< 0){
		return 1;
	}

	switch(get_bitsPerPixel()){
		case 8:
			number_bytes = 1;
			if(get_bitsPerPixel() % 8 != 0){
				number_bytes = 2;
			}

			pos = get_hres() * y * number_bytes + x* number_bytes;
			memcpy((void*)((unsigned int)video_mem + pos), &color, number_bytes);
			break;

		case 24:
			number_bytes = 3;
			if(get_bitsPerPixel() % 8 != 0){
				number_bytes = 4;
			}
			pos = get_hres() * y * number_bytes + x* number_bytes;
			memcpy((void*)((unsigned int)video_mem + pos), &color, number_bytes);
			break;
	}
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


int clearScreen(){
	vg_draw_rectangle(0,0, get_hres(), get_vres(),0x00); //paints the entire screen black
	return 0;
}
































