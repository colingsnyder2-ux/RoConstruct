// from server: 100% by atomic.potato
struct S
{
};

extern void G1_func_007dde60(int, int, int);

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_007dde60(a, b, c);
        return;
    }

    *(int*)b = 0xb64490;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
