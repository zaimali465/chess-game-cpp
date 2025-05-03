
#include <iostream>
#include <io.h>  // Provides the necessary functions e.g _setmode()
#include <fcntl.h>  // Specifies that the output should be in UTF-8 format.
#include "chess.h"
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
using namespace CHESS;

wstring player1, player2; int r = 0;
wstring playerW = L"White";
wstring playerB = L"Black";

void drawBoard(wstring player1, wstring player2)
{
    system("cls");
  // wcout << "\n\n\t\t\t\t\t\t\t      " << "============== CHESS ==============\n\n";
    wcout << "\n\n\n\t\t\t\t\t\t\t\t"<<"Player 2 ("<< player2<<") " << endl;
    wcout << "\t\t   _____ _    _ ______  _____ _____      \t" << "  a   b   c   d   e   f   g   h   \n";
    // Draw top border
    //wcout << "\t\t\t\t\t\t\t" << setw(8);
    wcout << "\t\t  / ____| |  | |  ____|/ ____/ ____|          ";
    wcout << L"  " << topLeft;
    for (int i = 0; i < 8; ++i) {
        wcout << horizontal << horizontal << horizontal;
        if (i < 7) wcout << topJoin;
    }
    wcout << topRight << endl;

  //  wcout << "\t\t   _____ _    _ ______  _____ _____" << setw(2);
   

    // Draw the chessboard rows
    for (int i = 0; i < 8; ++i) {
       if (i == 0)
            wcout << "\t\t | |    | |__| | |__  | (___| (___  " << setw(2);
        if (i == 1)
            wcout << "\t\t | |____| |  | | |____ ____) |___) | " << setw(1);
        if (i == 2)
            wcout << "\t\t\t\t\t\t    ";
        if (i == 3)
            wcout << "\t\t\t\t\t\t";
        if (i == 4)
            wcout << "\t\t\t\t\t\t";
        if (i == 5)
            wcout << "\t\t Knights " << L'\u265E' << "  weave cunning traps      ";
        if (i == 6)
            wcout << "\t\t Will you conquer—or be conquered?     ";
        if (i == 7)
            wcout << "\t\t  "<< L'\u2694' << "  lets Play ..!                  ";
        // Display row number and pieces
        wcout << L"\t " << setw(7) << (8 - i) << vertical;

        for (int j = 0; j < 8; ++j) {
            wcout << L" " << board[i][j] << L" " << vertical;
        }
        wcout << endl;
      
        if (i == 0)
            wcout << "\t\t | |    |  __  |  __|  \\___  \\___ \\ " << setw(1);
        if (i == 1)
            wcout << "\t\t  \\_____|_|  |_|______|_____/_____/ " << setw(1);
        if (i == 2)
            wcout << "\t\t\t      AMBER ASKHAB (BSCS-1) ";
        if (i == 3)
            wcout << " \t\t WELCOME TO MY GAME " << L"\U0001F917" << "              ";
        if (i == 4)
            wcout << "\t\t pawns " << L'\u265F' << "  dream of crowns           ";
        if (i == 5)
            wcout << "\t\t kings " << L'\u265A' << "  trembles in check.        ";
        if (i == 6)
            wcout << "\t\t\t\t\t            ";
        if (i == 7)
            wcout << "\t\t\t\t\t       ";
        // Draw horizontal lines between rows
        if (i < 7) {
            wcout << setw(13) << leftJoin;
            for (int j = 0; j < 8; ++j) {
                wcout << horizontal << horizontal << horizontal;
                if (j < 7) wcout << crossJoin;
            }
            wcout << rightJoin << endl;
        }
    }

    // Draw bottom border
    wcout << setw(18) << bottomLeft;
    for (int i = 0; i < 8; ++i) {
        wcout << horizontal << horizontal << horizontal;
        if (i < 7) wcout << bottomJoin;
    }
    wcout << bottomRight << endl;
    wcout << "\t\t\t \t\t\t                  a   b   c   d   e   f   g   h  \n";
    wcout << "\t\t\t\t\t\t\t\t" << "Player 1 (" << player1 << ") " << endl;
}
void drawBoard_(wstring player1, wstring player2)
{
    system("cls");
    _setmode(_fileno(stdout), _O_U16TEXT);  // Enable UTF-8 output mode

    wcout << "\n\t\t \t     " << "==============" << L'\u265F' << " CHESS" << " ============== \n\n";
    wcout << "\t\t\t\t" << "Player 2 (" << player2 << ") " << endl;
    wcout << "\t\t\t\t" << "  a   b   c   d   e   f   g   h  \t\t   \n";

    // Draw top border
    wcout << "\t\t\t" << setw(8);
    wcout << L"  " << topLeft;
    for (int i = 0; i < 8; ++i) {
        wcout << horizontal << horizontal << horizontal;
        if (i < 7) wcout << topJoin;
    }
    
    wcout << topRight<<endl ;

    // Draw the chessboard rows
    for (int i = 0; i < 8; ++i) {
        // Display row number and pieces
        wcout << L"\t\t\t " << setw(7) << (8 - i) << vertical;

        for (int j = 0; j < 8; ++j) {
            wcout << L" " << board[i][j] << L" " << vertical;
        }
        wcout << endl;

        // Draw horizontal lines between rows
        if (i < 7) {
            wcout <<"\t\t"<< setw(17) << leftJoin;
            for (int j = 0; j < 8; ++j) {
                wcout << horizontal << horizontal << horizontal;
                if (j < 7) wcout << crossJoin;
            }
            wcout << rightJoin << endl;
        }
    }

    // Draw bottom border
    wcout <<"\t\t"<< setw(17) << bottomLeft;
    for (int i = 0; i < 8; ++i) {
        wcout << horizontal << horizontal << horizontal;
        if (i < 7) wcout << bottomJoin;
    }
    wcout << bottomRight << endl;
    wcout << "\t\t\t\t" << "Player 1 (" << player1 << ") \n\n" << endl;
}
void tossing(wstring &playerW,wstring &playerB)
{
    wcout << "\t\t 1.TOSSING \n";
    wcout << "\t\t Enter Name Of Player 1: ";
    wcin >> player1;
    wcout << "\t\t Enter Name Of Player 2: ";
    wcin >> player2;

    int toss = rand() % 2;
    if (toss == 0) {
        wcout << "\t\t PLAYER 1 WON! " << player1 << " goes first.\n\n";
        playerW = player1; playerB = player2;
    }
    else {
        wcout << "\t\t PLAYER 2 WON! " << player2 << " goes first.\n\n";
        playerW = player2; playerB = player1;
    }
   system("pause");
    drawBoard_(playerW, playerB);
}

