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