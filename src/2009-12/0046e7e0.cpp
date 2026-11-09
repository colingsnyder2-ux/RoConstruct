// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" int __cdecl sub_46E620();
extern "C" void __cdecl sub_46E0D0();
extern "C" void __cdecl sub_854A90();
extern "C" void __cdecl sub_41C010();
extern "C" void __cdecl sub_708980();
extern "C" void __cdecl sub_41B230();
extern "C" void __cdecl sub_41AF50();

struct S {
    void f(int, int, int);
};

void S::f(int a, int b, int c)
{
    void* p = sub_7F3860(0x48);
    int* obj = 0;
    if (p != 0) {
        obj = (int*)sub_46E620();
    }
    sub_46E0D0();
    sub_854A90();
    sub_41C010();
    sub_708980();
    sub_41B230();
    sub_41AF50();
}
