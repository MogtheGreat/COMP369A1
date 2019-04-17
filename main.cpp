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
	check += install_keyboard ();		// Install the keyboard interrupt
	
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
	rest (100);
}

void printInfo (FONT * regFont) {

	// Loads the instructions of the game in the desired Font
	if (!regFont) {
		textprintf_ex (screen, font, SCREEN_W - 150, SCREEN_H - 20, 15, -1, "ESC: Exit...");
		textprintf_ex (screen, font, SCREEN_W - 200, 240, 15, -1, "M: Menu");
	}
	else
	{
		textprintf_ex (screen, regFont, SCREEN_W - 150, SCREEN_H - 40, 15, -1, "ESC: Exit...");
		textprintf_ex (screen, regFont, SCREEN_W - 200, 240, 15, -1, "M: Menu");
	}
}

void playStart (int &play, FONT * regFont) {
	if (!regFont) {
		textprintf_ex (screen, font, 0, 50, 15, -1, "Welcome to POCKET TRIVIA!");
		textprintf_ex (screen, font, 0, 100, 15, -1, "In this trivia game, players are given multple choice questions");
		textprintf_ex (screen, font, 0, 120, 15, -1, "from the textbook \"Game Programming All in One\".");
		textprintf_ex (screen, font, 0, 150, 15, -1, "Choices can be selected by pressing 1, 2, 3, or 4 on the keyboard.");
		
		textprintf_ex (screen, font, 0, 180, 15, -1, "Player's score is kept at the bottom of the screen as a ratio.");
		textprintf_ex (screen, font, 0, 210, 15, -1, "At the end of the game, players final score is displayed.");
		textprintf_ex (screen, font, 0, 240, 15, -1, "At any point a player can change the set of questions being asked");
		textprintf_ex (screen, font, 0, 260, 15, -1, "by pressing M");
		
		textprintf_ex (screen, font, 200, SCREEN_H-80, 15, -1, "Press Enter to continue.");
		textprintf_ex (screen, font, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
	else {
		textprintf_ex (screen, regFont, 0, 50, 15, -1, "Welcome to POCKET TRIVIA!");
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "In this trivia game, players are given multple choice questions");
		textprintf_ex (screen, regFont, 0, 120, 15, -1, "from the textbook \"Game Programming All in One\".");
		textprintf_ex (screen, regFont, 0, 150, 15, -1, "Choices can be selected by pressing 1, 2, 3, or 4 on the keyboard.");
		
		textprintf_ex (screen, regFont, 0, 180, 15, -1, "Player's score is kept at the bottom of the screen as a ratio.");
		textprintf_ex (screen, regFont, 0, 210, 15, -1, "At the end of the game, players final score is displayed.");
		textprintf_ex (screen, regFont, 0, 240, 15, -1, "At any point a player can change the set of questions being asked");
		textprintf_ex (screen, regFont, 0, 260, 15, -1, "by pressing M");
		
		textprintf_ex (screen, regFont, 200, SCREEN_H-80, 15, -1, "Press Enter to continue.");
		textprintf_ex (screen, regFont, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
}

void menu (FONT * regFont) {
	if (!regFont) {
		textprintf_ex (screen, font, 0, 100, 15, -1, "Press A for all chapters from text.");
		textprintf_ex (screen, font, 0, 150, 15, -1, "Press U to choose a unit from text.");
		textprintf_ex (screen, font, 0, 200, 15, -1, "Press C to choose a chapter from text.");
		textprintf_ex (screen, font, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
	else {
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "Press A for all chapters from text.");
		textprintf_ex (screen, regFont, 0, 150, 15, -1, "Press U to choose a unit from text.");
		textprintf_ex (screen, regFont, 0, 200, 15, -1, "Press C to choose a chapter from text.");
		textprintf_ex (screen, regFont, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
}

void menuUnit (FONT * regFont) {
	if (!regFont) {
		textprintf_ex (screen, font, 0, 100, 15, -1, "Press 1,2,3,4,5 or 6 for the corresponding unit.");
	}
	else {
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "Press 1,2,3,4,5 or 6 for the corresponding unit.");
	}
}

void playGame (FONT * regFont, vector <string> availImages) {
	// Choose a new random image
	BITMAP * image = randImage (availImages);
	if (image)
		blit (image, screen, 0,0, (SCREEN_W - image -> w), 40, image -> w, image -> h); //display the image

	// Print options/info about game
	printInfo (regFont);
	rest (100);
	destroy_bitmap (image); //delete bitmap from memory
}

int main (void) {
	vector <string> availImages; 
	vector <string> availBackground;
	vector <string> availFont;
	int play = 0;
	int choice = 0;

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

	// Set up Screen
	PALETTE palette;	// Color palette for fonts.
	FONT * titleFont = load_font (TITLEFONT, palette, NULL);
	FONT * regFont = randFont (availFont, palette);
	BITMAP * backImage = randBack (availBackground);
	printBackground (titleFont, backImage);
	

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {

		if (play == 0) {
			printBackground (titleFont, backImage);
			playStart (play, regFont);
			while (!keypressed());
			readkey();
			
			if (key[KEY_ENTER])
				play = 1;
		}

		else if (play == 1) {
			printBackground (titleFont, backImage);
			menu (regFont);
			while (!keypressed());
			readkey();
			
			if (key[KEY_A])
				play = 2;
			if (key[KEY_U]) {
				play = 2;
				choice = 1;
			}
			if (key[KEY_C]) {
				play = 2;
				choice = 2;
			}
		}

		else if (choice == 1) {
			printBackground (titleFont, backImage);
			menuUnit (regFont);
			while (!keypressed());
			readkey();
		}
		else if (choice == 2) {

		}
		else {
			printBackground (titleFont, backImage);
			playGame (regFont, availImages);
			while (!keypressed());
			readkey();
		}
	}

	destroy_bitmap (backImage); //delete bitmap from memory
	// Release font memory
	destroy_font(titleFont);
	destroy_font (regFont);

	allegro_exit ();	// Frees all Allegro memory
	return 0;
}
END_OF_MAIN()

