#ifndef MAIN_H
#define MAIN_H
#include <allegro.h>
#include "aux.h"

//All grpahics and sound in Game. Allows for easy swapping.
#define TITLEFONT "TitleFont/Circuit Mage(24).pcx"
#define REGFONT "Fonts/COMPUTER Robot (14).pcx"
#define BACKGROUND "Background/binarybackground.pcx"
#define IMAGE "Images/image1.pcx"
#define COLORLINE makecol (0, 63, 0)

int init_Lib ();

void printBackground (FONT * titleFont, BITMAP * backImage);

void printInfo (FONT * regFont);

void playStart (int &play, FONT * regFont);

void menu (FONT * regFont);

void menuUnit (FONT * regFont);

void menuUnitInput (int & unit);

void menuChapter (FONT * regFont);

void menuChapterInput (int & chapter);

void playGame (FONT * regFont, std::vector <std::string> availImages);

#endif