bool isvalid_format(string mov)
{
    // Check if the length is within a valid range (2 to 4 characters)
    if (mov.length() < 2 || mov.length() > 4)
        return false;

    // Case 1: Pawn move (e.g., "e4")
    if (mov.length() == 2)
    {
        if (mov[0] >= 'a' && mov[0] <= 'h' && mov[1] >= '1' && mov[1] <= '8')
            return true;
    }
    // Case 2: Piece move (e.g., "Ne4", "Bb5")
    else if (mov.length() == 3)
    {
        if ((mov[0] == 'K' || mov[0] == 'Q' || mov[0] == 'R' || mov[0] == 'B' || mov[0] == 'N') &&
            (mov[1] >= 'a' && mov[1] <= 'h') &&
            (mov[2] >= '1' && mov[2] <= '8'))
            return true;
    }
    // Case 3: Capture move (e.g., "Nxe4", "Qxh5")
    else if (mov.length() == 4)
    {
        if ((mov[0] == 'K' || mov[0] == 'Q' || mov[0] == 'R' || mov[0] == 'B' || mov[0] == 'N' || (mov[0] >= 'a' && mov[0] <= 'h')) &&
            (mov[1] == 'x') &&
            (mov[2] >= 'a' && mov[2] <= 'h') &&
            (mov[3] >= '1' && mov[3] <= '8'))
            return true;
    }

    return false;
}

bool updateboard(int torow, int tocol, int fromrow, int fromcol, wchar_t piece)
{
    if (board[fromrow][fromcol] == piece)
    {
        board[torow][tocol] = piece;
        board[fromrow][fromcol] = emptyspace;
        drawBoard_(playerW, playerB);
        lastcol = tocol;
        lastrow = torow;
        return true;
    }
    else
        return false;

}
bool isvalid_move(wstring player, string mov);
bool isCapturingSquare(wstring player, int torow, int tocol, vector<pair<int, int>>& nonBlockedPieces, int& cap_flag,int nflag);
bool ischeck(wstring player, int& noOfAttackingPieces)
{
    vector<pair<int, int>> attackingPieces;
    vector<pair<int, int>> empty_squares;
    int capflag = 0,nflag=1;
    int kingRow = (player == playerW) ? lastrow_wK : lastrow_bK;
    int kingCol = (player == playerW) ? lastcol_wK : lastcol_bK;
    if (isCapturingSquare(player, kingRow, kingCol, attackingPieces, capflag,nflag))
    {
        noOfAttackingPieces = attackingPieces.size();
        return true;
    }
    else
        return false;
}

bool isValidPosition(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}
bool is_path_blocked(int torow, int tocol, int fromrow, int fromcol, int flag, vector<pair<int, int>>& emptyspaces)
{
    int row_diff = 0, rowstep = 0;
    int col_diff = 0, colstep = 0;
    bool blockedpiece = false;

    row_diff = torow - fromrow;
    col_diff = tocol - fromcol;

    if (row_diff > 0) rowstep = 1;
    else if (row_diff < 0) rowstep = -1;

    if (col_diff < 0) colstep = -1;
    else if (col_diff > 0) colstep = 1;



    int crow = fromrow + rowstep;
    int ccol = fromcol + colstep;
    while (crow != torow || ccol != tocol)
    {
        if (flag == 0)
        {
            if (board[crow][ccol] == emptyspace && (board[fromrow][fromcol] != whiteKnight && board[fromrow][fromcol] != blackKnight))
            {
                emptyspaces.push_back({ crow,ccol });
            }
            else
            {
                return false;
            }
        }
        else
            if (board[crow][ccol] != emptyspace)
            {
                return true;
            }
        crow += rowstep;
        ccol += colstep;
    }
    return false;
}
void initial_position(wstring player, string mov, int& fromrow, int& fromcol, bool& validmove, wchar_t& piece, bool& blocking_piece)
{
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int flag = 1;
    vector<pair<int, int>>emptyspace;
    vector<pair<int, int>>validPieces;
    vector<pair<int, int>>nonBlockedpieces;

    const int validMoves[56][2] = {
        // Rook and Queen moves (horizontal and vertical)
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7},
        {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7},
        {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0},
        {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0},
        // Bishop and Queen moves (diagonal)
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7},
        {-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7},
        {1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7},
        {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}
    };
    const int knightMoves[8][2] = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };
    const int kingMoves[8][2] = { {0,-1},{0,1},{1,0},{-1,0},{-1,1},{1,1},{-1,-1},{1,-1} };

    //Finding number of pieces  targeting the respected square 

    if (piece == whiteRook || piece == blackRook || piece == whiteQueen || piece == blackQueen)
    {
        for (int i = 0; i < 56; i++) {
            int R = torow + validMoves[i][0];
            int C = tocol + validMoves[i][1];
            if (isValidPosition(R, C) && (board[R][C] == piece)) {
                validPieces.push_back({ R, C });
            }
        }
    }
    else if (piece == whiteBishop || piece == blackBishop)
    {
        for (int i = 28; i < 56; i++)
        {
            int R = torow + validMoves[i][0];
            int C = tocol + validMoves[i][1];
            if (isValidPosition(R, C) && (board[R][C] == piece)) {
                validPieces.push_back({ R, C });
            }
        }
    }
    else if (piece == whiteKnight || piece == blackKnight)
    {
        for (int i = 0; i < 8; i++) {
            int R = torow + knightMoves[i][0];
            int C = tocol + knightMoves[i][1];
            if (isValidPosition(R, C) && (board[R][C] == piece))
            {
                validPieces.push_back({ R, C });
            }
        }
    }
    else if (piece == whiteKing || piece == blackKing)
    {
        for (int i = 0; i < 8; i++) {
            int R = torow + kingMoves[i][0];
            int C = tocol + kingMoves[i][1];
            if (isValidPosition(R, C) && (board[R][C] == piece))
            {
                validPieces.push_back({ R, C });
            }
        }
    }

    for (int i = 0; i < validPieces.size(); i++)
    {
        int nfromrow = validPieces[i].first;
        int nfromcol = validPieces[i].second;
        if (piece == whiteKnight || piece == blackKnight || piece == whiteKing || piece == whiteKing)
        {
            blocking_piece = false;
        }
        else
        {
            blocking_piece = is_path_blocked(torow, tocol, nfromrow, nfromcol, flag, emptyspace);
        }
        if (!blocking_piece)
        {
            nonBlockedpieces.push_back({ nfromrow, nfromcol });
            continue;
        }
    }

    if (nonBlockedpieces.size() == 1)
    {
        fromrow = nonBlockedpieces[0].first;
        fromcol = nonBlockedpieces[0].second;
        validmove = true;
    }
    else
        if (nonBlockedpieces.size() > 1)
        {
            wstring choice;
            wcout << "\n\t\t\t\tMultiple " << piece << " S are targeting this square.\n";
            do
            {
                wcout << "\t\t\t\tPlease enter the coordinate of " << piece << "  you want to move(d6) :   ";
                wcin >> choice;
                fromcol = choice[0] - 'a';
                fromrow = '8' - choice[1];
            } while (board[fromrow][fromcol] != piece);
            validmove = true;
        }
}

