// from server: 29% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_7f4878(int, int);
extern "C" void __cdecl sub_504860();
extern "C" void __cdecl sub_430a10();

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Holder {
    char pad[0x38];
    RefCounted* ptr;
};

struct S {
    void __thiscall f(Holder* a, RefCounted* b);
};

void __thiscall S::f(Holder* a, RefCounted* b)
{
    RefCounted* old = a->ptr;
    if (old == b) return;
    if (old != 0) {
        _InterlockedExchangeAdd(&old->refcount, 1);
    }
    if (b != 0) {
        if (_InterlockedExchangeAdd(&b->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))((void**)b->vptr)[1])(b);
            if (_InterlockedExchangeAdd(&b->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)b->vptr)[2])(b);
            }
        }
    }
    a->ptr = old;
}
