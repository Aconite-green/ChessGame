#pragma once

#include"GamePiece.h"

class KingPiece : public GamePiece
{
public:
    KingPiece(char* PieceColor) : GamePiece(PieceColor) {}
    ~KingPiece() {}
private:
    virtual char* GetPiece() { return "K"; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};
