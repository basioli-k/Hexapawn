#include <bits/stdc++.h>
#include "position.h"
#include "player.h"
using namespace std;


int main(){
    int n = 3,m = 3;
    //cin >> n >> m;
    player white = player(n,m,true);
    player black = player(n,m,false);
    
    for(int i = 0 ; i < white.pawns.size();++i){
        cout << black.pawns[i] << endl;
    }


    return 0;
}
