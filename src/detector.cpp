#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <napi.h>

static Napi::Value detectFaces(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 3)
  {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  Napi::ArrayBuffer buf = info[0].As<Napi::ArrayBuffer>();
  long bufLength = info[1].As<Napi::Number>();
  std::string path2cascades = info[2].As<Napi::String>();
  
  cv::Mat rawData(1, bufLength, CV_8UC1, buf.Data());
  cv::Mat decodedImg = cv::imdecode(rawData, cv::IMREAD_UNCHANGED);

  // cv::Mat decodedImg = cv::imdecode(cv::Mat(1, bufLength, CV_8UC1, buf.Data()), cv::IMREAD_UNCHANGED);

  if ( decodedImg.data == NULL )   
  {
    Napi::TypeError::New(env, "Error reading raw image data").ThrowAsJavaScriptException();
    return env.Null();
  }
 
  // --- Load Face cascade (.xml file) ---
  cv::CascadeClassifier face_cascade;
  face_cascade.load( path2cascades );

  if (face_cascade.empty())
  {
    Napi::TypeError::New(env, "Error Loading XML file").ThrowAsJavaScriptException();
    return env.Null();
  }

  // --- Detect faces ---
  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale( decodedImg, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );

  // --- Draw circles on the detected faces ---
  for ( size_t i = 0; i < faces.size(); i++ )
  {
    cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    cv::ellipse( decodedImg, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
  }

  cv::imshow("img", decodedImg);
  cv::waitKey(0);

  return env.Null();
}

static Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "detectFaces"), Napi::Function::New(env, detectFaces));
  return exports;
}

NODE_API_MODULE(faces, Init)