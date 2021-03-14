#include "AREA.h"
#include "PLAYER.h"
#include "PARSER.h"
#include "NEWAREA.h"

int main()
{
    areaSetup();
    area* startRoom = area::getArea(3, 3);
    startRoom->enterArea();
    while (true)
    {
        userInput();
    }
    return 0;
}