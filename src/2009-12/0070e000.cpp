// from server: 31% by atomic.potato
struct S {
    char pad0[0x48];
    int f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_7058B0(void*);
extern "C" void __stdcall sub_705E30(void*, void*);
extern "C" void __stdcall sub_70D080(void*);

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19)
{
    char buf[0x48];
    int local;
    sub_705E30(buf, &local);
    sub_70D080(this);
    sub_7058B0(buf);
    return (int)this;
}
