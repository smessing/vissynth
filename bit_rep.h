/**
* bit_rep.h
*/

// Head Guards:
#ifndef BIT_REP_H
#define BIT_REP_H

class BitRep {
public:
    BitRep(int rows, int cols);
    // Return next column for this bit_rep:
    vector<bool> get_next_col();
};

#endif