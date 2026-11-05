// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vfptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Inner {
    int a;
    int b;
    int c;
    RefCounted* d;
    int e;
};

struct Target {
    int f0;
    int f1;
    int f2;
    void construct(int a, int b, int c, RefCounted* r, int extra);
};

void __stdcall helper(Target* self, Inner* inner);

void Target::construct(int a, int b, int c, RefCounted* r, int extra)
{
    Inner inner;
    inner.a = a;
    inner.b = b;
    inner.c = c;
    inner.d = r;
    inner.e = extra;
    f0 = 0;
    f1 = 0;
    f2 = 0;
    if (r) {
        _InterlockedExchangeAdd(&r->refCount, 1);
    }
    helper(this, &inner);
    if (r) {
        if (_InterlockedExchangeAdd(&r->refCount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))r->vfptr)(r);
            if (_InterlockedExchangeAdd(&r->weakCount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)(r->vfptr))[2])(r);
            }
        }
    }
}
