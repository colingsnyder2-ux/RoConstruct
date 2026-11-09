// from server: 100% by atomic.potato
struct S
{
};

extern "C" void __cdecl target(void *, int, int);

void __cdecl f(void *a, int b, int c)
{
    if (c != 4)
        target(a, b, c);
    else
    {
        unsigned char *p = (unsigned char *)b;
        *(unsigned long *)p = 0x00bb8b08;
        p[4] = 0;
        p[5] = 0;
    }
}
