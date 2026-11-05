// from server: 100% by atomic.potato
extern "C" unsigned long __declspec(dllimport) __stdcall htonl(unsigned long);

static unsigned char g_initialized;
static unsigned long g_guard;

struct S_func_004ecd60 {
    unsigned char f();
};

unsigned char S_func_004ecd60::f()
{
    if ((g_guard & 1) == 0)
    {
        g_guard |= 1;
        g_initialized = (unsigned char)(htonl(12345) == 12345);
    }
    return g_initialized;
}
