#include <allegro.h>
#include "aux.h"
//All grpahics and sound in Game. Allows for easy swapping.
#define TITLEFONT "Fonts/Circuit Mage(24).pcx"
#define REGFONT "Fonts/COMPUTER Robot (14).pcx"
#define BACKGROUND "Background/binarybackground.pcx"
#define IMAGE "Images/image1.pcx"
#define COLORLINE makecol (0, 63, 0)

using namespace std;

int main (void) {
	PALETTE palette;	// Color palette for fonts.
	vector <string> availImages; 
	vector <string> availBackground;
	vector <string> availFont; 

	int check = allegro_init ();		// Initialize Allegro library
	check = install_keyboard ();		// Install the keyboard interrupt

	// Checks to see if library properly initialized.
	if (check != 0) {
		std::cerr << "Allegro library failed to Initialize!" << std::endl;
		return 1;
	}

	// Get list of all avail images, fonts and background.
	availImages = getFileNames ("Images");
	availBackground = getFileNames ("Fonts");
	availFont = getFileNames ("Background");

	// Creates the window and sets the graphics mode
	int ret = set_gfx_mode (GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0) {
		allegro_message ("%s\n", allegro_error);
		return 1;
	}

	BITMAP * backImage = load_bitmap (BACKGROUND, NULL); //load the image file
	if (backImage)
		blit (backImage, screen, 0,0, 0, 0, SCREEN_W, SCREEN_H); //display the image

	BITMAP * image = load_bitmap (IMAGE, NULL); // Load the image file
	if (image)
		blit (image, screen, 0,0, (SCREEN_W - image -> w), 40, image -> w, image -> h); //display the image

	// Loads the Title of the game in the desired Font
	FONT * titleFont = load_font (TITLEFONT, palette, NULL);
	if (!titleFont)
		textprintf_ex (screen, font, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in regular font
	else 
		textprintf_ex (screen, titleFont, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in custom font

	// Loads the instructions of the game in the desired Font
	FONT * regFont = load_font (REGFONT, palette, NULL);
	if (!regFont) {
		textprintf_ex (screen, font, SCREEN_W - 200, SCREEN_H - 20, 15, -1, "Press ESC to exit...");
	}
	else
	{
		textprintf_ex (screen, regFont, SCREEN_W - 170, SCREEN_H - 20, 15, -1, "Press ESC to exit...");
	}

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

