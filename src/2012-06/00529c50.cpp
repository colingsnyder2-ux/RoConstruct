// from server: 67% by atomic.potato
struct S
{
};

extern void G1_func_00522250(void *, int);

void __cdecl f(void *p, int, int n)
{
    if (n != 4)
    {
        G1_func_00522250(p, n);
        return;
    }
    *(int *)p = 0xd7c110;
    *((char *)p + 4) = 0;
    *((char *)p + 5) = 0;
}
