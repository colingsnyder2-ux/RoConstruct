// from server: 100% by atomic.potato
struct S
{
    int f();
};

extern "C" S *sub_672bd0();

int S::f()
{
    S *p = sub_672bd0();
    if (p)
        return *(int *)((char *)*(int **)((char *)p + 0x168) + 0xf4);
    return 0;
}
