// from server: 55% by atomic.potato
struct S
{
    void __cdecl f(void *, unsigned int);
};

void S::f(void *p, unsigned int n)
{
    if (n == 4)
    {
        *(unsigned long *)p = 0x00dba4a0;
        *((unsigned char *)p + 4) = 0;
        *((unsigned char *)p + 5) = 0;
    }
    else
    {
        f(p, n);
    }
}
