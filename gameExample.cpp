#include "gameExample.h"
#include "player.h"
#include "move.h"
#include "helpers.h"
using namespace std;
#include<vector>
#include<string>
#include "minimax.h"

/*
void gameExampleOne(){
    int n = 3,m = 3;
    helpers helper;
    //cin >> n >> m;

    player white = player(n,m,true);
    player black = player(n,m,false);

    vector<string> board;
    helper.createBoard(board,n,m);

    helper.printBoard(board);

    cout << move(board,white,black,white.pawns[1],white.moves[0]) << endl;   //middle white moves forward

    helper.printBoard(board);

    cout << move(board,black,white,black.pawns[0],black.moves[2]) << endl;  //black takes white
    
    helper.printBoard(board);
    cout << "white pawns "; 
    helper.printPawns(white);
    cout << "black pawns ";
    helper.printPawns(black);


    cout << move(board,white,black,white.pawns[0],white.moves[1]) << endl;  //white tries illegal move
    helper.printBoard(board);

    cout << move(board,white,black,white.pawns[0],white.moves[2]) << endl;   //white takes black
    helper.printBoard(board);

}*/

void gameExampleTwo(){
    int n=3,m=3;
    helpers helper;
    cin >> n >> m;

    player white = player(n,m,true);
    player black = player(n,m,false);

    vector<string> board;
    helper.createBoard(board,n,m);
    minimax mm;
    bool noLegalMoves=false, isWhite=true;
    while(helper.evaluateBoard(board)==0 && !noLegalMoves)
    {
        mm.minimaxAlg(board,white,black,isWhite,1,INT_MIN,INT_MAX,noLegalMoves);
        isWhite = !isWhite;
        helper.printBoard(board);
    }
}