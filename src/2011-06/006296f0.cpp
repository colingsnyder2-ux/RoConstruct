// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_40A950(void*);
extern "C" void* __cdecl sub_402560(void*);
extern "C" void* __cdecl sub_5B1D80(void*);
extern "C" void* __cdecl sub_5B1B20(void*);
extern "C" void* __cdecl sub_592F60(void*);
extern "C" void* __cdecl sub_597910(void*);
extern "C" void* __cdecl sub_61B9B0(void*);
extern "C" void* __cdecl sub_721520(void*);
extern "C" void* __cdecl sub_7F90B0(void*);
extern "C" void* __cdecl sub_80B0AC(void*);
extern "C" void* __cdecl sub_46F000(void*);
extern "C" void* __cdecl sub_6282B0(void*);

struct S {
    void f(int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    int v1 = 1;
    if (a1 == 0) {
        sub_40A950(0);
        sub_80B0AC(0);
    }
    if (a2 == 0) {
        sub_721520(0);
        sub_402560(0);
    }
    sub_592F60(0);
    sub_5B1D80(0);
    sub_5B1B20(0);
    sub_7F90B0(0);
    sub_46F000(0);
    sub_61B9B0(0);
    sub_597910(0);
    sub_6282B0(0);
}
