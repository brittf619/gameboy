/* this code was generated and copied from youtube */
#include <gb/gb.h>
#include <stdio.h>
#include "smiley_mover.h"


unsigned char Smiler[] = {
	0x7e, 0x7e, 0xff, 0x81, 0xff, 0xA5, 0xFF, 0x81,
	0xFF, 0x81, 0xff, 0xBD, 0xFF, 0x81, 0x7e, 0x7e,
	0x7e, 0x7e, 0xff, 0x81, 0xff, 0xa5, 0xff, 0x81,
	0xff, 0xa5, 0xff, 0x99, 0xff, 0x81, 0x7e, 0x7e
};


int smiley_mover(){
	UINT8 sprite_index = 0;
	set_sprite_data(0, 2, Smiler);
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 88);
	SHOW_SPRITES;
	while(true){
		/* other values that can be used - J_SELECT, J_B, J_A, J_START */
		switch(joypad()){
			case J_LEFT:
				scroll_sprite(0, -10, 0);
				break;
			case J_RIGHT:
				scroll_sprite(0, 10, 0);
				break;
			case J_UP:
				scroll_sprite(0, 0, -10);
				break;
			case J_DOWN:
				scroll_sprite(0, 0, 10);
				break;
		}
		delay(100);
	}
}