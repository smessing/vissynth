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
    vector< vector<bool> > map;

public:
    BitRep(int width, int height);

    // Return next column for this bit_rep:
    //vector<bool> get_next_col();

    int getRows();
    int getCols();

    void setBit(int row, int col, bool value);
    bool getBit(int row, int col);

    void display();
};

#endif