// from server: 50% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    volatile long ref;
};

struct Outer {
    Inner* p;
};

extern Inner* __cdecl sub_6a4e00(int);

void __cdecl sub_6a50e0(Outer* out, int arg)
{
    Inner* tmp = sub_6a4e00(arg);
    out->p = tmp;
    if (tmp->ref != 0) {
        _InterlockedExchangeAdd(&tmp->ref, 1);
    }
}
