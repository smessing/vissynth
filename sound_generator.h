// sound_generator.h

// Header Guards:
#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

// NOTE: Number of rows in bitrep should correspond to this number.
// Currently we only have 10 wav files in "sounds" directory, will
// need to make more before this number can increase...
#define NUM_SOUNDS 10

// FMOD includes:
#include <fmod.hpp>
#include <fmod_errors.h>
#include <Windows.h>

// Bit Rep:
#include "bit_rep.h"

using namespace std;

class SoundGenerator {
private:
    FMOD::System            *system;
    FMOD::Sound             *sound[NUM_SOUNDS];
    FMOD::Channel           *channel[NUM_SOUNDS];
    FMOD_RESULT             result;
    int                     numdrivers;
    FMOD_SPEAKERMODE        speakermode;
    FMOD_CAPS               caps;

    // Load system sounds (used by init())
    bool loadSystemSounds();
    // Used for error checking:
    void ERRCHECK(FMOD_RESULT result);
    // repause all sounds:
    bool stopAllChannels();
public:
    SoundGenerator();
    ~SoundGenerator();
    // Initialize sound:
    bool init();
    // Play next sound:
    void play(vector<bool> toPlay);
};

#endif