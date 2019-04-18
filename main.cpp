#include "game.h"

using namespace std;

int main (void) {

	Question quest; // Holds the current question to be asked
	vector <vector <Question> > chapterList; // Holds all chapters quizes from textbook
	vector <string> availImages; 			//  Available images from Image folder
	vector <string> availBackground;		// Available background from Background foler
	vector <string> availFont;				// Available question file from Question folder
	vector <string> availQuestions;

	// control variables and counters
	int playScreen = 0;
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
		if (playScreen == 0) {
			printBackground (titleFont, backImage); // Prints the background screen
			playStart (playScreen, regFont); // Add instruction to screen
			while (!keypressed()); // Wait for key press
			readkey(); // Removes key press from buffer. Without keypressed() remains true after first key press
			
			if (key[KEY_ENTER])// if player press enter continue game
				playScreen = 1;
		}

		// Show Main Menu
		else if (playScreen == 1) {
			printBackground (titleFont, backImage); // Prints the background screen. Also used to clear previous screen
			menu (regFont); // Add menu selection
			while (!keypressed()); // Wait for key press
			readkey();
			
			if (key[KEY_A]) { // Player selects all chapters
				playScreen = 2;
				unit = -1;
				chapter = -1;
			}
			
			if (key[KEY_U]) { //Player select unit selection
				playScreen = 2;
				choice = 1;
			}
			if (key[KEY_C]) { // Player select chapter selection
				playScreen = 2;
				choice = 2;
			}
		}

		//Shows Unit Selection Menu
		else if (choice == 1) {
			printBackground (titleFont, backImage); // Prints the background screen. Also used to clear previous screen
			menuUnit (regFont); // Adds in unit menu selections
			while (!keypressed()); // Wait for key press
			readkey();

			menuUnitInput (unit); // Get user input for unit selection
			if (unit != -1) { // if player made a choice, allow game to move onto next screen
				choice = 3;
				chapter = -1;
			}
		}

		//Shows Chapter Selection Menu
		else if (choice == 2) {
			printBackground (titleFont, backImage); // Prints the background screen. Also used to clear previous screen
			menuChapter (regFont); // Adds in chapter menu selection
			while (!keypressed()); // Wait for key press
			readkey();

			menuChapterInput (chapter); // Get user input for chapter selection
			if (chapter != -1) { // if player made a choice, allow game to move onto next screen
				choice = 3;
				unit = -1;
			}
		}
		// Shows multiple choice question screen
		else {
			printBackground (titleFont, backImage); // Prints the background screen. Also used to clear previous screen
			showSelection (regFont, unit, chapter); // Shows player chapter selection at bottom middle of screen
			
			if (answered == true) { // If previous question has been anwered..
				quest = getRandQuest (chapterList, unit, chapter); // Get next random question 
				answered = false;
				questAskd++;
			}

			playGame (regFont, availImages, quest, questAskd, ansRight); // Display screen for question
			while (!keypressed()); // Wait for key press
			readkey();

			// Checks keys pressed to see if valid choice.
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

			// Checks to see if answer is correct
			if (answered == true) {
				if (playerChoice == quest.getAns()) {
					ansRight++;
				}
			}

			// Checks to see if player wants main menu
			if (key[KEY_M])
				playScreen = 1;
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

