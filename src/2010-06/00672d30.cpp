// from server: 100% by atomic.potato
struct S
{
    int *f();
};

extern "C" S *sub_672A50();

int *S::f()
{
    S *p = sub_672A50();
    if (p)
        return *(int **)((char *)p + 0x168);
    return 0;
}
