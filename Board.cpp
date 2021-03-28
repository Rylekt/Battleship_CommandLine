//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "Board.h"

Board::Board()
{
	reset(); // Clear the board and place new board pieces
}

/// <summary> Board Destructor
Board::~Board() {
	delete[] Board::Player1Board;
	delete[] Board::Enemy1Board;
	delete[] Board::Player2Board;
	delete[] Board::Enemy2Board;

}

/// <summary> Empties the board and sets new ships in their proper spot
/// <return> void
void Board::reset() noexcept {
	for (int i = 0; i < 100; ++i) {
		Board::Player1Board[i] = PlayerPiece::EMPTY;
		Board::Enemy1Board[i] = EnemyPiece::EMPTY;
		Board::Player2Board[i] = PlayerPiece::EMPTY;
		Board::Enemy2Board[i] = EnemyPiece::EMPTY;
	}

	// Setup each Players ships
	for (int i = 0; i < 5; ++i) { // Set the AIRCRAFT
		Board::Player1Board[i] = PlayerPiece::AIRCRAFT;
		Board::Player2Board[i] = PlayerPiece::AIRCRAFT;
	}
	for (int i = 10; i < 14; ++i) { // Set the BATTLESHIP
		Board::Player1Board[i] = PlayerPiece::BATTLESHIP;
		Board::Player2Board[i] = PlayerPiece::BATTLESHIP;
	}
	for (int i = 20; i < 23; ++i) { // Set the CRUISER and SUBMARINE
		Board::Player1Board[i] = PlayerPiece::CRUISER;
		Board::Player2Board[i] = PlayerPiece::CRUISER;
		Board::Player1Board[i + 10] = PlayerPiece::SUBMARINE;
		Board::Player2Board[i + 10] = PlayerPiece::SUBMARINE;
	}
	for (int i = 40; i < 42; ++i) { // Set the PATROL
		Board::Player1Board[i] = PlayerPiece::PATROL;
		Board::Player2Board[i] = PlayerPiece::PATROL;
	}
}

// ------------------------------------ Other Functionality ------------------------------------

/// <summary> Gather the player's board instances and display them to screen using cout.
/// <return> void
void Board::display(int player) const noexcept {

	// ----------------------------- Player's Enemy Board Display -----------------------------
	std::cout << "Enemy " << player << "'s Board \n";
	std::cout << "\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10";
	for (int i = 0; i < 10; ++i) {
		std::cout << '\n' << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < 10; ++j) {
			if (player == 1) { // For Player 1 Enemy Board
				if (Board::Enemy1Board[j + (i * 10)] == EnemyPiece::HIT)
					std::cout << "H \t";
				else if (Board::Enemy1Board[j + (i * 10)] == EnemyPiece::MISS)
					std::cout << "M \t";
				else
					std::cout << "~ \t";
			}
			else if (player == 2) { // For Player 2 Enemy Board
				if (Board::Enemy2Board[j + (i * 10)] == EnemyPiece::HIT)
					std::cout << "H \t"; // Display H if they hit
				else if (Board::Enemy2Board[j + (i * 10)] == EnemyPiece::MISS)
					std::cout << "M \t"; // Display M if they missed
				else
					std::cout << "~ \t"; // Display ~ if the tile is empty (as if it is a wave)
			}
			else { exit(1); } // Abort the program if it isn't a valid player;
		}
	}

	std::cout << "\n\n-------------------------------------------------------------------------------------------\n\n"; // Line dividing the boards (visibility sake)

	// ----------------------------- Player's Board Display -----------------------------
	std::cout << "Player " << player << "'s Board \n";
	std::cout << "\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10";
	for (int i = 0; i < 10; ++i) {
		std::cout << '\n' << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < 10; ++j) {
			if (player == 1) { // Check each of the tile pieces for Player 1
				if (Board::Player1Board[j + (i * 10)] == PlayerPiece::AIRCRAFT) {
					std::cout << "A \t"; // Display A if the tile is an Aircraft
				}
				else if (Board::Player1Board[j + (i * 10)] == PlayerPiece::BATTLESHIP) {
					std::cout << "B \t"; // Display B if the tile is a Battleship
				}
				else if (Board::Player1Board[j + (i * 10)] == PlayerPiece::CRUISER) {
					std::cout << "C \t"; // Display C if the tile is a Cruiser
				}
				else if (Board::Player1Board[j + (i * 10)] == PlayerPiece::SUBMARINE) {
					std::cout << "S \t"; // Display S if the tile is a Submarine
				}
				else if (Board::Player1Board[j + (i * 10)] == PlayerPiece::PATROL) {
					std::cout << "P \t"; // Display P if the tile is a Patrol
				}
				else {
					std::cout << "~ \t"; // Display ~ if the tile is empty (as if it is a wave)
				}
			}
			else if (player == 2) { // Check each of the tile pieces for Player 2
				if (Board::Player2Board[j + (i * 10)] == PlayerPiece::AIRCRAFT) {
					std::cout << "A \t"; // Display A if the tile is an Aircraft
				}
				else if (Board::Player2Board[j + (i * 10)] == PlayerPiece::BATTLESHIP) {
					std::cout << "B \t"; // Display B if the tile is a Battleship
				}
				else if (Board::Player2Board[j + (i * 10)] == PlayerPiece::CRUISER) {
					std::cout << "C \t"; // Display C if the tile is a Cruiser
				}
				else if (Board::Player2Board[j + (i * 10)] == PlayerPiece::SUBMARINE) {
					std::cout << "S \t"; // Display S if the tile is a Submarine
				}
				else if (Board::Player2Board[j + (i * 10)] == PlayerPiece::PATROL) {
					std::cout << "P \t"; // Display P if the tile is a Patrol
				}
				else {
					std::cout << "~ \t"; // Display ~ if the tile is empty (as if it is a wave)
				}
			}
			else { exit(1); } // Abort the program if it isn't a valid player;
		}
	}
	std::cout << "\n";
}

