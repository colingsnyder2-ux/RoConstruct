// from server: 76% by atomic.potato
struct S
{
    int f(void *, void *);
    int g(void *, void *);
    void *m_1c;
};

int S::f(void *a, void *b)
{
    char local[8];
    void *p = m_1c;
    void **v = *(void ***)p;
    v = (void **)((char *)v + 16);
    int x = g(b, local);
    return ((int (__thiscall *)(void *, void *, int))v[0])(p, a, x);
}
