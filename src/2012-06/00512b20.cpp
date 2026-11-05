// from server: 100% by atomic.potato
extern "C" void __cdecl Function9831F5(void *);

static unsigned int g_e1df6c;
static void *g_e1df64;
static void *g_e1df68;
static char g_b12c90;

void Function512B20()
{
    if (!(g_e1df6c & 1))
    {
        g_e1df6c |= 1;
        g_e1df64 = 0;
        g_e1df68 = 0;
        Function9831F5(&g_b12c90);
    }
}
