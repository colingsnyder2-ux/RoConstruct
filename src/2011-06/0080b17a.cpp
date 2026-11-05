// from server: 23% by atomic.potato
extern "C" void __cdecl f0080bbec(int, void *);

void f0080b17a(int a, int b, int count, void (__cdecl *fn)(int))
{
    f0080bbec(20, (void *)0x00bd38e8);
    while (--count >= 0)
    {
        a -= b;
        fn(a);
    }
}
