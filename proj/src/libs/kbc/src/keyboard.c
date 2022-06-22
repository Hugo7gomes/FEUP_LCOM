#include "libs/kbc/include/keyboard.h"

uint8_t scanCode = 0;
int KBC_id = KBD_IRQ;

uint16_t posX = 0;//Starting position X
uint16_t posY = 110;//Starting position Y

struct letter lettersArray[(HRES/LETTER_WIDTH)*(VRES/LETTER_HEIGHT)];
extern char* mapXpms[63];

bool isCaps = false;

//interrupt handler	
int (keyboard_ih)() {
	uint8_t st_reg;

	if(util_sys_inb(KBC_ST_REG ,&st_reg) != 0){
		printf("ERROR READING STATUS_REG");
		return 1;
	}

	if((st_reg & ST_PARITY) != 0){
		printf("PARITY ERROR\n");
		return 1;
	}

	if((st_reg & ST_TOUT) != 0){
		printf("TIMEOUT ERROR\n");
		return 1;
	}

	if((st_reg & ST_AUX) != 0){
		printf("MOUSE ERROR\n");
		return 1;
	}


	if((st_reg & ST_OBF) == 0){
		printf("ERROR OUTPUT BUFFER EMPTY \n");
		return 1;
	}


	if(util_sys_inb(KBC_OUT_BUF, &scanCode) != 0){
		printf("ERROR READING OUTPUT BUFFER\n");
		return 1;
	}
	return 0;
}

int (keyboard_subscribe_int)(uint8_t *bit_no){
	*bit_no = BIT(KBC_id);
	if(sys_irqsetpolicy(KBD_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE,&KBC_id) != 0){
		printf("CANNOT SUBSCRIBE INT\n");
		return 1;
	}
	return 0;
}

int (keyboard_unsubscribe_int()){
	if(sys_irqrmpolicy(&KBC_id) == 1){
		printf("CANNOT UNSUBSCRIBE INT\n");
		return 1;
	}

	return 0;
}

void interruptsKB(){
	bool make;
	uint8_t size;
	uint8_t sCodeBytes[2];

	if(keyboard_ih()){
		return;
	}

	if(scanCode == TWO_BYTE_SCANCODES){
    size = 2;
  }else{
    size = 1;
  }

  if(scanCode & MAKE_CODE){
    make = false;
  }else{
    make = true;
  }

  sCodeBytes[0] = scanCode;
  sCodeBytes[1] = scanCode;

  if(!make){
  	uint16_t code16;
  	code16 = sCodeBytes[1];
  	//code16 = code16 << 8;
  	//code16 = code16 & sCodeBytes[0];

  	addLetterArray(code16);
  }

}



