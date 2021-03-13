#include <locale>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "AREA.cpp"
#include "PLAYER.cpp"
using std::cout; using std::cin; using std::string; using std::endl; using std::vector;

//Converts inputs to lowercase for case insensitive parsing.
string lc(string s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    return s;
}

//The main event. Will be added to as we add more things to do. Synonyms should have the
//same numeric value as the main word.
enum eVerb
{
    look = 0,
    north = 1, south = 2, east = 3, west = 4,
    take = 5
};

std::map<string, eVerb> makeVerbMap()
{
    std::map<string, eVerb> verbMap;
    verbMap["look"] = look;
    verbMap["north"] = north; verbMap["n"] = north;
    verbMap["south"] = south; verbMap["s"] = south;
    verbMap["east"] = east; verbMap["e"] = east;
    verbMap["west"] = west; verbMap["w"] = west;
    verbMap["take"] = take; verbMap["get"] = take; verbMap["steal"] = take;
}

std::map<string, eVerb> verbMap = makeVerbMap();

void parseInput(vector<string> sentence)
{
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
    switch(verbMap[sentence[0]])
    {
        case look:
        
    }
}

void userInput()
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
}