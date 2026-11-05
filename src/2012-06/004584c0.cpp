// from server: 66% by atomic.potato
struct S
{
    int f(void *, void *);
    int *field138;
};

typedef int (__thiscall *Fn)(void *, void *);

int S::f(void *a, void *b)
{
    int *p = (int *)a;
    if (p != 0)
        p = (int *)((char *)p + 0x1c);

    int *q = *(int **)((char *)field138 + 0x28);
    Fn fn = *(Fn *)((char *)*(int **)q + 0x0c);
    return fn(q, p);
}
