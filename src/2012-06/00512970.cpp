// from server: 87% by atomic.potato
typedef void (__cdecl *FunctionType)(const char *);

static unsigned int g_initialized;
static int g_value1;
static int g_value2;

extern "C" void __cdecl Function9831F5(const char *);

void Function512970()
{
    if (g_initialized)
        return;

    g_initialized = 1;
    g_value1 = 0;
    g_value2 = 0;
    Function9831F5("8csm");
}
