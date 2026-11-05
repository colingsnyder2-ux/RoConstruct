// from server: 100% by atomic.potato
extern int g_00E565A0;
extern int g_00E56598;
extern int g_00E5659C;
extern const char g_00B20EF0;
extern void G1_func_009831F5(const char *);

void func_008F80B0()
{
    if ((g_00E565A0 & 1) == 0)
    {
        g_00E565A0 |= 1;
        g_00E56598 = 0;
        g_00E5659C = 0;
        G1_func_009831F5(&g_00B20EF0);
    }
}
