// from server: 100% by atomic.potato
extern int g_00e565d0;
extern int g_00e565c8;
extern int g_00e565cc;

extern void G1_func_009831f5(const void *);

void func_008f8180()
{
    if ((g_00e565d0 & 1) == 0)
    {
        g_00e565d0 |= 1;
        g_00e565c8 = 0;
        g_00e565cc = 0;
        G1_func_009831f5((const void *)0x00b20f30);
    }
}
