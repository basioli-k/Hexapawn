#include "move.h"
#include "helpers.h"
//board.size() = n
//board[0].size() = m

helpers helperX;

bool move(vector<string> &board, player &player1, player &player2, position &pawn, const position & move){
    //check if move stays inside board
    if((pawn+move).i < board.size() && (pawn+move).i >= 0 && (pawn+move).j < board[0].size() && (pawn+move).j >= 0){
        int i = (pawn+move).i;
        int j = (pawn+move).j;

        if(move.j != 0){        //check if other player has pawn there
            if(player1.isWhite && board[i][j] == 'b'){
                board[i][j] = '.';
                player2.erasePawn(position(i,j));
                std::swap(board[i][j],board[pawn.i][pawn.j]);
                pawn = pawn + move;
                cout << "here 1" << endl;
                helperX.printPawns(player1);
                helperX.printPawns(player2);
                return true;
            }
            else if(!player1.isWhite && board[i][j] == 'w'){
                board[i][j] = '.';
                player2.erasePawn(position(i,j));
                std::swap(board[i][j],board[pawn.i][pawn.j]);
                pawn = pawn + move;
                cout << "here 2" << endl;
                helperX.printPawns(player1);
                helperX.printPawns(player2);
                return true;
            }
        }
        else{
            if(board[i][j] == '.'){
                std::swap(board[i][j],board[pawn.i][pawn.j]);
                
                pawn = pawn + move;
                return true;
            }
        }
    }

    return false;
}