// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __cdecl sub_854A90(void*, void*, void*);
extern "C" void __cdecl sub_41C010();
extern "C" void __cdecl sub_708980();
extern "C" void __cdecl sub_76D7E0();
extern "C" void __cdecl sub_770000();
extern "C" void __cdecl sub_41B230();
extern "C" void __cdecl sub_41AF50();
extern "C" void __cdecl sub_98B20C();
extern "C" void __cdecl sub_B90258();
extern "C" void __cdecl sub_B7A220();

struct S {
    void f(int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* p = sub_7F3860(0x48);
    void* q = 0;
    if (p) {
        q = p;
        sub_770000();
    }
    sub_76D7E0();
    sub_854A90(0, 0, 0);
    sub_41C010();
    sub_708980();
    sub_98B20C();
    sub_B90258();
    sub_41B230();
    sub_B7A220();
    sub_41AF50();
    if (q) {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), -1);
    }
}
