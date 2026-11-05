// from server: 80% by atomic.potato
struct S
{
    int pad[8];
    int **vtable;
    void *f(int, int, void *);
};

void *S::f(int a, int b, void *c)
{
    int **p = *(int ***)((char *)a - 204);
    int *q = p[8];
    typedef void *(__thiscall *Fn)(int *, int, void *);
    Fn fn = (Fn)q[114];
    return fn(q, b, c);
}
