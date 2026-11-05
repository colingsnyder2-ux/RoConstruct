// from server: 37% by atomic.potato
struct S
{
    int f(void *, void *);
    void *field;
};

int S::f(void *a, void *b)
{
    void *p = a ? (char *)a + 28 : 0;
    ((int (__thiscall *)(void *, void *))(*(int **)field + 28))(field, p);
    return (int)b;
}
