// from server: 100% by atomic.potato
struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        extern void G1_func_0065f7b0(int, int, int);
        G1_func_0065f7b0(a, b, c);
        return;
    }

    *(int*)b = 0xc56e88;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
