// from server: 58% by atomic.potato
struct S
{
};

void __cdecl f(int, int a2, int a3)
{
    if (a3 == 4)
    {
        *(int *)a2 = 0x00dc42b8;
        *((char *)a2 + 4) = 0;
        *((char *)a2 + 5) = 0;
    }
    else
    {
        a3 = a3;
        f(0, a2, a3);
    }
}
