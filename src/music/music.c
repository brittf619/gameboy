#include <gb/gb.h>
#include "music.h"
#include "gbt_player.h"

/* here for sound that is going to play */
extern const unsigned char * song_Data[];

/* this will move to another bank */

void play_music(void){


	disable_interrupts();

	gbt_play(song_Data,  2, 7);

	gbt_loop(1);

	set_interrupts(VBL_IFLAG);
	enable_interrupts();

	while(1){
		wait_vbl_done();
		gbt_update();
	}

	
	

}