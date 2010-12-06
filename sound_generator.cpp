#include "sound_generator.h"

SoundGenerator::SoundGenerator() {

}

SoundGenerator::~SoundGenerator() {
    int count = 0;
    // release sounds:
    for (count = 0; count < NUM_SOUNDS; count++) {
           result = sound[count]->release();
           ERRCHECK(result);
    }
    // release system:
    result = system->close();
    ERRCHECK(result);
    result = system->release();
    ERRCHECK(result);
}

bool SoundGenerator::loadSystemSounds() {
    int count = 0;
    // load in the sounds from the "sounds" directory:
    result = system->createSound("sounds/1.wav", FMOD_DEFAULT, 0, &sound[0]);
    ERRCHECK(result);
    result = system->createSound("sounds/2.wav", FMOD_DEFAULT, 0, &sound[1]);
    ERRCHECK(result);
    result = system->createSound("sounds/3.wav", FMOD_DEFAULT, 0, &sound[2]);
    ERRCHECK(result);
    result = system->createSound("sounds/4.wav", FMOD_DEFAULT, 0, &sound[3]);
    ERRCHECK(result);
    result = system->createSound("sounds/5.wav", FMOD_DEFAULT, 0, &sound[4]);
    ERRCHECK(result);
    result = system->createSound("sounds/6.wav", FMOD_DEFAULT, 0, &sound[5]);
    ERRCHECK(result);
    result = system->createSound("sounds/7.wav", FMOD_DEFAULT, 0, &sound[6]);
    ERRCHECK(result);
    result = system->createSound("sounds/8.wav", FMOD_DEFAULT, 0, &sound[7]);
    ERRCHECK(result);
    result = system->createSound("sounds/9.wav", FMOD_DEFAULT, 0, &sound[8]);
    ERRCHECK(result);
    result = system->createSound("sounds/10.wav", FMOD_DEFAULT, 0, &sound[9]);
    ERRCHECK(result);
    return true;
}

// Function used to check FMOD error codes. NOTE: exit(-1) is commented out for 
// silent failure. 
void SoundGenerator::ERRCHECK(FMOD_RESULT result) {
    if (result != FMOD_OK) {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        //exit(-1);
    }
}

// Init the sound generator, needs to be called before you can start playing sounds.
// Handles system set up stuff, including call to loadSystemSounds().
// Check documentation (Program Files/FMOD SoundSystem/FMOD Programmers API Win32/documentation)
// for information on this stuff.
bool SoundGenerator::init() {
    result = FMOD::System_Create(&system);
    ERRCHECK(result);
    result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);
    if (numdrivers == 0) {
        result = system->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
    } else {
        result = system->getDriverCaps(0, &caps, 0, 0, &speakermode);
        ERRCHECK(result);
    }
    result = system->setSpeakerMode(speakermode);
    ERRCHECK(result);
    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);
    this->loadSystemSounds();
    ERRCHECK(result);
    return true;
}

// Play a "sound column". Takes in a vector of bools. Check supplied "test_sound_generator.cpp"
// file for how to create vectors properly from a bitrep.
void SoundGenerator::play(vector<bool> toPlay) {
    int count = 0;
    stopAllChannels();
    // NOTE: This only looks at first 10 elements of the current col, so 
    // image grid height and number of sounds to play should be the same...
    for (count = 0; count < NUM_SOUNDS; count++) {
        if (toPlay[count]) {
            result = system->playSound(FMOD_CHANNEL_REUSE, sound[count], true, &channel[count]);
            ERRCHECK(result);
             result = channel[count]->setPaused(false);
            ERRCHECK(result);
        }
    }
    // Actually play the sounds:
    system->update();
    // Might need to change this value for speed:
    // Sleep(10);
}

// Internal method, used to make used channels available for use
// again (i.e. FMOD_CHANNEL_REUSE will only work properly if you
// call this function. Otherwise over time you will lose sound (
// as you run out of available channels).
bool SoundGenerator::stopAllChannels() {
    int count = 0;
    bool is_playing = false;;
    for (count = 0; count < NUM_SOUNDS; count++) {
        channel[count]->isPlaying(&is_playing);
        if (is_playing) {
            result = channel[count]->stop();
            ERRCHECK(result);
        }
    }
    // might need to uncomment those code if sounds start to not play correctly
    // over time:
    //system->update();
    return true;
}