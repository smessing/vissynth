/**
* bit_rep.h
*/

// Head Guards:
#ifndef BIT_REP_H
#define BIT_REP_H

#include <vector>

using namespace std;

class BitRep {
private:
    int rows;
    int cols;
    int currentCol;
    vector< vector<bool> > map;
public:
    BitRep(int width, int height);
    int getRows();
    int getCols();
    int getCurrentCol();
    void setBit(int row, int col, bool value);
    bool getBit(int row, int col);
    void display();
    vector<bool> getCurrentVector();
    void incrementCol();
    bool last();
};

#endif