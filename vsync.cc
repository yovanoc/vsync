#include <uv.h>
#include <v8.h>
#include <nan.h>

using namespace v8;

void Run(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  uv_run(uv_default_loop(), UV_RUN_ONCE);
  info.GetReturnValue().Set(Nan::Undefined());
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("run").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Run)->GetFunction());
}

NODE_MODULE(vsync, Init)

// NAN_METHOD(Run) {
//   Nan::HandleScope scope;
//   uv_run(uv_default_loop(), UV_RUN_ONCE);
//   info.GetReturnValue().Set(Nan::Undefined());
// }

// static NAN_MODULE_INIT(init) {
//   Nan::Set(target, Nan::New("run").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Run)).ToLocalChecked());
// }

// NODE_MODULE(vsync, init)
