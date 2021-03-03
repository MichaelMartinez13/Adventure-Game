//Player class written by JS, 03/03/21.

#include <iostream>
#include "PLAYER.h"
using std::cout; using std::cin; using std::string; using std::endl;

    void player::setPlayerName(std::string enteredName)
    {
        playerName = enteredName;
    }

    void player::setPlayerJob(eJob weapon)
    {
        playerJob = weapon;
    }

    void player::hurtPlayer(int damage)
    {
        playerHealth -= damage;
        if (playerHealth < 0)
        {
            player::killPlayer();
        }
    }

    void player::healPlayer(int healing)
    {
        if (playerHealth + healing <= playerStats[maxHealth])
        {
            playerHealth += healing;
        }
        else
        {
            playerHealth = playerStats[maxHealth];
        }
    }

    void player::corruptPlayer(int damage)
    {
        playerCorruption += damage;
        if (playerCorruption >= 13)
        {
            player::badEnd();
        }
    }

    void player::purifyPlayer(int healing)
    {
        if (playerCorruption - healing >= 0)
        {
            playerCorruption = 0;
        }
        else
        {
            playerCorruption -= healing;
        }
    }

    void player::modPlayerStat(eStat stat, int modification)
    {
        playerStats[stat] += modification;
    }

    void player::killPlayer()
    {
        cout << "Congratulations! You died." << endl;
    }

    void player::badEnd()
    {
        cout << "You have suffered a fate worse than death." << endl;
    }

