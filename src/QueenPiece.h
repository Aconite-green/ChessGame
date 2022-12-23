#pragma once

#include"GamePiece.h"

class QueenPiece : public GamePiece
{
public:
    QueenPiece(char* PieceColor) : GamePiece(PieceColor) {}
    ~QueenPiece() {}
private:
    virtual char *GetPiece() { return "Q"; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};
