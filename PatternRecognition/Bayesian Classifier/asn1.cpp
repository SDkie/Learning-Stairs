

#include "opencv2/core/core.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>

using namespace std;
using namespace cv;

const Scalar WHITE_COLOR = CV_RGB(255,255,255);
const string winName = "points";
const int testStep = 5;


Mat img, imgDst;
RNG rng;

vector<Point>  trainedPoints;
vector<int>    trainedPointsMarkers;
vector<Scalar> classColors;

#define NBC 1 // normal Bayessian classifier

void on_mouse( int event, int x, int y, int /*flags*/, void* )
{
    if( img.empty() )
        return;

    int updateFlag = 0;

    if( event == CV_EVENT_LBUTTONUP )
    {
        if( classColors.empty() )
            return;

        trainedPoints.push_back( Point(x,y) );
        trainedPointsMarkers.push_back( classColors.size()-1 );
        updateFlag = true;
    }
    else if( event == CV_EVENT_RBUTTONUP )
    {
            classColors.push_back( Scalar((uchar)rng(256), (uchar)rng(256), (uchar)rng(256)) );
            updateFlag = true;

    }

    //draw
    if( updateFlag )
    {
        img = Scalar::all(0);

        // put the text
        stringstream text;
        text << "current class " << classColors.size()-1;
        //putText( img, text.str(), Point(10,25), CV_FONT_HERSHEY_SIMPLEX, 0.8f, WHITE_COLOR, 2 );

        text.str("");
        text << "total classes " << classColors.size();
        //putText( img, text.str(), Point(10,50), CV_FONT_HERSHEY_SIMPLEX, 0.8f, WHITE_COLOR, 2 );

        text.str("");
        text << "total points " << trainedPoints.size();
        //putText(img, text.str(), cvPoint(10,75), CV_FONT_HERSHEY_SIMPLEX, 0.8f, WHITE_COLOR, 2 );

        // draw points
        for( size_t i = 0; i < trainedPoints.size(); i++ )
            circle( img, trainedPoints[i], 5, classColors[trainedPointsMarkers[i]], -1 );

        imshow( winName, img );
   }
}

void prepare_train_data( Mat& samples, Mat& classes )
{
    Mat( trainedPoints ).copyTo( samples );
    Mat( trainedPointsMarkers ).copyTo( classes );

    // reshape trainData and change its type
    samples = samples.reshape( 1, samples.rows );
    samples.convertTo( samples, CV_32FC1 );
}


void find_decision_boundary_NBC()
{
    img.copyTo( imgDst );

    Mat trainSamples, trainClasses;
    prepare_train_data( trainSamples, trainClasses );

    // learn classifier
    CvNormalBayesClassifier normalBayesClassifier( trainSamples, trainClasses );

    Mat testSample( 1, 2, CV_32FC1 );
    for( int y = 0; y < img.rows; y += testStep )
    {
        for( int x = 0; x < img.cols; x += testStep )
        {
            testSample.at<float>(0) = (float)x;
            testSample.at<float>(1) = (float)y;

            int response = (int)normalBayesClassifier.predict( testSample );
            circle( imgDst, Point(x,y), 1, classColors[response] );
        }
    }
}


int main()
{
    cout << "Use:" << endl
         << "  right mouse button - to add new class;" << endl
         << "  left mouse button - to add new point;" << endl
         << "  key 'r' - to run the ML model;" << endl
         << "  key 'i' - to init (clear) the data." << endl << endl;

    cv::namedWindow( "points", 1 );
    img.create( 480, 640, CV_8UC3 );
    imgDst.create( 480, 640, CV_8UC3 );

    imshow( "points", img );
    cvSetMouseCallback( "points", on_mouse );

    for(;;)
    {
        uchar key = (uchar)waitKey();

        if( key == 27 ) break;

        if( key == 'i' ) // init
        {
            img = Scalar::all(0);

            classColors.clear();
            trainedPoints.clear();
            trainedPointsMarkers.clear();

            imshow( winName, img );
        }

        if( key == 'r' ) // run
        {

            find_decision_boundary_NBC();
            cvNamedWindow( "NormalBayesClassifier", WINDOW_AUTOSIZE );
            imshow( "NormalBayesClassifier", imgDst );

        }
    }

    return 1;
}
