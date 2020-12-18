#include <napi.h>
#include "detector.h"

using namespace Napi;  
using namespace std;

Number detectFacesWrapped(const CallbackInfo& info) 
{
  Env env = info.Env();

  return Number::New(env, detectFaces());
}

Object Init(Env env, Object exports) 
{
  exports.Set("faces", Function::New(env, detectFacesWrapped));

  return exports;
}

NODE_API_MODULE(faces, Init)