// from server: 58% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void __stdcall sub_6DBD00();

struct S {
    char pad0[4];
    char pad4[1];
    char pad5[3];
    int field8;
    int fieldC;
    int field10;
    char pad14[4];
    int field18;
    char pad1C[0x1C];
    int field38;
    int field3C;
    int field40;
    int field44;
    S(int, int, int, int, int, int, int);
};

S::S(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    InterlockedIncrement((long*)0xc007ac);
    *(int*)this = 0xa0399c;
    *(char*)((char*)this + 5) = 1;
    field8 = 0;
    fieldC = *(int*)0xa54060;
    field10 = a7;
    *(int*)this = 0xa184d0;
    *(int*)((char*)this + 0x18) = 0;
    int args[6];
    args[0] = a1;
    args[1] = a2;
    args[2] = a3;
    args[3] = a4;
    args[4] = a5;
    args[5] = a6;
    sub_6DBD00();
    field38 = 0;
    field3C = 0;
    field40 = 0;
    field44 = 0;
}
