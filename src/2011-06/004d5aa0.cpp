// from server: 100% by atomic.potato
extern "C" void __cdecl G1_func_004d2a20(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int value)
{
    if (value != 4)
    {
        G1_func_004d2a20(a, b, value);
        return;
    }

    int *p = (int *)b;
    *p = 0xc24748;
    ((char *)p)[4] = 0;
    ((char *)p)[5] = 0;
}
