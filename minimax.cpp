#include "minimax.h"
#include "helpers.h"
#include "move.h"

helpers helper;

// Heuristika koja broji koliko koji igrac ima pijuna.
int h1(vector<string> &board, player &white, player &black)
{
    int w=white.pawns.size(),b=black.pawns.size();
    return w-b;   
}

// Heuristika koja gleda koliko su pijuni od svakog igraca 'razmaknuti'. Neka sahovska intuicija nam govori da bi bilo bolje da su svi pijuni medusobno blizu kako bi se branili.
int h2(vector<string> &board, player &white, player &black)
{
    int minWhite = 1e9, maxWhite = -1, minBlack = 1e9, maxBlack = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'w') {
                minWhite = min(minWhite, i);
                maxWhite = max(maxWhite, i);
            }
            if (board[i][j] == 'b') {
                minBlack = min(minBlack, i);
                maxBlack = max(maxBlack, i);
            }
        }
    }
    return (maxBlack - minBlack) - (maxWhite - minWhite);
}

// Heuristika koja gleda koliko je blizu rubu ploce najudaljeniji pijun
int h3(vector<string> &board, player &white, player &black)
{
    int minWhite = 1e9, maxBlack = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'w') {
                minWhite = min(minWhite, i);
            }
            if (board[i][j] == 'b') {
                maxBlack = max(maxBlack, i);
            }
        }
    }
    return (board.size() - 1 - maxBlack) - minWhite;
}

int minimax::minimaxAlg(vector<string> &board, player &white, player &black, bool whitePlays, int depth,int alpha,int beta,bool &noLegalMoves){
    
    if(helper.evaluateBoard(board) != 0){
        return helper.evaluateBoard(board);
    }
    if(white.pawns.size()==0 && black.pawns.size()!=0) return INT_MIN;
    if(black.pawns.size() == 0 && white.pawns.size() != 0) return INT_MAX;
    if(depth>=min(10,helper.intlog(3*board[0].size(),1e9))) return h2(board,white,black);
    vector<string> bestBoard;
    player bestWhite=player(true),bestBlack=player(false);
    noLegalMoves=true;
    if(whitePlays){
        int m=alpha;
        for(int i = 0 ; i < white.pawns.size(); ++i){
            for(int j = 0 ; j < white.moves.size(); ++j){

                vector<string> currentBoard = board;
                player currentWhite = white, currentBlack = black;

                if(move(currentBoard,currentWhite,currentBlack,currentWhite.pawns[i],currentWhite.moves[j],true)){
                    if(noLegalMoves && depth==1) 
                    {
                        bestWhite=currentWhite;
                        bestBoard=currentBoard;
                        bestBlack=currentBlack;
                    }
                    int res = minimaxAlg(currentBoard,currentWhite,currentBlack,!whitePlays,depth+1,m,beta,noLegalMoves);
                    noLegalMoves = false;
                    if(res>m) 
                    {
                        if(depth==1)
                        {
                            bestWhite=currentWhite;
                            bestBoard=currentBoard;
                            bestBlack=currentBlack;
                        }
                        m=res;
                    }    
                    if(m>=beta)
                    { 
                        if(depth==1)
                        {
                            board=bestBoard;
                            black=bestBlack;
                            white=bestWhite;
                        }
                        return beta;
                    }
                }
            }
        }
        if(depth==1)
        {
            black=bestBlack;
            white=bestWhite;
            board=bestBoard;
        }
        if(noLegalMoves) return INT_MIN;
        return m;
    }

    else{  
        int n=beta;
        for(int i = 0 ; i < black.pawns.size(); ++i){
            for(int j = 0 ; j < black.moves.size(); ++j){

                vector<string> currentBoard = board;
                player currentWhite = white, currentBlack = black;

                if(move(currentBoard,currentBlack,currentWhite,currentBlack.pawns[i],currentBlack.moves[j],false)){
                    if(noLegalMoves && depth==1)
                    {
                        bestWhite=currentWhite;
                        bestBoard=currentBoard;
                        bestBlack=currentBlack;
                    }
                    int res = minimaxAlg(currentBoard,currentWhite,currentBlack,!whitePlays,depth+1,alpha,n,noLegalMoves);
                    noLegalMoves = false;
                    if(res<n)
                    {   
                        if(depth==1)
                        {
                            bestWhite=currentWhite;
                            bestBoard=currentBoard;
                            bestBlack=currentBlack;
                        }
                        n=res;
                    }
                    if(n<=alpha)
                    {
                        if(depth==1)
                        {
                            board=bestBoard;
                            white=bestWhite;
                            black=bestBlack;
                        }
                        return alpha;
                    }
                }
            }
        }
        if(depth==1)
        {
            black=bestBlack;
            white=bestWhite;
            board=bestBoard;
        }
        if(noLegalMoves) return INT_MAX;
        return n;
    }

}