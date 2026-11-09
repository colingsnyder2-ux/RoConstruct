// from server: 58% by atomic.potato
struct S
{
    void __cdecl f(void *, int);
};

void S::f(void *p, int n)
{
    if (n == 4)
    {
        *(unsigned long *)p = 0x00d74b70UL;
        ((unsigned char *)p)[4] = 0;
        ((unsigned char *)p)[5] = 0;
    }
    else
    {
        f(p, n);
    }
}
