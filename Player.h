//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>


class Player // Player Base Class
{
    public:
        Player(const std::string &Name, int num);
        virtual Board::Move makeMove(Board &PB, int player);
        int getPlayerID(){return playerID;}       // Get playerID
        std::string getName(){return PlayerName;} // Get the private variable PlayerName
        void setName(std::string newName);        // Change the player's name
        int changePlayer();
        virtual ~Player(); // Player Destructor

    private:
        std::string PlayerName;
        int playerID;
};

#endif // PLAYER_H
