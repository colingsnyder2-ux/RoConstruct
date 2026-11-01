// from server: 57% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct Inner
{
    void init(void*);
};

struct S
{
    char pad0[4];
    char f4;
    char pad5[3];
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

    S* construct(void* a, int b, int c, int d, int e, int f, int g);
};

S* S::construct(void* a, int b, int c, int d, int e, int f, int g)
{
    InterlockedIncrement((long volatile*)0xc007ac);
    *(int*)this = 0xa0399c;
    *(char*)((char*)this + 5) = 1;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = *(int*)0xa54060;
    *(int*)((char*)this + 0x10) = b;
    *(int*)this = 0xa03a1c;
    *(int*)((char*)this + 0x18) = 0;
    ((Inner*)((char*)this + 0x18))->init(&a);
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x44) = 0;
    return this;
}
