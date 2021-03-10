//Player class written by JS, 03/03/21.

#include <iostream>
#include "PLAYER.h"
using std::cout; using std::cin; using std::string; using std::endl;

//Sets player name. Call upon creation and forget about it.
void player::setPlayerName(std::string enteredName)
{
    playerName = enteredName;
}

//Sets player's job. Call upon creation (value 0 for Student) and when the player picks
//up their starting weapon.
void player::setPlayerJob(eJob weapon)
{
    playerJob = weapon;
}

//Causes HP damage.
void player::hurtPlayer(int damage)
{
    playerHealth -= damage;
    if (playerHealth < 0) //If damage exceeds HP, die
    {
        player::killPlayer();
    }
}

//Heals HP damage.
void player::healPlayer(int healing)
{
    if (playerHealth + healing <= playerStats[maxHealth]) //Check if overheal
    {
        playerHealth += healing;
    }
    else
    {
        playerHealth = playerStats[maxHealth]; //No overheal.
    }
}

//Causes corruption damage.
void player::corruptPlayer(int damage)
{
    playerCorruption += damage;
    if (playerCorruption >= 13) //Lucky 13 is the threshold. Over 13? Die.
    {
        player::badEnd();
    }
}

//Cures corruption damage.
void player::purifyPlayer(int healing)
{
    if (playerCorruption - healing >= 0) //No negative corruption.
    {
        playerCorruption = 0;
    }
    else
    {
        playerCorruption -= healing;
    }
}

//Mods stats; can be positive or negative.
void player::modPlayerStat(eStat stat, int modification)
{
    playerStats[stat] += modification;
}

//This will be expanded to account for what killed you. For now, Dark Souls style.
void player::killPlayer()
{
    cout << "Congratulations! You died." << endl;
}

//This will be expanded to account for what corrupted you.
void player::badEnd()
{
    cout << "You have suffered a fate worse than death." << endl;
}