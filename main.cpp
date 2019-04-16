#include "main.h"
//All grpahics and sound in Game. Allows for easy swapping.
#define TITLEFONT "TitleFont/Circuit Mage(24).pcx"
#define REGFONT "Fonts/COMPUTER Robot (14).pcx"
#define BACKGROUND "Background/binarybackground.pcx"
#define IMAGE "Images/image1.pcx"
#define COLORLINE makecol (0, 63, 0)

using namespace std;

int init_Lib () {
	int check = allegro_init ();		// Initialize Allegro library
	check = install_keyboard ();		// Install the keyboard interrupt
	
	// Checks to see if library properly initialized.
	if (check != 0) {
		std::cerr << "Allegro library failed to Initialize!" << std::endl;
		return 1;
	}
	else
		return 0;
}

BITMAP * randBack (vector <string> list) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Background/" + list[randomIndex]; // get the path to the file
	BITMAP * backImage = load_bitmap (filePath.c_str(), NULL); // load the image to the program
	return backImage;
}

BITMAP * randImage (vector <string> list) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Images/" + list[randomIndex]; // get the path to the file
	BITMAP * image = load_bitmap (filePath.c_str(), NULL); // load the image to the program
	return image;
}

FONT * randFont (vector <string> list, PALETTE palette) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Fonts/" + list[randomIndex]; // get the path to the file
	FONT * font = load_font (filePath.c_str(), palette, NULL); // loads the font to the program
	return font;
}

void printBackground (FONT * titleFont, BITMAP * backImage) {
	// generate background
	if (backImage)
		blit (backImage, screen, 0,0, 0, 0, SCREEN_W, SCREEN_H); //display the image

	if (!titleFont)
		textprintf_ex (screen, font, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in regular font
	else 
		textprintf_ex (screen, titleFont, 100, 0, 15, -1, "Pocket Trivia"); // Print title of the game in custom font

	// print borders
	hline (screen, 0,40,SCREEN_W, COLORLINE);
	hline (screen, 0,SCREEN_H-40,SCREEN_W, COLORLINE);
}

void printInfo (FONT * regFont) {

	// Loads the instructions of the game in the desired Font
	if (!regFont) {
		textprintf_ex (screen, font, SCREEN_W - 200, SCREEN_H - 20, 15, -1, "Press ESC to exit...");
	}
	else
	{
		textprintf_ex (screen, regFont, SCREEN_W - 200, SCREEN_H - 40, 15, -1, "Press ESC to exit...");
	}
}

int main (void) {
	vector <string> availImages; 
	vector <string> availBackground;
	vector <string> availFont; 

	// Initializes the Allegro library and sets up the interrupts
	if (init_Lib () == 1)
		return 1;

	srand (time (NULL)); // seed random generator.

	// Get list of all avail images, fonts and background.
	availImages = getFileNames ("Images");
	availBackground = getFileNames ("Background");
	availFont = getFileNames ("Fonts");

	// Creates the window and sets the graphics mode
	int ret = set_gfx_mode (GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0) {
		allegro_message ("%s\n", allegro_error);
		return 1;
	}

	PALETTE palette;	// Color palette for fonts.
	FONT * titleFont = load_font (TITLEFONT, palette, NULL);
	FONT * regFont = randFont (availFont, palette);
	BITMAP * backImage = randBack (availBackground);
	printBackground (titleFont, backImage);
	

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {
		
		// Choose a new random image
		BITMAP * image = randImage (availImages);
		if (image)
			blit (image, screen, 0,0, (SCREEN_W - image -> w), 40, image -> w, image -> h); //display the image

		// Print options/info about game
		printInfo (regFont);

		rest (100);
		destroy_bitmap (image); //delete bitmap from memory
	}

	destroy_bitmap (backImage); //delete bitmap from memory
	// Release font memory
	destroy_font(titleFont);
	destroy_font (regFont);

	allegro_exit ();	// Frees all Allegro memory
	return 0;
}
END_OF_MAIN()

