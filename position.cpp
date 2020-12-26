using namespace std;
#include "position.h"

position::position(){
    this->i = -1;
    this->j = -1;
}
position::position(int x, int y){
    this->i = x;
    this->j = y;
}

position position::operator+(const position& pos){
    position newPos;
    newPos.i = this->i + pos.i;
    newPos.j = this->j + pos.j;
    return newPos;
}

ostream& operator<<(ostream& os, const position& pos){
    os << pos.i << " " << pos.j;
    return os;
}

bool position::operator==(const position& pos){
    return this->i == pos.i && this->j == pos.j;
}