bool pawn_movement(wstring player, string mov)
{
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int pawn_validmoves[4][2]; bool updated = false; int validrow, valid_first;  wchar_t pawn;
    int noOfAttackingPieces = 0;
    if (player == playerW)
    {
        pawn = whitePawn;
        validrow = 6; valid_first = torow + 2;
        int temp[4][2] = { {2,0},{1,0},{1,-1},{1,1} };
        memcpy(pawn_validmoves, temp, sizeof(temp));// copying the data from one memory to other void *memcpy(void *destination, const void *source, size_t num);
    }
    else
    {
        pawn = blackPawn;
        validrow = 1; valid_first = torow - 2;
        int  temp[4][2] = { {-2,0},{-1,0},{-1,-1},{-1,1} };
        memcpy(pawn_validmoves, temp, sizeof(temp));
    }

    bool first_time = (valid_first == validrow) ? true : false;
    if (mov.length() == 2)
    {
        if (first_time)
        {
            for (int i = 0; i < 2; i++)
            {
                int R = torow + pawn_validmoves[i][0];
                int C = tocol + pawn_validmoves[i][1];
                if ((board[R][C] == pawn) && (board[torow][tocol] == emptyspace))
                {
                    if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, R, C, pawn);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, R, C, pawn);
                    break;
                }
            }
        }
        else
        {
            int R = torow + pawn_validmoves[1][0];
            int C = tocol + pawn_validmoves[1][1];
            if (board[R][C] == pawn && (board[torow][tocol] == emptyspace))
            {
               if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                    updated = updateboard(torow, tocol, R, C, pawn);
                else if (!ischeck(player, noOfAttackingPieces))
                    updated = updateboard(torow, tocol, R, C, pawn);
            }
        }
    }
    else
        if (mov.length() == 4)
        {
            for (int i = 2; i < 4; i++)
            {
                int R = torow + pawn_validmoves[i][0];
                int C = tocol + pawn_validmoves[i][1];

                if (board[R][C] == pawn && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
                {
                   if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, R, C, pawn);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, R, C, pawn);
                    break;
                }
            }
        }

    // if updated check for the pawn promotion
    if (updated)
    {
        if ((player == playerW && torow == 0) || (player == playerB && torow == 7))
        {
            wchar_t queen, rook, knight, bishop; int valid_capture;
            if (player == playerW)
            {
                queen = whiteQueen; rook = whiteRook; knight = whiteKnight; bishop = whiteBishop;
                valid_capture = torow + 1;
            }
            else
            {
                queen = blackQueen; rook = blackRook; knight = blackKnight; bishop = blackBishop;
                valid_capture = torow - 1;
            }

            int pawn_choice = 0;
            do
            {
                wcout << "\n\t\t\t\tPAWN PROMOTION "
                    << "\n\t\t\t\t Press 1 for " << queen
                    << "\n\t\t\t\t Press 2 for " << rook
                    << "\n\t\t\t\t Press 3 for " << knight
                    << "\n\t\t\t\t Press 4 for " << bishop << endl;
                cin >> pawn_choice;
                switch (pawn_choice)
                {
                case 1: board[torow][tocol] = queen; break;
                case 2: board[torow][tocol] = rook; break;
                case 3: board[torow][tocol] = knight; break;
                case 4: board[torow][tocol] = bishop;  break;
                default:
                    wcout << "INVALID MOVE ; TRY AGAIN::";
                }
            } while (pawn_choice > 4);

            drawBoard_(playerW, playerB);
        }
        return true;
    }

    // If no standard move was made, check for en passant
    if (!updated)
    {
        int fromcol = mov[0] - 'a';
        validrow = (player == playerW) ? 1 : 6;
        int valid_first = (player == playerW) ? lastrow - 2 : lastrow + 2;
        int valid_capture = (player == playerW) ? torow + 1 : torow - 1;
        if ((valid_first) == validrow)
        {
            if (((lastcol - 1) == fromcol) || (lastcol + 1) == fromcol)
            {
                if (board[torow][tocol] == emptyspace && board[valid_capture][fromcol] == pawn)
                {
                    board[torow][tocol] = pawn; // Move the pawn to the target square
                    board[valid_capture][fromcol] = emptyspace; // Clear the previous square
                    board[valid_capture][tocol] = emptyspace;

                    drawBoard_(playerW, playerB);
                    return true;
                }
            }
        }
    }
    return false;
}
bool QUEEN_movement(wstring player, string mov)
{
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];

    int fromrow = 0, fromcol = 0; bool validmove = false, updated = false; wchar_t piece; bool blocking_piece = false; int noOfAttackingPieces = 0;
    piece = (player == playerW) ? whiteQueen : blackQueen;
    initial_position(player, mov, fromrow, fromcol, validmove, piece, blocking_piece);

    if (!validmove && blocking_piece == true)
    {
        return false;
    }
    else
    {
        if (mov.length() == 3 && (board[torow][tocol] == emptyspace))
        {
            if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
            else if (!ischeck(player, noOfAttackingPieces))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
        }
        else
            if (mov.length() == 4 && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
            {
                if ((piece == whiteQueen) && (board[torow][tocol] == blackPawn ||
                    board[torow][tocol] == blackRook || board[torow][tocol] == blackKnight
                    || board[torow][tocol] == blackQueen || board[torow][tocol] == blackBishop))
                {
                    if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                }
                else
                    if ((piece == blackQueen) && (board[torow][tocol] == whitePawn ||
                        board[torow][tocol] == whiteRook || board[torow][tocol] == whiteKnight
                        || board[torow][tocol] == whiteQueen || board[torow][tocol] == whiteBishop))
                    {
                        if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                        else if (!ischeck(player, noOfAttackingPieces))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    }
            }
    }
    if (updated)
        return true;
    return false;
}
bool ROOK_movement(wstring player, string mov)
{

    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int fromrow = 0, fromcol = 0; bool validmove = false, updated = false; wchar_t piece; bool blocking_piece = true; int noOfAttackingPieces = 0;
    piece = (player == playerW) ? whiteRook : blackRook;
    initial_position(player, mov, fromrow, fromcol, validmove, piece, blocking_piece);

    if (!validmove && blocking_piece == true)
    {
        return false;
    }
    else
    {
        if (mov.length() == 3 && (board[torow][tocol] == emptyspace))
        {
            if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
            else if (!ischeck(player, noOfAttackingPieces))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
        }
        else
            if (mov.length() == 4 && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
            {
                if ((piece == whiteRook) && (board[torow][tocol] == blackPawn ||
                    board[torow][tocol] == blackRook || board[torow][tocol] == blackKnight
                    || board[torow][tocol] == blackQueen || board[torow][tocol] == blackBishop))
                {
                    if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                }
                else
                    if ((piece == blackRook) && (board[torow][tocol] == whitePawn ||
                        board[torow][tocol] == whiteRook || board[torow][tocol] == whiteKnight
                        || board[torow][tocol] == whiteQueen || board[torow][tocol] == whiteBishop))
                    {
                        if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                        else if (!ischeck(player, noOfAttackingPieces))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    }
            }
    }
    if (updated)
        return true;
    return false;
}
bool BISHOP_movement(wstring player, string mov)
{

    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int fromrow = 0, fromcol = 0; bool validmove = false, updated = false; wchar_t piece; bool blocking_piece = false; int noOfAttackingPieces = 0;
    piece = (player == playerW) ? whiteBishop : blackBishop;
    initial_position(player, mov, fromrow, fromcol, validmove, piece, blocking_piece);


    if (!validmove && blocking_piece == true)
    {
        return false;
    }
    else
    {
        if (mov.length() == 3 && (board[torow][tocol] == emptyspace))
        {
            if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
            else if (!ischeck(player, noOfAttackingPieces))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
        }
        else
            if (mov.length() == 4 && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
            {
                if ((piece == whiteBishop) && (board[torow][tocol] == blackPawn ||
                    board[torow][tocol] == blackRook || board[torow][tocol] == blackKnight
                    || board[torow][tocol] == blackQueen || board[torow][tocol] == blackBishop))
                {
                    if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                }
                else
                    if ((piece == blackBishop) && (board[torow][tocol] == whitePawn ||
                        board[torow][tocol] == whiteRook || board[torow][tocol] == whiteKnight
                        || board[torow][tocol] == whiteQueen || board[torow][tocol] == whiteBishop))
                    {
                        if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                        else if (!ischeck(player, noOfAttackingPieces))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    }
            }
    }
    if (updated)
        return true;
    return false;
}
bool KNIGHT_movement(wstring player, string mov)
{
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int fromrow = 0, fromcol = 0; bool validmove = false, updated = false; wchar_t piece; bool blocking_piece = false; int noOfAttackingPieces = 0;
    piece = (player == playerW) ? whiteKnight : blackKnight;
    initial_position(player, mov, fromrow, fromcol, validmove, piece, blocking_piece);

    if (!validmove && blocking_piece == true)
    {
        return false;
    }
    else
    {
        if (mov.length() == 3 && (board[torow][tocol] == emptyspace))
        {
            if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
            else if (!ischeck(player, noOfAttackingPieces))
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
        }
        else
            if (mov.length() == 4 && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
            {
                if ((piece == whiteKnight) && (board[torow][tocol] == blackPawn ||
                    board[torow][tocol] == blackRook || board[torow][tocol] == blackKnight
                    || board[torow][tocol] == blackQueen || board[torow][tocol] == blackBishop))
                {
                    if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    else if (!ischeck(player, noOfAttackingPieces))
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                }
                else
                    if ((piece == blackKnight) && (board[torow][tocol] == whitePawn ||
                        board[torow][tocol] == whiteRook || board[torow][tocol] == whiteKnight
                        || board[torow][tocol] == whiteQueen || board[torow][tocol] == whiteBishop))
                    {
                        if (ischeck(player, noOfAttackingPieces) && isvalid_move(player, mov))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                        else if (!ischeck(player, noOfAttackingPieces))
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                       
                    }
            }
    }
    if (updated)
        return true;
    return false;
}

bool isTargetPiece(wstring player, wchar_t piece, wchar_t targetPiece, int i, int cap_flag) {
    wchar_t  targetpiece_1, targetpiece_2, targetpiece_3, targetpiece_4, targetpiece_5, targetpiece_6;
    if (cap_flag == 0)
    {
        if (player == playerW)
        {
            piece = whiteKing;
            targetpiece_1 = blackRook, targetpiece_2 = blackQueen, targetpiece_3 = blackBishop, targetpiece_4 = blackKnight, targetpiece_5 = blackKing, targetpiece_6 = blackPawn;
        }
        else
        {
            piece = blackKing;
            targetpiece_1 = whiteRook, targetpiece_2 = whiteQueen, targetpiece_3 = whiteBishop, targetpiece_4 = whiteKnight, targetpiece_5 = whiteKing, targetpiece_6 = whitePawn;
        }
    }
    else
    {
        if (player == playerB)
        {
            piece = whiteKing;
            targetpiece_1 = blackRook, targetpiece_2 = blackQueen, targetpiece_3 = blackBishop, targetpiece_4 = blackKnight;
        }
        else
        {
            piece = blackKing;
            targetpiece_1 = whiteRook, targetpiece_2 = whiteQueen, targetpiece_3 = whiteBishop, targetpiece_4 = whiteKnight;
        }
    }
    if ((i < 28) && (targetPiece == targetpiece_1 || targetPiece == targetpiece_2))
    {
        return true;
    }
    else
        if ((i < 56 && i >= 28) && (targetPiece == targetpiece_3 || targetPiece == targetpiece_2))
        {
            return true;
        }
        else if ((i < 63 && i >= 56) && (targetPiece == targetpiece_4))
        {
            return true;
        }

        else
            return false;
}
bool isCapturingSquare(wstring player, int torow, int tocol, vector<pair<int, int>>& nonBlockedPieces, int& cap_flag,int nflag) {
    wchar_t piece = (player == playerW) ? whiteKing : blackKing;
    wchar_t targetPiece;
    vector<pair<int, int>> targetingPieces;
    int flag = 1;
    vector<pair<int, int>>emptyspace;
    int validMovesAll[72][2] = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,-7},{0,-6},{0,-5},{0,-4},{0,-3},{0,-2},{0,-1},
                                {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0},
                                {-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7},
                                {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7},
                                {1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7},{-2, -1}, {-2,  1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
    };

    for (int i = 0; i < 64; i++) {
        int R = torow + validMovesAll[i][0];
        int C = tocol + validMovesAll[i][1];
        if (isValidPosition(R, C)) {
            targetPiece = board[R][C];
            if (isTargetPiece(player, piece, targetPiece, i, cap_flag)) {

                targetingPieces.push_back({ R, C });
            }
        }
    }

    // Check for pawn captures
    int pawnMoves[4][2];

   if (cap_flag == 0)
    {
        if (player == playerW)
        {
            int temp[4][2] = { {-2,0},{-1,0},{-1,-1},{-1,1} };
            memcpy(pawnMoves, temp, sizeof(temp));// copying the data from one memory to other void *memcpy(void *destination, const void *source, size_t num);
        }
        else
        {
            int temp[4][2] = { {2,0},{1,0},{1,-1},{1,1} };

            memcpy(pawnMoves, temp, sizeof(temp));
        }
    }
    else
    {
        if (player == playerW)
        {
            int temp[4][2] = { {2,0},{1,0},{1,-1},{1,1} };

            memcpy(pawnMoves, temp, sizeof(temp));// copying the data from one memory to other void *memcpy(void *destination, const void *source, size_t num);
        }
        else
        {
            int temp[4][2] = { {-2,0},{-1,0},{-1,-1},{-1,1} };
            memcpy(pawnMoves, temp, sizeof(temp));
        }
    }

    for (int i = 0; i < 4; i++) {
        int R = torow + pawnMoves[i][0];
        int C = tocol + pawnMoves[i][1];
        if ((isValidPosition(R, C)) && (cap_flag==0 && board[R][C] == (player == playerW ? blackPawn : whitePawn)|| (cap_flag >0 && board[R][C] == (player == playerB ? blackPawn : whitePawn))))
        {
            if (nflag == 0)
            {
                if ((i < 2) && board[torow][tocol] == ' ')
                {
                    targetingPieces.push_back({ R, C });
                }
            }
            else
            {
                if (i >= 2 && i < 4)
                {
                    targetingPieces.push_back({ R, C });
                }
            }
        }
    }

    for (int i = 0; i < targetingPieces.size(); i++)
    {
        int fromrow = targetingPieces[i].first;
        int fromcol = targetingPieces[i].second;
        bool IsPathBlocked = false;
        if (board[fromrow][fromcol] != whiteKnight && board[fromrow][fromcol] != blackKnight)
        {
            IsPathBlocked = is_path_blocked(torow, tocol, fromrow, fromcol, flag, emptyspace);
        }
        if (!IsPathBlocked)
        {
            nonBlockedPieces.push_back({ fromrow, fromcol });
            continue;
        }
    }

    if (nonBlockedPieces.size() > 0)
    {
        return true;
    }
    return false;
}
bool isvalid_move(wstring player, string mov)
{
    int kingRow = (player == playerW) ? lastrow_wK : lastrow_bK;
    int kingCol = (player == playerW) ? lastcol_wK : lastcol_bK;

    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];

    vector<pair<int, int>> attackingPieces;
    vector<pair<int, int>> empty_squares;
    int flag = 0, nflag=1;

    if (isCapturingSquare(player, kingRow, kingCol, attackingPieces, flag, nflag))
    {
        int fromrow = attackingPieces[0].first;
        int fromcol = attackingPieces[0].second;

        if (!is_path_blocked(kingRow, kingCol, fromrow, fromcol, flag, empty_squares))
        {
            for (int i = 0; i < empty_squares.size(); i++)
            {
                if (torow == empty_squares[i].first && tocol == empty_squares[i].second)
                {
                    return true;
                }
            }
            if (torow == fromrow && tocol == fromcol)
            {
                return true;
            }
        }
    }
    return false;
}
bool KING_movement(wstring player, string mov)
{
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];
    int fromrow = 0, fromcol = 0; bool validmove = false, updated = false; wchar_t piece; bool blocking_piece = true; int cap_flag = 0, nflag=1;
    vector<pair<int, int>> nonBlockedPieces;
    piece = (player == playerW) ? whiteKing : blackKing;
    bool IsCapturing = isCapturingSquare(player, torow, tocol, nonBlockedPieces, cap_flag, nflag);

    if (!IsCapturing)
    {
        initial_position(player, mov, fromrow, fromcol, validmove, piece, blocking_piece);
        if (!validmove)
        {
            return false;
        }
        else
        {
            if (mov.length() == 3 && (board[torow][tocol] == emptyspace))
            {
                updated = updateboard(torow, tocol, fromrow, fromcol, piece);
            }
            else
                if (mov.length() == 4 && (board[torow][tocol] != emptyspace) && mov[1] == 'x')
                {
                    if ((piece == whiteKing) && (board[torow][tocol] == blackPawn ||
                        board[torow][tocol] == blackRook || board[torow][tocol] == blackKnight
                        || board[torow][tocol] == blackQueen || board[torow][tocol] == blackBishop))
                    {
                        updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                    }
                    else
                        if ((piece == blackKing) && (board[torow][tocol] == whitePawn ||
                            board[torow][tocol] == whiteRook || board[torow][tocol] == whiteKnight
                            || board[torow][tocol] == whiteQueen || board[torow][tocol] == whiteBishop))
                        {
                            updated = updateboard(torow, tocol, fromrow, fromcol, piece);
                        }
                }
            if (updated)
            {
                if (piece == whiteKing) {
                    lastrow_wK = torow;
                    lastcol_wK = tocol;
                }
                else {
                    lastrow_bK = torow;
                    lastcol_bK = tocol;
                }
                return true;
            }
        }
    }
    return false;
}

