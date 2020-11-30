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
        void reset();

    private:
        array<char,9> mBoard;
        const char mPlayerX = 'X';
        const char mPlayerO = 'O';
        char mCurrentPlayer;
        const int mMaxNumberOfMoves = 9;

};
