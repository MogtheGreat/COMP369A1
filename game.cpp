#include "game.h"

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
		textprintf_ex (screen, font, 0, 120, 15, -1, "1: Unit 1");
		textprintf_ex (screen, font, 0, 140, 15, -1, "2: Unit 2");
		textprintf_ex (screen, font, 0, 160, 15, -1, "3: Unit 3");
		textprintf_ex (screen, font, 0, 180, 15, -1, "4: Unit 4");

	}
	else {
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "Press 1,2,3, or 4 for the corresponding unit.");
		textprintf_ex (screen, regFont, 0, 120, 15, -1, "1: Unit 1");
		textprintf_ex (screen, regFont, 0, 140, 15, -1, "2: Unit 2");
		textprintf_ex (screen, regFont, 0, 160, 15, -1, "3: Unit 3");
		textprintf_ex (screen, regFont, 0, 180, 15, -1, "4: Unit 4");
	}
}

void menuUnitInput (int & unit) {
	// 1,2,3,4 keys chooses which Unit to take questions from
	if (key[KEY_1]) {
		unit = 0;
	}
	if (key[KEY_2]) {
		unit = 1;
	}
	if (key[KEY_3]) {
		unit = 2;
	}
	if (key[KEY_4]) {
		unit = 3;
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