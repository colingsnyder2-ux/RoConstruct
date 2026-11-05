// from server: 100% by atomic.potato
extern int g_00e565a4;
extern int g_00e565a8;
extern int g_00e565ac;
extern void G_009831f5(const char *);

void func_008f80e0()
{
    if (!(g_00e565ac & 1))
    {
        g_00e565ac |= 1;
        g_00e565a4 = 0;
        g_00e565a8 = 0;
        G_009831f5((const char *)0x00b20ed0);
    }
}
