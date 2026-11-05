// from server: 59% by atomic.potato
extern "C" void G1_func_008d5720(int, int, int, int);

void func_008d58e0(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_008d5720(a, b, c, 0);
        return;
    }

    *(int *)b = 0x00df4190;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
