#include <nan.h>
#include "detector.h"

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("detectFaces").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(detectFaces)).ToLocalChecked());
}

NODE_MODULE(faces, Init);