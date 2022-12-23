#include"GameBoard.h"


    GameBoard::GameBoard() {
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                MainGameBoard[iRow][iCol] = 0;
            }
        }
        // Allocate and place black pieces
        for (int iCol = 0; iCol < 8; ++iCol) {
            MainGameBoard[6][iCol] = new PawnPiece("b");
        }
        MainGameBoard[7][0] = new RookPiece("b");
        MainGameBoard[7][1] = new KnightPiece("b");
        MainGameBoard[7][2] = new BishopPiece("b");
        MainGameBoard[7][3] = new KingPiece("b");
        MainGameBoard[7][4] = new QueenPiece("b");
        MainGameBoard[7][5] = new BishopPiece("b");
        MainGameBoard[7][6] = new KnightPiece("b");
        MainGameBoard[7][7] = new RookPiece("b");
        // Allocate and place white pieces
        for (int iCol = 0; iCol < 8; ++iCol) {
            MainGameBoard[1][iCol] = new PawnPiece("w");
        }
        MainGameBoard[0][0] = new RookPiece("w");
        MainGameBoard[0][1] = new KnightPiece("w");
        MainGameBoard[0][2] = new BishopPiece("w");
        MainGameBoard[0][3] = new KingPiece("w");
        MainGameBoard[0][4] = new QueenPiece("w");
        MainGameBoard[0][5] = new BishopPiece("w");
        MainGameBoard[0][6] = new KnightPiece("w");
        MainGameBoard[0][7] = new RookPiece("w");
    }
    
    GameBoard::~GameBoard() {
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                delete MainGameBoard[iRow][iCol];
                MainGameBoard[iRow][iCol] = 0;
            }
        }
    }

    void GameBoard::Print() {
        //Print the chess board(without pieces)
        WinBGI& win = WinBGI::instance();
        win.cleardevice();
        win.setcolor(COLOR_WHITE);
        int offset = 150;
        int gap = 50;

        for (int y = 0; y < 9; y++) {
            win.line(offset, y * gap + offset, offset + 8 * gap, y * gap + offset);
        }
        
        for (int x = 0; x < 9; x++) {
            win.line(x * gap + offset, offset, x * gap + offset, offset + 8 * gap);
        }
        //Print numbers on side
        win.outtextxy(125, offset + 40, "0");
        win.outtextxy(125, offset + 40 + gap*1, "1");
        win.outtextxy(125, offset + 40 + gap*2, "2");
        win.outtextxy(125, offset + 40 + gap*3, "3");
        win.outtextxy(125, offset + 40 + gap*4, "4");
        win.outtextxy(125, offset + 40 + gap*5, "5");
        win.outtextxy(125, offset + 40 + gap*6, "6");
        win.outtextxy(125, offset + 40 + gap*7, "7");

        win.outtextxy(offset+20, 120, "0");
        win.outtextxy(offset + 20 + gap*1, 120, "1");
        win.outtextxy(offset + 20 + gap * 2, 120, "2");
        win.outtextxy(offset + 20 + gap * 3, 120, "3");
        win.outtextxy(offset + 20 + gap * 4, 120, "4");
        win.outtextxy(offset + 20 + gap * 5, 120, "5");
        win.outtextxy(offset + 20 + gap * 6, 120, "6");
        win.outtextxy(offset + 20 + gap * 7, 120, "7");
       
        win.settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
        
        //Print pieces on chessboard
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8 ; ++iCol) {
                if (MainGameBoard[iRow][iCol] != 0) {
                    if (MainGameBoard[iRow][iCol]->GetColor() == "b") {
                        win.setcolor(COLOR_BLUE);
                        win.outtextxy(offset + 15 + gap * iCol, offset + 14 + gap * iRow, MainGameBoard[iRow][iCol]->GetPiece());
                        win.circle(offset + 25 + gap * iCol, offset + 25 + gap*iRow, 22);
                    }
                    else {
                        win.setcolor(COLOR_WHITE);
                        win.outtextxy(offset + 15 + gap * iCol, offset + 14 + gap * iRow, MainGameBoard[iRow][iCol]->GetPiece());
                        win.circle(offset + 25 + gap * iCol, offset + 25 + gap * iRow, 22);
                    }
                }   
            }   
        }
        
        
    }

    bool GameBoard::IsInCheck(char* PieceColor) {
        // Find the king
        int iKingRow;
        int iKingCol;
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                if (MainGameBoard[iRow][iCol] != 0) {
                    if (MainGameBoard[iRow][iCol]->GetColor() == PieceColor) {
                        if (MainGameBoard[iRow][iCol]->GetPiece() == "K") {
                            iKingRow = iRow;
                            iKingCol = iCol;
                        }
                    }
                }
            }
        }
        // Run through the opponent's pieces and see if any can take the king
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                if (MainGameBoard[iRow][iCol] != 0) {
                    if (MainGameBoard[iRow][iCol]->GetColor() != PieceColor) {
                        if (MainGameBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iKingRow, iKingCol, MainGameBoard)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool GameBoard::CanMove(char* PieceColor) {
        // Run through all pieces
        for (int iRow = 0; iRow < 8; ++iRow) {
            for (int iCol = 0; iCol < 8; ++iCol) {
                if (MainGameBoard[iRow][iCol] != 0) {
                    // If it is a piece of the current player, see if it has a legal move
                    if (MainGameBoard[iRow][iCol]->GetColor() == PieceColor) {
                        for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow) {
                            for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol) {
                                if (MainGameBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, MainGameBoard)) {
                                    // Make move and check whether king is in check
                                    GamePiece* qpTemp = MainGameBoard[iMoveRow][iMoveCol];
                                    MainGameBoard[iMoveRow][iMoveCol] = MainGameBoard[iRow][iCol];
                                    MainGameBoard[iRow][iCol] = 0;
                                    bool bCanMove = !IsInCheck(PieceColor);
                                    // Undo the move
                                    MainGameBoard[iRow][iCol] = MainGameBoard[iMoveRow][iMoveCol];
                                    MainGameBoard[iMoveRow][iMoveCol] = qpTemp;
                                    if (bCanMove) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

