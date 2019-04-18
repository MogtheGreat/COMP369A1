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
	// Print out instructions in regular font
	if (!regFont) {
		textprintf_ex (screen, font, 0, 50, 15, -1, "Welcome to POCKET TRIVIA!");
		textprintf_ex (screen, font, 0, 100, 15, -1, "In this trivia game, players are given multple choice questions");
		textprintf_ex (screen, font, 0, 120, 15, -1, "from the textbook \"Game Programming All in One\".");
		textprintf_ex (screen, font, 0, 150, 15, -1, "Choices can be selected by pressing A, B, C, or D on the keyboard.");
		
		textprintf_ex (screen, font, 0, 180, 15, -1, "Player's score is kept at the bottom of the screen as a ratio.");
		textprintf_ex (screen, font, 0, 210, 15, -1, "At the end of the game, players final score is displayed.");
		textprintf_ex (screen, font, 0, 240, 15, -1, "At any point a player can change the set of questions being asked");
		textprintf_ex (screen, font, 0, 260, 15, -1, "by pressing M");
		
		textprintf_ex (screen, font, 200, SCREEN_H-80, 15, -1, "Press Enter to continue.");
		textprintf_ex (screen, font, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
	// Print out instructions in custom font
	else {
		textprintf_ex (screen, regFont, 0, 50, 15, -1, "Welcome to POCKET TRIVIA!");
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "In this trivia game, players are given multple choice questions");
		textprintf_ex (screen, regFont, 0, 120, 15, -1, "from the textbook \"Game Programming All in One\".");
		textprintf_ex (screen, regFont, 0, 150, 15, -1, "Choices can be selected by pressing A, B, C, or D on the keyboard.");
		
		textprintf_ex (screen, regFont, 0, 180, 15, -1, "Player's score is kept at the bottom of the screen as a ratio.");
		textprintf_ex (screen, regFont, 0, 210, 15, -1, "At the end of the game, players final score is displayed.");
		textprintf_ex (screen, regFont, 0, 240, 15, -1, "At any point a player can change the set of questions being asked");
		textprintf_ex (screen, regFont, 0, 260, 15, -1, "by pressing M");
		
		textprintf_ex (screen, regFont, 200, SCREEN_H-80, 15, -1, "Press Enter to continue.");
		textprintf_ex (screen, regFont, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
}

void menu (FONT * regFont) {
	// Print out main menu in regular font
	if (!regFont) {
		textprintf_ex (screen, font, 0, 100, 15, -1, "Press A for all chapters from text.");
		textprintf_ex (screen, font, 0, 150, 15, -1, "Press U to choose a unit from text.");
		textprintf_ex (screen, font, 0, 200, 15, -1, "Press C to choose a chapter from text.");
		textprintf_ex (screen, font, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
	// Print out main menu in custom font
	else {
		textprintf_ex (screen, regFont, 0, 100, 15, -1, "Press A for all chapters from text.");
		textprintf_ex (screen, regFont, 0, 150, 15, -1, "Press U to choose a unit from text.");
		textprintf_ex (screen, regFont, 0, 200, 15, -1, "Press C to choose a chapter from text.");
		textprintf_ex (screen, regFont, 200, SCREEN_H-60, 15, -1, "Press ESC to EXIT.");
	}
}

void showSelection (FONT * regFont, int unit, int chapter) {
	// Print out player's selection in regular font
	if (!regFont) {
		if ((unit != -1) && (chapter == -1))
			textprintf_ex (screen, font, 300, SCREEN_H-40, 15, -1, "Unit: %d", unit+1);
		else if ((unit == -1) && (chapter != -1))
			textprintf_ex (screen, font, 300, SCREEN_H-40, 15, -1, "Chapter: %d", chapter+1);
		else
			textprintf_ex (screen, font, 300, SCREEN_H-40, 15, -1, "All Chaptes");
	}
	// Print out player's selection in custom font
	else {
		if ((unit != -1) && (chapter == -1))
			textprintf_ex (screen, regFont, 300, SCREEN_H-40, 15, -1, "Unit: %d", unit+1);
		else if ((unit == -1) && (chapter != -1))
			textprintf_ex (screen, regFont, 300, SCREEN_H-40, 15, -1, "Chapter: %d", chapter+1);
		else {
			textprintf_ex (screen, regFont, 300, SCREEN_H-40, 15, -1, "All Chaptes");
		}
	}
}

void menuUnit (FONT * regFont) {
	// Print out menu for unit select in regular font
	if (!regFont) {
		textprintf_ex (screen, font, 0, 100, 15, -1, "Press 1,2,3,4,5 or 6 for the corresponding unit.");
		textprintf_ex (screen, font, 0, 120, 15, -1, "1: Unit 1");
		textprintf_ex (screen, font, 0, 140, 15, -1, "2: Unit 2");
		textprintf_ex (screen, font, 0, 160, 15, -1, "3: Unit 3");
		textprintf_ex (screen, font, 0, 180, 15, -1, "4: Unit 4");

	}
	// Print out menu for unit select in custom font
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
	// Print out chapter select in regular font.
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
	// Print out chapter select in custom font.
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
	if (key[KEY_A]) { // Chapter 1
		chapter = 0;
	}
	if (key[KEY_B]) { // Chapter 2
		chapter = 1;
	}
	if (key[KEY_C]) { // Chapter 3
		chapter = 2;
	}
	if (key[KEY_D]) { // Chapter 4
		chapter = 3;
	}
	if (key[KEY_E]) { // Chapter 5
		chapter = 4;
	}
	if (key[KEY_F]) { // Chapter 6
		chapter = 5;
	}
	if (key[KEY_G]) { // Chapter 7
		chapter = 6;
	}
	if (key[KEY_H]) { // Chapter 8
		chapter = 7;
	}
	if (key[KEY_I]) { // Chapter 9
		chapter = 8;
	}
	if (key[KEY_J]) { // Chapter 10
		chapter = 9;
	}
	if (key[KEY_K]) { // Chapter 11
		chapter = 10;
	}
	if (key[KEY_L]) { // Chapter 12
		chapter = 11;
	}
	if (key[KEY_M]) { // Chapter 13
		chapter = 12;
	}
	if (key[KEY_N]) { // Chapter 14
		chapter = 13;
	}
	if (key[KEY_O]) { // Chapter 15
		chapter = 14;
	}
	if (key[KEY_P]) { // Chapter 16
		chapter = 15;
	}
	if (key[KEY_Q]) { // Chapter 17
		chapter = 16;
	} 
	if (key[KEY_R]) { // Chapter 18
		chapter = 17;
	}
	if (key[KEY_S]) { // Chapter 19
		chapter = 18;
	}
	if (key[KEY_T]) { // Chapter 20
		chapter = 19;
	}
	if (key[KEY_U]) { // Chapter 21
		chapter = 20;
	}
	if (key[KEY_V]) { // Chapter 22
		chapter = 21;
	}
}

void printSplitLine (FONT * regFont, std::string line) {
	int size = line.size();
	int i = 0;
	while (size > 0) {
		textprintf_ex (screen, regFont, 0, 40 + (20*i), 15, -1, "%s", line.substr(0,45).c_str()); // print the first 45 characters to screen

		if (size  > 45)
			line.erase (0,45); // Removes the first 45 characters from string
		else
			line.erase (0, line.size()); // Removes the rest of the characters
		size -= 45;
		i++; // Shifts the next line down.
	}
}

void printInfo (FONT * regFont, Question quest, int questAskd, int ansRight) {
	// Regular Font.
	if (!regFont) {
		// Print button press for menu or game exit
		textprintf_ex (screen, font, SCREEN_W - 150, SCREEN_H - 20, 15, -1, "ESC: Exit...");
		textprintf_ex (screen, font, SCREEN_W - 200, 240, 15, -1, "M: Menu");

		// Print Qustion to screen
		if (quest.getAsk ().size() <= 45){ // Checks to see if question can fit without overlappig image
			textprintf_ex (screen, regFont, 0, 40, 15, -1, "%s", quest.getAsk ().c_str());
		}
		else
		{
			printSplitLine (regFont, quest.getAsk ()); //Divides questions into separate lines
		}

		//Print choices to screen. Regular font
		textprintf_ex (screen, font, 20, 260, 15, -1, "A: %s", quest.getChoice (0).c_str());
		textprintf_ex (screen, font, 20, 290, 15, -1, "B: %s", quest.getChoice (1).c_str());
		textprintf_ex (screen, font, 20, 320, 15, -1, "C: %s", quest.getChoice (2).c_str());
		textprintf_ex (screen, font, 20, 350, 15, -1, "D: %s", quest.getChoice (3).c_str());

		// diplay ratio
		textprintf_ex (screen, font, 0, SCREEN_H-40, 15,-1, "Correct / Total Questions: %d / %d", ansRight, questAskd-1);
	}
	// Custom Font enabled
	else
	{
		// Print button press for menu or game exit
		textprintf_ex (screen, regFont, SCREEN_W - 150, SCREEN_H - 40, 15, -1, "ESC: Exit...");
		textprintf_ex (screen, regFont, SCREEN_W - 200, 240, 15, -1, "M: Menu");

		// Print Qustion to screen
		if (quest.getAsk ().size() <= 45){
			textprintf_ex (screen, regFont, 0, 40, 15, -1, "%s", quest.getAsk ().c_str());
		}
		else
		{
			printSplitLine (regFont, quest.getAsk ());
		}

		// print choices to screen. Custom Font
		textprintf_ex (screen, regFont, 20, 260, 15, -1, "A: %s", quest.getChoice (0).c_str());
		textprintf_ex (screen, regFont, 20, 290, 15, -1, "B: %s", quest.getChoice (1).c_str());
		textprintf_ex (screen, regFont, 20, 320, 15, -1, "C: %s", quest.getChoice (2).c_str());
		textprintf_ex (screen, regFont, 20, 350, 15, -1, "D: %s", quest.getChoice (3).c_str());

		// Display ratio
		textprintf_ex (screen, regFont, 0, SCREEN_H-40, 15,-1, "Correct / Total Questions: %d / %d", ansRight, questAskd-1);
	}
}

void playGame (FONT * regFont, vector <string> availImages, Question quest, int questAskd, int ansRight) {
	// Choose a new random image
	BITMAP * image = randImage (availImages);
	if (image)
		blit (image, screen, 0,0, (SCREEN_W - image -> w), 40, image -> w, image -> h); //display the image

	// Print options/info about game
	printInfo (regFont, quest, questAskd, ansRight);
	rest (100);
	destroy_bitmap (image); //delete bitmap from memory
}