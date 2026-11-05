// from server: 79% by atomic.potato
struct S
{
    int *v;
    int f(int);
};

int S::f(int value)
{
    int *a = *(int **)((char *)this - 28);
    int *b = *(int **)((char *)a + 4);
    int *c = (int *)((char *)b + (int)((char *)this - 28));
    int (__thiscall *fn)(int *, int) = *(int (__thiscall **)(int *, int))c;
    fn(c, value);
    return value;
}
