// from server: 8% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_401630();
extern "C" void __cdecl sub_4020a0();
extern "C" int __cdecl sub_419ef0();
extern "C" void __cdecl sub_41a180();
extern "C" void __cdecl sub_41a440();
extern "C" void __cdecl sub_41a560();
extern "C" void __cdecl sub_442240();

struct CInsertObjectDialog {
    void func(int* arg);
};

void CInsertObjectDialog::func(int* arg)
{
    sub_401630();
    int v = sub_419ef0();
    if (arg[1] == v)
        return;
    sub_41a180();
    sub_442240();
    sub_41a560();
    sub_41a440();
    sub_4020a0();
}
