// from server: 100% by atomic.potato
extern int g_00E56594;
extern int g_00E5658C;
extern int g_00E56590;

extern void __cdecl G_00B20F10(int);

void func_008F8080()
{
    if ((g_00E56594 & 1) == 0)
    {
        g_00E56594 |= 1;
        g_00E5658C = 0;
        g_00E56590 = 0;
        G_00B20F10(0x00B20F10);
    }
}
