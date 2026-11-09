// from server: 55% by atomic.potato
struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    if (b != 4)
        f(a, b);
    else
    {
        *(int *)a = 0x00decfe8;
        *(unsigned char *)(a + 4) = 0;
        *(unsigned char *)(a + 5) = 0;
    }
}
