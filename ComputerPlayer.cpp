//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "ComputerPlayer.h"
#include <string>

char ComputerPlayer::letter = ' ';

/// <summary> Constructor for Computer Player
ComputerPlayer::ComputerPlayer(const std::string &Name, int num) :Player{ Name,num } {
	std::string n1 = Name;
	if (letter == ' ') {
		letter = 'A';
		n1 += letter;
	}
	else if (letter == 'Z') {
		letter = 'A';
		n1 += letter;
	}
	else {
		++letter;
		n1 += letter;
	}
	Player::setName(n1);
}

/// <summary> Generates a move for the Computer Player
/// <return> Move struct defined in Board.h
Board::Move ComputerPlayer::makeMove(Board & b, int player)
{
	char letter;    // Char for the Move struct
	int num;        // int for the Move struct
	Board::Move m;  // Move Struct
	do {
		std::cout << "\nMake a move: CP ";
		std::cin >> letter >> num; // Takes the user's inputs for the struct
		m.letter = letter;
		m.num = num;
	} while (!b.isLegal(m, player)); // Ensure the move is a legal move
	return m;
}
