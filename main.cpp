#include <iostream>
#include <allegro.h>

int main (void) {
	
	int check = allegro_init ();		// Initialize Allegro library
	check = install_keyboard ();		// Install the keyboard interrupt

	// Checks to see if library properly initialized.
	if (check != 0) {
		std::cerr << "Allegro library failed to Initialize!" << std::endl;
		return 1;
	}

	// Creates the window and sets the graphics mode
	int ret = set_gfx_mode (GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0) {
		allegro_message ("%s\n", allegro_error);
		return 1;
	}

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {

	}

	allegro_exit ();	// Frees all Allegro memory
	return 0;
}
END_OF_MAIN()