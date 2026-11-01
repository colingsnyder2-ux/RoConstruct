// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Object {
    char padding[0x50];
    long x;
    long y;
    long z;
};

struct Source {
    long reserved;
    RefCount* control;
    char padding[0x48];
    long value;
};

struct Context {
    long reserved;
    Object* object;
    long padding;
};

extern "C" void __cdecl transfer(long*, long*, long*, long*);

struct S {
    void f(Source*);
};

void S::f(Source* source)
{
    Object* z = (this ? reinterpret_cast<Context*>(
        reinterpret_cast<char*>(this) - 12) : 0)->object;
    Object* y = (this ? reinterpret_cast<Context*>(
        reinterpret_cast<char*>(this) - 12) : 0)->object;
    long* x = &(this ? reinterpret_cast<Context*>(
        reinterpret_cast<char*>(this) - 12) : 0)->object->x;

    long* value = source ? &source->value : 0;
    transfer(value, x, &y->y, &z->z);

    RefCount* control = source->control;
    if (control && _InterlockedDecrement(&control->strong) == 0) {
        control->dispose();
        if (_InterlockedDecrement(&control->weak) == 0)
            control->destroy();
    }
}
