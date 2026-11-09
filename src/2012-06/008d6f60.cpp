// from server: 100% by atomic.potato
extern unsigned int g_00e55330;
extern int g_00e55328;
extern int g_00e5532c;
extern void __cdecl G1_func_009831f5(const char *);

void func_008d6f60()
{
    if (!(g_00e55330 & 1))
    {
        g_00e55330 |= 1;
        g_00e55328 = 0;
        g_00e5532c = 0;
        G1_func_009831f5((const char *)0x00b20500);
    }
}