/// <summary>
/// <return> EnemyPiece either Hit or Miss
Board::EnemyPiece Board::makeMove(const Move &m, int player) {
    int move = convertMoveToInt(m);
	if (player == 1) {
		if (Player2Board[move] != PlayerPiece::EMPTY) {
			Enemy1Board[move] = EnemyPiece::HIT;
			std::cout << "You got a hit at " << move << "\n";
			return EnemyPiece::HIT;
		}
		else {
			Enemy1Board[move] = EnemyPiece::MISS;
			std::cout << "You missed " << move << "\n";
			return EnemyPiece::MISS;
		}
	}
	else {
		if (Player1Board[move] != PlayerPiece::EMPTY) {
			Enemy2Board[move] = EnemyPiece::HIT;
			std::cout << "You got a hit at " << move << "\n";
			return EnemyPiece::HIT;
		}
		else {
			Enemy2Board[move] = EnemyPiece::MISS;
			std::cout << "You missed " << move << "\n";
			return EnemyPiece::MISS;
		}
	}
}

/// <summary> Checks if a move that is input is legal or not
/// <return> Boolean value
bool Board::isLegal(Move move, int player) {
	int m = Board::convertMoveToInt(move);
	if (move.letter < 'a' || move.letter > 'j') {
		std::cout << "Letter not correct.";
		return false;
	}
	else {
		if (player == 1) {
			if (getEnemyBoard(player, m) != EnemyPiece::EMPTY) {
				return false;
			}
		}
		else {
			if (getEnemyBoard(player, m) != EnemyPiece::EMPTY) {
				return false;
			}
		}
		return true;
	}
}

/// <summary> Convert a Move struct into an int for array access purposes
/// <return> int
int Board::convertMoveToInt(Board::Move move) { // This converts it into an int to access the board's array
	char letter = move.letter;
	int num = move.num;
	switch (letter) { // Check each letter case and convert the move struct into an integer that can be put into the board
	case 'a':
		num += 0;
		break;
	case 'b':
		num += 10;
		break;
	case 'c':
		num += 20;
		break;
	case 'd':
		num += 30;
		break;
	case 'e':
		num += 40;
		break;
	case 'f':
		num += 50;
		break;
	case 'g':
		num += 60;
		break;
	case 'h':
		num += 70;
		break;
	case 'i':
		num += 80;
		break;
	case 'j':
		num += 90;
		break;
	default:
		num = num;
	}
	num -= 1; // since the index for an array is 0-99 not 1-100
	return num;
}
