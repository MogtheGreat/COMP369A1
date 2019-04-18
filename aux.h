#ifndef AUX_H
#define AUX_H
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <allegro.h>
#include <algorithm>
#include <fstream>
#include "question.h"

std::vector <std::string> getFileNames (std::string dirName);

BITMAP * randBack (std::vector <std::string> list);

BITMAP * randImage (std::vector <std::string> list);

FONT * randFont (std::vector <std::string> list, PALETTE palette);

void getQuestions (std::vector <std::string> list);

#endif