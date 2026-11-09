// from server: 61% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    int b;
};

struct Ret {
    int x;
    int y;
};

extern Ret __cdecl sub_4745E0(int* p);

struct S {
    Ret f(int* p);
};

Ret S::f(int* p) {
    Ret tmp;
    tmp = sub_4745E0(p);
    Ret* out = (Ret*)p;
    out->x = tmp.x;
    out->y = tmp.y;
    if (out->y != 0) {
        _InterlockedExchangeAdd((volatile long*)(out->y + 4), 1);
    }
    return tmp;
}
