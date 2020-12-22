#include<bits/stdc++.h>
#include "position.h"
using namespace std;


#ifndef player_h
#define player_h

class player{
public:
    bool isWhite;
    vector<position> moves;
    vector<position> pawns;
    position maxPawn;


    player(int n, int m, bool isWhite);
};


#endif