#include <iostream>
#include "Tictactoe.h"

using namespace std;

Tictactoe::Tictactoe()
{
    cout << "Tic Tac Toe Console Application" << endl;
    cout << "Two players make move in turn by entering slot number (1-9)" << endl;
    mBoard = {'1','2','3','4','5','6','7','8','9'};
    displayBoard();
    mBoard.fill(' ');
}

void Tictactoe::displayBoard(){
    cout << " " << mBoard[0] << " | " << mBoard[1] << " | " << mBoard[2]  << endl;
    cout << "-----------" << endl;
    cout << " " << mBoard[3] << " | " << mBoard[4] << " | " << mBoard[5]  << endl;
    cout << "-----------" << endl;
    cout << " " << mBoard[6] << " | " << mBoard[7] << " | " << mBoard[8]  << endl;
}

char Tictactoe::getFirstPlayerFromUser(){

    char playerSelection;
    while(1)
    {
        cout << "Which player will make the first move (X,O)? :";
        cin >> playerSelection;

        if (playerSelection == 'X' || playerSelection == 'x'){
            return mPlayerX;
            break;
        }
        else if (playerSelection == 'O' || playerSelection == 'o'){
            return mPlayerO;
            break;
        }
        else{
            cout << "Invalid Player ! Try Again." << endl;
            displayBoard();
            cin.clear();
            cin.ignore(256,'\n');
            continue;
        }
    }
}

void Tictactoe::play(){

    mCurrentPlayer = getFirstPlayerFromUser();
    bool isMoveValid;
    for (int i = 1; i <= mMaxNumberOfMoves; i++)
    {
        isMoveValid = makeMove();
        if (!isMoveValid){
            cout << "Invalid move ! Try Again." << std::endl;
            cin.clear();
            cin.ignore(256,'\n');
            i--;
            continue;
        }
        checkForWin();
        changePlayer();
    }
    draw();

}

bool Tictactoe::makeMove(){

    // return true if user makes a valid move
    int move;
    displayBoard();
    cout << "It is your turn " << mCurrentPlayer << ". Please move (1-9):";
    cin >> move;
    if (!cin.fail() && 1<=move && move<=9 && mBoard[move-1] == ' '){
        mBoard[move-1] = mCurrentPlayer;
        return true;
    }
    return false;

}

void Tictactoe::changePlayer(){
    if (mCurrentPlayer == mPlayerX)
        mCurrentPlayer = mPlayerO;
    else
        mCurrentPlayer = mPlayerX;
}

void Tictactoe::checkForWin(){
    bool isWin = 0;
    // check rows
    if (mBoard[0] != ' ' && mBoard[0] == mBoard[1] && mBoard[1] == mBoard[2]) isWin = 1;
    if (mBoard[3] != ' ' && mBoard[3] == mBoard[4] && mBoard[4] == mBoard[5]) isWin = 1;
    if (mBoard[6] != ' ' && mBoard[6] == mBoard[7] && mBoard[7] == mBoard[8]) isWin = 1;
    // check columns
    if (mBoard[0] != ' ' && mBoard[0] == mBoard[3] && mBoard[3] == mBoard[6]) isWin = 1;
    if (mBoard[1] != ' ' && mBoard[1] == mBoard[4] && mBoard[4] == mBoard[7]) isWin = 1;
    if (mBoard[2] != ' ' && mBoard[2] == mBoard[5] && mBoard[5] == mBoard[8]) isWin = 1;
    //check diagonal
    if (mBoard[0] != ' ' && mBoard[0] == mBoard[4] && mBoard[4] == mBoard[8]) isWin = 1;
    if (mBoard[2] != ' ' && mBoard[2] == mBoard[4] && mBoard[4] == mBoard[6]) isWin = 1;

    if(isWin){
        displayBoard();
        cout << mCurrentPlayer << " has Won !" << endl;
        exit(0);
    }
}

void Tictactoe::draw(){
    displayBoard();
    cout << "It is a DRAW. Nobody won !";
}


