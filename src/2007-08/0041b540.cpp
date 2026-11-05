// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    volatile long refCount1;
    volatile long refCount2;
};

extern "C" void __cdecl sub_417860(int);
extern "C" void __cdecl sub_40cc20(void*, int, int);
extern "C" void __cdecl sub_41b480(void*);
extern "C" void __cdecl sub_417c70(int, void*, int);
extern "C" void __cdecl sub_49a230(void*);

struct S {
    int __thiscall f(int a, int b, int c, int d);
};

int __thiscall S::f(int a, int b, int c, int d)
{
    int local0 = 0;
    int local4 = a;
    int local8 = 0;
    int localC = 0;
    int local10 = 0;
    int local14 = 0;
    int local18 = 0;
    int local1C = 0;
    int local20 = 0;

    sub_417860(a);
    sub_40cc20(&local4, a, a);
    sub_41b480(&local8);
    sub_417c70(b, &local4, c);
    sub_49a230(&local8);

    if (local4 != 0) {
        RefCounted* p = (RefCounted*)local4;
        if (_InterlockedExchangeAdd(&p->refCount1, -1) == 1) {
            p->unknown0();
            if (_InterlockedExchangeAdd(&p->refCount2, -1) == 1) {
                p->unknown1();
            }
        }
    }

    return c;
}
