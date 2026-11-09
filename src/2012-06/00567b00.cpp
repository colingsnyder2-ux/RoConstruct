// from server: 46% by atomic.potato
extern "C" unsigned long __stdcall htonl(unsigned long);

static unsigned long g_initialized;
static unsigned char g_result;

unsigned char f()
{
    if (!g_initialized)
    {
        g_initialized |= 1;
        g_result = (htonl(12345UL) == 12345UL) ? 1 : 0;
    }
    return g_result;
}
