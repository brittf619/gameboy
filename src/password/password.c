/* this code was generated and copied from youtube */
#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"

#define PASSWORD_LENGTH (4)

unsigned char Smiler[] = {
	0x7e, 0x7e, 0xff, 0x81, 0xff, 0xA5, 0xFF, 0x81,
	0xFF, 0x81, 0xff, 0xBD, 0xFF, 0x81, 0x7e, 0x7e,
	0x7e, 0x7e, 0xff, 0x81, 0xff, 0xa5, 0xff, 0x81,
	0xff, 0xa5, 0xff, 0x99, 0xff, 0x81, 0x7e, 0x7e
};

void func(){
	UINT8 sprite_index = 0;
	set_sprite_data(0, 2, Smiler);
	set_sprite_tile(0, 0);
	move_sprite(0, 88, 88);
	SHOW_SPRITES;
}


int validate_password(int * correct_password, int * input_password, int length, int * are_same){
	int i = 0;
	int result;
	int local_are_same = true;

	if ((NULL == correct_password) ||
		(NULL == are_same)
		(NULL == input_password)){
		goto cleanup;
	}

	for (i =0; i < length; i++){
			if (correct_password[i] != input_password[i]){
				local_are_same = false;
			}
	}

	if (local_are_same){
		printf("right password\n");
	} else {
		printf("wrong password!\n");
	}

	(*are_same) = local_are_same;
	result = true;
	cleanup:
	return result;
}


int wait_for_password(){
	int are_same = true;
	int i = 0;
	int input = 0;
	/* todo - make these globals? */
	int password_input[PASSWORD_LENGTH] = {0};
	int right_password[PASSWORD_LENGTH] = {J_LEFT, J_LEFT, J_UP, J_DOWN};
	
	/* now collect password input */
	printf("what is the magical password?\n");
	while(true){
		/* other values that can be used - J_SELECT, J_B, J_A, J_START */
		/* password will be - right, right, up, down */
		for (i = 0; i < 4; i++){
			/* poll input */
			while(input == 0){	
				input = joypad();	
			}

			password_input[i] = input;
			//printf("password set  to i - %d value - %d\n", i, password_input[i]);
			//printf("right value - %d\n", right_password[i]);
			
			input = 0;
			
			delay(100);
		}

		validate_password(right_password, password_input, PASSWORD_LENGTH);
	}
}