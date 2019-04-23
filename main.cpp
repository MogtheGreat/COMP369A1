/*
Title: main.cpp
Description: Plays the game Pocket Trivia A1 which is trivia game that can be played completely from the
			 keyboard.
Author: Michael G. Oranski
ID: 2743708
Date: Apr. 18, 2019
*/
/*
 DOCUMENTATION
 Program Purpose:
 	To play a trivia game called Pocket Trivia A1. The program will display the question to the
 	player along with a list of four possible answer.

  Compile (assuming running on Linux):
 	gcc -Wall main.cpp aux.cpp game.cpp question.cpp `pkg-config --cflags --libs allegro` -lstdc++ -o Trivia
 	or
	make
 Execution (assuming running on Linux):
 	./Trivia

class:
	Question 	- Represents the questions from the textbook. Contains the questions, the choices available, and the ansewr
 
 Variables:
	Question quest; // Holds the current question to be asked
	vector <vector <Question> > chapterList; // Holds all chapters quizes from textbook
	vector <string> availImages; 			//  Available images from Image folder
	vector <string> availBackground;		// Available background from Background foler
	vector <string> availFont;				// Available font file from Font folder
	vector <string> availQuestions;			// Available Questions from Question folder
	
	vector <string> soundCorrect;			// Available 'Correct' sound effect from sound folder
	vector <string> soundWrong;				// Available 'Wrong' sound effect from sound folder
	vector <string> soundSelect;			// Available 'Select' sound effect from sound folder
	vector <string> soundIntro;				// Available 'Intro' sound effect from sound folder
	vector <string> availMusic;				// Available .wav from music folder

	// control variables and counters
	int playScreen = 0;
	int choice = 0;
	int unit = -1;
	int chapter = -1;
	bool answered = true;
	char playerChoice = ' ';
	int questAskd = 0;
	int ansRight = 0;

	// Sound variables 
	int volume = 128;
	int musicVolume = 225;
    int pan = 128;
    int pitch = 1000;
 */
/*
	TEST PLAN

Normal Case 1
Choose all Chapters.
Play through 5 or so quesitons.
Exit.

Normal Case 2
Choose unit.
Choose unit 1.
Play 2 to 3 questions.
Go back to menu.
Choose next unit.
Repeat until all units have been tested.
exit.

Normal Case 3
Choose chapter
Choose chapter 1.
Play 2 to 3 questions.
Go back to menu.
Choose next chapter.
Repeat until all chapters have been tested.
exit.

Bad Data Case
Press anything else other then options listed. - pass
Remove image or sound from folder before game start. - pass 
Remove image or sound from folder after game start. - Seg fault
Remove question file before game start. - Seg fault
Remove question file after game start. - pass
Switch image files around. - pass
Switch image and sound around. - seg fault.

Limit Test
N/A
*/

#include "game.h"

using namespace std;

int main (void) {

	Question quest; // Holds the current question to be asked
	vector <vector <Question> > chapterList; // Holds all chapters quizes from textbook
	vector <string> availImages; 			//  Available images from Image folder
	vector <string> availBackground;		// Available background from Background foler
	vector <string> availFont;				// Available font file from Font folder
	vector <string> availQuestions;			// Available Questions from Question folder
	
	vector <string> soundCorrect;			// Available 'Correct' sound effect from sound folder
	vector <string> soundWrong;				// Available 'Wrong' sound effect from sound folder
	vector <string> soundSelect;			// Available 'Select' sound effect from sound folder
	vector <string> soundIntro;				// Available 'Intro' sound effect from sound folder
	vector <string> availMusic;				// Available .wav from music folder

	// control variables and counters
	int playScreen = 0;
	int choice = 0;
	int unit = -1;
	int chapter = -1;
	bool answered = true;
	char playerChoice = ' ';
	int questAskd = 0;
	int ansRight = 0;

	// Sound variables 
	int volume = 128;
	int musicVolume = 225;
    int pan = 128;
    int pitch = 1000;

	// Initializes the Allegro library and sets up the interrupts
	if (init_Lib () == 1)
		return 1;

	//install a digital sound driver
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
    {
        allegro_message("Error initializing sound system");
        return 1;
    }

	srand (time (NULL)); // seed random generator.

	// Get list of all avail questions, images, fonts and background.
	availImages = getFileNames ("Images");
	availBackground = getFileNames ("Background");
	availFont = getFileNames ("Fonts");
	availQuestions = getFileNames ("Questions");
	chapterList = getQuestions (availQuestions);

	// Get list of available sound effects
	soundCorrect = 	getFileNames ("Sounds/Correct");
	soundWrong = getFileNames ("Sounds/Wrong");
	soundSelect = getFileNames ("Sounds/Select");
	soundIntro = getFileNames ("Sounds/Intro");
	availMusic = getFileNames ("Music");

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
	
	//Gets a random sample and load it
	SAMPLE * introEffect = randSound (soundIntro, "Sounds/Intro/");
	SAMPLE * correctEffect = randSound (soundCorrect, "Sounds/Correct/");
	SAMPLE * wrongEffect = randSound (soundWrong, "Sounds/Wrong/");
	SAMPLE * selectEffect = randSound  (soundSelect, "Sounds/Select/");
	SAMPLE * music = randSound (availMusic, "Music/");

	// Play intro sample and destroy it
	if (introEffect)
		play_sample(introEffect, volume, pan, pitch, FALSE);
	if (music) // If music is availabe, play the music with looping
				play_sample(music, musicVolume, pan, pitch, TRUE);

	// While user has not pressed ESC key.
	while (!key[KEY_ESC]) {

		// Plays instruction at start of game
		if (playScreen == 0) {

			printBackground (titleFont, backImage); // Prints the background screen
			playStart (regFont); // Add instruction to screen
			while (!keypressed()); // Wait for key press
			readkey(); // Removes key press from buffer. Without keypressed() remains true after first key press
			
			if (key[KEY_ENTER])// if player press enter continue game
				playScreen = 1;
			if ((playScreen == 1) && (selectEffect)) // Players had made a valid choice and a sample has been loaded
				play_sample(selectEffect, volume, pan, pitch, FALSE);
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

			if ((playScreen == 2) && (selectEffect)) // Players had made a valid choice and a sample has been loaded
				play_sample(selectEffect, volume, pan, pitch, FALSE);
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

				if (selectEffect) // Sample has been loaded successfully, play sound
					play_sample(selectEffect, volume, pan, pitch, FALSE);
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

				if (selectEffect) // Sample has been loaded successfully, play sound
					play_sample(selectEffect, volume, pan, pitch, FALSE);
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

					if (correctEffect) // Sample has been loaded successfully, play sound
						play_sample(correctEffect, volume, pan, pitch, FALSE);
				}
				else if (wrongEffect) { // Player has made wrong choice and there is sample loaded successfully, play sound
					play_sample(wrongEffect, volume, pan, pitch, FALSE);
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

	//Release sound memory
	destroy_sample (introEffect);
	destroy_sample (correctEffect);
	destroy_sample (wrongEffect);
	destroy_sample (selectEffect);
	destroy_sample (music);

	allegro_exit ();	// Frees all Allegro memory
	return 0;
}
END_OF_MAIN()

