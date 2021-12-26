#include <nan.h>
#include <stdio.h>
#include <clip.h>
#include <stdlib.h>
#include <iostream>

using namespace v8;

NAN_METHOD(Print)
{
  if (!info[0]->IsString())
    return Nan::ThrowError("Must pass a string");
  Nan::Utf8String path(info[0]);
  std::string value;
  clip::get_text(value);
  std::cout << value << "\n";
  printf("Printed from C++ Test: %s\n", *path);
}

NAN_MODULE_INIT(InitAll)
{
  Nan::Set(target, Nan::New<String>("print").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Print)).ToLocalChecked());
}

NODE_MODULE(a_native_module, InitAll)
