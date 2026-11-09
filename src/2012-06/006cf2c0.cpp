// from server: 2% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_0052dfe0();
extern "C" void __stdcall sub_00531370();
extern "C" void __stdcall sub_00684c80();

struct S_func_006cf2c0 {
    void f(int a, int b, int c, int d);
};

void S_func_006cf2c0::f(int a, int b, int c, int d)
{
    char pad[0x28];
    int local14 = 0;
    int local1c = 0;
    int local28 = 0;
    int local30 = 0;
    int local34 = 0;
    int local3c = 0;
    int local44 = 0;
    int local48 = 0;
    int local50 = 0;
    int local5c = 0;
    (void)pad;
    (void)local14;
    (void)local1c;
    (void)local28;
    (void)local30;
    (void)local34;
    (void)local3c;
    (void)local44;
    (void)local48;
    (void)local50;
    (void)local5c;
    (void)a;
    (void)b;
    (void)c;
    (void)d;
}
