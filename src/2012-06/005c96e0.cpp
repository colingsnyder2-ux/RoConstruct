// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5c94e0(const void *, unsigned char);

struct S
{
    int __cdecl f(const void *);
};

int __cdecl S::f(const void *p)
{
    extern int g_00e273c0;
    int n = g_00e273c0;
    if (n > 1)
    {
        const unsigned char *q = (const unsigned char *)p + 0x10;
        int i = n - 1;
        do
        {
            sub_5c94e0(q, 4);
            q += 0x10;
            --i;
        } while (i != 0);
    }
    return 0;
}
