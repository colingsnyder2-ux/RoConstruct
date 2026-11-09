// from server: 82% by atomic.potato
extern "C" void G1_func_0069e2a0(int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_0069e2a0(c);
        return;
    }

    *(int*)b = 0x00d9d868;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
