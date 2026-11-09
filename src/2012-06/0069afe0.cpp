// from server: 83% by atomic.potato
extern "C" void __cdecl sub_9831F5(const char *);

volatile unsigned char g_00E2D1E8;
volatile int g_00E2D1E0;
volatile int g_00E2D1E4;

void f()
{
    if (!g_00E2D1E8)
    {
        g_00E2D1E8 |= 1;
        g_00E2D1E0 = 0;
        g_00E2D1E4 = 0;
        sub_9831F5("8csm");
    }
}
