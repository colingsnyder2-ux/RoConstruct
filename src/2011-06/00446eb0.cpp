// from server: 64% by atomic.potato
struct S
{
    int f(void *, void *);
    int *member;
};

int S::f(void *p, void *q)
{
    int *x = p ? (int *)((char *)p + 28) : 0;
    int *v = member;
    return ((int (__thiscall *)(int *, int *, void *))(*(v + 8)))(v, x, q);
}
