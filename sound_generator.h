/**
* sound_generator.h
*/

// Header Guards:
#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

class SoundGenerator {
private:
    // FMOD STUFF
    // CHECK OTHER PROJECT
public:
    SoundGenerator();
    ~SoundGenerator();
    // Initialize sound device:
    bool init();
    // Play an individual column from a bit_rep:
    void play(vector<bool> to_play);
};

#endif