bool can_king_escap(wstring player)
{
    int kingRow = (player == playerW) ? lastrow_wK : lastrow_bK;
    int kingCol = (player == playerW) ? lastcol_wK : lastcol_bK;
    vector<pair<int, int>> empty_squares;

    int valid_moves[8][2] = { {0,-1},{0,1},{1,0},{-1,0},{-1,1},{1,1},{-1,-1},{1,-1} };
    int  cap_falg = 0, nflag=1;
    for (int i = 0; i < 8; i++)
    {
        vector<pair<int, int>> nonBlockedpieces;
        int R = kingRow + valid_moves[i][0];
        int C = kingCol + valid_moves[i][1];
        if ((R < 8 && R >= 0) && (C >= 0 && C < 8))
        {
            bool is_sqcapturing = isCapturingSquare(player, R, C, nonBlockedpieces, cap_falg, nflag);
            if (player == playerW)
            {
                if ((board[R][C] != whiteRook) && (board[R][C] != whiteBishop) && (board[R][C] != whiteQueen) && (board[R][C] != whitePawn) && (board[R][C] != whiteKnight) && !is_sqcapturing)
                {
                    if (r == 0 && (board[R][C] == emptyspace))
                    {
                        wcout << " \t\t\t KING CAN ESCAPE ";
                        return true;
                    }else
                        if (r == 0 && (board[R][C] != emptyspace))
                        {
                            wcout << " \t\t\t KING CAN ESCAPE BY CAPTURING  ";
                            return true;
                        }

                  
                }
            }
            else
                if ((board[R][C] != blackRook) && (board[R][C] != blackBishop) && (board[R][C] != blackQueen) && (board[R][C] != blackPawn) && (board[R][C] != blackKnight) && !is_sqcapturing)
                {
                    if (r == 0)
                    wcout << " \t\t\t KING CAN ESCAPE \n";
                    return true;
                }
        }

    }
    return false;
}
bool can_capture_check(wstring player)
{
    int kingRow = (player == playerW) ? lastrow_wK : lastrow_bK;
    int kingCol = (player == playerW) ? lastcol_wK : lastcol_bK;
    vector<pair<int, int>> nonBlockedpieces;
    vector<pair<int, int>> checking_pieces;
    vector<pair<int, int>> empty_squares;
    int flag = 0, nflag=1;
    if (isCapturingSquare(player, kingRow, kingCol, nonBlockedpieces, flag, nflag))
    {
        for (int i = 0; i < nonBlockedpieces.size(); i++)
        {
            int toR = nonBlockedpieces[i].first;
            int toC = nonBlockedpieces[i].second;
            flag++; int nflag = 1;
            if (isCapturingSquare(player, toR, toC, checking_pieces, flag, nflag))
            {
                if ((checking_pieces[i].first == kingRow && checking_pieces[i].second == kingCol) && (checking_pieces.size() == 1))
                {
                    return false;
                }
                else
                {
                  if (r == 0)
                  {
                    wcout << "\n \t\t\t ATTACKING PIECE CAN BE CAPTURED BY : ";
                    for (int i = 0; i < checking_pieces.size(); i++)
                    {
                        wcout << board[checking_pieces[i].first][checking_pieces[i].second] << " ";
                    }
                  }
                    return true;
                }

            }
        }
    };
    return false;
}
bool can_block_check(wstring player)
{
    bool can_block = false;
    vector<pair<int, int>> nonBlockedpieces;
    vector<pair<int, int>> empty_squares;

    int kingRow = (player == playerW) ? lastrow_wK : lastrow_bK;
    int kingCol = (player == playerW) ? lastcol_wK : lastcol_bK;
    int flag = 0, nflag=1;
    if (isCapturingSquare(player, kingRow, kingCol, nonBlockedpieces, flag, nflag))
    {
        int row_diff = 0, rowstep = 0;
        int col_diff = 0, colstep = 0;

        int fromrow = nonBlockedpieces[0].first;
        int fromcol = nonBlockedpieces[0].second;
        is_path_blocked(kingRow, kingCol, fromrow, fromcol, flag, empty_squares);
        for (int i = 0; i < empty_squares.size(); i++)
        {
            vector<pair<int, int>> empty_squares_targeting_pieces;
            int empty_row = empty_squares[i].first;
            int empty_col = empty_squares[i].second;
            flag++; int nflag = 0;
            int is_capturing = isCapturingSquare(player, empty_row, empty_col, empty_squares_targeting_pieces, flag,nflag);
            for (int j = 0; j < empty_squares_targeting_pieces.size(); j++)
            {
                if ((is_capturing) && board[empty_squares_targeting_pieces[j].first][empty_squares_targeting_pieces[j].second] != whiteKing && board[empty_squares_targeting_pieces[j].first][empty_squares_targeting_pieces[j].second] != blackKing)
                {
                    if (r == 0)
                    {
                        if (j == 0)
                            wcout << "\n \t\t\t CHECK CAN BE BLOCKED BY PIECES  : ";

                        if ((board[empty_squares_targeting_pieces[j].first][empty_squares_targeting_pieces[j].second] != whiteKing) && (board[empty_squares_targeting_pieces[j].first][empty_squares_targeting_pieces[j].second] != blackKing))
                        {
                            wcout << board[empty_squares_targeting_pieces[j].first][empty_squares_targeting_pieces[j].second] << "  ";
                        }
                    }
                    can_block = true;
                }
                else
                    continue;
            }
        }
    }
    if (can_block)
        return true;
    else
        return false;
}
bool check_mate(wstring player, string mov)
{
    wchar_t piece = (player == playerW) ? piece = whiteKing : piece = blackKing;
    bool can_kingescap = false, can_capture_attacker = false, can_block = false;
    int noOfAttackingPieces = 0;

    if (!ischeck(player, noOfAttackingPieces)) {
        return false;
    }
    else
    {
        if (r == 0)
           wcout <<"\t\t\t" << piece << " king is in check ....Save the king !!!\n";
        if (noOfAttackingPieces == 1)
        {
            can_kingescap = can_king_escap(player);
            can_capture_attacker = (can_capture_check(player));
            can_block = can_block_check(player);
        }
        else
        {
            bool can_kingescap = can_king_escap(player);
        }

        if (can_kingescap || can_capture_attacker || can_block)
        {
            return false;
        }
    }
    return true;
}

