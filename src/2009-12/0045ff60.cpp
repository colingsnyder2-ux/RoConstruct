// from server: 100% by atomic.potato
extern "C" void func_0045f540(int, int, int);

void func_0045ff60(int a, int b, int c)
{
    if (c != 4)
    {
        func_0045f540(a, b, c);
        return;
    }

    *(int *)b = 0x00b0a2f0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
