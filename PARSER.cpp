//Parser written by JS, 03/12/21.

#include <locale>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "AREA.h"
#include "PLAYER.h"
using std::cout; using std::cin; using std::string; using std::endl; using std::vector;

//Converts inputs to lowercase for case-insensitive parsing.
string lc(string s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

//Enum to store verbs. Will be added to as we add more things to do. Cardinal directions are
//totally verbs, guys.
enum eVerb
{
    look = 0,
    north = 1, south = 2, east = 3, west = 4,
    take = 5
};

//Creates the verbMap used in the parser proper to parse the strings. Synonyms are
//defined here.
std::map<string, eVerb> makeVerbMap()
{
    std::map<string, eVerb> verbMap;
    verbMap["look"] = look; verbMap["look around"] = look;
    verbMap["north"] = north; verbMap["n"] = north;
    verbMap["south"] = south; verbMap["s"] = south;
    verbMap["east"] = east; verbMap["e"] = east;
    verbMap["west"] = west; verbMap["w"] = west;
    verbMap["take"] = take; verbMap["get"] = take; verbMap["steal"] = take;
}

//For some reason you have to make a constructor function and then call it, you can't
//just construct a map out-of-line. C++, why.
std::map<string, eVerb> verbMap = makeVerbMap();

//The actual main event. Takes words from userInput(), strips out filler words, and tells
//the system what to do with the words that are left (which should ideally be a single
//verb and an optional noun). Again, will be added to as we add things to do.
bool parseInput(vector<string> sentence)
{
    player* p1 = player::getPlayer();
    area* currentArea = area::getArea(p1->getPlayerX(), p1->getPlayerY());
    for (int i = 0; i < sentence.size();)
    {
        if (sentence[i] == "at" || sentence[i] == "go" || sentence[i] == "the" || 
        sentence[i] == "a" || sentence[i] == "an")
        {
            sentence.erase(sentence.begin() + i);
        }
        else
        {
            i++;
        }
    }
    switch(verbMap[sentence[0]]) //Checks the first relevant word input by the user.
    {
        case look:
        //Once we have objects coded, we'll be able to have code to look at those objects.
        //We don't, so we don't. Default looks around the current room. ("look
        //[currentArea->areaName]" should also look around the current room, but there's no
        //point coding that until we have a non-default case.)
        currentArea->displayArea();
        break;
        case north:
        currentArea->goDirection(north);
        break;
        case south:
        currentArea->goDirection(south);
        break;
        case east:
        currentArea->goDirection(east);
        break;
        case west:
        currentArea->goDirection(west);
        break;
        default:
        cout << "I didn't understand that command." << endl;
        return false;
        break;
    }
    return true;
}

void userInput()
{
    bool successful = false;
    do
    {
        cout << "What do you do?" << endl;
        string input;
        getline(cin, input);
        input = lc(input);
        vector<string> sentence;
        string temp;
        for (int i = 0; i < input.length(); i++)
        {
            int j = 0;
            int k = 0;
            if (input[i] != ' ')
            {
                temp[j] = input[i];
                j++;
            }
            else
            {
                sentence[k] = temp;
                j = 0;
                k++;
            }
        }
        successful = parseInput(sentence);
    }
    while (!successful);
}