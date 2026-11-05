// from server: 100% by atomic.potato
extern "C" void __cdecl Initialize(void *);

unsigned int g_initialized;
int g_value1;
int g_value2;

void Function()
{
    if (!(g_initialized & 1))
    {
        g_initialized |= 1;
        g_value1 = 0;
        g_value2 = 0;
        Initialize((void *)0x00B16100);
    }
}
