// from server: 50% by atomic.potato
struct S
{
    void __cdecl f(int, int, int);
};

void S::f(int a, int b, int c)
{
    int **p = (int **)((char *)a + 8);
    if (*(int *)((char *)a + 16))
        ((void (__cdecl *)(int, int, int))**p)(c, c, c);
}
