// from server: 100% by tester
struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int *p = *(int **)((char *)this + 0x34);
    ((void (__thiscall *)(int *, int, int))p[0])((int *)((char *)this + 0x34), a, b);
    return a;
}