// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_54c6d0();
extern "C" void __cdecl sub_413890();
extern "C" void __cdecl sub_8c05f0();
extern "C" void* __cdecl sub_40b9c0();
extern "C" void __stdcall SetEvent(void*);

struct S
{
    char pad[0x10];
    void* field10;
    void f();
};

void S::f()
{
    if (field10 != 0)
    {
        void* p = sub_54c6d0();
        char flag = 0;
        sub_413890();
        void* old = field10;
        field10 = 0;
        if (old != 0)
        {
            sub_8c05f0();
        }
        if (flag != 0)
        {
            long prev = _InterlockedExchangeAdd((volatile long*)p, (long)0x80000000);
            if ((prev & 0x40000000) == 0 && prev > (long)0x80000000)
            {
                long bit = _InterlockedExchangeAdd((volatile long*)p, 0);
                (void)bit;
                SetEvent(sub_40b9c0());
            }
        }
    }
}
