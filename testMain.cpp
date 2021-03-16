#include "AREA.cpp"
#include "PLAYER.cpp"
#include <iostream>
using std::string;

int main()
{
    area startRoom("startRoom", 3, 4, "Lobby");
    startRoom.setAreaDescription(
    "You're standing in the entry hall. There's not much in here\n"
    "- some candelabras, a rug, a hell of a lot of cobwebs."
    );
    startRoom.enterArea();
    return 0;
}