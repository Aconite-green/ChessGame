#include"ChessBoard.h"



    void ChessBoard::Start() {
        do {
            GetNextMove(mqGameBoard.MainGameBoard);
            AlternateTurn();
        } while (!IsGameOver());
        mqGameBoard.Print();
    }

    void ChessBoard::GetNextMove(GamePiece* GameBoard[8][8]) {
        bool bValidMove = false;

        

        int offset = 25;
        int gap = 50;
        do {
            
            
            system("clear");
            
            mqGameBoard.Print();
            
           
            WinBGI& win = WinBGI::instance();
            


            // Get input and convert to coordinates
            win.settextstyle(GOTHIC_FONT, GOTHIC_FONT, 1);
            if (mcPlayerTurn == "w") win.setcolor(COLOR_WHITE);
            else win.setcolor(COLOR_BLUE);
            win.outtextxy(57, 600, mcPlayerTurn);
            win.outtextxy(375, 600, "'s Move:(Row)(Column)");
            

            int iStartRow;
            
            //input of Starting Row
            while (1) {
                if (win.kbhit()) {                     
                    iStartRow = win.getch();
                    if (iStartRow == '0') {
                        iStartRow = 0;
                        win.outtextxy(495, 600, "(0)");
                    }
                    else if(iStartRow == '1') {
                        iStartRow = 1;
                        win.outtextxy(495, 600, "(1)");
                    }
                    else if (iStartRow == '2') {
                        iStartRow = 2;
                        win.outtextxy(495, 600, "(2)");
                    }
                    else if (iStartRow == '3') {
                        iStartRow = 3;
                        win.outtextxy(495, 600, "(3)");
                    }
                    else if (iStartRow == '4') {
                        iStartRow = 4;
                        win.outtextxy(495, 600, "(4)");
                    }
                    else if (iStartRow == '5') {
                        iStartRow = 5;
                        win.outtextxy(495, 600, "(5)");
                    }
                    else if (iStartRow == '6') {
                        iStartRow = 6;
                        win.outtextxy(495, 600, "(6)");
                    }
                    else if (iStartRow == '7') {
                        iStartRow = 7;
                        win.outtextxy(495, 600, "(7)");
                    }
                    else {
                        win.setcolor(COLOR_RED);
                        win.outtextxy(300, 175, "Type:0~7");
                        continue;
                    }
                    break;
                }
                win.delay(100);                       // 100ms¸¦ ¸ØÃã   
            }

            int iStartCol;

            //input of Starting Column
            while (1) {
                if (win.kbhit()) {                     // Å°º¸µå ÀÔ·Â¿©ºÎ 
                    iStartCol = win.getch();
                    if (iStartCol == '0') {
                        iStartCol = 0;
                        win.outtextxy(545, 600, "(0)");
                    }
                    else if (iStartCol == '1') {
                        iStartCol = 1;
                        win.outtextxy(545, 600, "(1)");
                    }
                    else if (iStartCol == '2') {
                        iStartCol = 2;
                        win.outtextxy(545, 600, "(2)");
                    }
                    else if (iStartCol == '3') {
                        iStartCol = 3;
                        win.outtextxy(545, 600, "(3)");
                    }
                    else if (iStartCol == '4') {
                        iStartCol = 4;
                        win.outtextxy(545, 600, "(4)");
                    }
                    else if (iStartCol == '5') {
                        iStartCol = 5;
                        win.outtextxy(545, 600, "(5)");
                    }
                    else if (iStartCol == '6') {
                        iStartCol = 6;
                        win.outtextxy(545, 600, "(6)");
                    }
                    else if (iStartCol == '7') {
                        iStartCol = 7;
                        win.outtextxy(545, 600, "(7)");
                    }
                    else {
                        win.setcolor(COLOR_RED);
                        win.outtextxy(300, 175, "Type:0~7");
                        continue;
                    }
                    break;
                }
                win.delay(100);                       
            }
 
            
            

            win.outtextxy(270, 625, "To:(Row)(Column)");

            int iEndRow;
            //input of destination row
            while (1) {
                if (win.kbhit()) {                     
                    iEndRow = win.getch();
                    if (iEndRow == '0') {
                        iEndRow = 0;
                        win.outtextxy(495, 625, "(0)");
                    }
                    else if (iEndRow == '1') {
                        iEndRow = 1;
                        win.outtextxy(495, 625, "(1)");
                    }
                    else if (iEndRow == '2') {
                        iEndRow = 2;
                        win.outtextxy(495, 625, "(2)");
                    }
                    else if (iEndRow == '3') {
                        iEndRow = 3;
                        win.outtextxy(495, 625, "(3)");
                    }
                    else if (iEndRow == '4') {
                        iEndRow = 4;
                        win.outtextxy(495, 625, "(4)");
                    }
                    else if (iEndRow == '5') {
                        iEndRow = 5;
                        win.outtextxy(495, 625, "(5)");
                    }
                    else if (iEndRow == '6') {
                        iEndRow = 6;
                        win.outtextxy(495, 625, "(6)");
                    }
                    else if (iEndRow == '7') {
                        iEndRow = 7;
                        win.outtextxy(495, 625, "(7)");
                    }
                    else {
                        win.setcolor(COLOR_RED);
                        win.outtextxy(300, 175, "Type:0~7");
                        continue;
                    }
                    break;
                }
                win.delay(100);                       
            }


            int iEndCol;
            //input of destination column
            while (1) {
                if (win.kbhit()) {                     
                    iEndCol = win.getch();
                    if (iEndCol == '0') {
                        iEndCol = 0;
                        win.outtextxy(545, 625, "(0)");
                    }
                    else if (iEndCol == '1') {
                        iEndCol = 1;
                        win.outtextxy(545, 625, "(1)");
                    }
                    else if (iEndCol == '2') {
                        iEndCol = 2;
                        win.outtextxy(545, 625, "(2)");
                    }
                    else if (iEndCol == '3') {
                        iEndCol = 3;
                        win.outtextxy(545, 625, "(3)");
                    }
                    else if (iEndCol == '4') {
                        iEndCol = 4;
                        win.outtextxy(545, 625, "(4)");
                    }
                    else if (iEndCol == '5') {
                        iEndCol = 5;
                        win.outtextxy(545, 625, "(5)");
                    }
                    else if (iEndCol == '6') {
                        iEndCol = 6;
                        win.outtextxy(545, 625, "(6)");
                    }
                    else if (iEndCol == '7') {
                        iEndCol = 7;
                        win.outtextxy(545, 625, "(7)");
                    }
                    else {
                        win.setcolor(COLOR_RED);
                        win.outtextxy(300, 175, "Type:0~7");
                        continue;
                    }
                    break;
                }
                win.delay(250);                       // 100ms¸¦ ¸ØÃã   
            }



            // Check that the indices are in range
            // and that the source and destination are different
            if ((iStartRow >= 0 && iStartRow <= 7) &&
                (iStartCol >= 0 && iStartCol <= 7) &&
                (iEndRow >= 0 && iEndRow <= 7) &&
                (iEndCol >= 0 && iEndCol <= 7)) {
                // Additional checks in here
                GamePiece* qpCurrPiece = GameBoard[iStartRow][iStartCol];
                // Check that the piece is the correct color
                if ((qpCurrPiece != 0) && (qpCurrPiece->GetColor() == mcPlayerTurn)) {
                    
                    // Check that the destination is a valid destination
                    if (qpCurrPiece->IsLegalMove(iStartRow, iStartCol, iEndRow, iEndCol, GameBoard)) {
                        // Make the move
                        GamePiece* qpTemp = GameBoard[iEndRow][iEndCol];
                        GameBoard[iEndRow][iEndCol] = GameBoard[iStartRow][iStartCol];
                        GameBoard[iStartRow][iStartCol] = 0;
                        // Make sure that the current player is not in check
                        
                        if (!mqGameBoard.IsInCheck(mcPlayerTurn)) {
                            delete qpTemp;
                            bValidMove = true;
                        }
                        else { // Undo the last move
                            GameBoard[iStartRow][iStartCol] = GameBoard[iEndRow][iEndCol];
                            GameBoard[iEndRow][iEndCol] = qpTemp;
                        }
                        if (mqGameBoard.IsInCheck(mcPlayerTurn)) {
                            AlternateTurn();
                            win.delay(1000);
                            win.setcolor(COLOR_GREEN);
                            win.settextstyle(SANSSERIF_FONT, HORIZ_DIR, 6);
                            win.outtextxy(50, 300, "Checkmate");
                            win.outtextxy(375, 300, mcPlayerTurn);
                            win.outtextxy(500, 300, "Wins!");
                            win.delay(999999);
                        }
                        
                    }
                }
            }
            if (!bValidMove) {
                win.cleardevice();
                win.outtextxy(400, 400, "Ivalid move!!");
                win.delay(500);
            }
        } while (!bValidMove);
    }

    void ChessBoard::AlternateTurn() {
        mcPlayerTurn = (mcPlayerTurn == "w") ? "b" : "w";
    }

    bool ChessBoard::IsGameOver() {
        // Check that the current player can move
        // If not, we have a stalemate or checkmate
        bool bCanMove(false);
        bCanMove = mqGameBoard.CanMove(mcPlayerTurn);
        WinBGI& win = WinBGI::instance();
        
        if (!bCanMove) {
            if (mqGameBoard.IsInCheck(mcPlayerTurn)) {
                AlternateTurn();
                win.cleardevice();
                win.outtextxy(150, 300, "Checkmate");
                win.outtextxy(300, 300, mcPlayerTurn);
                win.outtextxy(450, 300, "Wins!");
                win.delay(999999);
            }
            else {
                win.cleardevice();
                win.outtextxy(300, 300, "Stalemate!");
                win.delay(500);             
            }
        }
        return !bCanMove;
    }
