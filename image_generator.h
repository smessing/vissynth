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

#include "cv.h"
#include "ml.h"
#include "cxcore.h"
#include "cxtypes.h"
#include "highgui.h"

#include "bit_rep.h"

using namespace cv;

class ImageGenerator {
private:
    CvCapture* capture;
    IplImage* frame;
    IplImage* frameProcessed;

    // Fill a provided bitrep with img's information
    bool fillBitRep(IplImage* img, BitRep &br);

public:
    ImageGenerator();
    ~ImageGenerator();

    // Initialize camera:
    bool init();

    // Pull image in from camera:
    bool pullImage(BitRep &br);

    /*
    // Transform image into bit rep, add to queue:
    void transformImage();

    // Dequeue next bit rep:
    bit_rep* nextRep();
    */
};

#endif