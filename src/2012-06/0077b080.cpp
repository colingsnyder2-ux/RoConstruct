// from server: 100% by atomic.potato
extern "C" void __cdecl Function9831F5(void *);

unsigned int g_e39ac8;
int g_e39ac0;
int g_e39ac4;

void Function0077B080()
{
    if (!(g_e39ac8 & 1))
    {
        g_e39ac8 |= 1;
        g_e39ac0 = 0;
        g_e39ac4 = 0;
        Function9831F5((void *)0x00b18d00);
    }
}
