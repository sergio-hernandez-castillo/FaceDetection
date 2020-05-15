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

    FaceDetector Detect("../models/haarcascade_frontalface_alt.xml");
    //string pathImgTest = "../../Feature_Extraction/source/test_images/obama.png";

    //Mat imgTest = imread(pathImgTest, IMREAD_UNCHANGED);

    // Necessary if rectangles drawn around the face are needed.
    /*int scale;
    scale = Detect.getScale();*/

    cap = VideoCapture(0);

    if (!cap.isOpened()){
        return -1;
    }//Close if 

    for (;;){
        Mat frame;
        cap >> frame;

        faces = Detect.detection(frame);
        //target = Detect.identify(imgTest);

        /*for (Rect area : faces){
            Scalar drawColor = Scalar(255, 0, 0);

            rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
                Point(cvRound(((double)area.x + (double)area.width - 1) * scale),
                    cvRound(((double)area.y + (double)area.height - 1) * scale)), drawColor);

            if (target.empty()){
                cout << "\nTarget face was not detected." << endl;
            }//Close if 

            else {
                putText(frame, "Face", 
                Point(cvRound(((double)area.x + (double)area.width - 1) * scale), 
                cvRound(((double)area.y + (double)area.height - 1) * scale)), 
                FONT_HERSHEY_SIMPLEX , 1.0, drawColor, 2);
            }
        }//Close for*/

        imshow("Webcam", frame);
        char c = (char)waitKey(10);

        if (c == 27 || c == 'q' || c == 'Q'){
            break;
        }//Close if
    }//Close for

    //faces = Detect.originalSize(faces);

    return 0;
}//Close main 