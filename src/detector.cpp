#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
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

  if (!info[0].IsBuffer())
  {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::Buffer<uint8_t> buf = info[0].As<Napi::Buffer<uint8_t>>();
  int bufLength = sizeof(buf) / sizeof(uint8_t);
  cv::Mat img = cv::imdecode(cv::Mat(1, bufLength, CV_8UC1, buf), cv::IMREAD_UNCHANGED);

  // std::cout << bufLength << std::endl;
  // std::cout << "size of uint8_t: " << sizeof(uint8_t) << std::endl;
  // std::cout << "size of img: " << sizeof(img) << std::endl;
  
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
  cv::waitKey(0);

  return env.Null();
}

static Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "detectFaces"), Napi::Function::New(env, detectFaces));
  return exports;
}

NODE_API_MODULE(faces, Init)