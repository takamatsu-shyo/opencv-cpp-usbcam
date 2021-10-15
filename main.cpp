#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    VideoCapture cap;

    int camId = 0;
    cap.open(camId);

    if(!cap.isOpened()){
        cout << "Camera not found at " << camId;
        return -1;
    }

    Mat frame;

    while(true){
        bool grabSuccess = cap.read(frame);

        if( grabSuccess == false){
            cout << "Failed to grab a frame";
            break;
        }

        imshow("frame", frame);

        if(waitKey(10) == 27){
            cout << "quit by esc";
            break;
        }

    }

    return 0;
}
