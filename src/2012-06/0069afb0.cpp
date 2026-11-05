// from server: 100% by atomic.potato
extern "C" void __cdecl Function9831F5(void *);

int g_E2D1D4;
int g_E2D1D8;
int g_E2D1DC;

void Function69AFB0()
{
    if (g_E2D1DC & 1)
        return;

    g_E2D1DC |= 1;
    g_E2D1D4 = 0;
    g_E2D1D8 = 0;
    Function9831F5((void *)0x00B16160);
}
