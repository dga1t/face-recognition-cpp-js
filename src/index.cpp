#include <nan.h>
#include "detector.h"

using v8::FunctionTemplate;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_MODULE_INIT(InitAll) {
  Set(target, New("detectFaces").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(detectFaces)).ToLocalChecked());
}

NODE_MODULE(faces, InitAll)