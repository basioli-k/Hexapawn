#include <vector>
#include <string>
#include "player.h"

#ifndef helpers_h
#define helpers_h

class helpers{
public:
    void createBoard(vector<string> & board, const int &n, const int &m);

    void printPawns(player & player);

    void printBoard(vector<string> &board);

    int evaluateBoard(vector<string> &board);

    int intlog(double base, double x);
};

#endif