#include "game.h"

using namespace std;

int main (void) {

	Question quest;
	vector <vector <Question> > chapterList;
	vector <string> availImages; 
	vector <string> availBackground;
	vector <string> availFont;
	vector <string> availQuestions;

	int play = 0;
	int choice = 0;
	int unit = -1;
	int chapter = -1;
	bool answered = true;
	char playerChoice = ' ';
	int questAskd = 0;
	int ansRight = 0;

	// Initializes the Allegro library and sets up the interrupts
	if (init_Lib () == 1)
		return 1;

	srand (time (NULL)); // seed random generator.

	// Get list of all avail questions, images, fonts and background.
	availImages = getFileNames ("Images");
	availBackground = getFileNames ("Background");
	availFont = getFileNames ("Fonts");
	availQuestions = getFileNames ("Questions");
	chapterList = getQuestions (availQuestions);

	// Creates the window and sets the graphics mode
	int ret = set_gfx_mode (GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0) {
		allegro_message ("%s\n", allegro_error);
		return 1;
	}

	PALETTE palette;	// Color palette for fonts.
	FONT * titleFont = load_font (TITLEFONT, palette, NULL); // Loads Title font 
	FONT * regFont = randFont (availFont, palette); // Gets random font and load it
	BITMAP * backImage = randBack (availBackground); // Get random background image and loads it
	printBackground (titleFont, backImage); // Prints the background screen
	

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {

		// Plays instruction at start of game
		if (play == 0) {
			printBackground (titleFont, backImage); // Prints the background screen
			playStart (play, regFont); // Add instruction to screen
			while (!keypressed()); // Wait for key press
			readkey(); // Removes key press from buffer. Without keypressed() remains true after first key press
			
			if (key[KEY_ENTER])// if player press enter continue game
				play = 1;
		}

		// Show Main Menu
		else if (play == 1) {
			printBackground (titleFont, backImage); // Prints the background screen
			menu (regFont); // Add menu selection
			while (!keypressed()); // Wait for key press
			readkey();
			
			if (key[KEY_A]) { // Player selects all chapters
				play = 2;
				unit = -1;
				chapter = -1;
			}
			
			if (key[KEY_U]) { //Player select unit selection
				play = 2;
				choice = 1;
			}
			if (key[KEY_C]) { // Player select chapter selection
				play = 2;
				choice = 2;
			}
		}

		else if (choice == 1) {
			printBackground (titleFont, backImage);
			menuUnit (regFont);
			while (!keypressed());
			readkey();

			menuUnitInput (unit);
			if (unit != -1) {
				choice = 3;
				chapter = -1;
			}
		}

		else if (choice == 2) {
			printBackground (titleFont, backImage);
			menuChapter (regFont);
			while (!keypressed());
			readkey();

			menuChapterInput (chapter);
			if (chapter != -1) {
				choice = 3;
				unit = -1;
			}
		}
		else {
			printBackground (titleFont, backImage);
			showSelection (regFont, unit, chapter);
			if (answered == true) {
				quest = getRandQuest (chapterList, unit, chapter);
				answered = false;
				questAskd++;
			}

			playGame (regFont, availImages, quest, questAskd, ansRight);
			while (!keypressed());
			readkey();

			if (key[KEY_A]) {
				answered = true;
				playerChoice = 'a';
			}
			if (key[KEY_B]) {
				answered = true;
				playerChoice = 'b';
			}
			if (key[KEY_C]) {
				answered = true;
				playerChoice = 'c';
			}
			if (key[KEY_D]) {
				answered = true;
				playerChoice = 'd';
			}

			if (answered == true) {
				if (playerChoice == quest.getAns()) {
					ansRight++;
				}
			}

			if (key[KEY_M])
				play = 1;
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

