// from server: 73% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vfptr;
    volatile long refcount;
};

struct Arg {
    void* p0;
    RefCounted* p1;
};

struct S {
    int f(Arg a, Arg b, int c, float d);
};

int S::f(Arg a, Arg b, int c, float d)
{
    *(int*)((char*)this + 4) = c;
    *(int*)((char*)this + 0) = 0xa8a1cc;
    *(int*)((char*)this + 8) = (int)a.p0;
    *(float*)((char*)this + 0xc) = d;
    *(void**)((char*)this + 0x10) = a.p1;
    RefCounted* r1 = a.p1;
    *(RefCounted**)((char*)this + 0x14) = r1;
    if (r1) {
        _InterlockedExchangeAdd(&r1->refcount, 1);
    }
    *(void**)((char*)this + 0x18) = b.p0;
    RefCounted* r2 = b.p1;
    *(RefCounted**)((char*)this + 0x1c) = r2;
    if (r2) {
        _InterlockedExchangeAdd(&r2->refcount, 1);
    }
    return (int)this;
}
