// from server: 68% by atomic.potato
struct S
{
    static void __stdcall f(void *);
};

void __stdcall S::f(void *p)
{
    if (p != 0)
    {
        if (*(unsigned char *)((char *)p + 0x28) != 0)
            S::f(*(void **)((char *)p + 0x24));
        S::f(p);
    }
}
