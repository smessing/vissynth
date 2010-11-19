/** 
* image_generator.h: For talking to camera and generating formatted
*   images for use in vissynth.cpp
* AUTHORS:
* Chang
* Evan
* Sam (smessing@sas.upenn.edu)
* Yui
*/

// Initialize camera:
bool init();

// Pull image in from camera:
void pullImage();

// Transform image into bit rep, add to queue:
void transformImage();

// Dequeue next bit rep:
BitRep* nextRep();