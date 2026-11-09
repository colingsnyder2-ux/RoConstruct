// from server: 100% by atomic.potato
struct S
{
    int func_00664d70(int, const char *, const char *, int);
};

extern "C" void __cdecl func_007f4929(const void *);

void func_009726b0()
{
    S *p = (S *)0xb902ac;
    p->func_00664d70(0xd4, (const char *)0x9ce7cc, (const char *)0x9ce7a0, 1);
    func_007f4929((const void *)0x9847e0);
}
