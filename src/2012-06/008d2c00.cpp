// from server: 99% by atomic.potato
extern "C" void __cdecl Initialize_9831F5(const char *);

int g_E55050;
int g_E55054;
int g_E55058;

void Function_008D2C00()
{
    if (!(g_E55058 & 1))
    {
        g_E55058 |= 1;
        g_E55050 = 0;
        g_E55054 = 0;
        Initialize_9831F5("8csm");
    }
}
