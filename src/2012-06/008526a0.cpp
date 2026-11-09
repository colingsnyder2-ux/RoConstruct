// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    volatile long refCount;
};

struct Payload {
    RefCounted* ptr;
    int pad;
    int a;
    int b;
    int c;
    int d;
};

struct Holder {
    Payload* p;
};

struct S {
    int __cdecl f(Holder* h, int x, int y);
};

extern "C" int __cdecl helper(int, int, int, int, int);

int S::f(Holder* h, int x, int y)
{
    Payload* src = h->p;
    Payload tmp;
    tmp.ptr = src->ptr;
    if (tmp.ptr) {
        _InterlockedExchangeAdd(&tmp.ptr->refCount, 1);
    }
    tmp.pad = src->pad;
    tmp.a = src->a;
    tmp.b = src->b;
    tmp.c = src->c;
    tmp.d = src->d;
    return helper(x, y, (int)&tmp, (int)&tmp, 0);
}
