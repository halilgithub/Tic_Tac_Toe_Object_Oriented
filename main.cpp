#include "Tictactoe.h"


int main()
{
	Tictactoe *game = new Tictactoe();
	game->play();
    delete game;
    game = nullptr;
	return 0;
}



