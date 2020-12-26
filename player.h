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


    player(int n, int m, bool isWhite);

    void erasePawn(position pos);
};


#endif