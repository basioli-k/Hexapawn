#include "minimax.h"
#include "helpers.h"
#include "move.h"

#define MAX_DEPTH 12

helpers helper;

int h(vector<string> &board, player &white, player &black)
{
    int w=white.pawns.size(),b=black.pawns.size();
    return w-b;   
}
int minimax::minimaxAlg(vector<string> &board, player &white, player &black, bool whitePlays, int depth,int alpha,int beta,bool &noLegalMoves){
    
    if(helper.evaluateBoard(board) != 0){
        return helper.evaluateBoard(board);
    }
    if(white.pawns.size()==0 && black.pawns.size()!=0) return INT_MIN;
    if(black.pawns.size() == 0 && white.pawns.size() != 0) return INT_MAX;
    if(depth>=MAX_DEPTH) return h(board,white,black);
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