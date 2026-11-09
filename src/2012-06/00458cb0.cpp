// from server: 100% by tester
struct S
{
    int value;
    int f(int *a, int b);
};

int S::f(int *a, int b)
{
    int *p = a ? a + 7 : 0;
    int *q = *(int **)((char *)this + 0x130);
    q = *(int **)((char *)q + 0x28);
    return ((int (__thiscall *)(int *, int *, int))(*(int ***)q)[3])(q, p, b);
}
