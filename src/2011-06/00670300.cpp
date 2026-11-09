// from server: 56% by atomic.potato
struct S
{
    int f(void *, void *);
    int g(void *, void *);
    void *m[8];
};

int S::f(void *a, void *b)
{
    int value;
    S *p = (S *)m[7];
    int *q = *(int **)p->m[0];
    q += 3;
    value = g(a, b);
    return ((int (__thiscall *)(void *, void *, int))(*(int **)q))(p, b, value);
}
