/*******************************************
 * Emilio Popovits : A01027265
 * Sergio Hernandez : A01025210
 * Luis Antonio Garcia : A01021865
 * Eduardo Harari : A01025876

 In this file, all of the methods declared in the header file "FaceDetector.h" are initialized.
 This file contains the method for opening the camera, recognizing a human face, and drawing a square around it.
 *******************************************/

#include "FaceDetection.hpp"
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace cv;

// Default constructor, initializes variables with "default" values (set by us)
FaceDetector::FaceDetector(){
    faceCascade.load("../models/haarcascade_frontalface_alt.xml");
    size = 30;
    scale = 5.0;
    window_scaling = 1.1; //This multiplies by the size to find the next bigger image, if there even is one to begin with 
    minClassifiers = 4;
    imgHeight = 30;
    flags = 0;
}

// Constructor that initializes faceCascade path to a chosen one
FaceDetector::FaceDetector(const string path){
    faceCascade.load(path);
    size = 30;
    scale = 5.0;
    window_scaling = 1.1; //This multiplies by the size to find the next bigger image, if there even is one to begin with 
    minClassifiers = 4;
    imgHeight = 30;
    flags = 0;
}
    
// Overload constructor that initializes every other variable to user choice
FaceDetector::FaceDetector(string faceCascadeFile, int scale, int size, double scale_factor, int minConsensus, int flag){
    faceCascade.load(faceCascadeFile);
    this->scale = scale;
    this->size = size;
    window_scaling = scale_factor;
    minClassifiers = minConsensus;
    imgHeight = size;
    flags = flag;
}

// Converts image into grayscale, detects faces of different sizes and returns a list of different-sized faces as rectangle vectors
vector<Rect> FaceDetector::detection(Mat frame){
    vector<Rect> faces;
    Mat grayscale;

    cvtColor(frame, grayscale, COLOR_BGR2GRAY); // Converts "frame" image into grayscale and outputs into "grayscale"

    auto start = high_resolution_clock::now();  // Starts timer for execution time of face detection

    // Resizes image, necessary if rectangles drawn around the face are needed.
    //resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));

    // Detects faces of different sizes and returns a list of rectangles in "faces"
    FaceDetector::faceCascade.detectMultiScale(grayscale, faces, window_scaling, minClassifiers, flags, cv::Size(size, size));
    
    auto stop = high_resolution_clock::now();   // Stops timer for execution time of face detection
    auto duration = duration_cast<microseconds>(stop - start);  // Calculates duration for execution time of face detection
    cout << "\nExecution time for detecting a face: " << duration.count() << " microseconds." << endl;  // Prints execution time

    return faces;   // Returns faces of different sizes as rectangle vectors
}

// Method suposed to tell apart faces
vector<Rect> FaceDetector::identify(Mat img, vector<Rect> facesArray){
    vector<Rect> faces;

    if (img.empty()){
        cout << "The path to the image is incorrect";
        //exit(0);
    }

    else {
        faceCascade.detectMultiScale(img, faces);   // This line of code is wrong, will not tell apart faces
    }

    return faces;
}

// Getter method for scale variable
int FaceDetector::getScale(){
    return scale;
}