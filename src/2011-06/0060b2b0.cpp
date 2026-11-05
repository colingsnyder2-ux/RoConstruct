// from server: 54% by atomic.potato
struct S
{
    int f(void *);
    void *vtable;
    int value;
    int index;
    int **table;
};

int S::f(void *p)
{
    S *x;
    int i;

    x = p ? (S *)((char *)p - 0x1c) : 0;
    i = index;
    return ((int (__thiscall *)(void *, int *))vtable)(x->table[i] + value + (int)x + 0x94, 0);
}
