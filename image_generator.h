/** 
* image_generator.h: For talking to camera and generating formatted
*   images for use in vissynth.cpp
* AUTHORS:
* Chang
* Evan
* Sam (smessing@sas.upenn.edu)
* Yui
*/

// Header Guards:
#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H

class ImageGenerator {
    // Initialize camera:
    bool init();

    // Pull image in from camera:
    void pullImage();

    // Transform image into bit rep, add to queue:
    void transformImage();

    // Dequeue next bit rep:
    bit_rep* nextRep();
};

#endif