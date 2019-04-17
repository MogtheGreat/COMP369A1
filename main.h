#ifndef MAIN_H
#define MAIN_H
#include <allegro.h>
#include "aux.h"

int init_Lib ();

void printBackground (FONT * titleFont, BITMAP * backImage);

void printInfo (FONT * regFont);

void playStart (int &play, FONT * regFont);

void menu (FONT * regFont);

void menuUnit (FONT * regFont);

void menuUnitInput (int & unit);

void menuChapter (FONT * regFont);

void playGame (FONT * regFont);

#endif