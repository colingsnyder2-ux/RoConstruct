// from server: 86% by atomic.potato
struct S
{
    int f();
};

extern "C" S *sub_672bd0();

int S::f()
{
    S *p = sub_672bd0();
    int *q = p ? *(int **)((char *)p + 0x168) : 0;
    int *r = q ? *(int **)((char *)q + 0xf4) : 0;
    return r ? *(int *)((char *)r + 0x2c) : 0;
}
