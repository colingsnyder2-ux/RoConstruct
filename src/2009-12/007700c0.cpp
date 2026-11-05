// from server: 60% by atomic.potato
struct S
{
};

int __cdecl f(void *, void *a, void *b)
{
    struct T
    {
        int x;
        int y;
        int (__thiscall *p)(T *, void *);
    };

    T *t = (T *)a;
    return t->p(t, b);
}
