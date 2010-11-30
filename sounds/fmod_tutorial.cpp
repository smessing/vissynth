#include "/Developer/FMOD Programmers API Mac/api/inc/fmod.hpp"
#include "/Developer/FMOD Programmers API Mac/api/inc/fmod_errors.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>

void ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

int main() {
    FMOD::System    *system;
    FMOD::Sound     *sound1;
    FMOD::Channel   *channel = 0;
    FMOD_RESULT     result;
    unsigned int    version;
    void            *buff = 0;
    bool            bIsPlaying = true;
    // Create a System object and initialize.
    result = FMOD::System_Create(&system);
    ERRCHECK(result);
    result = system->getVersion(&version);
    ERRCHECK(result);
    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);
    // Load sound file:
    result = system->createSound("5.wav", FMOD_SOFTWARE, 0, &sound1);
    ERRCHECK(result);
    // Set volume:
//    channel->setVolume(0.5f);
    // Play sound:
    result = system->playSound(FMOD_CHANNEL_FREE, sound1, false, &channel);
    while (bIsPlaying) {
        system->update();
        channel->isPlaying(&bIsPlaying);
    }
    // Shutdown:
    result = sound1->release();
    ERRCHECK(result);
    result = system->close();
    ERRCHECK(result);
    result = system->release();
    ERRCHECK(result);
    return 0;
}