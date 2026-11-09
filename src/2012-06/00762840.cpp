// from server: 86% by atomic.potato
extern "C" void __cdecl call_9831f5(const void *);

volatile unsigned int g_e3735c;
volatile int g_e37354;
volatile int g_e37358;

void f()
{
    if (!(g_e3735c & 1))
    {
        g_e3735c |= 1;
        g_e37354 = 0;
        g_e37358 = 0;
        call_9831f5((const void *)0xB18B60);
    }
}
