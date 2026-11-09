// from server: 100% by atomic.potato
extern int g_00ccf3c8;
extern int g_00ccf3c0;
extern int g_00ccf3c4;
extern void G1_func_0080b15d(const char *);

void func_0068d0c0()
{
    if (!(g_00ccf3c8 & 1))
    {
        g_00ccf3c8 |= 1;
        g_00ccf3c0 = 0;
        g_00ccf3c4 = 0;
        G1_func_0080b15d((const char *)0x00a3ba00);
    }
}
