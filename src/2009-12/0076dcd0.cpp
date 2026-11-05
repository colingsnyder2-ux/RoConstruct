// from server: 100% by atomic.potato
extern "C" void __cdecl target(int, void *, int);

struct S
{
};

void __cdecl f(int a, void *p, int c)
{
    if (c != 4)
    {
        target(a, p, c);
        return;
    }

    *(unsigned long *)p = 0x00b5fe50;
    *((unsigned char *)p + 4) = 0;
    *((unsigned char *)p + 5) = 0;
}
