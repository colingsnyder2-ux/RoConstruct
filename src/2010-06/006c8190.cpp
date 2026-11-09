// from server: 77% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long volatile*);

struct S {
    char pad0[5];
    char f5;
    char pad6[2];
    int f8;
    int fc;
    int f10;
    char pad14[4];
    int f18;
    char pad1c[0x1c];
    int f38;
    int f3c;
    int f40;
    int f44;
    S(int, int, int);
};

extern "C" void __stdcall sub_6c7b40(int*, int, int);

S::S(int a, int b, int c)
{
    InterlockedIncrement((long volatile*)0xc007ac);
    *(int*)this = 0xa0399c;
    f5 = 1;
    f8 = 0;
    fc = *(int*)0xa54060;
    f10 = c;
    *(int*)((char*)this + 0x18) = 0;
    *(int*)this = 0xa44db0;
    sub_6c7b40((int*)((char*)this + 0x18), a, b);
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
}
