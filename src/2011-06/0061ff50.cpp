// from server: 100% by atomic.potato
extern int g_00CCBF74;
extern int g_00CCBF6C;
extern int g_00CCBF70;
extern void G_0080B15D(const char *);

void func_0061FF50()
{
    if ((g_00CCBF74 & 1) == 0)
    {
        g_00CCBF74 |= 1;
        g_00CCBF6C = 0;
        g_00CCBF70 = 0;
        G_0080B15D((const char *)0x00A39B30);
    }
}
