// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* c = control;
    if (c) {
        if (_InterlockedDecrement(&c->strong) == 0) {
            c->dispose();
            if (_InterlockedDecrement(&c->weak) == 0)
                c->destroy();
        }
    }
}

struct Object {
    void method();
};

void __stdcall f(Object* object, Shared shared)
{
    object->method();
}
