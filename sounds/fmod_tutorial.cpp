#include "/Developer/FMOD Programmers API Mac/api/inc/fmod.hpp"
#include "/Developer/FMOD Programmers API Mac/api/inc/fmod_errors.h"
#include <stdio.h>
#include <string.h>

// FMUSIC_MODULE* tone;
FMOD_SYSTEM **sys;

int main() {
    
    FMOD::System *system;
    FMOD::Sound *sound1;
    FMOD_RESULT result;
    
    result = FMOD::System_Create(&system);
    
    
    return 0;
}