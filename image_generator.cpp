#include "image_generator.h"

// OpenCV: http://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.1/OpenCV-2.1.0-win32-vs2008.exe/download
//  *** When installing, "Add OpenCV to the system PATH for all users"
// Reference for install: http://dasl.mem.drexel.edu/~noahKuntz/openCVTut1.html
// To link libs: Project Properties / Configuration Properties / Linker / Input / Additional Dependencies
//   Libs: cv.lib, ml.lib, cxcore.lib, and highgui.lib
//   NOTE: cv210.lib, ml210.lib, cxcore210.lib, and highgui210.lib :)
// If you had Visual Studio open while doing this, please restart it
//    
// Need to add OpenCV include, lib to their respective paths
//   http://www.lavishsoft.com/wiki/index.php/Visual_Studio_Paths#Visual_Studio_2005.2C_2008
//
// OpenCV filter for binary black/white
// Code samples from http://stackoverflow.com/questions/1585535/convert-rgb-2-black-white-in-opencv
// Useful for OpenCV... http://opencv.willowgarage.com/wiki/CameraCapture

ImageGenerator::ImageGenerator() {
    // TODO
    //frame = NULL;
    //frameProcessed = NULL;
}

ImageGenerator::~ImageGenerator() {
    // Clean up the webcam
    cvReleaseCapture(&capture);

    // Clean up the display windows
    cvDestroyWindow("Last Snapshot Preprocess");
    cvDestroyWindow("Last Snapshot");
}

bool ImageGenerator::init() {
    // Open the webcam
    capture = cvCaptureFromCAM(CV_CAP_ANY);
    if(!capture)
         return false;

    // Open the display windows
    cvNamedWindow("Last Snapshot Preprocess", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Last Snapshot", CV_WINDOW_AUTOSIZE);
    return true;
}

bool ImageGenerator::pullImage(BitRep &br) {
    // Grab a frame from the webcam - this must free the previous frame
    //   because I don't free it anywhere, yet it magically doesn't leak :P
    frame = cvQueryFrame(capture);
    if(!frame)
        return false;

    //if(frameProcessed != NULL)
    //    cvReleaseImage(&frameProcessed);

    // Filter to black/white, threshold 128/255
    // http://stackoverflow.com/questions/1585535/convert-rgb-2-black-white-in-opencv
    IplImage *im_gray = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
    cvCvtColor(frame,im_gray,CV_RGB2GRAY);

    // frameProcessed is IPL_DEPTH_8U, 8 bit unsigned image
    frameProcessed = cvCreateImage(cvGetSize(im_gray),IPL_DEPTH_8U,1);
    cvThreshold(im_gray, frameProcessed, 128, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    cvReleaseImage(&im_gray);

    // Display the unprocessed frame
    cvShowImage("Last Snapshot Preprocess", frame);

    // Display the processed frame
    cvShowImage("Last Snapshot", frameProcessed);

    if(!fillBitRep(frameProcessed, br))
        return false;
    
    // After we've used the processed image, free it up
    if(frameProcessed != NULL)
        cvReleaseImage(&frameProcessed);

    return true;
}

bool ImageGenerator::fillBitRep(IplImage *img, BitRep &br) {
    if(frameProcessed == NULL)
        return false;

    uchar* pixelOrigin = (uchar *)img->imageData;
    int brRows = br.getRows();
    int brCols = br.getCols();
    int imgHeight = img->height;
    int imgWidth = img->width;
    int stepRow = imgHeight / br.getRows();
    int stepCol = imgWidth / br.getCols();

    for(int row = 0; row < brRows; row++) {
        for(int col = 0; col < brCols; col++) {
            //br.setBit(row, col, pixelOrigin[(int)(row+.5)*stepRow*imgWidth + (int)(col+.5)*stepCol] > 0);
            br.setBit(row, col, pixelOrigin[row*stepRow*imgWidth + col*stepCol] > 0);
        }
    }
    return true;
}