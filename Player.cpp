//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "Player.h"

Player::Player(const std::string &Name, int num) { // Constructor to set the player with their ID and names
	this->PlayerName = Name;
	if (num == 1 || num == 2) // if the entry is not 1 or 2 invalid entry so leave the code
		this->playerID = num;
	else
		exit(1);
}

/// <summary> The user inputs a Move using the istream operator
/// <return> Move struct that is defined in Board.h
Board::Move Player::makeMove( Board &PB, int player) { // Takes in the player's move which is then passed to the appropriate player type class
	Board::Move m;
	char letter;
	int num;
	do {
		std::cout << "\nMake a move pp: ";
		std::cin >> letter; // Takes in the character for the struct
		std::cin >> num;    // Takes in the number for the struct
		m.letter = letter;  // Assigns the letter for the struct
		m.num = num;
	} while (!PB.isLegal(m, player));// Assigns the number for the struct
	return m;
}

/// <summary> Switches between playerID to the opposing player
/// <return> int
int Player::changePlayer() { // Move this to the Game class
	if (playerID == 1) {
		playerID = 2;
		return playerID;
	}
	else {
		playerID = 1;
		return playerID;
	}
}

/// <summary> Changes the private variable Player Name
void Player::setName(std::string newName) {
	this->PlayerName = newName;
}

Player::~Player()
{
	//dtor
}
