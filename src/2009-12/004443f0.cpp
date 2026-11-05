// from server: 37% by atomic.potato
struct S
{
    int f(int *p);
};

int S::f(int *p)
{
    int *q = p ? p - 7 : 0;
    int n = (int)*p;
    int *v = (int *)((char *)this + 12);
    int (__thiscall *fn)(int, int) = *(int (__thiscall **)(int, int))((char *)this + 8);
    return fn((int)((char *)v + (int)q), n);
}
