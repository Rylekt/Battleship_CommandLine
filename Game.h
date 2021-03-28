//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "RandomPlayer.h"
#include <string>
#include <chrono>
#include <thread>

class Game
{
public:
	Game();
	void selectPlayers(); // Define the players and the type of player
	Player* nextPlayer(Player *p) const; // Switch between the players
	Player* getCurrentPlayer(){return currentPlayer;} // get the current player
	bool isRunning(); // Check to see if there is a winner
	void play(); // play the game
	void announceWinner(); // display who the winner is
	virtual ~Game();

private:
	Player *player1;
	Player *player2;

	Player *currentPlayer;
	Board board1;


};

#endif // GAME_H
