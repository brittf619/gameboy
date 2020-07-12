/* this code was generated and copied from youtube */
#include <gb/gb.h>
#include <stdio.h>
#include "music.h"
#include "password.h"

#define PASSWORD_LENGTH (4)


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
			
			input = 0;
			
			delay(100);
		}

		if(!validate_password(right_password, password_input, PASSWORD_LENGTH, &are_same)){
			goto cleanup;
		}

		if(are_same){
			/* play music */
			//play_music();
		}
	}
	cleanup:
	return 0;
}