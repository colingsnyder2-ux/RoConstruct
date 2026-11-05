// from server: 85% by atomic.potato
struct S
{
    int f(int);
};

int S::f(int value)
{
    int *p = *(int **)((char *)this + 4);
    int offset = p[1];
    int *q = *(int **)((char *)this + offset + 4);
    ((void (__thiscall *)(int *, int))q[0])(q, value);
    return value;
}
