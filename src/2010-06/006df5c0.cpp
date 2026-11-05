// from server: 84% by atomic.potato
struct S
{
    int (__thiscall *fn)(void *);
    int f(void *);
};

int S::f(void *p)
{
    S *q = this;
    if (p != 0)
    {
        char *x = (char *)p - 28;
        if (x != 0)
            return fn((void *)(x + 704));
    }
    return fn(0);
}
