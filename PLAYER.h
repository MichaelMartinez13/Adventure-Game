//Player class written by JS, 03/03/21. 

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

//Using unscoped enum instead of enum class so enum values can index arrays
//without using static_cast. The correspondence between the jobs and their relevant stats
//is deliberate, in case we want to use unscoped enum equality in some capacity.
enum eJob {student = 0, mage = 1, warrior = 2, rogue = 3, cultist = 4};
enum eStat {maxHealth = 0, knowledge = 1, might = 2, trickery = 3, depravity = 4};
//The player's main stats: knowledge::mage, might::warrior, trickery::rogue,
//depravity::cultist. maxHealth is determined by class: mage/cultist/student 20,
//rogue 30, warrior 40.

class player
{
    private:
    static player* p1; //Making this class a singleton so the instance can be called
    //from anywhere.
    player(); //Private constructor for the singleton; prevents erroneous reconstruction.
    string playerName; //Entered by player at beginning of game.
    int playerLocationX; //Character's location along the X-axis.
    int playerLocationY; //Character's location along the Y-axis.
    eJob playerJob; //The character's class.
    int playerHealth; //The character's health meter. 
    int playerCorruption; //The character's corruption meter. This serves
    //as a sort of secondary health bar, related less to physical damage
    //and more to mental or moral harm. Starts at 0, goes to 13.
    int playerStats[5]; //Stores the player's stats.
    friend class area;

    public:
    static player* getPlayer(); //Use this to point to p1, the player.
    int getPlayerX() {return playerLocationX;} //Gets player's X-coordinates.
    int getPlayerY() {return playerLocationY;} //Gets player's Y-coordinates.
    void setPlayerName(); //Sets the player's name.
    void setPlayerJob(eJob); //Sets the player's job when they select their
    //starting weapon.
    void hurtPlayer(int); //Lowers player's health.
    void healPlayer(int); //Increases player's health up to max.
    void corruptPlayer(int); //Increases player's corruption.
    void purifyPlayer(int); //Decreases player's corruption.
    void modPlayerStat(eStat, int); //Modifies the specified stat.
    void killPlayer(); //Game over.
    void badEnd(); //Game over (corruption edition).
};

#endif