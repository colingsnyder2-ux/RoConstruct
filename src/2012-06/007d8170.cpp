// from server: 63% by atomic.potato
extern "C" void __cdecl target(int, int, int);

struct S
{
    void __cdecl f(int, int, int);
};

void __cdecl S::f(int a, int b, int c)
{
    if (c != 4)
    {
        target(a, b, c);
        return;
    }

    unsigned char *p = (unsigned char *)b;
    *(unsigned long *)p = 0x00DCFB10;
    p[4] = 0;
    p[5] = 0;
}
