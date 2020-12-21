#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cstdio>
#include "detector.h"

using namespace std;
using namespace cv;
using namespace v8;

NAN_METHOD(detectFaces) 
{
  Mat image;
  image = info[0]->IsObject();
  imshow( "window1", image );

  // Load Face cascade (.xml file)
  CascadeClassifier face_cascade;
  face_cascade.load( "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml" );

  if (face_cascade.empty())
  {
    cout << "Error Loading XML file" << endl;
  }
 
  // Detect faces
  vector<Rect> faces;
  face_cascade.detectMultiScale( image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30) );

  // Draw circles on the detected faces
  for ( size_t i = 0; i < faces.size(); i++ )
  {
    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
  }
    
  imshow( "Detected Faces", image ); 
  waitKey(0);
}