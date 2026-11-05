// from server: 47% by atomic.potato
struct S
{
    int f(int *a, int *b);
};

int S::f(int *a, int *b)
{
    int *p = a ? (int *)((char *)a + 0x1c) : 0;
    int *q = *(int **)((char *)this + 0x124);
    ((void (__thiscall *)(int *, int *))(*(int ***)q)[7])(q, p);
    return (int)b;
}
