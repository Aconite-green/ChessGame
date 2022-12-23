#pragma once

#include<iostream>
#include"PawnPiece.h"
#include"RookPiece.h"
#include"BishopPiece.h"
#include"KnightPiece.h"
#include"KingPiece.h"
#include"QueenPiece.h"
#include"winbgi.h"
using namespace std;


class GameBoard
{
public:
    GamePiece* MainGameBoard[8][8];
    
    GameBoard(); 
    ~GameBoard(); 
    
    //print gameboard and pieces
    void Print();
    //check if there is King, and choose the winner
    bool IsInCheck(char* PieceColor);
    //check the validation of piece movements and move
    bool CanMove(char* PieceColor);
};
    

