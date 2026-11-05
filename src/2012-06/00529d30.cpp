// from server: 82% by atomic.potato
extern "C" void G1_func_005223d0(int);

struct FactoryProduct
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_005223d0(c);
        return;
    }

    *(int*)b = 0x00d7c1c0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
