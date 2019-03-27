
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xbram.h"
#include "xil_io.h"


void render(u8 x, u8 y, u8 r, u8 g, u8 b);
void clearMemory();



int main()
{
    init_platform();

    clearMemory();

	for(u8 col = 0; col < 8; col++){
		for(u8 row = 0; row < 8; row++){
			render(col, row, row*10,col*10,0);
		}
	}

    cleanup_platform();
    return 0;
}




// Function to reset memory
void clearMemory(){
	for(u8 col = 0; col < 8; col++){
		for(u8 row = 0; row < 8; row++){
			render(col, row, 0, 0, 0);
		}
	}
}


// Function to render a pixel to the display
void render(u8 x, u8 y, u8 r, u8 g, u8 b){
	u32 Addr = XPAR_BRAM_0_BASEADDR + x*4 + y*32;
	u32 value = 0x00000000;
	value +=(r << 16);
	value +=(g << 8);
	value +=(b);
	Xil_Out32(Addr, value);
}
