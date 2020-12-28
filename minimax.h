#include<string>
#include<vector>
#include "player.h"


#ifndef minimax_h
#define minimax_h

class minimax{
public:
    int minimaxAlg(vector<string> &board, player& white, player &black, bool whitePlays, int depth,int alpha,int beta,bool &noLegalMoves);
};

#endif