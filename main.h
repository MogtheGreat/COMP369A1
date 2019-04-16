#ifndef MAIN_H
#define MAIN_H
#include <allegro.h>
#include "aux.h"

int init_Lib ();

BITMAP * randBack (std::vector <std::string> list);

BITMAP * randImage (std::vector <std::string> list);

FONT * randFont (std::vector <std::string> list, PALETTE palette);

void printBackground (FONT * titleFont, BITMAP * backImage);

void printInfo (FONT * regFont);

void playStart (int &play, FONT * regFont);

void menu (FONT * regFont);

void playGame (FONT * regFont);

#endif