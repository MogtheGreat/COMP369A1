/*
Title: aux.cpp
Description: An auxiliary file that contains functions that help make the game run. 
Author: Michael G. Oranski
ID: 2743708
Date: Apr. 18, 2019
*/

#include "auxi.h"

using namespace std;

/*
	Using the dirName provided, opens up the directory, collect all
	the file names in the directory and returns the list as a vector.
	If there is no files or no directory, then the function returns an 
	empty vector.

	Param:
		dirName 	- A string that represents the directory name
	Return:
		A vector of strings that contains all the names of all the files
		in the directory.
*/
vector <string> getFileNames (string dirName) {
	vector<string> list;	// Holds the file list from the directory
	DIR * dir;				// Used to 
	struct dirent * ent;
	
	//Opens the directory
	if ((dir = opendir (dirName.c_str())) != NULL) {
		// gets all files and directories in the folder
		while ((ent = readdir (dir)) != NULL) {
			string temp (ent -> d_name);

			// Checks to see if there is a file in the directory.
			if ((temp != ".") && (temp != "..")) {
				list.push_back (temp); // Stores the file name in the list.
			}
		}
		closedir (dir); // closes directories
	}

	return list;
}

/*
	Returns a random image from the folder Background.

	Param:
		A vector of strings that contains all the names of all the files in the directory.
	Return:
		A BITMAP that is a random image. NULL if failed.
*/	
BITMAP * randBack (vector <string> list) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Background/" + list[randomIndex]; // get the path to the file
	BITMAP * backImage = load_bitmap (filePath.c_str(), NULL); // load the image to the program
	return backImage;
}

/*
	Returns a random image from the folder Images.

	Param:
		list 		- A vector of strings that contains all the names of all the files in the directory.
	Return:
		A BITMAP that is a random image. NULL if failed.
*/	
BITMAP * randImage (vector <string> list) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Images/" + list[randomIndex]; // get the path to the file
	BITMAP * image = load_bitmap (filePath.c_str(), NULL); // load the image to the program
	return image;
}

/*
	Returns a random font from the folder Fonts.

	Param:
		list 		-A vector of strings that contains all the names of all the files in the directory.
		palette 	- A PALETTE which is a RGB color
	Return:
		A FONT that is a random font chosen. NULL if failed.
*/
FONT * randFont (vector <string> list, PALETTE palette) {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = "Fonts/" + list[randomIndex]; // get the path to the file
	FONT * font = load_font (filePath.c_str(), palette, NULL); // loads the font to the program
	return font;
}

/*
	Returns a random wav sound from the folder specified in param.

	Param:
		list 		-A vector of strings that contains all the names of all the files in the directory.
		path 		- A string that represents the sub directory being accessed
	Return:
		A SAMPLE that is a random wave sample chosen. NULL if failed.
*/
SAMPLE * randSound (vector <string> list, string path)  {
	int randomIndex = rand () % list.size();	// Pick a random element from list
	string filePath = path + list[randomIndex]; // get the complete path to the file
	SAMPLE * sample = load_sample(filePath.c_str()); // load the sample to the program
	return sample;
}

/*
	Opens up all the files in the Questions directory. Loads each
	file into a separate directory then store all the vectors in
	one master vector. Returns NULL if empty.

	Param:
		list 		-A vector of strings that contains all the names of all the files in the directory.
	Return:
		A vector of vector that contains all the questions from the textbook
*/
vector <vector <Question> > getQuestions (vector <string> list) {
	std::sort (list.begin(), list.end());			// Sorts the list of files in alphabetical order
	vector <vector <Question> > chapterList;

	for (int i = 0; i < (int) list.size(); i++)		// Goes through all the files in the directory
	{
		string line;
		string filePath = "Questions/" + list[i];	// Gets the complete path for the current file.
		ifstream file (filePath.c_str());			// Opens up the file.

		int cycle = 0;


		if (file.is_open()){

			vector <Question> chapter;		// Current chapter's question set
			vector <string> choice;			// Choice of current question
			string ask;						// Question being asked
			char answer;					// Answer to question

			while (getline (file,line)) {
				if (cycle == 0) // First line from file is the question
					ask = line;
				else if ((cycle > 0) && (cycle < 5)) // Next four lines are the choices
					choice.push_back(line);
				else if (cycle == 5)
					answer = line.at(0); 		// Sixth line is the answer
				cycle = (cycle + 1) % 6; 		// Reset cycle to beginning after sixth line. Prepare for next question
				
				if (cycle == 0) // After reset happens.
				{
					Question hold (ask, choice, answer); // Store info in a Question object
					chapter.push_back (hold);		// Store in list.
					choice.clear();		// Clear choice vector
				}
			}
			file.close();
			chapterList.push_back (chapter); // Store chapter in master vector
		}
	}
	return chapterList;
}

/*
	Gets the range of chapters to cover based on user's choice.

	Param:
		unit			- An integer that represent unit selection. If non negative, then positive integer 
						  represents the unit selected.
		chapter 		- An integer that represent chapter selection. If non negative, then positive integer 
						  represents the chapter selected.
		begin 			- A reference to an integer that represents the first chapter.
		end				- A reference to an integer that represents the last chapter.
	Return:
		N/A
	Note:
		begin and end are used to access array indexes.
*/
void questRange (int unit, int chapter, int &begin, int &end) {
	if ((unit != -1) && (chapter == -1)) // User has chosen either unit or chapter selection.
	{
		if (unit == 0) { // Unit 1 is chapters 1 to 6
			begin = 0;
			end = 5;
		}
		else if (unit == 1) { // Unit 2 is chapters 7 to 11
			begin = 6;
			end = 10;
		}
		else if (unit == 2) { // Unit 3 is chapters 12 to 16.
			begin = 11;
			end = 15;
		}
		else { // Unit 4 is chapters 17 to 22.
			begin = 16;
			end = 21;
		}
	}
	else if ((unit == -1) && (chapter != -1)) // Chapter selection is just one single chapter
	{
		begin = chapter;
		end = chapter;
	}
	else { // Occurs if all chapters are selected or both unit and chapter are non negative (possible bug in that case)
		begin = 0;
		end = 21;
	}
}

/*
	Gets a random question from the master vector list.
	
	Param:
		chapterList 	- A vector contain multiple vectors that contains questions.
		unit			- An integer that represent unit selection.
		chapter 		- An integer that represent chapter selection.
	Return:
		A Question object that holds the question being asked, the choice available, and the answer.
*/
Question getRandQuest (vector <vector <Question> > chapterList, int unit, int chapter) {
	int begin = -1;
	int end = -1;
	int randChapter = -1;
	int randQuest = rand() % 10;	// There are 10 questions per chapter. Picks one at random.

	questRange (unit, chapter, begin, end); // Grabs the range of available chapters based on user's selection
	randChapter = rand() % ((end - begin) + 1)+begin; // Picks the random chapter based on the range

	return chapterList[randChapter][randQuest];
}
