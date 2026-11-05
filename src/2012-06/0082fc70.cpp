// from server: 81% by atomic.potato
typedef void (__cdecl *InitFunction)();

volatile unsigned char g_initialized = 0;
volatile int g_value1 = 0;
volatile int g_value2 = 0;
InitFunction g_initializer = (InitFunction)0x00b1ebd0;

extern "C" void __cdecl Function_009831f5();

int Function_0082fc70()
{
    if (!g_initialized)
    {
        g_initialized = 1;
        g_value1 = 0;
        g_value2 = 0;
        Function_009831f5();
    }
    return 0;
}
