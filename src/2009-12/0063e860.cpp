// from server: 38% by atomic.potato
struct S
{
    void f(void *, void *);
};

void S::f(void *a, void *b)
{
    typedef void (__thiscall *Method)(void *);
    Method m = *(Method *)(*(unsigned long **)b + 4);
    m(b);
    f(a, b);
}
