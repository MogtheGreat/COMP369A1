/*
Title: game.h
Description: The game graphic file that contains functions that mostly deal with the game's graphics.
Author: Michael G. Oranski
ID: 2743708
Date: Apr. 18, 2019
*/
#ifndef MAIN_H
#define MAIN_H
#include <allegro.h>
#include "auxi.h"

//All grpahics and sound in Game. Allows for easy swapping.
#define TITLEFONT "TitleFont/Circuit Mage(24).pcx"
#define COLORLINE makecol (0, 63, 0)

int init_Lib ();

void printBackground (FONT * titleFont, BITMAP * backImage);

void playStart (FONT * regFont);

void menu (FONT * regFont);

void showSelection (FONT * regFont, int unit, int chapter);

void menuUnit (FONT * regFont);

void menuUnitInput (int & unit);

void menuChapter (FONT * regFont);

void menuChapterInput (int & chapter);

void printSplitLine (FONT * regFont, std::string line);

void printInfo (FONT * regFont, Question quest, int questAskd, int ansRight);

void playGame (FONT * regFont, std::vector <std::string> availImages, Question quest, int questAskd, int ansRight);

#endif