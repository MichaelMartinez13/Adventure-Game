#include <iostream>
#include <iomanip>
#include "AREA.h"
using std::cout; using std::cin; using std::string; using std::endl;

void area::displayArea()
{
    cout << areaDescription << endl;
}

void area::enterArea()
{
    area::displayArea();
}

void area::findExits()
{

}

void area::setAreaDescription(string description)
{
    area::areaDescription = description;
}

area::area(string tag, int X, int Y)
{
    area::areaTag = tag;
    area::areaLocationX = X;
    area::areaLocationY = Y;
}