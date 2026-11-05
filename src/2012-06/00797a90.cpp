// from server: 100% by tajop
struct bad_function_call {
    bad_function_call();
    ~bad_function_call();
    char pad[0x28];
};

__declspec(noreturn) void throw_exception(const bad_function_call& e);

struct FunctionVtable {
    void* manager;
    void (*invoker)(void* functor, float a0);
};

struct FunctionFloat {
    FunctionVtable* vtable;
    int pad;
    char functor[16];
    void operator()(float a0);
};

void FunctionFloat::operator()(float a0) {
    if (!vtable) throw_exception(bad_function_call());
    vtable->invoker(functor, a0);
}
