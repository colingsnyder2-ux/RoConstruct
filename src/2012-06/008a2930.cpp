// from server: 57% by atomic.potato
struct S
{
    int (__thiscall *function)(S *, double);
    int offset;
};

struct T
{
    int f(S *, double *);
};

int T::f(S *p, double *value)
{
    int offset = p ? -0x1c : 0;
    S *s = (S *)((char *)p + offset);
    return ((int (__thiscall *)(S *, double))s->function)(s, *value);
}
