#include "bit_rep.h"

BitRep::BitRep(int width, int height) : rows(height), cols(width) {
    map = vector< vector<bool> >(rows, vector<bool>(cols, 0));
    currentCol = 0;
}

int BitRep::getRows() { return rows; }

int BitRep::getCols() { return cols; }

int BitRep::getCurrentCol() { return currentCol; }

void BitRep::setBit(int row, int col, bool value) {
    map[row][col] = value;
}

bool BitRep::getBit(int row, int col) {
    return map[row][col];
}

void BitRep::display() {
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            printf("%c", map[row][col] ? '8' : '.');
        }
        printf("\n");
    }
}

vector<bool> BitRep::getCurrentVector() { return map[currentCol]; }

void BitRep::incrementCol() { currentCol++; }

bool BitRep::last() { 
    if (currentCol == cols - 1) return true;
    return false;
}