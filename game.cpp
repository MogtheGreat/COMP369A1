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

void menuChapter (FONT * regFont) {
	if (!regFont) {
		textprintf_ex (screen, font, 0, 100, 15, -1, "A: Chapter 1");
		textprintf_ex (screen, font, 0, 120, 15, -1, "B: Chapter 2");
		textprintf_ex (screen, font, 0, 140, 15, -1, "C: Chapter 3");
		textprintf_ex (screen, font, 0, 160, 15, -1, "D: Chapter 4");
		textprintf_ex (screen, font, 0, 180, 15, -1, "E: Chapter 5");
		textprintf_ex (screen, font, 0, 200, 15, -1, "F: Chapter 6");

		textprintf_ex (screen, font, 0, 220, 15, -1, "G: Chapter 7");
		textprintf_ex (screen, font, 0, 240, 15, -1, "H: Chapter 8");
		textprintf_ex (screen, font, 0, 260, 15, -1, "I: Chapter 9");
		textprintf_ex (screen, font, 0, 280, 15, -1, "J: Chapter 10");
		textprintf_ex (screen, font, 0, 300, 15, -1, "K: Chapter 11");
		textprintf_ex (screen, font, 0, 320, 15, -1, "L: Chapter 12");

		textprintf_ex (screen, font, 0, 340, 15, -1, "M: Chapter 13");
		textprintf_ex (screen, font, 0, 360, 15, -1, "N: Chapter 14");
		textprintf_ex (screen, font, 0, 380, 15, -1, "O: Chapter 15");
		textprintf_ex (screen, font, 0, 400, 15, -1, "P: Chapter 16");
		textprintf_ex (screen, font, 140, 100, 15, -1, "Q: Chapter 17");

		textprintf_ex (screen, font, 140, 120, 15, -1, "R: Chapter 18");
		textprintf_ex (screen, font, 140, 140, 15, -1, "S: Chapter 19");
		textprintf_ex (screen, font, 140, 160, 15, -1, "T: Chapter 20");
		textprintf_ex (screen, font, 140, 180, 15, -1, "U: Chapter 21");
		textprintf_ex (screen, font, 140, 200, 15, -1, "V: Chapter 22");
	}
	else {
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "A: Chapter 1");
		textprintf_ex (screen, regFont, 0, 120, 15, -1, "B: Chapter 2");
		textprintf_ex (screen, regFont, 0, 140, 15, -1, "C: Chapter 3");
		textprintf_ex (screen, regFont, 0, 160, 15, -1, "D: Chapter 4");
		textprintf_ex (screen, regFont, 0, 180, 15, -1, "E: Chapter 5");
		textprintf_ex (screen, regFont, 0, 200, 15, -1, "F: Chapter 6");

		textprintf_ex (screen, regFont, 0, 220, 15, -1, "G: Chapter 7");
		textprintf_ex (screen, regFont, 0, 240, 15, -1, "H: Chapter 8");
		textprintf_ex (screen, regFont, 0, 260, 15, -1, "I: Chapter 9");
		textprintf_ex (screen, regFont, 0, 280, 15, -1, "J: Chapter 10");
		textprintf_ex (screen, regFont, 0, 300, 15, -1, "K: Chapter 11");
		textprintf_ex (screen, regFont, 0, 320, 15, -1, "L: Chapter 12");

		textprintf_ex (screen, regFont, 0, 340, 15, -1, "M: Chapter 13");
		textprintf_ex (screen, regFont, 0, 360, 15, -1, "N: Chapter 14");
		textprintf_ex (screen, regFont, 0, 380, 15, -1, "O: Chapter 15");
		textprintf_ex (screen, regFont, 0, 400, 15, -1, "P: Chapter 16");
		textprintf_ex (screen, regFont, 140, 100, 15, -1, "Q: Chapter 17");

		textprintf_ex (screen, regFont, 140, 120, 15, -1, "R: Chapter 18");
		textprintf_ex (screen, regFont, 140, 140, 15, -1, "S: Chapter 19");
		textprintf_ex (screen, regFont, 140, 160, 15, -1, "T: Chapter 20");
		textprintf_ex (screen, regFont, 140, 180, 15, -1, "U: Chapter 21");
		textprintf_ex (screen, regFont, 140, 200, 15, -1, "V: Chapter 22");
	}
}

/*
	NOTE: There got to be a better way of doing this function.
		  Because right now this function burns my eyes!
*/
void menuChapterInput (int & chapter) {
	// A to V keys chooses which Chapter to take questions from
	if (key[KEY_A]) {
		chapter = 0;
	}
	if (key[KEY_B]) {
		chapter = 1;
	}
	if (key[KEY_C]) {
		chapter = 2;
	}
	if (key[KEY_D]) {
		chapter = 3;
	}
	if (key[KEY_E]) {
		chapter = 4;
	}
	if (key[KEY_F]) {
		chapter = 5;
	}
	if (key[KEY_G]) {
		chapter = 6;
	}
	if (key[KEY_H]) {
		chapter = 7;
	}
	if (key[KEY_I]) {
		chapter = 8;
	}
	if (key[KEY_J]) {
		chapter = 9;
	}
	if (key[KEY_K]) {
		chapter = 10;
	}
	if (key[KEY_L]) {
		chapter = 11;
	}
	if (key[KEY_M]) {
		chapter = 12;
	}
	if (key[KEY_N]) {
		chapter = 13;
	}
	if (key[KEY_O]) {
		chapter = 14;
	}
	if (key[KEY_P]) {
		chapter = 15;
	}
	if (key[KEY_Q]) {
		chapter = 16;
	}
	if (key[KEY_R]) {
		chapter = 17;
	}
	if (key[KEY_S]) {
		chapter = 18;
	}
	if (key[KEY_T]) {
		chapter = 19;
	}
	if (key[KEY_U]) {
		chapter = 20;
	}
	if (key[KEY_V]) {
		chapter = 21;
	}
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