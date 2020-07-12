#include <gb/gb.h>
#include "password.h"
#include "music.h"
#include "sprites_noise.h"


void init_sound(void){
	NR52_REG = 0x80; // turns sound on 
	NR50_REG = 0x77; // turns volume to max level
	NR51_REG = 0xFF; // select which channel to use
}


int main()
{
	int i =0;

	/* Initialize registers that are connected to sound */
	//init_sound();

	/* sprites function for backgroung noise */
	sprites_noise();
	//play_music();
	//wait_for_password();
	return 0;
}