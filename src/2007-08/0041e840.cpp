// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
};

struct Inner {
    char pad0[0x18];
    void* field18;
};

struct Outer {
    char pad0[4];
    Inner* inner;
    char pad8[0x10];
    void* field18;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_41da00(void*);
extern "C" void* __cdecl func_41e4f0(void*, void*, void*);
extern "C" void __cdecl func_433140(void*, void*);
extern "C" void __cdecl func_464ec0(void*, void*);
extern "C" void* __cdecl func_62fef6(unsigned int);

struct S {
    void* f(void* a, void* b, void* c, void* d, void* e);
};

void* S::f(void* a, void* b, void* c, void* d, void* e)
{
    void* mem = func_62fef6(0x20);
    void* result;
    if (mem) {
        void* args[4];
        args[0] = a;
        args[1] = b;
        if (b) {
            _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
        }
        args[2] = c;
        args[3] = d;
        if (d) {
            _InterlockedExchangeAdd((volatile long*)((char*)d + 4), 1);
        }
        result = func_41e4f0(mem, this, e);
    } else {
        result = 0;
    }
    void* tmp = result;
    func_464ec0((char*)this + 4, &tmp);
    func_433140(*(void**)((char*)this + 0x18), result);
    func_41da00(&tmp);
    return result;
}
