// from server: 43% by atomic.potato
struct S_func_0070b630
{
    static void f(void *, int);
};

void S_func_0070b630::f(void *a, int b)
{
    if (b == 4)
    {
        *(int *)a = 0x00daa068;
        ((char *)a)[4] = 0;
        ((char *)a)[5] = 0;
    }
    else
    {
        f(a, b);
    }
}
