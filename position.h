using namespace std;
#include<ostream>

#ifndef position_h
#define position_h

class position{
public:
    int i,j;
    position();
    position(int x, int y);

    position operator+(const position& pos);
    bool operator==(const position& pos);
    friend ostream& operator<<(ostream& os, const position& pos);

};


#endif
