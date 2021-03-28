//----------------------------------------
// Project 2
// Austin Lawrence & Riley Stewart-Tonkin
// December 4, 2019
//----------------------------------------

#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Board board1;           // Initialize the board
    Game game1;             // Initialize the game
    game1.selectPlayers();  // Select the players and player types
    game1.play();           // Play the game
    game1.announceWinner();
    return 0;
}
