// from server: 100% by atomic.potato
typedef unsigned long InitFunction;

unsigned long g_initialized;
unsigned long g_value1;
unsigned long g_value2;

extern "C" void __cdecl Initialize(unsigned long);

void Function()
{
    if ((g_initialized & 1) != 0)
        return;

    g_initialized |= 1;
    g_value1 = 0;
    g_value2 = 0;
    Initialize(0xb20370);
}
