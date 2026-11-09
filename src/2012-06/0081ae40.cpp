// from server: 99% by atomic.potato
extern "C" void __cdecl Function9831F5(const char *);

static int g_initialized;
static int g_value1;
static int g_value2;

void Function0081AE40()
{
    if (!(g_initialized & 1))
    {
        g_initialized |= 1;
        g_value1 = 0;
        g_value2 = 0;
        Function9831F5("8csm");
    }
}
