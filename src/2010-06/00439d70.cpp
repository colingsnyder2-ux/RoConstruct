// from server: 70% by atomic.potato
struct S
{
    int f(void *, void *);
};

int S::f(void *p, void *q)
{
    char *a = p ? (char *)p + 0x1c : 0;
    int **v = *(int ***)(*(char **)this + 0x134);
    return ((int (__thiscall *)(void *, void *, void *))v[0x10])(v, *(void **)q, a);
}
