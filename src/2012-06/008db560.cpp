// from server: 85% by atomic.potato
extern int g_e555c0;
extern int g_e555b8;
extern int g_e555bc;

extern "C" void __cdecl f_9831f5(const char *);

int f_008db560()
{
    if (*(volatile unsigned char *)&g_e555c0 != 0)
        return 0;

    g_e555c0 |= 1;
    g_e555b8 = 0;
    g_e555bc = 0;
    f_9831f5("8csm");
    return 0;
}
