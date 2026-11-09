// from server: 60% by atomic.potato
struct S
{
    void __cdecl f(void *, int);
};

void S::f(void *p, int v)
{
    if (v == 4)
    {
        *(int *)p = 0x00d9d2b0;
        ((char *)p)[4] = 0;
        ((char *)p)[5] = 0;
    }
}
