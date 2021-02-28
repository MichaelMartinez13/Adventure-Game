#ifndef AREA_H
#define AREA_H
#include <map>
using std::string;
using std::map;

class area
{
    private:
    string areaTag; //Simple identifier; bloodRoom,
                    //waterfallRoom, treasureRoom, etc.
    int areaLocationX; //Room's location along the X/east-west axis.
    int areaLocationY; //Room's location along the Y/north-south axis.
    string areaDescription; //What is displayed when entering
                            //or looking around the room.

    public:
    area(string, int, int); //Basic constructor.
    void displayArea(); //Displays the area description.
    void findExits(); //Finds any exits and outputs their locations.
    void enterArea(); //Moves the player to a given area.
    void setAreaDescription(string); //Sets the area description.
};

#endif