// from server: 100% by atomic.potato
extern "C" void __cdecl Call9831F5(const char *);

int g_e4f4a4;
int g_e4f49c;
int g_e4f4a0;

void Function007FAB70()
{
    if (!(g_e4f4a4 & 1))
    {
        g_e4f4a4 |= 1;
        g_e4f49c = 0;
        g_e4f4a0 = 0;
        Call9831F5((const char *)0x00b1dbe0);
    }
}
