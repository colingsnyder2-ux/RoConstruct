// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_007a79a0(unsigned int);
extern "C" void* __cdecl func_0079b5b0();
extern "C" void __cdecl func_0079a770();

struct RefCounted {
    void** vptr;
    long refcount;
    long weakref;
};

struct Inner {
    void* field0;
    RefCounted* field4;
};

struct Outer {
    char pad[0x380];
    Inner inner;
};

struct S {
    void method(void* a, void* b);
};

void S::method(void* a, void* b)
{
    void* p = func_007a79a0(0x1f8);
    if (p) {
        RefCounted* r = (RefCounted*)b;
        if (r) {
            _InterlockedExchangeAdd(&r->refcount, 1);
        }
        ((void (__thiscall*)(void*, void*, void*))0x473600)(p, a, b);
    } else {
        p = 0;
    }
    Outer* outer = (Outer*)((char*)this + 0x380);
    ((void (__thiscall*)(Outer*, void*))0x473960)(outer, p);
    Inner* inner = &outer->inner;
    RefCounted* r2 = inner->field4;
    void* v = inner->field0;
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }
    void* q = func_0079b5b0();
    ((void (__thiscall*)(void*, void*, RefCounted*))0x79a770)(q, v, r2);
    if (r2) {
        if (_InterlockedExchangeAdd(&r2->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))r2->vptr[1])(r2);
            if (_InterlockedExchangeAdd(&r2->weakref, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))r2->vptr[2])(r2);
            }
        }
    }
}
