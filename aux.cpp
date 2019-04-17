#include "aux.h"

using namespace std;

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
