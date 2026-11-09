// from server: 100% by atomic.potato
extern int g_00CD1A14;
extern int g_00CD1A18;
extern int g_00CD1A1C;
extern void G1_func_0080b15d(const char *);

void func_006da780()
{
    if (!(g_00CD1A1C & 1))
    {
        g_00CD1A1C |= 1;
        g_00CD1A14 = 0;
        g_00CD1A18 = 0;
        G1_func_0080b15d((const char *)0x00A3D160);
    }
}