void addLetterArray(uint16_t breakCode){

	struct letter l;

	bool drawLetter = false;
	
	
	l.x = posX;
	l.y = posY;

	switch(breakCode){
		case 0x9E://A
			if(isCaps){
				l.p = mapXpms[0];
			}else{
				l.p = mapXpms[26];	
			}
			drawLetter = true;
			break;

		case 0xB0://B
			if(isCaps){
				l.p = mapXpms[1];
			}else{
				l.p = mapXpms[27];	
			}
			drawLetter = true;
			break;

		case 0xAE://C
			if(isCaps){
				l.p = mapXpms[2];
			}else{
				l.p = mapXpms[28];	
			}
			drawLetter = true;
			break;

		case 0xA0://D
			if(isCaps){
				l.p = mapXpms[3];
			}else{
				l.p = mapXpms[29];	
			}
			drawLetter = true;
			break;

		case 0x92://E
			if(isCaps){
				l.p = mapXpms[4];
			}else{
				l.p = mapXpms[30];	
			}
			drawLetter = true;
			break;

		case 0xA1://F
			if(isCaps){
				l.p = mapXpms[5];
			}else{
				l.p = mapXpms[31];	
			}
			drawLetter = true;
			break;

		case 0xA2://G
			if(isCaps){
				l.p = mapXpms[6];
			}else{
				l.p = mapXpms[32];	
			}
			drawLetter = true;
			break;

		case 0xA3://H
			if(isCaps){
				l.p = mapXpms[7];
			}else{
				l.p = mapXpms[33];	
			}
			drawLetter = true;
			break;

		case 0x97://I
			if(isCaps){
				l.p = mapXpms[8];
			}else{
				l.p = mapXpms[34];	
			}
			drawLetter = true;
			break;

		case 0xA4://J
			if(isCaps){
				l.p = mapXpms[9];
			}else{
				l.p = mapXpms[35];	
			}
			drawLetter = true;
			break;

		case 0xA5://K
			if(isCaps){
				l.p = mapXpms[10];
			}else{
				l.p = mapXpms[36];	
			}
			drawLetter = true;
			break;

		case 0xA6://L
			if(isCaps){
				l.p = mapXpms[11];
			}else{
				l.p = mapXpms[37];	
			}
			drawLetter = true;
			break;

		case 0xB2://M
			if(isCaps){
				l.p = mapXpms[12];
			}else{
				l.p = mapXpms[38];	
			}
			drawLetter = true;
			break;

		case 0xB1://N
			if(isCaps){
				l.p = mapXpms[13];
			}else{
				l.p = mapXpms[39];	
			}
			drawLetter = true;
			break;

		case 0x98://O
			if(isCaps){
				l.p = mapXpms[14];
			}else{
				l.p = mapXpms[40];	
			}
			drawLetter = true;
			break;

		case 0x99://P
			if(isCaps){
				l.p = mapXpms[15];
			}else{
				l.p = mapXpms[41];	
			}
			drawLetter = true;
			break;

		case 0x90://Q
			if(isCaps){
				l.p = mapXpms[16];
			}else{
				l.p = mapXpms[42];	
			}
			drawLetter = true;
			break;

		case 0x93://R
			if(isCaps){
				l.p = mapXpms[17];
			}else{
				l.p = mapXpms[43];	
			}
			drawLetter = true;
			break;

		case 0x9F://S
			if(isCaps){
				l.p = mapXpms[18];
			}else{
				l.p = mapXpms[44];	
			}
			drawLetter = true;
			break;

		case 0x94://T
			if(isCaps){
				l.p = mapXpms[19];
			}else{
				l.p = mapXpms[45];	
			}
			drawLetter = true;
			break;

		case 0x96://U
			if(isCaps){
				l.p = mapXpms[20];
			}else{
				l.p = mapXpms[46];	
			}
			drawLetter = true;
			break;

		case 0XAF://V
			if(isCaps){
				l.p = mapXpms[21];
			}else{
				l.p = mapXpms[47];	
			}
			drawLetter = true;
			break;

		case 0x91://W
			if(isCaps){
				l.p = mapXpms[22];
			}else{
				l.p = mapXpms[48];	
			}
			drawLetter = true;
			break;

		case 0xAD://X
			if(isCaps){
				l.p = mapXpms[23];
			}else{
				l.p = mapXpms[49];	
			}
			drawLetter = true;
			break;

		case 0x95://Y
			if(isCaps){
				l.p = mapXpms[24];
			}else{
				l.p = mapXpms[50];	
			}
			drawLetter = true;
			break;

		case 0xAC://Z
			if(isCaps){
				l.p = mapXpms[25];
			}else{
				l.p = mapXpms[51];	
			}
			drawLetter = true;
			break;

		case 0x82://1
			l.p = mapXpms[52];
			drawLetter = true;
			break;	

		case 0x83://2
			l.p = mapXpms[53];
			drawLetter = true;
			break;	

		case 0x84://3
			l.p = mapXpms[54];
			drawLetter = true;
			break;	

		case 0x85://4
			l.p = mapXpms[55];
			drawLetter = true;
			break;	

		case 0x86://5
			l.p = mapXpms[56];
			drawLetter = true;
			break;	

		case 0x87://6
			l.p = mapXpms[57];
			drawLetter = true;
			break;	

		case 0x88://7
			l.p = mapXpms[58];
			drawLetter = true;
			break;	

		case 0x89://8
			l.p = mapXpms[59];
			drawLetter = true;
			break;	

		case 0x8A://9
			l.p = mapXpms[60];
			drawLetter = true;
			break;	

		case 0x8B://0
			l.p = mapXpms[61];
			drawLetter = true;
			break;	

		case 0xB9://espaço
			l.p = mapXpms[62];
			drawLetter = true;
			break;	

		case 0xBA://capsLock
			if(isCaps){
				isCaps = false;	
			}else{
				isCaps = true;
			}
			break;
		case 0x9C://Enter
			posX = 0;
			posY += LETTER_HEIGHT; 
			break;
		case 0x8E://BACKSPACE
			if(posX == 0){
				posY-=	LETTER_HEIGHT;
				posX = 1040;
			}
			posX -= LETTER_WIDTH;
			l.p = mapXpms[62];
			lettersArray[((HRES/LETTER_WIDTH) * (posY - 110)/LETTER_HEIGHT + posX/LETTER_WIDTH)] = l;
			break;			

		}
	
	if(drawLetter){
		lettersArray[((HRES/LETTER_WIDTH) * (posY - 110)/LETTER_HEIGHT + posX/LETTER_WIDTH)] = l;

		memset(l.p,0,8);
		posX += LETTER_WIDTH;
		if(posX >= (HRES - LETTER_WIDTH)){
			posX = 0;
			posY += LETTER_HEIGHT;
		}

	}

	if(posY > (VRES- LETTER_HEIGHT)){
		posY = VRES- LETTER_HEIGHT;
		posX = 1000;
	}

}


