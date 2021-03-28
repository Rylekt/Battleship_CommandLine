//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string &Name, int num) :Player{ Name,num } {}

HumanPlayer::~HumanPlayer() {
	//dtor
}

/// <summary> Have a Player input a move which is then checked and put into the board
/// <return> Move from input
Board::Move HumanPlayer::makeMove(Board &PB, int player) {
	char letter; // Obtain the character for the player input
	int num;     // Obtain the number for the player input
	Board::Move m;
	do{
        std::cout << "\nMake a move: ";
        std::cin >> letter >> num; // Takes the user's inputs for the struct
        m.letter = letter;
        m.num = num;
	} while (!PB.isLegal(m, player));
	return m;
}
