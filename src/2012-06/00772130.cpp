// from server: 81% by atomic.potato
extern int g_00e39aa0;
extern int g_00e39aa4;
extern unsigned char g_00e39aa8;
extern int g_00b18d20;
extern "C" void __cdecl f_009831f5(int);

int f_00772130()
{
    if (g_00e39aa8 & 1)
        return 0;

    g_00e39aa8 |= 1;
    g_00e39aa0 = 0;
    g_00e39aa4 = 0;
    f_009831f5(g_00b18d20);
    return 0;
}
