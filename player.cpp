#include "player.h"
//the board will have n rows and m columns
//moves -> array of possible moves for a pawn
//pawns -> array of alive pawns
//maxPawn -> the pawn with the highest (lowest) y coordinate for white (black)

player::player(int n, int m, bool isWhite)
{
    for (int i = 0; i < m; ++i)
    {
        pawns.push_back(position(isWhite * (n - 1), i));
    }
    maxPawn = pawns[m / 2];
    if (isWhite)
    {
        moves = {position(-1, 0), position(-1, -1), position(-1, 1)}; //first move moves the pawn forward
    }                                                                 //second move moves the pawn diagonally left
    else
    {                                                                  //third move moves the pawn diagonally right
        moves = {position(1, 0), position(1, -1), position(1, 1)};
    }
}
