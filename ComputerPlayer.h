//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <string>
#include "Player.h"
#include "Board.h"

class ComputerPlayer : public Player // Base class is Player which is derived into ComputerPlayer
{
public:
	ComputerPlayer(const std::string &Name, int num);
	std::string getName() { return ComputerName; }
	virtual Board::Move makeMove(Board &b, int player);

private:
	std::string ComputerName;
	static char letter;
};

#endif // COMPUTERPLAYER_H
