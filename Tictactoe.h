#pragma once

#include <array>

using namespace std;

class Tictactoe {

    public:
        Tictactoe();
        void displayBoard();
        char getFirstPlayerFromUser();
        void play();
        bool makeMove();
        void changePlayer();
        void checkForWin();
        void draw();

    private:
        array<char,9> mBoard;
        const char mPlayerX = 'X';
        const char mPlayerO = 'O';
        const int mMaxNumberOfMoves = 9;
        char mCurrentPlayer;

};
