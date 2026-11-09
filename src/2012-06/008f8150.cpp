// from server: 100% by atomic.potato
extern int g_00E565C4;
extern int g_00E565BC;
extern int g_00E565C0;
extern void __cdecl func_009831F5(const char *);

void func_008F8150()
{
    if ((g_00E565C4 & 1) == 0)
    {
        g_00E565C4 |= 1;
        g_00E565BC = 0;
        g_00E565C0 = 0;
        func_009831F5((const char *)0x00B20F50);
    }
}
