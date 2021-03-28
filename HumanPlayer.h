//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Board.h"
#include "Player.h"

class HumanPlayer : public Player { // Base class is Player which is derived into this class
public:
	HumanPlayer(const std::string &Name, int num); // Human Player Constructor
	virtual ~HumanPlayer();
	Board::Move makeMove(Board &PB, int player); // Takes in the user's input and puts it into a move

private:
};

#endif // HUMANPLAYER_H
