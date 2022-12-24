#pragma once

class GamePiece
{
private:
    virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) = 0;
    char* mPieceColor;
public:
    //initialize the color of the pices
    GamePiece(char* PieceColor) : mPieceColor(PieceColor) {}
    ~GamePiece() {}
    
    //return the name of the piece(ex King -> "K")
    virtual char* GetPiece() = 0;
    //return the color(blak or white)of the piece
    char* GetColor();
    //return the result(true/false) of user input validation with each pieces movement 
    bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};
