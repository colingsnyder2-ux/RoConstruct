// from server: 100% by atomic.potato
struct S
{
    int f(void *p);
};

int S::f(void *p)
{
    int *a = *(int **)((char *)p + 0x28);
    int *b = *(int **)((char *)a + 0x0c);
    return ((int (__thiscall *)(int *, int *))(*(int **)((char *)b + 4)))((int *)((char *)b), (int *)((char *)a + 0x0c));
}
