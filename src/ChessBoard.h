#pragma once

#include<iostream>
#include"GamePiece.h"
#include"GameBoard.h"
#include"winbgi.h"
using namespace std;

class ChessBoard
{
public:
    //initialize the start user(white)
    ChessBoard() : mcPlayerTurn("w") {}
    ~ChessBoard() {}

    //run the game
    void Start();
    //get user input and change the loacation of the pieces
    void GetNextMove(GamePiece* GameBoard[8][8]);
    //change the turn of black(printed in blue color) and white
    void AlternateTurn();
    //stop the screen and ends the game
    bool IsGameOver();
private:
    GameBoard mqGameBoard;
    char* mcPlayerTurn;
};
