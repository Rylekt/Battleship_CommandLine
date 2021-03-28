//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board
{
public:
	// Setting Enums
	enum class EnemyPiece { HIT, MISS, EMPTY };
	enum class PlayerPiece { AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY };

	// Move Struct
	typedef struct Move {
		char letter;
		int num;
	};

	// Constructor, Reset and Destructor
	Board();
	virtual ~Board();
	void reset() noexcept;

	// Other Functionality
	void display(int player) const noexcept;        // Takes in a player int and returns void
	EnemyPiece makeMove(const Move &m, int player); // Takes in a move and a player int and returns an EnemyPiece
	bool isLegal(Board::Move move, int player);     // Takes in a move and a player int and returns a bool
	int convertMoveToInt(Move move);                // Takes in a move and returns an int

    /// <summary> check if what is at the location check in the enemy board for the appropriate player
    /// <return> EnemyPiece
	EnemyPiece getEnemyBoard(int player, int check)
	{
		if (player == 1)
			return Enemy1Board[check];
		else
			return Enemy2Board[check];
	}


private:
	// Player 1 Boards
	PlayerPiece Player1Board[100];
	EnemyPiece Enemy1Board[100];

	// Player 2 Boards
	PlayerPiece Player2Board[100];
	EnemyPiece Enemy2Board[100];
};

#endif // BOARD_H
