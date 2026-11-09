// from server: 100% by atomic.potato
struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int *p = *(int **)((char *)this + 0x30);
    ((void (__thiscall *)(int *, int, int))p[0])((int *)((char *)this + 0x30), a, b);
    return a;
}
