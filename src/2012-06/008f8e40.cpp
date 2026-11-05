// from server: 58% by atomic.potato
struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c == 4)
    {
        *(int *)b = 0x00dfd850;
        *((unsigned char *)b + 4) = 0;
        *((unsigned char *)b + 5) = 0;
    }
    else
    {
        f(a, b, c);
    }
}
