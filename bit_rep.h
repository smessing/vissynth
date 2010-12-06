/**
* bit_rep.h
*/

// Head Guards:
#ifndef BIT_REP_H
#define BIT_REP_H

// Think about using bitsetlib instead of vector...

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

    // Return next column for this bit_rep:
    //vector<bool> get_next_col();

    int getRows();
    int getCols();
    int getCurrentCol();
    void setBit(int row, int col, bool value);
    bool getBit(int row, int col);
    vector<bool> getCurrentVector();
    void display();
    void incrementCol();
    bool last();
};

#endif