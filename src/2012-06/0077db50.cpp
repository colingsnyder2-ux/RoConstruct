// from server: 84% by atomic.potato
extern "C" void __cdecl Call_9831F5(const void *);

volatile unsigned char g_00E39B08;
volatile int g_00E39B00;
volatile int g_00E39B04;

void Function_0077DB50()
{
    if (!g_00E39B08)
    {
        g_00E39B08 = 1;
        g_00E39B00 = 0;
        g_00E39B04 = 0;
        Call_9831F5((const void *)0x00B18D60);
    }
}
