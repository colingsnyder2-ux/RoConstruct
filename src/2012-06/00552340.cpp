// from server: 0% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl sub_5c9fe8(int, int, int);
extern "C" void __cdecl sub_511180(int);
extern "C" void __cdecl sub_5470a0(int);
extern "C" void __cdecl sub_547120(int, int);
extern "C" void __cdecl sub_5476a0(int);

extern "C" byte data_e580e1;

struct S
{
    char f(int);
};

extern "C" char __fastcall sub_5504a0(void*, int, int);

char S::f(int)
{
    int local;
    local = 0;

    if (data_e580e1 != 0)
    {
        sub_5c9fe8((int)data_e580e1, 0xb44eb8, 0);
    }

    while (sub_5504a0(this, 0, (int)&local))
    {
        sub_547120((int)&local + 4, (int)&local);
        sub_5476a0(local);
    }

    sub_511180((int)&local);
    sub_5470a0((int)&local + 4);
    return 0;
}
