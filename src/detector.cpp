#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cstdio>
#include <napi.h>

static Napi::Value detectFaces(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1)
  {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  // if (!info[0].IsString())
  // {
  //   Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
  //   return env.Null();
  // }

  std::string arg0 = info[0].As<Napi::String>();
  cv::Mat img = cv::imread(arg0);

  // Load Face cascade (.xml file)
  cv::CascadeClassifier face_cascade;
  face_cascade.load( "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml" );

  if (face_cascade.empty())
  {
    Napi::TypeError::New(env, "Error Loading XML file").ThrowAsJavaScriptException();
    return env.Null();
  }

  // Detect faces
  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale( img, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );

  // Draw circles on the detected faces
  for ( size_t i = 0; i < faces.size(); i++ )
  {
    cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    cv::ellipse( img, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
  }

  cv::imshow("img", img);
  cv::waitKey();

  return env.Null();
}

static Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "detectFaces"), Napi::Function::New(env, detectFaces));
  return exports;
}

NODE_API_MODULE(faces, Init)


// NAN_METHOD() 
// {
//   Mat image;
//   image = info[0]->IsObject();
//   imshow( "window1", image );

//   // Load Face cascade (.xml file)
//   CascadeClassifier face_cascade;
//   face_cascade.load( "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml" );

//   if (face_cascade.empty())
//   {
//     cout << "Error Loading XML file" << endl;
//   }
 
//   // Detect faces
//   vector<Rect> faces;
//   face_cascade.detectMultiScale( image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30) );

//   // Draw circles on the detected faces
//   for ( size_t i = 0; i < faces.size(); i++ )
//   {
//     Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
//     ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
//   }
    
//   imshow( "Detected Faces", image ); 
//   waitKey(0);
// }