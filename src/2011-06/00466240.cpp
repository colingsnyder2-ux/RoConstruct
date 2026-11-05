// from server: 73% by atomic.potato
struct S
{
    int f();
    int a[8];
};

int S::f()
{
    int (__thiscall *p)(int) = (int (__thiscall *)(int))a[9];
    return p(a[8]);
}
