// from server: 100% by atomic.potato
extern int g_00E48E58;
extern int g_00E48E50;
extern int g_00E48E54;
extern void G_009831F5(const char *);

void func_0078A110()
{
    if ((g_00E48E58 & 1) == 0)
    {
        g_00E48E58 |= 1;
        g_00E48E50 = 0;
        g_00E48E54 = 0;
        G_009831F5((const char *)0x00B1B660);
    }
}
