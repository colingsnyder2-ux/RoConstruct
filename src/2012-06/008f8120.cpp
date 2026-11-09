// from server: 99% by atomic.potato
extern int g_00E565B8;
extern int g_00E565B0;
extern int g_00E565B4;
extern void G1_func_009831f5(const char *);

void func_008f8120()
{
    if (!(g_00E565B8 & 1))
    {
        g_00E565B8 |= 1;
        g_00E565B0 = 0;
        g_00E565B4 = 0;
        G1_func_009831f5("8csm");
    }
}
