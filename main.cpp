#include <iostream>
#include <allegro.h>
//All grpahics and sound in Game. Allows for easy swapping.
#define TITLEFONT "Images/Circuit Mage(24).pcx"
#define BACKGROUND "Images/binarybackground.pcx"
#define COLORLINE makecol (0, 63, 0)

int main (void) {
	PALETTE palette;	// Color palette for fonts.

	int check = allegro_init ();		// Initialize Allegro library
	check = install_keyboard ();		// Install the keyboard interrupt

	// Checks to see if library properly initialized.
	if (check != 0) {
		std::cerr << "Allegro library failed to Initialize!" << std::endl;
		return 1;
	}

	// Creates the window and sets the graphics mode
	int ret = set_gfx_mode (GFX_AUTODETECT_WINDOWED, 740, 580, 0, 0);
	if (ret != 0) {
		allegro_message ("%s\n", allegro_error);
		return 1;
	}

	BITMAP * backImage = load_bitmap (BACKGROUND, NULL); //load the image file
	if (backImage)
		blit (backImage, screen, 0,0, 0, 0, SCREEN_W, SCREEN_H); //display the image

	// Loads the Title of the game in the desired Font
	FONT * titleFont = load_font (TITLEFONT, palette, NULL);
	if (!titleFont)
		textprintf_ex (screen, font, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in regular font
	else 
		textprintf_ex (screen, titleFont, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in custom font
	hline (screen, 0,40,SCREEN_W, COLORLINE);
	hline (screen, 0,SCREEN_H-40,SCREEN_W, COLORLINE);

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {

	}

	destroy_bitmap (backImage); //done drawing--delete bitmap from memory
	destroy_font(titleFont);	// Release font memory
	allegro_exit ();	// Frees all Allegro memory
	return 0;
}
END_OF_MAIN()