// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    if (control && _InterlockedExchangeAdd(&control->strong, -1) == 1) {
        control->dispose();
        if (_InterlockedExchangeAdd(&control->weak, -1) == 1)
            control->destroy();
    }
}



struct Value {
    std::string text;
    Shared owner;
};

struct Receiver {
    void invoke(std::string text, Shared owner);
};

struct Context {
    unsigned char padding[16];
    unsigned char* receiver;
};

struct S {
    Value* value;
    void* f(void* result, Context* context);
};

void* S::f(void* result, Context* context) {
    Receiver* receiver =
        reinterpret_cast<Receiver*>(context->receiver + 8);
    receiver->invoke(value->text, value->owner);
    return result;
}
