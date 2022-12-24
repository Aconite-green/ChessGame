#include"PawnPiece.h"


bool PawnPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) {
    GamePiece* qpDest = GameBoard[iDestRow][iDestCol];
    if (qpDest == 0) {
        // Destination square is unoccupied
        if (iSrcCol == iDestCol) {
            if (GetColor() == "w") {
                if (iDestRow == iSrcRow + 1) {
                    return 1;
                }
            }
            else {
                if (iDestRow == iSrcRow - 1) {
                    return 1;
                }
            }
        }
    }
    else {
        // Dest holds piece of opposite color
        if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
            if (GetColor() == "w") {
                if (iDestRow == iSrcRow + 1) {
                    return 1;
                }
            }
            else {
                if (iDestRow == iSrcRow - 1) {
                    return 1;
                }
            }
        }
    }
    return false;
}