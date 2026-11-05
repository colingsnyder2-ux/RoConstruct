// from server: 84% by atomic.potato
struct S
{
    int (__thiscall *f)(void *);
    int g(void *);
};

int S::g(void *p)
{
    S *q = this;
    if (p != 0)
    {
        char *r = (char *)p - 28;
        if (r != 0)
            return q->f(r + 520);
    }
    return q->f(0);
}
