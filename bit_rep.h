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
    BitRep(int r, int c);
    // Return next column for this bit_rep:
    //vector<bool> get_next_col();

    bool getBit(int row, int col);
};

#endif