#include <cv.h>
#include <highgui.h>
int main(int argc, char** argv)
{
        IplImage* src = cvLoadImage("b.jpg",0);
 
        IplImage* dst = cvCreateImage( cvGetSize(src),IPL_DEPTH_8U,1);
        IplImage* color_dst = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U,3);
        CvMemStorage* storage = cvCreateMemStorage(0);
        CvSeq* lines = 0;
        int i;
        cvCanny( src, dst, 50, 150, 3 );
        cvCvtColor( dst, color_dst, CV_GRAY2BGR );
		
	
        lines = cvHoughLines2( dst,storage, CV_HOUGH_PROBABILISTIC,1, CV_PI/180, 10,30,10 );

        for( i = 0; i < lines->total; i++ )
        {
           CvPoint* line = (CvPoint*)cvGetSeqElem(lines,i);
           //cvLine( color_dst, line[0], line[1], CV_RGB(255,0,0), 3, 8 );
           cvLine( color_dst, line[0], line[1], CV_RGB(0,0,0), 1, 8 );
        }
		
	       
		cvNamedWindow( "Source", 1 );
        cvShowImage( "Source", src );

        cvNamedWindow( "Hough", 1 );
        cvShowImage( "Hough", color_dst );

		
        cvWaitKey(0);
        return 0;
   
}
