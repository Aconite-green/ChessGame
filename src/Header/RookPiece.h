#pragma once

#include"GamePiece.h"


class RookPiece : public GamePiece
{
public:
    RookPiece(char* PieceColor) : GamePiece(PieceColor) {}
    ~RookPiece() {}
private:
    virtual char* GetPiece() { return "R"; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};