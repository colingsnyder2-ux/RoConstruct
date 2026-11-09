// from server: 58% by atomic.potato
extern "C" void __cdecl helper(int, int, int);

int f(int a, int b)
{
    if (b != 4)
    {
        helper(0, a, b);
        return 0;
    }

    *(int *)a = 0xdb5310;
    *(char *)(a + 4) = 0;
    *(char *)(a + 5) = 0;
    return 0;
}
