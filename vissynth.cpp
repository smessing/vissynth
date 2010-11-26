/**
* vissynth.cpp: Controller source for vissynth application.
* AUTHORS:
* Chang
* Evan
* Sam (smessing@sas.upenn.edu)
* Yui
*/

#include <iostream>
#include "cv.h"
#include "ml.h"
#include "cxcore.h"
#include "cxtypes.h"
#include "highgui.h"

#include "image_generator.h"
/*
#include "sound_generator.h"
#include "view.h"
*/

#define MAX_BIT_REP_ROWS 100
#define MAX_BIT_REP_COLS 100

using namespace std;

// Starts the vissynth:
void start() {
    
}

int main(int argc, char** argv) {
    ImageGenerator imgGen;
    if(!imgGen.init()) {
        fprintf(stderr, "Error initializing Image Generator - check webcam?\n");
        getchar();
        return -1;
    }
   
    // Show the image captured from the camera in the window and repeat
    while(true) {
        if(!imgGen.pullImage()) {
            fprintf(stderr, "Error pulling a frame from the webcam\n");
            getchar();
            return -1;
        }

        // Wait 200 ms, then check if the key pressed is ESC
        // If it is, then break
        if((cvWaitKey(200) & 255) == 27)
            break;
    }

    return 0;
}