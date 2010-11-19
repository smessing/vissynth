/**
* sound_generator.h
*/

#include <vector>

// Initialize sound device:
bool init();

// Play an individual column from a bit_rep:
void play_col(vector<bool> to_play);