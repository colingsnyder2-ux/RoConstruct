// from server: 100% by atomic.potato
extern int g_00734300;
extern int g_00734304;
extern int g_00734308;
extern void G1_func_009831f5(const char *);

void func_00734300()
{
    if ((g_00734308 & 1) == 0)
    {
        g_00734308 |= 1;
        g_00734304 = 0;
        g_00734300 = 0;
        G1_func_009831f5((const char *)0x00b17dd0);
    }
}
