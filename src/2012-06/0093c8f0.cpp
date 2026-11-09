// from server: 80% by atomic.potato
typedef void (*InitFunction)();

static int g_initialized;
static int g_value1;
static int g_value2;

extern "C" void __cdecl InitializeSubsystem();

void Function0093c8f0()
{
    if (!(g_initialized & 1))
    {
        g_initialized |= 1;
        g_value1 = 0;
        g_value2 = 0;
        InitializeSubsystem();
    }
}
