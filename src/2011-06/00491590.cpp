// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    volatile long ref;
};

struct Outer {
    Inner* p;
};

extern Inner* __cdecl func_00491400(int*);

void func_00491590(int* out, int arg)
{
    Inner* r = func_00491400(&arg);
    out[0] = (int)r->a;
    Inner* tmp = r;
    out[1] = (int)tmp->ref;
    if (tmp->ref != 0)
        _InterlockedExchangeAdd(&tmp->ref, 1);
}