struct coordinates
{
    wchar_t piece = whiteBishop; int row = 0, col = 0;
};
bool stalemate(wstring player)
{
    bool move = false, blockedpiece = false;
    coordinates C[32]; int count_C = 0;
    int row_diff = 0, rowstep = 0;
    int col_diff = 0, colstep = 0;

    int valid_moves_whitepawn[3][2] = { {-1,0},{-1,-1},{-1,1} };
    int valid_moves_blackpawn[3][2] = { {1,0},{1,-1},{1,1} };


    vector<tuple<wchar_t, int, int>> coordinates; wchar_t pieces;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pieces = board[i][j];
            if (pieces != emptyspace)
            {
                C[count_C].piece = board[i][j];
                C[count_C].row = i;
                C[count_C].col = j;
                count_C++;
            }
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (C[i].piece == whitePawn)
        {
            for (int j = 0; j < 3; j++)
            {
                int Col = C[i].col + valid_moves_whitepawn[j][0];
                int Row = C[i].row + valid_moves_whitepawn[j][0];

                if (j == 0)
                {
                    if (board[Row][Col] == emptyspace)
                        return false;
                }
                else
                {
                    if (board[Row][Col] != emptyspace)
                        return false;
                }

            }
        }
        if (C[i].piece == blackPawn)
        {
            for (int j = 0; j < 3; j++)
            {
                int Col = C[i].col + valid_moves_blackpawn[j][0];
                int Row = C[i].row + valid_moves_blackpawn[j][0];

                if (j == 0)
                {
                    if (board[Row][Col] == emptyspace)
                        return false;
                }
                else
                {
                    if (board[Row][Col] != emptyspace)
                        return false;
                }

            }
        }
        if (C[i].piece == whiteRook || C[i].piece == blackRook || C[i].piece == whiteQueen || C[i].piece == blackQueen)
        {
            int valid_moves_all[28][2] = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,-7},{0,-6},{0,-5},{0,-4},{0,-3},{0,-2},{0,-1},
                                         {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0} };
            for (int j = 0; j < 28; j++)
            {
                int Col = C[i].col + valid_moves_all[j][0];
                int Row = C[i].row + valid_moves_all[j][0];
                if ((C[i].piece == whiteBishop || C[i].piece == whiteQueen))
                {
                    if (board[Row][Col] == emptyspace || (board[Row][Col] != whiteBishop && board[Row][Col] != whiteQueen && board[Row][Col] != whiteKnight
                        && board[Row][Col] != whiteRook && board[Row][Col] != whitePawn && board[Row][Col] != whiteKing))
                    {
                        row_diff = Row - C[i].row;
                        col_diff = Col - C[i].col;

                        if (row_diff > 0) rowstep = 1;
                        else if (row_diff < 0) rowstep = -1;

                        if (col_diff < 0) colstep = -1;
                        else if (col_diff > 0) colstep = 1;

                        int crow = C[i].row + rowstep;
                        int ccol = C[i].col + colstep;
                        while (crow != Row || ccol != Col)
                        {
                            if (board[crow][ccol] != emptyspace)
                            {
                                blockedpiece = true;
                                break;
                            }
                            crow += rowstep;
                            ccol += colstep;
                        }
                    }
                    else
                        move = false;
                }
                else
                    if ((C[i].piece == blackBishop || C[i].piece == blackQueen))
                    {
                        if (board[Row][Col] == emptyspace || (board[Row][Col] != blackBishop && board[Row][Col] != blackQueen && board[Row][Col] != blackKnight
                            && board[Row][Col] != blackRook && board[Row][Col] != blackPawn && board[Row][Col] != blackKing))
                        {
                            row_diff = Row - C[i].row;
                            col_diff = Col - C[i].col;

                            if (row_diff > 0) rowstep = 1;
                            else if (row_diff < 0) rowstep = -1;

                            if (col_diff < 0) colstep = -1;
                            else if (col_diff > 0) colstep = 1;

                            int crow = C[i].row + rowstep;
                            int ccol = C[i].col + colstep;
                            while (crow != Row || ccol != Col)
                            {
                                if (board[crow][ccol] != emptyspace)
                                {
                                    blockedpiece = true;
                                    break;
                                }
                                crow += rowstep;
                                ccol += colstep;
                            }
                        }
                        else
                            move = false;
                    }
                if (blockedpiece == false)
                {
                    return false;
                    break;
                }
            }
        }
        if (C[i].piece == whiteBishop || C[i].piece == blackBishop || C[i].piece == whiteQueen || C[i].piece == blackQueen)
        {
            int valid_moves_all[28][2] = { {-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7},
                                           {1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7} };

            for (int j = 0; j < 28; j++)
            {
                int Col = C[i].col + valid_moves_all[j][0];
                int Row = C[i].row + valid_moves_all[j][0];
                if ((C[i].piece == whiteBishop || C[i].piece == whiteQueen))
                {
                    if (board[Row][Col] == emptyspace || (board[Row][Col] != whiteBishop && board[Row][Col] != whiteQueen && board[Row][Col] != whiteKnight
                        && board[Row][Col] != whiteRook && board[Row][Col] != whitePawn && board[Row][Col] != whiteKing))
                    {
                        row_diff = Row - C[i].row;
                        col_diff = Col - C[i].col;

                        if (row_diff > 0) rowstep = 1;
                        else if (row_diff < 0) rowstep = -1;

                        if (col_diff < 0) colstep = -1;
                        else if (col_diff > 0) colstep = 1;

                        int crow = C[i].row + rowstep;
                        int ccol = C[i].col + colstep;
                        while (crow != Row || ccol != Col)
                        {
                            if (board[crow][ccol] != emptyspace)
                            {
                                blockedpiece = true;
                                break;
                            }
                            crow += rowstep;
                            ccol += colstep;
                        }
                    }
                    else
                        move = false;
                }
                else
                    if ((C[i].piece == blackBishop || C[i].piece == blackQueen))
                    {
                        if (board[Row][Col] == emptyspace || (board[Row][Col] != blackBishop && board[Row][Col] != blackQueen && board[Row][Col] != blackKnight
                            && board[Row][Col] != blackRook && board[Row][Col] != blackPawn && board[Row][Col] != blackKing))
                        {
                            row_diff = Row - C[i].row;
                            col_diff = Col - C[i].col;

                            if (row_diff > 0) rowstep = 1;
                            else if (row_diff < 0) rowstep = -1;

                            if (col_diff < 0) colstep = -1;
                            else if (col_diff > 0) colstep = 1;

                            int crow = C[i].row + rowstep;
                            int ccol = C[i].col + colstep;
                            while (crow != Row || ccol != Col)
                            {
                                if (board[crow][ccol] != emptyspace)
                                {
                                    blockedpiece = true;
                                    break;
                                }
                                crow += rowstep;
                                ccol += colstep;
                            }
                        }
                        else
                            move = false;
                    }
                if (blockedpiece == false)
                {
                    return false;
                    break;
                }
            }
        }
        if (C[i].piece == whiteKnight || C[i].piece == blackKnight)
        {
            int valid_moves_all[28][2] = { {-2, -1}, {-2,  1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
            for (int j = 0; j < 8; j++)
            {
                int Col = C[i].col + valid_moves_all[j][0];
                int Row = C[i].row + valid_moves_all[j][0];
                if ((C[i].piece == whiteRook))
                {
                    if (board[Row][Col] == emptyspace || (board[Row][Col] != whiteBishop && board[Row][Col] != whiteQueen && board[Row][Col] != whiteKnight && board[Row][Col] != whiteRook && board[Row][Col] != whitePawn && board[Row][Col] != whiteKing))
                    {
                        return false;
                    }
                }
                else
                {
                    if (board[Row][Col] == emptyspace || (board[Row][Col] != blackBishop && board[Row][Col] != blackQueen && board[Row][Col] != blackKnight && board[Row][Col] != blackRook && board[Row][Col] != blackPawn && board[Row][Col] != blackKing))
                    {
                        return false;
                    }
                }

            }
        }
        if (C[i].piece == whiteKing || C[i].piece == blackKing)
        {
            //if (can_king_escap(player))
                return false;
        }
    }
    return true;
}
void playermove(wstring player, bool& is_game_over)
{
    string mov;
    bool check = true;

    bool is_checkmate = check_mate(player, mov);
    if (is_checkmate)
    {
        if (player == playerW)
            wcout << "\n\t\t\t\t .....CHECK MATE....\n \t\t\t\tPLAYER 2 BLACK HAS WON .....! " << endl;
        else
            wcout << "\n\t\t\t \t.....CHECK MATE....\n \t\t\t\tPLAYER 1 WHITE HAS WON .....! " << endl;
        is_game_over = true;
        return;
    }

    if (stalemate(player))
    {
        if (player == playerW)
            wcout << "\n\t\t\t ..... GAME DRAW ....\n PLAYER 2 BLACK HAS WON .....! " << endl;
        else
            wcout << "\n\t\t\t ..... GAME DRAW ....\n PLAYER 1 WHITE HAS WON .....! " << endl;
        is_game_over = true;
        return;
    }

    // Player's turn prompt
    wcout  << "\n\t\t\t"<<player << "'s turn:\n";
    wcout << "\t\t\tEnter your choice in format ('e4'/'exd5'/'Kd5'/'Kxd5'): ";
    cin >> mov;

    // Validate move format
    if (!isvalid_format(mov))
    {
        wcout << "\r\t\t\t INVALID INPUT FORMAT! PLEASE ENTER A MOVE LIKE 'e4'/'exd5'/'Kd5'/'Kxd5'.";
        player1turn = !player1turn; // Toggle turn to correct mistake in previous logic
        return;
    }

    // Extract destination row & column
    int tocol = mov[(mov.length() - 2)] - 'a';
    int torow = '8' - mov[(mov.length() - 1)];


    // Identify piece and process move
   switch (mov[0])
    {
    case 'N':
        check = KNIGHT_movement(player, mov);
        break;
    case 'Q':
        check = QUEEN_movement(player, mov);
        break;
    case 'R':
        check = ROOK_movement(player, mov);
        break;
    case 'B':
        check = BISHOP_movement(player, mov);
        break;
    case 'K':
        check = KING_movement(player, mov);
        break;
    default:
        check = pawn_movement(player, mov);
        break;
    }
    
    // Handle invalid moves
    if (!check)
    {
        int noOfAttackingPieces = 0;
        wcout << "\t\t\t INVALID MOVE ; PLEASE TRY AGAIN " << endl;
        player1turn = !player1turn; // Prevents skipping turns due to an invalid move
        if(ischeck(player, noOfAttackingPieces))
            r++;
    }

    
    return;
}

int main()
{
        system("cls");
        _setmode(_fileno(stdout), _O_U8TEXT);  // Enable UTF-8 output mode
        initializeBoard();
        
        //drawBoard_(player1, player2);
        int ch=0; bool is_game_over = false;
        drawBoard(playerW, playerB);
        wcout << "\t\tPress 1 to play \n\t\tPress 2 to exit/Resign ";
        wcin >> ch;
        system("cls");
        drawBoard(playerW, playerB);
        if (ch == 1)
        {
            tossing(playerW, playerB);
            do
            {
                if (player1turn)
                    playermove(playerW, is_game_over);
                else
                    playermove(playerB, is_game_over);

                player1turn = !player1turn;
            } while (!is_game_over);
        }else
            if (ch == 2)
              wcout << "\t\t RESIGNING THE GAME .....! \n";
             // wcout << "\t\t\t BETTER LUCK NEXT TIME \n\n";

    system("pause");
}




