// from server: 99% by atomic.potato
extern int g_00E1C3A4;
extern int g_00E1C39C;
extern int g_00E1C3A0;
extern void G_009831F5(const char *);

void func_004CDA60()
{
    if ((g_00E1C3A4 & 1) == 0)
    {
        g_00E1C3A4 |= 1;
        g_00E1C39C = 0;
        g_00E1C3A0 = 0;
        G_009831F5("8csm");
    }
}
