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
