// from server: 20% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int *p;
    int a;
    int b;
    int c;
    int d;

    p = &d;
    a = (int)&a;
    b = (int)&b;
    c = (int)&c;
    d = (int)&d;

    return ((int (__thiscall *)(int *, int))(*(int *)p))(p, *(int *)(p + 1) + *(int *)(p + 2));
}
