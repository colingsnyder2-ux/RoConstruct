// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int a;
    int b;
};

struct Mid {
    int x;
    int y;
};

struct S {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    char f1c;
};

extern "C" void* __stdcall sub_62FEF6(unsigned int);
extern "C" void __stdcall sub_728830();
extern "C" void __stdcall sub_41B370();
extern "C" void __stdcall sub_4181B0();

struct Outer {
    int m0;
    int m4;
    S   m8;

    Outer* ctor(Mid* arg);
};

Outer* Outer::ctor(Mid* arg)
{
    m0 = 0;
    m4 = 0;

    Mid local;
    local.x = arg->x;
    local.y = arg->y;
    if (local.y != 0) {
        _InterlockedExchangeAdd((volatile long*)(local.y + 4), 1);
    }

    sub_41B370();

    S* p = (S*)sub_62FEF6(0x20);
    if (p != 0) {
        p->f4 = 0;
        p->f8 = 0;
        p->fc = 0;
        p->f14 = 0;
        p->f18 = 0;
        p->f1c = 0;
    } else {
        p = 0;
    }

    sub_4181B0();

    sub_728830();

    return this;
}
