// from server: 96% by atomic.potato
struct S
{
    static void f(int, int);
    static void g(void *);
    void __cdecl h(void *);
};

void S::h(void *p)
{
    if (p)
    {
        f((int)p, *(int *)((char *)p + 0x14));
        g(p);
    }
}
