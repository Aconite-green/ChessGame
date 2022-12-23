#include"GamePiece.h"

char* GamePiece::GetColor() {
	return mPieceColor;
}

bool GamePiece::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) {
    GamePiece* qpDest = GameBoard[iDestRow][iDestCol];
    if ((qpDest == 0) || (mPieceColor != qpDest->GetColor())) {
        return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, GameBoard);
    }
    return false;
}

