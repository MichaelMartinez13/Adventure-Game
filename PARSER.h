//This file exists to avoid linker errors.
#ifndef PARSER_H
#define PARSER_H

#include <locale>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "AREA.h"
#include "PLAYER.h"
#include "ENUMS.h"
using std::string; using std::vector;

string lc(string);
std::map<string, eVerb> makeVerbMap();
bool parseInput(vector<string> sentence);
void userInput();

#endif