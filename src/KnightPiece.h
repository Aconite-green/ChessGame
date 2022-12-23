#pragma once

#include"GamePiece.h"

class KnightPiece : public GamePiece
{
public:
    KnightPiece(char* PieceColor) : GamePiece(PieceColor) {}
    ~KnightPiece() {}
private:
    virtual char* GetPiece() { return "N"; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};
