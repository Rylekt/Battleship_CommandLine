//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "Game.h"

Game::Game()
{
	player1 = nullptr;
	player2 = nullptr;

}

/// <summary> Have the players defined with a name and their appropriate types
void Game::selectPlayers() {
	std::cout << "Welcome to battle ship! \n";
	char type;
	std::string name;
        // ----------------------- Define Player 1 ---------------------------------------
		std::cout << "Please input your character type (h = human / c = computer): ";
		std::cin >> type; // define the type of the first player
		if (type == 'h') {
			std::cout << "Enter players name: \n"; // define the human's name
			std::cin >> name;
			player1 = new HumanPlayer(name, 1);
			std::cout << "Welcome " << player1->getName() << "!\n";

		}
		else {
			player1 = new RandomPlayer("Computer ", 1);
			std::cout << "Welcome " << player1->getName() << "!\n"; // Name is automatically generated
		}

        // ----------------------- Define Player 2 ---------------------------------------
		std::cout << "Please input your character type (h = human / c = computer): ";
		std::cin >> type; // define the type of the second player
		if (type == 'h') {
			std::cout << "Enter players name: \n"; // define human's name
			std::cin >> name;
			player2 = new HumanPlayer(name, 2);
			std::cout << "Welcome " << player2->getName() << "!\n";

		}
		else {
			player2 = new RandomPlayer("Computer ", 2);
			std::cout << "Welcome " << player2->getName() << "!\n"; // Name is automatically generated

		}

}

/// <summary> Switches the pointer of the current Player
/// <return> Player pointer
Player* Game::nextPlayer(Player *p) const {
	int pID = p->changePlayer();
	if (pID == 1) { // if playerID is 1
		p = player1;
		return p;
	}
	else { // if playerID is 2
		p = player2;
		return p;
	}
}

/// <summary> Checks to see if either player has had each ship hit
bool Game::isRunning() {
	int countp1 = 0, countp2 = 0; // counters for each player
	for (int i = 0; i < 100; ++i) { // go through each player's board and see how many each player has hit
		if (board1.getEnemyBoard(1,i) == Board::EnemyPiece::HIT) {
			++countp1;
		}
		if (board1.getEnemyBoard(2, i) == Board::EnemyPiece::HIT) {
			++countp2;
		}
	}
	if (countp1 == 17 || countp2 == 17) // If the game is no longer running
		return false;
	else
		return true;

}

/// <summary> Initial game
/// <return> Void
void Game::play() {
	Board::Move m;
	std::string p1name = player1->getName();
	std::string p2name = player2->getName();

	while (isRunning()){  // while the game is not done
		board1.display(1); // show the first player's board
		m = player1->makeMove(board1,1);
		board1.makeMove(m, 1);
		std::cout << "\n\n\n______________________" << p2name <<  "'s TURN____________________________________\n\n\n";
		board1.display(2);
		m = player2->makeMove(board1,2);
		board1.makeMove(m, 2);
		std::cout << "\n\n\n______________________" << p1name <<  "'s TURN____________________________________\n\n\n";
	}

}

/// <summary> Print to screen who the winning player is
void Game::announceWinner()
{
	int countp1 = 0, countp2 = 0;
	for (int i = 0; i < 100; ++i) {
		if (board1.getEnemyBoard(1, i) == Board::EnemyPiece::HIT) {
			++countp1;
		}
		if (board1.getEnemyBoard(2, i) == Board::EnemyPiece::HIT) {
			++countp2;
		}
	}
	if (countp1 == 17) {
		std::cout << "CONGRATULATIONS "<< player1->getName() << " YOU WIN!!!!";
	}
	else if (countp2 == 17) {
		std::cout << "CONGRATULATIONS "<< player2->getName() << " YOU WIN!!!!";
	}

}

Game::~Game()
{
}
