// #include <uv.h>
// #include <v8.h>
// #include <nan.h>

// using namespace v8;

// void Run(const Nan::FunctionCallbackInfo<v8::Value>& info) {
//   uv_run(uv_default_loop(), UV_RUN_ONCE);
//   info.GetReturnValue().Set(Nan::Undefined());
// }

// void Init(v8::Local<v8::Object> exports) {
//   exports->Set(Nan::New("run").ToLocalChecked(),
//                Nan::New<v8::FunctionTemplate>(Run)->GetFunction());
// }

// NODE_MODULE(vsync, Init)

// NAN_METHOD(Run) {
//   Nan::HandleScope scope;
//   uv_run(uv_default_loop(), UV_RUN_ONCE);
//   info.GetReturnValue().Set(Nan::Undefined());
// }

// static NAN_MODULE_INIT(init) {
//   Nan::Set(target, Nan::New("run").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Run)).ToLocalChecked());
// }

// NODE_MODULE(vsync, init)

#include <node_api.h>
#include <uv.h>
#include <stdio.h>

napi_value run_event_loop(napi_env env, napi_callback_info args)
{
    napi_status status;

    uv_loop_t* loop;
    status = napi_get_uv_event_loop(env, &loop);

    if (status != napi_ok)
        return NULL;

    uv_run(loop, UV_RUN_ONCE);

    napi_value out;
    status = napi_get_undefined(env, &out);

    if (status != napi_ok)
        return NULL;
    return out;
}

napi_value init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value func;

    status = napi_create_function(
        env,
        "tick_event_loop",
        NAPI_AUTO_LENGTH,
        run_event_loop,
        NULL,
        &func
    );

    if (status != napi_ok)
        return NULL;
    return func;
}

NAPI_MODULE(DEASYNC, init)