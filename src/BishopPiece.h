#pragma once

#include"GamePiece.h"

class BishopPiece : public GamePiece
{
public:
    BishopPiece(char* PieceColor) : GamePiece(PieceColor) {}
    ~BishopPiece() {}
private:
    virtual char* GetPiece() { return "B"; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};
