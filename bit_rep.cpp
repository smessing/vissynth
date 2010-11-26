#include "bit_rep.h"

BitRep::BitRep(int r, int c) : rows(r), cols(c) {
    map = vector< vector<bool> >(rows, vector<bool>(cols, 0));
}

bool BitRep::getBit(int row, int col) {
    return map[row][col];
}