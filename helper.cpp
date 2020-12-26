#include "helpers.h"
#include <vector>
#include <string>

void helpers::createBoard(vector<string> & board, const int &n, const int &m){
    board.push_back(string(m,'b'));
    for(int i = 1; i < n-1; ++i) board.push_back(string(m,'.'));
    board.push_back(string(m,'w'));
}

void helpers::printPawns(player & player){
    for(int i = 0 ; i < player.pawns.size(); ++i){
        cout << player.pawns[i] << " ";
    }
    cout << endl;
}

void helpers::printBoard(vector<string> &board){
    for(int i = 0 ; i < board.size();++i){
        for(int j = 0 ; j < board[0].size(); ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int helpers::evaluateBoard(vector<string> &board){
    
    for(int i = 0 ; i < board[0].size(); ++i){
        if(board[0][i] == 'w') return INT_MAX;        //white wins
        if(board[board.size()-1][i] == 'b') return INT_MIN; //black wins
    }
    //TODO if there are no legal moves the winner is the player who has more pawns
    // check this with player.pawns.size()
    
    return 0; //no one is winning for now
}