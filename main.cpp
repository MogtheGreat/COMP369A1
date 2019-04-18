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
			
			if (key[KEY_A]) {
				play = 2;
				unit = -1;
				chapter = -1;
			}
			
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
			if (answered == true) {
				quest = getRandQuest (chapterList, unit, chapter);
				answered = false;
			}

			playGame (regFont, availImages, quest);
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
					//Play Winner func
					cout << "Winner!" << endl;
				}
				else  {
					// Play Lost func
					cout << "Loser!" << endl;
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

