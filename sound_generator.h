/**
* sound_generator.h
*/

// Header Guards:
#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

class Sound {
public:
    // Initialize sound device:
    bool init();

    // Play an individual column from a bit_rep:
    void play_col(vector<bool> to_play);
};

#endif