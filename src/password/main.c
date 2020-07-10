#include <gb/gb.h>
#include "password.h"
#include "sprites_noise.h"


int main()
{
	/* sprites function for backgroung noise */
	sprites_noise();

	wait_for_password();
	return 0;
}