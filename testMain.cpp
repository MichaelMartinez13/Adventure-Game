#include "AREA.cpp"
#include <iostream>
using std::string;

int main()
{
    area startRoom("startRoom", 0, 0);
    startRoom.setAreaDescription(
    "You're standing in the entry hall. There's not much in here\n"
    "- some candelabras, a rug, a hell of a lot of cobwebs."
    );
    startRoom.enterArea();
    return 0;
}