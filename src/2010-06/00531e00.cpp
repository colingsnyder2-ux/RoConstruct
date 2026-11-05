// from server: 63% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" bool __stdcall sub_6cfb90(int, int, int, int, int*);

struct G3DPart {
    char pad0[4];
    char f4;
    char pad5[3];
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    char pad1c[4];
    char f20[0x18];
    int f38;
    int f3c;
    int f40;
    int f44;
    G3DPart(int, int, int, int, int);
};

G3DPart::G3DPart(int a1, int a2, int a3, int a4, int a5)
{
    InterlockedIncrement((long*)0x9ea380);
    *(int*)this = 0xa0399c;
    f4 = 1;
    f8 = 0;
    fc = *(int*)0xa54060;
    f10 = a5;
    *(int*)this = 0xa1f000;
    if (sub_6cfb90(a1, a2, a3, a4, (int*)((char*)this + 0x20)))
        f18 = 0xb9a110;
    else
        f18 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
}
