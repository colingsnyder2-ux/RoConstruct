// from server: 51% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int a)
{
    int *p = *(int **)((char *)this + 0x9c);
    if (!p)
        return 0x80040209;
    return ((int (__thiscall *)(int *, int))(*(int **)*p + 0x18))(p, a);
}
