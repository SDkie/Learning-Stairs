#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

using namespace std;


// This function separates the blue colored region
IplImage* GetThresholdedImage(IplImage* imgHSV){
       IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       cvInRangeS(imgHSV, CV_RGB(0,0,0), CV_RGB(50,255,255), imgThresh);
       return imgThresh;
}

int main(){
      CvCapture* capture =0;
      IplImage* frame=0;
      cvNamedWindow("input");
      cvNamedWindow("output");

      IplImage* imgHSV = cvLoadImage("ip.png");
  cvShowImage("input", imgHSV);


            IplImage* imgThresh = GetThresholdedImage(imgHSV);

            cvShowImage("output", imgThresh);

            int c = cvWaitKey(10000);
            cvReleaseImage(&imgHSV);
            cvReleaseImage(&imgThresh);
            //Wait for key input

      cvDestroyAllWindows();

      return 0;
}
