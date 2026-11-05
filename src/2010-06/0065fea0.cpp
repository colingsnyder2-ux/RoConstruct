// from server: 100% by atomic.potato
extern "C" void __cdecl G1_func_0065f600(int, int, int);

void func_0065fea0(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_0065f600(a, b, c);
        return;
    }

    *(int*)b = 0x00bbc1e0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
