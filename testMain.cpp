#include "AREA.cpp"
#include <iostream>
#include <iomanip>
using std::string;

int main()
{
    area startRoom("startRoom", 0, 0);
    startRoom.setAreaDescription("This place is dark, "
    "but you can see faint outlines of furniture, including "
    "an unlit candle.");
    startRoom.enterArea();
    return 0;
}
