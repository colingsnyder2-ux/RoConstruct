// from server: 55% by atomic.potato
struct S
{
    int __cdecl f(int, int);
};

int S::f(int a, int b)
{
    if (b != 4)
        return f(a, 4);

    *(int*)a = 0x00da6928;
    *((char*)a + 4) = 0;
    *((char*)a + 5) = 0;
    return 0;
}
