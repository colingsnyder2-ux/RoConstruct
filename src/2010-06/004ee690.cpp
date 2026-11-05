// from server: 100% by atomic.potato
extern "C" void __cdecl sub_004eb5f0(int, void *, int);

struct S
{
};

void __cdecl f(int a, void *p, int c)
{
    if (c != 4)
    {
        sub_004eb5f0(a, p, c);
        return;
    }

    *(unsigned long *)p = 0x00b92c28UL;
    *((unsigned char *)p + 4) = 0;
    *((unsigned char *)p + 5) = 0;
}
