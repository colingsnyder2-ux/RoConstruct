// from server: 58% by atomic.potato
extern "C" void __cdecl f(unsigned int, unsigned int);

struct S
{
    void __cdecl f(unsigned int, unsigned int);
};

void __cdecl S::f(unsigned int a, unsigned int b)
{
    if (b != 4)
    {
        f(a, b);
        return;
    }

    unsigned char *p = (unsigned char *)a;
    *(unsigned int *)p = 0xDAE000;
    p[4] = 0;
    p[5] = 0;
}
