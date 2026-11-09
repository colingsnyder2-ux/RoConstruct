// from server: 80% by atomic.potato
extern "C" void __cdecl Initialize();

static volatile unsigned long g_initialized;
static volatile unsigned long g_value1;
static volatile unsigned long g_value2;
static const unsigned long g_table = 0x00b20330;

void f()
{
    if (g_initialized & 1)
        return;

    g_initialized |= 1;
    g_value1 = 0;
    g_value2 = 0;
    Initialize();
}
