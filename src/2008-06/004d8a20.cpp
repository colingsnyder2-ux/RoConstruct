// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Ref {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Ptr {
    void* p;
    Ref* r;
    ~Ptr();
};

__forceinline Ptr::~Ptr()
{
    if (r) {
        Ref* ref = r;
        if (_InterlockedDecrement(&ref->strong) == 0) {
            ref->dispose();
            if (_InterlockedDecrement(&ref->weak) == 0)
                ref->destroy();
        }
    }
}

struct S {
    S* f(Ptr value);
};

S* S::f(Ptr value)
{
    *(volatile int*)((char*)this + 0x00) = 0x826c24;
    *(volatile int*)((char*)this + 0x04) = 0;
    *(volatile int*)((char*)this + 0x08) = 0;
    *(volatile int*)((char*)this + 0x0c) = 0;
    *(volatile int*)((char*)this + 0x10) = 0;
    *(void* volatile*)((char*)this + 0x14) = value.p;
    *(Ref* volatile*)((char*)this + 0x18) = value.r;
    if (value.r)
        _InterlockedIncrement(&value.r->strong);

    *(int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(char*)((char*)this + 0x28) = 0;
    *(char*)((char*)this + 0x2c) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    *(char*)((char*)this + 0x3c) = 0;
    *(char*)((char*)this + 0x40) = 0;
    *(char*)((char*)this + 0x44) = 0;
    return this;
}
