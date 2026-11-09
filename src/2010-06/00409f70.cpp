// from server: 82% by atomic.potato
typedef unsigned long DWORD;

struct S;

extern "C" void __stdcall sub_409860(const void *);

struct S
{
    DWORD a0;
    char pad[36];
    DWORD a28;
    char pad2[16];
    DWORD a3c;
    S *f(const void *);
};

S *S::f(const void *p)
{
    sub_409860(p);
    a3c = 0x00a00920;
    a0 = 0x00a00b1c;
    a28 = 0x00a00b14;
    a3c = 0x00a00b04;
    return this;
}
