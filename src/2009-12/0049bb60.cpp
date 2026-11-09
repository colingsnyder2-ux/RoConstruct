// from server: 87% by atomic.potato
struct S
{
    void *v;
    void f(void *);
};

void S::f(void *p)
{
    void *old = v;
    v = p;
    if (old != 0)
    {
        void (__thiscall *fn)(void *, int) =
            (void (__thiscall *)(void *, int))(*(unsigned char **)old + 0x3c);
        fn(old, 1);
    }
}
