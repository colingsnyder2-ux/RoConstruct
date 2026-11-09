// from server: 100% by intel
struct S
{
    int f(void *p);
};

int S::f(void *p)
{
    int *a = *(int **)((char *)p + 0x28);
    int *b = *(int **)((char *)a + 0xc);
    return ((int (__thiscall *)(int *, int *))(*(int **)((char *)b + 8)))((int *)((char *)b), (int *)((char *)a + 0xc));
}