//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(const std::string &Name, int num) : ComputerPlayer{ Name, num } {}

/// <summary> Randomly generates a char and number using 2 Mersenne Twister seeds
/// <return> Move Struct defined in Board.h
Board::Move RandomPlayer::makeMove(Board &b, int player) {
	int check, num;
	char letter;
	Board::Move m;
	int i = 0;
    // ----------------------Char Random----------------------------------------------
    // Initialize our Character's Mersenne Twister with a random seed based on the clock
    std::mt19937 CharMersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution<int> charRand{ 97, 106 };
    letter = static_cast<char>(charRand(CharMersenne));

    // ----------------------Num Random----------------------------------------------
    // Initialize our Number's Mersenne Twister with a random seed based on the clock
    std::mt19937 NumMersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution<int> numRand{ 1, 10 };

	do {
        if((i%10) == 0 && letter != 'j') // if every iteration of row letter, go to the next letter
            ++letter;
        else if((i%10) == 0 && letter == 'j') // if at the end of letter list, start over
            letter = 'a';


        m.letter = letter;             // Set the letter in move to the randomly generated letter
        m.num = numRand(NumMersenne);  // Set the num in move to the randomly generated number
        check = b.convertMoveToInt(m); // Change it to an array access for the check
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Reset the randomization
		std::cout << "Tried " << i << " at spot " << m.letter << m.num << " which is array point " << check <<'\n';
		++i;
	} while (b.getEnemyBoard(player, check) != Board::EnemyPiece::EMPTY); // while there is not an empty and the move is legal
	return m;
}
