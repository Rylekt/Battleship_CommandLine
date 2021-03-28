//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <random>
#include <chrono>
#include <thread>
#include <ctime>
#include <functional>
#include "Board.h"
#include "ComputerPlayer.h"


class RandomPlayer : public ComputerPlayer // Base class is ComputerPlayer which is derived into RandomPlayer
{
public:
	RandomPlayer(const std::string &Name, int num);
	Board::Move makeMove(Board &b, int player);
	//~RandomPlayer();


};

#endif // RANDOMPLAYER_H
