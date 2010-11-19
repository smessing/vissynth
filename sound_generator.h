/**
* sound_generator.h
*/

#include <vector>

using namespace std;

// Initialize sound device:
bool init();

// Play an individual column from a bit_rep:
void play_col(vector<bool> to_play);