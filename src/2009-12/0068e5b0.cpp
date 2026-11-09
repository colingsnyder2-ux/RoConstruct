// from server: 52% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int f(void *, int);
};

int S::f(void *p, int n)
{
    int *v = (int *)p;
    if (v)
        return ((int (__thiscall *)(int *, int))b)((int *)((char *)v - 0x1c), n);
    return ((int (__thiscall *)(int *, int))b)((int *)0, n);
}
