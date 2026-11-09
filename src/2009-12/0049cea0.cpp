// from server: 85% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Arg {
    void* p0;
    RefCounted* p4;
};

struct S {
    int f(Arg* a, Arg* b, int c);
};

int S::f(Arg* a, Arg* b, int c) {
    *(int*)((char*)this + 4) = c;
    *(int*)((char*)this + 0) = 0x9b3a5c;
    *(int*)((char*)this + 8) = 0;
    *(float*)((char*)this + 0xc) = 0.0f;
    *(void**)((char*)this + 0x10) = a->p0;
    RefCounted* r1 = a->p4;
    *(RefCounted**)((char*)this + 0x14) = r1;
    if (r1) {
        _InterlockedExchangeAdd(&r1->refcount, 1);
    }
    *(void**)((char*)this + 0x18) = b->p0;
    RefCounted* r2 = b->p4;
    *(RefCounted**)((char*)this + 0x1c) = r2;
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }
    return (int)this;
}
