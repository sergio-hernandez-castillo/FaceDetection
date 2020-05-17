/*******************************************
 * Emilio Popovits : A01027265
 * Sergio Hernandez : A01025210
 * Luis Antonio Garcia : A01021865
 * Eduardo Harari : A01025876

 This is the main method for the initial face detector program.
 *******************************************/

#include "FaceDetection.hpp"

using namespace cv;
using namespace std;

int main(){
    VideoCapture cap;
    vector<Rect> faces;
    //vector<Rect> target;

    FaceDetector Detect("../models/haarcascade_frontalface_alt.xml");   // Creates "Detect" object with custom path to harrcascade
    //string pathImgTest = "../../Feature_Extraction/source/test_images/obama.png"; chrome

    // Necessary if rectangles drawn around the face are needed.
    /*int scale;
    scale = Detect.getScale();*/

    cap = VideoCapture(0);  // Starts videocapture

    // Verifies that videocapture started, if not, ends.
    if (!cap.isOpened()){
        return -1;
    }//Close if 

    for (;;){
        Mat frame;
        cap >> frame;

        //faces = Detect.detection(frame);    // Runs detection() on "frame" which returns rectangle vector

        // Draws rectangle around detected faces
        /*for (Rect area : faces){
            Scalar drawColor = Scalar(255, 0, 0);

            rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
                Point(cvRound(((double)area.x + (double)area.width - 1) * scale),
                    cvRound(((double)area.y + (double)area.height - 1) * scale)), drawColor);

            // Checks if there was a face detected
            /*if (target.empty()){
                cout << "\nTarget face was not detected." << endl;
            } else {    // If face was detected, write "face" under face rectangle
                putText(frame, "Face", 
                Point(cvRound(((double)area.x + (double)area.width - 1) * scale), 
                cvRound(((double)area.y + (double)area.height - 1) * scale)), 
                FONT_HERSHEY_SIMPLEX , 1.0, drawColor, 2);
            }//Close if-else
        }//Close for*/

        // Closes program with q or Q
        imshow("Webcam", frame);
        char c = (char)waitKey(10);

        if (c == 27 || c == 'q' || c == 'Q'){
            break;
        }//Close if
    }//Close for

    return 0;
}//Close main 