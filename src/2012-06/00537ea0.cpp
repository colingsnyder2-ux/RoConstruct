// from server: 44% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_52DE80();
extern "C" void __cdecl sub_413890(int*);
extern "C" void __cdecl sub_8C05F0(void*);
extern "C" int __cdecl sub_40B9C0();
extern "C" void __stdcall SetEvent(void*);

struct SlotCallable
{
    void *vptr;
    char pad[12];
    int field_10;

    void f();
};

void SlotCallable::f()
{
    int v4;
    sub_52DE80();
    int *v5 = &v4;
    sub_413890(v5);
    int v6 = field_10;
    field_10 = 0;
    if (v6)
    {
        sub_8C05F0(this);
    }
    if (v4)
    {
        long old = _InterlockedExchangeAdd((volatile long*)v6, 0x80000000);
        if (!(old & 0x40000000) && old != 0x80000000 && old > 0x80000000)
        {
            _InterlockedExchangeAdd((volatile long*)v6, 0x40000000);
            int hEvent = sub_40B9C0();
            SetEvent((void*)hEvent);
        }
    }
}
